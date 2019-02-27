//==============================================================================
// CV_Pre.cpp (User function)
// 
//    void CV_Pre_user_init(test_function& func)
//    void CV_Pre(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)
#include "CV_Pre.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void CV_Pre_user_init(test_function& func)
{
	CV_Pre_params *ours;
    ours = (CV_Pre_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void CV_Pre(test_function& func)
{
    // The two lines below must be the first two in the function.
    CV_Pre_params *ours;
    ours = (CV_Pre_params *)func.params;

	// Increment function number //
	gFuncNum++;	
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_CV_Pre, gFuncNum, 26, POWER_UNIT);

	// Skip Test if AbortTest set 
	if (AbortTest)
		return;

	// Skip trimming if g_p_Trim_Enable set //
	if (g_p_Trim_Enable == 0)
		return;

	if (g_Fn_CV_Pre == 0 )  return;

	// Test Time Begin //
	if (g_p_TstTime_Enble)
		g_begintime = g_mytimer.GetElapsedTime();

	// Test Names //
	//int fNum_CV_Pre = 0;
	//float CV_pt_S =0;
	float CV_Target_S = gCV_Vout_TARGET_Trimops;
	int CV_TrCode_S = 0;
	int CV_BitCode_S = 0;
	int EEtr_CV1_S = 0;
	int EEtr_CV2_S = 0;
	int EEtr_CV3_S = 0;
	int EEtr_CV4_S = 0;
	int EEtr_CV5_S = 0;
	int EEtr_CV6_S = 0;
	float CV_Sim_S = 0;
	float CV_Sim_Chg_S = 0;
	float CV_Pre_TT =0;

	// Declare Variables //
	int NObin[1] = {0}; // Place holder //
	int NOhex = 0; // Place holder //
	int WordArray[16] = {0};
	int TempArray[30] = {0};
	float WordData = 0;
	float UpperLimit = 0;
	float LowerLimit = 0;
	float Vforce = 0;
	float SRpinVolt = 0;
	Pulse pulse;

	// Open all relays //
	Initialize_Relays();

	// Initialize Instruments //
	Initialize_Instruments();

	// Drain //
	D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
	D_dvi->set_current(D_ch, 30e-3, RANGE_30_MA); // DVI_11_0 //

	// BPP //
	BPP_ovi->set_voltage(BPP_ch, 0.0, RANGE_10_V); // OVI_1_0 //
	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //

	// V pin //
	VPIN_ovi->set_voltage(VPIN_ch, 0.0, RANGE_10_V); // OVI_1_1 //
	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //

	// FW //
	Close_relay(K18);
	FW_dvi->set_voltage(FW_ch, 1, VOLT_10_RANGE); // DVI_11_1 //
	FW_dvi->set_current(FW_ch, 30e-3, RANGE_30_MA); // DVI_11_1 //

	// SR //
	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //

	// BPS //
	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //

	// IS //
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE); // DVI_13_0, dvi2k //
	IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //

	// Vout //
	VO_dvi->set_voltage(VO_ch, 4.5, VOLT_10_RANGE); // DVI_9_0 //
	VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //

	// COMP //
	FB_ovi->disconnect(2);

	// VBD //
	VBD_dvi->set_voltage(VBD_ch, 0.0, VOLT_5_RANGE); // DVI_21_0 //
	VBD_dvi->set_current(VBD_ch, 30e-6, RANGE_30_UA); // DVI_21_0, prevent glitch //
	wait.delay_10_us(25); // Prevent glitch //
	VBD_dvi->set_current(VBD_ch, 0.1e-9, RANGE_30_UA); // DVI_21_0, Float //

	// uVCC //
	uVCC_ovi->set_voltage(uVCC_ch, 0.0, RANGE_5_V); // OVI_3_2 //
	uVCC_ovi->set_current(uVCC_ch, 0.1e-9, RANGE_30_UA); // OVI_3_2, Float //

	// DDD level //
	g_DDD_Low = 0.0; // Save current value //
	g_DDD_High = 3.3; // Save current value //
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(g_DDDwait);

	// SDA //
	Mux20_Close_relay(K64); // SDA pullup to 3.3V through 1.5kohm resistor. //
	ovi_3->set_voltage(OVI_CHANNEL_7, g_I2C_Pullup, RANGE_5_V); // OVI_3_7 //
	ovi_3->set_current(OVI_CHANNEL_7, 30e-3, RANGE_30_MA); // OVI_3_7 //
	Mux20_Close_relay(K37); // Disconnect ovi from SDA. //
	Mux20_Close_relay(K38); // Connect SDA and SCL to DDD. //
	Mux20_Close_relay(K40); // Connect SDA and SCL to DDD. //

	// SCL //
	Mux20_Close_relay(K39); // Disconnect ovi from SCL. //
	ddd_7->ddd_run_pattern(g_SDA_SCL_Low_start, g_SDA_SCL_Low_stop);  // Start with SDA and SCL low with DDD. //
	
	// Set DDD for I2C. //
	ddd_7->ddd_set_clock_period(g_Dclk_I2C);
	ddd_7->ddd_set_voltage_ref(g_Vref_I2C);
		
	// Wait for relays //
	wait.delay_10_us(200); 

	// Powerup //
	BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
	wait.delay_10_us(100); // Must wait long enough for uVCC to come up before sending I2C commands. //

	// I2C into test mode. //  
	Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
	Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //

	Write_Word(g_TM_ANA, 0x0134, NObin, HEX); // TM_EN_SR_driver //

	Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //

	// Always load g_ShadowRegister[] array to shadow register of DUT after powerup if EEPROM has not yet been written. //
	LoadShadowRegister();

	// Float SR dvi //
	SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k, Float. //

	// Connect the FB comparator output to SR pin (CV comparator output). //
	Write_Word(g_TM_SEL, 0x0024, NObin, HEX);
	
	// Write 0x0820 to TM_CTRL.  This will force secondary in control and disconnect Vout from ADC.  Without this, the FB comparator reference is shifted causing a measuremnt error. //
	// Putting secondary in control prevents the FB comparator reference from shifting- this is the main cause of the FB comparator reference shift. //
	// Disconnecting Vout from ADC also prevents FB comparator reference from shifting, but not as much as putting secondary in control. //
	Write_Word(g_TM_CTRL, 0x0820, NObin, HEX);

	// CV regisiter is programmed to 5V by default on powerup. //

	// Binary search CV [on Vout pin] to get the CV_pt_S value, should be around CV_Target_S. //
	// Look for FB comparator output flip on SR pin. //
	SR_dvi2k->set_meas_mode(SR_ch, DVI_MEASURE_VOLTAGE); // DVI_13_1, dvi2k // 
	UpperLimit = (func.dlog->tests[A_CV_pt_S].f_max_limit_val[0])*1.1; // Get upper search limit //
	LowerLimit = (func.dlog->tests[A_CV_pt_S].f_min_limit_val[0])*0.9; // Get lower search limit //
//	if (g_p_Char_Enable == 1) // Widen the search limit for characterization. //
//	{
//		UpperLimit = (func.dlog->tests[A_CV_pt_S].f_max_limit_val[0])*1.4; // Get upper search limit //
//		LowerLimit = (func.dlog->tests[A_CV_pt_S].f_min_limit_val[0])*0.6; // Get lower search limit //
//	}
	Vforce = (UpperLimit + LowerLimit) / 2;
	if (Vforce < -9.99 || Vforce > 9.99) // Prevent out of range. //
	{
		Vforce = 0;
		g_Error_Flag = -111;
	}
	VO_dvi->set_voltage(VO_ch, Vforce, VOLT_10_RANGE); // DVI_9_0 //
	wait.delay_10_us(100);
	while ( (UpperLimit - LowerLimit) > .001)
	{
		Vforce = (UpperLimit + LowerLimit) / 2; 
		if (Vforce < -9.99 || Vforce > 9.99) // Prevent out of range. //
		{
			Vforce = 0;
			g_Error_Flag = -112;
			break;
		}
		VO_dvi->set_voltage(VO_ch, Vforce, VOLT_10_RANGE); // DVI_9_0 //
		wait.delay_10_us(100);
		SRpinVolt = SR_dvi2k->measure(); // DVI_13_1, dvi2k, check for CV comparator output flip. // 
		if (SRpinVolt < 1.5) // Below threshold.  CV comparator low. //
			LowerLimit = Vforce;
		else // Above threshold.  CV comparator high. //
			UpperLimit = Vforce;		
	}
	g_CV_pt_S = Vforce;

	// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
	WordArray[0] = g_ShadowRegister[16]; // EEtr_CV1_S //
	WordArray[1] = g_ShadowRegister[17]; // EEtr_CV2_S // 
	WordArray[2] = g_ShadowRegister[18]; // EEtr_CV3_S //
	WordArray[3] = g_ShadowRegister[19]; // EEtr_CV4_S //
	WordArray[4] = g_ShadowRegister[20]; // EEtr_CV5_S //
	WordArray[5] = g_ShadowRegister[21]; // EEtr_CV6_S //
	WordArray[6] = g_ShadowRegister[22];
	WordArray[7] = g_ShadowRegister[23];
	WordArray[8] = g_ShadowRegister[24];
	WordArray[9] = g_ShadowRegister[25];
	WordArray[10] = g_ShadowRegister[26];
	WordArray[11] = g_ShadowRegister[27];
	WordArray[12] = g_ShadowRegister[28];
	WordArray[13] = g_ShadowRegister[29];
	WordArray[14] = g_ShadowRegister[30];
	WordArray[15] = g_ShadowRegister[31];

	// Find trim code closest to target. //
	// Apply CV_Target_S at VOUT pin, write the I2C command to set_CV to be CV_Target_S; adjust the trim code through I2C until the comparator triggered. //
	VO_dvi->set_voltage(VO_ch, CV_Target_S, VOLT_10_RANGE); // DVI_9_0 //

	// CV regisiter is programmed to 5V by default on powerup. //

	// Find trim code closest to target. //
	UpperLimit = 33;
	LowerLimit = -32; 
	while ( (UpperLimit - LowerLimit) > 1)
	{
		CV_BitCode_S = (UpperLimit + LowerLimit) / 2;
		
		// Convert BitCode to TrCode. Mapping between bit code and trim code. //
		if(CV_BitCode_S == -31) CV_TrCode_S = 31;
		if(CV_BitCode_S == -30) CV_TrCode_S = 30;
		if(CV_BitCode_S == -29) CV_TrCode_S = 29;
		if(CV_BitCode_S == -28) CV_TrCode_S = 28;
		if(CV_BitCode_S == -27) CV_TrCode_S = 27;
		if(CV_BitCode_S == -26) CV_TrCode_S = 26;
		if(CV_BitCode_S == -25) CV_TrCode_S = 25;
		if(CV_BitCode_S == -24) CV_TrCode_S = 24;
		if(CV_BitCode_S == -23) CV_TrCode_S = 23;
		if(CV_BitCode_S == -22) CV_TrCode_S = 22;
		if(CV_BitCode_S == -21) CV_TrCode_S = 21;
		if(CV_BitCode_S == -20) CV_TrCode_S = 20;
		if(CV_BitCode_S == -19) CV_TrCode_S = 19;
		if(CV_BitCode_S == -18) CV_TrCode_S = 18;
		if(CV_BitCode_S == -17) CV_TrCode_S = 17;
		if(CV_BitCode_S == -16) CV_TrCode_S = 16;
		if(CV_BitCode_S == -15) CV_TrCode_S = 15;
		if(CV_BitCode_S == -14) CV_TrCode_S = 14;
		if(CV_BitCode_S == -13) CV_TrCode_S = 13;
		if(CV_BitCode_S == -12) CV_TrCode_S = 12;
		if(CV_BitCode_S == -11) CV_TrCode_S = 11;
		if(CV_BitCode_S == -10) CV_TrCode_S = 10;
		if(CV_BitCode_S == -9) CV_TrCode_S = 9;
		if(CV_BitCode_S == -8) CV_TrCode_S = 8;
		if(CV_BitCode_S == -7) CV_TrCode_S = 7;
		if(CV_BitCode_S == -6) CV_TrCode_S = 6;
		if(CV_BitCode_S == -5) CV_TrCode_S = 5;
		if(CV_BitCode_S == -4) CV_TrCode_S = 4;
		if(CV_BitCode_S == -3) CV_TrCode_S = 3;
		if(CV_BitCode_S == -2) CV_TrCode_S = 2;
		if(CV_BitCode_S == -1) CV_TrCode_S = 1;
		if(CV_BitCode_S == 0) CV_TrCode_S = 0;
		if(CV_BitCode_S == 1) CV_TrCode_S = 32;
		if(CV_BitCode_S == 2) CV_TrCode_S = 33;
		if(CV_BitCode_S == 3) CV_TrCode_S = 34;
		if(CV_BitCode_S == 4) CV_TrCode_S = 35;
		if(CV_BitCode_S == 5) CV_TrCode_S = 36;
		if(CV_BitCode_S == 6) CV_TrCode_S = 37;
		if(CV_BitCode_S == 7) CV_TrCode_S = 38;
		if(CV_BitCode_S == 8) CV_TrCode_S = 39;
		if(CV_BitCode_S == 9) CV_TrCode_S = 40;
		if(CV_BitCode_S == 10) CV_TrCode_S = 41;
		if(CV_BitCode_S == 11) CV_TrCode_S = 42;
		if(CV_BitCode_S == 12) CV_TrCode_S = 43;
		if(CV_BitCode_S == 13) CV_TrCode_S = 44;
		if(CV_BitCode_S == 14) CV_TrCode_S = 45;
		if(CV_BitCode_S == 15) CV_TrCode_S = 46;
		if(CV_BitCode_S == 16) CV_TrCode_S = 47;
		if(CV_BitCode_S == 17) CV_TrCode_S = 48;
		if(CV_BitCode_S == 18) CV_TrCode_S = 49;
		if(CV_BitCode_S == 19) CV_TrCode_S = 50;
		if(CV_BitCode_S == 20) CV_TrCode_S = 51;
		if(CV_BitCode_S == 21) CV_TrCode_S = 52;
		if(CV_BitCode_S == 22) CV_TrCode_S = 53;
		if(CV_BitCode_S == 23) CV_TrCode_S = 54;
		if(CV_BitCode_S == 24) CV_TrCode_S = 55;
		if(CV_BitCode_S == 25) CV_TrCode_S = 56;
		if(CV_BitCode_S == 26) CV_TrCode_S = 57;
		if(CV_BitCode_S == 27) CV_TrCode_S = 58;
		if(CV_BitCode_S == 28) CV_TrCode_S = 59;
		if(CV_BitCode_S == 29) CV_TrCode_S = 60;
		if(CV_BitCode_S == 30) CV_TrCode_S = 61;
		if(CV_BitCode_S == 31) CV_TrCode_S = 62;
		if(CV_BitCode_S == 32) CV_TrCode_S = 63;

		// Convert decimal number 'CV_TrCode_S' into binary number and store in TempArray[]. //		
		Convert_Decimal_To_Binary(CV_TrCode_S, TempArray);

		// Load TempArray[] to WordArray[] at correct bit locations. //
		WordArray[0] = TempArray[0];
		WordArray[1] = TempArray[1]; 
		WordArray[2] = TempArray[2]; 
		WordArray[3] = TempArray[3]; 
		WordArray[4] = TempArray[4]; 
		WordArray[5] = TempArray[5]; 

		// Load new trim code to shadow register. //
		Write_Word(g_SREG1, NOhex, WordArray, BIN); // Load trim code to shadow register. //
		wait.delay_10_us(100);

		// Check if CV comparator output has flipped. //
		SRpinVolt = SR_dvi2k->measure(); // DVI_13_1, dvi2k, check for CV comparator output flip. // 
		if (SRpinVolt > 1.5) // Below target //
			LowerLimit = CV_BitCode_S;
		else // Above target //
			UpperLimit = CV_BitCode_S;		
	}

	// Load the shadow register with the final trim code CV_TrCode_S.  Must not overwrite any of the other shadow register bits! //	
	Convert_Decimal_To_Binary(CV_TrCode_S, TempArray); // Convert decimal number 'CV_TrCode_S' into binary number and store in TempArray[]. // 

	// Load TempArray[] to WordArray[] at correct bit locations. //
	WordArray[0] = TempArray[0];
	WordArray[1] = TempArray[1]; 
	WordArray[2] = TempArray[2]; 
	WordArray[3] = TempArray[3]; 
	WordArray[4] = TempArray[4]; 
	WordArray[5] = TempArray[5]; 

	// Load final trim code to shadow register. //
	Write_Word(g_SREG1, NOhex, WordArray, BIN); // Load trim code to shadow register. //

	// Save the new values to the g_ShadowRegister[] array. //
	g_ShadowRegister[16] = WordArray[0];
	g_ShadowRegister[17] = WordArray[1];
	g_ShadowRegister[18] = WordArray[2];
	g_ShadowRegister[19] = WordArray[3];
	g_ShadowRegister[20] = WordArray[4];
	g_ShadowRegister[21] = WordArray[5];

	// Load individual bits for datalogging //
	EEtr_CV1_S = WordArray[0];
	EEtr_CV2_S = WordArray[1];
	EEtr_CV3_S = WordArray[2];
	EEtr_CV4_S = WordArray[3];
	EEtr_CV5_S = WordArray[4];
	EEtr_CV6_S = WordArray[5];

	if (g_p_Char_Enable) // Characterization only //
	{
		// CV_Sim_S. Measure the final value after shadow register is loaded with final trim code. //
		// Binary search CV [on Vout pin] to get the CV_Sim_S value, should be around CV_Target_S. //
		// Look for FB comparator output flip on SR pin. //
		SR_dvi2k->set_meas_mode(SR_ch, DVI_MEASURE_VOLTAGE); // DVI_13_1, dvi2k // 
		UpperLimit = (func.dlog->tests[A_CV_Sim_S].f_max_limit_val[0])*1.1; // Get upper search limit //
		LowerLimit = (func.dlog->tests[A_CV_Sim_S].f_min_limit_val[0])*0.9; // Get lower search limit //
//		if (g_p_Char_Enable == 1) // Widen the search limit for characterization. //
//		{
//			UpperLimit = (func.dlog->tests[A_CV_Sim_S].f_max_limit_val[0])*1.5; // Get upper search limit //
//			LowerLimit = (func.dlog->tests[A_CV_Sim_S].f_min_limit_val[0])*0.5; // Get lower search limit //
//		}
		Vforce = (UpperLimit + LowerLimit) / 2;
		if (Vforce < -9.99 || Vforce > 9.99) // Prevent out of range. //
		{
			Vforce = 0;
			g_Error_Flag = -113;
		}
		VO_dvi->set_voltage(VO_ch, Vforce, VOLT_10_RANGE); // DVI_9_0 //
		wait.delay_10_us(100);
		while ( (UpperLimit - LowerLimit) > .001)
		{
			Vforce = (UpperLimit + LowerLimit) / 2; 
			if (Vforce < -9.99 || Vforce > 9.99) // Prevent out of range. //
			{
				Vforce = 0;
				g_Error_Flag = -114;
				break;
			}
			VO_dvi->set_voltage(VO_ch, Vforce, VOLT_10_RANGE); // DVI_9_0 //
			wait.delay_10_us(30);
			SRpinVolt = SR_dvi2k->measure(); // DVI_13_1, dvi2k, check for CV comparator output flip. // 
			if (SRpinVolt < 1.5) // Below threshold.  CV comparator low. //
				LowerLimit = Vforce;
			else // Above threshold.  CV comparator high. //
				UpperLimit = Vforce;		
		}
		CV_Sim_S = Vforce;
		CV_Sim_Chg_S = ((CV_Sim_S - g_CV_pt_S) / g_CV_pt_S)*100; // In percent //
	}

	// Reset test mode control register for next test. //
	Write_Word(g_TM_CTRL, 0x0000, NObin, HEX);

	// Powerdown //
//	Open_relay(K18);
//	FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
//	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
	SR_dvi2k->set_voltage(SR_ch, 5, VOLT_10_RANGE); // DVI_13_1, dvi2k, prevent undershoot //
	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
	wait.delay_10_us(45); // prevent SR undershoot //
	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
//	BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
//	VO_dvi->set_voltage(VO_ch, 4.7, VOLT_10_RANGE);
//	wait.delay_10_us(5);
//	VO_dvi->set_voltage(VO_ch, 4.5, VOLT_10_RANGE);
//	FB_ovi->connect(2);
//	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
//	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
//	Mux20_Open_relay(K64);
//	ovi_3->set_voltage(OVI_CHANNEL_7, 0.0, RANGE_10_V); // OVI_3_7 //
//	Mux20_Open_relay(K37);
//	Mux20_Open_relay(K38);
//	Mux20_Open_relay(K40);
//	Mux20_Open_relay(K39);
//	ddd_7->ddd_set_clock_period(Dclk_period);
//	ddd_7->ddd_set_voltage_ref(DDD_Vref);

	// DDD level //
//	g_DDD_Low = 0.0; // Save current value //
//	g_DDD_High = 4.0; // Save current value //
//	wait.delay_10_us(100);
//	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
//	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(200); // Wait for relays //

	// Datalog //
	//PiDatalog(func, A_Func_Num_CV_Pre, fNum_CV_Pre, 26, POWER_UNIT);
	PiDatalog(func, A_CV_pt_S, g_CV_pt_S, 26, POWER_UNIT);
	PiDatalog(func, A_CV_target_S, CV_Target_S, 26, POWER_UNIT);
	PiDatalog(func, A_CV_TrCode_S, CV_TrCode_S, 26, POWER_UNIT);
	PiDatalog(func, A_CV_BitCode_S, CV_BitCode_S, 26, POWER_UNIT);
	PiDatalog(func, A_Iztr_CV1_S, EEtr_CV1_S, 26, POWER_UNIT);
	PiDatalog(func, A_Iztr_CV2_S, EEtr_CV2_S, 26, POWER_UNIT);
	PiDatalog(func, A_Iztr_CV3_S, EEtr_CV3_S, 26, POWER_UNIT);
	PiDatalog(func, A_Iztr_CV4_S, EEtr_CV4_S, 26, POWER_UNIT);
	PiDatalog(func, A_Iztr_CV5_S, EEtr_CV5_S, 26, POWER_UNIT);
	PiDatalog(func, A_Iztr_CV6_S, EEtr_CV6_S, 26, POWER_UNIT);
	if (g_p_Char_Enable) // Characterization only //
	{
		PiDatalog(func, A_CV_Sim_S, CV_Sim_S, 26, POWER_UNIT);
		PiDatalog(func, A_CV_Sim_Chg_S, CV_Sim_Chg_S, 26, POWER_UNIT);
	}
	
	// Test Time End //
	if (g_p_TstTime_Enble)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		CV_Pre_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_CV_Pre_TT, CV_Pre_TT, 26, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}
