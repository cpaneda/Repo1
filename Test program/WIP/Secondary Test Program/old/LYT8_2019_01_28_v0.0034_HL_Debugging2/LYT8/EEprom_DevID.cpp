//==============================================================================
// EEprom_DevID.cpp (User function)
// 
//    void EEprom_DevID_user_init(test_function& func)
//    void EEprom_DevID(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "EEprom_DevID.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void EEprom_DevID_user_init(test_function& func)
{
	EEprom_DevID_params *ours;
    ours = (EEprom_DevID_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void EEprom_DevID(test_function& func)
{
    // The two lines below must be the first two in the function.
    EEprom_DevID_params *ours;
    ours = (EEprom_DevID_params *)func.params;

	//Variables
	int Secondary_DieID = 0;

	// Increment function number //
	gFuncNum++;	

	Pulse pulse;

	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_eeprom_devid, gFuncNum, 15, POWER_UNIT);

	// Skip Test if AbortTest set //
	if (AbortTest)
		return;

	if (g_Fn_Continuity == 0 )  return;

	// Test Time Begin //
	 if (g_p_TstTime_Enble)
	 	g_begintime = g_mytimer.GetElapsedTime();

	 //---------------------------------------------------------------------------------------------------------------
	//Charles will work on the Primary section.
	//-----------------------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------------------
////////////	//-------------------------------------------------------------------------------------
////////////	//---------- Secondary EEprom 'Read ID' &'Erase EEprom'  ------------------------------
////////////	//-------------------------------------------------------------------------------------
////////////	/*
////////////		Erase EEProm for Secondary
////////////		1.	vFB = 1.25V
////////////		2.	VR = 15V
////////////        3.  Read Die ID and convert it to decimal for datalogging later.	 
////////////		4.	Test Mode Enable with Drivers_en, Dsbl_FBshrt, ana_EN, Core_En, Comp out on HSG
////////////			a.	0x00 0x5E write 0x16 0x20
////////////			b.	0x00 0x5E write 0x34 0x12
////////////        5.  Read 0xC0 and determine if it's untrimmed and erasing EEprom is required.
////////////        6.  Erase EEprom
////////////			a.	ZTMC_Drivers_en and ZTMC_Dsbl_FBshrt
////////////				i.	0x00 0x62 write 0x88 0x00
////////////			b.	ZTMC_ana_EN and Core_en
////////////				i.	0x00 0x40 write 0x06 0x00
////////////			c.	ZVtrim_comp (Comp out on HSG)
////////////				i.	0x00 0x46 write 0x00 0xB8
////////////				ii.	Note: If Comp out on HSG is not done rasing vFB above 2.5V/3V would bring HSG output down to ~2V and lower it to 1.25V would see HSG output ~11.5V
////////////			d.	0x00 0x5C write 0x03
////////////			e.	ZTMC_ana_vprog_EN and ZTMC_ana_Vprog_2
////////////				i.	0x00 0x44 write 0x07 0x00
////////////			f.	Raise VR pin voltage >24V until HSG pin toggles to complete Erase (DC voltage could determine toggle or not)
////////////			g.	Stop/End Erase EEprom
////////////				i.	 0x00 0x5C write 0x00
////////////				ii.	 VR set to 15V 
////////////				iii. 0x00 0x44 write 0x00 0x00 --> bring internal supply back to 5V from 7V
///////////         7.  Re-Read EEprom 0xC0 to ensure if it's erased properly




	//-----------------------------------------------------------------------------------------------------------------
	//Power down Primary Die
	//------------------------------------------------------------------------------------------------------------------
	//Drain = 0V
	D_dvi->set_current(D_ch, 100e-3, RANGE_300_MA);
	D_dvi->set_voltage(D_ch, 0.0, VOLT_2_RANGE); 
	//BPP = 0V
	BPP_dvi->set_current(BPP_ch, 300e-3, RANGE_300_MA);
	BPP_dvi->set_voltage(BPP_ch, 0.0, VOLT_10_RANGE); 

	//TS = 0V 
	TS_ovi3->set_current(TSovi3_ch, 30e-3, RANGE_30_MA);
	TS_ovi3->set_voltage(TSovi3_ch, 0.0, VOLT_10_RANGE); 
	//UV = 0V 
	UV_dvi->set_current(UV_ch, 300e-3, RANGE_300_MA);
	UV_dvi->set_voltage(UV_ch, 0.0, VOLT_10_RANGE);

	//-----------------------------------------------------------------------------------------------------------------
	//Setup Resource pins on Secondary.
	//------------------------------------------------------------------------------------------------------------------
	HSG_ovi->set_current(HSG_ch, 30e-3, RANGE_30_MA);
	HSG_ovi->set_voltage(HSG_ch, 0, VOLT_20_RANGE); 
	B_ovi3->set_current(B_ch1, 30e-3, RANGE_30_MA);
	B_ovi3->set_voltage(B_ch1, 0.0, VOLT_10_RANGE);
	FW_ovi3->set_current(FW_ch, 3e-3, RANGE_30_MA);
	FW_ovi3->set_voltage(FW_ch, 0.0, VOLT_2_RANGE); 
	FB_ovi3->set_current(FB_ch, 30e-3, RANGE_30_MA);
	FB_ovi3->set_voltage(FB_ch, 0.0, VOLT_5_RANGE); 
	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_5_RANGE);				
	IS_dvi2k->set_current(IS_ch, 200e-3, RANGE_200_MA);
	SDA_ovi3->set_current(SDA_ch, 30e-3, RANGE_30_MA);	        
	SDA_ovi3->set_voltage(SDA_ch, 0.0, VOLT_5_RANGE); 
	SCL_ovi3->set_current(SCL_ch, 30e-3, RANGE_30_MA);				
	SCL_ovi3->set_voltage(SCL_ch, 0.0, VOLT_5_RANGE); 
	BPS_dvi->set_voltage(BPS_ch, 0.0, VOLT_5_RANGE); 
	BPS_dvi->set_current(BPS_ch, 0.0e-3, RANGE_300_MA);
	HBP_dvi2k->set_current(HBP_ch, 0.0e-6, RANGE_200_MA);
	HBP_dvi2k->set_voltage(HBP_ch, 0.0, VOLT_20_RANGE);
	VR_dvi->set_current(VR_ch, 300e-3, RANGE_300_MA);	
	VR_dvi->set_voltage(VR_ch, 0.0, VOLT_5_RANGE); 
	wait.delay_10_us(50);

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


	//Step 1.	vFB = 1.25V
	FB_ovi3->set_current(FB_ch, 30e-3, RANGE_30_MA);
	FB_ovi3->set_voltage(FB_ch, 1.25, VOLT_5_RANGE); // DVI_11_0
	wait.delay_10_us(10);

	//Step 2.	VR = 15V 
	VR_dvi->set_current(VR_ch, 300e-3, RANGE_300_MA);	//Require >30mA else VR -> 10V, droop, then start rising with weird ramps
	VR_dvi->set_voltage(VR_ch, 15.0, VOLT_50_RANGE); // DVI_11_1
	wait.delay_10_us(200);

	//SDA,SCL = 3.3V via pullup resistor. Ready for I2C.
	SDA_ovi3->set_voltage(SDA_ch, 3.3, VOLT_10_RANGE); // OVI_3_0
	SCL_ovi3->set_voltage(SCL_ch, 3.3, VOLT_10_RANGE); // DVI_21_1
	wait.delay_10_us(50);
	
	//-----------------------------------------------------------------------------------------------------------------
	// Read Secondary Die ID  *START
	//------------------------------

	//Sometimes, DSM I2C can't be written correctly the first time.
	//Change the DSM timeout to 1ms since the default timeout is approximately 35ms.
	//g_Debug = 1;
	DSM_set_I2C_timeout(0, 1);

	//Step 3. Reading 2ndary Die ID.
	Secondary_DieID = DSM_I2C_Read(0x00);	//Read Die ID
	//g_Debug = 0;
	//----------------------------------------------------------------------------------------------------------------
	// Read Secondary Die ID  *END
	//-----------------------------------------------------------------------------------------------------------------

	//Step 4.  Enter test mode
    //4a.	0x00 0x5E write 0x16 0x20
	DSM_I2C_Write('w', 0x5E, 0x2016);
	//4b.	0x00 0x5E write 0x34 0x12
	DSM_I2C_Write('w', 0x5E, 0x1234);	

//pulse.do_pulse();

////////////			//////For TEST only..  Manually raise vFB above 2.5V or 3V here to observe HBP will go low and then lower to 1.25V for HSG to go High
////////////			//////Below to to make sure the FB controlling HBP is working properly before Disabling it.
////////////			////if(1)
////////////			////{
////////////			////	FB_ovi3->set_voltage(FB_ch, 2.00, VOLT_5_RANGE); // DVI_11_0
////////////			////	delay(1);
////////////			////	FB_ovi3->set_voltage(FB_ch, 2.25, VOLT_5_RANGE); // DVI_11_0
////////////			////	delay(1);
////////////			////	FB_ovi3->set_voltage(FB_ch, 2.50, VOLT_5_RANGE); // DVI_11_0
////////////			////	delay(1);
////////////			////	FB_ovi3->set_voltage(FB_ch, 2.75, VOLT_5_RANGE); // DVI_11_0
////////////			////	delay(1);
////////////			////	FB_ovi3->set_voltage(FB_ch, 3.00, VOLT_5_RANGE); // DVI_11_0	//1uF on HBP.  The drop is slow if it's only 3ms.  Manual observe drop to ~1.7V
////////////			////	delay(3);
////////////			////	FB_ovi3->set_voltage(FB_ch, 1.25, VOLT_5_RANGE); // DVI_11_0
////////////			////	delay(1);
////////////			////}

	//-----------------------------------------------------------------------------------------------------------------
	// Read Back EEprom for Secondary to determine if it's trimmed? *START
	//---------------------------------------------------------------------
	//Step 5.  Read back from 0xC0 to determine if it's trimmed or not.
	DSM_I2C_SREG0_0x7070();	//Get ready for any data to move to read address 0x00
	DSM_I2C_Read(0xC0);	//Read back data of Register addr 0xE0 from 0xC0 register address through READ_ADDR 0x00

	//If any bit of LowerByte of 0XC0 is not zero, then it's considered a virgin unit and secondary trim flag should be enabled.
	//If Virgin unit then proceed to erase EEprom.
	if(g_LowerByte != 0) g_s_Trim_Enable = 1;
	
	//-------------------------------------
	// Read Back EEprom for Secondary *END
	//-----------------------------------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------------------------------
	// Erase 2ndary EEprom *START
	//---------------------------------------------------------------------


	//-------------------------------------
	// Erase 2ndary EEprom *END
	//-----------------------------------------------------------------------------------------------------------------
	// Step 6.  Erase EEprom if it's untrimmed.
	if(g_s_Trim_Enable)
	{
////////////		//6a.	ZTMC_Drivers_en and ZTMC_Dsbl_FBshrt  (The FBshrt -> FB to HBP short fault protection function.)
////////////		//											  (This Test Mode disable 
////////////		//	i.	0x00 0x62 write 0x88 0x00
////////////		DSM_I2C_Write('w', 0x62, 0x0088);
////////////
////////////		//6b.	ZTMC_ana_EN and Core_en
////////////		//	i.	0x00 0x40 write 0x06 0x00
////////////		DSM_I2C_Write('w', 0x40, 0x0006);
////////////
////////////		//6c.	ZVtrim_comp (Comp out on HSG)
////////////		//	i.	0x00 0x46 write 0x00 0xB8
////////////		//	ii.	Note: If Comp out on HSG is not done rasing vFB above 2.5V/3V would bring HSG output down to ~2V and lower it to 1.25V would see HSG output ~11.5V
////////////		DSM_I2C_Write('w', 0x46, 0xB800);
////////////
////////////		
////////////		//6d.	0x00 0x5C write 0x03
////////////		DSM_I2C_Write('b', 0x5C, 0x03);
////////////
////////////		//6e.	ZTMC_ana_vprog_EN and ZTMC_ana_Vprog_2
////////////		//	i.	0x00 0x44 write 0x07 0x00
////////////		DSM_I2C_Write('w', 0x44, 0x0007);
////////////
////////////		//6f.	Raise VR pin voltage >24V until HSG pin toggles to complete Erase (DC voltage could determine toggle or not)
////////////		VR_dvi->set_current(VR_ch, 30e-3, RANGE_300_MA);
////////////		VR_dvi->set_voltage(VR_ch, 20.0, VOLT_50_RANGE); // DVI_11_1
////////////		delay(1);
////////////		HSG_ovi->set_meas_mode(HSG_ch, OVI_MEASURE_VOLTAGE, AUTORANGE);
////////////		i=0;
////////////		while (vVR_set < 28)
////////////		{
////////////			vVR_set = vVR_set + i*0.2;
////////////			VR_dvi->set_voltage(VR_ch, vVR_set, VOLT_50_RANGE); // DVI_11_1
////////////			wait.delay_10_us(10);
////////////			vHSG = HSG_ovi->measure_average(5);
////////////			if(vHSG > 2) //exit while loop
////////////			{
////////////				vVR_Erase_th = vVR_set+i*0.2;
////////////				break;
////////////			}
////////////			i++;
////////////		}
////////////
////////////		//6g.	Stop/End Erase EEprom
////////////		End_EEprom_Erase_Secondary();
	}
////////////	//---------------------------------
////////////	// Erase EEProm for Secondary *END
////////////	//-----------------------------------------------------------------------------------------------------------------


	//Not sure why there is a glitch on FW when powering down.
	FW_ovi3->set_voltage(FW_ch, 0.5, VOLT_5_RANGE); 

	//Powerdown Secondary.
	VR_dvi->set_voltage(VR_ch, 5.0, VOLT_50_RANGE); // DVI_11_1
	wait.delay_10_us(50);
	FB_ovi3->set_voltage(FB_ch, 0.0, VOLT_5_RANGE); // DVI_11_0
	wait.delay_10_us(50);
	SDA_ovi3->set_voltage(SDA_ch, 0.0, VOLT_5_RANGE); // OVI_3_0
	SCL_ovi3->set_voltage(SCL_ch, 0.0, VOLT_5_RANGE); // DVI_21_1
	FW_ovi3->set_voltage(FW_ch, 0.0, VOLT_5_RANGE); 
	wait.delay_10_us(50);

	

	VR_dvi->set_voltage(VR_ch, 0.0, VOLT_50_RANGE); // DVI_11_1
	wait.delay_10_us(100);

	//Open relays.
	//Disonnect Pullup R from TS and UV pins
	Open_relay(K1_TS_RB);
	Open_relay(K1_UV_RB);	
	//Connect Pullup R to SCL & SDA
	Open_relay(K1_SDA_SPI_TB);
	Open_relay(K1_SCL_SPI_TB);
	//Disconnect DSM CLK & Data from primary pins: TS & UV
	//Connect DSM CLK & Data to secondary:         SCL & SDA
	Open_relay(K1_DSM_TB);
	Open_relay(K3_DSM_TB);
	Open_relay(K2_DSM_TB);
	Open_relay(K4_DSM_TB);
	wait.delay_10_us(250);






////////////	//-------------------------------------------------------------------------------------
////////////	//---------- Secondary EEprom 'Read ID' &'Erase EEprom'  ------------------------------
////////////	//-------------------------------------------------------------------------------------
////////////	/*
////////////		Erase EEProm for Secondary
////////////		1.	vFB = 1.25V
////////////		2.	VR = 15V
////////////		3.	Test Mode Enable with Drivers_en, Dsbl_FBshrt, ana_EN, Core_En, Comp out on HSG
////////////			a.	0x00 0x5E write 0x16 0x20
////////////			b.	0x00 0x5E write 0x34 0x12
////////////			c.	ZTMC_Drivers_en and ZTMC_Dsbl_FBshrt
////////////				i.	0x00 0x62 write 0x88 0x00
////////////			d.	ZTMC_ana_EN and Core_en
////////////				i.	0x00 0x40 write 0x06 0x00
////////////			e.	ZVtrim_comp (Comp out on HSG)
////////////				i.	0x00 0x46 write 0x00 0xB8
////////////				ii.	Note: If Comp out on HSG is not done rasing vFB above 2.5V/3V would bring HSG output down to ~2V and lower it to 1.25V would see HSG output ~11.5V
///////////         4.  Read EEprom to see if it's trimmed.  If any bit is 1, then it's not trimmed unit.  Proceed to ERASE.

////////////		4.	Erase EEprom
////////////			a.	0x00 0x5C write 0x03
////////////			b.	ZTMC_ana_vprog_EN and ZTMC_ana_Vprog_2
////////////				i.	0x00 0x44 write 0x07 0x00
////////////			c.	Raise VR pin voltage >24V until HSG pin toggles to complete Erase (DC voltage could determine toggle or not)
////////////			d.	Stop/End Erase EEprom
////////////				i.	 0x00 0x5C write 0x00
////////////				ii.	 VR set to 15V 
////////////				iii. 0x00 0x44 write 0x00 0x00 --> bring internal supply back to 5V from 7V
////////////
////////////		Trim/Burn EEprom for Secondary
////////////		1.	vFB = 1.25V
////////////		2.	VR = 15V
////////////		3.	Test Mode Enable with Drivers_en, Dsbl_FBshrt, ana_EN, Core_En, Comp out on HSG
////////////			a.	0x00 0x5E write 0x16 0x20
////////////			b.	0x00 0x5E write 0x34 0x12
////////////			c.	ZTMC_Drivers_en and ZTMC_Dsbl_FBshrt
////////////				i.	0x00 0x62 write 0x88 0x00
////////////			d.	ZTMC_ana_EN and Core_en
////////////				i.	0x00 0x40 write 0x06 0x00
////////////			e.	ZVtrim_comp (Comp out on HSG)
////////////				i.	0x00 0x46 write 0x00 0xB8
////////////				ii.	Note: If Comp out on HSG is not done rasing vFB above 2.5V/3V would bring HSG output down to ~2V and lower it to 1.25V would see HSG output ~11.5V
////////////		4.	Program any trim code to EEprom register
////////////			a.	E0 write 	E0 ??D[15:0]
////////////			b.	E2 write 	E0 ??D[31:16]
////////////			c.	E4 write 	E0 ??D[17:32]
////////////			d.	E6 write 	E0 ??D[63:48]
////////////			e.	E8 write 	E0 ??D[79:64]
////////////		5.	Burn to EEprom Cell
////////////			a.	Write whats programmed to the EEprom register to EEprom Cell.
////////////				i.	0x00 0x5C write 0x01
////////////			b.	ZTMC_ana_Vprog_En and ZTMC_trim_EN_vDDA
////////////				i.	0x00 0x44 write 0x05 0x00
////////////			c.	Raise VR > 18V until HSG is toggling to burn programmed trimcodes to EEprom cell.  (DC voltage to determine switching or not)
////////////
////////////		Pins involved for Secondary EEprom:
////////////			FB, BPS, VR, HSG, SDA(SET), SCL(DIM)
////////////
////////////		What to expect with VR set to 15V
////////////			BPS regulated to 3.3V internally
////////////			HSG regulated to 11.5V internally
////////////	*/
////////////
////////////	//Disconnect DSM from Primary.
////////////	mux_14->open_relay(MUX_1_1);
////////////	mux_14->open_relay(MUX_1_3);
////////////	delay(1);
////////////
////////////	//Secondary I2C to ready Secondary Die ID.
////////////	//Disconnect DVI_13 from HBP.
////////////	dvi_13->disconnect(CONN_FORCE0);
//////////////	dvi_13->disconnect(CONN_SENSE0);
////////////	delay(5);
////////////
////////////	//SDA & SCL set to 0V
////////////	//SDA = 0V via pullup resistor. Ready for I2C.
////////////	SDA_ovi3->set_current(SDA_ch, 10e-3, RANGE_30_MA);
////////////	SDA_ovi3->set_voltage(SDA_ch, 0.0, VOLT_10_RANGE); // OVI_3_0
////////////
////////////	//SCL = 0V via pullup resistor. Ready for I2C.
////////////	SCL_ovi3->set_current(SCL_ch, 10e-3, RANGE_30_MA);
////////////	SCL_ovi3->set_voltage(SCL_ch, 0.0, VOLT_10_RANGE); // DVI_21_1
////////////
////////////	//Connect DSM CLK & Data to Secondary pins: SDA & SCL
////////////	mux_14->close_relay(MUX_1_2);	//SDA	K2_DSM
////////////	mux_14->close_relay(MUX_1_4);	//SCL	K4_DSM
////////////	delay(5);
////////////
////////////	//1.	vFB = 1.25V
////////////	FB_ovi3->set_current(FB_ch, 30e-3, RANGE_30_MA);
////////////	FB_ovi3->set_voltage(FB_ch, 1.25, VOLT_5_RANGE); // DVI_11_0
////////////	delay(1);
////////////
////////////	//2.	VR = 15V (20V from Hang)
////////////	VR_dvi->set_current(VR_ch, 300e-3, RANGE_300_MA);	//Require >30mA else VR -> 10V, droop, then start rising with weird ramps
////////////	VR_dvi->set_voltage(VR_ch, 15.0, VOLT_50_RANGE); // DVI_11_1
////////////	delay(10);
////////////
////////////	//Need to close K1_SDA.  Manually short due to SPI relay driver issues.
////////////
////////////	//SDA,SCL = 3.3V via pullup resistor. Ready for I2C.
////////////	SDA_ovi3->set_voltage(SDA_ch, 3.3, VOLT_10_RANGE); // OVI_3_0
////////////	SCL_ovi3->set_voltage(SCL_ch, 3.3, VOLT_10_RANGE); // DVI_21_1
////////////	delay(5);
////////////	
////////////	//-----------------------------------------------------------------------------------------------------------------
////////////	// Read Secondary Die ID  *START
////////////	//------------------------------
////////////	if(1)
////////////	{
////////////		DSM_I2C_Read(0x00);	//Read Die ID
////////////	}
////////////	//------------------------------
////////////	// Read Secondary Die ID  *END
////////////	//-----------------------------------------------------------------------------------------------------------------
////////////
////////////
////////////
////////////	//-----------------------------------------------------------------------------------------------------------------
////////////	// TestMode Secondary *START
////////////	//------------------------------
////////////	if(1)
////////////	{
////////////		//3a.	0x00 0x5E write 0x16 0x20
////////////		DSM_I2C_Write('w', 0x5E, 0x2016);	
////////////
////////////		//3b.	0x00 0x5E write 0x34 0x12
////////////		DSM_I2C_Write('w', 0x5E, 0x1234);	
////////////
////////////			//////For TEST only..  Manually raise vFB above 2.5V or 3V here to observe HBP will go low and then lower to 1.25V for HSG to go High
////////////			//////Below to to make sure the FB controlling HBP is working properly before Disabling it.
////////////			////if(1)
////////////			////{
////////////			////	FB_ovi3->set_voltage(FB_ch, 2.00, VOLT_5_RANGE); // DVI_11_0
////////////			////	delay(1);
////////////			////	FB_ovi3->set_voltage(FB_ch, 2.25, VOLT_5_RANGE); // DVI_11_0
////////////			////	delay(1);
////////////			////	FB_ovi3->set_voltage(FB_ch, 2.50, VOLT_5_RANGE); // DVI_11_0
////////////			////	delay(1);
////////////			////	FB_ovi3->set_voltage(FB_ch, 2.75, VOLT_5_RANGE); // DVI_11_0
////////////			////	delay(1);
////////////			////	FB_ovi3->set_voltage(FB_ch, 3.00, VOLT_5_RANGE); // DVI_11_0	//1uF on HBP.  The drop is slow if it's only 3ms.  Manual observe drop to ~1.7V
////////////			////	delay(3);
////////////			////	FB_ovi3->set_voltage(FB_ch, 1.25, VOLT_5_RANGE); // DVI_11_0
////////////			////	delay(1);
////////////			////}
////////////	}
////////////	//------------------------------
////////////	// TestMode Secondary *END
////////////	//----------------------------------------------------------------------------------------------------------------
////////////int Secondary_Erase_Trim = 0;
////////////	//-----------------------------------------------------------------------------------------------------------------
////////////	// Erase EEProm for Secondary *START
////////////	//-----------------------------------
////////////	float vVR_set=20, vHSG=0;
////////////	float vVR_Erase_th=0, vVR_Burn_th=0;
////////////	if(Secondary_Erase_Trim)
////////////	{
////////////		//3c.	ZTMC_Drivers_en and ZTMC_Dsbl_FBshrt  (The FBshrt -> FB to HBP short fault protection function.)
////////////		//											  (This Test Mode disable 
////////////		//	i.	0x00 0x62 write 0x88 0x00
////////////		DSM_I2C_Write('w', 0x62, 0x0088);
////////////
////////////		//3d.	ZTMC_ana_EN and Core_en
////////////		//	i.	0x00 0x40 write 0x06 0x00
////////////		DSM_I2C_Write('w', 0x40, 0x0006);
////////////
////////////		//3e.	ZVtrim_comp (Comp out on HSG)
////////////		//	i.	0x00 0x46 write 0x00 0xB8
////////////		//	ii.	Note: If Comp out on HSG is not done rasing vFB above 2.5V/3V would bring HSG output down to ~2V and lower it to 1.25V would see HSG output ~11.5V
////////////		DSM_I2C_Write('w', 0x46, 0xB800);
////////////
////////////		//4. Erase EEprom
////////////		//4a.	0x00 0x5C write 0x03
////////////		DSM_I2C_Write('b', 0x5C, 0x03);
////////////
////////////		//4b.	ZTMC_ana_vprog_EN and ZTMC_ana_Vprog_2
////////////		//	i.	0x00 0x44 write 0x07 0x00
////////////		DSM_I2C_Write('w', 0x44, 0x0007);
////////////
////////////		//4c.	Raise VR pin voltage >24V until HSG pin toggles to complete Erase (DC voltage could determine toggle or not)
////////////		VR_dvi->set_current(VR_ch, 30e-3, RANGE_300_MA);
////////////		VR_dvi->set_voltage(VR_ch, 20.0, VOLT_50_RANGE); // DVI_11_1
////////////		delay(1);
////////////		HSG_ovi->set_meas_mode(HSG_ch, OVI_MEASURE_VOLTAGE, AUTORANGE);
////////////		i=0;
////////////		while (vVR_set < 28)
////////////		{
////////////			vVR_set = vVR_set + i*0.2;
////////////			VR_dvi->set_voltage(VR_ch, vVR_set, VOLT_50_RANGE); // DVI_11_1
////////////			wait.delay_10_us(10);
////////////			vHSG = HSG_ovi->measure_average(5);
////////////			if(vHSG > 2) //exit while loop
////////////			{
////////////				vVR_Erase_th = vVR_set+i*0.2;
////////////				break;
////////////			}
////////////			i++;
////////////		}
////////////
////////////		//4d.	Stop/End Erase EEprom
////////////		End_EEprom_Erase_Secondary();
////////////		
////////////		
////////////		////DSM_I2C_Write2('b', 0x5C, 0x00);					//	i.	 0x00 0x5C write 0x00
////////////		////VR_dvi->set_voltage(VR_ch, 15.0, VOLT_50_RANGE);	//	ii.	 VR set to 15V (optional)
////////////		////delay(5);
////////////		////DSM_I2C_Write2('w', 0x44, 0x0000);					//	iii. 0x00 0x44 write 0x00 0x00 --> bring internal supply back to 5V from 7V
////////////
////////////	}
////////////	//---------------------------------
////////////	// Erase EEProm for Secondary *END
////////////	//-----------------------------------------------------------------------------------------------------------------
////////////
////////////
////////////	//-----------------------------------------------------------------------------------------------------------------
////////////	// Trim/Burn EEprom for Secondary *START
////////////	//---------------------------------------
////////////	if(Secondary_Erase_Trim)
////////////	{
////////////		uint16_t D15_0, D31_16, D47_32, D63_48, D79_64;
////////////		D15_0  = 0x0000;
////////////		D31_16 = 0x001C; //Trim Bit 18,19 & 20 per design request. Upper Byte = 0x00, Lower Byte 0x1C
////////////		D47_32 = 0x0000;
////////////		D63_48 = 0x0000;
////////////		D79_64 = 0x0000;
////////////		//Since the previous I2C commands were just ERASE, we can continue without going through steps 1 to 3 like above.
////////////
////////////		//4a to 4e.  Program any trim code to EEprom registers
////////////			DSM_I2C_Write('w', 0xE0, D15_0);	//4a. E0 <--> D[15:0]
////////////			DSM_I2C_Write('w', 0xE2, D31_16);	//4b. E2 <--> D[31:16]
////////////			DSM_I2C_Write('w', 0xE4, D47_32);	//4c. E4 <--> D[47:32]
////////////			DSM_I2C_Write('w', 0xE6, D63_48);	//4d. E6 <--> D[63:48]
////////////			DSM_I2C_Write('w', 0xE8, D79_64);	//4e. E8 <--> D[79:64]
////////////		//5a. Write whats programmed to the EEprom register to EEprom Cell.	(0x00 0x5C write 0x01)
////////////			DSM_I2C_Write('b', 0x5C, 0x01);
////////////		//5b. ZTMC_ana_Vprog_En and ZTMC_trim_EN_vDDA	(0x00 0x44 write 0x05 0x00)
////////////			DSM_I2C_Write('w', 0x44, 0x0005);
////////////		//5c. Raise VR > 18V until HSG is toggling to burn programmed trimcodes to EEprom cell.  
////////////		//											(DC voltage to determine switching or not) 
////////////			VR_dvi->set_voltage(VR_ch, 15.0, VOLT_50_RANGE); // DVI_11_1
////////////			delay(1);
////////////			HSG_ovi->set_meas_mode(HSG_ch, OVI_MEASURE_VOLTAGE, AUTORANGE);
////////////			vVR_set=15;
////////////			vHSG=0;
////////////			i=0;
////////////			while (vVR_set < 21)
////////////			{
////////////				vVR_set = vVR_set + i*0.2;
////////////				VR_dvi->set_voltage(VR_ch, vVR_set, VOLT_50_RANGE); // DVI_11_1
////////////				wait.delay_10_us(10);
////////////				vHSG = HSG_ovi->measure_average(5);
////////////				if(vHSG > 2) //exit while loop
////////////				{
////////////					vVR_Burn_th = vVR_set+i*0.2;
////////////					break;
////////////				}
////////////				i++;
////////////			}
////////////		//5d. Stop/End Burn EEprom
////////////			//i.  0x00 0x5C write 0x00
////////////			DSM_I2C_Write('b', 0x5C, 0x00);
////////////			//ii. 0x00 0x44 write 0x00 0x00 --> bring internal supply back to 5V from 7V
////////////			DSM_I2C_Write('w', 0x44, 0x0000);
////////////	}
////////////	//-------------------------------------
////////////	// Trim/Burn EEprom for Secondary *END
////////////	//-----------------------------------------------------------------------------------------------------------------
////////////
////////////
////////////	//-----------------------------------------------------------------------------------------------------------------
////////////	// Read Back EEprom for Secondary *START
////////////	//---------------------------------------
////////////	if(1)
////////////	{
////////////		DSM_I2C_SREG0_0x7070();	//Get ready for any data to move to read address 0x00
////////////		//DSM_I2C_Read(0xC0);	//Read back data of Register addr 0xE0 from 0xC0 register address through READ_ADDR 0x00
////////////		g_Debug = 1;
////////////		DSM_I2C_Read(0xC2);	//Read back data of Register addr 0xE2 from 0xC2 register address through READ_ADDR 0x00
////////////		g_Debug = 0;
////////////		//DSM_I2C_Read(0xC4);	//Read back data of Register addr 0xE4 from 0xC4 register address through READ_ADDR 0x00
////////////		//DSM_I2C_Read(0xC6);	//Read back data of Register addr 0xE6 from 0xC6 register address through READ_ADDR 0x00
////////////		//DSM_I2C_Read(0xC8);	//Read back data of Register addr 0xE8 from 0xC8 register address through READ_ADDR 0x00
////////////		//DSM_I2C_Pri_Read(0xC2);
////////////	}
////////////	//-------------------------------------
////////////	// Read Back EEprom for Secondary *END
////////////	//-----------------------------------------------------------------------------------------------------------------
////////////
////////////
////////////	//Power Down from Secondary use
////////////	//SDA,SCL = 0.0V via pullup resistor. Ready for I2C.
////////////	SDA_ovi3->set_voltage(SDA_ch, 0.0, VOLT_10_RANGE); // OVI_3_0
////////////	SCL_ovi3->set_voltage(SCL_ch, 0.0, VOLT_10_RANGE); // DVI_21_1
////////////	//VR=0V
////////////	VR_dvi->set_voltage(VR_ch, 0.0, VOLT_50_RANGE); // DVI_11_1
////////////	//FB=0V
////////////	FB_ovi3->set_voltage(FB_ch, 0.0, VOLT_5_RANGE); // DVI_11_0
////////////	delay(1);
////////////	//Disconnect DSM CLK & Data from Secondary pins: SDA & SCL
////////////	mux_14->open_relay(MUX_1_2);	//SDA	K2_DSM
////////////	mux_14->open_relay(MUX_1_4);	//SCL	K4_DSM
////////////	delay(5);




}
