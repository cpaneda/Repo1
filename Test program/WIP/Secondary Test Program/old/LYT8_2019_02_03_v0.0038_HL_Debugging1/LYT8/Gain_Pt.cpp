//==============================================================================
// Gain_Pt.cpp (User function)
// 
//    void Gain_Pt_user_init(test_function& func)
//    void Gain_Pt(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "Gain_Pt.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void Gain_Pt_user_init(test_function& func)
{
	Gain_Pt_params *ours;
    ours = (Gain_Pt_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void Gain_Pt(test_function& func)
{
    // The two lines below must be the first two in the function.
    Gain_Pt_params *ours;
    ours = (Gain_Pt_params *)func.params;

	// Increment function number //
	gFuncNum++;	
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_fNum_Gain_Pt, gFuncNum, 25, POWER_UNIT);

	// Skip Test if AbortTest set // 
	if (AbortTest)
		return;
	
	// Skip trimming if g_p_Trim_Enable set //
	if (g_p_Trim_Enable == 0)
		return;

	if (g_Fn_Gain_Pt == 0 )  return;

	// Test Time Begin //
	 if (g_p_TstTime_Enble)
	 	g_begintime = g_mytimer.GetElapsedTime();

	// Test Names //
	//float Gain_Pt_S = 0;
	float Gain_Target_S = 40;
	int Gain_TrCode_S = 0;
	int Gain_BitCode_S = 0;
	int EEtr_Gain1_S = 0;
	int EEtr_Gain2_S = 0;
	int EEtr_Gain3_S = 0;
	int EEtr_Gain4_S = 0;
	float Gain_Sim_S = 0;
	float Gain_Sim_Chg_S = 0;
	float Gain_Pt_TT = 0; 

	// Declare Variables //
	int NObin[1] = {0}; // Place holder //
	int NOhex = 0; // Place holder //
	int WordArray[16] = {0};
	int TempArray[30] = {0};
	float UpperLimit = 0;
	float LowerLimit = 0;
	int ReadWordData[16] = {0};
	int ReadByteData[8] = {0};
	int Data1 = 0;
	int Data2 = 0;
	float Volt1 = 0;
	float Volt2 = 0;
	float TempGain = 0;
	float IsPinVolt = 0;
	float Delta = 0;
	float MinDelta = 0;
	float BestGain = 0;
	int Best_TrCode = 0;
	int Best_BitCode = 0;
	Pulse pulse;

	// Open all relays //
//	Initialize_Relays();

	// Initialize Instruments //
//	Initialize_Instruments();

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
	//SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
	SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k //
	Mux20_Close_relay(K50); // SR pin hard short to GND with relay //

	// BPS //
	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //

	// IS //
	mux_14->close_relay(MUX_2_GND);
	Close_relay(K24); // Connect IS pin to 20X buffer. //
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE); // DVI_13_0, dvi2k //
	IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //

	// Vout //
	VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //
	VO_dvi->set_voltage(VO_ch, 4.5, VOLT_5_RANGE); // DVI_9_0 //

	// FB (COMP) //
	//FB_ovi->disconnect(2);
	FB_ovi->set_voltage(FB_ch, 0.0, RANGE_2_V); // OVI_1_2 //
	FB_ovi->set_current(FB_ch, 0.1e-9, RANGE_30_UA); // OVI_1_2, Float //
	FB_ovi->set_meas_mode(FB_ch, OVI_MEASURE_VOLTAGE); // OVI_1_2 //

	// VBD //
	VBD_dvi->set_voltage(VBD_ch, 0.0, VOLT_5_RANGE); // DVI_21_0 //
//	VBD_dvi->set_current(VBD_ch, 30e-6, RANGE_30_UA); // DVI_21_0, prevent glitch //
	wait.delay_10_us(25); // Prevent glitch //
	VBD_dvi->set_current(VBD_ch, 0.1e-9, RANGE_30_UA); // DVI_21_0, Float //

	// uVCC //
	uVCC_ovi->set_voltage(uVCC_ch, 0.0, RANGE_5_V); // OVI_3_2 //
	uVCC_ovi->set_current(uVCC_ch, 0.1e-9, RANGE_30_UA); // OVI_3_2, Float //

	// DDD level //
//	g_DDD_Low = 0.0; // Save current value //
//	g_DDD_High = 3.3; // Save current value //
//	wait.delay_10_us(100);
//	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
//	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
//	wait.delay_10_us(100);

	// SDA //
	Mux20_Close_relay(K64); // SDA pullup to 3.3V through 1.5kohm resistor. //
	ovi_3->set_voltage(OVI_CHANNEL_7, g_I2C_Pullup, RANGE_5_V); // OVI_3_7 //
	ovi_3->set_current(OVI_CHANNEL_7, 30e-3, RANGE_30_MA); // OVI_3_7 //
	Mux20_Close_relay(K37); // Disconnect ovi from SDA. //
	Mux20_Close_relay(K38); // Connect SDA and SCL to DDD. //
	Mux20_Close_relay(K40); // Connect SDA and SCL to DDD. //

	// SCL //
	Mux20_Close_relay(K39);  // Disconnect ovi from SCL. //
	ddd_7->ddd_run_pattern(g_SDA_SCL_Low_start, g_SDA_SCL_Low_stop);  // Start with SDA and SCL low with DDD. //

	// Set DDD for I2C. //
//	ddd_7->ddd_set_clock_period(g_Dclk_I2C);
//	ddd_7->ddd_set_voltage_ref(g_Vref_I2C);
		
	// Wait for relays //
	wait.delay_10_us(200); 

	// Powerup //
	BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
	wait.delay_10_us(100); // Must wait long enough for uVCC to come up before sending I2C commands. //

	// I2C into test mode. //  
	Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
	Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //
	Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //

	// Always load g_ShadowRegister[] array to shadow register of DUT after powerup if EEPROM has not yet been written. //
	LoadShadowRegister();

	// Write the I2C command to connect the input of the ADC to IS pin. //
	//Write_Word(g_TM_CTRL, 0x0900, NObin, HEX); //  Write the I2C command to connect the input of the ADC to IS pin. //
	
	//Write I2C command to connect output of 40X gain amplifier to FB pin using TM_CTRL (tm_ctrl[12]:tm_isn_afe set to 1).
	//Write I2C command to set tm_ctrl[11:8] to '1000'  (design says this will provide cleanest signal on FB pin. )
	Write_Word(g_TM_CTRL, 0x1800, NObin, HEX); 
	
	// Input 8mV to IS pin and readout the ADC code through I2C;Data1 //
	//IS_dvi2k->set_voltage(IS_ch, 160e-3, VOLT_1_RANGE); // DVI_13_0, dvi2k.  Remember, IS pin attached to 20X gain buffer, 160mV / 20 = 8mV. //
	//IsPinVolt = 0.008 * g_ISbuff_Gain32;
	IsPinVolt = 0.008 * g_ISbuff_GainLow;
	IS_dvi2k->set_voltage(IS_ch, IsPinVolt, VOLT_1_RANGE); // DVI_13_0, dvi2k.  Remember, IS pin attached to 20X gain buffer, 160mV / 20 = 8mV. //
	wait.delay_10_us(100);

	// Measure amp output on FB pin. //
	FB_ovi->set_meas_mode(FB_ch, OVI_MEASURE_VOLTAGE); // OVI_1_2 //
	wait.delay_10_us(10);
	Volt1 = FB_ovi->measure();

	// Input 32mV to IS pin and readout the ADC code through I2C;Data2 //
	//IS_dvi2k->set_voltage(IS_ch, 640e-3, VOLT_1_RANGE); // DVI_13_0, dvi2k.  Remember, IS pin attached to 20X gain buffer, 640mV / 20 = 32mV. //
	IsPinVolt = 0.032 * g_ISbuff_Gain32;
	IS_dvi2k->set_voltage(IS_ch, IsPinVolt, VOLT_1_RANGE); // DVI_13_0, dvi2k.  Remember, IS pin attached to 20X gain buffer, 640mV / 20 = 32mV. //
	wait.delay_10_us(100);

	// Measure amp output on FB pin. //
	Volt2 = FB_ovi->measure();

	// Gain_Pt_S.  Calculate the Gain by (Volt2-Volt1)/0.024 //
	g_Gain_Pt_S = (Volt2-Volt1)/0.024;

	// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
	WordArray[0] = g_ShadowRegister[64];
	WordArray[1] = g_ShadowRegister[65];
	WordArray[2] = g_ShadowRegister[66];
	WordArray[3] = g_ShadowRegister[67];
	WordArray[4] = g_ShadowRegister[68];
	WordArray[5] = g_ShadowRegister[69];
	WordArray[6] = g_ShadowRegister[70];
	WordArray[7] = g_ShadowRegister[71];
	WordArray[8] = g_ShadowRegister[72]; // EEtr_Gain1_S //
	WordArray[9] = g_ShadowRegister[73]; // EEtr_Gain2_S //
	WordArray[10] = g_ShadowRegister[74]; // EEtr_Gain3_S //
	WordArray[11] = g_ShadowRegister[75]; // EEtr_Gain4_S //
	WordArray[12] = g_ShadowRegister[76];
	WordArray[13] = g_ShadowRegister[77];
	WordArray[14] = g_ShadowRegister[78];
	WordArray[15] = g_ShadowRegister[79];

	// Find trim code closest to target. //
	UpperLimit = 9;
	LowerLimit = -8;
	MinDelta = 99999;
	while ( (UpperLimit - LowerLimit) > 1)
	{
		Gain_BitCode_S = (UpperLimit + LowerLimit) / 2;
		
		// Convert BitCode to TrCode. Mapping between bit code and trim code. //
		if(Gain_BitCode_S == -7) Gain_TrCode_S = 7;
		if(Gain_BitCode_S == -6) Gain_TrCode_S = 6;
		if(Gain_BitCode_S == -5) Gain_TrCode_S = 5;
		if(Gain_BitCode_S == -4) Gain_TrCode_S = 4;
		if(Gain_BitCode_S == -3) Gain_TrCode_S = 3;
		if(Gain_BitCode_S == -2) Gain_TrCode_S = 2;
		if(Gain_BitCode_S == -1) Gain_TrCode_S = 1;
		if(Gain_BitCode_S == 0) Gain_TrCode_S = 0;
		if(Gain_BitCode_S == 1) Gain_TrCode_S = 15;
		if(Gain_BitCode_S == 2) Gain_TrCode_S = 14;
		if(Gain_BitCode_S == 3) Gain_TrCode_S = 13;
		if(Gain_BitCode_S == 4) Gain_TrCode_S = 12;
		if(Gain_BitCode_S == 5) Gain_TrCode_S = 11;
		if(Gain_BitCode_S == 6) Gain_TrCode_S = 10;
		if(Gain_BitCode_S == 7) Gain_TrCode_S = 9;
		if(Gain_BitCode_S == 8) Gain_TrCode_S = 8;

		// Convert decimal number 'Gain_TrCode_S' into binary number and store in TempArray[]. //		
		Convert_Decimal_To_Binary(Gain_TrCode_S, TempArray);

		// Load TempArray[] to WordArray[] at correct bit locations. //
		WordArray[8] = TempArray[0];
		WordArray[9] = TempArray[1]; 
		WordArray[10] = TempArray[2]; 
		WordArray[11] = TempArray[3]; 

		// Load new trim code to shadow register. //
		Write_Word(g_SREG4, NOhex, WordArray, BIN); // Load trim code to shadow register. //

		// Check if Gain is above or below the target. //
		// Input 8mV to IS pin and readout the ADC code through I2C;Data1 //
		//IS_dvi2k->set_voltage(IS_ch, 160e-3, VOLT_1_RANGE); // DVI_13_0, dvi2k.  Remember, IS pin attached to 20X gain buffer, 160mV / 20 = 8mV. //
		//IsPinVolt = 0.008 * g_ISbuff_Gain32;
		IsPinVolt = 0.008 * g_ISbuff_GainLow;
		IS_dvi2k->set_voltage(IS_ch, IsPinVolt, VOLT_1_RANGE); // DVI_13_0, dvi2k.  Remember, IS pin attached to 20X gain buffer, 160mV / 20 = 8mV. //
		wait.delay_10_us(100);

		// Measure amp output on FB pin. //
		Volt1 = FB_ovi->measure();

		// Input 32mV to IS pin and readout the ADC code through I2C;Data2 //
		//IS_dvi2k->set_voltage(IS_ch, 640e-3, VOLT_1_RANGE); // DVI_13_0, dvi2k.  Remember, IS pin attached to 20X gain buffer, 640mV / 20 = 32mV. //
		IsPinVolt = 0.032 * g_ISbuff_Gain32;
		IS_dvi2k->set_voltage(IS_ch, IsPinVolt, VOLT_1_RANGE); // DVI_13_0, dvi2k.  Remember, IS pin attached to 20X gain buffer, 640mV / 20 = 32mV. //
		wait.delay_10_us(100);

		// Measure amp output on FB pin. //
		Volt2 = FB_ovi->measure();

		// Check if Gain is above or below the target.   Calculate the Gain by (Volt2-Volt1)/0.024 //
		TempGain = (Volt2-Volt1)/0.024;

		Delta = TempGain - Gain_Target_S;
		if (Delta < 0) // Remove negative //
			Delta *= -1;
		if (Delta < MinDelta)
		{
			MinDelta = Delta;
			BestGain = TempGain;
			Best_TrCode = Gain_TrCode_S;
			Best_BitCode = Gain_BitCode_S;
		}

		if (TempGain < Gain_Target_S) // Below target //
			LowerLimit = Gain_BitCode_S;
		else // Above target //
			UpperLimit = Gain_BitCode_S;		
	}
	Gain_Sim_S = BestGain;
	Gain_TrCode_S = Best_TrCode;
	Gain_BitCode_S = Best_BitCode;
	Gain_Sim_Chg_S = ((Gain_Sim_S - g_Gain_Pt_S) / g_Gain_Pt_S)*100; // In percent //

	// Load the shadow register with the final trim code Gain_TrCode_S.  Must not overwrite any of the other shadow register bits! //	
	Convert_Decimal_To_Binary(Gain_TrCode_S, TempArray); // Convert decimal number 'Gain_TrCode_S' into binary number and store in TempArray[]. // 
	
	// Load TempArray[] to WordArray[] at correct bit locations. //
	WordArray[8] = TempArray[0];
	WordArray[9] = TempArray[1]; 
	WordArray[10] = TempArray[2]; 
	WordArray[11] = TempArray[3]; 

	// Load final trim code to shadow register. //
	Write_Word(g_SREG4, NOhex, WordArray, BIN); // Load trim code to shadow register. //

	// Save the new values to the g_ShadowRegister[] array. //
	g_ShadowRegister[72] = WordArray[8];
	g_ShadowRegister[73] = WordArray[9];
	g_ShadowRegister[74] = WordArray[10];
	g_ShadowRegister[75] = WordArray[11];

	// Load individual bits for datalogging //
	EEtr_Gain1_S = WordArray[8];
	EEtr_Gain2_S = WordArray[9];
	EEtr_Gain3_S = WordArray[10];
	EEtr_Gain4_S = WordArray[11];

	
	// Powerdown //
	//Open_relay(K2);
	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
//	Open_relay(K18);
//	FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
//	BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
	mux_14->open_relay(MUX_2_GND);
	Open_relay(K24);
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE); // DVI_13_0, dvi2k //
//	VO_dvi->set_voltage(VO_ch, 0, VOLT_5_RANGE); // DVI_9_0 //
	FB_ovi->set_current(FB_ch, 30e-3, RANGE_30_MA); // OVI_1_2 //
