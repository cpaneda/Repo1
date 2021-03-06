//==============================================================================
// Fosc_post_S.cpp (User function)
// 
//    void Fosc_post_S_user_init(test_function& func)
//    void Fosc_post_S(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "Fosc_post_S.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void Fosc_post_S_user_init(test_function& func)
{
	Fosc_post_S_params *ours;
    ours = (Fosc_post_S_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void Fosc_post_S(test_function& func)
{
    // The two lines below must be the first two in the function.
    Fosc_post_S_params *ours;
    ours = (Fosc_post_S_params *)func.params;

	// Increment function number //
	gFuncNum++;
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_Fosc_post_S, gFuncNum, 14, POWER_UNIT);

	//Skip Test if AbortTest set 
	if (AbortTest)
		return;

	if (g_Fn_Fosc_post_S == 0 )  return;

	// Test Time Begin //
	 if (g_p_TstTime_Enble)
	 	g_begintime = g_mytimer.GetElapsedTime();

	// Test Names //
	//int fNum_FoscPost_S = 0;
	float Fosc_WeakBPS = 0;
	//HS_PASS_post
	float Fosc_post_S_TT = 0;

	// Declare Variables //
	int NObin[1] = {0}; // Place holder //
	int NOhex = 0; // Place holder //	
	float tmeas =0.0, toff =0.0;
	Pulse pulse(PULSE_RISING_EDGE,10e-6);			//external trigger pulse from dvi for debug

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	// 					Fosc_WeakBPS: Functionality test									//
	// Note: Lower BPS voltage to vBPS_minus+250mV and make sure communication between      //
	// primary and secondary doesn't get weak. If communication gets weak,					//
	// switching cycles can be missed and caused Fosc to drop.								//
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

	// Open all relays //
//	Initialize_Relays();

	// Initialize Instruments //
//	Initialize_Instruments();

	// Drain //
	Close_relay(K3);
 	tmu_6->close_relay(TMU_HIZ_DUT1); // Connect TMU HIZ to Drain 
	tmu_6->start_trigger_setup(1.0, NEG_SLOPE, TMU_HIZ, TMU_IN_2_5V);
	tmu_6->stop_trigger_setup(1.2, NEG_SLOPE, TMU_HIZ, TMU_IN_2_5V);
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
	//Connect_InvSyn_IM(Low_Load_Vd_Input);

	// SR //
	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
	SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k //
	Mux20_Close_relay(K50); // SR pin hard short to GND with relay //

	// BPS //
	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA);
	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //

	// FW //
	Connect_InvSyn_IM(Low_Load_Vd_Input);

	// Lower the inv sync output GND to get a faster falling edge to make sure secondary request comes before the end of the primary window (tblock = 2us) //
	//ovi_1->set_voltage(OVI_CHANNEL_6, -2.15, VOLT_5_RANGE);
	//ovi_1->set_voltage(OVI_CHANNEL_6, -2.4, VOLT_5_RANGE);
	ovi_1->set_voltage(OVI_CHANNEL_6, -3, VOLT_5_RANGE);

	// Adjust invSYNC reference at hot //
	if (g_OPCODE==4300 || g_OPCODE==4500)
	{
		if (!strnicmp(Part_ID_LimitSet, "INN3368", 7) ||
			!strnicmp(Part_ID_LimitSet, "SC1738", 6))
		{
			InvSyn_REF_ovi->set_voltage(InvSyn_ch, 0.7, VOLT_20_RANGE);	// OVI_1_4	
		}
	}

	// IS //
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_2_RANGE); // DVI_13_0, dvi2k //
	IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //

	// Vout //
	VO_dvi->set_voltage(VO_ch, 4.5, VOLT_10_RANGE); // DVI_9_0 //
	VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //

	// FB (COMP) //
	if (g_ShadowRegister[63] == 1 || g_EEpt_ShadReg63 == 1) // bit[63]: trim_no_fb_pin //
	{
		FB_ovi->disconnect(2);
	}
	else
	{
		FB_ovi->set_voltage(FB_ch, 1, RANGE_2_V); // OVI_1_2 //
		FB_ovi->set_current(FB_ch, 30e-3, RANGE_30_MA); // OVI_1_2 //
	}

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
	//Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //

	// The shadow register should only be loaded if this is a virgin part and EEPROM has not yet been written. //
	if (g_p_Trim_Enable == 0)
	{
		// Do not load shadow register because this is already a trimmed part and EEPROM has already been written. //
	}
	else
	{
		// Load the shadow register //
		LoadShadowRegister();
		wait.delay_10_us(100);
	}

	// Powerup primary in test mode 1. //
	VBPP_Power_Up_w_Test_Mode(gTM1_p,ILIM_NORM);
	BPP_ovi->set_current(BPP_ch, 3e-3,	RANGE_30_MA);

	// Handshake will happen right after 'wait & listen' is done. //

	// Wait for 'wait & listen' to finish. // 
	wait.delay_10_us(350);

	// VBP_P drops when secondary has control //
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final+0.1, RANGE_10_V); // prevent undershoot //
	wait.delay_10_us(8);
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final, RANGE_10_V);
	wait.delay_10_us(10);

	// Bring FB pin or Vout voltage up to stop switching.  fOVL fault will occur if secondary 
	// switches above fOVL frequency for tAR- so, need to reset the tAR timer here 
	// to give enougn time to measure frequency. //
	if (g_ShadowRegister[63] == 1 || g_EEpt_ShadReg63 == 1) // bit[63]: trim_no_fb_pin //
	{
		VO_dvi->set_voltage(VO_ch, 5.5, VOLT_10_RANGE); // DVI_9_0 //
		wait.delay_10_us(50);

		// Drop Vout to start switching. //
		VO_dvi->set_voltage(VO_ch, 4.5, VOLT_10_RANGE); // DVI_9_0 //
	}
	else
	{
		FB_ovi->set_voltage(FB_ch, 1.5, RANGE_2_V); // OVI_1_2	
		wait.delay_10_us(50);

		// Drop FB to start switching. //
		FB_ovi->set_voltage(FB_ch, 1.0, RANGE_2_V); // OVI_1_2	
	}

	// Measure frequency //
	tmu_6->start_holdoff(5,TRUE);
	tmu_6->stop_holdoff(5,TRUE);
	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init+250e-3, VOLT_10_RANGE);	// DVI_9_1
	wait.delay_10_us(10);
	tmu_6->arm();						// Device doing auto-restart
	wait.delay_10_us(15);				// Wait for TMU to trigger and to capture 10 cycles 
	tmeas = tmu_6->read(150e-6);	 
	tmeas/=5;
	if (tmeas != 0)
		Fosc_WeakBPS = 1/tmeas;
	else
		Fosc_WeakBPS = 0.0;	

	// Measure IS2-VBPP_p here to save test time.
	// Make sure VBPP is below shunt otherwise current reading will be wrong. //
	//BPP_ovi->set_voltage(BPP_ch, gVBPP_P_Init-0.100, RANGE_10_V); // Keep below shunt voltage //
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_S_Init_S+0.100, RANGE_10_V); // Test condition per datasheet //
//	VBPP_ramp_down(gVBPP_P_final, g_VBPP_P_S_Init_S+0.100, 0.01);
	BPP_ovi->set_current(BPP_ch, 3e-3, RANGE_3_MA);
	BPP_ovi->set_meas_mode(BPP_ch, OVI_MEASURE_CURRENT);
	wait.delay_10_us(120);
	g_BPP_IS2_sw_P = 0;
	g_BPP_IS2_sw_P = BPP_ovi->measure_average(5);
	g_BPP_IS2_Diff = g_BPP_IS2_sw_P - g_BPP_IS2_Pre;

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	// 					gHandShake_PASS													//
	//  Note: Verify handshake is done properly under normal operating condition.		//
	//  Normal operating condition:VBPS= VBPS_P+0.05V, Itag is pulled up to VBPS_P		//
	//  switching cycles can be missed and caused Fosc to drop.							//
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	tmu_6->start_holdoff(0,FALSE);
	tmu_6->stop_holdoff(0,FALSE);

	// Go above secondary OVP, device should stop switching if it is secondary control
	if (g_ShadowRegister[63] == 1 || g_EEpt_ShadReg63 == 1) // bit[63]: trim_no_fb_pin //
	{
		VO_dvi->set_voltage(VO_ch, 5.5, VOLT_10_RANGE); // DVI_9_0 //
	}
	else
	{
		FB_ovi->set_voltage(FB_ch, 1.5, RANGE_2_V);	// OVI_1_2	
	}
	wait.delay_10_us(10);
	tmu_6->arm(); 
	wait.delay_10_us(10);
	toff = tmu_6->read(); 

	// ++++++++++++++++ BPP:IS1_VBPP-P +++++++++++++++++++++++++++++++++++++++++++++++++ //
	// This test is tested here because primary side turns on an internal Isource after 5ms		 //
	// Originally, these two test are done in VBP_Supply function, but it takes >5ms to test			 //
	// So, moving these two test here will not require ramp to save test time and IS1 meas within 5ms	 //
	// These two test will be datalog in VBP_Supply function since datalog already exist there			 //
	// ++++++++++++++++ BPP:IS1_VBPP-P +++++++++++++++++++++++++++++++++++++++++++++++++ //
	// Make sure VBPP is below shunt otherwise current reading will be wrong //
	//BPP_ovi->set_voltage(BPP_ch, gVBPP_P_Init-0.175, RANGE_10_V); // Keep below shunt voltage //
	//BPP_ovi->set_voltage(BPP_ch, gVBPP_P_Init-0.100, RANGE_10_V); // Keep below shunt voltage //
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_S_Init_S+0.100, RANGE_10_V); // Test condition per datasheet //
	//BPP_ovi->set_current(BPP_ch, 0.001, RANGE_3_MA);
	BPP_ovi->set_meas_mode(BPP_ch, OVI_MEASURE_CURRENT);
	wait.delay_10_us(175);
	g_BPP_IS1_nsw_P = 0.0;
	g_BPP_IS1_nsw_P = BPP_ovi->measure_average(5);
	g_BPP_IS1_Diff = g_BPP_IS1_nsw_P - g_BPP_IS1_Pre;


	// 80kHz => 12.5us period ->toff  [8.5us - 14.5us]
	// 132kHz => 7.5us period ->toff  [3.5us - 9.5us]
	if (g_OPCODE==4200 ||g_OPCODE==4250)
	{
		if( (g_Fosc_Sim_S - Fosc_WeakBPS)  >3.0e3 )	// If Fosc drops more than 3kHz, Handshake fail //
				gHandShake_PASS = 999;
		else if(tmeas < 1e-6  || tmeas > 999) // If part stops switching, Handshake fail //
				gHandShake_PASS = 999;
		else if(toff > (1/gFOSC_TARGET_S_Trimops - 4e-6) && toff < (1/gFOSC_TARGET_S_Trimops + 2.0e-6)) // HandShake fail if primary doesn't stop switching when FB is raised above CV //
				gHandShake_PASS = 999;
		else
				gHandShake_PASS =1;
	}
	else 
	{
		if(toff > (1/gFOSC_TARGET_S_Trimops - 4e-6) && toff < (1/gFOSC_TARGET_S_Trimops + 2.0e-6))
			gHandShake_PASS = 999;
		else
			gHandShake_PASS =1;
	}

	// Powerdown //
	Mux20_Open_relay(K50); // SR pin hard short to GND with relay //
	D_dvi->set_voltage(D_ch, 0.0, VOLT_50_RANGE); // DVI_11_0
	D_dvi->set_current(D_ch, 300e-3, RANGE_300_MA);
	FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
	Disconnect_InvSyn_IM();
	tmu_6->open_relay(TMU_HIZ_DUT1); // Connect TMU HIZ to Drain
	SR_dvi2k->set_voltage(SR_ch, 0.5, VOLT_10_RANGE); // DVI_13_1, dvi2k, prevent undershoot //
	wait.delay_10_us(30); // prevent undershoot //
	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
	wait.delay_10_us(5); // prevent undershoot //
	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
	wait.delay_10_us(5); // prevent undershoot //
	Open_relay(K3); // Drain to RL pullup
	Mux20_Open_relay(K64);
	ovi_3->set_voltage(OVI_CHANNEL_7, 0, RANGE_5_V); // OVI_3_7 //
	Mux20_Open_relay(K37);
	Mux20_Open_relay(K38);
	Mux20_Open_relay(K40);
	Mux20_Open_relay(K39); 
	VPIN_ovi->set_voltage(VPIN_ch, 0.0, RANGE_10_V); // OVI_1_1 //
	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //
	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
	VBPP_ramp_down(4, 0, 0.2);
	wait.delay_10_us(10);
	VO_dvi->set_voltage(VO_ch, 0, VOLT_10_RANGE); // DVI_9_0 //
	wait.delay_10_us(20);
	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
	uVCCrampDown(1, 0, 0.1);
	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
	wait.delay_10_us(2);
	VBPS_ramp_down(3, 0, 150e-3);
	VBD_dvi->set_voltage(VBD_ch, 2, VOLT_5_RANGE); // DVI_21_0, prevent undershoot //
	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
	wait.delay_10_us(20);
	VBD_dvi->set_voltage(VBD_ch, 0, VOLT_5_RANGE); // DVI_21_0 //
	ddd_7->ddd_set_clock_period(Dclk_period);
	ddd_7->ddd_set_voltage_ref(DDD_Vref);
	ddd_7->ddd_run_pattern(Low_pat_start, Low_pat_stop);
	FB_ovi->connect(2);
	FB_ovi->set_voltage(FB_ch, 0, RANGE_2_V); // OVI_1_2 //

	// DDD level //
	g_DDD_Low = 0.0; // Save current value //
	g_DDD_High = 4.0; // Save current value //
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(200); // Wait for relays //

	// Datalog //	
	if(g_p_Trim_Enable)
	{
		PiDatalog(func, A_Fosc_Sim_S, g_Fosc_Sim_S, 14, POWER_KILO);
		PiDatalog(func, A_FOSC_Sim_Chg_S, g_Fosc_Sim_Chg_S, 14, POWER_UNIT);
	}
//	if (g_OPCODE==4200 ||g_OPCODE==4250)
//	{
		PiDatalog(func, A_Fosc_WeakBPS, Fosc_WeakBPS, 14, POWER_KILO);
//	}
	PiDatalog(func, A_HS_PASS_post, gHandShake_PASS, 14, POWER_UNIT);	

	// Test Time End //
	if (g_p_TstTime_Enble)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		Fosc_post_S_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_Fosc_post_S_TT, Fosc_post_S_TT, 14, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}
