//==============================================================================
// IsDAC_Pt.cpp (User function)
// 
//    void IsDAC_Pt_user_init(test_function& func)
//    void IsDAC_Pt(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "IsDAC_Pt.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void IsDAC_Pt_user_init(test_function& func)
{
	IsDAC_Pt_params *ours;
    ours = (IsDAC_Pt_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void IsDAC_Pt(test_function& func)
{
    // The two lines below must be the first two in the function.
    IsDAC_Pt_params *ours;
    ours = (IsDAC_Pt_params *)func.params;

	// Increment function number //
	gFuncNum++;	
////
////	// Datalog gFuncNum variable //
////	if(gDisplay_FuncNum)
////		PiDatalog(func, A_fNum_IsDAC_Pt, gFuncNum, 25, POWER_UNIT);
////
////	// Skip Test if AbortTest set //
////	if (AbortTest)
////		return;
////
////	// Skip trimming if g_p_Trim_Enable set //
////	if (g_p_Trim_Enable == 0)
////		return;
////
////	if (g_Fn_IsDAC_Pt == 0 )  return;
////
////	// Test Time Begin //
////	 if (g_p_TstTime_Enble)
////	 	g_begintime = g_mytimer.GetElapsedTime();
////
////	// Test Names //
////	//float IsDAC_Pt_S =0;
////	float IsDAC_Target_S = 1.28;
////	int IsDAC_TrCode_S =0;
////	int IsDAC_BitCode_S =0;
////	int EEtr_IsDAC1_S =0;
////	int EEtr_IsDAC2_S =0;
////	int EEtr_IsDAC3_S =0;
////	int EEtr_IsDAC4_S =0;
////	int EEtr_IsDAC5_S =0;
////	//float IsDAC_Sim_S =0;
////	float IsDAC_Sim_Chg_S =0;
////	float IsDAC_Pt_TT =0;
////
////	// Declare Variables //
////	int NObin[1] = {0}; // Place holder //
////	int NOhex = 0; // Place holder //
////	int WordArray[16] = {0};
////	int TempArray[30] = {0};
////	float UpperLimit = 0;
////	float LowerLimit = 0;
////	float COMPpinVolt = 0;
////	Pulse pulse;
////	float Delta = 0;
////	float MinDelta = 0;
////	float BestCV = 0;
////	int Best_TrCode = 0;
////	int Best_BitCode = 0;
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
////	SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k //
////	Mux20_Close_relay(K50); // SR pin hard short to GND with relay //
////
////	// BPS //
//////	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
//////	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //
////
////	// IS //
////	FB_ovi->disconnect(2); // Remove OVI from FB and use DVI2K instead for better accuracy. //
////	Mux20_Close_relay(K46); // Connect DVI 2k to COMP pin intead of IS pin. //
////	Mux20_Close_relay(K48); // Connect IS pin to ovi. //
////	IS_ovi->set_voltage(IS_ovi_ch, 0.0, RANGE_10_V); // OVI_3_4 //
////	IS_ovi->set_current(IS_ovi_ch, 30e-3, RANGE_30_MA); // OVI_3_4 //
////
////	// Vout //
////	VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //
////	VO_dvi->set_voltage(VO_ch, 4.5, VOLT_5_RANGE); // DVI_9_0 //
////
////	// FB (COMP) //
////	Mux20_Close_relay(K55); // FB (COMP) pin to input of OP07 buffer.  Needed because the internal DAC 
////							// ouput resistor is 80kohm, so the input impedance of the measure 
////							// instrument needs to be 8Megohm just to get 1% accuracy. //
////	Mux20_Close_relay(K56); // Output of OP07 buffer to DVI_13_0, dvi2k //
////	dvi_13->set_voltage(DVI_CHANNEL_0, 0.0, VOLT_5_RANGE); // DVI_13_0, dvi2k //
////	dvi_13->set_current(DVI_CHANNEL_0, 0.1e-9, RANGE_20_UA); // DVI_13_0, dvi2k, float //
////	dvi_13->set_meas_mode(DVI_CHANNEL_0, DVI_MEASURE_VOLTAGE); // DVI_13_0, dvi2k // 
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
////	Mux20_Close_relay(K39);  // Disconnect ovi from SCL. //
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
////	//Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //
////
////	// Always load g_ShadowRegister[] array to shadow register of DUT after powerup if EEPROM has not yet been written. //
////	LoadShadowRegister();
////
////	// Disable the Cal Bit in shadow register (SREG3, bit[55]: trim_dis_cali, set to 1.).
////	// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
////	WordArray[0] = g_ShadowRegister[48];
////	WordArray[1] = g_ShadowRegister[49];
////	WordArray[2] = g_ShadowRegister[50];
////	WordArray[3] = g_ShadowRegister[51];
////	WordArray[4] = g_ShadowRegister[52];
////	WordArray[5] = g_ShadowRegister[53];
////	WordArray[6] = g_ShadowRegister[54];
////	WordArray[7] = g_ShadowRegister[55]; //  bit[55]: trim_dis_cali //
////	WordArray[8] = g_ShadowRegister[56];
////	WordArray[9] = g_ShadowRegister[57];
////	WordArray[10] = g_ShadowRegister[58];
////	WordArray[11] = g_ShadowRegister[59];
////	WordArray[12] = g_ShadowRegister[60];
////	WordArray[13] = g_ShadowRegister[61];
////	WordArray[14] = g_ShadowRegister[62];
////	WordArray[15] = g_ShadowRegister[63];
////
////	// (SREG3, bit[55]: trim_dis_cali, set to 1.) //
////	WordArray[7] = 1; // bit[55]: trim_dis_cali, set to 1. //
////	Write_Word(g_SREG3, NOhex, WordArray, BIN); // bit[55]: trim_dis_cali, set to 1. //
////	
////	// Disable CC comparator offset trim in shadow register (SREG4, bit[71:69]: trim_comp_cc , set to 0.)
////	// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
////	WordArray[0] = g_ShadowRegister[64];
////	WordArray[1] = g_ShadowRegister[65];
////	WordArray[2] = g_ShadowRegister[66];
////	WordArray[3] = g_ShadowRegister[67];
////	WordArray[4] = g_ShadowRegister[68];
////	WordArray[5] = g_ShadowRegister[69];
////	WordArray[6] = g_ShadowRegister[70];
////	WordArray[7] = g_ShadowRegister[71];
////	WordArray[8] = g_ShadowRegister[72];
////	WordArray[9] = g_ShadowRegister[73];
////	WordArray[10] = g_ShadowRegister[74];
////	WordArray[11] = g_ShadowRegister[75];
////	WordArray[12] = g_ShadowRegister[76];
////	WordArray[13] = g_ShadowRegister[77];
////	WordArray[14] = g_ShadowRegister[78];
////	WordArray[15] = g_ShadowRegister[79];
////
////	// (SREG4, bit[71:69]: trim_comp_cc , set to 0.)//
////	WordArray[5] = 0;
////	WordArray[6] = 0;
////	WordArray[7] = 0;	
////	Write_Word(g_SREG4, NOhex, WordArray, BIN); // SREG4, bit[71:69]: trim_comp_cc , set to 0.)//
////
////	// Set the calibration bits to zero in shadow register (SREG5, trim_cali_ofst[5:0], set to all zeros)
////	// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
////	WordArray[0] = g_ShadowRegister[80];
////	WordArray[1] = g_ShadowRegister[81];
////	WordArray[2] = g_ShadowRegister[82];
////	WordArray[3] = g_ShadowRegister[83];
////	WordArray[4] = g_ShadowRegister[84];
////	WordArray[5] = g_ShadowRegister[85];
////	WordArray[6] = g_ShadowRegister[86];
////	WordArray[7] = g_ShadowRegister[87];
////	WordArray[8] = g_ShadowRegister[88];
////	WordArray[9] = g_ShadowRegister[89];
////	WordArray[10] = g_ShadowRegister[90]; // trim_cali_ofst[0] //
////	WordArray[11] = g_ShadowRegister[91]; // trim_cali_ofst[1] //
////	WordArray[12] = g_ShadowRegister[92]; // trim_cali_ofst[2] //
////	WordArray[13] = g_ShadowRegister[93]; // trim_cali_ofst[3] //
////	WordArray[14] = g_ShadowRegister[94]; // trim_cali_ofst[4] //
////	WordArray[15] = g_ShadowRegister[95]; // trim_cali_ofst[5] //
////	
////	// (SREG5, trim_cali_ofst[5:0], set to all zeros) //
////	WordArray[10] = 0; // trim_cali_ofst[0] //
////	WordArray[11] = 0; // trim_cali_ofst[1] //
////	WordArray[12] = 0; // trim_cali_ofst[2] //
////	WordArray[13] = 0; // trim_cali_ofst[3] //
////	WordArray[14] = 0; // trim_cali_ofst[4] //
////	WordArray[15] = 0; // trim_cali_ofst[5] //
////	Write_Word(g_SREG5, NOhex, WordArray, BIN); // trim_cali_ofst[5:0], set to all zeros) //
////
////	// Write the I2C command to connect the output of the 8-Bit DAC to FB(COMP) pin. //
////	Write_Word(g_TM_CTRL, 0x0004, NObin, HEX); //  Write the I2C command to connect the output of the 8-Bit DAC to FB(COMP) pin. //
////	
////	// Write the I2C command to set the DAC value to be 8'b10000000. //
////	Write_Byte(g_TM_DAC, 0x80, NObin, HEX);
////
////	// IsDAC_Pt_S.  Measure voltage on FB (COMP) pin. //
////	wait.delay_10_us(100);	
////	g_IsDAC_Pt_S = dvi_13->measure_average(10); // DVI_13_0, dvi2k //
////
////	// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
////	WordArray[0] = g_ShadowRegister[64]; // EEtr_IsDAC1_S //
////	WordArray[1] = g_ShadowRegister[65]; // EEtr_IsDAC2_S //
////	WordArray[2] = g_ShadowRegister[66]; // EEtr_IsDAC3_S //
////	WordArray[3] = g_ShadowRegister[67]; // EEtr_IsDAC4_S //
////	WordArray[4] = g_ShadowRegister[68]; // EEtr_IsDAC5_S //
////	WordArray[5] = g_ShadowRegister[69];
////	WordArray[6] = g_ShadowRegister[70];
////	WordArray[7] = g_ShadowRegister[71];
////	WordArray[8] = g_ShadowRegister[72];
////	WordArray[9] = g_ShadowRegister[73];
////	WordArray[10] = g_ShadowRegister[74];
////	WordArray[11] = g_ShadowRegister[75];
////	WordArray[12] = g_ShadowRegister[76];
////	WordArray[13] = g_ShadowRegister[77];
////	WordArray[14] = g_ShadowRegister[78];
////	WordArray[15] = g_ShadowRegister[79];
////
////	// (SREG4, bit[71:69]: trim_comp_cc , set to 0.)//
////	WordArray[5] = 0;
////	WordArray[6] = 0;
////	WordArray[7] = 0;	
////
////	// Find trim code closest to target. //	
////	UpperLimit = 16;
////	LowerLimit = -17; 	
////	MinDelta = 99999;
////	while ( (UpperLimit - LowerLimit) > 1)
////	{
////		IsDAC_BitCode_S = (UpperLimit + LowerLimit) / 2;
////		
////		// Convert BitCode to TrCode. Mapping between bit code and trim code. //
////		if(IsDAC_BitCode_S == -16) IsDAC_TrCode_S = 16;
////		if(IsDAC_BitCode_S == -15) IsDAC_TrCode_S = 17;
////		if(IsDAC_BitCode_S == -14) IsDAC_TrCode_S = 18;
////		if(IsDAC_BitCode_S == -13) IsDAC_TrCode_S = 19;
////		if(IsDAC_BitCode_S == -12) IsDAC_TrCode_S = 20;
////		if(IsDAC_BitCode_S == -11) IsDAC_TrCode_S = 21;
////		if(IsDAC_BitCode_S == -10) IsDAC_TrCode_S = 22;
////		if(IsDAC_BitCode_S == -9) IsDAC_TrCode_S = 23;
////		if(IsDAC_BitCode_S == -8) IsDAC_TrCode_S = 24;
////		if(IsDAC_BitCode_S == -7) IsDAC_TrCode_S = 25;
////		if(IsDAC_BitCode_S == -6) IsDAC_TrCode_S = 26;
////		if(IsDAC_BitCode_S == -5) IsDAC_TrCode_S = 27;
////		if(IsDAC_BitCode_S == -4) IsDAC_TrCode_S = 28;
////		if(IsDAC_BitCode_S == -3) IsDAC_TrCode_S = 29;
////		if(IsDAC_BitCode_S == -2) IsDAC_TrCode_S = 30;
////		if(IsDAC_BitCode_S == -1) IsDAC_TrCode_S = 31;
////		if(IsDAC_BitCode_S == 0) IsDAC_TrCode_S = 0;
////		if(IsDAC_BitCode_S == 1) IsDAC_TrCode_S = 1;
////		if(IsDAC_BitCode_S == 2) IsDAC_TrCode_S = 2;
////		if(IsDAC_BitCode_S == 3) IsDAC_TrCode_S = 3;
////		if(IsDAC_BitCode_S == 4) IsDAC_TrCode_S = 4;
////		if(IsDAC_BitCode_S == 5) IsDAC_TrCode_S = 5;
////		if(IsDAC_BitCode_S == 6) IsDAC_TrCode_S = 6;
////		if(IsDAC_BitCode_S == 7) IsDAC_TrCode_S = 7;
////		if(IsDAC_BitCode_S == 8) IsDAC_TrCode_S = 8;
////		if(IsDAC_BitCode_S == 9) IsDAC_TrCode_S = 9;
////		if(IsDAC_BitCode_S == 10) IsDAC_TrCode_S = 10;
////		if(IsDAC_BitCode_S == 11) IsDAC_TrCode_S = 11;
////		if(IsDAC_BitCode_S == 12) IsDAC_TrCode_S = 12;
////		if(IsDAC_BitCode_S == 13) IsDAC_TrCode_S = 13;
////		if(IsDAC_BitCode_S == 14) IsDAC_TrCode_S = 14;
////		if(IsDAC_BitCode_S == 15) IsDAC_TrCode_S = 15;
////
////		// Convert decimal number 'IsDAC_TrCode_S' into binary number and store in TempArray[]. //		
////		Convert_Decimal_To_Binary(IsDAC_TrCode_S, TempArray);
////
////		// Load TempArray[] to WordArray[] at correct bit locations. //
////		WordArray[0] = TempArray[0];
////		WordArray[1] = TempArray[1]; 
////		WordArray[2] = TempArray[2]; 
////		WordArray[3] = TempArray[3]; 
////		WordArray[4] = TempArray[4]; 
////
////		// Load new trim code to shadow register. //
////		Write_Word(g_SREG4, NOhex, WordArray, BIN); // Load trim code to shadow register. //
////
////		// Check if FB (COMP) pin is above or below the target. //
////		wait.delay_10_us(100);	
////		COMPpinVolt = dvi_13->measure_average(10);  // DVI_13_0, dvi2k //
////		Delta = COMPpinVolt - IsDAC_Target_S;
////		if (Delta < 0) // Remove negative //
////			Delta *= -1;
////		if (Delta < MinDelta)
////		{
////			MinDelta = Delta;
////			BestCV = COMPpinVolt;
////			Best_TrCode = IsDAC_TrCode_S;
////			Best_BitCode = IsDAC_BitCode_S;
////		}
////		if (COMPpinVolt < IsDAC_Target_S) // Below target //
////			LowerLimit = IsDAC_BitCode_S;
////		else // Above target //
////			UpperLimit = IsDAC_BitCode_S;		
////	}
////	g_IsDAC_Sim_S = BestCV;
////	IsDAC_TrCode_S = Best_TrCode;
////	IsDAC_BitCode_S = Best_BitCode;
////	IsDAC_Sim_Chg_S = ((g_IsDAC_Sim_S - g_IsDAC_Pt_S) / g_IsDAC_Pt_S)*100; // In percent //
////
////	// Load the shadow register with the final trim code IsDAC_TrCode_S.  Must not overwrite any of the other shadow register bits! //	
////	Convert_Decimal_To_Binary(IsDAC_TrCode_S, TempArray); // Convert decimal number 'IsDAC_TrCode_S' into binary number and store in TempArray[]. // 
////
////	// Load TempArray[] to WordArray[] at correct bit locations. //
////	WordArray[0] = TempArray[0];
////	WordArray[1] = TempArray[1]; 
////	WordArray[2] = TempArray[2]; 
////	WordArray[3] = TempArray[3]; 
////	WordArray[4] = TempArray[4];
////
////	// Load final trim code to shadow register. //
////	Write_Word(g_SREG4, NOhex, WordArray, BIN); // Load trim code to shadow register. //
////
////	// Save the new values to the g_ShadowRegister[] array. //
////	g_ShadowRegister[64] = WordArray[0];
////	g_ShadowRegister[65] = WordArray[1];
////	g_ShadowRegister[66] = WordArray[2];
////	g_ShadowRegister[67] = WordArray[3];
////	g_ShadowRegister[68] = WordArray[4];
////
////	// Load individual bits for datalogging //
////	EEtr_IsDAC1_S = WordArray[0];
////	EEtr_IsDAC2_S = WordArray[1];
////	EEtr_IsDAC3_S = WordArray[2];
////	EEtr_IsDAC4_S = WordArray[3];
////	EEtr_IsDAC5_S = WordArray[4];
////
////	// Powerdown //
////	// This powerdown must not be removed.  We must power down here is reset all the shadow register bits. //
////	// Do not remove power down. //
////	//Open_relay(K2);
//////	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
//////	Open_relay(K18);
////	FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
////	VO_dvi->set_voltage(VO_ch,0, VOLT_5_RANGE); // DVI_9_0 //
////	ovi_3->set_voltage(OVI_CHANNEL_7, 0, RANGE_5_V); // OVI_3_7 //
////	BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
////	Mux20_Open_relay(K55); // FB (COMP) pin to input of OP07 buffer. //
////	Mux20_Open_relay(K56); // FB (COMP) pin output of OP07 buffer. //
////	Mux20_Open_relay(K48); // Disconnect IS pin from ovi. //
////	Mux20_Open_relay(K46); // Connect DVI 2k to IS pin. //
////	FB_ovi->connect(2);
////	dvi_13->set_voltage(DVI_CHANNEL_0, 0.0, VOLT_2_RANGE); // DVI_13_0, dvi2k //
////	dvi_13->set_current(DVI_CHANNEL_0, 20e-3, RANGE_20_MA); // DVI_13_0, dvi2k //
//////	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
//////	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
//////	Mux20_Open_relay(K64);
//////	Mux20_Open_relay(K37);
//////	Mux20_Open_relay(K38);
//////	Mux20_Open_relay(K40);
//////	Mux20_Open_relay(K39);
//////	Mux20_Open_relay(K50);
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
////	PiDatalog(func, A_IsDAC_Pt_S, g_IsDAC_Pt_S, 25, POWER_UNIT);
////	PiDatalog(func, A_IsDAC_Target_S, IsDAC_Target_S, 25, POWER_UNIT);
////	PiDatalog(func, A_IsDAC_TrCode_S, IsDAC_TrCode_S, 25, POWER_UNIT);
////	PiDatalog(func, A_IsDAC_BitCode_S, IsDAC_BitCode_S, 25, POWER_UNIT);
////	PiDatalog(func, A_EEtr_IsDAC1_S, EEtr_IsDAC1_S, 25, POWER_UNIT);
////	PiDatalog(func, A_EEtr_IsDAC2_S, EEtr_IsDAC2_S, 25, POWER_UNIT);
////	PiDatalog(func, A_EEtr_IsDAC3_S, EEtr_IsDAC3_S, 25, POWER_UNIT);
////	PiDatalog(func, A_EEtr_IsDAC4_S, EEtr_IsDAC4_S, 25, POWER_UNIT);
////	PiDatalog(func, A_EEtr_IsDAC5_S, EEtr_IsDAC5_S, 25, POWER_UNIT);
////	PiDatalog(func, A_IsDAC_Sim_S, g_IsDAC_Sim_S, 25, POWER_UNIT);
////	PiDatalog(func, A_IsDAC_Sim_Chg_S, IsDAC_Sim_Chg_S, 25, POWER_UNIT);
////	
////	// Test Time End //
////	if (g_p_TstTime_Enble)
////	{
////		g_endtime = g_mytimer.GetElapsedTime();
////		IsDAC_Pt_TT = (g_endtime - g_begintime)*1e-6;
////		PiDatalog(func, A_IsDAC_Pt_TT, IsDAC_Pt_TT, 25, POWER_MILLI);
////	}
////
////	// Check any test failed //
////	if (PiGetAnyFailStatus())		
////	{
////		g_PartFailed = 1;
////	}
}