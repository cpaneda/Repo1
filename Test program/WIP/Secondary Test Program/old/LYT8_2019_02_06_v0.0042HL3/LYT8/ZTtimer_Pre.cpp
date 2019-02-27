//==============================================================================
// ZTtimer_Pre.cpp (User function)
// 
//    void ZTtimer_Pre_user_init(test_function& func)
//    void ZTtimer_Pre(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "ZTtimer_Pre.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void ZTtimer_Pre_user_init(test_function& func)
{
	ZTtimer_Pre_params *ours;
    ours = (ZTtimer_Pre_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void ZTtimer_Pre(test_function& func)
{
    // The two lines below must be the first two in the function.
    ZTtimer_Pre_params *ours;
    ours = (ZTtimer_Pre_params *)func.params;

			// Increment function number //
	gFuncNum++;	

// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_ZTtimer_Pre, gFuncNum, 27, POWER_UNIT);

	// Skip Test if AbortTest set 
	if (AbortTest)
		return;

	// Skip trimming if g_p_Trim_Enable set //
	//if (g_p_Trim_Enable == 0)
//		return;

	//if (g_Fn_ZTtimer_Pre == 0 )  return;

	// Test Time Begin //
	if (g_p_TstTime_Enble)
		g_begintime = g_mytimer.GetElapsedTime();

	// Test variables

	int   i              = 0;
	int   WordArray[16]  = {0};
	uint16_t converted_dec1 = 0;
	uint16_t converted_dec2 = 0;

	// Test Names //
	//int fNum_ZTtimer_Pre = 0;
	float ZTtimer_pt_S      =   0;
	float ZTtimer_prg_S     =   0;
	float ZTtimer_Target_S  = 160e-6; 
	int   ZTtimer_TrCode_S  = 0;
	int   ZTtimer_BitCode_S = 0;
	int   EEtr57_ZTtimer0_S  = 0;
	int   EEtr58_ZTtimer1_S  = 0;
	int   EEtr59_ZTtimer2_S  = 0;
	int   EEtr60_ZTtimer3_S  = 0;
	
	float ZTtimer_Sim_S     = 0;
	float ZTtimer_Sim_Chg_S = 0;
	float ZTtimer_ExpChg    = 0;
	float ZTtimer_ExpValue  = 0;
	float ZTtimer_PrgChg    = 0;
	float ZTtimer_pst_S		= 0;
	float ZTtimer_Pre_TT    = 0;

Pulse pulse;

	//Trimcode & bit weights.
	float	ZTtimer_S_TrimWt[16]   = {0.0};
	float	ZTtimer_S_code[16]     = {0.0};
	float   smallest_diff_val = 999999.9;
	int     smallest_diff_idx = 0;
	float   temp_1            = 0;

	i = 0;
	ZTtimer_S_code[i] =  0; ZTtimer_S_code[i] =    0;    i++;     //0 (0 link trimmed)
	ZTtimer_S_code[i] = -1; ZTtimer_S_code[i] = -2.0;    i++;     //0 (1 link trimmed--> -2.0%)
	ZTtimer_S_code[i] = -2; ZTtimer_S_code[i] = -4.0;    i++;     //0 (1 link trimmed--> -4.0%)
	ZTtimer_S_code[i] = -3; ZTtimer_S_code[i] = -6.0;    i++;     //0 (2 link trimmed--> -6.0%)
	ZTtimer_S_code[i] = -4; ZTtimer_S_code[i] = -8.0;    i++;     //0 (1 link trimmed--> -8.0%)
	ZTtimer_S_code[i] = -5; ZTtimer_S_code[i] = -10.0;   i++;     //0 (2 link trimmed--> -10%)
	ZTtimer_S_code[i] = -6; ZTtimer_S_code[i] = -12.0;   i++;     //0 (2 link trimmed--> -12%)
	ZTtimer_S_code[i] = -7; ZTtimer_S_code[i] = -14.0;   i++;     //0 (3 link trimmed--> -14%)
	ZTtimer_S_code[i] =  8; ZTtimer_S_code[i] =  16.0;   i++;     //0 (1 link trimmed-->  16%)
	ZTtimer_S_code[i] =  9; ZTtimer_S_code[i] =  14.0;   i++;     //0 (2 link trimmed-->  14%)
	ZTtimer_S_code[i] = 10; ZTtimer_S_code[i] =  12.0;   i++;     //0 (2 link trimmed-->  12%)
	ZTtimer_S_code[i] = 11; ZTtimer_S_code[i] =  10.0;   i++;     //0 (3 link trimmed-->  10%)
	ZTtimer_S_code[i] = 12; ZTtimer_S_code[i] =  8.0;    i++;     //0 (2 link trimmed-->  8.0%)
	ZTtimer_S_code[i] = 13; ZTtimer_S_code[i] =  6.0;    i++;     //0 (3 link trimmed-->  6.0%)
	ZTtimer_S_code[i] = 14; ZTtimer_S_code[i] =  4.0;    i++;     //0 (3 link trimmed-->  4.0%)
	ZTtimer_S_code[i] = 15; ZTtimer_S_code[i] =  2.0;    i++;     //0 (4 link trimmed-->  2.0%)

	
	// Load WordArray[] with contents of g_Sec_TrimRegister[] array!  This includes trim bit from other tests & trim options 
    // This is important for proper trimming! //
	// E2 Trim register.
	WordArray[0]  = g_S_TrimRegister[48];
	WordArray[1]  = g_S_TrimRegister[49];
	WordArray[2]  = g_S_TrimRegister[50];
	WordArray[3]  = g_S_TrimRegister[51];
	WordArray[4]  = g_S_TrimRegister[52];
	WordArray[5]  = g_S_TrimRegister[53];
	WordArray[6]  = g_S_TrimRegister[54]; 
	WordArray[7]  = g_S_TrimRegister[55]; 
	WordArray[8]  = g_S_TrimRegister[56]; 
	WordArray[9]  = g_S_TrimRegister[57]; //EEtr57_ZTtime0_S
	WordArray[10] = g_S_TrimRegister[58]; //EEtr58_ZTtime1_S
	WordArray[11] = g_S_TrimRegister[59]; //EEtr59_ZTtime2_S
	WordArray[12] = g_S_TrimRegister[60]; //EEtr60_ZTtime3_S
	WordArray[13] = g_S_TrimRegister[61];
	WordArray[14] = g_S_TrimRegister[62];
	WordArray[15] = g_S_TrimRegister[63];

	// Open all relays //
	Initialize_Relays();

	//Loading 10Khz DDD pattern into memory.
	//Note:  DDD period is done at 1us, but it will be changed in the future to accomodate for both primary and 2ndary.
	//Load_10Khz_Pulses();
	Load_100Khz_Pulses();

	// Initialize Instruments //
	//Initialize_Instruments();   //No content for now.

	// Setup Instruments //
	// Primary
	D_dvi->set_voltage(D_ch, 0.0, VOLT_10_RANGE);                  // DVI_11_0
	D_dvi->set_current(D_ch, 300.0e-3, RANGE_300_MA);     
	UV_dvi->set_voltage(UV_ch, 0.0, RANGE_10_V);                   // DVI_21_1
	UV_dvi->set_current(UV_ch, 30e-3, RANGE_300_MA);	
	BPP_dvi->set_voltage(BPP_ch, 0.0, RANGE_10_V);				   // DVI_11_1
	BPP_dvi->set_current(BPP_ch, 200e-3, RANGE_300_MA);
	TS_ovi3->set_voltage(TSovi3_ch, 0.0, VOLT_5_RANGE);            // OVI_3_0
	TS_ovi3->set_current(TSovi3_ch, 30e-3, RANGE_30_MA);

	//Secondary.
	//HSG needs to connect thru buffer then.
	HSG_ovi->set_current(HSG_ch, 0.3e-3, RANGE_3_MA);
	HSG_ovi->set_voltage(HSG_ch, 0, VOLT_20_RANGE); 
	//B:  disconnect OVI and connect to 2nF to GND.
	B_ovi3->set_current(B_ch1, 300e-6, RANGE_300_UA);
	B_ovi3->set_voltage(B_ch1, 0.0, VOLT_10_RANGE);
	//FW = 0V/30UA==> Require to disconnect OVI from FW and clock pulses from DDD_7_7.
	FW_ovi3->set_current(FW_ch, 300e-6, RANGE_300_UA);
	FW_ovi3->set_voltage(FW_ch, 0.0, VOLT_5_RANGE); 
	//FB = 1.15V/30mA then sweep or binary search.
	FB_ovi3->set_current(FB_ch, 300e-6, RANGE_300_UA);
	FB_ovi3->set_voltage(FB_ch, 0.0, VOLT_10_RANGE); 
	//IS = 0V/200mA...
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE);				
	IS_dvi2k->set_current(IS_ch, 200e-3, RANGE_200_MA);
	//SDA will be at 3.3V/30mA for I2C
	SDA_ovi3->set_current(SDA_ch, 30e-3, RANGE_30_MA);	        
	SDA_ovi3->set_voltage(SDA_ch, 0.0, VOLT_10_RANGE); 
	//SCL will be at 3.3V/30mA for I2C
	SCL_ovi3->set_current(SCL_ch, 30e-3, RANGE_30_MA);				
	SCL_ovi3->set_voltage(SCL_ch, 0.0, VOLT_10_RANGE); 
	//BPS will be Hiz
	BPS_dvi->set_voltage(BPS_ch, 0.0, VOLT_5_RANGE); 
	BPS_dvi->set_current(BPS_ch, 0.0e-3, RANGE_300_MA);
	//HBP will be Hiz.
	HBP_dvi2k->set_current(HBP_ch, 20e-3, RANGE_200_MA);
	HBP_dvi2k->set_voltage(HBP_ch, 0.0, VOLT_20_RANGE);
	//VR will be set at 15V.  Test plan requires at 20V.
	VR_dvi->set_current(VR_ch, 300e-3, RANGE_300_MA);	
	VR_dvi->set_voltage(VR_ch, 0.0, VOLT_50_RANGE); 
	wait.delay_10_us(100);

	//Secondary I2C to ready Secondary Die ID.
	//Disconnect HBP & BPs and use VR to powerup 2ndary.
	HBP_dvi2k->open_relay(CONN_FORCE0);
	BPS_dvi->open_relay(CONN_FORCE0);

	Close_relay(K2_HSG_SPI_TB);      //Disconnect OVI_1_0 from HSG.
	Open_relay(K1_HSG_SPI_RB);       //Keep Kelvin connection.  OVI_1_0 is disconnected from HSG anyway.
	Close_relay(K5_HSG_SPI_TB);      //Connect HSG to buffer  ==> The buffer AD817 is too much for HSG/B.  Will need hardware fix.
	Close_relay(K3_B_SPI_TB);		 //Connect 2nF to B
	Open_relay(K5_TMU_TB);           //Keep TMU_HIZ_3 open from FW.
	Close_relay(K7_DDD_TB);          //Connect DDD_7_7 to FW.
	Close_relay(K1_FW_SPI_TB);       //Disconnect OVI from FW.
	
	//Disonnect Pullup R from TS and UV pins
	Open_relay(K1_TS_RB);
	Open_relay(K1_UV_RB);	
	//Connect Pullup R to SCL & SDA
	Close_relay(K1_SDA_SPI_TB);
	Close_relay(K1_SCL_SPI_TB);
	//Disconnect DSM CLK & Data from primary pins: TS & UV
	//Connect DSM CLK & Data to secondary:         SCL & SDA
	Open_relay(K1_DSM_TB);
	Open_relay(K3_DSM_TB);
	Close_relay(K2_DSM_TB);
	Close_relay(K4_DSM_TB);
	wait.delay_10_us(250);

	FB_ovi3->set_current(FB_ch, 30e-3, RANGE_30_MA);
	FB_ovi3->set_voltage(FB_ch, 1.25, VOLT_5_RANGE); 	
	wait.delay_10_us(10);
	///Power up VR to 15V to wake up 2ndary.
	// If 15V doesn't work, will set to 20V.
	VR_dvi->set_voltage(VR_ch, 20, VOLT_50_RANGE); 
	//HBP_dvi2k->set_voltage(HBP_ch, g_HBP_Pre_S, VOLT_20_RANGE);
	wait.delay_10_us(500);

	//SDA,SCL = 3.3V via pullup resistor. Ready for I2C.
	SDA_ovi3->set_voltage(SDA_ch, 3.3, VOLT_10_RANGE); 
	SCL_ovi3->set_voltage(SCL_ch, 3.3, VOLT_10_RANGE); 
	wait.delay_10_us(200);

	//Setup IS for mesuring current.
	//IS_dvi2k->set_meas_mode(IS_ch, DVI_MEASURE_CURRENT);
	IS_dvi2k->set_current(IS_ch, 200e-3, RANGE_200_MA);
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE);
	wait.delay_10_us(100);

	//-----------------------------------------------------------------------------------
	//I2C command and sweep FB here.
	//------------------------------------------------------------------------------------
	
	//Sometimes, DSM I2C can't be written correctly the first time.
	//Change the DSM timeout to 1ms since the default timeout is approximately 35ms.
	//g_Debug = 1;
	DSM_set_I2C_timeout(0, 1);
	DSM_set_I2C_clock_freq(DSM_CONTEXT, 300);

	//Enter TM
	Analog_TM_Enable_Secondary();
	//For TEST only..  Manually raise vFB above 2.5V or 3V here to observe HBP will go low and then lower to 1.25V for HSG to go High
	//Below to to make sure the FB controlling HBP is working properly before Disabling it.
	if(0)
	{
		FB_ovi3->set_voltage(FB_ch, 2.00, VOLT_5_RANGE); // DVI_11_0
		delay(1);
		FB_ovi3->set_voltage(FB_ch, 2.25, VOLT_5_RANGE); // DVI_11_0
		delay(1);
		FB_ovi3->set_voltage(FB_ch, 2.50, VOLT_5_RANGE); // DVI_11_0
		delay(1);
		FB_ovi3->set_voltage(FB_ch, 2.75, VOLT_5_RANGE); // DVI_11_0
		delay(1);
		FB_ovi3->set_voltage(FB_ch, 3.00, VOLT_5_RANGE); // DVI_11_0	//1uF on HBP.  The drop is slow if it's only 3ms.  Manual observe drop to ~1.7V
		delay(3);              
		FB_ovi3->set_voltage(FB_ch, 1.25, VOLT_5_RANGE); // DVI_11_0
		delay(1);
	}

//////////pulse.do_pulse();

	//ZTMC_Drivers_en and ZTMC_Dsbl_FBshrt  (The FBshrt -> FB to HBP short fault protection function.)
	//											  (This Test Mode disable 
	//0x00 0x62 write 0x88 0x00
	DSM_I2C_Write('w', g_S_TEST_CTRL2, 0x0088);

	//ZTMC_ana_EN, ZTMT_Sig_EN and Core_en
	//0x00 0x40 write 0x07 0x00
	DSM_I2C_Write('w', g_S_TM_CTRL, 0x0007);

	//Open Drain won't work.   Don't try this method.
	//0x00 0x60 write 0x00 0xC0  ==> Open Drain on HSG & B.
	//DSM_I2C_Write('w', g_S_TEST_CTRL1, 0xC000);

	//Loading previous trimming before performing the test.

	//Program Trim Register with new calculated bit combination.
	Program_Trim_Register(g_S_TrimRegister);


	if(0)
	{
		//1p35us Timer ==> Works okay.  But might not the trim parameter.
		//0x00 0x46 write 0x00 0x08
		DSM_I2C_Write('w', g_S_ANA_CTRL_1, 0x0800);
		Run_100Khz_Pulses();
	}

	if(1)
	{
		//DX_Starttimer. Expect ~= 3us.  Might be the trim parameter.
		//0x00 0x46 write 0x00 0x78
		DSM_I2C_Write('w', g_S_ANA_CTRL_1, 0x7800);
		Run_100Khz_Pulses();
	}

	if(0)
	{
		//DX Control S==> Currently having problem.  HSG won't goes low. Need to check with design onthe pin conditions.
		//0x00 0x46 write 0x00 0x00
		DSM_I2C_Write('w', g_S_ANA_CTRL_1, 0x0000);
		Run_10Khz_Pulses();
	}



	
	

	wait.delay_10_us(20);

//pulse.do_pulse();

////////
////////	wait.delay_10_us(100);
////////
////////	IRSET_pt_S = -1*(IS_dvi2k->measure_average(25));
////////
////////
////////	// IRSET_S_Code //
////////	// Find which trim code will make IRSET_Pre closest to target //
////////	smallest_diff_val = 999999.9;
////////	smallest_diff_idx = 0;
////////	for (i=0; i<16; i++)
////////	{
////////		temp_1 = (IRSET_pt_S * (1 + (IRSET_S_TrimWt[i]/100)) -  IRSET_Target_S);
////////		if (temp_1 < 0)	// Get rid of negatives //
////////			temp_1 *= -1.0;
////////		if (temp_1 < smallest_diff_val)
////////		{
////////			smallest_diff_val = temp_1;
////////			smallest_diff_idx = i;
////////		}
////////	}
////////
////////
////////	//Manual forcing:
////////	//smallest_diff_idx = 15;
////////
////////	IRSET_TrCode_S = smallest_diff_idx;
////////	IRSET_TrCode_S = IRSET_S_code[smallest_diff_idx];
////////	IRSET_ExpChg   = IRSET_S_TrimWt[smallest_diff_idx];
////////
////////	TrimCode_To_TrimBit(IRSET_TrCode_S, "IRSET_S", 's');
////////
////////	//Update WordArray.
////////	WordArray[12]        = g_S_TrimRegisterTemp[76]; //EEtr76_ZTLnt0_S
////////	WordArray[13]        = g_S_TrimRegisterTemp[77]; //EEtr77_ZTLnt1_S
////////	WordArray[14]        = g_S_TrimRegisterTemp[78]; //EEtr78_ZTLnt2_S
////////	WordArray[15]        = g_S_TrimRegisterTemp[79]; //EEtr79_ZTLnt3_S
////////
////////	//Update secondary trim register array for programming later.
////////	g_S_TrimRegister[76] = g_S_TrimRegisterTemp[76]; //EEtr76_ZTLnt0_S
////////	g_S_TrimRegister[77] = g_S_TrimRegisterTemp[77]; //EEtr77_ZTLnt1_S
////////	g_S_TrimRegister[78] = g_S_TrimRegisterTemp[78]; //EEtr78_ZTLnt2_S
////////	g_S_TrimRegister[79] = g_S_TrimRegisterTemp[79]; //EEtr79_ZTLnt3_S
////////
////////	//Convert from binary to decimal.
////////	converted_dec1 = Convert_BIN_2_Dec(WordArray);
////////	converted_dec2 = Convert_BIN_2_Dec(WordArray);
////////
////////
////////	//Program Trim Register with new calculated bit combination.
////////	Program_Trim_Register(g_S_TrimRegister);
////////
////////	int TrimBank[5];
////////
////////	Read_Trim_Register(TrimBank);
////////
////////
////////	wait.delay_10_us(100);
////////
////////	IRSET_prg_S = -1*(IS_dvi2k->measure_average(25));
////////
////////	if(IRSET_pt_S != 0)
////////	{
////////		IRSET_PrgChg = 100*(IRSET_prg_S - IRSET_pt_S) / IRSET_pt_S;
////////	}
	//---------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------
	//Powerdown
	//-------------------------------------------------------------------------------
	DSM_set_I2C_clock_freq(DSM_CONTEXT, 300);

	ddd_7->ddd_stop_pattern(); //Stop the 10Khz Pattern.

	//Reset DDD low level to 0V.
	ddd_7->ddd_set_lo_level(0.0);
	ddd_7->ddd_set_hi_level(g_DDD_High);	
	wait.delay_10_us(10);


	HSG_ovi->set_voltage(HSG_ch, 0, VOLT_20_RANGE); 
	wait.delay_10_us(50);
	VR_dvi->set_voltage(VR_ch, 5, VOLT_50_RANGE); 
	wait.delay_10_us(200);
	FB_ovi3->set_voltage(FB_ch, 0.0, VOLT_10_RANGE); 
	wait.delay_10_us(10);
	SDA_ovi3->set_voltage(SDA_ch, 0.0, VOLT_10_RANGE); 
	SCL_ovi3->set_voltage(SCL_ch, 0.0, VOLT_10_RANGE); 
	wait.delay_10_us(10);
	SDA_ovi3->set_current(SDA_ch, 0.01e-3, RANGE_30_MA);	        
	SCL_ovi3->set_current(SCL_ch, 0.01e-3, RANGE_30_MA);				
	wait.delay_10_us(10);

	VR_dvi->set_voltage(VR_ch, 0.0, VOLT_50_RANGE); 
	wait.delay_10_us(500);

	HBP_dvi2k->close_relay(CONN_FORCE0);
	BPS_dvi->close_relay(CONN_FORCE0);
	Open_relay(K1_SDA_SPI_TB);       //Disconnect pullup R from SDA.
	Open_relay(K1_SCL_SPI_TB);       //Disconnect pullup R from SCL
	Open_relay(K2_DSM_TB);           //Disconnect DSM SDA from DUT SDA
	Open_relay(K4_DSM_TB);           //Disconnect DSM SCL from DUT SCL
	Open_relay(K2_HSG_SPI_TB);		 //Reconnect OVI_1_0 to HSG
	Open_relay(K3_B_SPI_TB);		 //Disconnect 2nF from B
	Open_relay(K1_HSG_SPI_RB);		 //Disconnect pullup R from HSG.
	Open_relay(K1_FB_SPI_TB);		 //Reconnect OVI to FB
	Open_relay(K5_TMU_TB);           //Disconnect TMU_HIZ_3 to FW.
	Open_relay(K7_DDD_TB);           //Disconnect DDD_7_7 to FW.
	Open_relay(K1_FW_SPI_TB);        //Reconnect OVI to FW.
	Open_relay(K5_HSG_SPI_TB);       //Disconnect HSG from buffer  
	wait.delay_10_us(250);
////////
////////
////////	PiDatalog(func, A_IRSET_pt_S, IRSET_pt_S,              26, POWER_MICRO);
////////	PiDatalog(func, A_IRSET_target_S,     IRSET_Target_S,          26, POWER_MICRO);
////////	PiDatalog(func, A_IRSET_TrCode_S,     IRSET_TrCode_S,          26, POWER_UNIT);
////////	//PiDatalog(func, A_IRSET_BitCode_S,  IRSET_BitCode_S,         26, POWER_UNIT);
////////	PiDatalog(func, A_IRSET_ExpChg_S,     IRSET_ExpChg,            26, POWER_UNIT);
////////	PiDatalog(func, A_Eetr76_ZTLnt0_S,    g_S_TrimRegister[76],    26, POWER_UNIT);
////////	PiDatalog(func, A_Eetr77_ZTLnt1_S,    g_S_TrimRegister[77],    26, POWER_UNIT);
////////	PiDatalog(func, A_Eetr78_ZTLnt2_S,    g_S_TrimRegister[78],    26, POWER_UNIT);
////////	PiDatalog(func, A_Eetr79_ZTLnt3_S,    g_S_TrimRegister[79],    26, POWER_UNIT);
////////	PiDatalog(func, A_Bin2Dec1_S,         converted_dec1,          26, POWER_UNIT);
////////	PiDatalog(func, A_IRSET_prg_S,        IRSET_prg_S,             26, POWER_MICRO);
////////	PiDatalog(func, A_IRSET_prgchg_S,     IRSET_PrgChg,            26, POWER_UNIT);


}
