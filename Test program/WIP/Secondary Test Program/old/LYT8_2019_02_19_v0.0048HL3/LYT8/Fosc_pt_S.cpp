//==============================================================================
// Fosc_pt_S.cpp (User function)
// 
//    void Fosc_pt_S_user_init(test_function& func)
//    void Fosc_pt_S(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "Fosc_pt_S.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void Fosc_pt_S_user_init(test_function& func)
{
	Fosc_pt_S_params *ours;
    ours = (Fosc_pt_S_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void Fosc_pt_S(test_function& func)
{
    // The two lines below must be the first two in the function.
    Fosc_pt_S_params *ours;
    ours = (Fosc_pt_S_params *)func.params;


		gFuncNum++;	

// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_Fosc_Pre_S, gFuncNum, 27, POWER_UNIT);

	// Skip Test if AbortTest set 
	if (AbortTest)
		return;

	// Skip trimming if g_Trim_Enable_P set //
	//if (g_Trim_Enable_P == 0)
//		return;

	//if (g_Fn_CLK1M_Pre == 0 )  return;

	// Test Time Begin //
	if (g_TstTime_Enble_P)
		g_begintime = g_mytimer.GetElapsedTime();

	// Test variables

	int   i              = 0;
	int   WordArray[32]  = {0};
	uint16_t converted_dec1 = 0;
	uint16_t converted_dec2 = 0;

	// Test Names //
	float Fosc_pt_S      = 0;
	float Fosc_prg_S     = 0;
	float Fosc_Target_S  = 100E3; 
	int   Fosc_TrCode_S  = 0;
	int   Fosc_BitCode_S = 0;
	int   EEtr64_VCO0_S     = 0;
	int   EEtr65_VCO1_S     = 0;
	int   EEtr66_VCO2_S     = 0;
	int   EEtr67_VCO3_S     = 0;
	int   EEtr68_VCO4_S     = 0;
	int   EEtr69_VCO5_S     = 0;

	float Fosc_Sim_S = 0;
	float Fosc_Sim_Chg_S = 0;
	float Fosc_ExpChg    = 0;
	float Fosc_ExpValue  = 0;
	float Fosc_PrgChg    = 0;
	float Fosc_pst_S     = 0;
	float Fosc_Pre_TT    = 0;

Pulse pulse;

	//Trimcode & bit weights.
	float	Fosc_S_TrimWt[32]   = {0.0};
	float	Fosc_S_code[32]     = {0.0};
	float   smallest_diff_val = 999999.9;
	int     smallest_diff_idx = 0;
	float   temp_1            = 0;
	float   tmeas             = 0;

	
	i = 0;
	Fosc_S_code[i] =  0; Fosc_S_TrimWt[i] =  0.00;       i++;     //0 (0 link trimmed)
	Fosc_S_code[i] =  1; Fosc_S_TrimWt[i] =  1.60;     i++;     //0 (1 link trimmed--> 0.0%)
	Fosc_S_code[i] =  2; Fosc_S_TrimWt[i] =  3.20;    i++;     //0 (1 link trimmed--> 8.0%)
	Fosc_S_code[i] =  3; Fosc_S_TrimWt[i] =  4.80;    i++;     //0 (2 link trimmed--> 12.0%)
	Fosc_S_code[i] =  4; Fosc_S_TrimWt[i] =  6.40;   i++;     //0 (1 link trimmed--> 16.0%)
	Fosc_S_code[i] =  5; Fosc_S_TrimWt[i] =  8.00;  i++;     //0 (2 link trimmed--> 20.0%)
	Fosc_S_code[i] =  6; Fosc_S_TrimWt[i] =  9.60;  i++;     //0 (2 link trimmed--> 24.0%)
	Fosc_S_code[i] =  7; Fosc_S_TrimWt[i] =  11.2;   i++;     //0 (3 link trimmed--> 28.0%)
	Fosc_S_code[i] =  8; Fosc_S_TrimWt[i] =  12.8;   i++;     //0 (1 link trimmed-->  -32%)
	Fosc_S_code[i] =  9; Fosc_S_TrimWt[i] =  14.4;   i++;     //0 (2 link trimmed-->  -28%)
	Fosc_S_code[i] = 10; Fosc_S_TrimWt[i] =  16.0;   i++;     //0 (2 link trimmed-->  -24%)
	Fosc_S_code[i] = 11; Fosc_S_TrimWt[i] =  17.6;   i++;     //0 (3 link trimmed-->  -20%)
	Fosc_S_code[i] = 12; Fosc_S_TrimWt[i] =  19.2;   i++;     //0 (2 link trimmed-->  -16%)
	Fosc_S_code[i] = 13; Fosc_S_TrimWt[i] =  20.8;    i++;     //0 (3 link trimmed-->  -12%)
	Fosc_S_code[i] = 14; Fosc_S_TrimWt[i] =  22.4;    i++;     //0 (3 link trimmed-->  -8%)
	Fosc_S_code[i] = 15; Fosc_S_TrimWt[i] =  24.0;    i++;     //0 (4 link trimmed-->  -4%)
	Fosc_S_code[i] = 16; Fosc_S_TrimWt[i] =  0.00;       i++;     //0 (0 link trimmed)
	Fosc_S_code[i] = 17; Fosc_S_TrimWt[i] =  1.60;     i++;     //0 (1 link trimmed--> 0.0%)
	Fosc_S_code[i] = 18; Fosc_S_TrimWt[i] =  3.20;    i++;     //0 (1 link trimmed--> 8.0%)
	Fosc_S_code[i] = 19; Fosc_S_TrimWt[i] =  4.80;    i++;     //0 (2 link trimmed--> 12.0%)
	Fosc_S_code[i] = 20; Fosc_S_TrimWt[i] =  6.40;   i++;     //0 (1 link trimmed--> 16.0%)
	Fosc_S_code[i] = 21; Fosc_S_TrimWt[i] =  8.00;  i++;     //0 (2 link trimmed--> 20.0%)
	Fosc_S_code[i] = 22; Fosc_S_TrimWt[i] =  9.60;  i++;     //0 (2 link trimmed--> 24.0%)
	Fosc_S_code[i] = 23; Fosc_S_TrimWt[i] =  11.2;   i++;     //0 (3 link trimmed--> 28.0%)
	Fosc_S_code[i] = 24; Fosc_S_TrimWt[i] =  12.8;   i++;     //0 (1 link trimmed-->  -32%)
	Fosc_S_code[i] = 25; Fosc_S_TrimWt[i] =  14.4;   i++;     //0 (2 link trimmed-->  -28%)
	Fosc_S_code[i] = 26; Fosc_S_TrimWt[i] =  16.0;   i++;     //0 (2 link trimmed-->  -24%)
	Fosc_S_code[i] = 27; Fosc_S_TrimWt[i] =  17.6;   i++;     //0 (3 link trimmed-->  -20%)
	Fosc_S_code[i] = 28; Fosc_S_TrimWt[i] =  19.2;   i++;     //0 (2 link trimmed-->  -16%)
	Fosc_S_code[i] = 29; Fosc_S_TrimWt[i] =  20.8;    i++;     //0 (3 link trimmed-->  -12%)
	Fosc_S_code[i] = 30; Fosc_S_TrimWt[i] =  22.4;    i++;     //0 (3 link trimmed-->  -8%)
	Fosc_S_code[i] = 31; Fosc_S_TrimWt[i] =  24.0;    i++;     //0 (4 link trimmed-->  -4%)

	
	// Load WordArray[] with contents of g_Sec_TrimRegister[] array!  This includes trim bit from other tests & trim options 
    // This is important for proper trimming! //
	// E8 Trim register.
	WordArray[0]  = g_S_TrimRegister[64]; //EEtr64_VCO0_S
	WordArray[1]  = g_S_TrimRegister[65]; //EEtr65_VCO1_S
	WordArray[2]  = g_S_TrimRegister[66]; //EEtr66_VCO2_S
	WordArray[3]  = g_S_TrimRegister[67]; //EEtr67_VCO3_S
	WordArray[4]  = g_S_TrimRegister[68]; //EEtr68_VCO4_S
	WordArray[5]  = g_S_TrimRegister[69]; //EEtr64_VCO5_S
	WordArray[6]  = g_S_TrimRegister[70]; 
	WordArray[7]  = g_S_TrimRegister[71]; 
	WordArray[8]  = g_S_TrimRegister[72]; 
	WordArray[9]  = g_S_TrimRegister[73]; 
	WordArray[10] = g_S_TrimRegister[74];
	WordArray[11] = g_S_TrimRegister[75];
	WordArray[12] = g_S_TrimRegister[76];
	WordArray[13] = g_S_TrimRegister[77];
	WordArray[14] = g_S_TrimRegister[78];
	WordArray[15] = g_S_TrimRegister[79];

	// Open all relays //
	Initialize_Relays();

	Load_10Khz_Pulses();

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
	//HSG: disconnect and connect to 2nF
	HSG_ovi->set_current(HSG_ch, 300e-6, RANGE_300_UA);
	HSG_ovi->set_voltage(HSG_ch, 0, VOLT_20_RANGE); 
	//B:  require open drain config and use pullup R.
	B_ovi3->set_current(B_ch1, 300e-6, RANGE_300_UA);
	B_ovi3->set_voltage(B_ch1, 0.0, VOLT_10_RANGE);
	//FW = 0V/30mA
	FW_ovi3->set_current(FW_ch, 30e-3, RANGE_30_MA);
	FW_ovi3->set_voltage(FW_ch, 0.0, VOLT_5_RANGE); 
	//FB = Hiz.
	FB_ovi3->set_current(FB_ch, 300e-6, RANGE_300_UA);
	FB_ovi3->set_voltage(FB_ch, 0.0, VOLT_10_RANGE); 
	//IS = 0V/200mA...should it be a bit above ground?
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_1_RANGE);				
	IS_dvi2k->set_current(IS_ch, 200e-6, RANGE_200_UA);//Keep 200UA range here to minimize range error.
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

	DSM_set_I2C_clock_freq(DSM_CONTEXT, 300);

	//Setup TMU on Buffer of HSG pin.
	tmu_6->close_relay(TMU_HIZ_DUT4); 
	tmu_6->start_trigger_setup(0.6, NEG_SLOPE, TMU_HIZ, TMU_IN_10V);
	tmu_6->stop_trigger_setup(0.8, NEG_SLOPE, TMU_HIZ, TMU_IN_10V);
	tmu_6->start_holdoff(0,FALSE);
	tmu_6->stop_holdoff(0,FALSE);

	//Secondary I2C to ready Secondary Die ID.
	//Disconnect HBP & BPs and use VR to powerup 2ndary.
	HBP_dvi2k->open_relay(CONN_FORCE0);
	BPS_dvi->open_relay(CONN_FORCE0);

	Close_relay(K7_IS_SPI_TB);      //Connect 1K from IS to GND
	Close_relay(K1_IS_SPI_TB);		  //Disconnect DVI_13_1 from IS.
	Open_relay(K2_HSG_SPI_TB);        //Keep OVI_1_0 on HSG.
	Close_relay(K1_HSG_SPI_RB);       //Connect pullup R on HSG. 
	Close_relay(K5_HSG_SPI_TB);      //Connect HSG to buffer 
	Close_relay(K3_B_SPI_TB);		 //Connect 2nF to B
	Open_relay(K5_TMU_TB);           //DisconnectTMU_HIZ_3 from FW.
	Close_relay(K7_DDD_TB);          //Connect DDD_7_7 to FW.
	Close_relay(K1_FW_SPI_TB);       //Disconnect OVI from FW.
	tmu_6->open_relay(TMU_CHAN_B_DUT1); 
	tmu_6->open_relay(TMU_HIZ_DUT3); 

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

	VR_dvi->set_voltage(VR_ch, 5, VOLT_50_RANGE); 
	wait.delay_10_us(10);

	//Clock FW with 10Khz pulses.
	Run_10Khz_Pulses();
	wait.delay_10_us(10);

	FB_ovi3->set_current(FB_ch, 300e-6, RANGE_300_UA);
	FB_ovi3->set_voltage(FB_ch, 1.0, VOLT_5_RANGE);
	//FB_ovi3->disconnect(FB_ch);  //Disconnect OVI from FB to keep it at Hiz.
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

////////
////////	//-----------------------------------------------------------------------------------
////////	//I2C command.
////////	//------------------------------------------------------------------------------------
////////	
////////	//Sometimes, DSM I2C can't be written correctly the first time.
////////	//Change the DSM timeout to 1ms since the default timeout is approximately 35ms.
////////	//g_Debug = 1;
////////	DSM_set_I2C_timeout(0, 1);
////////	DSM_set_I2C_clock_freq(DSM_CONTEXT, 300);
////////
////////	//Enter TM
////////	Analog_TM_Enable_Secondary();
////////	//For TEST only..  Manually raise vFB above 2.5V or 3V here to observe HBP will go low and then lower to 1.25V for HSG to go High
////////	//Below to to make sure the FB controlling HBP is working properly before Disabling it.
////////	if(0)
////////	{
////////		FB_ovi3->set_voltage(FB_ch, 2.00, VOLT_5_RANGE); // DVI_11_0
////////		delay(1);
////////		FB_ovi3->set_voltage(FB_ch, 2.25, VOLT_5_RANGE); // DVI_11_0
////////		delay(1);
////////		FB_ovi3->set_voltage(FB_ch, 2.50, VOLT_5_RANGE); // DVI_11_0
////////		delay(1);
////////		FB_ovi3->set_voltage(FB_ch, 2.75, VOLT_5_RANGE); // DVI_11_0
////////		delay(1);
////////		FB_ovi3->set_voltage(FB_ch, 3.00, VOLT_5_RANGE); // DVI_11_0	//1uF on HBP.  The drop is slow if it's only 3ms.  Manual observe drop to ~1.7V
////////		delay(3);              
////////		FB_ovi3->set_voltage(FB_ch, 1.25, VOLT_5_RANGE); // DVI_11_0
////////		delay(1);
////////	}
////////
////////
////////
////////	//ZTMC_Driver_en & ZTMC_Dsbl_FBshrt  (The FBshrt -> FB to HBP short fault protection function.)								  
////////	//0x00 0x62 write 0x88 0x00
////////	DSM_I2C_Write('w', g_TEST_CTRL2, 0x0088);
////////
////////	//ZTMC_sig_EN and Core_en.  Dont turn on HSG driver because of noise.
////////	//0x00 0x40 write 0x05 0x00
////////	DSM_I2C_Write('w', g_TM_CTRL, 0x0005);
////////
////////	//0x00 0x60 write 0x00 0xC0  ==> Open Drain on HSG & B.
////////	DSM_I2C_Write('w', g_TEST_CTRL1, 0xC000);
////////
////////	FB_ovi3->set_current(FB_ch, 300e-6, RANGE_300_UA);
////////	FB_ovi3->set_voltage(FB_ch, 0.0, VOLT_5_RANGE);
////////	wait.delay_10_us(10);
////////	FB_ovi3->disconnect(FB_ch);  //Disconnect OVI from FB to keep it at Hiz.
////////	wait.delay_10_us(250);
////////	//Set pull V& I on B
////////	B_ovi3->set_current(B_ch1, 30e-3, RANGE_30_MA);
////////	B_ovi3->set_voltage(B_ch1, 5.0, VOLT_10_RANGE);
////////
////////
////////	//Loading previous trimming before performing the test.
////////	Program_Trim_Register(g_S_TrimRegister);
////////
////////
////////	//DsysClk1Mhz on B.
////////	//0x00 0x42 write 0x0F 0x00
////////	DSM_I2C_Write('w', 0x42, 0x000F);
////////
////////	//DsysClk6Mhz on B.
////////	//0x00 0x42 write 0x0F 0x00
////////	//DSM_I2C_Write('w', 0x42, 0x0018);
////////DSM_set_I2C_clock_freq(DSM_CONTEXT, 300);
////////
////////
////////	//Monitor 1Mhz switching on Boost pin.	
////////	tmu_6->start_holdoff(15,TRUE);
////////	tmu_6->stop_holdoff(15,TRUE);
////////	wait.delay_10_us(10);
////////	tmu_6->arm();						// Device doing auto-restart
////////	wait.delay_10_us(15);				// Wait for TMU to trigger and to capture 10 cycles 
////////	tmeas = tmu_6->read(150e-6);	 
////////	tmeas/=15;
////////	if (tmeas != 0)
////////		CLK1M_pt_S = 1/tmeas;
////////	else
////////		CLK1M_pt_S = 0.0;	
////////
////////
////////
////////
////////	// CLK1M_S_Code //
////////	// Find which trim code will make CLK1M_Pre closest to target //
////////	smallest_diff_val = 999999.9;
////////	smallest_diff_idx = 0;
////////	for (i=0; i<16; i++)
////////	{
////////		temp_1 = (CLK1M_pt_S * (1 + (CLK1M_S_TrimWt[i]/100)) -  CLK1M_Target_S);
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
////////	CLK1M_TrCode_S = smallest_diff_idx;
////////	CLK1M_TrCode_S = CLK1M_S_code[smallest_diff_idx];
////////	CLK1M_ExpChg   = CLK1M_S_TrimWt[smallest_diff_idx];
////////
////////	CLK1M_ExpValue = (CLK1M_pt_S * (1 + (CLK1M_S_TrimWt[smallest_diff_idx]/100)));
////////
////////	TrimCode_To_TrimBit(CLK1M_TrCode_S, "Clock1M_S", 's');
////////
////////
////////	//Convert Trimcode to readable datalog file.
////////	///*if(CLK1M_S_code[smallest_diff_idx]>=0 && CLK1M_S_code[smallest_diff_idx] <= 7)
////////	//{
////////	//	CLK1M_BitCode_S = -1*VADC_TrCode_S; 
////////	//}
////////	//else
////////	//{
////////	//	VADC_BitCode_S = VADC_TrCode_S - 7;
////////	//}*/
////////
////////	//Update WordArray.
////////	WordArray[6]        = g_S_TrimRegisterTemp[70]; //EEtr70_B0_S
////////	WordArray[7]        = g_S_TrimRegisterTemp[71]; //EEtr71_B1_S
////////	WordArray[8]        = g_S_TrimRegisterTemp[72]; //EEtr72_B2_S
////////	WordArray[9]        = g_S_TrimRegisterTemp[73]; //EEtr73_B3_S
////////
////////	//Update secondary trim register array for programming later.
////////	g_S_TrimRegister[70] = g_S_TrimRegisterTemp[70]; //EEtr76_ZTLnt0_S
////////	g_S_TrimRegister[71] = g_S_TrimRegisterTemp[71]; //EEtr77_ZTLnt1_S
////////	g_S_TrimRegister[72] = g_S_TrimRegisterTemp[72]; //EEtr78_ZTLnt2_S
////////	g_S_TrimRegister[73] = g_S_TrimRegisterTemp[73]; //EEtr79_ZTLnt3_S
////////
////////	//Convert from binary to decimal.
////////	converted_dec1 = Convert_BIN_2_Dec(WordArray);
////////	converted_dec2 = Convert_BIN_2_Dec(WordArray);
////////
////////DSM_set_I2C_clock_freq(DSM_CONTEXT, 300);
////////	//Program Trim Register with new calculated bit combination.
////////	Program_Trim_Register(g_S_TrimRegister);
////////DSM_set_I2C_clock_freq(DSM_CONTEXT, 300);
////////	int TrimBank[5];
////////
////////	Read_Trim_Register(TrimBank);
////////DSM_set_I2C_clock_freq(DSM_CONTEXT, 300);
////////	tmeas = 0.0;
////////
////////	//Monitor 1Mhz switching on Boost pin.	
////////	tmu_6->start_holdoff(15,TRUE);
////////	tmu_6->stop_holdoff(15,TRUE);
////////	wait.delay_10_us(10);
////////	tmu_6->arm();						// Device doing auto-restart
////////	wait.delay_10_us(15);				// Wait for TMU to trigger and to capture 10 cycles 
////////	tmeas = tmu_6->read(150e-6);	 
////////	tmeas/=15;
////////	if (tmeas != 0)
////////		CLK1M_prg_S = 1/tmeas;
////////	else
////////		CLK1M_prg_S = 0.0;	
////////
////////
////////
////////
////////	if(CLK1M_pt_S != 0)
////////	{
////////		CLK1M_PrgChg = 100*(CLK1M_prg_S - CLK1M_pt_S) / CLK1M_pt_S;
////////	}
////////	//---------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------
	//Powerdown
	//-------------------------------------------------------------------------------
	DSM_set_I2C_clock_freq(DSM_CONTEXT, 300);

	ddd_7->ddd_stop_pattern(); //Stop the 10Khz Pattern.

	//Reset DDD low level to 0V.
	ddd_7->ddd_set_lo_level(0.0);
	ddd_7->ddd_set_hi_level(g_DDD_High);	
	wait.delay_10_us(10);

	VR_dvi->set_voltage(VR_ch, 5, VOLT_50_RANGE); 
	wait.delay_10_us(200);
	B_ovi3->set_current(B_ch1, 30e-3, RANGE_30_MA);
	B_ovi3->set_voltage(B_ch1, 0.0, VOLT_10_RANGE);
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

	Open_relay(K7_IS_SPI_TB);         //Disconnect 1K from IS to GND
	Open_relay(K1_IS_SPI_TB);		  //Reconnect DVI_13_1 to IS.
	Open_relay(K2_HSG_SPI_TB);        //Keep OVI_1_0 on HSG.
	Open_relay(K1_HSG_SPI_RB);        //Disconnect pullup R from HSG. 
	Open_relay(K5_HSG_SPI_TB);        //Disconnect HSG from buffer 
	Open_relay(K3_B_SPI_TB);		  //Disconnect 2nF from B
	Open_relay(K3_HSG_SPI_TB);       //Disconnect 2nF from HSG
	Open_relay(K5_TMU_TB);           //DisconnectTMU_HIZ_3 from FW.
	Open_relay(K7_DDD_TB);           //Disconnect DDD_7_7 from FW.
	Open_relay(K1_FW_SPI_TB);        //Reconnect OVI to FW.
	tmu_6->open_relay(TMU_CHAN_B_DUT1); 
	tmu_6->open_relay(TMU_HIZ_DUT3); 
	tmu_6->open_relay(TMU_HIZ_DUT4); 
	wait.delay_10_us(250);

	
////////
////////
////////	PiDatalog(func, A_Fosc_pt_S,		  CLK1M_pt_S,               26, POWER_MEGA);
////////	PiDatalog(func, A_Fosc_target_S,     CLK1M_Target_S,           26, POWER_MEGA);
////////	PiDatalog(func, A_Fosc_TrCode_S,     CLK1M_TrCode_S,           26, POWER_UNIT);
////////	PiDatalog(func, A_Fosc_BitCode_S,    CLK1M_BitCode_S,           26, POWER_UNIT);
////////	PiDatalog(func, A_Fosc_ExpChg_S,     CLK1M_ExpChg,             26, POWER_UNIT);
////////	PiDatalog(func, A_Fosc_Exp_Value,    CLK1M_ExpValue,           26, POWER_MEGA);
////////	PiDatalog(func, A_Eetr64_VCO0_S,    g_S_TrimRegister[70],    26, POWER_UNIT);
////////	PiDatalog(func, A_Eetr65_VCO1_S,    g_S_TrimRegister[71],    26, POWER_UNIT);
////////	PiDatalog(func, A_Eetr66_VCO2_S,    g_S_TrimRegister[72],    26, POWER_UNIT);
////////	PiDatalog(func, A_Eetr67_VCO3_S,    g_S_TrimRegister[73],    26, POWER_UNIT);
////////	PiDatalog(func, A_Eetr68_VCO4_S,    g_S_TrimRegister[72],    26, POWER_UNIT);
////////	PiDatalog(func, A_Eetr69_VCO5_S,    g_S_TrimRegister[73],    26, POWER_UNIT);
////////	PiDatalog(func, A_Bin2Dec1_S,         converted_dec1,          26, POWER_UNIT);
////////	PiDatalog(func, A_CLK1M_prg_S,         CLK1M_prg_S,              26, POWER_MEGA);
////////	PiDatalog(func, A_CLK1M_prgchg_S,      CLK1M_PrgChg,             26, POWER_UNIT);


}
