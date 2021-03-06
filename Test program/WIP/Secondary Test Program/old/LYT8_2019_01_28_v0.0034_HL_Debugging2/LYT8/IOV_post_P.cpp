//==============================================================================
// IOV_post_P.cpp (User function)
// 
//    void IOV_post_P_user_init(test_function& func)
//    void IOV_post_P(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "IOV_post_P.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void IOV_post_P_user_init(test_function& func)
{
	IOV_post_P_params *ours;
    ours = (IOV_post_P_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void IOV_post_P(test_function& func)
{
    // The two lines below must be the first two in the function.
    IOV_post_P_params *ours;
    ours = (IOV_post_P_params *)func.params;

	// Increment function number //
	gFuncNum++;	
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_IOV_post_P, gFuncNum, 24, POWER_UNIT);

	// Skip Test if AbortTest set //
	if (AbortTest)
		return;

	// Skip trimming if g_p_Trim_Enable set //
	if (g_p_Trim_Enable == 0)
		return;

	if(gTrim_iov_Off_P_Trimops)
		return;

	// skip this function if it's not for characterization
	if(g_p_Char_Enable == false)
		return;

	if (g_Fn_IOV_post_P == 0 )  return;	

	// Test Time Begin //
	 if (g_p_TstTime_Enble)
	 	g_begintime = g_mytimer.GetElapsedTime();

	// Declare Variables //
	int NObin[1] = {0}; // Place holder //
	int NOhex = 0; // Place holder //
	float iOV_plus_post	=0;
	float i_start =0;
	float i_stop =0;
	float i_step =0;
	float i_VPIN =0;
	float i_Hys =0;
	float tmeas =0;
	bool SWITCHING =false;
	int count =0;
	float UpperLimit = 0;
	float LowerLimit = 0;
	float IOV_post_P_TT =0;
	Pulse pulse;

	VBPP_Negative_Cycle();

	// Open all relays //
	Initialize_Relays();

	// Initialize Instruments //
	Initialize_Instruments();

	// Drain //
	Close_relay(K3);
	D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
	D_dvi->set_current(D_ch, 30e-3, RANGE_30_MA); // DVI_11_0 //

	// BPP //
	BPP_ovi->set_voltage(BPP_ch, 0.0, RANGE_10_V); // OVI_1_0 //
	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //

	// V pin //
	VPIN_ovi->connect(VPIN_ch);
	VPIN_ovi->set_voltage(VPIN_ch, 0.0, RANGE_10_V); // OVI_1_1 //
	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //

	// FW //
	// Only 1V on FW pin here to reduce current to BPS pin.  FW upto 4V after BPS brought up. //
	Close_relay(K18);
	FW_dvi->set_voltage(FW_ch, 1, VOLT_10_RANGE); // DVI_11_1 //
	FW_dvi->set_current(FW_ch, 30e-3, RANGE_30_MA); // DVI_11_1 //

	// SR //
	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //

	// BPS //
	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //

	// FW //
	wait.delay_10_us(5);
	FW_dvi->set_voltage(FW_ch, 4, VOLT_10_RANGE); // DVI_11_1 //

	// IS //
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE); // DVI_13_0, dvi2k //
	IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //

	// Vout //
	VO_dvi->set_voltage(VO_ch, 4.5, VOLT_10_RANGE); // DVI_9_0 //
	VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //

	// COMP //
	FB_ovi->set_voltage(FB_ch, 0.0, RANGE_10_V); // OVI_1_2 //
	FB_ovi->set_current(FB_ch, 30e-3, RANGE_30_MA); // OVI_1_2 //

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
	//Mux20_Close_relay(K37); // Disconnect ovi from SDA. //
	SDA_ovi->set_current(SDA_ch, 0.1e-9, RANGE_30_UA); // OVI_3_0, float, let DDD control //
	Mux20_Close_relay(K38); // Connect SDA and SCL to DDD. //
	Mux20_Close_relay(K40); // Connect SDA and SCL to DDD. //

	// SCL //
	//Mux20_Close_relay(K39); // Disconnect ovi from SCL. //
	SCL_ovi->set_current(SCL_ch, 0.1e-9, RANGE_30_UA); // OVI_3_1, float, let DDD control //
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

	Write_Word(g_TM_ANA, 0x0138, NObin, HEX);
	
	//Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //

	// Always load g_ShadowRegister[] array to shadow register of DUT after powerup if EEPROM has not yet been written. //
	LoadShadowRegister();

	// Float SR dvi //
//	SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k, Float. //

	// Connect the FB comparator output to SR pin (CV comparator output). //
//	Write_Word(g_TM_SEL, 0x0024, NObin, HEX); //  Write the I2C command to connect the FB comparator output to SR pin (CV comparator output). //
	
	// Write 0x0820 to TM_CTRL.  This will force secondary in control and disconnect Vout from ADC.  Without this, the FB comparator reference is shifted causing a measuremnt error. //
	// Putting secondary in control prevents the FB comparator reference from shifting- this is the main cause of the FB comparator reference shift. //
	// Disconnecting Vout from ADC also prevents FB comparator reference from shifting, but not as much as putting secondary in control. //
//	Write_Word(g_TM_CTRL, 0x0820, NObin, HEX); 

	// Hold SDA and SCL low before disconnecting DDD. //
	ovi_3->set_voltage(OVI_CHANNEL_7, 0, RANGE_5_V); // OVI_3_7 //
	ddd_7->ddd_run_pattern(Low_pat_start, Low_pat_stop);
	wait.delay_10_us(5); // Do not remove. Needed to avoid glitch. // //
	SDA_ovi->set_voltage(SDA_ch, 0, RANGE_10_V); // OVI_3_0 //
	SDA_ovi->set_current(SDA_ch, 30e-3, RANGE_30_MA); // OVI_3_0 //
	SCL_ovi->set_voltage(SCL_ch, 0.0, RANGE_10_V); // OVI_3_1 //
	SCL_ovi->set_current(SCL_ch, 30e-3, RANGE_30_MA); // OVI_3_1 //
	wait.delay_10_us(30);
	Mux20_Open_relay(K38); // Disconnect SDA and SCL from DDD. //
	Mux20_Open_relay(K40); // Disconnect SDA and SCL from DDD. //
	Mux20_Open_relay(K64); // Disconnect SDA pullup to 3.3V through 1.5kohm resistor. //
	wait.delay_10_us(200);

	FB_ovi->set_voltage(FB_ch, 1.0, RANGE_2_V);	// OVI_1_2 //

	// Powerup Primary //
	tmu_6->close_relay(TMU_HIZ_DUT1); // Connect TMU HIZ to Drain 
	tmu_6->start_trigger_setup(2.0, NEG_SLOPE, TMU_HIZ, TMU_IN_5V);
	tmu_6->stop_trigger_setup(3.0,	POS_SLOPE, TMU_HIZ, TMU_IN_5V);
	wait.delay_10_us(10);
	tmu_6->start_holdoff(0,FALSE);
	tmu_6->stop_holdoff(0,FALSE);
	VBPP_Negative_Cycle();
	delay(4);

	// Power Up //
	gIOV = true;	// Used in "Power_Up_Primary_Normal_Mode" sequence
	VBPP_Power_Up_w_Test_Mode(gTM2_UVOV_NoDelay, ILIM_NORM); // TM2 requires the normal wait and listen 85ms //
	D_dvi->set_voltage(D_ch, 5.0, VOLT_50_RANGE); // Bring Drain higher to TMU measurement during iVpin test //

	// Setup DDD //
	ddd_7->ddd_set_clock_period(Dclk_period);
	ddd_7->ddd_set_voltage_ref(DDD_Vref);

	// DDD level //
	g_DDD_Low = 0.0; // Save current value //
	g_DDD_High = 4.0; // Save current value //
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(200); // Wait for relays //

	// Get ready for handshake to give control to secondary. //
	ddd_7->ddd_run_pattern(High_pat_start,High_pat_stop);
	wait.delay_10_us(14);
	Close_relay(K21); // Connect FW pin to DDD_Ch3. //
	wait.delay_10_us(200);
	Open_relay(K18); // Disconnect FW pin from DVI-11-1 //
	wait.delay_10_us(200);
	FB_ovi->set_voltage(FB_ch, 1, RANGE_2_V); // OVI_1_2
	wait.delay_10_us(50);

	// Provide 2 negative pulses on FW to give Secondary control.  (FW go below -100mV)
	Force_Neg_Pulses_FW_DDD(5, -0.5);
	wait.delay_10_us(100);  //more than 30us quiet time on FW signal
	FW_dvi->set_voltage(FW_ch, 5, VOLT_10_RANGE); // DVI_11_1 //
	wait.delay_10_us(10);
	Close_relay(K18); // Connect FW pin to DVI-11-1 //
	delay(2);	

	Open_relay(K21); // Disconnect FW pin from DDD_Ch3. //
	delay(2);
	FW_dvi->set_voltage(FW_ch, 1.0, VOLT_50_RANGE);	// DVI_11_1
	wait.delay_10_us(200);
	gIOV = false;	// Used in "Power_Up_Primary_Normal_Mode" sequence
	wait.delay_10_us(50);
	VPIN_ovi->set_voltage(VPIN_ch, 5.0, RANGE_5_V);	//Can't go down to 2V.  3V is about 0.3uA lower than original

	// VBP_P drops when secondary has control //
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final+0.1, RANGE_10_V); // prevent undershoot //
	wait.delay_10_us(8);
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final, RANGE_10_V);
	wait.delay_10_us(20);
	UpperLimit = (func.dlog->tests[A_iOV_plus_post].f_max_limit_val[0])*1.2; // Get upper search limit //
	LowerLimit = (func.dlog->tests[A_iOV_plus_post].f_min_limit_val[0])*0.8; // Get lower search limit //
	search_IOVp_Binary(&iOV_plus_post, LowerLimit, UpperLimit);

	// Powerdown //
	D_dvi->set_voltage(D_ch, 0.0, VOLT_50_RANGE); // DVI_11_0
	D_dvi->set_current(D_ch, 300e-3, RANGE_300_MA);
	FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
	Disconnect_InvSyn_IM();
	tmu_6->open_relay(TMU_HIZ_DUT1); // Connect TMU HIZ to Drain 
	Open_relay(K3); // Drain to RL pullup
	Open_relay(K18);
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
	BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
	VBD_dvi->set_voltage(VBD_ch, 2, VOLT_5_RANGE); // DVI_21_0, prevent undershoot //
	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
	wait.delay_10_us(20);
	VBD_dvi->set_voltage(VBD_ch, 0, VOLT_5_RANGE); // DVI_21_0 //
	ddd_7->ddd_set_clock_period(Dclk_period);
	ddd_7->ddd_set_voltage_ref(DDD_Vref);
	ddd_7->ddd_run_pattern(Low_pat_start, Low_pat_stop);
	FB_ovi->connect(2);
	FB_ovi->set_voltage(FB_ch, 0, RANGE_2_V); // OVI_1_2 //
	SR_dvi2k->set_voltage(SR_ch, 0.5, VOLT_10_RANGE); // DVI_13_1, dvi2k //
	wait.delay_10_us(30);
	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
	wait.delay_10_us(5);
	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //

	// DDD level //
	g_DDD_Low = 0.0; // Save current value //
	g_DDD_High = 4.0; // Save current value //
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(200); // Wait for relays //

	// Datalog
	PiDatalog(func, A_iOV_plus_post, iOV_plus_post, 24, POWER_MICRO);

	// Test Time End //
	if (g_p_TstTime_Enble)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		IOV_post_P_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_IOV_post_P_TT, IOV_post_P_TT, 24, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}
