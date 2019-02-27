//==============================================================================
// Fosc_Pre_S.cpp (User function)
// 
//    void Fosc_Pre_S_user_init(test_function& func)
//    void Fosc_Pre_S(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "Fosc_Pre_S.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void Fosc_Pre_S_user_init(test_function& func)
{
	Fosc_Pre_S_params *ours;
    ours = (Fosc_Pre_S_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void Fosc_Pre_S(test_function& func)
{
    // The two lines below must be the first two in the function.
    Fosc_Pre_S_params *ours;
    ours = (Fosc_Pre_S_params *)func.params;

	// Increment function number //
	gFuncNum++;
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_Fosc_Pre_S, gFuncNum, 14, POWER_UNIT);

	// Skip Test if AbortTest set  //
	if (AbortTest)
		return;

	// Skip trimming if g_p_Trim_Enable set //
	if (g_p_Trim_Enable == 0)
		return;

	if (g_Fn_Fosc_Pre_S == 0 )  return;

	// Test Time Begin //
	 if (g_p_TstTime_Enble)
	 	g_begintime = g_mytimer.GetElapsedTime();

	// Test Names //
	//float Fosc_pt_S = 0.0;
	float Fosc_Pre_S_TT = 0;

	// Declare Variables //
	int NObin[1] = {0}; // Place holder //
	int NOhex = 0; // Place holder //
	int READ59_word[16] = {0};
	int WordArray[16] = {0};
	float tmeas =0.0; 
	Pulse pulse;

	// Fosc_pt_S: Secondary Frequency //
	// Note: Secondary frequency has Jitter //

	// Open all relays //
//	Initialize_Relays();

	// Initialize Instruments //
//	Initialize_Instruments();

	// Drain //
	Close_relay(K3);
 	tmu_6->close_relay(TMU_HIZ_DUT1); // Connect TMU HIZ to Drain 
	tmu_6->start_trigger_setup(0.9, NEG_SLOPE, TMU_HIZ, TMU_IN_5V);
	tmu_6->stop_trigger_setup(1.1, NEG_SLOPE, TMU_HIZ, TMU_IN_5V);
	tmu_6->start_holdoff(0,FALSE);
	tmu_6->stop_holdoff(0,FALSE);
	D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
	D_dvi->set_current(D_ch, 300e-3,RANGE_300_MA); // DVI_11_0 //	

	// BPP //
	BPP_ovi->set_voltage(BPP_ch, 0.0, RANGE_10_V); // OVI_1_0 //
	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //

	// V pin //
	VPIN_ovi->connect(VPIN_ch);
	VPIN_ovi->set_voltage(VPIN_ch, 0, RANGE_10_V); // OVI_1_1 //
	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //

	// FW //
//	Connect_InvSyn_IM(Low_Load_Vd_Input);

	// SR //
	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
	SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k //
	Mux20_Close_relay(K50); // SR pin hard short to GND with relay //

	// BPS //
	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA);
	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //
	//wait.delay_10_us(10);

	// FW //
	Connect_InvSyn_IM(Low_Load_Vd_Input);

	// Lower the inv sync output GND to get a faster falling edge to make sure secondary request comes before the end of the primary window (tblock = 2us) //
	//ovi_1->set_voltage(OVI_CHANNEL_6, -2.15, VOLT_5_RANGE);

	// IS //
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_2_RANGE); // DVI_13_0, dvi2k //
	IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //

	// Vout //
	VO_dvi->set_voltage(VO_ch, 4.5, VOLT_5_RANGE); // DVI_9_0 //
	VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //

	// FB (COMP) //
	FB_ovi->set_voltage(FB_ch, 1, RANGE_2_V); // OVI_1_2 //
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

	// Powerup secondary //
	BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
	wait.delay_10_us(100); // Must wait long enough for uVCC to come up before sending I2C commands. //

	// I2C secondary into test mode. //  
	Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
	Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //

	Write_Word(g_TM_ANA, 0x0120, NObin, HEX);
	
	//Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //

	// If the COMP(FB) was disconnected with trim, need to reconnect here for controlling 
	// switching freqeuncy with FB pin //
	g_Bit63_Change_Flag = 0;
	if (g_ShadowRegister[63] == 1) // bit[63]: trim_no_fb_pin //
	{
		g_ShadowRegister[63] = 0;
		g_Bit63_Change_Flag = 1;
	}

	// Always load g_ShadowRegister[] array to shadow register of DUT after powerup if EEPROM has not yet been written. //
	LoadShadowRegister();
	wait.delay_10_us(100);

	// Powerup primary in test mode 1. //
	VBPP_Power_Up_w_Test_Mode(gTM1_p,ILIM_NORM);

	// Handshake will happen right after 'wait & listen' is done. //

	// Wait for 'wait & listen' to finish. // 
	wait.delay_10_us(350);

	// Bring FB pin voltage up to stop switching.  fOVL fault will occur if secondary 
	// switches above fOVL frequency for tAR- so, need to reset the tAR timer here 
	// to give enougn time to measure frequency. //
	FB_ovi->set_voltage(FB_ch, 1.5, RANGE_2_V); // OVI_1_2	
	wait.delay_10_us(50);

	// VBP_P drops when secondary has control //
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final+0.1, RANGE_10_V); // prevent undershoot //
	wait.delay_10_us(8);
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final, RANGE_10_V);
	wait.delay_10_us(10);

	// Drop FB to start switching. //
	FB_ovi->set_voltage(FB_ch, 1.0, RANGE_2_V); // OVI_1_2	
	wait.delay_10_us(10);
	tmu_6->start_holdoff(5,TRUE);
	tmu_6->stop_holdoff(128,TRUE);
	tmu_6->arm();
	wait.delay_10_us(150); // Wait for TMU to trigger and to capture 128 cycles (need at least 1280us wait if 10us period)
	tmeas = tmu_6->read(1.5e-3);	 
	tmeas/=128;
	if (tmeas != 0)
			gFOSC_pt_S = 1/tmeas;
		else
			gFOSC_pt_S = 0.0;

	// Powerdown //
	// Do not power down.  Stay powered up for Fosc_Trim_S.cpp. //

	// Datalog
	PiDatalog(func, A_Fosc_pt_S, gFOSC_pt_S, 14,	POWER_KILO);	

	// Test Time End //
	if (g_p_TstTime_Enble)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		Fosc_Pre_S_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_Fosc_Pre_S_TT, Fosc_Pre_S_TT, 14, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}