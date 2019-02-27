//==============================================================================
// CDC_Pre.cpp (User function)
// 
//    void CDC_Pre_user_init(test_function& func)
//    void CDC_Pre(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "CDC_Pre.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void CDC_Pre_user_init(test_function& func)
{
	CDC_Pre_params *ours;
    ours = (CDC_Pre_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void CDC_Pre(test_function& func)
{
    // The two lines below must be the first two in the function.
    CDC_Pre_params *ours;
    ours = (CDC_Pre_params *)func.params;

	// Increment function number //
	gFuncNum++;	
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_fNum_CDC_Pre, gFuncNum, 26, POWER_UNIT);

	// Skip Test if AbortTest set 
	if (AbortTest)
		return;

	// Skip trimming if g_p_Trim_Enable set //
	if (g_p_Trim_Enable == 0)
		return;

	if (g_Fn_CDC_Pre == 0 )  
		return;

	// Test Time Begin //
	 if (g_p_TstTime_Enble)
	 	g_begintime = g_mytimer.GetElapsedTime();

	// Test Names //
	float CV_CDCpt_S =0;
	int CDC_TrCode_S = 0;
	int CDC_BitCode_S = 0;
	int EEtr_CDC1_S = 0;
	int EEtr_CDC2_S = 0;
	int EEtr_CDC3_S = 0;
	float CDC_Sim_S = 0;
	float CDC_Sim_Chg_S = 0;
	float CDC_Pre_TT =0;

	// Declare Variables //
	int NObin[1] = {0}; // Place holder //
	int NOhex = 0; // Place holder //
	int WordArray[16] = {0};
	int TempArray[30] = {0};
	float UpperLimit = 0;
	float LowerLimit = 0;
	float Vforce = 0;
	float SRpinVolt = 0;
	float TempValue = 0;
	float IsDAC_CDCpt_S =0;
	float ISpinVolt = 0;
	float trim_weight[16] ={0};
	float delta = 0;
	int i = 0;
	float trim_result = 0;
	float Bit38_Change_Flag = 0;
	float ISVTH_pre = 0;
	float WordData = 0;
	float V_Step = 0;
	int LoopCnt = 0;
	float ISVTH_FromAbove = 0;
	float ISVTH_FromBelow = 0;
	Pulse pulse;

	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	// CDC_Pt-S
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
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
	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
	SR_dvi2k->set_meas_mode(SR_ch, DVI_MEASURE_VOLTAGE); // DVI_13_1, dvi2k // 

	// BPS //
//	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
//	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //

	// IS //
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE); // DVI_13_0, dvi2k //
	IS_dvi2k->set_current(IS_ch, 2, RANGE_2_A); // DVI_13_0, dvi2k //

	// Vout //
	VO_dvi->set_voltage(VO_ch, 4.5, VOLT_10_RANGE); // DVI_9_0 //
	VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //

	// FB (COMP) //
	FB_ovi->disconnect(2);

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
//	wait.delay_10_us(g_DDDwait);
//	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
//	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
//	wait.delay_10_us(g_DDDwait);

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
//	ddd_7->ddd_set_clock_period(g_Dclk_I2C);
//	ddd_7->ddd_set_voltage_ref(g_Vref_I2C);
		
	// Wait for relays //
	wait.delay_10_us(200);

	// Powerup //
//	BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
//	wait.delay_10_us(100); // Must wait long enough for uVCC to come up before sending I2C commands. //

	// I2C into test mode. //  
//	Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
//	Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //

	Write_Word(g_TM_ANA, 0x0134, NObin, HEX); // TM_EN_SR_driver //

//	Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //

	// Always load g_ShadowRegister[] array to shadow register of DUT after powerup if EEPROM has not yet been written. //
	LoadShadowRegister();

	// Measure CV here.  CV is measured again here because Inno3X found a shift in CV after trimming other parameters.  
	// For InnoVI, ISvth was trimmed after CV was trimmed, so need to test again just in case CV 
	// has shifted after ISvth trimming.  This can potentially be removed later if data shows there is no 
	// CV shift after trimming ISvth. //
	
	// SR //
	SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k, Float. //

	// Connect the FB comparator output to SR pin (CV comparator output). //
	Write_Word(g_TM_SEL, 0x0024, NObin, HEX); //  Write the I2C command to connect the FB comparator output to SR pin (CV comparator output). //

	// Write 0x0820 to TM_CTRL.  This will force secondary in control and disconnect Vout from ADC.  Without this, the FB comparator reference is shifted causing a measuremnt error. //
	// Putting secondary in control prevents the FB comparator reference from shifting- this is the main cause of the FB comparator reference shift. //
	// Disconnecting Vout from ADC also prevents FB comparator reference from shifting, but not as much as putting secondary in control. //
	Write_Word(g_TM_CTRL, 0x0820, NObin, HEX); 

	// CV regisiter is programmed to 5V by default on powerup. //

	// Binary search CV [on Vout pin] to get the CV_CDCpt_S value, should be around CV_Target_S. //
	// Look for FB comparator output flip on SR pin. //
	SR_dvi2k->set_meas_mode(SR_ch, DVI_MEASURE_VOLTAGE); // DVI_13_1, dvi2k // 
	UpperLimit = (func.dlog->tests[A_CV_CDCpt_S].f_max_limit_val[0])*1.1; // Get upper search limit //
	LowerLimit = (func.dlog->tests[A_CV_CDCpt_S].f_min_limit_val[0])*0.9; // Get lower search limit //
//	if (g_p_Char_Enable == 1) // Widen the search limit for characterization. //
//	{
//		UpperLimit = (func.dlog->tests[A_CV_CDCpt_S].f_max_limit_val[0])*1.5; // Get upper search limit //
//		LowerLimit = (func.dlog->tests[A_CV_CDCpt_S].f_min_limit_val[0])*0.5; // Get lower search limit //
//	}
	Vforce = (UpperLimit + LowerLimit) / 2;
	if (Vforce < -9.99 || Vforce > 9.99) // Prevent out of range. //
	{
		Vforce = 0;
		g_Error_Flag = -119;
	}
	VO_dvi->set_voltage(VO_ch, Vforce, VOLT_10_RANGE); // DVI_9_0 //
	wait.delay_10_us(100);
	while ( (UpperLimit - LowerLimit) > .001)
	{
		Vforce = (UpperLimit + LowerLimit) / 2; 
		if (Vforce < -9.99 || Vforce > 9.99) // Prevent out of range. //
		{
			Vforce = 0;
			g_Error_Flag = -120;
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
	CV_CDCpt_S = Vforce;

	// Get IS pin ready. //
	ISpinVolt = 0.032; // Change to force fixed 32mV per design (Johnny and Yuri) 11/29/2017. //
	ISpinVolt = g_ISbuff_Gain32 * ISpinVolt; // IS pin is connected to 20X buffer. //

	mux_14->close_relay(MUX_2_GND);
	Close_relay(K24); // Connect IS pin to 20X buffer. //
	wait.delay_10_us(200); // Wait for relay //

	// Force ~32mV to IS pin to get full CDC. //
	if (ISpinVolt > 0.999 || ISpinVolt < 0) // Prevent out of range. //
	{
		ISpinVolt = 0;
		g_Error_Flag = -198;
	}
	IS_dvi2k->set_voltage(IS_ch, ISpinVolt, VOLT_1_RANGE); // DVI_13_0, dvi2k.  Remember, IS pin attached to 20X gain buffer, 640mV / 20 = 32mV. //
	wait.delay_10_us(100);

	// Program the CDC with I2C to g_CDC_Target_S. //
	TempValue = (g_CDC_Target_S*1000) / 50; // The g_CDC register is a 4bit with 50mV per step. //
	Write_Byte(g_CDC, TempValue, NObin, HEX);

	// Binary search CV [on Vout pin] to get CV plus CDC. //
	// Look for FB comparator output flip on SR pin. //
	SR_dvi2k->set_meas_mode(SR_ch, DVI_MEASURE_VOLTAGE); // DVI_13_1, dvi2k // 
	UpperLimit = (func.dlog->tests[A_CDC_Pt_S].f_max_limit_val[0])*1.1; // Get upper search limit //
	UpperLimit = UpperLimit + CV_CDCpt_S;
	LowerLimit = (func.dlog->tests[A_CDC_Pt_S].f_min_limit_val[0])*0.9; // Get lower search limit //
	LowerLimit = LowerLimit + CV_CDCpt_S;
//	if (g_p_Char_Enable == 1) // Widen the search limit for characterization. //
//	{
//		UpperLimit = (func.dlog->tests[A_CDC_Pt_S].f_max_limit_val[0])*1.5; // Get upper search limit //
//		UpperLimit = UpperLimit + CV_CDCpt_S;
//		LowerLimit = (func.dlog->tests[A_CDC_Pt_S].f_min_limit_val[0])*0.5; // Get lower search limit //
//		LowerLimit = LowerLimit + CV_CDCpt_S;
//	}
	Vforce = (UpperLimit + LowerLimit) / 2;
	if (Vforce < -9.99 || Vforce > 9.99) // Prevent out of range. //
	{
		Vforce = 0;
		g_Error_Flag = -121;
	}
	VO_dvi->set_voltage(VO_ch, Vforce, VOLT_10_RANGE); // DVI_9_0 //
	wait.delay_10_us(100);
	while ( (UpperLimit - LowerLimit) > .001)
	{
		Vforce = (UpperLimit + LowerLimit) / 2; 
		if (Vforce < -9.99 || Vforce > 9.99) // Prevent out of range. //
		{
			Vforce = 0;
			g_Error_Flag = -122;
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
	g_CDC_Pt_S = Vforce - CV_CDCpt_S;

	// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
	WordArray[0] = g_ShadowRegister[16];
	WordArray[1] = g_ShadowRegister[17];
	WordArray[2] = g_ShadowRegister[18];
	WordArray[3] = g_ShadowRegister[19];
	WordArray[4] = g_ShadowRegister[20];
	WordArray[5] = g_ShadowRegister[21];
	WordArray[6] = g_ShadowRegister[22];
	WordArray[7] = g_ShadowRegister[23];
	WordArray[8] = g_ShadowRegister[24]; // EEtr_CDC1_S //
	WordArray[9] = g_ShadowRegister[25]; // EEtr_CDC2_S //
	WordArray[10] = g_ShadowRegister[26]; // EEtr_CDC3_S //
	WordArray[11] = g_ShadowRegister[27];
	WordArray[12] = g_ShadowRegister[28];
	WordArray[13] = g_ShadowRegister[29];
	WordArray[14] = g_ShadowRegister[30];
	WordArray[15] = g_ShadowRegister[31];

	// Find trim code closest to target. //
	// Use trim weight table for faster test time. //
	trim_weight[0] = -0.240;
	trim_weight[1] = 3.916;
	trim_weight[2] = 7.835;
	trim_weight[3] = 12.534;
	trim_weight[4] = -3.621;	
	trim_weight[5] = -6.901;
	trim_weight[6] = -10.124;	
	trim_weight[7] = -12.819;

	// Determine Trim Code //
	CDC_TrCode_S = 0;
	delta = 99999; 
	for(i=0; i<8 ;i++)
	{
		trim_result =  g_CDC_Pt_S*( (trim_weight[i]/100.0) + 1);
		if(fabs(trim_result - g_CDC_Target_S) < delta)
		{
			CDC_TrCode_S = i;
			delta = fabs(trim_result - g_CDC_Target_S);
		}
	}

	// Load the shadow register with the final trim code CDC_TrCode_S.  Must not overwrite any of the other shadow register bits! //	
	Convert_Decimal_To_Binary(CDC_TrCode_S, TempArray); // Convert decimal number 'CDC_TrCode_S' into binary number and store in TempArray[]. // 

	// Load TempArray[] to WordArray[] at correct bit locations. //
	WordArray[8] = TempArray[0];
	WordArray[9] = TempArray[1];
	WordArray[10] = TempArray[2];

	// Load final trim code to shadow register. //
	Write_Word(g_SREG1, NOhex, WordArray, BIN); // Load trim code to shadow register. //

	// Save the new values to the g_ShadowRegister[] array. //
	g_ShadowRegister[24] = WordArray[8];
	g_ShadowRegister[25] = WordArray[9];
	g_ShadowRegister[26] = WordArray[10];

	// Load individual bits for datalogging //
	EEtr_CDC1_S = WordArray[8];
	EEtr_CDC2_S = WordArray[9];
	EEtr_CDC3_S = WordArray[10];

	if (g_p_Char_Enable) // Characterization only //
	{
		// CDC_Sim_S. Measure the final value after shadow register is loaded with final trim code. //
		// Binary search CV [on Vout pin] to get CV plus CDC. //
		// Look for FB comparator output flip on SR pin. //
		SR_dvi2k->set_meas_mode(SR_ch, DVI_MEASURE_VOLTAGE); // DVI_13_1, dvi2k // 
		UpperLimit = (func.dlog->tests[A_CDC_Sim_S].f_max_limit_val[0])*1.1; // Get upper search limit //
		UpperLimit = UpperLimit + CV_CDCpt_S;
		LowerLimit = (func.dlog->tests[A_CDC_Sim_S].f_min_limit_val[0])*0.9; // Get lower search limit //
		LowerLimit = LowerLimit + CV_CDCpt_S;
//		if (g_p_Char_Enable == 1) // Widen the search limit for characterization. //
//		{
//			UpperLimit = (func.dlog->tests[A_CDC_Sim_S].f_max_limit_val[0])*1.5; // Get upper search limit //
//			UpperLimit = UpperLimit + CV_CDCpt_S;
//			LowerLimit = (func.dlog->tests[A_CDC_Sim_S].f_min_limit_val[0])*0.5; // Get lower search limit //
//			LowerLimit = LowerLimit + CV_CDCpt_S;
//		}
		Vforce = (UpperLimit + LowerLimit) / 2;
		if (Vforce < -9.99 || Vforce > 9.99) // Prevent out of range. //
		{
			Vforce = 0;
			g_Error_Flag = -123;
		}
		VO_dvi->set_voltage(VO_ch, Vforce, VOLT_10_RANGE); // DVI_9_0 //
		wait.delay_10_us(100);
		while ( (UpperLimit - LowerLimit) > .001)
		{
			Vforce = (UpperLimit + LowerLimit) / 2; 
			if (Vforce < -9.99 || Vforce > 9.99) // Prevent out of range. //
			{
				Vforce = 0;
				g_Error_Flag = -124;
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
		CDC_Sim_S = Vforce - CV_CDCpt_S;
		CDC_Sim_Chg_S = ((CDC_Sim_S - g_CDC_Pt_S) / g_CDC_Pt_S)*100; // In percent //
	}

	// Reset test mode registers for next test. //
	Write_Word(g_TM_ANA, 0x0000, NObin, HEX);
	Write_Word(g_TM_SEL, 0x0000, NObin, HEX);

	// Program the CDC with I2C to 0V (default). //
	TempValue = (0*1000) / 50; // The g_CDC register is a 4bit with 50mV per step. //
	Write_Byte(g_CDC, TempValue, NObin, HEX);


	// Powerdown //
	mux_14->open_relay(MUX_2_GND);
	Open_relay(K24);
//	Open_relay(K18);
//	FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
//	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
//	BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE); // DVI_13_0, dvi2k //
//	VO_dvi->set_voltage(VO_ch, 0, VOLT_5_RANGE); // DVI_9_0 //
	FB_ovi->connect(2);
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
//	wait.delay_10_us(g_DDDwait);
//	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
//	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
//	wait.delay_10_us(g_DDDwait);
	wait.delay_10_us(200); // Wait for relays //

	// Disable TM_EN_SR_driver //
	Write_Word(g_TM_ANA, 0x0130, NObin, HEX);

	// Datalog //
	PiDatalog(func, A_CV_CDCpt_S, CV_CDCpt_S, 26, POWER_UNIT);
	PiDatalog(func, A_CDC_Pt_S, g_CDC_Pt_S, 26, POWER_MILLI);
	PiDatalog(func, A_CDC_Target_S, g_CDC_Target_S, 26, POWER_MILLI);
	PiDatalog(func, A_CDC_TrCode_S, CDC_TrCode_S, 26, POWER_UNIT);
	//PiDatalog(func, A_CDC_BitCode_S, CDC_BitCode_S, 26, POWER_UNIT);
	PiDatalog(func, A_EEtr_CDC1_S, EEtr_CDC1_S, 26, POWER_UNIT);
	PiDatalog(func, A_EEtr_CDC2_S, EEtr_CDC2_S, 26, POWER_UNIT);
	PiDatalog(func, A_EEtr_CDC3_S, EEtr_CDC3_S, 26, POWER_UNIT);
	//PiDatalog(func, A_ISvth_CDCpost_S, ISvth_CDCpost_S, 26, POWER_MILLI);
	if (g_p_Char_Enable) // Characterization only //
	{
		PiDatalog(func, A_CDC_Sim_S, CDC_Sim_S, 26, POWER_MILLI);
		PiDatalog(func, A_CDC_Sim_Chg_S, CDC_Sim_Chg_S, 26, POWER_UNIT);
	}
	
	// Test Time End //
	if (g_p_TstTime_Enble)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		CDC_Pre_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_CDC_Pre_TT, CDC_Pre_TT, 26, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}
