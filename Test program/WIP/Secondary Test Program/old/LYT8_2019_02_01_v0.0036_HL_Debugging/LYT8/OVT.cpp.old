//==============================================================================
// OVT.cpp (User function)
// 
//    void OVT_user_init(test_function& func)
//    void OVT(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)
#include "OVT.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void OVT_user_init(test_function& func)
{
	OVT_params *ours;
    ours = (OVT_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void OVT(test_function& func)
{
    // The two lines below must be the first two in the function.
    OVT_params *ours;
    ours = (OVT_params *)func.params;

	// Increment function number //
	gFuncNum++;

	////// Datalog gFuncNum variable //
	////if(gDisplay_FuncNum)
	////	PiDatalog(func, A_Func_Num_OVT, gFuncNum, 30, POWER_UNIT);

	////// Skip Test if AbortTest set //
	////if (AbortTest)
	////	return;

	////if (g_OPCODE==4300 ||g_OPCODE==4500)
	////	return;

	////if (g_Fn_OVT == 0 )  return;

	////// Test Time Begin //
	//// if (g_p_TstTime_Enble)
	//// 	g_begintime = g_mytimer.GetElapsedTime();

	////// Declare Variables //
	////int NObin[1] = {0}; // Place holder //
	////int NOhex = 0; // Place holder //
	////float WordData = 0;
	////int OVT_OFF =0;
	////int OVT_ON =0;
	////float tmeas=0.0;
	////float tElapse=0.0;
	////float WAIT_n_LISTEN_TM_starttime=0;
	////float WAIT_n_LISTEN_TM_stoptime=0;
	////float WAIT_n_LISTEN_TM_time=0;
	////float t_hi=0.0; 
	////float t_lo=0.0;
	////float Imeas_Before = 0;
	////float Imeas_After = 0;
	////float OVT_TT = 0;

	////Pulse pulse;// external trigger pulse from dvi for debug //


	////ovi_1->disconnect(OVI_CHANNEL_1);	// Vpin does not use ovi-1-1 for Iz function

	////// Initialize DDD
	////// DDD level //
	////g_DDD_Low = 0.0; // Save current value //
	////g_DDD_High = 4.0; // Save current value //
	////wait.delay_10_us(g_DDDwait);
	////ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	////ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	////wait.delay_10_us(g_DDDwait);
	////ddd_7->ddd_run_pattern(Low_pat_start,Low_pat_stop);
	////wait.delay_10_us(10);

	////Close_relay(K12);					// Connect DDD7_1	to Vpin(UV)	pin
	////Close_relay(K3);					// Connect Drain	to R1 and L1 Load
 ////	tmu_6->close_relay(TMU_HIZ_DUT1);   // Connect TMU HIZ	to Drain 

	////tmu_6->start_trigger_setup(0.4, NEG_SLOPE, TMU_HIZ, TMU_IN_10V);
	////tmu_6->stop_trigger_setup(0.5,	NEG_SLOPE, TMU_HIZ, TMU_IN_10V);
	////tmu_6->start_holdoff(0,FALSE);
	////tmu_6->stop_holdoff(0,FALSE);
	////VBPP_Negative_Cycle();
	////delay(4);
	////
	////// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	////// OVER TEMPERATURE
	//////																																						
	////// Entry into OT mode follows a similar sequence as that for Write and Program; the 
	////// difference is that we clock in
	////// 4 posedges on VPIN.  Once that is done, we keep drain low, so it stays in testmode1 (like Inno3).
	////// Finish the zig-zag on BP and the primary will start switching.  With VPIN at 0, the 
	////// OT threshold will be around ~60C; VPIN at 1, threshold drops to ~19C, so at room temp 
	////// of 25C, it should stop switching.
	////// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
	////BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
	////Powerup_Primary_in_Testmode(gOT_Mode);

	////WAIT_n_LISTEN_TM_starttime = mytimer.GetElapsedTime();
	////tElapse = 0;
	////tmeas = 0;
	////while(tElapse<7e-3 && tmeas < 0.1e-9)
	////{
	////	tmu_6->arm();					
	////	wait.delay_10_us(10);			
	////	tmeas = tmu_6->read(40e-6);
	////	tElapse += 40e-6; //Estimated time per loop without the arm() and read() in account.
	////}
	////WAIT_n_LISTEN_TM_stoptime = mytimer.GetElapsedTime();
	////WAIT_n_LISTEN_TM_time = (WAIT_n_LISTEN_TM_stoptime - WAIT_n_LISTEN_TM_starttime)*1e-6;

	////if(WAIT_n_LISTEN_TM_time < 7e-3) // Possible test time saving here //
	////{
	////	gDly_Wait_and_Listen_Test_Mode	 = WAIT_n_LISTEN_TM_time*1e5 + 10;	//add another 100us so we are sure in switching state
	////	gDly_Wait_and_Listen_Normal_Mode = WAIT_n_LISTEN_TM_time*1e3*32 + 15; //add another 10ms to ensure switching
	////}
	////else
	////{
	////	gDly_Wait_and_Listen_Test_Mode		= 300;	//Test   Mode delay for "Wait and Listen" 2.5ms (250 x 10us)
	////	gDly_Wait_and_Listen_Normal_Mode	= 90;	//Normal Mode delay for "Wait and Listen" 90 ms
	////}

	////// With Vpin low, OT is 60C.  At room temp(25C), expect device to be switching. //
	////if (tmeas > 0.1e-9)	
	////	OVT_ON = 1; // Switching //
	////else 
	////	OVT_ON = -99; // Not switching //

	////// Raise Vpin to change OT to 19C.  At room temp(25C), expect device to stop switching. //
	////ddd_7->ddd_run_pattern(High_pat_start,High_pat_stop);
	////wait.delay_10_us(20);
	////tmu_6->arm();						
	////wait.delay_10_us(20);					
	////tmeas = tmu_6->read(1e-3);
	////if (tmeas < 0.1e-9)
	////	OVT_OFF = 1; // Not switching //
	////else 
	////	OVT_OFF = -99; // Switching //

	////// Power down
	////D_dvi->set_voltage(D_ch, 0.0, VOLT_50_RANGE); // DVI_11_0	
	////VBPP_ramp_down(3, 0.0, 0.05);
	////BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
	////ddd_7->ddd_run_pattern(Low_pat_start,Low_pat_stop);
	////wait.delay_10_us(10);
	////VPIN_ovi->set_voltage(VPIN_ch, 0, RANGE_10_V); // OVI_1_1
	////VPIN_ovi->connect(VPIN_ch);								// OVI_1_1
 ////	tmu_6->open_relay(TMU_HIZ_DUT1); // Disconnect TMU HIZ from Drain 
	////Open_relay(K3);
	////Open_relay(K12); // DDD7_1	to Vpin(UV)	pin
	////FB_ovi->set_voltage(FB_ch, 0.0, RANGE_2_V);	// OVI_1_2
	////wait.delay_10_us(100);

	//////Datalog
	////PiDatalog(func, A_OVT_OFF, OVT_OFF, 30, POWER_UNIT);	
	////PiDatalog(func, A_OVT_ON, OVT_ON, 30, POWER_UNIT);

	////// Test Time End //
	////if (g_p_TstTime_Enble)
	////{
	////	g_endtime = g_mytimer.GetElapsedTime();
	////	OVT_TT = (g_endtime - g_begintime)*1e-6;
	////	PiDatalog(func, A_OVT_TT, OVT_TT, 30, POWER_MILLI);
	////}

	////// Check any test failed //
	////if (PiGetAnyFailStatus())		
	////{
	////	g_PartFailed = 1;
	////}
}
