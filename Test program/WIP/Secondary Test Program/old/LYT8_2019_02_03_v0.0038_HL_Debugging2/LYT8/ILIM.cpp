//==============================================================================
// ILIM.cpp (User function)
// 
//    void ILIM_user_init(test_function& func)
//    void ILIM(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)
#include "ILIM.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void ILIM_user_init(test_function& func)
{
	ILIM_params *ours;
    ours = (ILIM_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void ILIM(test_function& func)
{
    // The two lines below must be the first two in the function.
    ILIM_params *ours;
    ours = (ILIM_params *)func.params;

	// Increment function number //
	gFuncNum++;	
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_ILIM, gFuncNum, 9, POWER_UNIT);

	//Skip Test if AbortTest set 
	if (AbortTest)
		return;

	if (g_Fn_ILIM == 0 )  return;

	// Test Time Begin //
	if (g_p_TstTime_Enble)
		g_begintime = g_mytimer.GetElapsedTime();

	// Declare Variables //
	int NObin[1] = {0}; // Place holder //
	int NOhex = 0; // Place holder //
	//float ILIM_S=0.0;
	float DIDT_S=0.0;
	float TON_S=0.0;
	float DIDT_70pct_P=0.0;
	float TON_70pct_P=0.0;
	float I2F_S=0.0;
	float ILIM_exp_S=0.0;
	float ILIM_act_S=0.0;
	float VIND_P1_S=0.0;
	float ILIM_P1_S=0.0;
	float DIDT_P1_S=0.0;
	float TON_P1_S=0.0;
	float RDSON_P1_S=0.0;
	float ILIM_LO_S=0.0;
	float ILIM_Med_S=0.0;
	float ILIM_High_S=0.0;
	float IlimHigh_JitterLow_132kHz_S=0.0;
	float IlimLow_JitterHigh_132kHz_S=0.0;
	float IlimHigh_JitterLow_18kHz_S=0.0;
	float IlimLow_JitterHigh_18kHz_S=0.0;
	float ILIM_Reduce_w_Jitter_18kHz=0.0;
	float RxTx_CycReq_cnt			= 0.0;
	float RxTx_Hi_BPS_Low_Rcv		= 0.0;
	float RxTx_Lo_BPS_Low_Rcv		= 0.0;
	float RxTx_Hi_BPS_High_Rcv	= 0.0;
	float RxTx_Lo_BPS_High_Rcv	= 0.0;
	float Fosc_Mod_18kHz_S	=0.0;
	float ilim_Spec_P	= 0.0;
	float Dummy_vped=0.0;
	float Dummy_ilim=0.0;
	float Dummy_didt=0.0; 
	float Dummy_ton=0.0;
	float Dummy_rdson_peak = 0.0; 
	float Dummy_rdson_spec =0.0;
	float Rdson_peak_rslt =0.0;
	float Rdson_spec_rslt =0.0; // RDSON_P1_S, Rdson_Spec_P
	float ILIM_Seak_rslt = 0.0;
	float PV3_Charge =0.0;
	float Vped_meas  =0.0;
	float Vpv3_meas  =0.0;
	int lcnt=0;
	int ILIM_Debug =0;
	int Debug_CAPTURED; 
	int ILIM_n_pulses =0;
	float tmeas=0.0;
	float fmeas=0.0;
	float vStep=0.0;
	int i=0;
	int	ENG_Data_Collect=0;
	float ChB_vrng=0.0;
	int vrng_b	=0.0;
	float InvSync_vREF = 0;
	float I2F_ILIM_Incr_P = 0;
	int READ56_word[16] = {0};
	int READ57_word[16] = {0};
	int READ58_word[16] = {0};
	int READ59_word[16] = {0};
	int READ60_word[16] = {0};
	int READ61_word[16] = {0};
	int READ62_word[16] = {0};
	int TempShadowArray[112] = {0};
	int WordArray[16] = {0};
	float ILIM_TT = 0;
	Pulse pulse; // External trigger pulse from dvi for debug //

	if(g_OPCODE==4300 || g_OPCODE==4500) 
	{
		if(gMOSFET_SIZE_Trimops == 2)		InvSync_vREF = 4.5;
		if(gMOSFET_SIZE_Trimops == 3)		InvSync_vREF = 4.5;
		if(gMOSFET_SIZE_Trimops == 4)		InvSync_vREF = 4.5;
		if(gMOSFET_SIZE_Trimops == 5)		InvSync_vREF = 4.0;
		if(gMOSFET_SIZE_Trimops == 6)		InvSync_vREF = 4.5;
		if(gMOSFET_SIZE_Trimops == 7)		InvSync_vREF = 4.5;
		if(gMOSFET_SIZE_Trimops == 8)		InvSync_vREF = 4.0;
	}
	else if(g_OPCODE==4400) 
	{
		if(gMOSFET_SIZE_Trimops == 2)		InvSync_vREF = 3.0;
		if(gMOSFET_SIZE_Trimops == 3)		InvSync_vREF = 3.0;
		if(gMOSFET_SIZE_Trimops == 4)		InvSync_vREF = 3.0;
		if(gMOSFET_SIZE_Trimops == 5)		InvSync_vREF = 5.5;
		if(gMOSFET_SIZE_Trimops == 6)		InvSync_vREF = 5.5;
		if(gMOSFET_SIZE_Trimops == 7)		InvSync_vREF = 5.5;
		if(gMOSFET_SIZE_Trimops == 8)		InvSync_vREF = 5.5;
	}
	else 
	{
		if(gMOSFET_SIZE_Trimops == 2)		InvSync_vREF = 3.0;
		if(gMOSFET_SIZE_Trimops == 3)		InvSync_vREF = 3.0;
		if(gMOSFET_SIZE_Trimops == 4)		InvSync_vREF = 3.0;
		if(gMOSFET_SIZE_Trimops == 5)		InvSync_vREF = 3.0;
		if(gMOSFET_SIZE_Trimops == 6)		InvSync_vREF = 3.0;
		if(gMOSFET_SIZE_Trimops == 7)		InvSync_vREF = 3.0;
		if(gMOSFET_SIZE_Trimops == 8)		InvSync_vREF = 3.0;
	}

	ILIM_Debug = 0;
	Debug_CAPTURED = ILIM_NORM;
	gFind_ILIM_Jitter = 1;

	// Open all relays //
//	Initialize_Relays();

	// Initialize Instruments //
//	Initialize_Instruments();

	PV3_CHARGE_ON(RANGE_100_V);	//Prepare PV3 before power-up
	PV3_Check_Charge(RANGE_100_V);
	pv3_4->charge_off();

	// Pretrig sample were set to 256 in ILIM_Pre.cpp.  Only set pretrig samples here if ILIM_Pre.cpp was skipped. //
	if (g_p_Trim_Enable == 0 || g_Fn_ILIM_Pre == 0)
	{
		//Gage_pretrig_samples=256;
		//Gage_pretrig_samples=1024;
		//Gage_init();
	}
	
	SAMPLE_SIZE = GAGE_POST_32K;
	vrng_b = 0;
	ChB_vrng = 0;
	INNO_Gage_ChanAB_setup(0.1);	// Only do it if SAMPLE_SIZE is diff from previous. (Each input/trig control function takes 4ms)

	// Drain //
	D_dvi->set_voltage(D_ch, 0.0, VOLT_10_RANGE);
	D_dvi->set_current(D_ch, 300e-3, RANGE_300_MA);
	Close_relay(K3); // Drain to dvi through pullup resistor. //
	
	// BPS //
	BPS_dvi->set_voltage(BPS_ch, 0.0, VOLT_10_RANGE);

	// IS //
	IS_dvi2k->set_voltage(IS_ch, 0, VOLT_50_RANGE);
	//IS_dvi2k->set_current(IS_ch, 200e-3, RANGE_200_MA);
	IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //

	// Setup Vpin for DDD clocking //
	//ovi_1->disconnect(OVI_CHANNEL_1);
	VPIN_ovi->disconnect(VPIN_ch);
	
	// Setup DDD //
	// DDD level //
	g_DDD_Low = 0.0; // Save current value //
	g_DDD_High = 4.0; // Save current value //
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_run_pattern(Low_pat_start,Low_pat_stop);
	wait.delay_10_us(10);
	Close_relay(K12); // Connect DDD7_1	to Vpin //

	// Connect 1uF cap to BPP pin to prevent BP droop when drain switching. //
	if(gLoadBoardRev > 24 && gContactorRev > 20)
	{
		mux_14->close_relay(MUX_2_GND);
		Close_relay(K74);
	}
	wait.delay_10_us(300); // Wait for all relays //

	// Remove latchoff problem. //
	VBPP_Negative_Cycle();
	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA);
	wait.delay_10_us(10);

	// Primary Power up with normal mode and TM6 //
	VBPP_ramp_up(0.0, 5.0, 0.2); // vstart, vstop, vstep //	
	wait.delay_10_us(2);
	
	// Vpin pulse 6 times for test mode 6. //
	// In test mode 6 the Vpin becomes the receiver input. //
	ddd_7->ddd_run_pattern(Vpin_6clocks_start,Vpin_6clocks_stop);	
	wait.delay_10_us(5);

	// be able to see AF links properly
	D_dvi->set_voltage(D_ch, 40.0, VOLT_50_RANGE); // DVI_11_0 //	
	wait.delay_10_us(50);

	VBPP_ramp_up(5.0, gVBPP_PV_final, 50e-3);	

	D_dvi->set_voltage(D_ch, 0.0, VOLT_50_RANGE); // DVI_11_0	
	wait.delay_10_us(5);
	VBPP_ramp_down(gVBPP_PV_final, gVBPP_M_Init +0.25, 0.1); // vstart, vstop, vstep	
	wait.delay_10_us(3); // 1.0 uF (ILIM) 30us for ILIM NORM

	// BPP set 4.5V for 100us and 5.2V to bring chip back to normal operation
	BPP_ovi->set_voltage(BPP_ch, gVBPP_M_Init-200e-3, RANGE_10_V); // OVI_1_0 //
	wait.delay_10_us(50);
//	BPP_ovi->set_current(BPP_ch, 2e-3,	RANGE_30_MA);
	BPP_ovi->set_current(BPP_ch, 3e-3,	RANGE_30_MA);
	wait.delay_10_us(1);
	VBPP_ramp_up(gVBPP_M_Init -0.2, gVBPP_P_final, 10e-3);	// vstart, vstop, vstep	B3 material
	wait.delay_10_us(10);

	// Connect Inductor to Drain
	Open_relay(K3); // Drain to RL pullup
	Close_relay(KIM1); // Connect Vind to CT2+ to CT2-
	Close_relay(K9); // Connect CT2- to Drain
	Close_relay(K1); // Connect Iped to CT2+ to CT2-

	if (!strnicmp(Part_ID_LimitSet, "INN3366", 7) || !strnicmp(Part_ID_LimitSet, "INN3376", 7) || !strnicmp(Part_ID_LimitSet, "SC1738", 6) || !strnicmp(Part_ID_LimitSet, "SC1750", 6))
	{
		Close_relay(KIM3); // ILIM Pedestal Use resistor Rpd2
	}
	else
		Open_relay(KIM3); // ILIM Pedestal Use resistor Rpd1

	wait.delay_10_us(300);

	// Setup Pedestal
	D_dvi->set_current(D_ch, 300e-3, RANGE_300_MA);
	D_dvi->set_voltage(D_ch, g_Vpedestal, VOLT_50_RANGE); // DVI_11_0
	D_dvi->set_meas_mode(D_ch, DVI_MEASURE_VOLTAGE);
	wait.delay_10_us(50);
	//pv3_4->charge_off();
	//delay(15);	//must have in order to use PV3 properly

	PV3_Connect_Drain_and_DriveON(gVind_RM); // Drive Voltage

	// Two pulses 30usec apart to give control to secondary. //
	ddd_7->ddd_run_pattern(Vpin_30usec_start,Vpin_30usec_stop);	
	wait.delay_10_us(10);

	// Enable RTM by switch >110kHz for >200usec. //
	ddd_7->ddd_run_pattern(Vpin_125kHz_pulse_start_X,Vpin_125kHz_pulse_stop_X);	
	wait.delay_10_us(100);

	// VBP_P drops when secondary has control //
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final+0.1, RANGE_10_V); // prevent undershoot //
	wait.delay_10_us(8);
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final, RANGE_10_V);
	wait.delay_10_us(20);

	// Start capturing data //
	Gage_Start_Capture();

	// Setup to have ILIM switch for 18pulses, then OFF 30us, ON 10us, OFF 200us and ON for 3 pulses of 100kHz
	ddd_7->ddd_run_pattern(Vpin_100kHz_ILIM_pulse_start,Vpin_100kHz_ILIM_pulse_stop);
	wait.delay_10_us(100);	

	// Finish capturing data //
	Gage_Wait_For_Capture_Complete();
	pv3_4->drive_off();	

	// Process data
	WAVE_NAME =  "ILIM_NORM";
	FIND_RDSON_Peak_FLAG = 0;
	g_SaveAwav = 0;
	Gage_Find_Ilim(&g_ILIM_S, &DIDT_S, &TON_S, &Dummy_rdson_peak, &Dummy_rdson_spec);
	g_SaveAwav = 0;
	I2F_S = g_ILIM_S *g_ILIM_S * 100e3 * 1e-3;	//FB clocking request at 100kHz hence multiply by 100e3

	// Calculate ILIM_act trim
	if( gILIM_pt_S !=0)
		ILIM_act_S = (g_ILIM_S/gILIM_pt_S -1)*100;
	else 
		ILIM_act_S = 999.0;

	// Powerdown //
	pv3_4->set_current(0.1e-9);						
	pv3_4->set_voltage(0, RANGE_100_V);
	wait.delay_10_us(10);
	pv3_4->open_switch(PV3_LOW_FORCE_2);
	pv3_4->open_switch(PV3_LOW_SENSE_2);
	pv3_4->open_switch(PV3_HIGH_FORCE_1);
	pv3_4->open_switch(PV3_HIGH_SENSE_1);
	D_dvi->set_voltage(D_ch, 0.0, VOLT_50_RANGE); // DVI_11_0
	//uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
	//VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
	wait.delay_10_us(10);
	//pv3_4->drive_off();	
	//pv3_4->charge_on();
	Open_relay(K12);
	Open_relay(KIM1);
	Open_relay(K9); // Disconnect CT2 from Drain
	Open_relay(KIM3); // Disconnect Pedestal circuit
	Open_relay(K1); // Disconnect Pedestal circuit
	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA);
	VBPP_ramp_down(3, 0.0, 0.05);	
	//Disconnect_InvSyn_IM();
	//ddd_7->ddd_stop_pattern(); // Need to do a stop pattern when you don't want ddd looping
	wait.delay_10_us(10);
	VPIN_ovi->connect(VPIN_ch);
	//Open_relay(K17); // FB to DDD7_2
	//Mux20_Open_relay(K50);
	//ddd_7->ddd_set_clock_period(Dclk_period);
	//ddd_7->ddd_set_voltage_ref(DDD_Vref);
	if(gLoadBoardRev > 24 && gContactorRev > 20) // Disconnect 1uF cap from BPP. //
	{
		Open_relay(K74);
		mux_14->open_relay(MUX_2_GND);
	}

	// DDD level //
