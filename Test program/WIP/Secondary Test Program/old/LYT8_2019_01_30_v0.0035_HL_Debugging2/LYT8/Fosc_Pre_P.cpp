//==============================================================================
// Fosc_Pre_P.cpp (User function)
// 
//    void Fosc_Pre_P_user_init(test_function& func)
//    void Fosc_Pre_P(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "Fosc_Pre_P.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void Fosc_Pre_P_user_init(test_function& func)
{
	Fosc_Pre_P_params *ours;
    ours = (Fosc_Pre_P_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void Fosc_Pre_P(test_function& func)
{
    // The two lines below must be the first two in the function.
    Fosc_Pre_P_params *ours;
    ours = (Fosc_Pre_P_params *)func.params;

	// Increment function number //
	gFuncNum++;
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_fnum_Fosc_Pre_P, gFuncNum, 14, POWER_UNIT);

	// Skip Test if AbortTest set //
	if (AbortTest)
		return;

	// Skip trimming if g_p_Trim_Enable set //
	if (g_p_Trim_Enable == 0)
		return;

	if (g_Fn_Fosc_Pre_P == 0 )  return;

	// Test Time Begin //
	 if (g_p_TstTime_Enble)
	 	g_begintime = g_mytimer.GetElapsedTime();

	// Declare Variables //
	float Fosc_pt_P=0.0;
	float tmeas=0.0;
	float tElapse=0.0;
	int lcnt =0;
	float Fosc_Pre_P_TT = 0;
	Pulse pulse;

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	// 	Fosc_pt_P: Primary Frequency							
	//  Note: Primay frequency doesn't have Jitter							    
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	Close_relay(K3);
 	tmu_6->close_relay(TMU_HIZ_DUT1);    // Connect TMU HIZ to Drain 
	tmu_6->start_trigger_setup(0.5, NEG_SLOPE, TMU_HIZ, TMU_IN_5V);
	tmu_6->stop_trigger_setup(1.5,	NEG_SLOPE, TMU_HIZ, TMU_IN_5V);
	tmu_6->start_holdoff(0,FALSE);
	tmu_6->stop_holdoff(0,FALSE);
	wait.delay_10_us(300);

	// Update TMU setting to have better Freq measurement //
	tmu_6->start_holdoff(5,TRUE);
	tmu_6->stop_holdoff(128,TRUE);
	wait.delay_10_us(10);			

	//Setup Vpin for digital clocking
	ovi_1->disconnect(OVI_CHANNEL_1);	

	// Initialize DDD
	// DDD level //
	g_DDD_Low = 0.0; // Save current value //
	g_DDD_High = 4.0; // Save current value //
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_run_pattern(Low_pat_start,Low_pat_stop);
	wait.delay_10_us(10);
	Close_relay(K12); // Connect DDD7_1	to Vpin(UV)	pin
	delay(3);

	Power_Up_Primary_BypassWL_TM5(ILIM_NORM);

	tmu_6->arm();					
	delay(8); // Wait for TMU to trigger and to capture 128 cycles
	tmeas = tmu_6->read(8e-3);	 
	tmeas/=128;
	if (tmeas>99)
		Fosc_pt_P=999e3;
	else if (tmeas==0)
		Fosc_pt_P=-999e3;
	else
		Fosc_pt_P=1/(tmeas);
	gFosc_pt_P = Fosc_pt_P;	// Pass to global variable

	// Powerdown //
	D_dvi->set_voltage(D_ch, 0.0, VOLT_50_RANGE); // DVI_11_0
	D_dvi->set_current(D_ch, 300e-3, RANGE_300_MA);
	tmu_6->open_relay(TMU_HIZ_DUT1); // Disconnect TMU HIZ from Drain 
	Open_relay(K3);
	Open_relay(K12);
	VPIN_ovi->connect(VPIN_ch);
	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
	VBPP_ramp_down(4, 0, 0.2);

	// DDD level //
	g_DDD_Low = 0.0; // Save current value //
	g_DDD_High = 4.0; // Save current value //
	wait.delay_10_us(g_DDDwait);
	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	wait.delay_10_us(200); // Wait for relays //
	ddd_7->ddd_run_pattern(Low_pat_start, Low_pat_stop);

	//Power down
	//Power_Down_Everything();
	//Open_All_Relays();
	//Disconnect_InvSyn_IM();
 	//tmu_6->open_relay(TMU_HIZ_DUT1); // Disconnect TMU HIZ from Drain 
	//Open_relay(K12);
	//VPIN_ovi->connect(VPIN_ch);

	//Datalog
	PiDatalog(func, A_Fosc_pt_P, Fosc_pt_P, 14,	POWER_KILO);	

	// Test Time End //
	if (g_p_TstTime_Enble)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		Fosc_Pre_P_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_Fosc_Pre_P_TT, Fosc_Pre_P_TT, 14, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}
