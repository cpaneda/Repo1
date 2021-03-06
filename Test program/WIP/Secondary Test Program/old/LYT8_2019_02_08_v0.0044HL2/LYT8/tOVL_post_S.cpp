//==============================================================================
// tOVL_post_S.cpp (User function)
// 
//    void tOVL_post_S_user_init(test_function& func)
//    void tOVL_post_S(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "tOVL_post_S.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void tOVL_post_S_user_init(test_function& func)
{
	tOVL_post_S_params *ours;
    ours = (tOVL_post_S_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void tOVL_post_S(test_function& func)
{
    // The two lines below must be the first two in the function.
    tOVL_post_S_params *ours;
    ours = (tOVL_post_S_params *)func.params;

	// Increment function number //
	gFuncNum++;

////	// Datalog gFuncNum variable //
////	if(gDisplay_FuncNum)
////		PiDatalog(func, A_Func_Num_tOVL_post_S, gFuncNum, 14, POWER_UNIT);
////
////	// Skip Test if AbortTest set // 
////	if (AbortTest)
////		return;
////
////	// Skip trimming if g_p_Trim_Enable set //
////	if (g_p_Trim_Enable == 0)
////		return;
////
////	// skip this function if it's not for characterization
////	if(g_p_Char_Enable == false)
////		return;
////
////	if (g_Fn_tOVL_post_S == 0 )  return;
////
////	// Test Time Begin //
////	 if (g_p_TstTime_Enble)
////	 	g_begintime = g_mytimer.GetElapsedTime();
////
////	// Declare  Variables //
////	int NObin[1] = {0}; // Place holder //
////	int NOhex = 0; // Place holder //
////	float tOVL_post_S =0;
////	float tmeas =0;
////	float ChB_vrng =0.0;
////	int vrng_b	=0.0;
////	float tOVL_post_S_TT = 0;
////
////	Pulse pulse; // External trigger pulse from dvi for debug. //
////
////	// Setup Digitizer //
////	//Gage_pretrig_samples=1024; // Set up the Pre_Trigger sample to be 1024 for better trigger point.
////	//Gage_init();
////	SAMPLE_SIZE = GAGE_POST_4K;
////	vrng_b = GAGE_PM_10_V;
////	ChB_vrng = 5.6;
////
////	// Channel B setup //
////	Gage_Setup_Acquisition_xp(SAMPLE_RATE_Hz,SAMPLE_SIZE); 
////	gage_input_control_xp (GAGE_CHAN_B, // channel
////						   GAGE_INPUT_ENABLE, // enable / disable
////						   GAGE_DC, // coupling
////						   vrng_b|GAGE_1_MOHM_INPUT); // range, impedance
////	gage_trigger_control_xp (GAGE_CHAN_B, // trigger source
////							 GAGE_DC, // coupling for ext trig
////							 vrng_b, // range for CHA trigger
////							 GAGE_NEGATIVE, // slope
////							 4.5, // 1.0V trigger level 
////	   						 SAMPLE_SIZE); // 20ns * GAGE_WAVEFORM_BUFFER_SIZE
////
////	// tOVL or fOVL (Fosc_Overload) //
////	VBPP_Negative_Cycle();
////	//delay(4);
////
////	// Open all relays //
//////	Initialize_Relays();
////
////	// Initialize Instruments //
//////	Initialize_Instruments();
////
////	// Set up Buffer Clamp
////	BC_ovi->set_current(BC_ch, 30e-3, RANGE_30_MA);
////	BC_ovi->set_voltage(BC_ch, (ChB_vrng-0.6),VOLT_10_RANGE); // OVI_1_3 Account for one diode drop
////	wait.delay_10_us(100);
////
////	// Drain //
////	Close_relay(K3);
////	D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
////	D_dvi->set_current(D_ch, 30e-3, RANGE_30_MA); // DVI_11_0 //
////
////	// BPP //
////	BPP_ovi->set_voltage(BPP_ch, 0.0, RANGE_10_V); // OVI_1_0 //
////	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
////
////	// V pin //
////	VPIN_ovi->connect(VPIN_ch);
////	VPIN_ovi->set_voltage(VPIN_ch, 0.0, RANGE_10_V); // OVI_1_1 //
////	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //
////
////	// FW //
////	//Connect_InvSyn_IM(Low_Load_Vd_Input);
////
////	// SR //
////	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
////	SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k //
////	Mux20_Close_relay(K50); // SR pin hard short to GND with relay //
////
////	// BPS //
////	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA);	 // DVI_9_1 //
////	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //
////
////	// FW //
////	Connect_InvSyn_IM(Low_Load_Vd_Input);
////InvSyn_REF_ovi->set_voltage(InvSyn_ch, 3, VOLT_20_RANGE); // OVI_1_4
////	
////	// IS //
////	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE); // DVI_13_0, dvi2k //
////	IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //
////
////	// Vout //
////	VO_dvi->set_voltage(VO_ch, 4.5, VOLT_10_RANGE); // DVI_9_0 //
////	VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //
////
////	// FB (COMP) //
////	FB_ovi->set_voltage(FB_ch, 1, RANGE_2_V); // OVI_1_2 //
////	FB_ovi->set_current(FB_ch, 30e-3, RANGE_30_MA); // OVI_1_2 //
////
////	// VBD //
////	VBD_dvi->set_voltage(VBD_ch, 0.0, VOLT_5_RANGE); // DVI_21_0 //
////	VBD_dvi->set_current(VBD_ch, 30e-6, RANGE_30_UA); // DVI_21_0, prevent glitch //
////	wait.delay_10_us(25); // Prevent glitch //
////	VBD_dvi->set_current(VBD_ch, 0.1e-9, RANGE_30_UA); // DVI_21_0, Float //
////
////	// uVCC //
////	uVCC_ovi->set_voltage(uVCC_ch, 0.0, RANGE_5_V); // OVI_3_2 //
////	uVCC_ovi->set_current(uVCC_ch, 0.1e-9, RANGE_30_UA); // OVI_3_2, Float //
////
////	// DDD level //
////	g_DDD_Low = 0.0; // Save current value //
////	g_DDD_High = 3.3; // Save current value //
////	wait.delay_10_us(g_DDDwait);
////	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////	wait.delay_10_us(g_DDDwait);
////
////	// SDA //
////	Mux20_Close_relay(K64); // SDA pullup to 3.3V through 1.5kohm resistor. //
////	ovi_3->set_voltage(OVI_CHANNEL_7, g_I2C_Pullup, RANGE_5_V); // OVI_3_7 //
////	ovi_3->set_current(OVI_CHANNEL_7, 30e-3, RANGE_30_MA); // OVI_3_7 //
////	Mux20_Close_relay(K37); // Disconnect ovi from SDA. //
////	//SDA_ovi->set_current(SDA_ch, 0.1e-9, RANGE_30_MA); // OVI_3_0, float, let DDD control //
////	Mux20_Close_relay(K38); // Connect SDA and SCL to DDD. //
////	Mux20_Close_relay(K40); // Connect SDA and SCL to DDD. //
////
////	// SCL //
////	Mux20_Close_relay(K39); // Disconnect ovi from SCL. //
////	//SCL_ovi->set_current(SCL_ch, 0.1e-9, RANGE_30_MA); // OVI_3_1, float, let DDD control //
////	ddd_7->ddd_run_pattern(g_SDA_SCL_Low_start, g_SDA_SCL_Low_stop);  // Start with SDA and SCL low with DDD. //
////	
////	// Set DDD for I2C. //
////	ddd_7->ddd_set_clock_period(g_Dclk_I2C);
////	ddd_7->ddd_set_voltage_ref(g_Vref_I2C);
////		
////	// Wait for relays //
////	wait.delay_10_us(200); 
////
////	// Powerup secondary //
////	BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
////	wait.delay_10_us(100); // Must wait long enough for uVCC to come up before sending I2C commands. //
////
////	// I2C into test mode. //  
////	Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
////	Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //
////	//Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //
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
////	// Hold SDA and SCL low before disconnecting DDD. //
////	ovi_3->set_voltage(OVI_CHANNEL_7, 0, RANGE_5_V); // OVI_3_7 //
////	ddd_7->ddd_run_pattern(g_SDA_SCL_Low_start, g_SDA_SCL_Low_stop); 
////	wait.delay_10_us(20);
////	SDA_ovi->set_voltage(SDA_ch, 0.0, RANGE_10_V); // OVI_3_0 //
////	SDA_ovi->set_current(SDA_ch, 30e-3, RANGE_30_MA); // OVI_3_0 //
////	SCL_ovi->set_voltage(SCL_ch, 0.0, RANGE_10_V); // OVI_3_1 //
////	SCL_ovi->set_current(SCL_ch, 30e-3, RANGE_30_MA); // OVI_3_1 //
////	wait.delay_10_us(30);
////	Mux20_Open_relay(K37);
////	Mux20_Open_relay(K38); // Disconnect SDA and SCL from DDD. //
////	Mux20_Open_relay(K39);
////	wait.delay_10_us(300); // Needed to prevent noise on SDA and SCL lines. //
////	Mux20_Open_relay(K40); // Disconnect SDA and SCL from DDD. //
////	Mux20_Open_relay(K64); // Disconnect SDA pullup to 3.3V through 1.5kohm resistor. //
////	wait.delay_10_us(200);
////
////	// Setup DDD //
////	ddd_7->ddd_set_clock_period(Dclk_period);
////	ddd_7->ddd_set_voltage_ref(DDD_Vref);
////
////	// DDD level //
////	g_DDD_Low = 0.0; // Save current value //
////	g_DDD_High = 4.0; // Save current value //
////	wait.delay_10_us(g_DDDwait);
////	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////	wait.delay_10_us(g_DDDwait);
////	wait.delay_10_us(50);
////	ddd_7->ddd_run_pattern(Low_pat_start,Low_pat_stop);
////	wait.delay_10_us(10);
////
////	// Vpin to DDD //
////	Close_relay(K12); // Connect DDD7_1 to Vpin(UV) pin
////	wait.delay_10_us(200);
////	VPIN_ovi->disconnect(VPIN_ch); // Disconnect ovi from Vpin, let DDD control Vpin. //
////	wait.delay_10_us(200);
////
////	// Primary TM5 bypass Wait and Listen power up
////	Power_Up_Primary_BypassWL_TM5(ILIM_NORM);
////	wait.delay_10_us(30);
////	FB_ovi->set_voltage(FB_ch, 1.5, RANGE_2_V); // OVI_1_2 //
////	wait.delay_10_us(30);
////
////	// VBP_P drops when secondary has control //
////	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final+0.1, RANGE_10_V); // prevent undershoot //
////	wait.delay_10_us(8);
////	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final, RANGE_10_V);
////	wait.delay_10_us(10);
////
////	// FB setup //
////	// DDD level //
////	g_DDD_High = 1.0; // Save current value //
////	wait.delay_10_us(g_DDDwait);
////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////	wait.delay_10_us(g_DDDwait);
////	ddd_7->ddd_run_pattern(High_pat_FB_start,High_pat_FB_stop);
////	wait.delay_10_us(10);
////	Close_relay(K17); // Connect FB to DDD_2.  Disconnect FB from ovi. //
////	wait.delay_10_us(200);
////	FB_ovi->set_voltage(FB_ch, 0, RANGE_2_V); // OVI_1_2
////
////	// Connect Vpin back to OVI //
////	VPIN_ovi->connect(VPIN_ch);
////	VPIN_ovi->set_voltage(VPIN_ch, 0.0, RANGE_10_V);  
////	VPIN_ovi->set_current(VPIN_ch, 1e-3, RANGE_30_MA); 
////
////	// Connect Vpin to RDSon buffer circuit. //
////	Close_relay(K35);
////	wait.delay_10_us(100);
////
////	// Setup to measure tOVL from Vpin
////	Open_relay(K12); // disconnect DDD7_1	from Vpin(UV)	pin
////	Close_relay(KC5C); // VPIN_OVI to 15Kohm to UV pin
////	Close_relay(KC6C); // UV pin to 330ohm to TMU_HIZ_DUT3
////	wait.delay_10_us(300);
////	VPIN_ovi->set_voltage(VPIN_ch, 5.0, RANGE_10_V);  
////	wait.delay_10_us(10);
////
////	// Setup FB High/Low switching thresholds
////	// DDD level //
////	g_DDD_Low = 1.0; // Save current value //
////	g_DDD_High = 1.5; // Save current value //
////	wait.delay_10_us(g_DDDwait);
////	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////	wait.delay_10_us(g_DDDwait);
////	ddd_7->ddd_run_pattern(High_pat_FB_start,High_pat_FB_stop);
////	wait.delay_10_us(50);
////
////	Gage_Start_Capture(  );
////
////	// Initiate the first pattern of tOVL to get rid of all of the noise before tmu arm()
////	ddd_7->ddd_run_pattern(FB_tOVL_start,FB_tOVL_stop);
////	wait.delay_10_us(25); // HOT debug
////	Gage_Wait_For_Capture_Complete();
////
////	// Powerdown //
////	D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
////	VPIN_ovi->set_voltage(VPIN_ch, 0, RANGE_10_V); 
////	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA);
////	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
////	VBPP_ramp_down(4, 0, 0.2);
////	Open_relay(K3);
////	Open_relay(K35);
////	Open_relay(KC5C); // VPIN_OVI to 15Kohm to UV pin
////	Open_relay(KC6C); // UV pin to 330ohm to TMU_HIZ_DUT3
////	Open_relay(K17);
////	Mux20_Open_relay(K50);
////	Disconnect_InvSyn_IM();
////	VO_dvi->set_voltage(VO_ch, 0, VOLT_10_RANGE); // DVI_9_0 //
////	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
////	uVCCrampDown(1, 0, 0.1);
////	SR_dvi2k->set_voltage(SR_ch, 5, VOLT_10_RANGE); // DVI_13_1, dvi2k, prevent undershoot //
////	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
////	wait.delay_10_us(45); // prevent SR undershoot //
////	BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
////	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
////	BC_ovi->set_voltage(BC_ch, 0, VOLT_10_RANGE); 
////	VBD_dvi->set_voltage(VBD_ch, 2, VOLT_5_RANGE); // DVI_21_0, prevent undershoot //
////	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
////	wait.delay_10_us(20);
////	VBD_dvi->set_voltage(VBD_ch, 0, VOLT_5_RANGE); // DVI_21_0 //
////	ddd_7->ddd_set_clock_period(Dclk_period);
////	ddd_7->ddd_set_voltage_ref(DDD_Vref);
////
////	// DDD level //
////	g_DDD_Low = 0.0; // Save current value //
////	g_DDD_High = 4.0; // Save current value //
////	wait.delay_10_us(g_DDDwait);
////	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////	wait.delay_10_us(200); // Wait for relays //
////	ddd_7->ddd_run_pattern(Low_pat_start, Low_pat_stop);
////
////	// Reset bit63 shadow register if needed. //
////	if (g_Bit63_Change_Flag == 1)
////	{
////		g_ShadowRegister[63] = 1;
////		g_Bit63_Change_Flag = 0;
////	}
////
////	// Search result //
////	Gage_Find_tOVL(&tOVL_post_S);
////
////	//Gage_pretrig_samples=64;	// Reset the Pre_Trigger Samples back to defaul at 64.
////	//Gage_init() ;
////
////	//Datalog
////	PiDatalog(func, A_tOVL_post_S, tOVL_post_S,	14,	POWER_MICRO);
////
////	// Test Time End //
////	if (g_p_TstTime_Enble)
////	{
////		g_endtime = g_mytimer.GetElapsedTime();
////		tOVL_post_S_TT = (g_endtime - g_begintime)*1e-6;
////		PiDatalog(func, A_tOVL_post_S_TT, tOVL_post_S_TT, 14, POWER_MILLI);
////	}
////
////	// Check any test failed //
////	if (PiGetAnyFailStatus())		
////	{
////		g_PartFailed = 1;
////	}
}