//	g_DDD_Low = 0.0; // Save current value //
//	g_DDD_High = 4.0; // Save current value //
//	wait.delay_10_us(100);
//	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
//	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(200);
	ddd_7->ddd_run_pattern(Low_pat_start, Low_pat_stop);	
//	wait.delay_10_us(3);
//	Power_Down_Primary();
//	wait.delay_10_us(10);
	//Gage_pretrig_samples=64; // Back to previous //
	//Gage_init();

	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	// Receiver and Transmitter sanity check START
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	// Test procedure: - FB request 100 cyles at 100kHz (Transmitter side).
	//				   - Expect Drain (Receiver side) to switch 100 times at 100kHz while secondary in control
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	SAMPLE_SIZE = GAGE_POST_64K;
	RxTx_CycReq_cnt = 100; // Total number of requested counts from FB on secondary side
	
	// Setup Digitizer //
	vrng_b = GAGE_PM_5_V;
	ChB_vrng = 5.0;

	// Channel B setup //
	Gage_Setup_Acquisition_xp(SAMPLE_RATE_Hz,SAMPLE_SIZE); 
	//	delay(2);
	gage_input_control_xp(GAGE_CHAN_B, // channel
						  GAGE_INPUT_ENABLE, // enable / disable
						  GAGE_DC, // coupling
						  vrng_b|GAGE_1_MOHM_INPUT); // range, impedance
	//	delay(2);
	gage_trigger_control_xp(GAGE_CHAN_B, // trigger source
							GAGE_DC, // coupling for ext trig
							vrng_b, // range for CHA trigger
							GAGE_POSITIVE, // slope
							1.0, // 1.0V trigger level 
	   						SAMPLE_SIZE); // 20ns * GAGE_WAVEFORM_BUFFER_SIZE
	//	delay(2);

	// Negative cycle BPP pin //
	VBPP_Negative_Cycle();

	// Open all relays //
	Initialize_Relays();

	// Initialize Instruments //
	Initialize_Instruments();

	// Set up Buffer Clamp
	BC_ovi->set_current(BC_ch, 30e-3, RANGE_30_MA);
	BC_ovi->set_voltage(BC_ch, (ChB_vrng-0.6),VOLT_5_RANGE); // OVI_1_3 Account for one diode drop

	// Drain //
	Close_relay(K3);
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

	// BPS //
	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA);
	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //

	// FW //
	Connect_InvSyn_IM(Low_Load_Vd_Input);

	// Lower the inv sync output GND to get a faster falling edge to make sure secondary request comes before the end of the primary window (tblock = 2us) //
	//ovi_1->set_voltage(OVI_CHANNEL_6, -2.15, VOLT_5_RANGE);

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
//	SDA_ovi->set_current(SDA_ch, 0.1e-9, RANGE_30_MA); // OVI_3_0, float, let DDD control //
	Mux20_Close_relay(K38); // Connect SDA and SCL to DDD. //
	Mux20_Close_relay(K40); // Connect SDA and SCL to DDD. //

	// SCL //
	Mux20_Close_relay(K39); // Disconnect ovi from SCL. //