//	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
//	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
//	Mux20_Open_relay(K64);
//	ovi_3->set_voltage(OVI_CHANNEL_7, 0, RANGE_5_V); // OVI_3_7 //
//	Mux20_Open_relay(K37);
//	Mux20_Open_relay(K38);
//	Mux20_Open_relay(K40);
//	Mux20_Open_relay(K39);  // Disconnect ovi from SCL. //
	Mux20_Open_relay(K50); // SR pin hard short to GND with relay //
//	ddd_7->ddd_set_clock_period(Dclk_period);
//	ddd_7->ddd_set_voltage_ref(DDD_Vref);
	
	// DDD level //
	//g_DDD_Low = 0.0; // Save current value //
	//g_DDD_High = 4.0; // Save current value //
	//wait.delay_10_us(100);
	//ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	//ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(200); // Wait for relays //

	// Datalog //
	PiDatalog(func, A_Gain_Pt_S, g_Gain_Pt_S, 25, POWER_UNIT);
	PiDatalog(func, A_Gain_Target_S, Gain_Target_S, 25, POWER_UNIT);
	PiDatalog(func, A_Gain_TrCode_S, Gain_TrCode_S, 25, POWER_UNIT);
	PiDatalog(func, A_Gain_BitCode_S, Gain_BitCode_S, 25, POWER_UNIT);
	PiDatalog(func, A_EEtr_Gain1_S, EEtr_Gain1_S, 25, POWER_UNIT);
	PiDatalog(func, A_EEtr_Gain2_S, EEtr_Gain2_S, 25, POWER_UNIT);
	PiDatalog(func, A_EEtr_Gain3_S, EEtr_Gain3_S, 25, POWER_UNIT);
	PiDatalog(func, A_EEtr_Gain4_S, EEtr_Gain4_S, 25, POWER_UNIT);
	if (g_p_Char_Enable) // Characterization only //
	{
		PiDatalog(func, A_Gain_Sim_S, Gain_Sim_S, 25, POWER_UNIT);
		PiDatalog(func, A_Gain_Sim_Chg_S, Gain_Sim_Chg_S, 25, POWER_UNIT);
	}

	// Test Time End //
	if (g_p_TstTime_Enble)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		Gain_Pt_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_Gain_Pt_TT, Gain_Pt_TT, 25, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}
