//==============================================================================
// Fosc_Trim_S.cpp (User function)
// 
//    void Fosc_Trim_S_user_init(test_function& func)
//    void Fosc_Trim_S(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "Fosc_Trim_S.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void Fosc_Trim_S_user_init(test_function& func)
{
	Fosc_Trim_S_params *ours;
    ours = (Fosc_Trim_S_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void Fosc_Trim_S(test_function& func)
{
    // The two lines below must be the first two in the function.
    Fosc_Trim_S_params *ours;
    ours = (Fosc_Trim_S_params *)func.params;

	// Increment function number //
	gFuncNum++;	
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_Fosc_Trim_S, gFuncNum, 14, POWER_UNIT);

	// Skip Test if AbortTest set //
	if (AbortTest)
		return;

	// Skip trimming if g_p_Trim_Enable set //
	if (g_p_Trim_Enable == 0)
		return;

	if (g_Fn_Fosc_Trim_S == 0 )  return;

	// Test Time Begin //
	 if (g_p_TstTime_Enble)
	 	g_begintime = g_mytimer.GetElapsedTime();

	// Test Names //
	//int fNum_FoscTrim_S =0;
	float Fosc_Target_S = gFOSC_TARGET_S_Trimops;
	int Fosc_TrCode_S =0;
	int Fosc_BitCode_S =0;
	int EEtr_F1_S =0;
	int EEtr_F2_S =0;
	int EEtr_F3_S =0;
	int F_Iint_TrCode =0;
	int F_Iint_BitCode =0;
	int EEtr_F_Iint1_s =0;
	int EEtr_F_Iint2_s =0;
	int EEtr_F_Iint3_s =0;
	int EEtr_F_Iint4_s =0;
	float Fosc_Trim_S_TT =0;

	// Declare Variables //
	int NObin[1] = {0}; // Place holder //
	int NOhex = 0; // Place holder //
	int WordArray[16] = {0};
	int TempArray[30] = {0};
	float UpperLimit = 0;
	float LowerLimit = 0;
	float FreqMeas = 0;
	float tmeas = 0;
	Pulse pulse;
	float Delta = 0;
	float MinDelta = 0;
	float BestFreq = 0;
	int Best_TrCode = 0;
	int Best_BitCode = 0;
	float MaxPercentDiff = 2.5;
	int Trim_Iint_Flag = 0;

	// Still powered up from Fosc_Pre_S.cpp function. //


	// FB //
	// Stop switching // 
	FB_ovi->set_voltage(FB_ch, 1.5, RANGE_2_V); // OVI_1_2	
	wait.delay_10_us(10);

	// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
	WordArray[0] = g_ShadowRegister[0];
	WordArray[1] = g_ShadowRegister[1];
	WordArray[2] = g_ShadowRegister[2];
	WordArray[3] = g_ShadowRegister[3];
	WordArray[4] = g_ShadowRegister[4];
	WordArray[5] = g_ShadowRegister[5];
	WordArray[6] = g_ShadowRegister[6];
	WordArray[7] = g_ShadowRegister[7];
	WordArray[8] = g_ShadowRegister[8];
	WordArray[9] = g_ShadowRegister[9];
	WordArray[10] = g_ShadowRegister[10];
	WordArray[11] = g_ShadowRegister[11];
	WordArray[12] = g_ShadowRegister[12]; // EEtr_F1_S //
	WordArray[13] = g_ShadowRegister[13]; // EEtr_F2_S //
	WordArray[14] = g_ShadowRegister[14]; // EEtr_F3_S //
	WordArray[15] = g_ShadowRegister[15];

	// Find trim code closest to target. //
	UpperLimit = 5;
	LowerLimit = -4;
	MinDelta = 99999;
	while ( (UpperLimit - LowerLimit) > 1)
	{
		Fosc_BitCode_S = (UpperLimit + LowerLimit) / 2;
		
		// Convert BitCode to TrCode. Mapping between bit code and trim code. //
		if(Fosc_BitCode_S == -3) Fosc_TrCode_S = 3;
		if(Fosc_BitCode_S == -2) Fosc_TrCode_S = 2;
		if(Fosc_BitCode_S == -1) Fosc_TrCode_S = 1;
		if(Fosc_BitCode_S == 0) Fosc_TrCode_S = 0;
		if(Fosc_BitCode_S == 1) Fosc_TrCode_S = 4;
		if(Fosc_BitCode_S == 2) Fosc_TrCode_S = 5;
		if(Fosc_BitCode_S == 3) Fosc_TrCode_S = 6;
		if(Fosc_BitCode_S == 4) Fosc_TrCode_S = 7;

		// Convert decimal number 'Fosc_TrCode_S' into binary number and store in TempArray[]. //		
		Convert_Decimal_To_Binary(Fosc_TrCode_S, TempArray);

		// Load TempArray[] to WordArray[] at correct bit locations. //
		WordArray[12] = TempArray[0];
		WordArray[13] = TempArray[1];
		WordArray[14] = TempArray[2];

		// Load new trim code to shadow register. //
		Write_Word(g_SREG0, NOhex, WordArray, BIN); // Load trim code to shadow register. //

		// Start switching //
		FB_ovi->set_voltage(FB_ch, 1.0, RANGE_2_V); // OVI_1_2	
		wait.delay_10_us(10);
	
		// Check if frequency is above or below target. //
		tmu_6->arm();
		wait.delay_10_us(150); // Wait for TMU to trigger and to capture 128 cycles (need at least 1280us wait if 10us period)
		tmeas = tmu_6->read(1.5e-3);

		tmeas/=128;
		if (tmeas != 0)
			FreqMeas = 1/tmeas;
		else
		{			
			FreqMeas = 0.0;
			g_Error_Flag = -109;
		}
		Delta = FreqMeas - Fosc_Target_S;
		if (Delta < 0) // Remove negative //
			Delta *= -1;
		if (Delta < MinDelta)
		{
			MinDelta = Delta;
			BestFreq = FreqMeas;
			Best_TrCode = Fosc_TrCode_S;
			Best_BitCode = Fosc_BitCode_S;
		}

		// Stop switching //
		FB_ovi->set_voltage(FB_ch, 1.5, RANGE_2_V); // OVI_1_2	
		wait.delay_10_us(10);

		// Check if FreqMeas is above or below target. //
		if (FreqMeas < Fosc_Target_S) // Below target //
			LowerLimit = Fosc_BitCode_S;
		else // Above target //
			UpperLimit = Fosc_BitCode_S;		
	}
	g_Fosc_Sim_S = BestFreq;
	Fosc_TrCode_S = Best_TrCode;
	Fosc_BitCode_S = Best_BitCode;
	g_Fosc_Sim_Chg_S = ((g_Fosc_Sim_S - gFOSC_pt_S) / gFOSC_pt_S)*100; // In percent //

	// Load the shadow register with the final trim code Fosc_TrCode_S.  Must not overwrite any of the other shadow register bits! //	
	Convert_Decimal_To_Binary(Fosc_TrCode_S, TempArray); // Convert decimal number 'Fosc_TrCode_S' into binary number and store in TempArray[]. // 

	// Load TempArray[] to WordArray[] at correct bit locations. //
	WordArray[12] = TempArray[0];
	WordArray[13] = TempArray[1];
	WordArray[14] = TempArray[2];

	// Load final trim code to shadow register. //
	Write_Word(g_SREG0, NOhex, WordArray, BIN); // Load trim code to shadow register. //

	// Save the new values to the g_ShadowRegister[] array. //
	g_ShadowRegister[12] = WordArray[12];
	g_ShadowRegister[13] = WordArray[13];
	g_ShadowRegister[14] = WordArray[14];

	// Load individual bits for datalogging //
	EEtr_F1_S = WordArray[12];
	EEtr_F2_S = WordArray[13];
	EEtr_F3_S = WordArray[14];

	// Start Iint trim for Fosc-S. //
	// If the frequency is still more than MaxPercentDiff% away from target, then use the current 
	// reference trim to adjust it further.  eep_sreg[99:96]: trim_inno_iint[3:0] //
	Delta =( (g_Fosc_Sim_S - Fosc_Target_S)/ Fosc_Target_S ) * 100;
	if (Delta < 0) // Remove negative //
		Delta *= -1;
	if (Delta > MaxPercentDiff) // If more than MaxPercentDiff% from target. //
	{
		Trim_Iint_Flag = 1;

		// Start switching //
		FB_ovi->set_voltage(FB_ch, 1.0, RANGE_2_V); // OVI_1_2	
		wait.delay_10_us(20);

		// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
		WordArray[0] = g_ShadowRegister[96]; // EEtr_F_Iint1_S //
		WordArray[1] = g_ShadowRegister[97]; // EEtr_F_Iint2_S //
		WordArray[2] = g_ShadowRegister[98]; // EEtr_F_Iint3_S //
		WordArray[3] = g_ShadowRegister[99]; // EEtr_F_Iint4_S //
		WordArray[4] = g_ShadowRegister[100];
		WordArray[5] = g_ShadowRegister[101];
		WordArray[6] = g_ShadowRegister[102];
		WordArray[7] = g_ShadowRegister[103];
		WordArray[8] = g_ShadowRegister[104];
		WordArray[9] = g_ShadowRegister[105];
		WordArray[10] = g_ShadowRegister[106];
		WordArray[11] = g_ShadowRegister[107];
		WordArray[12] = g_ShadowRegister[108];
		WordArray[13] = g_ShadowRegister[109];
		WordArray[14] = g_ShadowRegister[110];
		WordArray[15] = g_ShadowRegister[111];

		// Find trim code closest to target. //
		UpperLimit = 9;
		LowerLimit = -8;
		MinDelta = 99999;
		BestFreq = 0;
		Best_TrCode = 0;
		Best_BitCode = 0;
		while ( (UpperLimit - LowerLimit) > 1)
		{
			F_Iint_BitCode = (UpperLimit + LowerLimit) / 2;
			
			// Convert BitCode to TrCode. Mapping between bit code and trim code. //
			if(F_Iint_BitCode == -7) F_Iint_TrCode = 7;
			if(F_Iint_BitCode == -6) F_Iint_TrCode = 6;
			if(F_Iint_BitCode == -5) F_Iint_TrCode = 5;
			if(F_Iint_BitCode == -4) F_Iint_TrCode = 4;
			if(F_Iint_BitCode == -3) F_Iint_TrCode = 3;
			if(F_Iint_BitCode == -2) F_Iint_TrCode = 2;
			if(F_Iint_BitCode == -1) F_Iint_TrCode = 1;
			if(F_Iint_BitCode == 0) F_Iint_TrCode = 0;
			if(F_Iint_BitCode == 1) F_Iint_TrCode = 8;
			if(F_Iint_BitCode == 2) F_Iint_TrCode = 9;
			if(F_Iint_BitCode == 3) F_Iint_TrCode = 10;
			if(F_Iint_BitCode == 4) F_Iint_TrCode = 11;
			if(F_Iint_BitCode == 5) F_Iint_TrCode = 12;
			if(F_Iint_BitCode == 6) F_Iint_TrCode = 13;
			if(F_Iint_BitCode == 7) F_Iint_TrCode = 14;
			if(F_Iint_BitCode == 8) F_Iint_TrCode = 15;

			// Convert decimal number 'F_Iint_TrCode' into binary number and store in TempArray[]. //		
			Convert_Decimal_To_Binary(F_Iint_TrCode, TempArray);

			// Load TempArray[] to WordArray[] at correct bit locations. //
			WordArray[0] = TempArray[0];
			WordArray[1] = TempArray[1];
			WordArray[2] = TempArray[2];
			WordArray[3] = TempArray[3];
			
			// Stop switching //
			FB_ovi->set_voltage(FB_ch, 1.5, RANGE_2_V); // OVI_1_2	
			wait.delay_10_us(10);

			// Load new trim code to shadow register. //
			Write_Word(g_SREG6, NOhex, WordArray, BIN); // Load trim code to shadow register. //

			// Start switching //
			FB_ovi->set_voltage(FB_ch, 1.0, RANGE_2_V); // OVI_1_2	
			wait.delay_10_us(10);
		
			// Check if frequency is above or below target. //
			tmu_6->arm();
			wait.delay_10_us(150); // Wait for TMU to trigger and to capture 128 cycles (need at least 1280us wait if 10us period)
			tmeas = tmu_6->read(1.5e-3);

			tmeas/=128;
			if (tmeas != 0)
				FreqMeas = 1/tmeas;
			else
			{			
				FreqMeas = 0.0;
				g_Error_Flag = -130;
			}
			Delta = FreqMeas - Fosc_Target_S;
			if (Delta < 0) // Remove negative //
				Delta *= -1;
			if (Delta < MinDelta)
			{
				MinDelta = Delta;
				BestFreq = FreqMeas;
				Best_TrCode = F_Iint_TrCode;
				Best_BitCode = F_Iint_BitCode;
			}

			// Check if FreqMeas is above or below target. //
			if (FreqMeas < Fosc_Target_S) // Below target //
				LowerLimit = F_Iint_BitCode;
			else // Above target //
				UpperLimit = F_Iint_BitCode;		
		}
		g_Fosc_Sim_S = BestFreq;
		F_Iint_TrCode = Best_TrCode;
		F_Iint_BitCode = Best_BitCode;
		g_Fosc_Sim_Chg_S = ((g_Fosc_Sim_S - gFOSC_pt_S) / gFOSC_pt_S)*100; // In percent //

		// Load the shadow register with the final trim code F_Iint_TrCode.  Must not overwrite any of the other shadow register bits! //	
		Convert_Decimal_To_Binary(F_Iint_TrCode, TempArray); // Convert decimal number 'F_Iint_TrCode' into binary number and store in TempArray[]. // 

		// Load TempArray[] to WordArray[] at correct bit locations. //
		WordArray[0] = TempArray[0];
		WordArray[1] = TempArray[1];
		WordArray[2] = TempArray[2];
		WordArray[3] = TempArray[3];

		// Stop switching //
		FB_ovi->set_voltage(FB_ch, 1.5, RANGE_2_V); // OVI_1_2	
		wait.delay_10_us(10);

		// Load final trim code to shadow register. //
		Write_Word(g_SREG6, NOhex, WordArray, BIN); // Load trim code to shadow register. //
		wait.delay_10_us(100);

		// Save the new values to the g_ShadowRegister[] array. //
		g_ShadowRegister[96] = WordArray[0];
		g_ShadowRegister[97] = WordArray[1];
		g_ShadowRegister[98] = WordArray[2];
		g_ShadowRegister[99] = WordArray[3];

		// Load individual bits for datalogging //
		EEtr_F_Iint1_s = WordArray[0];
		EEtr_F_Iint2_s = WordArray[1];
		EEtr_F_Iint3_s = WordArray[2];
		EEtr_F_Iint4_s = WordArray[3];
	}

	// Powerdown //
	Mux20_Open_relay(K50);
	D_dvi->set_voltage(D_ch, 0.0, VOLT_50_RANGE); // DVI_11_0
	D_dvi->set_current(D_ch, 300e-3, RANGE_300_MA);
	FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
	Disconnect_InvSyn_IM();
	tmu_6->open_relay(TMU_HIZ_DUT1); // Connect TMU HIZ to Drain
	SR_dvi2k->set_voltage(SR_ch, 0.5, VOLT_10_RANGE); // DVI_13_1, dvi2k, prevent undershoot //
	wait.delay_10_us(30); // prevent undershoot //
	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
	wait.delay_10_us(5); // prevent undershoot //
	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
	wait.delay_10_us(5); // prevent undershoot //
	Open_relay(K3); // Drain to RL pullup
	Mux20_Open_relay(K64);
	ovi_3->set_voltage(OVI_CHANNEL_7, 0, RANGE_5_V); // OVI_3_7 //
	Mux20_Open_relay(K37);
	Mux20_Open_relay(K38);
	Mux20_Open_relay(K40);
	Mux20_Open_relay(K39); 
	VPIN_ovi->set_voltage(VPIN_ch, 0.0, RANGE_10_V); // OVI_1_1 //
	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //
	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
	VBPP_ramp_down(4, 0, 0.5);
	wait.delay_10_us(10);
	VO_dvi->set_voltage(VO_ch, 0, VOLT_10_RANGE); // DVI_9_0 //
	wait.delay_10_us(20);
	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
	uVCCrampDown(1, 0, 0.1);
	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
	wait.delay_10_us(2);
	VBPS_ramp_down(3, 0, 150e-3);
	VBD_dvi->set_voltage(VBD_ch, 2, VOLT_5_RANGE); // DVI_21_0, prevent undershoot //
	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
	wait.delay_10_us(20);
	VBD_dvi->set_voltage(VBD_ch, 0, VOLT_5_RANGE); // DVI_21_0 //
	ddd_7->ddd_set_clock_period(Dclk_period);
	ddd_7->ddd_set_voltage_ref(DDD_Vref);
	ddd_7->ddd_run_pattern(Low_pat_start, Low_pat_stop);
	FB_ovi->connect(2);
	FB_ovi->set_voltage(FB_ch, 0, RANGE_2_V); // OVI_1_2 //

	// DDD level //
	g_DDD_Low = 0.0; // Save current value //
	g_DDD_High = 4.0; // Save current value //
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(200); // Wait for relays //

	// Reset bit63 shadow register if needed. //
	if (g_Bit63_Change_Flag == 1)
	{
		g_ShadowRegister[63] = 1;
		g_Bit63_Change_Flag = 0;
	}

	// Check error flag. //
	if (g_Error_Flag == -109) // Error.  Force failure. //
	{
		Fosc_Target_S = -999;
		Fosc_TrCode_S = -999;
		Fosc_BitCode_S = -999;
		EEtr_F1_S = -999;
		EEtr_F2_S = -999;
		EEtr_F3_S = -999;
		F_Iint_TrCode = -999;
		F_Iint_BitCode = -999;
		EEtr_F_Iint1_s = -999;
		EEtr_F_Iint2_s = -999;
		EEtr_F_Iint3_s = -999;
		EEtr_F_Iint4_s = -999;
	}

	// Datalog //
	PiDatalog(func, A_gFOSC_TARGET_S, Fosc_Target_S, 14, POWER_KILO);
	PiDatalog(func, A_Fosc_TrCode_S, Fosc_TrCode_S, 14, POWER_UNIT);
	PiDatalog(func, A_Fosc_BitCode_S, Fosc_BitCode_S, 14, POWER_UNIT);
	PiDatalog(func, A_IZtr_F1_S, EEtr_F1_S, 14, POWER_UNIT);
	PiDatalog(func, A_IZtr_F2_S, EEtr_F2_S, 14, POWER_UNIT);
	PiDatalog(func, A_IZtr_F3_S, EEtr_F3_S, 14, POWER_UNIT);
	if (Trim_Iint_Flag) // If trim_inno_iint[3:0] bits were trimmed. //
	{
		PiDatalog(func, A_F_Iint_TrCode, F_Iint_TrCode, 14, POWER_UNIT);
		PiDatalog(func, A_F_Iint_BitCode, F_Iint_BitCode, 14, POWER_UNIT);
		PiDatalog(func, A_EEtr_F_Iint1_s, EEtr_F_Iint1_s, 14, POWER_UNIT);
		PiDatalog(func, A_EEtr_F_Iint2_s, EEtr_F_Iint2_s, 14, POWER_UNIT);
		PiDatalog(func, A_EEtr_F_Iint3_s, EEtr_F_Iint3_s, 14, POWER_UNIT);
		PiDatalog(func, A_EEtr_F_Iint4_s, EEtr_F_Iint4_s, 14, POWER_UNIT);
	}
	// Test Time End //
	if (g_p_TstTime_Enble)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		Fosc_Trim_S_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_Fosc_Trim_S_TT, Fosc_Trim_S_TT, 14, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}