//	SCL_ovi->set_current(SCL_ch, 0.1e-9, RANGE_30_MA); // OVI_3_1, float, let DDD control //
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
	Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //

	// The shadow register should only be loaded if this is a virgin part and EEPROM has not yet been written. //
	if (g_p_Trim_Enable == 0) // Trimmed part
	{
		// If the COMP(FB) was disconnected with trim, need to reconnect here for controlling 
		// switching freqeuncy with FB pin //
		if (g_EEpt_ShadReg63 == 1) // bit[63]: trim_no_fb_pin //
		{
			// Read out contents of shadow register.  Can't overwrite shadow register. //
			//////
			////Write_Word(g_RDADDR, g_READ59, NObin, HEX);// SREG3.  Shadow register. //
			////Read_Word(g_RDADDR, READ59_word);// SREG3.  Shadow register. //

			////WordArray[0] = READ59_word[0];
			////WordArray[1] = READ59_word[1];
			////WordArray[2] = READ59_word[2];
			////WordArray[3] = READ59_word[3];
			////WordArray[4] = READ59_word[4];
			////WordArray[5] = READ59_word[5];
			////WordArray[6] = READ59_word[6];
			////WordArray[7] = READ59_word[7];
			////WordArray[8] = READ59_word[8];
			////WordArray[9] = READ59_word[9];
			////WordArray[10] = READ59_word[10];
			////WordArray[11] = READ59_word[11];
			////WordArray[12] = READ59_word[12];
			////WordArray[13] = READ59_word[13];
			////WordArray[14] = READ59_word[14];
			////WordArray[15] = READ59_word[15]; // bit[63]: trim_no_fb_pin //
			//////
			WordArray[0] = g_EEpt_ShadReg48;
			WordArray[1] = g_EEpt_ShadReg49;
			WordArray[2] = g_EEpt_ShadReg50;
			WordArray[3] = g_EEpt_ShadReg51;
			WordArray[4] = g_EEpt_ShadReg52;
			WordArray[5] = g_EEpt_ShadReg53;
			WordArray[6] = g_EEpt_ShadReg54;
			WordArray[7] = g_EEpt_ShadReg55;
			WordArray[8] = g_EEpt_ShadReg56;
			WordArray[9] = g_EEpt_ShadReg57;
			WordArray[10] = g_EEpt_ShadReg58;
			WordArray[11] = g_EEpt_ShadReg59;
			WordArray[12] = g_EEpt_ShadReg60;
			WordArray[13] = g_EEpt_ShadReg61;
			WordArray[14] = g_EEpt_ShadReg62;
			WordArray[15] = g_EEpt_ShadReg63; // bit[63]: trim_no_fb_pin //

			// bit[63]: trim_no_fb_pin, set to zero to connect COMP(FB) //
			WordArray[15] = 0;
			Write_Word(g_SREG3, NOhex, WordArray, BIN);
		}
	}
	else // Virgin part //
	{
		// If the COMP(FB) was disconnected with trim, need to reconnect here for controlling 
		// switching freqeuncy with FB pin //
		TempShadowArray[63] = 0; 
		if (g_ShadowRegister[63] == 1) // bit[63]: trim_no_fb_pin //
		{
			TempShadowArray[63] = 1; // Save for later //
			g_ShadowRegister[63] = 0; // bit[63]: trim_no_fb_pin //  READ59_word[15] //
		}
			
		// Load the shadow register //
		LoadShadowRegister();
		wait.delay_10_us(100);
	}

	// Hold SDA and SCL low before disconnecting DDD. //
	ovi_3->set_voltage(OVI_CHANNEL_7, 0, RANGE_5_V); // OVI_3_7 //
	ddd_7->ddd_run_pattern(g_SDA_SCL_Low_start, g_SDA_SCL_Low_stop); 
	wait.delay_10_us(20);
	SDA_ovi->set_voltage(SDA_ch, 0.0, RANGE_10_V); // OVI_3_0 //
	SDA_ovi->set_current(SDA_ch, 30e-3, RANGE_30_MA); // OVI_3_0 //
	SCL_ovi->set_voltage(SCL_ch, 0.0, RANGE_10_V); // OVI_3_1 //
	SCL_ovi->set_current(SCL_ch, 30e-3, RANGE_30_MA); // OVI_3_1 //
	wait.delay_10_us(30);
	Mux20_Open_relay(K37);
	Mux20_Open_relay(K38); // Disconnect SDA and SCL from DDD. //
	Mux20_Open_relay(K39);
	wait.delay_10_us(300); // Needed to prevent noise on SDA and SCL lines. //
	Mux20_Open_relay(K40); // Disconnect SDA and SCL from DDD. //
	Mux20_Open_relay(K64); // Disconnect SDA pullup to 3.3V through 1.5kohm resistor. //
	wait.delay_10_us(200);

	// Powerup primary in test mode 1. //
	VBPP_Power_Up_w_Test_Mode(gTM1_p,ILIM_NORM);

	// Handshake will happen right after 'wait & listen' is done. //

	// Wait for 'wait & listen' to finish. // 
	wait.delay_10_us(400);

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

	// Get FB ready for clocking. //
	// DDD level //
	g_DDD_Low = 0.8; // Save current value //
	g_DDD_High = 1.5; // Save current value //
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_clock_period(Dclk_period);
	ddd_7->ddd_set_voltage_ref(DDD_Vref);
	wait.delay_10_us(50);
	ddd_7->ddd_run_pattern(Low_pat_start,Low_pat_stop);
	wait.delay_10_us(5);

	FB_ovi->set_voltage(FB_ch, 0.8, RANGE_2_V); // OVI_1_2	
	wait.delay_10_us(20);

	// Setup FB to connect to DDD //
	Close_relay(K17); // Connect FB to DDD //
	Close_relay(K10); // Connect drain to RDS buffer circuit to digitize drain waveform. //
	wait.delay_10_us(200);
	FB_ovi->disconnect(2);
	ddd_7->ddd_run_pattern(High_pat_FB_start,High_pat_FB_stop);
	wait.delay_10_us(50);


	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	//  RxTx_LoBPS_HRcv-  With BPS at 4V.
	//	BPS is actual at (gVBPS_P_Init+gVBPS_M_Init)/2 instead of 4.0V.
	//  In test mode 1, the receiver threshold can be changed by changing the Vpin level. 
	//  With Vpin low, the receiver threshold is standard.  With Vpin high, the receiver 
	//  threshold is increased by 5mV. //
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	// Bring up Vpin. //
	// Vpin must be high to enable the elevated receiver threshold.  With Vpin 
	// low, the receiver threshold is standard.  With Vpin high, the receiver 
	// threshold is increased by 5mV. //
	VPIN_ovi->set_voltage(VPIN_ch, 5, RANGE_10_V);
	wait.delay_10_us(5);
	VO_dvi->set_voltage(VO_ch, 3.7, VOLT_5_RANGE); // DVI_9_0
	wait.delay_10_us(5);

	// BPS set to 4.0V to ensure communication between primary and secondary is good. //
	VBPS_ramp_down(4.4, 4.0, 20e-3);
	wait.delay_10_us(50);

	// DDD occasionally does not send pulses, not well understood, need to run these pulses first to fix. //
	ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
	wait.delay_10_us(150);
	ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
	wait.delay_10_us(150);
	ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
	wait.delay_10_us(150);

	// Gage_Start_Capture, RxTx_LoBPS
	Gage_Start_Capture(  );
	wait.delay_10_us(10);

	// Issue 100 FB pulses with Normal VBPP requesting primary to switch 100 times and expect 100 ILIM pulses
	ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
	wait.delay_10_us(105);

	// Gage_End_Capture, RxTx_LoBPS
	Gage_Wait_For_Capture_Complete();

	// Start drain switching to prevent secondary from giving up control during the data 
	// processing time in the Gage_Count_Cycles_CHB() function.  If too much time goes by 
	// without any seconary requests then primary takes control. //
	ddd_7->ddd_end_pattern(FB_100kHz_loop_pulse_stop); // Run a looping pattern. //
	ddd_7->ddd_run_pattern(); // Need to do a stop pattern to stop ddd looping //

	// Process data //
	g_SaveAwav = 0;
	Gage_Count_Cycles_CHB(&RxTx_Lo_BPS_High_Rcv);
	g_SaveAwav = 0;

	// Call stop pattern to stop ddd looping //
	ddd_7->ddd_stop_pattern(); 

	if (g_p_Char_Enable) // Characterization only //
	{
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
		// RxTx_HiBPS_HRcv-  With BPS at 4.4V.
		// 
		// In test mode 1, the receiver threshold can be changed by changing the Vpin level. 
		// With Vpin low, the receiver threshold is standard.  With Vpin high, the receiver 
		// threshold is increased by 5mV. //
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
		// Bring up Vpin. //
		// Vpin must be high to enable the elevated receiver threshold.  With Vpin 
		// low, the receiver threshold is standard.  With Vpin high, the receiver 
		// threshold is increased by 5mV. // 
		VPIN_ovi->set_voltage(VPIN_ch, 5, RANGE_10_V);
		wait.delay_10_us(5);
		VO_dvi->set_voltage(VO_ch, 4.0, VOLT_5_RANGE); // DVI_9_0
		wait.delay_10_us(5);

		// BPS must be high //
		BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
		wait.delay_10_us(50);

		// DDD occasionally does not send pulses, not well understood, need to run these pulses first to fix. //
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(150);
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(150);
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(150);

		// Gage_Start_Capture, RxTx_LoBPS
		Gage_Start_Capture(  );
		wait.delay_10_us(10);

		// Issue 100 FB pulses with Normal VBPP requesting primary to switch 100 times and expect 100 ILIM pulses
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(105);

		// Gage_End_Capture, RxTx_LoBPS
		Gage_Wait_For_Capture_Complete();

		// Start drain switching to prevent secondary from giving up control during the data 
		// processing time in the Gage_Count_Cycles_CHB() function.  If too much time goes by 
		// without any seconary requests then primary takes control. //
		ddd_7->ddd_end_pattern(FB_100kHz_loop_pulse_stop); // Run a looping pattern. //
		ddd_7->ddd_run_pattern(); // Need to do a stop pattern to stop ddd looping //

		// Process data //
		g_SaveAwav = 0;
		Gage_Count_Cycles_CHB(&RxTx_Hi_BPS_High_Rcv);
		g_SaveAwav = 0;

		// Call stop pattern to stop ddd looping //
		ddd_7->ddd_stop_pattern();


		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
		// RxTx_HiBPS_LRcv-  With High BPS at 4.4V.
		// 
		// In test mode 1, the receiver threshold can be changed by changing the Vpin level. 
		// With Vpin low, the receiver threshold is standard.  With Vpin high, the receiver 
		// threshold is increased by 5mV. //
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
		// Vpin low //
		// Vpin must be low for the lower receiver threshold.  With Vpin 
		// low, the receiver threshold is standard.  With Vpin high, the receiver 
		// threshold is increased by 5mV. // 
		VPIN_ovi->set_voltage(VPIN_ch, 0, RANGE_10_V);
		wait.delay_10_us(5);
		VO_dvi->set_voltage(VO_ch, 4.0, VOLT_5_RANGE); // DVI_9_0
		wait.delay_10_us(5);

		// BPS must be high //
		BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
		wait.delay_10_us(50);

		// DDD occasionally does not send pulses, not well understood, need to run these pulses first to fix. //
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(150);
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(150);
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(150);

		// Start waveform capture //
		Gage_Start_Capture(  );
		wait.delay_10_us(10);

		// Issue 100 FB pulses with Normal VBPP requesting primary to switch 100 times and expect 100 ILIM pulses
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(105);

		// End waveform capture //
		Gage_Wait_For_Capture_Complete();

		// Start drain switching to prevent secondary from giving up control during the data 
		// processing time in the Gage_Count_Cycles_CHB() function.  If too much time goes by 
		// without any seconary requests then primary takes control. //
		ddd_7->ddd_end_pattern(FB_100kHz_loop_pulse_stop); // Run a looping pattern. //
		ddd_7->ddd_run_pattern(); // Need to do a stop pattern to stop ddd looping //

		// Process data //
		g_SaveAwav = 0;
		Gage_Count_Cycles_CHB(&RxTx_Hi_BPS_Low_Rcv);
		g_SaveAwav = 0;

		// Call stop pattern to stop ddd looping //
		ddd_7->ddd_stop_pattern(); 

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
		//  RxTx_Lo_BPS_Low_Rcv-  With BPS at 4V.
		//	
		// In test mode 1, the receiver threshold can be changed by changing the Vpin level. 
		// With Vpin low, the receiver threshold is standard.  With Vpin high, the receiver 
		// threshold is increased by 5mV. //
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
		VPIN_ovi->set_voltage(VPIN_ch, 0, RANGE_10_V);
		wait.delay_10_us(5);
		VO_dvi->set_voltage(VO_ch, 3.7, VOLT_5_RANGE); // DVI_9_0
		wait.delay_10_us(10);

		// BPS set to 4.0V to ensure communication between primary and secondary is good. //
		VBPS_ramp_down(4.4, 4.0, 20e-3);
		wait.delay_10_us(50);

		// DDD occasionally does not send pulses, not well understood, need to run these pulses first to fix. //
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(150);
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(150);
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(150);

		// Gage_Start_Capture, RxTx_LoBPS
		Gage_Start_Capture(  );
		wait.delay_10_us(10);

		// Issue 100 FB pulses with Normal VBPP requesting primary to switch 100 times and expect 100 ILIM pulses
		ddd_7->ddd_run_pattern(FB_100kHz_100_pulses_start, FB_100kHz_100_pulses_stop);
		wait.delay_10_us(105);

		// Gage_End_Capture, RxTx_LoBPS
		Gage_Wait_For_Capture_Complete();

		// Start drain switching to prevent secondary from giving up control during the data 
		// processing time in the Gage_Count_Cycles_CHB() function.  If too much time goes by 
		// without any seconary requests then primary takes control. //
		ddd_7->ddd_end_pattern(FB_100kHz_loop_pulse_stop); // Run a looping pattern. //
		ddd_7->ddd_run_pattern(); // Need to do a stop pattern to stop ddd looping //

		// Process data //
		g_SaveAwav = 0;
		Gage_Count_Cycles_CHB(&RxTx_Lo_BPS_Low_Rcv);
		g_SaveAwav = 0;

		// Call stop pattern to stop ddd looping //
		ddd_7->ddd_stop_pattern(); 
	}

	// Powerdown //
	D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
	VPIN_ovi->set_voltage(VPIN_ch, 0, RANGE_10_V); // OVI_1_1 //
	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA);
	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
	VBPP_ramp_down(3, 0, 0.2);
	Open_relay(K3);
	Open_relay(K17);
	Open_relay(K10);
	Disconnect_InvSyn_IM();
	VO_dvi->set_voltage(VO_ch, 0, VOLT_5_RANGE); // DVI_9_0 //
	FB_ovi->connect(2);
	FB_ovi->set_voltage(FB_ch, 0, RANGE_2_V); // OVI_1_2
	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
	uVCCrampDown(1, 0, 0.1);
	SR_dvi2k->set_voltage(SR_ch, 5, VOLT_10_RANGE); // DVI_13_1, dvi2k, prevent undershoot //
	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
	wait.delay_10_us(45); // prevent SR undershoot //
	BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
	BC_ovi->set_voltage(BC_ch, 0, VOLT_5_RANGE); // OVI_1_3
	VBD_dvi->set_voltage(VBD_ch, 2, VOLT_5_RANGE); // DVI_21_0, prevent undershoot //
	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
	wait.delay_10_us(20);
	VBD_dvi->set_voltage(VBD_ch, 0, VOLT_5_RANGE); // DVI_21_0 //
	ddd_7->ddd_set_clock_period(Dclk_period);
	ddd_7->ddd_set_voltage_ref(DDD_Vref);
	
	// DDD level //
	g_DDD_Low = 0.0; // Save current value //
	g_DDD_High = 4.0; // Save current value //
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(200); // Wait for relays //

	// The shadow register should only be loaded if this is a virgin part and EEPROM has not yet been written. //
	if (g_p_Trim_Enable == 0)
	{
		// Do not load shadow register because this is already a trimmed part and EEPROM has already been written. //
	}
	else // Virgin part //
	{
		// Need to set bit63 in shadow register back to trimmed. //
		if (TempShadowArray[63] == 1) // bit[63]: trim_no_fb_pin //
		{
			g_ShadowRegister[63] = 1; // bit[63]: trim_no_fb_pin //  READ59_word[15] //
		}
	}

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	// ILIM_P1: Secondary Control (ZF-P MUST TRIMMED)
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	// Buffer clamp needs to be reconnected //
//	INNO_Gage_ChanAB_setup(0.1); // Only do it if SAMPLE_SIZE is diff from previous. (Each input/trig control function takes 4ms)

	// Open all relays //
