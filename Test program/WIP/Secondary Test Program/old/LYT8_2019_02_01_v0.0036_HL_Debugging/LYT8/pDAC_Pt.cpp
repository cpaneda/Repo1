//==============================================================================
// pDAC_Pt.cpp (User function)
// 
//    void pDAC_Pt_user_init(test_function& func)
//    void pDAC_Pt(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "pDAC_Pt.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void pDAC_Pt_user_init(test_function& func)
{
	pDAC_Pt_params *ours;
    ours = (pDAC_Pt_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void pDAC_Pt(test_function& func)
{
    // The two lines below must be the first two in the function.
    pDAC_Pt_params *ours;
    ours = (pDAC_Pt_params *)func.params;

	// Increment function number //
	gFuncNum++;

////	// Datalog gFuncNum variable //
////	if(gDisplay_FuncNum)
////		PiDatalog(func, A_fNum_pDAC_Pt, gFuncNum, 26, POWER_UNIT);
////
////	// Skip Test if AbortTest set //
////	if (AbortTest)
////		return;
////
////	// Skip trimming if g_p_Trim_Enable set //
////	if (g_p_Trim_Enable == 0)
////		return;
////
////	if (g_Fn_pDAC_Pt == 0 )  return;
////
////	// Test Time Begin //
////	 if (g_p_TstTime_Enble)
////	 	g_begintime = g_mytimer.GetElapsedTime();
////
////	// Test Names //
////	float pDAC_Pt_dlta = 0;
////	int pDAC_TrCode_S = 0;
////	int pDAC_BitCode_S = 0;
////	int EEtr_pDAC1_S = 0;
////	int EEtr_pDAC2_S = 0;
////	int EEtr_pDAC3_S = 0;
////	int EEtr_pDAC4_S = 0;
////	int EEtr_pDAC5_S = 0;
////	float pDAC_Sim_S = 0;
////	float pDAC_Sim_Chg_S = 0;
////	float pDAC_Pt_TT = 0;
////
////	// Declare Variables //
////	int NObin[1] = {0}; // Place holder //
////	int NOhex = 0; // Place holder //
////	int READ59_word[16] = {0};
////	int WordArray[16] = {0};
////	int TempArray[30] = {0};
////	float WordData = 0;
////	float UpperLimit = 0;
////	float LowerLimit = 0;
////	Pulse pulse;
////	float Delta = 0;
////	float MinDelta = 0;
////	float BestCV = 0;
////	int Best_TrCode = 0;
////	int Best_BitCode = 0;
////	float VoutVolt = 0;
////	float CV_Ref = 0;
////
////	// Open all relays //
//////	Initialize_Relays();
////
////	// Initialize Instruments //
//////	Initialize_Instruments();
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
////
////	// BPS //
//////	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
//////	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //
////
////	// IS //
////	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_2_RANGE); // DVI_13_0, dvi2k //
////	IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //
////
////	// uVCC //
////	uVCC_ovi->set_voltage(uVCC_ch, 0.0, RANGE_5_V); // OVI_3_2 //
////	uVCC_ovi->set_current(uVCC_ch, 0.1e-9, RANGE_30_UA); // OVI_3_2, Float //
////
////	// Vout //
////	Mux20_Close_relay(K53); // Connect Vout pin to Op Amp output. //
////	VO_dvi->set_current(VO_ch, 0.1e-9, RANGE_30_UA); // DVI_9_0, float //
////	VO_dvi->set_voltage(VO_ch, 0, VOLT_10_RANGE); // DVI_9_0 //
////	VO_dvi->set_meas_mode(VO_ch, DVI_MEASURE_VOLTAGE); // DVI_9_0 //
////
////	// COMP //
////	FB_ovi->disconnect(2);
////	Mux20_Close_relay(K54); // Connect FB pin to Op Amp negative input. //
////
////	// Setup Op Amp positive input reference to 1.25V. //
////	ovi_3->set_current(OVI_CHANNEL_6, 30e-3, RANGE_30_MA); // OVI_3_6 //
////	ovi_3->set_voltage(OVI_CHANNEL_6, 1.25, RANGE_2_V); // OVI_3_6 //
////
////	// VBD //
//////	VBD_dvi->set_voltage(VBD_ch, 0.0, VOLT_5_RANGE); // DVI_21_0 //
//////	//VBD_dvi->set_current(VBD_ch, 30e-6, RANGE_30_UA); // DVI_21_0, prevent glitch //
//////	wait.delay_10_us(25); // Prevent glitch //
//////	VBD_dvi->set_current(VBD_ch, 0.1e-9, RANGE_30_UA); // DVI_21_0, Float //
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
////	// I2C into test mode. //  
//////	Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
//////	Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //
//////	Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //
////
////	// If the COMP(FB) was disconnected with trim, need to reconnect here for controlling 
////	// switching freqeuncy with FB pin //
////	g_Bit63_Change_Flag = 0;
////	if (g_ShadowRegister[63] == 1) // bit[63]: trim_no_fb_pin //
////	{
////		g_ShadowRegister[63] = 0;
////		g_Bit63_Change_Flag = 1;
////	}
////
////	// Always load g_ShadowRegister[] array to shadow register of DUT after powerup if EEPROM has not yet been written. //
////	LoadShadowRegister();
////	wait.delay_10_us(100);
////
////	// Write 0x0820 to TM_CTRL.  This will force secondary in control and disconnect Vout from ADC.  Without this, the FB comparator reference is shifted causing a measuremnt error. //
////	// Putting secondary in control prevents the FB comparator reference from shifting- this is the main cause of the FB comparator reference shift. //
////	// Disconnecting Vout from ADC also prevents FB comparator reference from shifting, but not as much as putting secondary in control. //
////	Write_Word(g_TM_CTRL, 0x0820, NObin, HEX);
////	wait.delay_10_us(30);
////
////	// More delay for Rev C //
////	if (g_SiliconRev_Sec == 5) // Rev C silicon //
////		wait.delay_10_us(100); 
////
////	// Measure Vout.  This with nDAC and pDAC pogrammed to zero by default at powerup. //
////	CV_Ref = VO_dvi->measure_average(10);
////
////	// Calculate target //
////	g_pDAC_Target_S = CV_Ref - 1.28;
////
////	// Write the I2C command to set_CV //
////	//WordData = 372; // 10mV per LSB.  For example, to set 3.72V,  WordData = 3.72/0.01 = 372. //
////	// For Rev.2 silicon bit[7] is odd parity bit for bits 0 to 6, and bit[15] is odd parity 
////	// bit for bits 7 through 11. Therefore, data bits 7,8,9,10,11 shift to left by one, 
////	// and [7] and [15] are odd parity bits.  
////	// For example, (decimal 372)0000 0001 0111 0100 becomes (decimal 756)0000 0010 1111 0100. //
////	WordData = 756; // 3.72V //
////	Write_Word(g_CV_reg, WordData, NObin, HEX); // Write CV register to set Vout to pDAC_Target_S. //
////
////	// Measure Vout //
////	if (g_SiliconRev_Sec == 5) // Rev C silicon //
////		wait.delay_10_us(1000); // Needed //
////	else
////		wait.delay_10_us(120); // Needed //
////	g_pDAC_Pt_S = VO_dvi->measure_average(10);
////	pDAC_Pt_dlta = CV_Ref - g_pDAC_Pt_S;
////
////	// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
////	WordArray[0] = g_ShadowRegister[48]; // EEtr_pDAC1_S //
////	WordArray[1] = g_ShadowRegister[49]; // EEtr_pDAC1_S // 
////	WordArray[2] = g_ShadowRegister[50]; // EEtr_pDAC1_S //
////	WordArray[3] = g_ShadowRegister[51]; // EEtr_pDAC1_S //
////	WordArray[4] = g_ShadowRegister[52]; // EEtr_pDAC1_S //
////	WordArray[5] = g_ShadowRegister[53];
////	WordArray[6] = g_ShadowRegister[54];
////	WordArray[7] = g_ShadowRegister[55];
////	WordArray[8] = g_ShadowRegister[56];
////	WordArray[9] = g_ShadowRegister[57];
////	WordArray[10] = g_ShadowRegister[58];
////	WordArray[11] = g_ShadowRegister[59];
////	WordArray[12] = g_ShadowRegister[60];
////	WordArray[13] = g_ShadowRegister[61];
////	WordArray[14] = g_ShadowRegister[62];
////	WordArray[15] = g_ShadowRegister[63];
////
////	// Find trim code closest to target. //
////	UpperLimit = 17;
////	LowerLimit = -16; 
////	MinDelta = 99999;
////	while ( (UpperLimit - LowerLimit) > 1)
////	{
////		pDAC_BitCode_S = (UpperLimit + LowerLimit) / 2;
////		
////		// Convert BitCode to TrCode. Mapping between bit code and trim code. //
////		if(pDAC_BitCode_S == -15) pDAC_TrCode_S = 15;
////		if(pDAC_BitCode_S == -14) pDAC_TrCode_S = 14;
////		if(pDAC_BitCode_S == -13) pDAC_TrCode_S = 13;
////		if(pDAC_BitCode_S == -12) pDAC_TrCode_S = 12;
////		if(pDAC_BitCode_S == -11) pDAC_TrCode_S = 11;
////		if(pDAC_BitCode_S == -10) pDAC_TrCode_S = 10;
////		if(pDAC_BitCode_S == -9) pDAC_TrCode_S = 9;
////		if(pDAC_BitCode_S == -8) pDAC_TrCode_S = 8;
////		if(pDAC_BitCode_S == -7) pDAC_TrCode_S = 7;
////		if(pDAC_BitCode_S == -6) pDAC_TrCode_S = 6;
////		if(pDAC_BitCode_S == -5) pDAC_TrCode_S = 5;
////		if(pDAC_BitCode_S == -4) pDAC_TrCode_S = 4;
////		if(pDAC_BitCode_S == -3) pDAC_TrCode_S = 3;
////		if(pDAC_BitCode_S == -2) pDAC_TrCode_S = 2;
////		if(pDAC_BitCode_S == -1) pDAC_TrCode_S = 1;
////		if(pDAC_BitCode_S == 0) pDAC_TrCode_S = 0;
////		if(pDAC_BitCode_S == 1) pDAC_TrCode_S = 31;
////		if(pDAC_BitCode_S == 2) pDAC_TrCode_S = 30;
////		if(pDAC_BitCode_S == 3) pDAC_TrCode_S = 29;
////		if(pDAC_BitCode_S == 4) pDAC_TrCode_S = 28;
////		if(pDAC_BitCode_S == 5) pDAC_TrCode_S = 27;
////		if(pDAC_BitCode_S == 6) pDAC_TrCode_S = 26;
////		if(pDAC_BitCode_S == 7) pDAC_TrCode_S = 25;
////		if(pDAC_BitCode_S == 8) pDAC_TrCode_S = 24;
////		if(pDAC_BitCode_S == 9) pDAC_TrCode_S = 23;
////		if(pDAC_BitCode_S == 10) pDAC_TrCode_S = 22;
////		if(pDAC_BitCode_S == 11) pDAC_TrCode_S = 21;
////		if(pDAC_BitCode_S == 12) pDAC_TrCode_S = 20;
////		if(pDAC_BitCode_S == 13) pDAC_TrCode_S = 19;
////		if(pDAC_BitCode_S == 14) pDAC_TrCode_S = 18;
////		if(pDAC_BitCode_S == 15) pDAC_TrCode_S = 17;
////		if(pDAC_BitCode_S == 16) pDAC_TrCode_S = 16;
////
////		// Convert decimal number 'pDAC_TrCode_S' into binary number and store in TempArray[]. //		
////		Convert_Decimal_To_Binary(pDAC_TrCode_S, TempArray);
////
////		// Load TempArray[] to WordArray[] at correct bit locations. //
////		WordArray[0] = TempArray[0];
////		WordArray[1] = TempArray[1]; 
////		WordArray[2] = TempArray[2]; 
////		WordArray[3] = TempArray[3]; 
////		WordArray[4] = TempArray[4]; 
////
////		// Load new trim code to shadow register. //
////		Write_Word(g_SREG3, NOhex, WordArray, BIN); // Load trim code to shadow register. //
////		
////		// Check CV //
////		wait.delay_10_us(100);
////		VoutVolt = VO_dvi->measure_average(10); // DVI_9_0 //
////		Delta = VoutVolt - g_pDAC_Target_S;
////		if (Delta < 0) // Remove negative //
////			Delta *= -1;
////		if (Delta < MinDelta)
////		{
////			MinDelta = Delta;
////			BestCV = VoutVolt;
////			Best_TrCode = pDAC_TrCode_S;
////			Best_BitCode = pDAC_BitCode_S;
////		}
////		if (VoutVolt < g_pDAC_Target_S) // Below target //
////			LowerLimit = pDAC_BitCode_S;
////		else // Above target //
////			UpperLimit = pDAC_BitCode_S;
////	}
////	pDAC_Sim_S = BestCV;
////	pDAC_TrCode_S = Best_TrCode;
////	pDAC_BitCode_S = Best_BitCode;
////	pDAC_Sim_Chg_S = ((pDAC_Sim_S - g_pDAC_Pt_S) / g_pDAC_Pt_S)*100; // In percent //
////
////	// Load the shadow register with the final trim code pDAC_TrCode_S.  Must not overwrite any of the other shadow register bits! //	
////	Convert_Decimal_To_Binary(pDAC_TrCode_S, TempArray); // Convert decimal number 'pDAC_TrCode_S' into binary number and store in TempArray[]. // 
////
////	// Load TempArray[] to WordArray[] at correct bit locations. //
////	WordArray[0] = TempArray[0];
////	WordArray[1] = TempArray[1]; 
////	WordArray[2] = TempArray[2]; 
////	WordArray[3] = TempArray[3]; 
////	WordArray[4] = TempArray[4]; 
////
////	// Load final trim code to shadow register. //
////	Write_Word(g_SREG3, NOhex, WordArray, BIN); // Load trim code to shadow register. //
////
////	// Save the new values to the g_ShadowRegister[] array. //
////	g_ShadowRegister[48] = WordArray[0];
////	g_ShadowRegister[49] = WordArray[1];
////	g_ShadowRegister[50] = WordArray[2];
////	g_ShadowRegister[51] = WordArray[3];
////	g_ShadowRegister[52] = WordArray[4];
////
////	// Load individual bits for datalogging //
////	EEtr_pDAC1_S = WordArray[0];
////	EEtr_pDAC2_S = WordArray[1];
////	EEtr_pDAC3_S = WordArray[2];
////	EEtr_pDAC4_S = WordArray[3];
////	EEtr_pDAC5_S = WordArray[4];
////
////	// Powerdown //
////	ovi_3->set_voltage(OVI_CHANNEL_7, 0.0, RANGE_10_V); // OVI_3_7 //
////	FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
////	Mux20_Open_relay(K53); // Disconnect Vout pin from Op Amp output. //
////	wait.delay_10_us(200); // Wait for relay //
////	VO_dvi->set_voltage(VO_ch, 5, VOLT_10_RANGE); // DVI_9_0 //
////	VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //
////	FB_ovi->connect(2);
////	Mux20_Open_relay(K54); // Disconnect FB pin from Op Amp negative input. //
////	ovi_3->set_voltage(OVI_CHANNEL_6, 0, RANGE_2_V); // OVI_3_6 //
////	wait.delay_10_us(20);
////	VO_dvi->set_voltage(VO_ch, 0, VOLT_10_RANGE); // DVI_9_0 //
////	VBPS_ramp_down(3, 0, 0.1);
//////	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
//////	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
//////	Mux20_Open_relay(K64);
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
////	wait.delay_10_us(200); // Wait for relay //
////
////// Disconnect Op Amp supply.  dvi used as OpAmp supply. //
////VBD_ramp_down(24, 0, 0.2);
////Mux20_Open_relay(K36);
////wait.delay_10_us(300);
////
////	// Reset bit63 shadow register if needed. //
////	if (g_Bit63_Change_Flag == 1)
////	{
////		g_ShadowRegister[63] = 1;
////		g_Bit63_Change_Flag = 0;
////	}
////
////	// Datalog //
////	PiDatalog(func, A_pDAC_Pt_S, g_pDAC_Pt_S, 26, POWER_UNIT);
////	PiDatalog(func, A_pDAC_Pt_dlta, pDAC_Pt_dlta, 26, POWER_UNIT);
////	PiDatalog(func, A_pDAC_Target_S, g_pDAC_Target_S, 26, POWER_UNIT);
////	PiDatalog(func, A_pDAC_TrCode_S, pDAC_TrCode_S, 26, POWER_UNIT);
////	PiDatalog(func, A_pDAC_BitCode_S, pDAC_BitCode_S, 26, POWER_UNIT);
////	PiDatalog(func, A_EEtr_pDAC1_S, EEtr_pDAC1_S, 26, POWER_UNIT);
////	PiDatalog(func, A_EEtr_pDAC2_S, EEtr_pDAC2_S, 26, POWER_UNIT);
////	PiDatalog(func, A_EEtr_pDAC3_S, EEtr_pDAC3_S, 26, POWER_UNIT);
////	PiDatalog(func, A_EEtr_pDAC4_S, EEtr_pDAC4_S, 26, POWER_UNIT);
////	PiDatalog(func, A_EEtr_pDAC5_S, EEtr_pDAC5_S, 26, POWER_UNIT);
////	PiDatalog(func, A_pDAC_Sim_S, pDAC_Sim_S, 26, POWER_UNIT);
////	PiDatalog(func, A_pDAC_Sim_Chg_S, pDAC_Sim_Chg_S, 26, POWER_UNIT);
////	
////	// Test Time End //
////	if (g_p_TstTime_Enble)
////	{
////		g_endtime = g_mytimer.GetElapsedTime();
////		pDAC_Pt_TT = (g_endtime - g_begintime)*1e-6;
////		PiDatalog(func, A_pDAC_Pt_TT, pDAC_Pt_TT, 26, POWER_MILLI);
////	}
////
////	// Check any test failed //
////	if (PiGetAnyFailStatus())		
////	{
////		g_PartFailed = 1;
////	}
}