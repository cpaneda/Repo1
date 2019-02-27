//==============================================================================
// ISvth3X_Pre_S.cpp (User function)
// 
//    void ISvth3X_Pre_S_user_init(test_function& func)
//    void ISvth3X_Pre_S(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "ISvth3X_Pre_S.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void ISvth3X_Pre_S_user_init(test_function& func)
{
	ISvth3X_Pre_S_params *ours;
    ours = (ISvth3X_Pre_S_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void ISvth3X_Pre_S(test_function& func)
{
    // The two lines below must be the first two in the function.
    ISvth3X_Pre_S_params *ours;
    ours = (ISvth3X_Pre_S_params *)func.params;

	// Increment function number //
	gFuncNum++;

////	// Datalog gFuncNum variable //
////	if(gDisplay_FuncNum)
////		PiDatalog(func, A_Func_Num_ISvth_Pre_S, gFuncNum, 26, POWER_UNIT);
////
////	// Skip Test if AbortTest set 
////	if (AbortTest)
////		return;
////
////	// Skip trimming if g_p_Trim_Enable set //
////	if (g_p_Trim_Enable == 0)
////		return;
////
////	if (g_Fn_ISvth_Pre_S == 0 )  return;
////
////	// Test Time Begin //
////	 if (g_p_TstTime_Enble)
////	 	g_begintime = g_mytimer.GetElapsedTime();
////
////	// Test Names //
////	float ISvth_Target3X_S = 3 * gISvth_TARGET_Trimops; // Target is 3X. //
////	int ISvth_TrCode_S = 0;
////	int ISvth_BitCode_S = 0;
////	int EEtr_ISvth3X1_S = 0;
////	int EEtr_ISvth3X2_S = 0;
////	int EEtr_ISvth3X3_S = 0;
////	int EEtr_ISvth3X4_S = 0;
////	int EEtr_ISvth3X5_S = 0;
////	int EEtr_ISvth3X6_S = 0;
////	float ISvth3X_Sim_S = 0;
////	float ISvth_Sim_Chg_S = 0;
////	float ISvth_Pre_S_TT =0;
////
////	// Declare Variables //
////	int NObin[1] = {0}; // Place holder //
////	int NOhex = 0; // Place holder //
////	int WordArray[16] = {0};
////	int TempArray[30] = {0};
////	float UpperLimit = 0;
////	float LowerLimit = 0;
////	float Vforce = 0;
////	float SRpinVolt = 0;
////	Pulse pulse;
////
////	// Open all relays //
//////	Initialize_Relays();
////
////	// Initialize Instruments //
//////	Initialize_Instruments();
////
////
////	// Drain //
////	D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
////	D_dvi->set_current(D_ch, 30e-3, RANGE_30_MA); // DVI_11_0 //
////
////	// BPP //
////	BPP_ovi->set_voltage(BPP_ch, 0.0, RANGE_10_V); // OVI_1_0 //
////	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
////
////	// V pin //
////	VPIN_ovi->set_voltage(VPIN_ch, 0.0, RANGE_10_V); // OVI_1_1 //
////	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //
////
////	// FW //
////	Close_relay(K18);
////	FW_dvi->set_voltage(FW_ch, 1, VOLT_10_RANGE); // DVI_11_1 //
////	FW_dvi->set_current(FW_ch, 30e-3, RANGE_30_MA); // DVI_11_1 //
////
////	// SR //
////	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
////	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
////	SR_dvi2k->set_meas_mode(SR_ch, DVI_MEASURE_VOLTAGE); // DVI_13_1, dvi2k // 
////
////	// BPS //
//////	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
//////	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //
////
////	// IS //
////	mux_14->close_relay(MUX_2_GND);
////	Close_relay(K24); // Connect IS pin to 20X buffer. //
////	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_5_RANGE); // DVI_13_0, dvi2k //
////	IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //
////
////	// Vout //
////	VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //
////	VO_dvi->set_voltage(VO_ch, 4.5, VOLT_10_RANGE); // DVI_9_0 //
////
////	// FB (COMP) //
////	FB_ovi->disconnect(2);
////
////	// VBD //
////	VBD_dvi->set_voltage(VBD_ch, 0.0, VOLT_5_RANGE); // DVI_21_0 //
//////	VBD_dvi->set_current(VBD_ch, 30e-6, RANGE_30_UA); // DVI_21_0, prevent glitch //
////	wait.delay_10_us(25); // Prevent glitch //
////	VBD_dvi->set_current(VBD_ch, 0.1e-9, RANGE_30_UA); // DVI_21_0, Float //
////
////	// uVCC //
////	uVCC_ovi->set_voltage(uVCC_ch, 0.0, RANGE_5_V); // OVI_3_2 //
////	uVCC_ovi->set_current(uVCC_ch, 0.1e-9, RANGE_30_UA); // OVI_3_2, Float //
////
////	// DDD level //
//////	g_DDD_Low = 0.0; // Save current value //
//////	g_DDD_High = 3.3; // Save current value //
//////	wait.delay_10_us(100);
//////	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
//////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
//////	wait.delay_10_us(100);
////
////	// SDA //
////	Mux20_Close_relay(K64); // SDA pullup to 3.3V through 1.5kohm resistor. //
////	ovi_3->set_voltage(OVI_CHANNEL_7, g_I2C_Pullup, RANGE_5_V); // OVI_3_7 //
////	ovi_3->set_current(OVI_CHANNEL_7, 30e-3, RANGE_30_MA); // OVI_3_7 //
////	Mux20_Close_relay(K37); // Disconnect ovi from SDA. //
////	Mux20_Close_relay(K38); // Connect SDA and SCL to DDD. //
////	Mux20_Close_relay(K40); // Connect SDA and SCL to DDD. //
////
////	// SCL //
////	Mux20_Close_relay(K39); // Disconnect ovi from SCL. //
////	ddd_7->ddd_run_pattern(g_SDA_SCL_Low_start, g_SDA_SCL_Low_stop);  // Start with SDA and SCL low with DDD. //
////	
////	// Set DDD for I2C. //
//////	ddd_7->ddd_set_clock_period(g_Dclk_I2C);
//////	ddd_7->ddd_set_voltage_ref(g_Vref_I2C);
////		
////	// Wait for relays //
////	wait.delay_10_us(200); 
////		
////	// Powerup //
//////	BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
//////	wait.delay_10_us(100); // Must wait long enough for uVCC to come up before sending I2C commands. //
////
////	// I2C into test mode //
//////	Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
//////	Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //
////
//////	Write_Word(g_TM_ANA, 0x0134, NObin, HEX); // TM_EN_SR_driver //
////	
////	//Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //
////
////	Write_Byte(g_CCSCL, 0x00, NObin, HEX); // Disable CCSCL //
////	
////	// Always load g_ShadowRegister[] array to shadow register of DUT after powerup if EEPROM has not yet been written. //
////	LoadShadowRegister();
////
////	// SR //
////	SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k, Float. //
////
////	// Write the I2C command to connect the HC_ signal to SR pin. //
////	Write_Word(g_TM_SEL, 0x0020, NObin, HEX); // Write the I2C command to connect the HC_ signal to SR pin. //
////
////	// ISvth_pt_S //
////	// Binary search on IS pin looking at SR pin flip state //
////	SR_dvi2k->set_meas_mode(SR_ch, DVI_MEASURE_VOLTAGE); // DVI_13_1, dvi2k // 
////	UpperLimit = (func.dlog->tests[A_ISvth3X_pt_S].f_max_limit_val[0])*1.1; // Get upper search limit //
////	LowerLimit = (func.dlog->tests[A_ISvth3X_pt_S].f_min_limit_val[0])*0.9; // Get lower search limit //
////	if (g_p_Char_Enable == 1) // Widen the search limit for characterization. //
////	{
////		UpperLimit = (func.dlog->tests[A_ISvth3X_pt_S].f_max_limit_val[0])*1.5; // Get upper search limit //
////		LowerLimit = (func.dlog->tests[A_ISvth3X_pt_S].f_min_limit_val[0])*0.5; // Get lower search limit //
////	}
////	UpperLimit *= g_ISbuff_Gain32; // IS pin is connected to 20X buffer. //
////	LowerLimit *= g_ISbuff_Gain32; // IS pin is connected to 20X buffer. //
////	Vforce = (UpperLimit + LowerLimit) / 2;
////	if (Vforce < -4.99 || Vforce > 4.99) // Prevent out of range. //
////	{
////		Vforce = 0;
////		g_Error_Flag = -115;
////	}
////	IS_dvi2k->set_voltage(IS_ch, Vforce, VOLT_5_RANGE); // DVI_13_0, dvi2k //
////	wait.delay_10_us(100);
////	while ( (UpperLimit - LowerLimit) > .001)
////	{
////		Vforce = (UpperLimit + LowerLimit) / 2; 
////		if (Vforce < -4.99 || Vforce > 4.99) // Prevent out of range. //
////		{
////			Vforce = 0;
////			g_Error_Flag = -116;
////			break;
////		}
////		IS_dvi2k->set_voltage(IS_ch, Vforce, VOLT_5_RANGE); // DVI_13_0, dvi2k //
////		wait.delay_10_us(100);
////		SRpinVolt = SR_dvi2k->measure(); // DVI_13_1, dvi2k // 
////		if (SRpinVolt < 1.5) // Below threshold //
////			LowerLimit = Vforce;
////		else // Above threshold //
////			UpperLimit = Vforce;		
////	}
////	g_ISvth3X_pt_S = Vforce;
////	g_ISvth3X_pt_S = g_ISvth3X_pt_S/g_ISbuff_Gain32; // IS pin is connected to 20X buffer. //
////
////	// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
////	WordArray[0] = g_ShadowRegister[32]; // EEtr_ISvth3X1_S //
////	WordArray[1] = g_ShadowRegister[33]; // EEtr_ISvth3X2_S //
////	WordArray[2] = g_ShadowRegister[34]; // EEtr_ISvth3X3_S //
////	WordArray[3] = g_ShadowRegister[35]; // EEtr_ISvth3X4_S //
////	WordArray[4] = g_ShadowRegister[36]; // EEtr_ISvth3X5_S //
////	WordArray[5] = g_ShadowRegister[37]; // EEtr_ISvth3X6_S //
////	WordArray[6] = g_ShadowRegister[38];
////	WordArray[7] = g_ShadowRegister[39];
////	WordArray[8] = g_ShadowRegister[40];
////	WordArray[9] = g_ShadowRegister[41];
////	WordArray[10] = g_ShadowRegister[42];
////	WordArray[11] = g_ShadowRegister[43];
////	WordArray[12] = g_ShadowRegister[44];
////	WordArray[13] = g_ShadowRegister[45];
////	WordArray[14] = g_ShadowRegister[46];
////	WordArray[15] = g_ShadowRegister[47];
////
////	// Find trim code closest to target. //
////	// Apply ISvth_Target3X_S at IS pin, adjust the trim code until the SR pin changes state. //
////	//Vforce = 20 * ISvth_Target3X_S; // IS pin is connected to 20X buffer. //
////	Vforce = g_ISbuff_Gain32 * ISvth_Target3X_S; // IS pin is connected to 20X buffer. //
////	if (Vforce < -4.999 || Vforce > 4.999) // Prevent out of range. //
////	{
////		Vforce = 0;
////		g_Error_Flag = -199;
////	}
////	IS_dvi2k->set_voltage(IS_ch, Vforce, VOLT_5_RANGE); // DVI_13_0, dvi2k //
////
////	// Find trim code closest to target. //
////	UpperLimit = 33;
////	LowerLimit = -32; 
////	while ( (UpperLimit - LowerLimit) > 1)
////	{
////		ISvth_BitCode_S = (UpperLimit + LowerLimit) / 2;
////		
////		// Convert BitCode to TrCode. Mapping between bit code and trim code. //
////		if(ISvth_BitCode_S == -31) ISvth_TrCode_S = 31;
////		if(ISvth_BitCode_S == -30) ISvth_TrCode_S = 30;
////		if(ISvth_BitCode_S == -29) ISvth_TrCode_S = 29;
////		if(ISvth_BitCode_S == -28) ISvth_TrCode_S = 28;
////		if(ISvth_BitCode_S == -27) ISvth_TrCode_S = 27;
////		if(ISvth_BitCode_S == -26) ISvth_TrCode_S = 26;
////		if(ISvth_BitCode_S == -25) ISvth_TrCode_S = 25;
////		if(ISvth_BitCode_S == -24) ISvth_TrCode_S = 24;
////		if(ISvth_BitCode_S == -23) ISvth_TrCode_S = 23;
////		if(ISvth_BitCode_S == -22) ISvth_TrCode_S = 22;
////		if(ISvth_BitCode_S == -21) ISvth_TrCode_S = 21;
////		if(ISvth_BitCode_S == -20) ISvth_TrCode_S = 20;
////		if(ISvth_BitCode_S == -19) ISvth_TrCode_S = 19;
////		if(ISvth_BitCode_S == -18) ISvth_TrCode_S = 18;
////		if(ISvth_BitCode_S == -17) ISvth_TrCode_S = 17;
////		if(ISvth_BitCode_S == -16) ISvth_TrCode_S = 16;
////		if(ISvth_BitCode_S == -15) ISvth_TrCode_S = 15;
////		if(ISvth_BitCode_S == -14) ISvth_TrCode_S = 14;
////		if(ISvth_BitCode_S == -13) ISvth_TrCode_S = 13;
////		if(ISvth_BitCode_S == -12) ISvth_TrCode_S = 12;
////		if(ISvth_BitCode_S == -11) ISvth_TrCode_S = 11;
////		if(ISvth_BitCode_S == -10) ISvth_TrCode_S = 10;
////		if(ISvth_BitCode_S == -9) ISvth_TrCode_S = 9;
////		if(ISvth_BitCode_S == -8) ISvth_TrCode_S = 8;
////		if(ISvth_BitCode_S == -7) ISvth_TrCode_S = 7;
////		if(ISvth_BitCode_S == -6) ISvth_TrCode_S = 6;
////		if(ISvth_BitCode_S == -5) ISvth_TrCode_S = 5;
////		if(ISvth_BitCode_S == -4) ISvth_TrCode_S = 4;
////		if(ISvth_BitCode_S == -3) ISvth_TrCode_S = 3;
////		if(ISvth_BitCode_S == -2) ISvth_TrCode_S = 2;
////		if(ISvth_BitCode_S == -1) ISvth_TrCode_S = 1;
////		if(ISvth_BitCode_S == 0) ISvth_TrCode_S = 0;
////		if(ISvth_BitCode_S == 1) ISvth_TrCode_S = 32;
////		if(ISvth_BitCode_S == 2) ISvth_TrCode_S = 33;
////		if(ISvth_BitCode_S == 3) ISvth_TrCode_S = 34;
////		if(ISvth_BitCode_S == 4) ISvth_TrCode_S = 35;
////		if(ISvth_BitCode_S == 5) ISvth_TrCode_S = 36;
////		if(ISvth_BitCode_S == 6) ISvth_TrCode_S = 37;
////		if(ISvth_BitCode_S == 7) ISvth_TrCode_S = 38;
////		if(ISvth_BitCode_S == 8) ISvth_TrCode_S = 39;
////		if(ISvth_BitCode_S == 9) ISvth_TrCode_S = 40;
////		if(ISvth_BitCode_S == 10) ISvth_TrCode_S = 41;
////		if(ISvth_BitCode_S == 11) ISvth_TrCode_S = 42;
////		if(ISvth_BitCode_S == 12) ISvth_TrCode_S = 43;
////		if(ISvth_BitCode_S == 13) ISvth_TrCode_S = 44;
////		if(ISvth_BitCode_S == 14) ISvth_TrCode_S = 45;
////		if(ISvth_BitCode_S == 15) ISvth_TrCode_S = 46;
////		if(ISvth_BitCode_S == 16) ISvth_TrCode_S = 47;
////		if(ISvth_BitCode_S == 17) ISvth_TrCode_S = 48;
////		if(ISvth_BitCode_S == 18) ISvth_TrCode_S = 49;
////		if(ISvth_BitCode_S == 19) ISvth_TrCode_S = 50;
////		if(ISvth_BitCode_S == 20) ISvth_TrCode_S = 51;
////		if(ISvth_BitCode_S == 21) ISvth_TrCode_S = 52;
////		if(ISvth_BitCode_S == 22) ISvth_TrCode_S = 53;
////		if(ISvth_BitCode_S == 23) ISvth_TrCode_S = 54;
////		if(ISvth_BitCode_S == 24) ISvth_TrCode_S = 55;
////		if(ISvth_BitCode_S == 25) ISvth_TrCode_S = 56;
////		if(ISvth_BitCode_S == 26) ISvth_TrCode_S = 57;
////		if(ISvth_BitCode_S == 27) ISvth_TrCode_S = 58;
////		if(ISvth_BitCode_S == 28) ISvth_TrCode_S = 59;
////		if(ISvth_BitCode_S == 29) ISvth_TrCode_S = 60;
////		if(ISvth_BitCode_S == 30) ISvth_TrCode_S = 61;
////		if(ISvth_BitCode_S == 31) ISvth_TrCode_S = 62;
////		if(ISvth_BitCode_S == 32) ISvth_TrCode_S = 63;
////
////		// Convert decimal number 'ISvth_TrCode_S' into binary number and store in TempArray[]. //		
////		Convert_Decimal_To_Binary(ISvth_TrCode_S, TempArray);
////
////		// Load TempArray[] to WordArray[] at correct bit locations. //
////		WordArray[0] = TempArray[0];
////		WordArray[1] = TempArray[1]; 
////		WordArray[2] = TempArray[2]; 
////		WordArray[3] = TempArray[3]; 
////		WordArray[4] = TempArray[4]; 
////		WordArray[5] = TempArray[5]; 
////
////		// Load new trim code to shadow register. //
////		Write_Word(g_SREG2, NOhex, WordArray, BIN); // Load trim code to shadow register. //
////		wait.delay_10_us(100);
////
////		// Check if SR comparator output has flipped. //
////		SRpinVolt = SR_dvi2k->measure(); // DVI_13_1, dvi2k // 
////		if (SRpinVolt > 1.5) // Below target //
////			LowerLimit = ISvth_BitCode_S;
////		else // Above target //
////			UpperLimit = ISvth_BitCode_S;		
////	}
////
////	// Load the shadow register with the final trim code ISvth_TrCode_S.  Must not overwrite any of the other shadow register bits! //	
////	Convert_Decimal_To_Binary(ISvth_TrCode_S, TempArray); // Convert decimal number 'ISvth_TrCode_S' into binary number and store in TempArray[]. // 
////	
////	// Load TempArray[] to WordArray[] at correct bit locations. //
////	WordArray[0] = TempArray[0];
////	WordArray[1] = TempArray[1]; 
////	WordArray[2] = TempArray[2]; 
////	WordArray[3] = TempArray[3]; 
////	WordArray[4] = TempArray[4]; 
////	WordArray[5] = TempArray[5]; 
////
////	// Load final trim code to shadow register. //d
////	Write_Word(g_SREG2, NOhex, WordArray, BIN); // Load trim code to shadow register. //
////
////	// Save the new values to the g_ShadowRegister[] array. //
////	g_ShadowRegister[32] = WordArray[0];
////	g_ShadowRegister[33] = WordArray[1];
////	g_ShadowRegister[34] = WordArray[2];
////	g_ShadowRegister[35] = WordArray[3];
////	g_ShadowRegister[36] = WordArray[4];
////	g_ShadowRegister[37] = WordArray[5];
////
////	// Load individual bits for datalogging //
////	EEtr_ISvth3X1_S = WordArray[0];
////	EEtr_ISvth3X2_S = WordArray[1];
////	EEtr_ISvth3X3_S = WordArray[2];
////	EEtr_ISvth3X4_S = WordArray[3];
////	EEtr_ISvth3X5_S = WordArray[4];
////	EEtr_ISvth3X6_S = WordArray[5];
////
////	if (g_p_Char_Enable) // Characterization only //
////	{
////		// ISvth3X_Sim_S. Measure the final value after shadow register is loaded with final trim code. //
////		// Binary search on IS pin looking at SR pin flip state //
////		SR_dvi2k->set_meas_mode(SR_ch, DVI_MEASURE_VOLTAGE); // DVI_13_1, dvi2k // 
////		UpperLimit = (func.dlog->tests[A_ISvth3X_Sim_S].f_max_limit_val[0])*1.1; // Get upper search limit //
////		LowerLimit = (func.dlog->tests[A_ISvth3X_Sim_S].f_min_limit_val[0])*0.9; // Get lower search limit //
////		if (g_p_Char_Enable == 1) // Widen the search limit for characterization. //
////		{
////			UpperLimit = (func.dlog->tests[A_ISvth3X_Sim_S].f_max_limit_val[0])*1.5; // Get upper search limit //
////			LowerLimit = (func.dlog->tests[A_ISvth3X_Sim_S].f_min_limit_val[0])*0.5; // Get lower search limit //
////		}
////		UpperLimit *= g_ISbuff_Gain32; // IS pin is connected to 20X buffer. //
////		LowerLimit *= g_ISbuff_Gain32; // IS pin is connected to 20X buffer. //
////		Vforce = (UpperLimit + LowerLimit) / 2;
////		if (Vforce < -4.99 || Vforce > 4.99) // Prevent out of range. //
////		{
////			Vforce = 0;
////			g_Error_Flag = -117;
////		}
////		IS_dvi2k->set_voltage(IS_ch, Vforce, VOLT_5_RANGE); // DVI_13_0, dvi2k //
////		wait.delay_10_us(100);
////		while ( (UpperLimit - LowerLimit) > .001)
////		{
////			Vforce = (UpperLimit + LowerLimit) / 2; 
////			if (Vforce < -4.99 || Vforce > 4.99) // Prevent out of range. //
////			{
////				Vforce = 0;
////				g_Error_Flag = -118;
////				break;
////			}
////			IS_dvi2k->set_voltage(IS_ch, Vforce, VOLT_5_RANGE); // DVI_13_0, dvi2k //
////			wait.delay_10_us(100);
////			SRpinVolt = SR_dvi2k->measure(); // DVI_13_1, dvi2k // 
////			if (SRpinVolt < 1.5) // Below threshold //
////				LowerLimit = Vforce;
////			else // Above threshold //
////				UpperLimit = Vforce;		
////		}
////		ISvth3X_Sim_S = Vforce;
////		ISvth3X_Sim_S = ISvth3X_Sim_S/g_ISbuff_Gain32; // IS pin is connected to 20X buffer. //
////		ISvth_Sim_Chg_S = ((ISvth3X_Sim_S - g_ISvth3X_pt_S) / g_ISvth3X_pt_S)*100; // In percent //
////	}
////
////	// Powerdown //
//////	Open_relay(K18);
////	ovi_3->set_voltage(OVI_CHANNEL_7, 0.0, RANGE_10_V); // OVI_3_7 //
////	FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
////	VO_dvi->set_voltage(VO_ch, 0, VOLT_10_RANGE); // DVI_9_0 //
//////	BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
////	VBPS_ramp_down(3, 0, 0.1);
////	//SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
////	SR_dvi2k->set_voltage(SR_ch, 5, VOLT_10_RANGE); // DVI_13_1, dvi2k, prevent undershoot //
////	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
////	wait.delay_10_us(45); // prevent SR undershoot //
////	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
////	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_5_RANGE); // DVI_13_0, dvi2k //
////	mux_14->open_relay(MUX_2_GND);
////	Open_relay(K24); // Disconnect IS pin to 20X buffer. //
////
//////	FB_ovi->connect(2);
//////	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
//////	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
//////	Mux20_Open_relay(K64);
////	
//////	Mux20_Open_relay(K37);
//////	Mux20_Open_relay(K38);
//////	Mux20_Open_relay(K40);
//////	Mux20_Open_relay(K39);
//////	ddd_7->ddd_set_clock_period(Dclk_period);
//////	ddd_7->ddd_set_voltage_ref(DDD_Vref);
////
////	// DDD level //
//////	g_DDD_Low = 0.0; // Save current value //
//////	g_DDD_High = 4.0; // Save current value //
//////	wait.delay_10_us(100);
//////	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
//////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////	wait.delay_10_us(200); // Wait for relays //
////
////	// Datalog //
////	//PiDatalog(func, A_Func_Num_ISvth_Pre_S, fNum_ISvthPre_S, 26, POWER_UNIT);
////	PiDatalog(func, A_ISvth3X_pt_S, g_ISvth3X_pt_S, 26, POWER_MILLI);
////	PiDatalog(func, A_gISvth_TARGET_S, ISvth_Target3X_S, 26, POWER_MILLI);
////	PiDatalog(func, A_ISvth_TrCode_S, ISvth_TrCode_S, 26, POWER_UNIT);
////	PiDatalog(func, A_ISvth_BitCode_S, ISvth_BitCode_S, 26, POWER_UNIT);
////	PiDatalog(func, A_IZtr_ISvth3X1_S, EEtr_ISvth3X1_S, 26, POWER_UNIT);
////	PiDatalog(func, A_IZtr_ISvth3X2_S, EEtr_ISvth3X2_S, 26, POWER_UNIT);
////	PiDatalog(func, A_IZtr_ISvth3X3_S, EEtr_ISvth3X3_S, 26, POWER_UNIT);
////	PiDatalog(func, A_IZtr_ISvth3X4_S, EEtr_ISvth3X4_S, 26, POWER_UNIT);
////	PiDatalog(func, A_IZtr_ISvth3X5_S, EEtr_ISvth3X5_S, 26, POWER_UNIT);
////	PiDatalog(func, A_IZtr_ISvth3X6_S, EEtr_ISvth3X6_S, 26, POWER_UNIT);
////	if (g_p_Char_Enable) // Characterization only //
////	{
////		PiDatalog(func, A_ISvth3X_Sim_S, ISvth3X_Sim_S, 26, POWER_MILLI);
////		PiDatalog(func, A_ISvth_Sim_Chg_S, ISvth_Sim_Chg_S, 26, POWER_UNIT);
////	}
////	
////	// Test Time End //
////	if (g_p_TstTime_Enble)
////	{
////		g_endtime = g_mytimer.GetElapsedTime();
////		ISvth_Pre_S_TT = (g_endtime - g_begintime)*1e-6;
////		PiDatalog(func, A_ISvth_Pre_S_TT, ISvth_Pre_S_TT, 26, POWER_MILLI);
////	}
////
////	// Check any test failed //
////	if (PiGetAnyFailStatus())		
////	{
////		g_PartFailed = 1;
////	}
}