//	Initialize_Relays();

	// Initialize Instruments //
//	Initialize_Instruments();

	// Power Down from previous //
	//Power_Down_Everything_Except_Buf_Clamp();
	//Open_All_Relays();

	PV3_CHARGE_ON(RANGE_100_V);	//Prepare PV3 before power-up
	PV3_Check_Charge(RANGE_100_V);
	pv3_4->charge_off();

//	Gage_pretrig_samples=256;
//	Gage_init();
	SAMPLE_SIZE = GAGE_POST_32K;
	vrng_b = 0;
	ChB_vrng = 0;
	INNO_Gage_ChanAB_setup(0.1);	// Only do it if SAMPLE_SIZE is diff from previous. (Each input/trig control function takes 4ms)

	// Drain //
	D_dvi->set_voltage(D_ch, 0.0, VOLT_10_RANGE);
	D_dvi->set_current(D_ch, 300e-3, RANGE_300_MA);
	Close_relay(K3); // Drain to dvi through pullup resistor. //
	
	// BPS //
	BPS_dvi->set_voltage(BPS_ch, 0.0, VOLT_10_RANGE);

	// IS //
	IS_dvi2k->set_voltage(IS_ch, 0, VOLT_50_RANGE);
	//IS_dvi2k->set_current(IS_ch, 200e-3, RANGE_200_MA);
	IS_dvi2k->set_current(IS_ch, 20e-3, RANGE_20_MA);

	// Setup Vpin for DDD clocking //
	//ovi_1->disconnect(OVI_CHANNEL_1);
	VPIN_ovi->disconnect(VPIN_ch);
	
	// Setup DDD //
	// DDD level //
	g_DDD_Low = 0.0; // Save current value //
	g_DDD_High = 5.0; // Save current value //
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_run_pattern(Low_pat_start,Low_pat_stop);
	wait.delay_10_us(10);
	Close_relay(K12); // Connect DDD7_1	to Vpin //

	// Connect 1uF cap to BPP pin to prevent BP droop when drain switching. //
	if(gLoadBoardRev > 24 && gContactorRev > 20)
	{
		mux_14->close_relay(MUX_2_GND);
		Close_relay(K74);
	}
	wait.delay_10_us(300); // Wait for all relays //

	// Remove latchoff problem. //
	VBPP_Negative_Cycle();
	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA);
	wait.delay_10_us(10);

	// Primary Power up with normal mode and TM6 //
	VBPP_ramp_up(0.0, 5.0, 0.2); // vstart, vstop, vstep //	
	wait.delay_10_us(2);
	
	// Vpin pulse 6 times for test mode 6. //
	// In test mode 6 the Vpin becomes the receiver input. //
	ddd_7->ddd_run_pattern(Vpin_6clocks_start,Vpin_6clocks_stop);	
	wait.delay_10_us(5);

	// be able to see AF links properly
	D_dvi->set_voltage(D_ch, 40.0, VOLT_50_RANGE); // DVI_11_0 //	
	wait.delay_10_us(50);

