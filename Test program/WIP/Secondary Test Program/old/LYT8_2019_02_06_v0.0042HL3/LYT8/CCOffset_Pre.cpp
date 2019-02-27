//==============================================================================
// CCOffset_Pre.cpp (User function)
// 
//    void CCOffset_Pre_user_init(test_function& func)
//    void CCOffset_Pre(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "CCOffset_Pre.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void CCOffset_Pre_user_init(test_function& func)
{
	CCOffset_Pre_params *ours;
    ours = (CCOffset_Pre_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void CCOffset_Pre(test_function& func)
{
    // The two lines below must be the first two in the function.
    CCOffset_Pre_params *ours;
    ours = (CCOffset_Pre_params *)func.params;

				// Increment function number //
	gFuncNum++;	

// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_CCOffset_Pre, gFuncNum, 27, POWER_UNIT);

	// Skip Test if AbortTest set 
	if (AbortTest)
		return;

	// Skip trimming if g_p_Trim_Enable set //
	//if (g_p_Trim_Enable == 0)
//		return;

	//if (g_Fn_CCOffset_Pre == 0 )  return;

	// Test Time Begin //
	if (g_p_TstTime_Enble)
		g_begintime = g_mytimer.GetElapsedTime();

	// Test variables

	int   i              = 0;
	int   WordArray[16]  = {0};
	uint16_t converted_dec1 = 0;
	uint16_t converted_dec2 = 0;

	// Test Names //
	float CCOffset_pt_S    =0;
	float CCOffset_prg_S   = 0;
	float CCOffsetTarget_S = 1.2; 
	int CCOffset_TrCode_S  = 0;
	int CCOffset_BitCode_S = 0;
	int EEtr32_Zoffset0_S  = 0;
	int EEtr33_Zoffset1_S  = 0;
	int EEtr34_Zoffset2_S  = 0;
	
	
	float CCOffset_Sim_S     = 0;
	float CCOffset_Sim_Chg_S = 0;
	float CCOffset_ExpChg    = 0;
	float CCOffset_ExpValue  = 0;
	float CCOffset_PrgChg    = 0;
	float CCOffset_pst_S     = 0;
	float CCOffset_Pre_TT    = 0;

Pulse pulse;

	//Trimcode & bit weights.
	float	CCOffset_S_TrimWt[4]   = {0.0};
	float	CCOffset_S_code[4]     = {0.0};
	float   smallest_diff_val = 999999.9;
	int     smallest_diff_idx = 0;
	float   temp_1            = 0;

	
	i = 0;
	CCOffset_S_code[i] =  0; CCOffset_S_TrimWt[i] =   0;        i++;     //0 (0 link trimmed)
	CCOffset_S_code[i] =  1; CCOffset_S_TrimWt[i] =  -0.006;    i++;     //0 (1 link trimmed--> -6mV, VIN-)
	CCOffset_S_code[i] =  2; CCOffset_S_TrimWt[i] =  -0.012;    i++;     //0 (1 link trimmed--> -12mV,VIN-)
	CCOffset_S_code[i] =  3; CCOffset_S_TrimWt[i] =  +0.018;    i++;     //0 (2 link trimmed--> +18mV,VIN+)
	

	
	// Load WordArray[] with contents of g_Sec_TrimRegister[] array!  This includes trim bit from other tests & trim options 
    // This is important for proper trimming! //
	// E4 Trim register.
	WordArray[0]  = g_S_TrimRegister[32]; //EEtr32_Zoffset0_S
	WordArray[1]  = g_S_TrimRegister[33]; //EEtr33_Zoffset1_S
	WordArray[2]  = g_S_TrimRegister[34]; //EEtr34_Zoffset2_S
	WordArray[3]  = g_S_TrimRegister[35]; 
	WordArray[4]  = g_S_TrimRegister[36];
	WordArray[5]  = g_S_TrimRegister[37];
	WordArray[6]  = g_S_TrimRegister[38]; 
	WordArray[7]  = g_S_TrimRegister[39]; 
	WordArray[8]  = g_S_TrimRegister[40]; 
	WordArray[9]  = g_S_TrimRegister[41]; 
	WordArray[10] = g_S_TrimRegister[42];
	WordArray[11] = g_S_TrimRegister[43];
	WordArray[12] = g_S_TrimRegister[44];
	WordArray[13] = g_S_TrimRegister[45];
	WordArray[14] = g_S_TrimRegister[46];
	WordArray[15] = g_S_TrimRegister[47];

	// Open all relays //
	Initialize_Relays();

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
	//HSG: disconnect OVI and connect to 2nF to GND
	HSG_ovi->set_current(HSG_ch, 300e-6, RANGE_300_UA);
	HSG_ovi->set_voltage(HSG_ch, 0, VOLT_20_RANGE); 
	//B:  disconnect OVI and connect to 2nF to GND.
	B_ovi3->set_current(B_ch1, 300e-6, RANGE_300_UA);
	B_ovi3->set_voltage(B_ch1, 0.0, VOLT_10_RANGE);
	//FW = 0V/30mA
	FW_ovi3->set_current(FW_ch, 30e-3, RANGE_30_MA);
	FW_ovi3->set_voltage(FW_ch, 0.0, VOLT_5_RANGE); 
	//FB = Hiz.
	FB_ovi3->set_current(FB_ch, 300e-6, RANGE_300_UA);
	FB_ovi3->set_voltage(FB_ch, 0.0, VOLT_10_RANGE); 
	//IS = 100mV/200mA
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE);				
	IS_dvi2k->set_current(IS_ch, 20e-3, RANGE_20_MA);
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
	//HBP_dvi2k->open_relay(CONN_FORCE0);
	BPS_dvi->open_relay(CONN_FORCE0);

	//Close_relay(K1_FB_SPI_TB); //Trying.
	Close_relay(K2_HSG_SPI_TB);      //Disconect OVI_1_0 from HSG.
	Close_relay(K2_B_SPI_TB);        //Disconnect OVI_3_1 from B.
	Close_relay(K3_B_SPI_TB);		//Connect 2nF to B
	Close_relay(K3_HSG_SPI_TB);     //Connect 2nF to HSG
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

	//FB_ovi3->set_current(FB_ch, 300e-6, RANGE_300_UA);
	//FB_ovi3->set_voltage(FB_ch, 1.25, VOLT_5_RANGE); 	
	//wait.delay_10_us(10);
	///Power up VR to 15V to wake up 2ndary.
	// If 15V doesn't work, will set to 20V.
	VR_dvi->set_voltage(VR_ch, 20, VOLT_50_RANGE); 
	HBP_dvi2k->set_voltage(HBP_ch, g_HBP_Pre_S, VOLT_20_RANGE);
	wait.delay_10_us(500);

	//SDA,SCL = 3.3V via pullup resistor. Ready for I2C.
	SDA_ovi3->set_voltage(SDA_ch, 3.3, VOLT_10_RANGE); 
	SCL_ovi3->set_voltage(SCL_ch, 3.3, VOLT_10_RANGE); 
	wait.delay_10_us(200);

	//IS = 100mV/20mA
	IS_dvi2k->set_current(IS_ch, 20e-3, RANGE_20_MA);
	IS_dvi2k->set_voltage(IS_ch, 0.1, VOLT_1_RANGE);
	wait.delay_10_us(100);

	//-----------------------------------------------------------------------------------
	//I2C command.
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

//pulse.do_pulse();

	//ZTMC_Dsbl_FBshrt  (The FBshrt -> FB to HBP short fault protection function.)								  
	//0x00 0x62 write 0x80 0x00
	DSM_I2C_Write('w', g_S_TEST_CTRL2, 0x0080);

	//ZTMC_ana_EN and Core_en
	//0x00 0x40 write 0x06 0x00
	DSM_I2C_Write('w', g_S_TM_CTRL, 0x0007);

	//ZTMC_trimOffset, ZTMC_Frc_gain & ZTMC_AVIN
	//0x00 0x46 write 0x70 0x00
	DSM_I2C_Write('w', g_S_ANA_CTRL_1, 0x0070);

	FB_ovi3->set_meas_mode(FB_ch, OVI_MEASURE_VOLTAGE);
	FB_ovi3->set_current(FB_ch, 0.1e-9, RANGE_3_UA);
	FB_ovi3->set_voltage(FB_ch, 0.0, VOLT_2_RANGE); 	
	wait.delay_10_us(100);

	//Loading previous trimming before performing the test.
	Program_Trim_Register(g_S_TrimRegister);

	//ZTMC_ADC_ref
	//0x00 0x44 write 0x20 0x00
	//DSM_I2C_Write('w', g_S_ANA_CTRL_0, 0x0020);

	CCOffset_pt_S = FB_ovi3->measure_average(25);
	delay(1);
//////////
//////////
//////////	// IRSET_S_Code //
//////////	// Find which trim code will make IRSET_Pre closest to target //
//////////	smallest_diff_val = 999999.9;
//////////	smallest_diff_idx = 0;
//////////	for (i=0; i<16; i++)
//////////	{
//////////		temp_1 = (VADC_pt_S * (1 + (VADC_S_TrimWt[i]/100)) -  VADC_Target_S);
//////////		if (temp_1 < 0)	// Get rid of negatives //
//////////			temp_1 *= -1.0;
//////////		if (temp_1 < smallest_diff_val)
//////////		{
//////////			smallest_diff_val = temp_1;
//////////			smallest_diff_idx = i;
//////////		}
//////////	}
//////////
//////////
//////////	//Manual forcing:
////////////	smallest_diff_idx = 15;
//////////
//////////	VADC_TrCode_S = smallest_diff_idx;
//////////	VADC_TrCode_S = VADC_S_code[smallest_diff_idx];
//////////	VADC_ExpChg   = VADC_S_TrimWt[smallest_diff_idx];
//////////
//////////	VADC_ExpValue = (VADC_pt_S * (1 + (VADC_S_TrimWt[smallest_diff_idx]/100)));
//////////
//////////	TrimCode_To_TrimBit(VADC_TrCode_S, "VADC_S", 's');
//////////
//////////
//////////	//Convert Trimcode to readable datalog file.
//////////	if(VADC_S_code[smallest_diff_idx]>=0 && VADC_S_code[smallest_diff_idx] <= 7)
//////////	{
//////////		VADC_BitCode_S = -1*VADC_TrCode_S; 
//////////	}
//////////	else
//////////	{
//////////		VADC_BitCode_S = VADC_TrCode_S - 7;
//////////	}
//////////
//////////	//Update WordArray.
//////////	WordArray[0]        = g_S_TrimRegisterTemp[48]; //EEtr76_ZTLnt0_S
//////////	WordArray[1]        = g_S_TrimRegisterTemp[49]; //EEtr77_ZTLnt1_S
//////////	WordArray[2]        = g_S_TrimRegisterTemp[50]; //EEtr78_ZTLnt2_S
//////////	WordArray[3]        = g_S_TrimRegisterTemp[51]; //EEtr79_ZTLnt3_S
//////////
//////////	//Update secondary trim register array for programming later.
//////////	g_S_TrimRegister[48] = g_S_TrimRegisterTemp[48]; //EEtr76_ZTLnt0_S
//////////	g_S_TrimRegister[49] = g_S_TrimRegisterTemp[49]; //EEtr77_ZTLnt1_S
//////////	g_S_TrimRegister[50] = g_S_TrimRegisterTemp[50]; //EEtr78_ZTLnt2_S
//////////	g_S_TrimRegister[51] = g_S_TrimRegisterTemp[51]; //EEtr79_ZTLnt3_S
//////////
//////////	//Convert from binary to decimal.
//////////	converted_dec1 = Convert_BIN_2_Dec(WordArray);
//////////	converted_dec2 = Convert_BIN_2_Dec(WordArray);
//////////
//////////
//////////	//Program Trim Register with new calculated bit combination.
//////////	Program_Trim_Register(g_S_TrimRegister);
//////////
//////////	int TrimBank[5];
//////////
//////////	Read_Trim_Register(TrimBank);
//////////
//////////
//////////	wait.delay_10_us(100);
//////////
//////////	VADC_prg_S = FB_ovi3->measure_average(25);
//////////
//////////	if(VADC_pt_S != 0)
//////////	{
//////////		VADC_PrgChg = 100*(VADC_prg_S - VADC_pt_S) / VADC_pt_S;
//////////	}
	//---------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------
	//Powerdown
	//-------------------------------------------------------------------------------
	DSM_set_I2C_clock_freq(DSM_CONTEXT, 300);

	VR_dvi->set_voltage(VR_ch, 5, VOLT_50_RANGE); 
	wait.delay_10_us(200);
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE);
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
	Open_relay(K2_B_SPI_TB);         //Reconnect OVI_3_1 to B.
	Open_relay(K3_B_SPI_TB);		 //Disconnect 2nF from B
	Open_relay(K3_HSG_SPI_TB);       //Disconnect 2nF from HSG
	Open_relay(K1_HSG_SPI_RB);		 //Disconnect pullup R from HSG.
	Open_relay(K1_FB_SPI_TB);		 //Reconnect OVI to FB

	Open_relay(K1_FB_SPI_TB); //Trying
	
	wait.delay_10_us(250);
//////////
//////////
//////////	PiDatalog(func, A_VADC_pt_S,		  VADC_pt_S,               26, POWER_UNIT);
//////////	PiDatalog(func, A_VADC_target_S,      VADC_Target_S,           26, POWER_UNIT);
//////////	PiDatalog(func, A_VADC_TrCode_S,      VADC_TrCode_S,           26, POWER_UNIT);
//////////	PiDatalog(func, A_VADC_BitCode_S,     VADC_BitCode_S,           26, POWER_UNIT);
//////////	PiDatalog(func, A_VADC_ExpChg_S,      VADC_ExpChg,             26, POWER_UNIT);
//////////	PiDatalog(func, A_VADC_Exp_Value,     VADC_ExpValue,           26, POWER_UNIT);
//////////	PiDatalog(func, A_Eetr48_ZTMFS0_S,    g_S_TrimRegister[48],    26, POWER_UNIT);
//////////	PiDatalog(func, A_Eetr49_ZTMFS1_S,    g_S_TrimRegister[49],    26, POWER_UNIT);
//////////	PiDatalog(func, A_Eetr50_ZTMFS2_S,    g_S_TrimRegister[50],    26, POWER_UNIT);
//////////	PiDatalog(func, A_Eetr51_ZTMFS3_S,    g_S_TrimRegister[51],    26, POWER_UNIT);
//////////	PiDatalog(func, A_Bin2Dec1_S,         converted_dec1,          26, POWER_UNIT);
//////////	PiDatalog(func, A_VADC_prg_S,         VADC_prg_S,              26, POWER_UNIT);
//////////	PiDatalog(func, A_VADC_prgchg_S,      VADC_PrgChg,             26, POWER_UNIT);


}
