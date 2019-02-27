//==============================================================================
// TonMin_Slope_P.cpp (User function)
// 
//    void TonMin_Slope_P_user_init(test_function& func)
//    void TonMin_Slope_P(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "TonMin_Slope_P.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void TonMin_Slope_P_user_init(test_function& func)
{
	TonMin_Slope_P_params *ours;
    ours = (TonMin_Slope_P_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void TonMin_Slope_P(test_function& func)
{
    // The two lines below must be the first two in the function.
    TonMin_Slope_P_params *ours;
    ours = (TonMin_Slope_P_params *)func.params;


	Pulse pulse;
	pulse.do_pulse();	

	Setup_Resources_for_I2C_P();
	PowerUp_I2C_P();

	DSM_I2C_Write('b', g_TM_CTRL, 0x02);	//0x40, 0x06 (enable analog mode + core_en)

	//3. write CFG<18:17>=10 on RegAddr 'ANA_CTRL_1' to stay in I2C after powerup.
	DSM_I2C_Write('w', g_ANA_CTRL_1, 0x2804);	//0x46, 0x0024 (I2C password + observe drain 
	DSM_I2C_Write('w', 0x44, 0x0402);			//choose min ON time and allow flux link thru TSPIN + disable receiver output
	DSM_I2C_Write('b', 0x4C, 0x01);				//release TS pin

	DSM_set_I2C_clock_freq(DSM_CONTEXT, 300);	//Disable DSM I2C


	//--------------------------------------------------------------------------------------------
	//Setup for TS to run 100kHz
		//Disconnect DSM from Primary after releasing VPIN or TS pins
		Open_relay(K1_DSM_TB);	
		Open_relay(K3_DSM_TB);	
		delay(1);

	TS_ovi3->set_voltage(TSovi3_ch, 0.0, VOLT_10_RANGE); // OVI_3_0
	wait.delay_10_us(10);

	Close_relay(K2_TS_TB); //TS disconnect from OVI_3_0_TS_RB
	Close_relay(K3_TS_IB); //DDD7_1 to Comparator LT1719 to COMP_OUT to TS
	delay(4);

	TS_ovi->set_voltage(TSovi1_ch, 1.0, VOLT_1_RANGE); // OVI_1_5 for Comparator LT1719 Vref input
	wait.delay_10_us(10);

	//Drain setup to connect to Ridder board with RL load and set Drain to 5V and ready for vMeas mode
	Close_relay(K2_D_RB);
	delay(4);
		D_dvi->set_current(D_ch, 100e-3, RANGE_300_MA); 
		delay(1);
		D_dvi->set_voltage(D_ch, 5.0, VOLT_20_RANGE); // DVI_11_0
		delay(1);

	//BPP zig zag (5V to 5.5V to 4.3V to 5.4V below OV threshold)
	BPP_dvi->set_voltage(BPP_ch, 5.5, VOLT_10_RANGE); // DVI_11_1
	delay(1);
	BPP_dvi->set_voltage(BPP_ch, 4.3, VOLT_10_RANGE); // DVI_11_1
	delay(1);
	BPP_dvi->set_voltage(BPP_ch, 5.4, VOLT_10_RANGE); // DVI_11_1
	delay(1);





	Load_30Khz_Pulses_TS();
	delay(1);
	Run_30Khz_Pulses_TS();	//DE want 50ns high duty cycle ideally.
	delay(1);
	//Observe 1.44us Ton_min at 30kHz TS request

	pulse.do_pulse();	
	Load_80Khz_Pulses_TS();
	delay(1);
	Run_80Khz_Pulses_TS();	//DE want 50ns high duty cycle ideally.
	delay(1);
	//Observe that the part react to faster freq request and adjust Ton accordingly
	//The first two Ton is due to transient behavior.  We want to ignore them.
	//We need to observe from the 4th pulse and expect all Ton stays the same after the 4th pulse.
	//Observe 5.64us Ton_min at 80kHz TS request.





	//////Drain signal shows sharper rising edge, hence use START/STOP POSITIVE/POSITIVE
	////tmu_6->close_relay(TMU_HIZ_DUT1);    // Connect TMU HIZ to Drain 
	////tmu_6->start_trigger_setup(-0.25, NEG_SLOPE, TMU_HIZ, TMU_IN_5V);	
	////tmu_6->stop_trigger_setup(-0.15,  NEG_SLOPE, TMU_HIZ, TMU_IN_5V);
	////tmu_6->start_holdoff(5,TRUE);
	////tmu_6->stop_holdoff(10,TRUE);
	////wait.delay_10_us(100);

	////tmu_6->arm();				
	////delay(1);					 
	////tmeas = tmu_6->read(1e-3);	
	////tmeas/=10;	
	////Fosc_pt_P = 1/tmeas;


	////tmu_6->open_relay(TMU_HIZ_DUT1);    //TMU HIZ1 to Drain 
	//////Open_relay(K2_D_RB);	//D  to RB_82uH_50ohm to K2_D to DVI-11-0
	//////Open_relay(K1_TMU_TB);	//D  to TMU_HIZ1
	delay(4);
	Stop_100Khz_Pulses_TS();
	Power_Down_I2C_P();
	Open_relay(K2_D_RB);
	Open_relay(K2_TS_TB); //TS to OVI_3_0_TS_RB								Connect
	Open_relay(K3_TS_IB); //DDD7_1 to Comparator LT1719 to COMP_OUT to TS	Disconnect

	//Datalog
	//PiDatalog(func, A_Fosc_pt_P, Fosc_pt_P, 14,	POWER_KILO);	

}