//	VBPP_ramp_up(5.0, gVBPP_PV_Init, 50e-3);
VBPP_ramp_up(5.0, gVBPP_PV_final, 50e-3);

	D_dvi->set_voltage(D_ch, 0.0, VOLT_50_RANGE); // DVI_11_0	
//	wait.delay_10_us(50);
wait.delay_10_us(5);
//	VBPP_ramp_down(gVBPP_PV_Init, gVBPP_M_Init +0.25, 0.1);	// vstart, vstop, vstep
VBPP_ramp_down(gVBPP_PV_final, gVBPP_M_Init +0.25, 0.1); // vstart, vstop, vstep
	wait.delay_10_us(150); // 10uF (ILIM+1) 1.2ms

	// BPP set 4.5V for 100us and 5.2V to bring chip back to normal operation
	BPP_ovi->set_voltage(BPP_ch, gVBPP_M_Init-200e-3, RANGE_10_V); // OVI_1_0 //
	wait.delay_10_us(50);

//	BPP_ovi->set_current(BPP_ch, 2e-3,	RANGE_30_MA);
	BPP_ovi->set_current(BPP_ch, 3e-3,	RANGE_30_MA);
	wait.delay_10_us(1);
	VBPP_ramp_up(gVBPP_M_Init -0.2, gVBPP_P_final, 10e-3);	// vstart, vstop, vstep	B3 material
	wait.delay_10_us(10);

	// Connect Inductor to Drain
	Open_relay(K3); // Drain to RL pullup
	Close_relay(KIM1); // Connect Vind to CT2+ to CT2-
	Close_relay(K9); // Connect CT2- to Drain
	Close_relay(K1); // Connect Iped to CT2+ to CT2-

	if (!strnicmp(Part_ID_LimitSet, "INN3366", 7) || !strnicmp(Part_ID_LimitSet, "INN3376", 7) || !strnicmp(Part_ID_LimitSet, "SC1738", 6) || !strnicmp(Part_ID_LimitSet, "SC1750", 6))
	{
		Close_relay(KIM3); // ILIM Pedestal Use resistor Rpd2
	}
	else
		Open_relay(KIM3); // ILIM Pedestal Use resistor Rpd1

	wait.delay_10_us(300);

	// Setup Pedestal
	D_dvi->set_current(D_ch, 300e-3, RANGE_300_MA);
	D_dvi->set_voltage(D_ch, g_Vpedestal, VOLT_50_RANGE); // DVI_11_0
	D_dvi->set_meas_mode(D_ch, DVI_MEASURE_VOLTAGE);
	wait.delay_10_us(50);
	//pv3_4->charge_off();
	//delay(15);	//must have in order to use PV3 properly

	PV3_Connect_Drain_and_DriveON(gVind_RM); // Drive Voltage

	// Two pulses 30usec apart to give control to secondary. //
	ddd_7->ddd_run_pattern(Vpin_30usec_start,Vpin_30usec_stop);	
	wait.delay_10_us(10);

	// Enable RTM by switch >110kHz for >200usec. //
	ddd_7->ddd_run_pattern(Vpin_125kHz_pulse_start_X,Vpin_125kHz_pulse_stop_X);	
	wait.delay_10_us(100);

	// VBP_P drops when secondary has control //
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final+0.1, RANGE_10_V); // prevent undershoot //
	wait.delay_10_us(8);
	//BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final, RANGE_10_V);
	BPP_ovi->set_voltage(BPP_ch, g_VBPP_P_s_final + 0.05, RANGE_10_V);
	wait.delay_10_us(20);

	// Start capturing data //
	Gage_Start_Capture();

	// Setup to have ILIM switch //
	ddd_7->ddd_run_pattern(Vpin_100kHz_ILIM_pulse_start_X, Vpin_100kHz_ILIM_pulse_stop_X);
	wait.delay_10_us(100);	

	// Finish capturing data //
	Gage_Wait_For_Capture_Complete();

	// Process data
	WAVE_NAME =  "ILIM_P1";
	g_SaveAwav = 0;
	Gage_Find_Ilim(&ILIM_P1_S, &DIDT_P1_S, &TON_P1_S, &Dummy_rdson_peak, &Dummy_rdson_spec);
	g_SaveAwav = 0;
	I2F_ILIM_Incr_P = ILIM_P1_S *ILIM_P1_S * 100e3 * 1e-3;	// Vpin clocking request at 100kHz hence multiply by 100e3


	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	// 				Rdson at ILIM_P1 peak:	Secondary control										
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	Close_relay(K10); // Drain to Rdson Buffer
	wait.delay_10_us(300);

	// Start capturing data //
	Gage_Start_Capture(  );

	// Setup to have ILIM switch //
	ddd_7->ddd_run_pattern(Vpin_100kHz_ILIM_pulse_start_X, Vpin_100kHz_ILIM_pulse_stop_X);
	wait.delay_10_us(100);	

	// Finish capturing data //
	Gage_Wait_For_Capture_Complete();
	pv3_4->drive_off();	

	// Process data
	WAVE_NAME =  "ILIM_P1_RDSON_PEAK";
	FIND_RDSON_Peak_FLAG = 1; // Will be reset at the end of  Gage_Find_Ilim func
	g_SaveAwav = 0;
	Gage_Find_Ilim(&ILIM_Seak_rslt, &Dummy_didt, &Dummy_didt, &Rdson_peak_rslt, &Dummy_rdson_spec);
	g_SaveAwav = 0;

	// Use ILIM_P1_S without Rdson buffer connected for more accurate measurement. 
	if (ILIM_P1_S !=0)
		RDSON_P1_S = (Rdson_peak_rslt * ILIM_Seak_rslt) /ILIM_P1_S;     
	else
		RDSON_P1_S = 999.0;
	
	// Power down //
	Open_relay(K10); // Disconnect Rdson Buffer
	pv3_4->set_current(0.1e-9);						
	pv3_4->set_voltage(0, RANGE_100_V);
	wait.delay_10_us(10);
	pv3_4->open_switch(PV3_LOW_FORCE_2);
	pv3_4->open_switch(PV3_LOW_SENSE_2);
	pv3_4->open_switch(PV3_HIGH_FORCE_1);
	pv3_4->open_switch(PV3_HIGH_SENSE_1);
	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
	VBPP_ramp_down(3, 0.0, 0.05);
	D_dvi->set_voltage(D_ch, 0.0, VOLT_50_RANGE); // DVI_11_0
