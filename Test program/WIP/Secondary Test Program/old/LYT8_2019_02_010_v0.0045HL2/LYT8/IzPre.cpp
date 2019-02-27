//==============================================================================
// IzPre.cpp (User function)
// 
//    void IzPre_user_init(test_function& func)
//    void IzPre(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)
#include "IzPre.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void IzPre_user_init(test_function& func)
{
	IzPre_params *ours;
    ours = (IzPre_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void IzPre(test_function& func)
{
    // The two lines below must be the first two in the function.
    IzPre_params *ours;
    ours = (IzPre_params *)func.params;

	// Increment function number //
	gFuncNum++;

////	// Datalog gFuncNum variable //
////	if(gDisplay_FuncNum)
////		PiDatalog(func, A_Func_Num_IZpre, gFuncNum, 8, POWER_UNIT);
////
////	// Skip Test if AbortTest set //
////	if (AbortTest)
////		return;
////
////	// Don't test at hot //
//////	if (g_OPCODE==4300 ||g_OPCODE==4500)
//////		return;
////
////	if (g_Fn_IzPre == 0 )  return;
////
////	// Test Time Begin //
////	 if (g_p_TstTime_Enble)
////	 	g_begintime = g_mytimer.GetElapsedTime();
////	
////	// Test Names //
////	// Primary //
////	float Izpt_iov1_p =0.0;		
////	float Izpt_iov2_p =0.0;	
////	float Izpt_iov3_p =0.0;		
////	float Izpt_iov4_p =0.0;
////	float Izpt_iovSign_p =0.0;
////	float Izpt_iL1_p =0.0;		
////	float Izpt_iL2_p =0.0;			
////	float Izpt_iL3_p =0.0;			
////	float Izpt_iLsign_p =0.0;
////	float Izpt_tOVL1_p =0.0;		
////	float Izpt_tOVL2_p =0.0;		
////	float Izpt_tOVLSign_p =0.0;
////	float Izpt_f1_p =0.0;	
////	float Izpt_f2_p =0.0;			
////	float Izpt_fSign_p =0.0;
////	float Izpt_iov_Off_p =0.0; 
////	float Izpt_iuvMinus_p =0.0;
////	float Izpt_uvDelay_p =0.0;
////	float Izpt_Loff_AR_p =0.0;
////	float Izpt_DisablAR_p =0.0;
////	float Izpt_didtComp_p =0.0;
////	float Izpt_OT_Hys_p =0.0;
////	float Izpt_LoffwOT_p =0.0;
////	float Izpt_iLselOff_p =0.0;	
////	float Izpt_iLStdIcr_p =0.0;
////	float Izpt_iL20dn_p =0.0;	
////	float Izpt_iL20up_p =0.0;
////	float Izpt_SAM_p =0.0;
////	float Izpt_OTP1_p =0.0;		
////	float Izpt_OTP2_p =0.0;		
////	float Izpt_OTP3_p =0.0;
////	float Izpt_SDSoff_p =0.0;
////	float Izpt_Rcv1_p =0.0;	
////	float Izpt_Rcv2_p =0.0;		
////	float Izpt_RcvSign_p =0.0;
////	float Izpt_drvSize1_p =0.0;	
////	float Izpt_drvSize2_p =0.0;	
////	float Izpt_drvSize3_p =0.0;	
////	float Izpt_drvSize4_p =0.0;
////	float Izpt_RsenseUp_p =0.0;
////	float Izpt_vxAdj1_p =0.0;	
////	float Izpt_vxAdj2_p =0.0;		
////	float Izpt_vxAdj3_p =0.0;		
////	float Izpt_vxAdj4_p =0.0;		
////	float Izpt_vxAdj5_p =0.0;
////	float Izpt_iLRatio1_p =0.0;	
////	float Izpt_iLRatio2_p =0.0;	
////	float Izpt_iLRatio3_p =0.0;	
////	float Izpt_iLRatio4_p =0.0;
////	float Izpt_iLTC1_p =0.0;		
////	float Izpt_iLTC2_p =0.0;		
////	float Izpt_iLTC3_p =0.0;		
////	float Izpt_iLTC4_p =0.0;
////	float Izpt_ARreq_p =0.0;
////	float Izpt_ZF_p =0.0;
////
////	// Test Names //
////	// Secondary //
////	int EEpt_F1_S =0;
////	int EEpt_F2_S =0;
////	int EEpt_F3_S =0;
////	int EEpt_F_Iint1_S =0;
////	int EEpt_F_Iint2_S =0;
////	int EEpt_F_Iint3_S =0;
////	int EEpt_F_Iint4_S =0;
////	int EEpt_PKspdLd_S =0;
////	int EEpt_CV1_S =0;
////	int EEpt_VesrAdp_S =0;
////	int EEpt_ISvth3X1_S =0;
////	int EEpt_ISvth3X2_S =0;
////	int EEpt_ISvth3X3_S =0;
////	int EEpt_ISvth3X4_S =0;
////	int EEpt_ISvth3X5_S =0;
////	int EEpt_ISvth3X6_S =0;
////	int EEpt_CDC1_S =0;
////	int EEpt_CDC2_S =0;
////	int EEpt_CDC3_S =0;
////	int EEpt_CV2_S =0;
////	int EEpt_CV3_S =0;
////	int EEpt_CV4_S =0;
////	int EEpt_CV5_S =0;
////	int EEpt_CV6_S =0;
////	int EEpt_OSC0_S =0;
////	int EEpt_OSC1_S =0;
////	int EEpt_OSC2_S =0;
////	int EEpt_OSC3_S =0;
////	int EEpt_nDAC1_S =0;
////	int EEpt_nDAC2_S =0;
////	int EEpt_nDAC3_S =0;
////	int EEpt_nDAC4_S =0;
////	int EEpt_nDAC5_S =0;
////	int EEpt_pDAC1_S =0;
////	int EEpt_pDAC2_S =0;
////	int EEpt_pDAC3_S =0;
////	int EEpt_pDAC4_S =0;
////	int EEpt_pDAC5_S =0;
////	int EEpt_DofA1_S =0;
////	int EEpt_DofA2_S =0;
////	int EEpt_DofA3_S =0;
////	int EEpt_DofA4_S =0;
////	int EEpt_DofA5_S =0;
////	int EEpt_IsDAC1_S =0;
////	int EEpt_IsDAC2_S =0;
////	int EEpt_IsDAC3_S =0;
////	int EEpt_IsDAC4_S =0;
////	int EEpt_IsDAC5_S =0;
////	int EEpt_Gain1_S =0;
////	int EEpt_Gain2_S =0;
////	int EEpt_Gain3_S =0;
////	int EEpt_Gain4_S =0;
////	int EEpt_CCoff1_S =0;
////	int EEpt_CCoff2_S =0;
////	int EEpt_CCoff3_S =0;
////	int EEpt_IsCal1_S =0;
////	int EEpt_IsCal2_S =0;
////	int EEpt_IsCal3_S =0;
////	int EEpt_DsoftEn_S =0;
////	int EEpt_DOPL_S =0;
////	int EEpt_CCAR_S =0;
////	int EEpt_DoplEnCp_S = 0;
////	int EEpt_ESRsel_S =0;
////	int EEpt_DdampEn_S =0;
////	int Izpt_Trimmed =0;
////	int EEpt_SiOption_s =0;
////	/*
////	int EEpt_ShadReg0 =0;
////	int EEpt_ShadReg1 =0;
////	int EEpt_ShadReg2 =0;
////	int EEpt_ShadReg3 =0;
////	int EEpt_ShadReg4 =0;
////	int EEpt_ShadReg5 =0;
////	int EEpt_ShadReg6 =0;
////	int EEpt_ShadReg7 =0;
////	int EEpt_ShadReg8 =0;
////	int EEpt_ShadReg9 =0;
////	int EEpt_ShadReg10 =0;
////	int EEpt_ShadReg11 =0;
////	int EEpt_ShadReg12 =0;
////	int EEpt_ShadReg13 =0;
////	int EEpt_ShadReg14 =0;
////	int EEpt_ShadReg15 =0;
////	int EEpt_ShadReg16 =0;
////	int EEpt_ShadReg17 =0;
////	int EEpt_ShadReg18 =0;
////	int EEpt_ShadReg19 =0;
////	int EEpt_ShadReg20 =0;
////	int EEpt_ShadReg21 =0;
////	int EEpt_ShadReg22 =0;
////	int EEpt_ShadReg23 =0;
////	int EEpt_ShadReg24 =0;
////	int EEpt_ShadReg25 =0;
////	int EEpt_ShadReg26 =0;
////	int EEpt_ShadReg27 =0;
////	int EEpt_ShadReg28 =0;
////	int EEpt_ShadReg29 =0;
////	int EEpt_ShadReg30 =0;
////	int EEpt_ShadReg31 =0;
////	int EEpt_ShadReg32 =0;
////	int EEpt_ShadReg33 =0;
////	int EEpt_ShadReg34 =0;
////	int EEpt_ShadReg35 =0;
////	int EEpt_ShadReg36 =0;
////	int EEpt_ShadReg37 =0;
////	int EEpt_ShadReg38 =0;
////	int EEpt_ShadReg39 =0;
////	int EEpt_ShadReg40 =0;
////	int EEpt_ShadReg41 =0;
////	int EEpt_ShadReg42 =0;
////	int EEpt_ShadReg43 =0;
////	int EEpt_ShadReg44 =0;
////	int EEpt_ShadReg45 =0;
////	int EEpt_ShadReg46 =0;
////	int EEpt_ShadReg47 =0;
////	int EEpt_ShadReg48 =0;
////	int EEpt_ShadReg49 =0;
////	int EEpt_ShadReg50 =0;
////	int EEpt_ShadReg51 =0;
////	int EEpt_ShadReg52 =0;
////	int EEpt_ShadReg53 =0;
////	int EEpt_ShadReg54 =0;
////	int EEpt_ShadReg55 =0;
////	int EEpt_ShadReg56 =0;
////	int EEpt_ShadReg57 =0;
////	int EEpt_ShadReg58 =0;
////	int EEpt_ShadReg59 =0;
////	int EEpt_ShadReg60 =0;
////	int EEpt_ShadReg61 =0;
////	int EEpt_ShadReg62 =0;
////	// int EEpt_ShadReg63 =0; // Using global variable g_EEpt_ShadReg63 instead.  bit[63]: trim_no_fb_pin //
////	int EEpt_ShadReg64 =0;
////	int EEpt_ShadReg65 =0;
////	int EEpt_ShadReg66 =0;
////	int EEpt_ShadReg67 =0;
////	int EEpt_ShadReg68 =0;
////	int EEpt_ShadReg69 =0;
////	int EEpt_ShadReg70 =0;
////	int EEpt_ShadReg71 =0;
////	int EEpt_ShadReg72 =0;
////	int EEpt_ShadReg73 =0;
////	int EEpt_ShadReg74 =0;
////	int EEpt_ShadReg75 =0;
////	int EEpt_ShadReg76 =0;
////	int EEpt_ShadReg77 =0;
////	int EEpt_ShadReg78 =0;
////	int EEpt_ShadReg79 =0;
////	int EEpt_ShadReg80 =0;
////	int EEpt_ShadReg81 =0;
////	int EEpt_ShadReg82 =0;
////	int EEpt_ShadReg83 =0;
////	int EEpt_ShadReg84 =0;
////	int EEpt_ShadReg85 =0;
////	int EEpt_ShadReg86 =0;
////	int EEpt_ShadReg87 =0;
////	int EEpt_ShadReg88 =0;
////	int EEpt_ShadReg89 =0;
////	int EEpt_ShadReg90 =0;
////	int EEpt_ShadReg91 =0;
////	int EEpt_ShadReg92 =0;
////	int EEpt_ShadReg93 =0;
////	int EEpt_ShadReg94 =0;
////	int EEpt_ShadReg95 =0;
////	int EEpt_ShadReg96 =0;
////	int EEpt_ShadReg97 =0;
////	int EEpt_ShadReg98 =0;
////	int EEpt_ShadReg99 =0;
////	int EEpt_ShadReg100 =0;
////	int EEpt_ShadReg101 =0;
////	int EEpt_ShadReg102 =0;
////	int EEpt_ShadReg103 =0;
////	//int EEpt_ShadReg104 =0; // Using global variable g_EEpt_ShadReg104 instead.  eep_sreg[104]: trim_ldo_3p6v //
////	int EEpt_ShadReg105 =0;
////	int EEpt_ShadReg106 =0;
////	int EEpt_ShadReg107 =0;
////	int EEpt_ShadReg108 =0;
////	int EEpt_ShadReg109 =0;
////	int EEpt_ShadReg110 =0;
////	int EEpt_ShadReg111 =0;
////	*/
////	float IZpre_TT =0;
////
////	// Declare Variables //
////	int NObin[1] = {0}; // Place holder //
////	int NOhex = 0; // Place holder //
////	int WordArray[16] = {0};
////	int TempArray[30] = {0};
////	int READ0_word[16] = {0};
////	int READ1_word[16] = {0};
////	int READ2_word[16] = {0};
////	int READ3_word[16] = {0};
////	int READ4_word[16] = {0};
////	int READ5_word[16] = {0};
////	int READ6_word[16] = {0};
////	int READ7_word[16] = {0};
////	int READ8_word[16] = {0};
////	int READ9_word[16] = {0};
////	int READ10_word[16] = {0};
////	int READ11_word[16] = {0};
////	int READ12_word[16] = {0};
////	int READ13_word[16] = {0};
////	int READ14_word[16] = {0};
////	int READ15_word[16] = {0};
////	int READ16_word[16] = {0};
////	int READ17_word[16] = {0};
////	int READ18_word[16] = {0};
////	int READ19_word[16] = {0};
////	int READ56_word[16] = {0};
////	int READ57_word[16] = {0};
////	int READ58_word[16] = {0};
////	int READ59_word[16] = {0};
////	int READ60_word[16] = {0};
////	int READ61_word[16] = {0};
////	int READ62_word[16] = {0};
////	float iAFp_th =0.0;
////	float iAF_array_p[100] = {0};
////	float iAF_min_p = 999;
////	float iAF_max_p = -99;
////	int addr =0;
////	int Total_Addr_Count_p=0;
////	int i=0; 
////	int Trimmed_P=0;
////	int Trimmed_S=0; 
////	int readTime=0;
////	//int rev_id_Byte[8] = {0};
////	int rev_id_Word[16] = {0};
////	int EEPROM_Erase = 0;
////	float Vforce = 0;
////	int ReadResult[112] = {0};
////
////	//Pulse pulse(PULSE_RISING_EDGE,10e-6); // external trigger pulse from dvi for debug
////	Pulse pulse; // external trigger pulse from dvi for debug
////
////	//readTime = 5; // x*10us => 100us if readTime = 10
////	readTime = 10; // x*10us => 100us if readTime = 10
////	iAFp_th = 300e-6; // Threshold use to determine if Primary   is trimmed or not.  If trimmed, iAFp ~= 500uA
////
////	VBPP_Negative_Cycle();
////
////	// Open all relays //
////	Initialize_Relays();
////
////	// Initialize Instruments //
////	Initialize_Instruments();
////
////	// Setup Vout to connect to DDD7_4 and have DDD7_4 toggle to stay LOW to start with
////	VO_dvi->open_relay(CONN_FORCE0);
////	VO_dvi->open_relay(CONN_SENSE0);
////
////	ovi_1->disconnect(OVI_CHANNEL_1); // Vpin does not use ovi-1-1 for Iz function
////
////	// Initialize DDD
////	// DDD level //
////	g_DDD_Low = 0.0; // Save current value //
////	g_DDD_High = 4.0; // Save current value //
////	wait.delay_10_us(g_DDDwait);
////	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////	wait.delay_10_us(g_DDDwait);
////	ddd_7->ddd_run_pattern(Low_pat_start,Low_pat_stop);
////	wait.delay_10_us(10);
////	Close_relay(K2); // Primary: Connect DVI11_0 to Drain pin
////	Close_relay(K12); // Primary: Connect DDD7_1 to Vpin(UV) pin
//////	Close_relay(K18); // Secondary: Connect DVI11_1 to FB pin
//////	Close_relay(K27); // Secondary: Connect DDD7_4 to Vout pin (Inno4)
////	delay(4); // 4 ms delay is necessary to wait for DDD to settle down before powering up BPP pin to avoid mis-clocking
////
////	// Power Up Primary
////	Powerup_Primary_in_Testmode(gWrite_Mode_ReadAF);
////	D_dvi->set_meas_mode(D_ch, DVI_MEASURE_CURRENT);
////
////	Total_Addr_Count_p = 55;
////
////	// Read Primary
////	for (i = 1; i<=Total_Addr_Count_p; i++) // Primary: First clock count at address 4
////	{
////		// Require more wait time for the first AF link
////		if(i==1)	
////			wait.delay_10_us(70);
////		
////		addr=i;
////		DDD_Clock_UV_Antifuse(1); // Vpin(UV) clock through all AF links one by one
////
////		// Vpin assert and deassert for the selected anti-fuse link with vDrain at Trim voltage
////		ddd_7->ddd_run_pattern(AF_Vpin_Data_pulse_start, AF_Vpin_Data_pulse_stop);	//Assert   data pulse 
////		wait.delay_10_us(readTime);
////		iAF_array_p[addr] = D_dvi->measure_average(5);
////		ddd_7->ddd_run_pattern(AF_Vpin_Data_pulse_start, AF_Vpin_Data_pulse_stop);	//Deassert data pulse 
////		wait.delay_10_us(3);
////
////		if (iAF_array_p[addr] > iAFp_th)		// Trimmed if > 0.1mA
////			Trimmed_P += 1;
////	}
////
////	// Observe mode to identify device ID and other features that designers are interested in for Primary Controller
//////	Observe_Vpin_Internal_Signals();
////
////	// Power Down //
////	D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
////	D_dvi->set_current(D_ch, 300e-3, RANGE_300_MA); // DVI_11_0 //
////	VBPP_ramp_down(3, 0.0, 0.05);
////	Open_relay(K12);
////	Open_relay(K2); // Primary: Connect DVI11_0 to Drain pin
////	VO_dvi->close_relay(CONN_FORCE0);
////	VO_dvi->close_relay(CONN_SENSE0);
////	VPIN_ovi->connect(VPIN_ch); // OVI_1_1 //
////	VPIN_ovi->set_voltage(VPIN_ch, 0, RANGE_10_V); // OVI_1_1 //
////	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //
////	ddd_7->ddd_run_pattern(Low_pat_start,Low_pat_stop);
////	
////	// Antifuse current results
////	// Primary
////    Izpt_iov1_p		=iAF_array_p[1];
////	Izpt_iov2_p		=iAF_array_p[2];
////	Izpt_iov3_p		=iAF_array_p[3]; 
////	Izpt_iov4_p		=iAF_array_p[4]; 
////	Izpt_iovSign_p	=iAF_array_p[5]; 
////	Izpt_iL1_p		=iAF_array_p[6];
////	Izpt_iL2_p		=iAF_array_p[7];
////	Izpt_iL3_p		=iAF_array_p[8]; 
////	Izpt_iLsign_p	=iAF_array_p[9]; 
////	Izpt_tOVL1_p	=iAF_array_p[10];
////	Izpt_tOVL2_p	=iAF_array_p[11];
////	Izpt_tOVLSign_p	=iAF_array_p[12]; 
////	Izpt_f1_p		=iAF_array_p[13];  
////	Izpt_f2_p		=iAF_array_p[14];
////	Izpt_fSign_p	=iAF_array_p[15];
////	Izpt_iov_Off_p	=iAF_array_p[16];
////	Izpt_iuvMinus_p	=iAF_array_p[17];
////	Izpt_uvDelay_p	=iAF_array_p[18];
////	Izpt_Loff_AR_p	=iAF_array_p[19];
////	Izpt_DisablAR_p	=iAF_array_p[20];
////	Izpt_didtComp_p	=iAF_array_p[21];
////	Izpt_OT_Hys_p	=iAF_array_p[22];
////	Izpt_LoffwOT_p	=iAF_array_p[23];
////	Izpt_iLselOff_p	=iAF_array_p[24];
////	Izpt_iLStdIcr_p	=iAF_array_p[25];
////	Izpt_iL20dn_p	=iAF_array_p[26];
////	Izpt_iL20up_p	=iAF_array_p[27];
////	Izpt_SAM_p		=iAF_array_p[28];
////	Izpt_OTP1_p		=iAF_array_p[29];
////	Izpt_OTP2_p		=iAF_array_p[30];
////	Izpt_OTP3_p		=iAF_array_p[31];
////	Izpt_SDSoff_p	=iAF_array_p[32];
////	Izpt_Rcv1_p		=iAF_array_p[33];
////	Izpt_Rcv2_p		=iAF_array_p[34];
////	Izpt_RcvSign_p	=iAF_array_p[35];
////	Izpt_drvSize1_p	=iAF_array_p[36];
////	Izpt_drvSize2_p	=iAF_array_p[37];
////	Izpt_drvSize3_p	=iAF_array_p[38];
////	Izpt_drvSize4_p	=iAF_array_p[39];
////	Izpt_RsenseUp_p	=iAF_array_p[40];
////	Izpt_vxAdj1_p	=iAF_array_p[41];
////	Izpt_vxAdj2_p	=iAF_array_p[42];
////	Izpt_vxAdj3_p	=iAF_array_p[43];
////	Izpt_vxAdj4_p	=iAF_array_p[44];
////	Izpt_vxAdj5_p	=iAF_array_p[45];
////	Izpt_iLRatio1_p	=iAF_array_p[46];
////	Izpt_iLRatio2_p	=iAF_array_p[47];
////	Izpt_iLRatio3_p	=iAF_array_p[48];
////	Izpt_iLRatio4_p	=iAF_array_p[49];
////	Izpt_iLTC1_p	=iAF_array_p[50];
////	Izpt_iLTC2_p	=iAF_array_p[51];
////	Izpt_iLTC3_p	=iAF_array_p[52];
////	Izpt_iLTC4_p	=iAF_array_p[53];
////	Izpt_ARreq_p	=iAF_array_p[54];
////	Izpt_ZF_p		=iAF_array_p[55];
////
////	// Keep track of min/max and delta to make sure DDD card is good
////	for(i=1; i<=54; i++)
////	{
////		if(iAF_array_p[i] < iAF_min_p)		iAF_min_p = iAF_array_p[i];
////		if(iAF_array_p[i] > iAF_max_p)		iAF_max_p = iAF_array_p[i];
////	}
////
////	// Purposely datalog out -999 to fail ZF-P so we know DDD or DVI is bad and "Disable Trim"  (TMT26 shows this symptom)
////	if(iAF_max_p > 150e-6 && iAF_max_p < 200e-6 ) //virgin device but iAF is measured incorrectly
////	{
////		Izpt_ZF_p = -999;
////		g_p_Trim_Enable = 0;	//DISABLE TRIM
////	}
////	
////	// Datalog //
////	// Primary //
////	PiDatalog(func, A_Izpt_iov1_p, Izpt_iov1_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iov2_p, Izpt_iov2_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iov3_p, Izpt_iov3_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iov4_p, Izpt_iov4_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iovSign_p, Izpt_iovSign_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iL1_p, Izpt_iL1_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iL2_p, Izpt_iL2_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iL3_p, Izpt_iL3_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iLsign_p, Izpt_iLsign_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_tOVL1_p, Izpt_tOVL1_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_tOVL2_p, Izpt_tOVL2_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_tOVLSign_p, Izpt_tOVLSign_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_f1_p, Izpt_f1_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_f2_p, Izpt_f2_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_fSign_p, Izpt_fSign_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iov_Off_p, Izpt_iov_Off_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iuvMinus_p, Izpt_iuvMinus_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_uvDelay_p, Izpt_uvDelay_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_Loff_AR_p, Izpt_Loff_AR_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_DisablAR_p, Izpt_DisablAR_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_didtComp_p, Izpt_didtComp_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_OT_Hys_p, Izpt_OT_Hys_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_LoffwOT_p, Izpt_LoffwOT_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iLselOff_p, Izpt_iLselOff_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iLStdIcr_p, Izpt_iLStdIcr_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iL20dn_p, Izpt_iL20dn_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iL20up_p, Izpt_iL20up_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_SAM_p, Izpt_SAM_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_OTP1_p, Izpt_OTP1_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_OTP2_p, Izpt_OTP2_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_OTP3_p, Izpt_OTP3_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_SDSoff_p, Izpt_SDSoff_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_Rcv1_p, Izpt_Rcv1_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_Rcv2_p, Izpt_Rcv2_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_RcvSign_p, Izpt_RcvSign_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_drvSize1_p, Izpt_drvSize1_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_drvSize2_p, Izpt_drvSize2_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_drvSize3_p, Izpt_drvSize3_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_drvSize4_p, Izpt_drvSize4_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_RsenseUp_p, Izpt_RsenseUp_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_vxAdj1_p, Izpt_vxAdj1_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_vxAdj2_p, Izpt_vxAdj2_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_vxAdj3_p, Izpt_vxAdj3_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_vxAdj4_p, Izpt_vxAdj4_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_vxAdj5_p, Izpt_vxAdj5_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iLRatio1_p, Izpt_iLRatio1_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iLRatio2_p, Izpt_iLRatio2_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iLRatio3_p, Izpt_iLRatio3_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iLRatio4_p, Izpt_iLRatio4_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iLTC1_p, Izpt_iLTC1_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iLTC2_p, Izpt_iLTC2_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iLTC3_p, Izpt_iLTC3_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_iLTC4_p, Izpt_iLTC4_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_ARreq_p, Izpt_ARreq_p, 8, POWER_MICRO);
////	PiDatalog(func, A_Izpt_ZF_p, Izpt_ZF_p, 8, POWER_MICRO);
////
////	// Open all relays //
////	Initialize_Relays();
////
////	// Initialize Instruments //
////	Initialize_Instruments();
////
////	// Drain //
////	D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
////	D_dvi->set_current(D_ch, 30e-3, RANGE_30_MA); // DVI_11_0 //
////
////	// BPP //
////	BPP_ovi->set_voltage(BPP_ch, 0.0, RANGE_10_V); // OVI_1_0 //
////	BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
////
////	// V pin //
////	VPIN_ovi->set_voltage(VPIN_ch, 0.0, RANGE_10_V); // OVI_1_1 //
////	VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //
////
////	// FW //
////	Close_relay(K18);
////	FW_dvi->set_voltage(FW_ch, 1, VOLT_10_RANGE); // DVI_11_1 //
////	FW_dvi->set_current(FW_ch, 30e-3, RANGE_30_MA); // DVI_11_1 //
////
////	// SR //
////	SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_2_RANGE); // DVI_13_1, dvi2k //
////	//SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
////	SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k //
////	Mux20_Close_relay(K50); // SR pin hard short to GND with relay //
////
////	// BPS //
////	BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
////	BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //
////
////	// IS //
////	IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_2_RANGE); // DVI_13_0, dvi2k //
////	IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //
////
////	// Vout //
////	VO_dvi->set_voltage(VO_ch, 4.5, VOLT_10_RANGE); // DVI_9_0 //
////	VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //
////
////	// COMP //
////	FB_ovi->disconnect(2);
////
////	// VBD //
////	VBD_dvi->set_voltage(VBD_ch, 0.0, VOLT_5_RANGE); // DVI_21_0 //
////	VBD_dvi->set_current(VBD_ch, 30e-6, RANGE_30_UA); // DVI_21_0, prevent glitch //
////	wait.delay_10_us(25); // Prevent glitch //
////	VBD_dvi->set_current(VBD_ch, 0.1e-9, RANGE_30_UA); // DVI_21_0, Float //
////
////	// uVCC //
////	uVCC_ovi->set_voltage(uVCC_ch, 0.0, RANGE_5_V); // OVI_3_2 //
////	uVCC_ovi->set_current(uVCC_ch, 0.1e-9, RANGE_30_UA); // OVI_3_2, Float //
////
////	// DDD level //
////	g_DDD_Low = 0.0; // Save current value //
////	g_DDD_High = 3.3; // Save current value //
////	wait.delay_10_us(g_DDDwait);
////	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////	wait.delay_10_us(g_DDDwait);
////
////	// SDA //
////	Mux20_Close_relay(K64); // SDA pullup to 3.3V through 1.5kohm resistor. //
////	ovi_3->set_voltage(OVI_CHANNEL_7, g_I2C_Pullup, RANGE_5_V); // OVI_3_7 //
////	ovi_3->set_current(OVI_CHANNEL_7, 30e-3, RANGE_30_MA); // OVI_3_7 //
////	Mux20_Close_relay(K37); // Disconnect ovi from SDA. //
////	Mux20_Close_relay(K38); // Connect SDA and SCL to DDD. //
////	Mux20_Close_relay(K40); // Connect SDA and SCL to DDD. //
////
////	// SCL //
////	Mux20_Close_relay(K39);  // Disconnect ovi from SCL. //
////	ddd_7->ddd_run_pattern(g_SDA_SCL_Low_start, g_SDA_SCL_Low_stop);  // Start with SDA and SCL low with DDD. //
////
////	// Set DDD for I2C. //
////	ddd_7->ddd_set_clock_period(g_Dclk_I2C);	
////	ddd_7->ddd_set_voltage_ref(g_Vref_I2C);
////		
////	// Wait for relays //
////	wait.delay_10_us(200); 
////
////	// Powerup //
////	BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
////	wait.delay_10_us(100); // Must wait long enough for uVCC to come up before sending I2C commands. //
////
////	// Powerup into test mode. //
////	Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
////	Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //
////	//Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //
////
////	// Read all secondary registers using I2C. //
////	Write_Word(g_RDADDR, g_READ0, NObin, HEX);
////	Read_Word(g_RDADDR, READ0_word);
////
////	//Write_Word(g_RDADDR, g_READ1, NObin, HEX);
////	//Read_Word(g_RDADDR, READ1_word);
////
////	//Write_Word(g_RDADDR, g_READ2, NObin, HEX);
////	//Read_Word(g_RDADDR, READ2_word);
////
////	//Write_Word(g_RDADDR, g_READ3, NObin, HEX);
////	//Read_Word(g_RDADDR, READ3_word);
////
////	//Write_Word(g_RDADDR, g_READ4, NObin, HEX);
////	//Read_Word(g_RDADDR, READ4_word);
////
////	//Write_Word(g_RDADDR, g_READ5, NObin, HEX);
////	//Read_Word(g_RDADDR, READ5_word);
////
////	//Write_Word(g_RDADDR, g_READ6, NObin, HEX);
////	//Read_Word(g_RDADDR, READ6_word);
////
////	//Write_Word(g_RDADDR, g_READ7, NObin, HEX);
////	//Read_Word(g_RDADDR, READ7_word);
////
////	//Write_Word(g_RDADDR, g_READ8, NObin, HEX);
////	//Read_Word(g_RDADDR, READ8_word);
////
////	//Write_Word(g_RDADDR, g_READ9, NObin, HEX);
////	//Read_Word(g_RDADDR, READ9_word);
////
////	//Write_Word(g_RDADDR, g_READ10, NObin, HEX);
////	//Read_Word(g_RDADDR, READ10_word);
////
////	//Write_Word(g_RDADDR, g_READ11, NObin, HEX);
////	//Read_Word(g_RDADDR, READ11_word);
////
////	//Write_Word(g_RDADDR, g_READ12, NObin, HEX);
////	//Read_Word(g_RDADDR, READ12_word);
////
////	Write_Word(g_RDADDR, g_READ56, NObin, HEX);// SREG0.  Shadow register. //
////	Read_Word(g_RDADDR, READ56_word);// SREG0.  Shadow register. //
////
////	Write_Word(g_RDADDR, g_READ57, NObin, HEX);// SREG1.  Shadow register. //
////	Read_Word(g_RDADDR, READ57_word);// SREG1.  Shadow register. //
////
////	Write_Word(g_RDADDR, g_READ58, NObin, HEX);// SREG2.  Shadow register. //
////	Read_Word(g_RDADDR, READ58_word);// SREG2.  Shadow register. //
////
////	Write_Word(g_RDADDR, g_READ59, NObin, HEX);// SREG3.  Shadow register. //
////	Read_Word(g_RDADDR, READ59_word);// SREG3.  Shadow register. //
////
////	Write_Word(g_RDADDR, g_READ60, NObin, HEX); // SREG4.  Shadow register. //
////	Read_Word(g_RDADDR, READ60_word);// SREG4.  Shadow register. //
////
////	Write_Word(g_RDADDR, g_READ61, NObin, HEX); // SREG5.  Shadow register. //
////	Read_Word(g_RDADDR, READ61_word); // SREG5.  Shadow register. //
////
////	Write_Word(g_RDADDR, g_READ62, NObin, HEX); // SREG6.  Shadow register. //
////	Read_Word(g_RDADDR, READ62_word); // SREG6.  Shadow register. //
////
////	// Load Shadow Register //
////	g_ShadowRegister[0] = READ56_word[0];
////	g_ShadowRegister[1] = READ56_word[1];
////	g_ShadowRegister[2] = READ56_word[2];
////	g_ShadowRegister[3] = READ56_word[3];
////	g_ShadowRegister[4] = READ56_word[4];
////	g_ShadowRegister[5] = READ56_word[5];
////	g_ShadowRegister[6] = READ56_word[6];
////	g_ShadowRegister[7] = READ56_word[7];
////	g_ShadowRegister[8] = READ56_word[8];
////	g_ShadowRegister[9] = READ56_word[9];
////	g_ShadowRegister[10] = READ56_word[10];
////	g_ShadowRegister[11] = READ56_word[11];
////	g_ShadowRegister[12] = READ56_word[12];
////	g_ShadowRegister[13] = READ56_word[13];
////	g_ShadowRegister[14] = READ56_word[14];
////	g_ShadowRegister[15] = READ56_word[15];
////	g_ShadowRegister[16] = READ57_word[0];
////	g_ShadowRegister[17] = READ57_word[1];
////	g_ShadowRegister[18] = READ57_word[2];
////	g_ShadowRegister[19] = READ57_word[3];
////	g_ShadowRegister[20] = READ57_word[4];
////	g_ShadowRegister[21] = READ57_word[5];
////	g_ShadowRegister[22] = READ57_word[6];
////	g_ShadowRegister[23] = READ57_word[7];
////	g_ShadowRegister[24] = READ57_word[8];
////	g_ShadowRegister[25] = READ57_word[9];
////	g_ShadowRegister[26] = READ57_word[10];
////	g_ShadowRegister[27] = READ57_word[11];
////	g_ShadowRegister[28] = READ57_word[12];
////	g_ShadowRegister[29] = READ57_word[13];
////	g_ShadowRegister[30] = READ57_word[14];
////	g_ShadowRegister[31] = READ57_word[15];
////	g_ShadowRegister[32] = READ58_word[0];
////	g_ShadowRegister[33] = READ58_word[1];
////	g_ShadowRegister[34] = READ58_word[2];
////	g_ShadowRegister[35] = READ58_word[3];
////	g_ShadowRegister[36] = READ58_word[4];
////	g_ShadowRegister[37] = READ58_word[5];
////	g_ShadowRegister[38] = READ58_word[6];
////	g_ShadowRegister[39] = READ58_word[7];
////	g_ShadowRegister[40] = READ58_word[8];
////	g_ShadowRegister[41] = READ58_word[9];
////	g_ShadowRegister[42] = READ58_word[10];
////	g_ShadowRegister[43] = READ58_word[11];
////	g_ShadowRegister[44] = READ58_word[12];
////	g_ShadowRegister[45] = READ58_word[13];
////	g_ShadowRegister[46] = READ58_word[14];
////	g_ShadowRegister[47] = READ58_word[15];
////	g_ShadowRegister[48] = READ59_word[0];
////	g_ShadowRegister[49] = READ59_word[1];
////	g_ShadowRegister[50] = READ59_word[2];
////	g_ShadowRegister[51] = READ59_word[3];
////	g_ShadowRegister[52] = READ59_word[4];
////	g_ShadowRegister[53] = READ59_word[5];
////	g_ShadowRegister[54] = READ59_word[6];
////	g_ShadowRegister[55] = READ59_word[7];
////	g_ShadowRegister[56] = READ59_word[8];
////	g_ShadowRegister[57] = READ59_word[9];
////	g_ShadowRegister[58] = READ59_word[10];
////	g_ShadowRegister[59] = READ59_word[11];
////	g_ShadowRegister[60] = READ59_word[12];
////	g_ShadowRegister[61] = READ59_word[13];
////	g_ShadowRegister[62] = READ59_word[14];
////	g_ShadowRegister[63] = READ59_word[15]; // bit[63]: trim_no_fb_pin //
////	g_ShadowRegister[64] = READ60_word[0];
////	g_ShadowRegister[65] = READ60_word[1];
////	g_ShadowRegister[66] = READ60_word[2];
////	g_ShadowRegister[67] = READ60_word[3];
////	g_ShadowRegister[68] = READ60_word[4];
////	g_ShadowRegister[69] = READ60_word[5];
////	g_ShadowRegister[70] = READ60_word[6];
////	g_ShadowRegister[71] = READ60_word[7];
////	g_ShadowRegister[72] = READ60_word[8];
////	g_ShadowRegister[73] = READ60_word[9];
////	g_ShadowRegister[74] = READ60_word[10];
////	g_ShadowRegister[75] = READ60_word[11];
////	g_ShadowRegister[76] = READ60_word[12];
////	g_ShadowRegister[77] = READ60_word[13];
////	g_ShadowRegister[78] = READ60_word[14];
////	g_ShadowRegister[79] = READ60_word[15];
////	g_ShadowRegister[80] = READ61_word[0];
////	g_ShadowRegister[81] = READ61_word[1];
////	g_ShadowRegister[82] = READ61_word[2];
////	g_ShadowRegister[83] = READ61_word[3];
////	g_ShadowRegister[84] = READ61_word[4];
////	g_ShadowRegister[85] = READ61_word[5];
////	g_ShadowRegister[86] = READ61_word[6];
////	g_ShadowRegister[87] = READ61_word[7];
////	g_ShadowRegister[88] = READ61_word[8];
////	g_ShadowRegister[89] = READ61_word[9];
////	g_ShadowRegister[90] = READ61_word[10];
////	g_ShadowRegister[91] = READ61_word[11];
////	g_ShadowRegister[92] = READ61_word[12];
////	g_ShadowRegister[93] = READ61_word[13];
////	g_ShadowRegister[94] = READ61_word[14];
////	g_ShadowRegister[95] = READ61_word[15];
////	g_ShadowRegister[96] = READ62_word[0];
////	g_ShadowRegister[97] = READ62_word[1];
////	g_ShadowRegister[98] = READ62_word[2];
////	g_ShadowRegister[99] = READ62_word[3];
////	g_ShadowRegister[100] = READ62_word[4];
////	g_ShadowRegister[101] = READ62_word[5];
////	g_ShadowRegister[102] = READ62_word[6];
////	g_ShadowRegister[103] = READ62_word[7];
////	g_ShadowRegister[104] = READ62_word[8];
////	g_ShadowRegister[105] = READ62_word[9];
////	g_ShadowRegister[106] = READ62_word[10];
////	g_ShadowRegister[107] = READ62_word[11];
////	g_ShadowRegister[108] = READ62_word[12];
////	g_ShadowRegister[109] = READ62_word[13];
////	g_ShadowRegister[110] = READ62_word[14];
////	g_ShadowRegister[111] = READ62_word[15];
////
////	// Load EEpt_ShadRegXXX bits. //
////	g_EEpt_ShadReg0 = g_ShadowRegister[0];
////	g_EEpt_ShadReg1 = g_ShadowRegister[1];
////	g_EEpt_ShadReg2 = g_ShadowRegister[2];
////	g_EEpt_ShadReg3 = g_ShadowRegister[3];
////	g_EEpt_ShadReg4 = g_ShadowRegister[4];
////	g_EEpt_ShadReg5 = g_ShadowRegister[5];
////	g_EEpt_ShadReg6 = g_ShadowRegister[6];
////	g_EEpt_ShadReg7 = g_ShadowRegister[7];
////	g_EEpt_ShadReg8 = g_ShadowRegister[8];
////	g_EEpt_ShadReg9 = g_ShadowRegister[9];
////	g_EEpt_ShadReg10 = g_ShadowRegister[10];
////	g_EEpt_ShadReg11 = g_ShadowRegister[11];
////	g_EEpt_ShadReg12 = g_ShadowRegister[12];
////	g_EEpt_ShadReg13 = g_ShadowRegister[13];
////	g_EEpt_ShadReg14 = g_ShadowRegister[14];
////	g_EEpt_ShadReg15 = g_ShadowRegister[15];
////	g_EEpt_ShadReg16 = g_ShadowRegister[16];
////	g_EEpt_ShadReg17 = g_ShadowRegister[17];
////	g_EEpt_ShadReg18 = g_ShadowRegister[18];
////	g_EEpt_ShadReg19 = g_ShadowRegister[19];
////	g_EEpt_ShadReg20 = g_ShadowRegister[20];
////	g_EEpt_ShadReg21 = g_ShadowRegister[21];
////	g_EEpt_ShadReg22 = g_ShadowRegister[22];
////	g_EEpt_ShadReg23 = g_ShadowRegister[23];
////	g_EEpt_ShadReg24 = g_ShadowRegister[24];
////	g_EEpt_ShadReg25 = g_ShadowRegister[25];
////	g_EEpt_ShadReg26 = g_ShadowRegister[26];
////	g_EEpt_ShadReg27 = g_ShadowRegister[27];
////	g_EEpt_ShadReg28 = g_ShadowRegister[28];
////	g_EEpt_ShadReg29 = g_ShadowRegister[29];
////	g_EEpt_ShadReg30 = g_ShadowRegister[30];
////	g_EEpt_ShadReg31 = g_ShadowRegister[31];
////	g_EEpt_ShadReg32 = g_ShadowRegister[32];
////	g_EEpt_ShadReg33 = g_ShadowRegister[33];
////	g_EEpt_ShadReg34 = g_ShadowRegister[34];
////	g_EEpt_ShadReg35 = g_ShadowRegister[35];
////	g_EEpt_ShadReg36 = g_ShadowRegister[36];
////	g_EEpt_ShadReg37 = g_ShadowRegister[37];
////	g_EEpt_ShadReg38 = g_ShadowRegister[38];
////	g_EEpt_ShadReg39 = g_ShadowRegister[39];
////	g_EEpt_ShadReg40 = g_ShadowRegister[40];
////	g_EEpt_ShadReg41 = g_ShadowRegister[41];
////	g_EEpt_ShadReg42 = g_ShadowRegister[42];
////	g_EEpt_ShadReg43 = g_ShadowRegister[43];
////	g_EEpt_ShadReg44 = g_ShadowRegister[44];
////	g_EEpt_ShadReg45 = g_ShadowRegister[45];
////	g_EEpt_ShadReg46 = g_ShadowRegister[46];
////	g_EEpt_ShadReg47 = g_ShadowRegister[47];
////	g_EEpt_ShadReg48 = g_ShadowRegister[48];
////	g_EEpt_ShadReg49 = g_ShadowRegister[49];
////	g_EEpt_ShadReg50 = g_ShadowRegister[50];
////	g_EEpt_ShadReg51 = g_ShadowRegister[51];
////	g_EEpt_ShadReg52 = g_ShadowRegister[52];
////	g_EEpt_ShadReg53 = g_ShadowRegister[53];
////	g_EEpt_ShadReg54 = g_ShadowRegister[54];
////	g_EEpt_ShadReg55 = g_ShadowRegister[55];
////	g_EEpt_ShadReg56 = g_ShadowRegister[56];
////	g_EEpt_ShadReg57 = g_ShadowRegister[57];
////	g_EEpt_ShadReg58 = g_ShadowRegister[58];
////	g_EEpt_ShadReg59 = g_ShadowRegister[59];
////	g_EEpt_ShadReg60 = g_ShadowRegister[60];
////	g_EEpt_ShadReg61 = g_ShadowRegister[61];
////	g_EEpt_ShadReg62 = g_ShadowRegister[62];
////	g_EEpt_ShadReg63 = g_ShadowRegister[63]; // bit[63]: trim_no_fb_pin //
////	g_EEpt_ShadReg64 = g_ShadowRegister[64];
////	g_EEpt_ShadReg65 = g_ShadowRegister[65];
////	g_EEpt_ShadReg66 = g_ShadowRegister[66];
////	g_EEpt_ShadReg67 = g_ShadowRegister[67];
////	g_EEpt_ShadReg68 = g_ShadowRegister[68];
////	g_EEpt_ShadReg69 = g_ShadowRegister[69];
////	g_EEpt_ShadReg70 = g_ShadowRegister[70];
////	g_EEpt_ShadReg71 = g_ShadowRegister[71];
////	g_EEpt_ShadReg72 = g_ShadowRegister[72];
////	g_EEpt_ShadReg73 = g_ShadowRegister[73];
////	g_EEpt_ShadReg74 = g_ShadowRegister[74];
////	g_EEpt_ShadReg75 = g_ShadowRegister[75];
////	g_EEpt_ShadReg76 = g_ShadowRegister[76];
////	g_EEpt_ShadReg77 = g_ShadowRegister[77];
////	g_EEpt_ShadReg78 = g_ShadowRegister[78];
////	g_EEpt_ShadReg79 = g_ShadowRegister[79];
////	g_EEpt_ShadReg80 = g_ShadowRegister[80];
////	g_EEpt_ShadReg81 = g_ShadowRegister[81];
////	g_EEpt_ShadReg82 = g_ShadowRegister[82];
////	g_EEpt_ShadReg83 = g_ShadowRegister[83];
////	g_EEpt_ShadReg84 = g_ShadowRegister[84];
////	g_EEpt_ShadReg85 = g_ShadowRegister[85];
////	g_EEpt_ShadReg86 = g_ShadowRegister[86];
////	g_EEpt_ShadReg87 = g_ShadowRegister[87];
////	g_EEpt_ShadReg88 = g_ShadowRegister[88];
////	g_EEpt_ShadReg89 = g_ShadowRegister[89];
////	g_EEpt_ShadReg90 = g_ShadowRegister[90];
////	g_EEpt_ShadReg91 = g_ShadowRegister[91];
////	g_EEpt_ShadReg92 = g_ShadowRegister[92];
////	g_EEpt_ShadReg93 = g_ShadowRegister[93];
////	g_EEpt_ShadReg94 = g_ShadowRegister[94];
////	g_EEpt_ShadReg95 = g_ShadowRegister[95];
////	g_EEpt_ShadReg96 = g_ShadowRegister[96];
////	g_EEpt_ShadReg97 = g_ShadowRegister[97];
////	g_EEpt_ShadReg98 = g_ShadowRegister[98];
////	g_EEpt_ShadReg99 = g_ShadowRegister[99];
////	g_EEpt_ShadReg100 = g_ShadowRegister[100];
////	g_EEpt_ShadReg101 = g_ShadowRegister[101];
////	g_EEpt_ShadReg102 = g_ShadowRegister[102];
////	g_EEpt_ShadReg103 = g_ShadowRegister[103];
////	g_EEpt_ShadReg104 = g_ShadowRegister[104]; // eep_sreg[104]: trim_ldo_3p6v //
////	g_EEpt_ShadReg105 = g_ShadowRegister[105];
////	g_EEpt_ShadReg106 = g_ShadowRegister[106];
////	g_EEpt_ShadReg107 = g_ShadowRegister[107];
////	g_EEpt_ShadReg108 = g_ShadowRegister[108];
////	g_EEpt_ShadReg109 = g_ShadowRegister[109];
////	g_EEpt_ShadReg110 = g_ShadowRegister[110];
////	g_EEpt_ShadReg111 = g_ShadowRegister[111];
////
////	// Load other EEpt_XX bits //
////	EEpt_F1_S = g_ShadowRegister[12];
////	EEpt_F2_S = g_ShadowRegister[13];
////	EEpt_F3_S = g_ShadowRegister[14];
////	EEpt_PKspdLd_S = g_ShadowRegister[45]; // 999 in InnoVI-TrimOptions.csv file // 
////	EEpt_CV1_S = g_ShadowRegister[16];
////	EEpt_VesrAdp_S = g_ShadowRegister[27];
////	EEpt_ISvth3X1_S = g_ShadowRegister[32];
////	EEpt_ISvth3X2_S = g_ShadowRegister[33];
////	EEpt_ISvth3X3_S = g_ShadowRegister[34];
////	EEpt_ISvth3X4_S = g_ShadowRegister[35];
////	EEpt_ISvth3X5_S = g_ShadowRegister[36];
////	EEpt_ISvth3X6_S = g_ShadowRegister[37];
////	EEpt_CDC1_S = g_ShadowRegister[24];
////	EEpt_CDC2_S = g_ShadowRegister[25];
////	EEpt_CDC3_S = g_ShadowRegister[26];
////	EEpt_CV2_S = g_ShadowRegister[17];
////	EEpt_CV3_S = g_ShadowRegister[18];
////	EEpt_CV4_S = g_ShadowRegister[19];
////	EEpt_CV5_S = g_ShadowRegister[20];
////	EEpt_CV6_S = g_ShadowRegister[21];
////	EEpt_OSC0_S = g_ShadowRegister[8];
////	EEpt_OSC1_S = g_ShadowRegister[9];
////	EEpt_OSC2_S = g_ShadowRegister[10];
////	EEpt_OSC3_S = g_ShadowRegister[11];
////	EEpt_nDAC1_S = g_ShadowRegister[40];
////	EEpt_nDAC2_S = g_ShadowRegister[41];
////	EEpt_nDAC3_S = g_ShadowRegister[42];
////	EEpt_nDAC4_S = g_ShadowRegister[43];
////	EEpt_nDAC5_S = g_ShadowRegister[44];
////	EEpt_pDAC1_S = g_ShadowRegister[48];
////	EEpt_pDAC2_S = g_ShadowRegister[49];
////	EEpt_pDAC3_S = g_ShadowRegister[50];
////	EEpt_pDAC4_S = g_ShadowRegister[51];
////	EEpt_pDAC5_S = g_ShadowRegister[52];
////	EEpt_DofA1_S = g_ShadowRegister[56];
////	EEpt_DofA2_S = g_ShadowRegister[57];
////	EEpt_DofA3_S = g_ShadowRegister[58];
////	EEpt_DofA4_S = g_ShadowRegister[59];
////	EEpt_DofA5_S = g_ShadowRegister[60];
////	EEpt_IsDAC1_S = g_ShadowRegister[64];
////	EEpt_IsDAC2_S = g_ShadowRegister[65];
////	EEpt_IsDAC3_S = g_ShadowRegister[66];
////	EEpt_IsDAC4_S = g_ShadowRegister[67];
////	EEpt_IsDAC5_S = g_ShadowRegister[68];
////	EEpt_Gain1_S = g_ShadowRegister[72];
////	EEpt_Gain2_S = g_ShadowRegister[73];
////	EEpt_Gain3_S = g_ShadowRegister[74];
////	EEpt_Gain4_S = g_ShadowRegister[75];
////	EEpt_CCoff1_S = g_ShadowRegister[69];
////	EEpt_CCoff2_S = g_ShadowRegister[70];
////	EEpt_CCoff3_S = g_ShadowRegister[71];
////	EEpt_IsCal1_S = g_ShadowRegister[76];
////	EEpt_IsCal2_S = g_ShadowRegister[77];
////	EEpt_IsCal3_S = g_ShadowRegister[78];
////	EEpt_DsoftEn_S = g_ShadowRegister[23];
////	EEpt_DOPL_S = g_ShadowRegister[22];
////	EEpt_DoplEnCp_S = g_ShadowRegister[15];
////	EEpt_ESRsel_S = g_ShadowRegister[29];
////	EEpt_DdampEn_S = g_ShadowRegister[28];
////
////	// EEpt_SiOption_s.  Get rev_id //
////	rev_id_Word[0] = READ0_word[0];
////	rev_id_Word[1] = READ0_word[1];
////	rev_id_Word[2] = READ0_word[2];
////	rev_id_Word[3] = READ0_word[3];
////	rev_id_Word[4] = READ0_word[4];
////	rev_id_Word[5] = READ0_word[5];
////	rev_id_Word[6] = READ0_word[6];
////	rev_id_Word[7] = READ0_word[7];
////	rev_id_Word[8] = READ0_word[8];
////	rev_id_Word[9] = READ0_word[9];
////	rev_id_Word[10] = READ0_word[10];
////	rev_id_Word[11] = READ0_word[11];
////	rev_id_Word[12] = READ0_word[12];
////	rev_id_Word[13] = READ0_word[13];
////	rev_id_Word[14] = READ0_word[14];
////	rev_id_Word[15] = READ0_word[15];
////	Convert_16bitBinary_To_Decimal(rev_id_Word, EEpt_SiOption_s);
////	gSiOption_s = EEpt_SiOption_s;
////	// EEpt_SiOption_s: 2304 = Rev C silicon //
////	// EEpt_SiOption_s: 2305 = Rev C1 silicon //
////
////	// How many bits are trimmed. //
////	Izpt_Trimmed = Trimmed_P; // Datalog number of primary side bits are trimmed. //
////
////	// Secondary.  Look at first four shadow register bits.  If all are '1' then it is a virgin 
////	// part. If all are '0' then it is a trimmed part (i.e. EEPROM already written).  If 
////	// some are '1' and some are '0' then error. //
////	if (g_EEpt_ShadReg0 == 1 &&
////		g_EEpt_ShadReg1 == 1 &&
////		g_EEpt_ShadReg2 == 1 &&
////		g_EEpt_ShadReg3 == 1)
////	{
////		Trimmed_S = 0; // Virgin //
////	}
////	else if (g_EEpt_ShadReg0 == 0 &&
////			 g_EEpt_ShadReg1 == 0 &&
////		 	 g_EEpt_ShadReg2 == 0 &&
////			 g_EEpt_ShadReg3 == 0)
////	{
////		Trimmed_S = 1; // Trimmed //
////	}	
////	else // Error //
////	{
////		g_Error_Flag = -127;
////		Trimmed_S = 1; // Flag to prevent trimming. //
////	}
////
////	// Powerdown //
////	SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
////	Mux20_Open_relay(K64);
////	ovi_3->set_voltage(OVI_CHANNEL_7, 0.0, RANGE_10_V); // OVI_3_7 //
////	Mux20_Open_relay(K37);
////	Mux20_Open_relay(K38);
////	Mux20_Open_relay(K40);
////	Mux20_Open_relay(K39);
////	Mux20_Open_relay(K50); // SR pin hard short to GND with relay //
////	VO_dvi->set_voltage(VO_ch, 0, VOLT_5_RANGE); // DVI_9_0 //
////	wait.delay_10_us(20);
////	Open_relay(K18);
////	FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
////	uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
////	uVCCrampDown(0.5, 0, 0.1);
////	VBPS_ramp_down(4, 0.2, 200e-3);
////	VBD_dvi->set_voltage(VBD_ch, 3, VOLT_5_RANGE); // DVI_21_0, prevent undershoot //
////	VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
////	wait.delay_10_us(20);
////	VBD_dvi->set_voltage(VBD_ch, 0, VOLT_5_RANGE); // DVI_21_0 //
////	BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
////	FB_ovi->connect(2);
////	ddd_7->ddd_set_clock_period(Dclk_period);
////	ddd_7->ddd_set_voltage_ref(DDD_Vref);
////
////	// DDD level //
////	g_DDD_Low = 0.0; // Save current value //
////	g_DDD_High = 4.0; // Save current value //
////	wait.delay_10_us(g_DDDwait);
////	ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
////	ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////	wait.delay_10_us(200); // Wait for relays //
////
////	// Datalog //
////	// Secondary //
////	PiDatalog(func, A_EEpt_F1_s, EEpt_F1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_F2_s, EEpt_F2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_F3_s, EEpt_F3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_F_Iint1_s, EEpt_F_Iint1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_F_Iint2_s, EEpt_F_Iint2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_F_Iint3_s, EEpt_F_Iint3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_F_Iint4_s, EEpt_F_Iint4_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_PKspdLd_s, EEpt_PKspdLd_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CV1_s, EEpt_CV1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_VesrAdp_s, EEpt_VesrAdp_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ISvth3X1_s, EEpt_ISvth3X1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ISvth3X2_s, EEpt_ISvth3X2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ISvth3X3_s, EEpt_ISvth3X3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ISvth3X4_s, EEpt_ISvth3X4_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ISvth3X5_s, EEpt_ISvth3X5_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ISvth3X6_s, EEpt_ISvth3X6_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CDC1_s, EEpt_CDC1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CDC2_s, EEpt_CDC2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CDC3_s, EEpt_CDC3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CV2_s, EEpt_CV2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CV3_s, EEpt_CV3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CV4_s, EEpt_CV4_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CV5_s, EEpt_CV5_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CV6_s, EEpt_CV6_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_OSC0_s, EEpt_OSC0_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_OSC1_s, EEpt_OSC1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_OSC2_s, EEpt_OSC2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_OSC3_s, EEpt_OSC3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_nDAC1_s, EEpt_nDAC1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_nDAC2_s, EEpt_nDAC2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_nDAC3_s, EEpt_nDAC3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_nDAC4_s, EEpt_nDAC4_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_nDAC5_s, EEpt_nDAC5_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_pDAC1_s, EEpt_pDAC1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_pDAC2_s, EEpt_pDAC2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_pDAC3_s, EEpt_pDAC3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_pDAC4_s, EEpt_pDAC4_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_pDAC5_s, EEpt_pDAC5_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_DofA1_s, EEpt_DofA1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_DofA2_s, EEpt_DofA2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_DofA3_s, EEpt_DofA3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_DofA4_s, EEpt_DofA4_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_DofA5_s, EEpt_DofA5_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_IsDAC1_s, EEpt_IsDAC1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_IsDAC2_s, EEpt_IsDAC2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_IsDAC3_s, EEpt_IsDAC3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_IsDAC4_s, EEpt_IsDAC4_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_IsDAC5_s, EEpt_IsDAC5_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_Gain1_s, EEpt_Gain1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_Gain2_s, EEpt_Gain2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_Gain3_s, EEpt_Gain3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_Gain4_s, EEpt_Gain4_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CCoff1_s, EEpt_CCoff1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CCoff2_s, EEpt_CCoff2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_CCoff3_s, EEpt_CCoff3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_IsCal1_s, EEpt_IsCal1_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_IsCal2_s, EEpt_IsCal2_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_IsCal3_s, EEpt_IsCal3_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_DsoftEn_s, EEpt_DsoftEn_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_DOPL_s, EEpt_DOPL_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_DoplEnCp_S, EEpt_DoplEnCp_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ESRsel_s, EEpt_ESRsel_S, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_DdampEn_s, EEpt_DdampEn_S, 8, POWER_UNIT);
////	PiDatalog(func, A_Izpt_Trimmed, Izpt_Trimmed, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_SiOption_s, gSiOption_s, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg0, g_EEpt_ShadReg0, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg1, g_EEpt_ShadReg1, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg2, g_EEpt_ShadReg2, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg3, g_EEpt_ShadReg3, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg4, g_EEpt_ShadReg4, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg5, g_EEpt_ShadReg5, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg6, g_EEpt_ShadReg6, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg7, g_EEpt_ShadReg7, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg8, g_EEpt_ShadReg8, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg9, g_EEpt_ShadReg9, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg10, g_EEpt_ShadReg10, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg11, g_EEpt_ShadReg11, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg12, g_EEpt_ShadReg12, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg13, g_EEpt_ShadReg13, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg14, g_EEpt_ShadReg14, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg15, g_EEpt_ShadReg15, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg16, g_EEpt_ShadReg16, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg17, g_EEpt_ShadReg17, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg18, g_EEpt_ShadReg18, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg19, g_EEpt_ShadReg19, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg20, g_EEpt_ShadReg20, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg21, g_EEpt_ShadReg21, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg22, g_EEpt_ShadReg22, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg23, g_EEpt_ShadReg23, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg24, g_EEpt_ShadReg24, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg25, g_EEpt_ShadReg25, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg26, g_EEpt_ShadReg26, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg27, g_EEpt_ShadReg27, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg28, g_EEpt_ShadReg28, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg29, g_EEpt_ShadReg29, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg30, g_EEpt_ShadReg30, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg31, g_EEpt_ShadReg31, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg32, g_EEpt_ShadReg32, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg33, g_EEpt_ShadReg33, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg34, g_EEpt_ShadReg34, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg35, g_EEpt_ShadReg35, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg36, g_EEpt_ShadReg36, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg37, g_EEpt_ShadReg37, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg38, g_EEpt_ShadReg38, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg39, g_EEpt_ShadReg39, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg40, g_EEpt_ShadReg40, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg41, g_EEpt_ShadReg41, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg42, g_EEpt_ShadReg42, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg43, g_EEpt_ShadReg43, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg44, g_EEpt_ShadReg44, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg45, g_EEpt_ShadReg45, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg46, g_EEpt_ShadReg46, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg47, g_EEpt_ShadReg47, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg48, g_EEpt_ShadReg48, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg49, g_EEpt_ShadReg49, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg50, g_EEpt_ShadReg50, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg51, g_EEpt_ShadReg51, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg52, g_EEpt_ShadReg52, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg53, g_EEpt_ShadReg53, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg54, g_EEpt_ShadReg54, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg55, g_EEpt_ShadReg55, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg56, g_EEpt_ShadReg56, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg57, g_EEpt_ShadReg57, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg58, g_EEpt_ShadReg58, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg59, g_EEpt_ShadReg59, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg60, g_EEpt_ShadReg60, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg61, g_EEpt_ShadReg61, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg62, g_EEpt_ShadReg62, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg63, g_EEpt_ShadReg63, 8, POWER_UNIT); // bit[63]: trim_no_fb_pin //
////	PiDatalog(func, A_EEpt_ShadReg64, g_EEpt_ShadReg64, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg65, g_EEpt_ShadReg65, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg66, g_EEpt_ShadReg66, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg67, g_EEpt_ShadReg67, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg68, g_EEpt_ShadReg68, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg69, g_EEpt_ShadReg69, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg70, g_EEpt_ShadReg70, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg71, g_EEpt_ShadReg71, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg72, g_EEpt_ShadReg72, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg73, g_EEpt_ShadReg73, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg74, g_EEpt_ShadReg74, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg75, g_EEpt_ShadReg75, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg76, g_EEpt_ShadReg76, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg77, g_EEpt_ShadReg77, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg78, g_EEpt_ShadReg78, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg79, g_EEpt_ShadReg79, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg80, g_EEpt_ShadReg80, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg81, g_EEpt_ShadReg81, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg82, g_EEpt_ShadReg82, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg83, g_EEpt_ShadReg83, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg84, g_EEpt_ShadReg84, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg85, g_EEpt_ShadReg85, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg86, g_EEpt_ShadReg86, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg87, g_EEpt_ShadReg87, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg88, g_EEpt_ShadReg88, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg89, g_EEpt_ShadReg89, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg90, g_EEpt_ShadReg90, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg91, g_EEpt_ShadReg91, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg92, g_EEpt_ShadReg92, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg93, g_EEpt_ShadReg93, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg94, g_EEpt_ShadReg94, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg95, g_EEpt_ShadReg95, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg96, g_EEpt_ShadReg96, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg97, g_EEpt_ShadReg97, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg98, g_EEpt_ShadReg98, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg99, g_EEpt_ShadReg99, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg100, g_EEpt_ShadReg100, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg101, g_EEpt_ShadReg101, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg102, g_EEpt_ShadReg102, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg103, g_EEpt_ShadReg103, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg104, g_EEpt_ShadReg104, 8, POWER_UNIT); // eep_sreg[104]: trim_ldo_3p6v //
////	PiDatalog(func, A_EEpt_ShadReg105, g_EEpt_ShadReg105, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg106, g_EEpt_ShadReg106, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg107, g_EEpt_ShadReg107, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg108, g_EEpt_ShadReg108, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg109, g_EEpt_ShadReg109, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg110, g_EEpt_ShadReg110, 8, POWER_UNIT);
////	PiDatalog(func, A_EEpt_ShadReg111, g_EEpt_ShadReg111, 8, POWER_UNIT);
////	PiDatalog(func, A_IZpre_TT, IZpre_TT, 8, POWER_MILLI);
////
////	// Check if part is trimmed. //
////	if(Trimmed_P > 0 || Trimmed_S > 0)
////	{
////		g_p_Trim_Enable = 0; // DISABLE TRIM
////	}
////
////	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
////	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
////	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
////	// ERASE the EEPROM //
////	// Only erase the EEPROM if virgin part. //
////	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
////	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
////	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
////	if(Trimmed_P < 1 && Trimmed_S < 1 && g_p_Trim_Enable)  // Virgin part //
//////if(1) // DEBUG ONLY!!! //
////	{
////
////
////
////		// Open all relays //
////		Initialize_Relays();
////
////		// Initialize Instruments //
////		Initialize_Instruments();
////
////		// Drain //
////		//Close_relay(K2);
////		D_dvi->set_voltage(D_ch, 0, VOLT_50_RANGE); // DVI_11_0 //
////		D_dvi->set_current(D_ch, 30e-3, RANGE_30_MA); // DVI_11_0 //
////
////		// BPP //
////		BPP_ovi->set_voltage(BPP_ch, 0.0, RANGE_10_V); // OVI_1_0 //
////		BPP_ovi->set_current(BPP_ch, 30e-3, RANGE_30_MA); // OVI_1_0 //
////
////		// V pin //
////		VPIN_ovi->set_voltage(VPIN_ch, 0.0, RANGE_10_V); // OVI_1_1 //
////		VPIN_ovi->set_current(VPIN_ch, 30e-3, RANGE_30_MA); // OVI_1_1 //
////
////		// FW //
////		Close_relay(K18); // Connect FW to DVI_11_1 //
////		FW_dvi->set_voltage(FW_ch, 0, VOLT_50_RANGE); // DVI_11_1 //
////		FW_dvi->set_current(FW_ch, 300e-3, RANGE_300_MA); // DVI_11_1 //
////
////		// SR //
////		SR_dvi2k->set_voltage(SR_ch, 0.0, VOLT_2_RANGE); // DVI_13_1, dvi2k //
////		SR_dvi2k->set_current(SR_ch, 0.1e-9, RANGE_20_UA); // DVI_13_1, dvi2k //
////		Mux20_Close_relay(K50); // SR pin hard short to GND with relay //
////
////		// BPS //
////		BPS_dvi->set_current(BPS_ch, 300e-3, RANGE_300_MA); // DVI_9_1 //
////		BPS_dvi->set_voltage(BPS_ch, gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //
////
////		// IS //
////		IS_dvi2k->set_voltage(IS_ch, 0.0, VOLT_2_RANGE); // DVI_13_0, dvi2k //
////		IS_dvi2k->set_current(IS_ch, 20.0e-3, RANGE_20_MA); // DVI_13_0, dvi2k //
////
////		// Vout //
////		VO_dvi->set_voltage(VO_ch, 4.5, VOLT_5_RANGE); // DVI_9_0 //
////		VO_dvi->set_current(VO_ch, 300e-3, RANGE_300_MA); // DVI_9_0 //
////
////		// FB (COMP) //
////		FB_ovi->disconnect(2);
////
////		// VBD //
////		VBD_dvi->set_voltage(VBD_ch, 0.0, VOLT_5_RANGE); // DVI_21_0 //
////		VBD_dvi->set_current(VBD_ch, 30e-6, RANGE_30_UA); // DVI_21_0, prevent glitch //
////		wait.delay_10_us(25); // Prevent glitch //
////		VBD_dvi->set_current(VBD_ch, 0.1e-9, RANGE_30_UA); // DVI_21_0, Float //
////
////		// uVCC //
////		uVCC_ovi->set_voltage(uVCC_ch, 0.0, RANGE_5_V); // OVI_3_2 //
////		uVCC_ovi->set_current(uVCC_ch, 0.1e-9, RANGE_30_UA); // OVI_3_2, Float //
////
////		// DDD level //
////		g_DDD_Low = 0.0; // Save current value //
////		g_DDD_High = 3.3; // Save current value //
////		wait.delay_10_us(g_DDDwait);
////		ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
////		ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////		wait.delay_10_us(g_DDDwait);
////
////		// SDA //
////		Mux20_Close_relay(K64); // SDA pullup to 3.3V through 1.5kohm resistor. //
////		ovi_3->set_voltage(OVI_CHANNEL_7, g_I2C_Pullup, RANGE_5_V); // OVI_3_7 //
////		ovi_3->set_current(OVI_CHANNEL_7, 30e-3, RANGE_30_MA); // OVI_3_7 //
////		Mux20_Close_relay(K37); // Disconnect ovi from SDA. //
////		Mux20_Close_relay(K38); // Connect SDA and SCL to DDD. //
////		Mux20_Close_relay(K40); // Connect SDA and SCL to DDD. //
////
////		// SCL //
////		Mux20_Close_relay(K39); // Disconnect ovi from SCL. //
////		ddd_7->ddd_run_pattern(g_SDA_SCL_Low_start, g_SDA_SCL_Low_stop);  // Start with SDA and SCL low with DDD. //
////		
////		// Set DDD for I2C. //
////		ddd_7->ddd_set_clock_period(g_Dclk_I2C);
////		ddd_7->ddd_set_voltage_ref(g_Vref_I2C);
////			
////		// Wait for relays //
////		wait.delay_10_us(200); 
////
////		// Powerup //
////		BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
////		wait.delay_10_us(100); // Must wait long enough for uVCC to come up before sending I2C commands. //
////
////		// I2C into test mode. // 
////		Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
////		Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //
////		Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //
////		
////		// Must Erase before Write //
////		// Erase EEPROM with I2C //
////		Write_Byte(g_EEP_CMD, 0x03, NObin, HEX); // Erase EEPROM //
////
////		// Wait //
////		wait.delay_10_us(100);
////
////		// Ramp BPS up to 7V //
////		Vforce = gVBPS_final;
////		while(Vforce < 7.0)
////		{
////			BPS_dvi->set_voltage(BPS_ch, Vforce, VOLT_10_RANGE); // DVI_9_1 //
////			wait.delay_10_us(1);
////			Vforce += 0.1;
////		}
////		BPS_dvi->set_voltage(BPS_ch, 7.0, VOLT_10_RANGE); // DVI_9_1 //
////		wait.delay_10_us(2);
////
////		// Bring up Erase voltage on FW pin //
////		// Ramp up to 24V in ~2msec //
////		Vforce = 0;
////		while(Vforce < 24.0)
////		{
////			FW_dvi->set_voltage(FW_ch, Vforce, VOLT_50_RANGE); // DVI_11_1 //
////			wait.delay_10_us(1);
////			Vforce += 0.120;
////		}
////		FW_dvi->set_voltage(FW_ch, 24.0, VOLT_50_RANGE); // DVI_11_1 //
////		//wait.delay_10_us(1);
////
////		// Hold 24V for 4msec //
////		wait.delay_10_us(400);
////
////		// Ramp down to 0V in ~2msec //
////		Vforce = 24;
////		while(Vforce > 0)
////		{
////			FW_dvi->set_voltage(FW_ch, Vforce, VOLT_50_RANGE); // DVI_11_1 //
////			wait.delay_10_us(1);
////			Vforce -= 0.120;
////		}
////		FW_dvi->set_voltage(FW_ch, 0, VOLT_50_RANGE); // DVI_11_1 //
////		wait.delay_10_us(2);
////
////		// Ramp BPS down to gVBPS_final //
////		Vforce = 7.0;
////		while(Vforce > gVBPS_final)
////		{
////			BPS_dvi->set_voltage(BPS_ch, Vforce, VOLT_10_RANGE); // DVI_9_1 //
////			wait.delay_10_us(1);
////			Vforce -= 0.02;
////		}
////		BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
////		wait.delay_10_us(2);
////
////		// Terminate Erase command by issuing another EEP_CMD command (any command, we use Read command). 
////		// This command�s function is only for terminating erasing. //
////		Write_Byte(g_EEP_CMD, 0x00, NObin, HEX); // Terminate Erase with Read command //
////		wait.delay_10_us(2);
////
////		// Power down //
////		VO_dvi->set_voltage(VO_ch, 0, VOLT_5_RANGE); // DVI_9_0 //
////
////		// Ramp BPS down to gVBPS_final //
////		Vforce = gVBPS_final;
////		while(Vforce > 0)
////		{
////			BPS_dvi->set_voltage(BPS_ch, Vforce, VOLT_10_RANGE); // DVI_9_1 //
////			wait.delay_10_us(1);
////			Vforce -= 0.02;
////		}
////		BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
////		wait.delay_10_us(200);
////
////		// Power back up and make sure EEPROM was written correctly. //
////		FW_dvi->set_voltage(FW_ch, 1, VOLT_10_RANGE); // DVI_11_1 //
////		FW_dvi->set_current(FW_ch, 30e-3, RANGE_30_MA); // DVI_11_1 //
////
////		// Ramp BPS up to prevent overshoot //
////		Vforce = 0;
////		while(Vforce < (gVBPS_M_Init - 200e-3))
////		{
////			BPS_dvi->set_voltage(BPS_ch, Vforce, VOLT_10_RANGE); // DVI_9_1 //
////			wait.delay_10_us(1);
////			Vforce += 0.1;
////		}
////		BPS_dvi->set_voltage(BPS_ch,gVBPS_M_Init - 200e-3, VOLT_10_RANGE); // DVI_9_1 //
////		VO_dvi->set_voltage(VO_ch, 4.5, VOLT_5_RANGE); // DVI_9_0 //
////		wait.delay_10_us(100);
////		BPS_dvi->set_voltage(BPS_ch, gVBPS_final, VOLT_10_RANGE); // DVI_9_1 //
////		wait.delay_10_us(100); // Must wait long enough for uVCC to come up before sending I2C commands. //
////
////		// I2C into test mode. //  
////		Write_Word(g_TM_EN, g_TestMode_Password, NObin, HEX); // Write I2C password for test mode. //
////		Write_Word(g_TM_EN, g_TestMode_Enter, NObin, HEX); // Write I2C key to get into test mode. //
////		Write_Byte(g_Watchdog_Timer, 0x00, NObin, HEX); // Disable watchdog timer //
////
////		// Read the shadow register. //
////		Write_Word(g_RDADDR, g_READ56, NObin, HEX);// SREG0.  Shadow register. //
////		Read_Word(g_RDADDR, READ56_word);// SREG0.  Shadow register. //
////
////		Write_Word(g_RDADDR, g_READ57, NObin, HEX);// SREG1.  Shadow register. //
////		Read_Word(g_RDADDR, READ57_word);// SREG1.  Shadow register. //
////
////		Write_Word(g_RDADDR, g_READ58, NObin, HEX);// SREG2.  Shadow register. //
////		Read_Word(g_RDADDR, READ58_word);// SREG2.  Shadow register. //
////
////		Write_Word(g_RDADDR, g_READ59, NObin, HEX);// SREG3.  Shadow register. //
////		Read_Word(g_RDADDR, READ59_word);// SREG3.  Shadow register. //
////
////		Write_Word(g_RDADDR, g_READ60, NObin, HEX); // SREG4.  Shadow register. //
////		Read_Word(g_RDADDR, READ60_word);// SREG4.  Shadow register. //
////
////		Write_Word(g_RDADDR, g_READ61, NObin, HEX); // SREG5.  Shadow register. //
////		Read_Word(g_RDADDR, READ61_word); // SREG5.  Shadow register. //
////
////		Write_Word(g_RDADDR, g_READ62, NObin, HEX); // SREG6.  Shadow register. //
////		Read_Word(g_RDADDR, READ62_word); // SREG6.  Shadow register. //
////
////		// Save results that were read out of shadow register //
////		ReadResult[0] = READ56_word[0];
////		ReadResult[1] = READ56_word[1];
////		ReadResult[2] = READ56_word[2];
////		ReadResult[3] = READ56_word[3];
////		ReadResult[4] = READ56_word[4];
////		ReadResult[5] = READ56_word[5];
////		ReadResult[6] = READ56_word[6];
////		ReadResult[7] = READ56_word[7];
////		ReadResult[8] = READ56_word[8];
////		ReadResult[9] = READ56_word[9];
////		ReadResult[10] = READ56_word[10];
////		ReadResult[11] = READ56_word[11];
////		ReadResult[12] = READ56_word[12];
////		ReadResult[13] = READ56_word[13];
////		ReadResult[14] = READ56_word[14];
////		ReadResult[15] = READ56_word[15];
////		ReadResult[16] = READ57_word[0];
////		ReadResult[17] = READ57_word[1];
////		ReadResult[18] = READ57_word[2];
////		ReadResult[19] = READ57_word[3];
////		ReadResult[20] = READ57_word[4];
////		ReadResult[21] = READ57_word[5];
////		ReadResult[22] = READ57_word[6];
////		ReadResult[23] = READ57_word[7];
////		ReadResult[24] = READ57_word[8];
////		ReadResult[25] = READ57_word[9];
////		ReadResult[26] = READ57_word[10];
////		ReadResult[27] = READ57_word[11];
////		ReadResult[28] = READ57_word[12];
////		ReadResult[29] = READ57_word[13];
////		ReadResult[30] = READ57_word[14];
////		ReadResult[31] = READ57_word[15];
////		ReadResult[32] = READ58_word[0];
////		ReadResult[33] = READ58_word[1];
////		ReadResult[34] = READ58_word[2];
////		ReadResult[35] = READ58_word[3];
////		ReadResult[36] = READ58_word[4];
////		ReadResult[37] = READ58_word[5];
////		ReadResult[38] = READ58_word[6];
////		ReadResult[39] = READ58_word[7];
////		ReadResult[40] = READ58_word[8];
////		ReadResult[41] = READ58_word[9];
////		ReadResult[42] = READ58_word[10];
////		ReadResult[43] = READ58_word[11];
////		ReadResult[44] = READ58_word[12];
////		ReadResult[45] = READ58_word[13];
////		ReadResult[46] = READ58_word[14];
////		ReadResult[47] = READ58_word[15];
////		ReadResult[48] = READ59_word[0];
////		ReadResult[49] = READ59_word[1];
////		ReadResult[50] = READ59_word[2];
////		ReadResult[51] = READ59_word[3];
////		ReadResult[52] = READ59_word[4];
////		ReadResult[53] = READ59_word[5];
////		ReadResult[54] = READ59_word[6];
////		ReadResult[55] = READ59_word[7];
////		ReadResult[56] = READ59_word[8];
////		ReadResult[57] = READ59_word[9];
////		ReadResult[58] = READ59_word[10];
////		ReadResult[59] = READ59_word[11];
////		ReadResult[60] = READ59_word[12];
////		ReadResult[61] = READ59_word[13];
////		ReadResult[62] = READ59_word[14];
////		ReadResult[63] = READ59_word[15];
////		ReadResult[64] = READ60_word[0];
////		ReadResult[65] = READ60_word[1];
////		ReadResult[66] = READ60_word[2];
////		ReadResult[67] = READ60_word[3];
////		ReadResult[68] = READ60_word[4];
////		ReadResult[69] = READ60_word[5];
////		ReadResult[70] = READ60_word[6];
////		ReadResult[71] = READ60_word[7];
////		ReadResult[72] = READ60_word[8];
////		ReadResult[73] = READ60_word[9];
////		ReadResult[74] = READ60_word[10];
////		ReadResult[75] = READ60_word[11];
////		ReadResult[76] = READ60_word[12];
////		ReadResult[77] = READ60_word[13];
////		ReadResult[78] = READ60_word[14];
////		ReadResult[79] = READ60_word[15];
////		ReadResult[80] = READ61_word[0];
////		ReadResult[81] = READ61_word[1];
////		ReadResult[82] = READ61_word[2];
////		ReadResult[83] = READ61_word[3];
////		ReadResult[84] = READ61_word[4];
////		ReadResult[85] = READ61_word[5];
////		ReadResult[86] = READ61_word[6];
////		ReadResult[87] = READ61_word[7];
////		ReadResult[88] = READ61_word[8];
////		ReadResult[89] = READ61_word[9];
////		ReadResult[90] = READ61_word[10];
////		ReadResult[91] = READ61_word[11];
////		ReadResult[92] = READ61_word[12];
////		ReadResult[93] = READ61_word[13];
////		ReadResult[94] = READ61_word[14];
////		ReadResult[95] = READ61_word[15];
////		ReadResult[96] = READ62_word[0];
////		ReadResult[97] = READ62_word[1];
////		ReadResult[98] = READ62_word[2];
////		ReadResult[99] = READ62_word[3];
////		ReadResult[100] = READ62_word[4];
////		ReadResult[101] = READ62_word[5];
////		ReadResult[102] = READ62_word[6];
////		ReadResult[103] = READ62_word[7];
////		ReadResult[104] = READ62_word[8];
////		ReadResult[105] = READ62_word[9];
////		ReadResult[106] = READ62_word[10];
////		ReadResult[107] = READ62_word[11];
////		ReadResult[108] = READ62_word[12];
////		ReadResult[109] = READ62_word[13];
////		ReadResult[110] = READ62_word[14];
////		ReadResult[111] = READ62_word[15];
////
////		// Compare read results to expected. //
////		// After erase, expect all shadow register bits to be 0. //
////		EEPROM_Erase = 1;
////		for (i=0;i<112;i++)
////		{
////			if (ReadResult[i] != 0)
////			{
////				EEPROM_Erase = -999;
////				g_Error_Flag = -126;
////			}
////		}
////
////		// If erased correctly, all shadow register bits will be zero, then set g_ShadowRegister[] array to all zeros. //
////		if (EEPROM_Erase == 1)
////		{
////			for (i=0;i<112;i++)
////			{
////				g_ShadowRegister[i] = 0;
////			}
////		}
////
////		// Powerdown //
////		SR_dvi2k->set_current(SR_ch, 20.0e-3, RANGE_20_MA); // DVI_13_1, dvi2k //
////		Mux20_Open_relay(K64);
////		ovi_3->set_voltage(OVI_CHANNEL_7, 0.0, RANGE_10_V); // OVI_3_7 //
////		Mux20_Open_relay(K37);
////		Mux20_Open_relay(K38);
////		Mux20_Open_relay(K40);
////		Mux20_Open_relay(K39);
////		Mux20_Open_relay(K50); // SR pin hard short to GND with relay //
////		VO_dvi->set_voltage(VO_ch, 0, VOLT_5_RANGE); // DVI_9_0 //
////		wait.delay_10_us(20);
////		Open_relay(K18);
////		FW_dvi->set_voltage(FW_ch, 0, VOLT_10_RANGE); // DVI_11_1 //
////		uVCC_ovi->set_current(uVCC_ch, 30e-3, RANGE_30_MA); // OVI_3_2 //
////		uVCCrampDown(0.5, 0, 0.1);
////		VBPS_ramp_down(4, 0.2, 200e-3);
////		VBD_dvi->set_voltage(VBD_ch, 3, VOLT_5_RANGE); // DVI_21_0, prevent undershoot //
////		VBD_dvi->set_current(VBD_ch, 30e-3, RANGE_30_MA); // DVI_21_0 //
////		wait.delay_10_us(20);
////		VBD_dvi->set_voltage(VBD_ch, 0, VOLT_5_RANGE); // DVI_21_0 //
////		BPS_dvi->set_voltage(BPS_ch, 0, VOLT_10_RANGE); // DVI_9_1 //
////		FB_ovi->connect(2);
////		ddd_7->ddd_set_clock_period(Dclk_period);
////		ddd_7->ddd_set_voltage_ref(DDD_Vref);
////
////		// DDD level //
////		g_DDD_Low = 0.0; // Save current value //
////		g_DDD_High = 4.0; // Save current value //
////		wait.delay_10_us(g_DDDwait);
////		ddd_7->ddd_set_lo_level(g_DDD_Low); // Will immediately change to this level upon execution 
////		ddd_7->ddd_set_hi_level(g_DDD_High); // Will immediately change to this level upon execution
////		wait.delay_10_us(200); // Wait for relays //
////
////		// Datalog //
////		PiDatalog(func, A_EEPROM_Erase, EEPROM_Erase, 8, POWER_UNIT);
////	}
////
////	// Test Time End //
////	if (g_p_TstTime_Enble)
////	{
////		g_endtime = g_mytimer.GetElapsedTime();
////		IZpre_TT = (g_endtime - g_begintime)*1e-6;
////		PiDatalog(func, A_IZpre_TT, IZpre_TT, 14, POWER_MILLI);
////	}
////
//////g_p_Trim_Enable = 1; // DEBUG ONLY!!! //
////
////	// Check any test failed //
////	if (PiGetAnyFailStatus())		
////	{
////		g_PartFailed = 1;
////	}
}