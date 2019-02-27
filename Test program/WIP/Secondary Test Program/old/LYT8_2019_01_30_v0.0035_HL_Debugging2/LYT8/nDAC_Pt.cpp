//==============================================================================
// nDAC_Pt.cpp (User function)
// 
//    void nDAC_Pt_user_init(test_function& func)
//    void nDAC_Pt(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)
#include "nDAC_Pt.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void nDAC_Pt_user_init(test_function& func)
{
	nDAC_Pt_params *ours;
    ours = (nDAC_Pt_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void nDAC_Pt(test_function& func)
{
    // The two lines below must be the first two in the function.
    nDAC_Pt_params *ours;
    ours = (nDAC_Pt_params *)func.params;

	// Increment function number //
	gFuncNum++;

//////	// Datalog gFuncNum variable //
//////	if(gDisplay_FuncNum)
//////		PiDatalog(func, A_fNum_nDAC_Pt, gFuncNum, 26, POWER_UNIT);
//////
//////	// Skip Test if AbortTest set //
//////	if (AbortTest)
//////		return;
//////
//////	// Skip trimming if g_p_Trim_Enable set //
//////	if (g_p_Trim_Enable == 0)
//////		return;
//////
//////	if (g_Fn_nDAC_Pt == 0 )  return;
//////
//////	// Test Time Begin //
//////	 if (g_p_TstTime_Enble)
//////	 	g_begintime = g_mytimer.GetElapsedTime();
//////
//////	// Test Names //
//////	float nDAC_Pt_dlta = 0;
//////	int nDAC_TrCode_S = 0;
//////	int nDAC_BitCode_S = 0;
//////	float nDAC_Exp_Chg_S = 0;
//////	int EEtr_nDAC1_S = 0;
//////	int EEtr_nDAC2_S = 0;
//////	int EEtr_nDAC3_S = 0;
//////	int EEtr_nDAC4_S = 0;
//////	int EEtr_nDAC5_S = 0;
//////	float nDAC_Sim_S = 0;
//////	float nDAC_Sim_Chg_S = 0;
//////	float nDAC_Pt_TT = 0;
//////	
//////	// Declare Variables //
//////	int NObin[1] = {0}; // Place holder //
//////	int NOhex = 0; // Place holder //
//////	int READ59_word[16] = {0};
//////	int WordArray[16] = {0};
//////	int TempArray[30] = {0};
//////	float WordData = 0;
//////	float UpperLimit = 0;
//////	float LowerLimit = 0;
//////	float Vforce = 0;
//////	float SRpinVolt = 0;
//////	Pulse pulse;
//////	float Delta = 0;
//////	float MinDelta = 0;
//////	float BestCV = 0;
//////	int Best_TrCode = 0;
//////	int Best_BitCode = 0;
//////	float VoutVolt = 0;
//////	float CV_Ref = 0;
//////	//int ChangeFlag = 0;
//////
//////	// Open all relays //
////////	Initialize_Relays();
//////
//////	// Initialize Instruments //
////////	Initialize_Instruments();
//////
//////
//////	// Drain //
//////	D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
//////	D_dvi->set_current(D_ch, 30e-3, RANGE_30_MA); // DVI_11_0 //
//////
//////	// BPP //
//////	BPP_ovi->set_voltage(BPP_ch, 0.0, RANGE_10_V); // OVI_1_0 //
//////	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
//////
//////	// V pin //
//////	VPIN_ovi->set_voltage(VPIN_ch, 0.0, RANGE_10_V); // OVI_1_1 //
//////	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //
//////
//////	// FW //
//////	Close_relay(K18);
//////	FW_dvi->set_voltage(FW_ch, 1, VOLT_10_RANGE); // DVI_11_1 //
//////	FW_dvi->set_current(FW_ch, 30e-3, RANGE_30_MA); // DVI_11_1 //
//////
//////	// SR //
//////	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
//////	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
//////
//////	// BPS //
//////	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
//////	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //
//////
//////	// IS //
//////	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_2_RANGE); // DVI_13_0, dvi2k //
//////	IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //
//////
//////	// uVCC //
//////	uVCC_ovi->set_voltage(uVCC_ch, 0.0, RANGE_5_V); // OVI_3_2 //
//////	uVCC_ovi->set_current(uVCC_ch, 0.1e-9, RANGE_30_UA); // OVI_3_2, Float //
//////
//////// Connect Op Amp supply.  dvi used as OpAmp supply. //
//////// Limit supply to 10V during connection to prevent Vout going to high- will damage part. //
//////Mux20_Close_relay(K36);
//////wait.delay_10_us(300);
//////VBD_ramp_up(0, 1, 0.2);
//////VBD_dvi->set_current(VBD_ch, 300e-3, RANGE_300_MA); // DVI_21_0, prevent glitch //
//////VBD_ramp_up(1, 10, 0.2);
//////
//////	// Vout //
//////	Mux20_Close_relay(K53); // Connect Vout pin to Op Amp output. //
//////	VO_dvi->set_current(VO_ch, 0.1e-9, RANGE_30_UA); // DVI_9_0, float //
//////	VO_dvi->set_voltage(VO_ch, 0, VOLT_20_RANGE); // DVI_9_0 //
//////	VO_dvi->set_meas_mode(VO_ch, DVI_MEASURE_VOLTAGE); // DVI_9_0 //
//////
//////	// COMP //
//////	FB_ovi->disconnect(2);
//////	Mux20_Close_relay(K54); // Connect FB pin to Op Amp negative input. //
//////
//////	// Setup Op Amp positive input reference to 1.25V. //
//////	ovi_3->set_current(OVI_CHANNEL_6, 30e-3, RANGE_30_MA); // OVI_3_6 //
//////	ovi_3->set_voltage(OVI_CHANNEL_6, 1.25, RANGE_2_V); // OVI_3_6 //
//////
//////	// VBD //
////////	VBD_dvi->set_voltage(VBD_ch, 0.0, VOLT_5_RANGE); // DVI_21_0 //
////////	//VBD_dvi->set_current(VBD_ch, 30e-6, RANGE_30_UA); // DVI_21_0, prevent glitch //
////////	wait.delay_10_us(25); // Prevent glitch //
////////	VBD_dvi->set_current(VBD_ch, 0.1e-9, RANGE_30_UA); // DVI_21_0, Float //
//////
//////	// DDD level //
////////	g_DDD_Low = 0.0; // Save current value //
////////	g_DDD_High = 3.3; // Save current value //
////////	wait.delay_10_us(100);
////////	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
////////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////////	wait.delay_10_us(100);
//////
//////	// SDA //
//////	Mux20_Close_relay(K64); // SDA pullup to 3.3V through 1.5kohm resistor. //
//////	ovi_3->set_voltage(OVI_CHANNEL_7, g_I2C_Pullup, RANGE_5_V); // OVI_3_7 //
//////	ovi_3->set_current(OVI_CHANNEL_7, 30e-3, RANGE_30_MA); // OVI_3_7 //
//////	Mux20_Close_relay(K37); // Disconnect ovi from SDA. //
//////	Mux20_Close_relay(K38); // Connect SDA and SCL to DDD. //
//////	Mux20_Close_relay(K40); // Connect SDA and SCL to DDD. //
//////
//////	// SCL //
//////	Mux20_Close_relay(K39); // Disconnect ovi from SCL. //
//////	ddd_7->ddd_run_pattern(g_SDA_SCL_Low_start, g_SDA_SCL_Low_stop);  // Start with SDA and SCL low with DDD. //
//////	
//////	// Set DDD for I2C. //
////////	ddd_7->ddd_set_clock_period(g_Dclk_I2C);
////////	ddd_7->ddd_set_voltage_ref(g_Vref_I2C);
//////		
//////	// Wait for relays //
//////	wait.delay_10_us(200); 
//////
//////	// Powerup //
//////	BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
//////	wait.delay_10_us(100); // Must wait long enough for uVCC to come up before sending I2C commands. //
//////
//////	// I2C into test mode. //  
//////	Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
//////	Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //
//////	Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //
//////
//////	// If the COMP(FB) was disconnected with trim, need to reconnect here for controlling 
//////	// switching freqeuncy with FB pin //
//////	g_Bit63_Change_Flag = 0;
//////	if (g_ShadowRegister[63] == 1) // bit[63]: trim_no_fb_pin //
//////	{
//////		g_ShadowRegister[63] = 0;
//////		g_Bit63_Change_Flag = 1;
//////	}
//////
//////	// Always load g_ShadowRegister[] array to shadow register of DUT after powerup if EEPROM has not yet been written. //
//////	LoadShadowRegister();
//////
//////	// Don't write to CV register.  Instead, using test mode, write directly to the nDAC register.  Writing to the 
//////	// CV register causes the pDAC to also be written when Vout is higher than 5V to get the 10mV steps, but want 
//////	// to isolate the nDAC trimming by writing to nDAC register only.
//////	// In TM_CTRL register, set bit tm_ctrl[3]: tm_fbdac100 to 1 to write directly to nDAC.
//////	// Then write code 64 (0x40) to TM_DAC register. Use 64 because we are trimming to 1/4 scale, so 256/4 = 64. //  
//////
//////	// Also, need to prevent the FB comparator reference from shifting.
//////	// Write 0x0820 to TM_CTRL.  This will force secondary in control and disconnect Vout from ADC.  Without this, the FB comparator reference is shifted causing a measuremnt error. //
//////	// Putting secondary in control prevents the FB comparator reference from shifting- this is the main cause of the FB comparator reference shift. //
//////	// Disconnecting Vout from ADC also prevents FB comparator reference from shifting, but not as much as putting secondary in control. //
//////	
//////	// Both of the above need to be written at the same time, so the code is 0x0828.
//////
//////	// Put secondary in control, disconnect Vout from ADC, and program nDAC directly. //
//////	Write_Word(g_TM_CTRL, 0x0828, NObin, HEX);
//////	wait.delay_10_us(30);
//////
//////
//////// Ramp Op Amp supply up to 24V to match previous test program conditions //
//////VBD_ramp_up(10, 24, 0.2);
//////wait.delay_10_us(100);
//////
//////
//////	// Measure Vout.  This with nDAC and pDAC pogrammed to zero by default at powerup. //
//////	CV_Ref = VO_dvi->measure_average(10);
//////
//////	// Calculate target //
//////	g_nDAC_Target_S = CV_Ref + 6.4;
//////	
//////
//////// Ramp down op amp supply voltage to prevent initial overshoot on Vout. //
//////VBD_ramp_down(24, 11.5, 0.2);
//////
//////	 // Set nDAC to 1/4 scale. // 
//////	Write_Byte(g_TM_DAC, 0x40, NObin, HEX);
//////
//////wait.delay_10_us(120); 
//////VBD_ramp_up(11.5, 24, 0.2);
//////
//////	// Measure Vout //
//////	wait.delay_10_us(120);
//////	g_nDAC_Pt_S = VO_dvi->measure_average(10);
//////	nDAC_Pt_dlta = g_nDAC_Pt_S - CV_Ref;
//////
//////
//////	// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
//////	WordArray[0] = g_ShadowRegister[32];
//////	WordArray[1] = g_ShadowRegister[33]; 
//////	WordArray[2] = g_ShadowRegister[34]; 
//////	WordArray[3] = g_ShadowRegister[35]; 
//////	WordArray[4] = g_ShadowRegister[36]; 
//////	WordArray[5] = g_ShadowRegister[37];
//////	WordArray[6] = g_ShadowRegister[38];
//////	WordArray[7] = g_ShadowRegister[39];
//////	WordArray[8] = g_ShadowRegister[40]; // EEtr_nDAC1_S //
//////	WordArray[9] = g_ShadowRegister[41]; // EEtr_nDAC2_S //
//////	WordArray[10] = g_ShadowRegister[42]; // EEtr_nDAC3_S //
//////	WordArray[11] = g_ShadowRegister[43]; // EEtr_nDAC4_S //
//////	WordArray[12] = g_ShadowRegister[44]; // EEtr_nDAC5_S //
//////	WordArray[13] = g_ShadowRegister[45];
//////	WordArray[14] = g_ShadowRegister[46];
//////	WordArray[15] = g_ShadowRegister[47];
//////
//////	// Find trim code closest to target. //
//////	UpperLimit = 17;
//////	LowerLimit = -16;
//////	MinDelta = 99999;
//////	while ( (UpperLimit - LowerLimit) > 1)
//////	{
//////		nDAC_BitCode_S = (UpperLimit + LowerLimit) / 2;
//////		
//////		// Convert BitCode to TrCode. Mapping between bit code and trim code. //
//////		if(nDAC_BitCode_S == -15) nDAC_TrCode_S = 15;
//////		if(nDAC_BitCode_S == -14) nDAC_TrCode_S = 14;
//////		if(nDAC_BitCode_S == -13) nDAC_TrCode_S = 13;
//////		if(nDAC_BitCode_S == -12) nDAC_TrCode_S = 12;
//////		if(nDAC_BitCode_S == -11) nDAC_TrCode_S = 11;
//////		if(nDAC_BitCode_S == -10) nDAC_TrCode_S = 10;
//////		if(nDAC_BitCode_S == -9) nDAC_TrCode_S = 9;
//////		if(nDAC_BitCode_S == -8) nDAC_TrCode_S = 8;
//////		if(nDAC_BitCode_S == -7) nDAC_TrCode_S = 7;
//////		if(nDAC_BitCode_S == -6) nDAC_TrCode_S = 6;
//////		if(nDAC_BitCode_S == -5) nDAC_TrCode_S = 5;
//////		if(nDAC_BitCode_S == -4) nDAC_TrCode_S = 4;
//////		if(nDAC_BitCode_S == -3) nDAC_TrCode_S = 3;
//////		if(nDAC_BitCode_S == -2) nDAC_TrCode_S = 2;
//////		if(nDAC_BitCode_S == -1) nDAC_TrCode_S = 1;
//////		if(nDAC_BitCode_S == 0) nDAC_TrCode_S = 0;
//////		if(nDAC_BitCode_S == 1) nDAC_TrCode_S = 31;
//////		if(nDAC_BitCode_S == 2) nDAC_TrCode_S = 30;
//////		if(nDAC_BitCode_S == 3) nDAC_TrCode_S = 29;
//////		if(nDAC_BitCode_S == 4) nDAC_TrCode_S = 28;
//////		if(nDAC_BitCode_S == 5) nDAC_TrCode_S = 27;
//////		if(nDAC_BitCode_S == 6) nDAC_TrCode_S = 26;
//////		if(nDAC_BitCode_S == 7) nDAC_TrCode_S = 25;
//////		if(nDAC_BitCode_S == 8) nDAC_TrCode_S = 24;
//////		if(nDAC_BitCode_S == 9) nDAC_TrCode_S = 23;
//////		if(nDAC_BitCode_S == 10) nDAC_TrCode_S = 22;
//////		if(nDAC_BitCode_S == 11) nDAC_TrCode_S = 21;
//////		if(nDAC_BitCode_S == 12) nDAC_TrCode_S = 20;
//////		if(nDAC_BitCode_S == 13) nDAC_TrCode_S = 19;
//////		if(nDAC_BitCode_S == 14) nDAC_TrCode_S = 18;
//////		if(nDAC_BitCode_S == 15) nDAC_TrCode_S = 17;
//////		if(nDAC_BitCode_S == 16) nDAC_TrCode_S = 16;
//////
//////		// Convert decimal number 'nDAC_TrCode_S' into binary number and store in TempArray[]. //		
//////		Convert_Decimal_To_Binary(nDAC_TrCode_S, TempArray);
//////
//////		// Load TempArray[] to WordArray[] at correct bit locations. //
//////		WordArray[8] = TempArray[0];
//////		WordArray[9] = TempArray[1]; 
//////		WordArray[10] = TempArray[2]; 
//////		WordArray[11] = TempArray[3]; 
//////		WordArray[12] = TempArray[4]; 
//////
//////		// Load new trim code to shadow register. //
//////		Write_Word(g_SREG2, NOhex, WordArray, BIN); // Load trim code to shadow register. //
//////		
//////		// Check CV //
//////		wait.delay_10_us(100);
//////		VoutVolt = VO_dvi->measure_average(10); // DVI_9_0 //
//////		Delta = VoutVolt - g_nDAC_Target_S;
//////		if (Delta < 0) // Remove negative //
//////			Delta *= -1;
//////		if (Delta < MinDelta)
//////		{
//////			MinDelta = Delta;
//////			BestCV = VoutVolt;
//////			Best_TrCode = nDAC_TrCode_S;
//////			Best_BitCode = nDAC_BitCode_S;
//////		}
//////		if (VoutVolt < g_nDAC_Target_S) // Below target //
//////			LowerLimit = nDAC_BitCode_S;
//////		else // Above target //
//////			UpperLimit = nDAC_BitCode_S;
//////	}
//////	nDAC_Sim_S = BestCV;
//////	nDAC_TrCode_S = Best_TrCode;
//////	nDAC_BitCode_S = Best_BitCode;
//////	nDAC_Sim_Chg_S = ((nDAC_Sim_S - g_nDAC_Pt_S) / g_nDAC_Pt_S)*100; // In percent //
//////
//////	// Load the shadow register with the final trim code nDAC_TrCode_S.  Must not overwrite any of the other shadow register bits! //	
//////	Convert_Decimal_To_Binary(nDAC_TrCode_S, TempArray); // Convert decimal number 'nDAC_TrCode_S' into binary number and store in TempArray[]. // 
//////
//////	// Load TempArray[] to WordArray[] at correct bit locations. //
//////	WordArray[8] = TempArray[0];
//////	WordArray[9] = TempArray[1]; 
//////	WordArray[10] = TempArray[2]; 
//////	WordArray[11] = TempArray[3]; 
//////	WordArray[12] = TempArray[4]; 
//////
//////	// Load final trim code to shadow register. //
//////	Write_Word(g_SREG2, NOhex, WordArray, BIN); // Load trim code to shadow register. //
//////
//////	// Save the new values to the g_ShadowRegister[] array. //
//////	g_ShadowRegister[40] = WordArray[8];
//////	g_ShadowRegister[41] = WordArray[9];
//////	g_ShadowRegister[42] = WordArray[10];
//////	g_ShadowRegister[43] = WordArray[11];
//////	g_ShadowRegister[44] = WordArray[12];
//////	
//////	// Load individual bits for datalogging //
//////	EEtr_nDAC1_S = WordArray[8];
//////	EEtr_nDAC2_S = WordArray[9];
//////	EEtr_nDAC3_S = WordArray[10];
//////	EEtr_nDAC4_S = WordArray[11];
//////	EEtr_nDAC5_S = WordArray[12];
//////
//////
//////	// Reset for next test. // 
//////	Write_Byte(g_TM_DAC, 0x00, NObin, HEX);
//////
//////	// Powerdown //
////////	Open_relay(K18);
////////	FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
////////	BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
////////	VO_dvi->set_voltage(VO_ch, 0, VOLT_10_RANGE); // DVI_9_0 //
////////	Mux20_Open_relay(K53); // Disconnect Vout pin from Op Amp output. //
////////	VO_dvi->set_current(VO_ch, 30e-3, RANGE_30_MA); // DVI_9_0 //
////////	FB_ovi->connect(2);
////////	Mux20_Open_relay(K54); // Disconnect FB pin from Op Amp negative input. //
////////	ovi_3->set_voltage(OVI_CHANNEL_6, 0, RANGE_2_V); // OVI_3_6 //
////////	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
////////	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
////////	Mux20_Open_relay(K64);
////////	ovi_3->set_voltage(OVI_CHANNEL_7, 0.0, RANGE_10_V); // OVI_3_7 //
////////	Mux20_Open_relay(K37); 
////////	Mux20_Open_relay(K38);
////////	Mux20_Open_relay(K40);
////////	Mux20_Open_relay(K39);
////////	ddd_7->ddd_set_clock_period(Dclk_period);
////////	ddd_7->ddd_set_voltage_ref(DDD_Vref);
//////
//////	// DDD level //
////////	g_DDD_Low = 0.0; // Save current value //
////////	g_DDD_High = 4.0; // Save current value //
////////	wait.delay_10_us(100);
////////	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
////////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
//////	wait.delay_10_us(200); // Wait for relays //
//////
//////	// Reset bit63 shadow register if needed. //
//////	if (g_Bit63_Change_Flag == 1)
//////	{
//////		g_ShadowRegister[63] = 1;
//////		g_Bit63_Change_Flag = 0;
//////	}
//////
//////	// Datalog //
//////	PiDatalog(func, A_nDAC_Pt_S, g_nDAC_Pt_S, 26, POWER_UNIT);
//////	PiDatalog(func, A_nDAC_Pt_dlta, nDAC_Pt_dlta, 26, POWER_UNIT);
//////	PiDatalog(func, A_nDAC_Target_S, g_nDAC_Target_S, 26, POWER_UNIT);
//////	PiDatalog(func, A_nDAC_TrCode_S, nDAC_TrCode_S, 26, POWER_UNIT);
//////	PiDatalog(func, A_nDAC_BitCode_S, nDAC_BitCode_S, 26, POWER_UNIT);
//////	//PiDatalog(func, A_nDAC_Exp_Chg_S, nDAC_Exp_Chg_S, 26, POWER_UNIT);
//////	PiDatalog(func, A_EEtr_nDAC1_S, EEtr_nDAC1_S, 26, POWER_UNIT);
//////	PiDatalog(func, A_EEtr_nDAC2_S, EEtr_nDAC2_S, 26, POWER_UNIT);
//////	PiDatalog(func, A_EEtr_nDAC3_S, EEtr_nDAC3_S, 26, POWER_UNIT);
//////	PiDatalog(func, A_EEtr_nDAC4_S, EEtr_nDAC4_S, 26, POWER_UNIT);
//////	PiDatalog(func, A_EEtr_nDAC5_S, EEtr_nDAC5_S, 26, POWER_UNIT);
//////	PiDatalog(func, A_nDAC_Sim_S, nDAC_Sim_S, 26, POWER_UNIT);
//////	PiDatalog(func, A_nDAC_Sim_Chg_S, nDAC_Sim_Chg_S, 26, POWER_UNIT);
//////	
//////	// Test Time End //
//////	if (g_p_TstTime_Enble)
//////	{
//////		g_endtime = g_mytimer.GetElapsedTime();
//////		nDAC_Pt_TT = (g_endtime - g_begintime)*1e-6;
//////		PiDatalog(func, A_nDAC_Pt_TT, nDAC_Pt_TT, 26, POWER_MILLI);
//////	}
//////
//////	// Check any test failed //
//////	if (PiGetAnyFailStatus())		
//////	{
//////		g_PartFailed = 1;
//////	}
}
