//==============================================================================
// OSC_Pt.cpp (User function)
// 
//    void OSC_Pt_user_init(test_function& func)
//    void OSC_Pt(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "OSC_Pt.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void OSC_Pt_user_init(test_function& func)
{
	OSC_Pt_params *ours;
    ours = (OSC_Pt_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void OSC_Pt(test_function& func)
{
    // The two lines below must be the first two in the function.
    OSC_Pt_params *ours;
    ours = (OSC_Pt_params *)func.params;

	// Increment function number //
	gFuncNum++;

	////// Datalog gFuncNum variable //
	////if(gDisplay_FuncNum)
	////	PiDatalog(func, A_fNum_OSC_Pt, gFuncNum, 14, POWER_UNIT);

	////// Skip Test if AbortTest set //
	////if (AbortTest)
	////	return;

	////// Skip trimming if g_p_Trim_Enable set //
	////if (g_p_Trim_Enable == 0)
	////	return;

	////if (g_Fn_OSC_Pt == 0 )  return;

	////// Test Time Begin //
	//// if (g_p_TstTime_Enble)
	//// 	g_begintime = g_mytimer.GetElapsedTime();

	////// Test Names //
	//////float OSC_Pt_S = 0;
	////float OSC_Target_S = 375000;
	////int OSC_TrCode_S = 0;
	////int OSC_BitCode_S = 0;
	////int EEtr_OSC0_S = 0;
	////int EEtr_OSC1_S = 0;
	////int EEtr_OSC2_S = 0;
	////int EEtr_OSC3_S = 0;
	////float OSC_Sim = 0;
	////float OSC_Sim_Chg = 0;
	////float OSC_Pt_TT = 0;

	////// Declare Variables //
	////float Period = 0;
	////int NObin[1] = {0}; // Place holder //
	////int NOhex = 0; // Place holder //
	////int WordArray[16] = {0};
	////int TempArray[30] = {0};
	////float Frequency = 0;
	////int UpperLimit = 0;
	////int LowerLimit = 0;
	////Pulse pulse;
	////float Delta = 0;
	////float MinDelta = 0;
	////float BestFreq = 0;
	////int Best_TrCode = 0;
	////int Best_BitCode = 0;

	////// Open all relays //
	////Initialize_Relays();

	////// Initialize Instruments //
	////Initialize_Instruments();

	////// Drain //
	////D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
	////D_dvi->set_current(D_ch, 30e-3, RANGE_30_MA); // DVI_11_0 //

	////// BPP //
	////BPP_ovi->set_voltage(BPP_ch, 0.0, RANGE_10_V); // OVI_1_0 //
	////BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //

	////// V pin //
	////VPIN_ovi->set_voltage(VPIN_ch, 0.0, RANGE_10_V); // OVI_1_1 //
	////VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //

	////// FW //
	////Close_relay(K18);
	////FW_dvi->set_voltage(FW_ch, 1, VOLT_10_RANGE); // DVI_11_1 //
	////FW_dvi->set_current(FW_ch, 30e-3, RANGE_30_MA); // DVI_11_1 //

	////// SR //
	////Mux20_Close_relay(K42); // TMU_HIZ_4 to SR pin //
 ////   tmu_6->close_relay(TMU_HIZ_DUT4);
	////tmu_6->start_trigger_setup(1.5, POS_SLOPE, TMU_HIZ, TMU_IN_10V);
	////tmu_6->stop_trigger_setup(1.5, POS_SLOPE, TMU_HIZ, TMU_IN_10V);
	////SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_2_RANGE); // DVI_13_1, dvi2k //
	////SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //

	////// BPS //
	////BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
	////BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //

	////// IS //
	////IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_2_RANGE); // DVI_13_0, dvi2k //
	////IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //

	////// Vout //
	////VO_dvi->set_voltage(VO_ch, 4.5, VOLT_10_RANGE); // DVI_9_0 //
	////VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //

	////// COMP //
	////FB_ovi->disconnect(2);

	////// VBD //
	////VBD_dvi->set_voltage(VBD_ch, 0.0, VOLT_5_RANGE); // DVI_21_0 //
	////VBD_dvi->set_current(VBD_ch, 30e-6, RANGE_30_UA); // DVI_21_0, prevent glitch //
	////wait.delay_10_us(25); // Prevent glitch //
	////VBD_dvi->set_current(VBD_ch, 0.1e-9, RANGE_30_UA); // DVI_21_0, Float //

	////// uVCC //
	////uVCC_ovi->set_voltage(uVCC_ch, 0.0, RANGE_5_V); // OVI_3_2 //
	////uVCC_ovi->set_current(uVCC_ch, 0.1e-9, RANGE_30_UA); // OVI_3_2, Float //

	////// DDD level //
	////g_DDD_Low = 0.0; // Save current value //
	////g_DDD_High = 3.3; // Save current value //
	////wait.delay_10_us(g_DDDwait);
	////ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	////ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	////wait.delay_10_us(g_DDDwait);

	////// SDA //
	////Mux20_Close_relay(K64);  // SDA pullup to 3.3V through 1.5kohm resistor. //
	////ovi_3->set_voltage(OVI_CHANNEL_7, g_I2C_Pullup, RANGE_5_V); // OVI_3_7 //
	////ovi_3->set_current(OVI_CHANNEL_7, 30e-3, RANGE_30_MA); // OVI_3_7 //
	////Mux20_Close_relay(K37);  // Disconnect ovi from SDA. //
	////Mux20_Close_relay(K38);  // Connect SDA and SCL to DDD. //
	////Mux20_Close_relay(K40);  // Connect SDA and SCL to DDD. //

	////// SCL //
	////Mux20_Close_relay(K39);  // Disconnect ovi from SCL. //
	////ddd_7->ddd_run_pattern(g_SDA_SCL_Low_start, g_SDA_SCL_Low_stop);  // Start with SDA and SCL low with DDD. //

	////// Set DDD for I2C. //
	////ddd_7->ddd_set_clock_period(g_Dclk_I2C);
	////ddd_7->ddd_set_voltage_ref(g_Vref_I2C);
	////	
	////// Wait for relays //
	////wait.delay_10_us(200); 

	////// Powerup //
	////BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
	////wait.delay_10_us(100); // Must wait long enough for uVCC to come up before sending I2C commands. //

	////// I2C into test mode. //  
	////Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
	////Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //

	////Write_Word(g_TM_ANA, 0x0134, NObin, HEX); // TM_EN_SR_driver //
	////
	//////Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //

	////// Always load g_ShadowRegister[] array to shadow register of DUT after powerup if EEPROM has not yet been written. //
	////LoadShadowRegister();

	////// Float SR dvi //
	////SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k, Float. //

	////// Output 375kHz OSC clock to SR pin. //
	////Write_Word(g_TM_SEL, 0x0001, NObin, HEX); // Write the I2C command to connect the 375KHZ signal to SR pin. //

	////// OSC_Pt_S //
	////tmu_6->arm(); 
	////wait.delay_10_us(10);
	////Period = tmu_6->read();
	////g_OSC_Pt_S = 1/Period;

	////// Load WordArray[] with contents of g_ShadowRegister[] array!  Must not overwrite shadow register!  This is important for proper trimming! //
	////WordArray[0] = g_ShadowRegister[0];
	////WordArray[1] = g_ShadowRegister[1];
	////WordArray[2] = g_ShadowRegister[2];
	////WordArray[3] = g_ShadowRegister[3];
	////WordArray[4] = g_ShadowRegister[4];
	////WordArray[5] = g_ShadowRegister[5];
	////WordArray[6] = g_ShadowRegister[6];
	////WordArray[7] = g_ShadowRegister[7];
	////WordArray[8] = g_ShadowRegister[8];  // EEtr_OSC0_S //
	////WordArray[9] = g_ShadowRegister[9];  // EEtr_OSC1_S //
	////WordArray[10] = g_ShadowRegister[10];  // EEtr_OSC2_S //
	////WordArray[11] = g_ShadowRegister[11];  // EEtr_OSC3_S //
	////WordArray[12] = g_ShadowRegister[12];
	////WordArray[13] = g_ShadowRegister[13];
	////WordArray[14] = g_ShadowRegister[14];
	////WordArray[15] = g_ShadowRegister[15];

	////// Find trim code closest to target; binary search. //
	////UpperLimit = 9;
	////LowerLimit = -8;
	////MinDelta = 99999;
	////while ( (UpperLimit - LowerLimit) > 1)
	////{
	////	OSC_BitCode_S = (UpperLimit + LowerLimit) / 2;
	////	
	////	// Convert BitCode to TrCode. Mapping between bit code and trim code. //
	////	if(OSC_BitCode_S == -7) OSC_TrCode_S = 7;
	////	if(OSC_BitCode_S == -6) OSC_TrCode_S = 6;
	////	if(OSC_BitCode_S == -5) OSC_TrCode_S = 5;
	////	if(OSC_BitCode_S == -4) OSC_TrCode_S = 4;
	////	if(OSC_BitCode_S == -3) OSC_TrCode_S = 3;
	////	if(OSC_BitCode_S == -2) OSC_TrCode_S = 2;
	////	if(OSC_BitCode_S == -1) OSC_TrCode_S = 1;
	////	if(OSC_BitCode_S == 0) OSC_TrCode_S = 0;
	////	if(OSC_BitCode_S == 1) OSC_TrCode_S = 15;
	////	if(OSC_BitCode_S == 2) OSC_TrCode_S = 14;
	////	if(OSC_BitCode_S == 3) OSC_TrCode_S = 13;
	////	if(OSC_BitCode_S == 4) OSC_TrCode_S = 12;
	////	if(OSC_BitCode_S == 5) OSC_TrCode_S = 11;
	////	if(OSC_BitCode_S == 6) OSC_TrCode_S = 10;
	////	if(OSC_BitCode_S == 7) OSC_TrCode_S = 9;
	////	if(OSC_BitCode_S == 8) OSC_TrCode_S = 8;

	////	
	////	// Convert decimal number 'OSC_TrCode_S' into binary number and store in TempArray[]. //		
	////	Convert_Decimal_To_Binary(OSC_TrCode_S, TempArray); 

	////	// Load TempArray[] to WordArray[] at correct bit locations. //
	////	WordArray[8] = TempArray[0];
	////	WordArray[9] = TempArray[1]; 
	////	WordArray[10] = TempArray[2]; 
	////	WordArray[11] = TempArray[3]; 

	////	// Load new trim code to shadow register. //
	////	Write_Word(g_SREG0, NOhex, WordArray, BIN); // Load trim code to shadow register. //
	////	// Frequency should now have changed based on the new trim code. //

	////	// Measure frequency with updated trim code. //
	////	tmu_6->arm(); 
	////	wait.delay_10_us(10);
	////	Period = tmu_6->read();
	////	Frequency = 1/Period;
	////	Delta = Frequency - OSC_Target_S;
	////	if (Delta < 0) // Remove negative //
	////		Delta *= -1;
	////	if (Delta < MinDelta)
	////	{
	////		MinDelta = Delta;
	////		BestFreq = Frequency;
	////		Best_TrCode = OSC_TrCode_S;
	////		Best_BitCode = OSC_BitCode_S;
	////	}
	////	if (Frequency < OSC_Target_S) // Below target //
	////		LowerLimit = OSC_BitCode_S;
	////	else // Above target //
	////		UpperLimit = OSC_BitCode_S;		
	////}
	////OSC_Sim = BestFreq;
	////OSC_TrCode_S = Best_TrCode;
	////OSC_BitCode_S = Best_BitCode;
	////OSC_Sim_Chg = ((OSC_Sim - g_OSC_Pt_S) / g_OSC_Pt_S)*100; // In percent //	

	////// Load the shadow register with the final trim code OSC_TrCode_S.  Must not overwrite any of the other shadow register bits! //	
	////Convert_Decimal_To_Binary(OSC_TrCode_S, TempArray); // Convert decimal number 'OSC_TrCode_S' into binary number and store in TempArray[]. // 

	////// Load TempArray[] to WordArray[] at correct bit locations. //
	////WordArray[8] = TempArray[0];
	////WordArray[9] = TempArray[1]; 
	////WordArray[10] = TempArray[2]; 
	////WordArray[11] = TempArray[3]; 

	////// Load final trim code to shadow register. //
	//////Write_Word(g_SREG0, NOhex, WordArray, BIN); // Load trim code to shadow register. //
	////// Frequency should now have changed based on the new trim code. //

	////// Save the new values to the g_ShadowRegister[] array. //
	////g_ShadowRegister[8] = WordArray[8];
	////g_ShadowRegister[9] = WordArray[9];
	////g_ShadowRegister[10] = WordArray[10];
	////g_ShadowRegister[11] = WordArray[11];
	////
	////// Load individual bits for datalogging //
	////EEtr_OSC0_S = WordArray[8];
	////EEtr_OSC1_S = WordArray[9];
	////EEtr_OSC2_S = WordArray[10];
	////EEtr_OSC3_S =  WordArray[11];

	////// Powerdown //
	////Mux20_Open_relay(K64);
	////ovi_3->set_voltage(OVI_CHANNEL_7, 0, RANGE_5_V); // OVI_3_7 //
	////Mux20_Open_relay(K37);
	////Mux20_Open_relay(K38);
	////Mux20_Open_relay(K40);
	////Mux20_Open_relay(K39);
	////Mux20_Open_relay(K42);
	////tmu_6->open_relay(TMU_HIZ_DUT4);
	////VO_dvi->set_voltage(VO_ch, 0, VOLT_10_RANGE); // DVI_9_0 //
	////uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
	////uVCCrampDown(1, 0, 0.1);
	////SR_dvi2k->set_voltage(SR_ch, 5, VOLT_10_RANGE); // DVI_13_1, dvi2k, prevent undershoot //
	////SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
	////wait.delay_10_us(45); // prevent SR undershoot //
	////FB_ovi->connect(2);
	////Open_relay(K18);
	////FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
	////BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
	////wait.delay_10_us(5);
	////SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_10_RANGE); // DVI_13_1, dvi2k //
	////VBD_dvi->set_voltage(VBD_ch, 2, VOLT_5_RANGE); // DVI_21_0, prevent undershoot //
	////VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
	////wait.delay_10_us(20);
	////VBD_dvi->set_voltage(VBD_ch, 0, VOLT_5_RANGE); // DVI_21_0 //
	////ddd_7->ddd_set_clock_period(Dclk_period);
	////ddd_7->ddd_set_voltage_ref(DDD_Vref);

	////// DDD level //
	////g_DDD_Low = 0.0; // Save current value //
	////g_DDD_High = 4.0; // Save current value //
	////wait.delay_10_us(g_DDDwait);
	////ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
	////ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
	////wait.delay_10_us(200); // Wait for relays //

	////// Datalog //
	////PiDatalog(func, A_OSC_Pt_S, g_OSC_Pt_S, 14, POWER_KILO);
	////PiDatalog(func, A_OSC_Target_S, OSC_Target_S, 14, POWER_KILO);
	////PiDatalog(func, A_OSC_TrCode_S, OSC_TrCode_S, 14, POWER_UNIT);
	////PiDatalog(func, A_OSC_BitCode_S, OSC_BitCode_S, 14, POWER_UNIT);
	////PiDatalog(func, A_EEtr_OSC0_S, EEtr_OSC0_S, 14, POWER_UNIT);
	////PiDatalog(func, A_EEtr_OSC1_S, EEtr_OSC1_S, 14, POWER_UNIT);
	////PiDatalog(func, A_EEtr_OSC2_S, EEtr_OSC2_S, 14, POWER_UNIT);
	////PiDatalog(func, A_EEtr_OSC3_S, EEtr_OSC3_S, 14, POWER_UNIT);
	////PiDatalog(func, A_OSC_Sim, OSC_Sim, 14, POWER_KILO);
	////PiDatalog(func, A_OSC_Sim_Chg, OSC_Sim_Chg, 14, POWER_UNIT);

	////// Test Time End //
	////if (g_p_TstTime_Enble)
	////{
	////	g_endtime = g_mytimer.GetElapsedTime();
	////	OSC_Pt_TT = (g_endtime - g_begintime)*1e-6;
	////	PiDatalog(func, A_OSC_Pt_TT, OSC_Pt_TT, 14, POWER_MILLI);
	////}

	////// Check any test failed //
	////if (PiGetAnyFailStatus())		
	////{
	////	g_PartFailed = 1;
	///}
}