//	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
//	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
//	wait.delay_10_us(10);
	Open_relay(KIM1);
	Open_relay(K9); // Disconnect CT2 from Drain
	Open_relay(KIM3); // Disconnect Pedestal circuit
	Open_relay(K1); // Disconnect Pedestal circuit
	Open_relay(K12);
	VPIN_ovi->connect(VPIN_ch);
//	Disconnect_InvSyn_IM();
//	ddd_7->ddd_stop_pattern(); // Need to do a stop pattern when you don't want ddd looping
//	wait.delay_10_us(10);
//	Open_relay(K17); // FB to DDD7_2
//	Mux20_Open_relay(K50);
//	ddd_7->ddd_set_clock_period(Dclk_period);
//	ddd_7->ddd_set_voltage_ref(DDD_Vref);
	if(gLoadBoardRev > 24 && gContactorRev > 20) // Disconnect 1uF cap from BPP. //
	{
		Open_relay(K74);
		mux_14->open_relay(MUX_2_GND);
	}

	// DDD level //
	//g_DDD_Low = 0.0; // Save current value //
	//g_DDD_High = 4.0; // Save current value //
	//wait.delay_10_us(100);
	//ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	//ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	//wait.delay_10_us(100);
	ddd_7->ddd_run_pattern(Low_pat_start, Low_pat_stop);	
	//Gage_pretrig_samples=64; // Back to previous //
	//Gage_init();
	wait.delay_10_us(200);

	// Datalog //
	PiDatalog(func, A_ILIM_S, g_ILIM_S, 9, POWER_MILLI);
	PiDatalog(func, A_DIDT_S, DIDT_S, 9, POWER_MILLI);
	PiDatalog(func, A_TON_S, TON_S, 9, POWER_MICRO);
	PiDatalog(func, A_I2F_S, I2F_S, 9, POWER_UNIT);
	if(g_p_Trim_Enable)
	{
		PiDatalog(func, A_ILIM_exp_S, gILIM_exp_S, 9, POWER_UNIT);	
		PiDatalog(func, A_ILIM_act_S, ILIM_act_S, 9, POWER_UNIT);
	}
	PiDatalog(func, A_ILIM_Low_S, gILIM_pct_1stP, 9, POWER_UNIT);
	PiDatalog(func, A_ILIM_Med_S, gILIM_pct_2ndP, 9, POWER_UNIT);
	PiDatalog(func, A_ILIM_High_S, gILIM_pct_3rdP, 9, POWER_UNIT);
	PiDatalog(func, A_ILIM_RTM_Slope, gRTM_Slope, 9, POWER_UNIT);
	PiDatalog(func, A_tDelta_RTM_Slope_30us_S, gtDelta_RTM_Slope, 9, POWER_MICRO);
	PiDatalog(func, A_i_pct_drop_RTM, -gi_pct_drop_RTM, 9,	POWER_UNIT);
	PiDatalog(func, A_tDelta_RTM_Slope_200us_S,	gtDelta_RTM_Slope_200us, 9, POWER_MICRO);
	PiDatalog(func, A_ILIM_200us_S, gILIM_200us_S, 9, POWER_MILLI);
	PiDatalog(func, A_ILIM_200us_pct_S, -gILIM_200us_pct_S, 9, POWER_UNIT);

	PiDatalog(func, A_RxTx_CycReq_cnt, RxTx_CycReq_cnt, 28, POWER_UNIT);
	PiDatalog(func, A_RxTx_Lo_BPS_High_Rcv, RxTx_Lo_BPS_High_Rcv-6, 28, POWER_UNIT);
	
	if (g_p_Char_Enable) // Characterization only //
	{
		PiDatalog(func, A_RxTx_Hi_BPS_Low_Rcv, RxTx_Hi_BPS_Low_Rcv-6, 28, POWER_UNIT);
		PiDatalog(func, A_RxTx_Lo_BPS_Low_Rcv, RxTx_Lo_BPS_Low_Rcv-6, 28, POWER_UNIT);
		PiDatalog(func, A_RxTx_Hi_BPS_High_Rcv, RxTx_Hi_BPS_High_Rcv-6, 28, POWER_UNIT);
	}
	PiDatalog(func, A_ILIM_P1_S, ILIM_P1_S, 9, POWER_MILLI);
	PiDatalog(func, A_DIDT_P1_S, DIDT_P1_S, 9, POWER_MILLI);
	PiDatalog(func, A_TON_P1_S, TON_P1_S, 9, POWER_MICRO);
	PiDatalog(func, A_I2F_ILIM_Incr_P, I2F_ILIM_Incr_P, 9, POWER_UNIT);
	PiDatalog(func, A_RDSON_P1_S, RDSON_P1_S, 13, POWER_UNIT);

	// Test Time End //
	if (g_p_TstTime_Enble)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		ILIM_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_ILIM_TT, ILIM_TT, 9, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}