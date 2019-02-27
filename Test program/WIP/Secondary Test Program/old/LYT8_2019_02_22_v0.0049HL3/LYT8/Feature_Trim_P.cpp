//==============================================================================
// Feature_Trim_P.cpp (User function)
// 
//    void Feature_Trim_P_user_init(test_function& func)
//    void Feature_Trim_P(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "Feature_Trim_P.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void Feature_Trim_P_user_init(test_function& func)
{
	Feature_Trim_P_params *ours;
    ours = (Feature_Trim_P_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void Feature_Trim_P(test_function& func)
{
    // The two lines below must be the first two in the function.
    Feature_Trim_P_params *ours;
    ours = (Feature_Trim_P_params *)func.params;

	// Increment function number //
	gFuncNum++;
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_Feature_Trim_P, gFuncNum, 26, POWER_UNIT);

	// Skip Test if AbortTest set //
	if (AbortTest)
		return;

	// Skip trimming if g_Trim_Enable_P set //
	if (g_Trim_Enable_P == 0)
		return;

	if (g_Fn_Feature_Trim_P == 0 )  return;

	// Test Time Begin //
	 if (g_TstTime_Enble_P)
	 	g_begintime = g_mytimer.GetElapsedTime();
	
	// Declare Variables //
	Pulse pulse;
	float fNum_FetrTrim_P = 0;

	float IZtr_iov_Off_P = 0;
	float IZtr_iuvMinus_P =0;	//iUV+ @10uA
	float IZtr_uvDelay_P =0;
	float IZtr_Loff_AR_P =0;
	float IZtr_DisablAR_P =0;
	float IZtr_didtComp_P =0;
	float IZtr_OT_Hys_P =0;
	float IZtr_LoffwOT_P =0;
	float IZtr_iLselOff_P =0;
	float IZtr_iLStdIcr_P =0;
	float IZtr_iL20dn_P =0;
	float IZtr_iL20up_P =0;
	float IZtr_SAM_P =0;
	float IZtr_OTP1_P =0;
	float IZtr_OTP2_P =0;
	float IZtr_OTP3_P =0;
	float IZtr_SDSoff_P = 0;
	float IZtr_Rcv1_P =0;
	float IZtr_Rcv2_P =0;
	float IZtr_RcvSign_P =0;
	float IZtr_drvSize1_P =0;
	float IZtr_drvSize2_P =0;
	float IZtr_drvSize3_P =0;
	float IZtr_drvSize4_P =0;
	float IZtr_RsenseUp_P =0;
	float IZtr_vxAdj1_P =0;
	float IZtr_vxAdj2_P =0;
	float IZtr_vxAdj3_P =0;
	float IZtr_vxAdj4_P =0;
	float IZtr_vxAdj5_P =0;
	float IZtr_iLRatio1_P =0;
	float IZtr_iLRatio2_P =0;
	float IZtr_iLRatio3_P =0;
	float IZtr_iLRatio4_P =0;
	float IZtr_iLTC1_P =0;
	float IZtr_iLTC2_P =0;
	float IZtr_iLTC3_P =0;
	float IZtr_iLTC4_P =0;
	float IZtr_AR_req_P =0;
	float Fetur_Trim_P_TT = 0;

	bool Trim_iov_Off_P =false;
	bool Trim_iuvMinus_P = false;
	bool Trim_uvDelay_P = false;
	bool Trim_Loff_AR_P = false;
	bool Trim_DisablAR_P = false;
	bool Trim_didtComp_P = false;
	bool Trim_OT_Hys_P = false;
	bool Trim_LoffwOT_P = false;
	bool Trim_iLselOff_P = false;
	bool Trim_iLStdIcr_P = false;
	bool Trim_iL20dn_P = false;
	bool Trim_iL20up_P = false;
	bool Trim_SAM_P = false;
	bool Trim_OTP1_P = false;
	bool Trim_OTP2_P = false;
	bool Trim_OTP3_P = false;
	bool Trim_SDSoff_P = false;
	bool Trim_Rcv1_P = false;
	bool Trim_Rcv2_P = false;
	bool Trim_RcvSign_P = false;
	bool Trim_drvSize1_P = false;
	bool Trim_drvSize2_P = false;
	bool Trim_drvSize3_P = false;
	bool Trim_drvSize4_P = false;
	bool Trim_RsenseUp_P = false;
	bool Trim_vxAdj1_P = false;
	bool Trim_vxAdj2_P = false;
	bool Trim_vxAdj3_P = false;
	bool Trim_vxAdj4_P = false;
	bool Trim_vxAdj5_P = false;
	bool Trim_iLRatio1_P = false;
	bool Trim_iLRatio2_P = false;
	bool Trim_iLRatio3_P = false;
	bool Trim_iLRatio4_P = false;
	bool Trim_iLTC1_P = false;
	bool Trim_iLTC2_P = false;
	bool Trim_iLTC3_P = false;
	bool Trim_iLTC4_P = false;
	bool Trim_AR_req_P = false;

	// Initializ based on trimops table. //
	Trim_iov_Off_P =gTrim_iov_Off_P_Trimops;
	Trim_iuvMinus_P =gTrim_iuvMinus_P_Trimops;
	Trim_uvDelay_P =gTrim_uvDelay_P_Trimops;
	Trim_Loff_AR_P =gTrim_Loff_AR_P_Trimops;
	Trim_DisablAR_P =gTrim_DisablAR_P_Trimops;
	Trim_didtComp_P =gTrim_didtComp_P_Trimops;
	Trim_OT_Hys_P =gTrim_OT_Hys_P;
	Trim_LoffwOT_P =gTrim_LoffwOT_P_Trimops;
	Trim_iLselOff_P =gTrim_iLselOff_P_Trimops;
	Trim_iLStdIcr_P =gTrim_iLStdIcr_P_Trimops;
	Trim_iL20dn_P =gTrim_iL20dn_P_Trimops;
	Trim_iL20up_P =gTrim_iL20up_P_Trimops;
	Trim_SAM_P =gTrim_SAM_P_Trimops;

	//Determine OTP trim bits,			3 bits
	if((gTrim_OTP_P_Trimops & 1) == 1)		Trim_OTP1_P = 1;
	if((gTrim_OTP_P_Trimops & 2) == 2)		Trim_OTP2_P = 1;
	if((gTrim_OTP_P_Trimops & 4) == 4)		Trim_OTP3_P = 1;

	Trim_SDSoff_P = gTrim_SDSoff_P_Trimops;

	//Determine Rcv trim bits,			3 bits
	if((gTrim_Rcv_P_Trimops & 1) == 1)		Trim_Rcv1_P = 1;
	if((gTrim_Rcv_P_Trimops & 2) == 2)		Trim_Rcv2_P = 1;
	if((gTrim_Rcv_P_Trimops & 4) == 4)		Trim_RcvSign_P = 1;

	//Determine Driver Size trim bits,	4 bits
	if((gTrim_drvSize_P_Trimops & 1) == 1)	Trim_drvSize1_P = 1;
	if((gTrim_drvSize_P_Trimops & 2) == 2)	Trim_drvSize2_P = 1;
	if((gTrim_drvSize_P_Trimops & 4) == 4)	Trim_drvSize3_P = 1;
	if((gTrim_drvSize_P_Trimops & 8) == 8)	Trim_drvSize4_P = 1;

	Trim_RsenseUp_P =gTrim_RsenseUp_P_Trimops;

	//Determine vxAdj trim bits,		5 bits
	if((gTrim_vxAdj_P_Trimops & 1) == 1)	Trim_vxAdj1_P = 1;
	if((gTrim_vxAdj_P_Trimops & 2) == 2)	Trim_vxAdj2_P = 1;
	if((gTrim_vxAdj_P_Trimops & 4) == 4)	Trim_vxAdj3_P = 1;
	if((gTrim_vxAdj_P_Trimops & 8) == 8)	Trim_vxAdj4_P = 1;
	if((gTrim_vxAdj_P_Trimops & 16) == 16)	Trim_vxAdj5_P = 1;

	//Determine ILIM Ratio trim bits,	4 bits
	if((gTrim_iLRatio_P_Trimops & 1) == 1)	Trim_iLRatio1_P = 1;
	if((gTrim_iLRatio_P_Trimops & 2) == 2)	Trim_iLRatio2_P = 1;
	if((gTrim_iLRatio_P_Trimops & 4) == 4)	Trim_iLRatio3_P = 1;
	if((gTrim_iLRatio_P_Trimops & 8) == 8)	Trim_iLRatio4_P = 1;

	//Determine ILIM TC trim bits,		4 bits
	if((gTrim_iLTC_P_Trimops & 1) == 1)		Trim_iLTC1_P = 1;
	if((gTrim_iLTC_P_Trimops & 2) == 2)		Trim_iLTC2_P = 1;
	if((gTrim_iLTC_P_Trimops & 4) == 4)		Trim_iLTC3_P = 1;
	if((gTrim_iLTC_P_Trimops & 8) == 8)		Trim_iLTC4_P = 1;

	Trim_AR_req_P =gTrim_AR_req_Trimops;

	// Declare Variables //
	int	  trim_code=0, plot_code=0;
	int	  Force_Trim = 0;
	int   previous_addr=0, trim_addr=0, clks=0;
	int	  i=0;

	//Trim Features for Primary (See OTS/TestPlan)
	Powerup_to_trim_primary();
	previous_addr =0;
	trim_addr     =0;

	//Individual Feature Bits
	if(Trim_iuvMinus_P)
	{
		trim_addr = gP_AF_Start_Addr_Iuv_10uA;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iuvMinus_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iuvMinus_P, IZtr_iuvMinus_P, 26, POWER_MILLI);
	}
	if(Trim_uvDelay_P)
	{
		trim_addr = gP_AF_Start_Addr_UV_400ms_dly;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_uvDelay_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_uvDelay_P, IZtr_uvDelay_P, 26, POWER_MILLI);
	}
	if(Trim_Loff_AR_P)
	{
		trim_addr = gP_AF_Start_Addr_LatchOFF_aft_AR;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_Loff_AR_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_Loff_AR_P, IZtr_Loff_AR_P, 26, POWER_MILLI);

	}
	if(Trim_DisablAR_P)
	{
		trim_addr = gP_AF_Start_Addr_Disable_AR;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_DisablAR_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_DisablAR_P, IZtr_DisablAR_P, 26, POWER_MILLI);
	}
	if(Trim_didtComp_P)
	{
		trim_addr = gP_AF_Start_Addr_didt_comp;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_didtComp_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_didtComp_P, IZtr_didtComp_P, 26, POWER_MILLI);
	}
	if(Trim_OT_Hys_P)
	{
		trim_addr = gP_AF_Start_Addr_OT_Hys_30C;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_OT_Hys_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_OT_Hys_P, IZtr_OT_Hys_P, 26, POWER_MILLI);
	}
	if(Trim_LoffwOT_P)
	{
		trim_addr = gP_AF_Start_Addr_LatchOFF_w_OT;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_LoffwOT_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_LoffwOT_P, IZtr_LoffwOT_P, 26, POWER_MILLI);
	}
	if(Trim_iLselOff_P)
	{
//		trim_addr = 4;
		trim_addr = gP_AF_Start_Addr_Disable_ILIM_Select;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iLselOff_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iLselOff_P, IZtr_iLselOff_P, 26, POWER_MILLI);
	}
	if(Trim_iLStdIcr_P)
	{
		trim_addr = gP_AF_Start_Addr_Select_ILIM_Incr;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iLStdIcr_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iLStdIcr_P, IZtr_iLStdIcr_P, 26, POWER_MILLI);
	}
	if(Trim_iL20dn_P)
	{
		trim_addr = gP_AF_Start_Addr_minus_20pct_ILIM;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iL20dn_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iL20dn_P, IZtr_iL20dn_P, 26, POWER_MILLI);
	}

	if(Trim_iL20up_P)
	{
		trim_addr = gP_AF_Start_Addr_plus_20pct_ILIM;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iL20up_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iL20up_P, IZtr_iL20up_P, 26, POWER_MILLI);
	}

	if(Trim_SAM_P)
	{
		trim_addr = gP_AF_Start_Addr_Samsung_Mode;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_SAM_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_SAM_P, IZtr_SAM_P, 26, POWER_MILLI);
	}
	if(Trim_OTP1_P)
	{
		trim_addr = gP_AF_Start_Addr_OTP;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_OTP1_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_OTP1_P, IZtr_OTP1_P, 26, POWER_MILLI);
	}
	if(Trim_OTP2_P)
	{
		trim_addr = gP_AF_Start_Addr_OTP +1;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_OTP2_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_OTP2_P, IZtr_OTP2_P, 26, POWER_MILLI);
	}
	if(Trim_OTP3_P)
	{
		trim_addr = gP_AF_Start_Addr_OTP +2;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_OTP3_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_OTP3_P, IZtr_OTP3_P, 26, POWER_MILLI);
	}
	if(Trim_SDSoff_P)
	{
		trim_addr = gP_AF_Start_Addr_SDS_OFF;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_SDSoff_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_SDSoff_P, IZtr_SDSoff_P, 26, POWER_MILLI);
	}
	if(Trim_Rcv1_P)
	{
		trim_addr = gP_AF_Start_Addr_Rcv;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_Rcv1_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_Rcv1_P, IZtr_Rcv1_P, 26, POWER_MILLI);
	}
	if(Trim_Rcv2_P)
	{
		trim_addr = gP_AF_Start_Addr_Rcv +1;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_Rcv2_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_Rcv2_P, IZtr_Rcv2_P, 26, POWER_MILLI);
	}
	if(Trim_RcvSign_P)
	{
		trim_addr = gP_AF_Start_Addr_Rcv +2;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_RcvSign_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_RcvSign_P, IZtr_RcvSign_P, 26, POWER_MILLI);
	}
	if(Trim_drvSize1_P)
	{
		trim_addr = gP_AF_Start_Addr_Driver_Size;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_drvSize1_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_drvSize1_P, IZtr_drvSize1_P, 26, POWER_MILLI);
	}
	if(Trim_drvSize2_P)
	{
		trim_addr = gP_AF_Start_Addr_Driver_Size +1;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_drvSize2_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_drvSize2_P, IZtr_drvSize2_P, 26, POWER_MILLI);
	}
	if(Trim_drvSize3_P)
	{
		trim_addr = gP_AF_Start_Addr_Driver_Size +2;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_drvSize3_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_drvSize3_P, IZtr_drvSize3_P, 26, POWER_MILLI);
	}

	if(Trim_drvSize4_P)
	{
		trim_addr = gP_AF_Start_Addr_Driver_Size +3;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_drvSize4_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_drvSize4_P, IZtr_drvSize4_P, 26, POWER_MILLI);
	}

	if(Trim_RsenseUp_P)
	{
		trim_addr = gP_AF_Start_Addr_Rsense_up;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_RsenseUp_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_RsenseUp_P, IZtr_RsenseUp_P, 26, POWER_MILLI);
	}
	if(Trim_vxAdj1_P)
	{
		trim_addr = gP_AF_Start_Addr_Vx_adjust;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_vxAdj1_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_vxAdj1_P, IZtr_vxAdj1_P, 26, POWER_MILLI);
	}
	if(Trim_vxAdj2_P)
	{
		trim_addr = gP_AF_Start_Addr_Vx_adjust+1;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_vxAdj2_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_vxAdj2_P, IZtr_vxAdj2_P, 26, POWER_MILLI);
	}
	if(Trim_vxAdj3_P)
	{
		trim_addr = gP_AF_Start_Addr_Vx_adjust+2;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_vxAdj3_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_vxAdj3_P, IZtr_vxAdj3_P, 26, POWER_MILLI);
	}

	if(Trim_vxAdj4_P)
	{
		trim_addr = gP_AF_Start_Addr_Vx_adjust+3;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_vxAdj4_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_vxAdj4_P, IZtr_vxAdj4_P, 26, POWER_MILLI);
	}

	if(Trim_vxAdj5_P)
	{
		trim_addr = gP_AF_Start_Addr_Vx_adjust+4;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_vxAdj5_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_vxAdj5_P, IZtr_vxAdj5_P, 26, POWER_MILLI);
	}
	if(Trim_iLRatio1_P)
	{
		trim_addr = gP_AF_Start_Addr_ILIM_Ratio;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iLRatio1_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iLRatio1_P, IZtr_iLRatio1_P, 26, POWER_MILLI);
	}
	if(Trim_iLRatio2_P)
	{
		trim_addr = gP_AF_Start_Addr_ILIM_Ratio+1;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iLRatio2_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iLRatio2_P, IZtr_iLRatio2_P, 26, POWER_MILLI);
	}
	if(Trim_iLRatio3_P)
	{
		trim_addr = gP_AF_Start_Addr_ILIM_Ratio+2;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iLRatio3_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iLRatio3_P, IZtr_iLRatio3_P, 26, POWER_MILLI);
	}
	if(Trim_iLRatio4_P)
	{
		trim_addr = gP_AF_Start_Addr_ILIM_Ratio+3;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iLRatio4_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iLRatio4_P, IZtr_iLRatio4_P, 26, POWER_MILLI);
	}

	if(Trim_iLTC1_P)
	{
		trim_addr = gP_AF_Start_Addr_ILIM_TC;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iLTC1_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iLTC1_P, IZtr_iLTC1_P, 26, POWER_MILLI);
	}
	if(Trim_iLTC2_P)
	{
		trim_addr = gP_AF_Start_Addr_ILIM_TC+1;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iLTC2_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iLTC2_P, IZtr_iLTC2_P, 26, POWER_MILLI);
	}

	if(Trim_iLTC3_P)
	{
		trim_addr = gP_AF_Start_Addr_ILIM_TC+2;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iLTC3_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iLTC3_P, IZtr_iLTC3_P, 26, POWER_MILLI);
	}
	if(Trim_iLTC4_P)
	{
		trim_addr = gP_AF_Start_Addr_ILIM_TC+3;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_iLTC4_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_iLTC4_P, IZtr_iLTC4_P, 26, POWER_MILLI);
	}

	if(Trim_AR_req_P)
	{
		trim_addr = gP_AF_Start_Addr_AR_Request;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_AR_req_P);
		previous_addr =  trim_addr;

		// Datalog
		PiDatalog(func, A_IZtr_AR_req_P, IZtr_AR_req_P, 26, POWER_MILLI);
	}

//END_OF_FUNC:;

	// Powerdown //
	Powerdown_from_trim_primary();

	// Save required trimmed bits to Antifuse array, for checking later in IzPost.cpp function. //
	//g_xChk_P[1] = 0;
	//g_xChk_P[2] = 0;
	//g_xChk_P[3] = 0;
	//g_xChk_P[4] = 0;
	//g_xChk_P[5] = 0;
	//g_xChk_P[6] = 0;
	//g_xChk_P[7] = 0;
	//g_xChk_P[8] = 0;
	//g_xChk_P[9] = 0;
	//g_xChk_P[10] = 0;
	//g_xChk_P[11] = 0;
	//g_xChk_P[12] = 0;
	//g_xChk_P[13] = 0;
	//g_xChk_P[14] = 0;
	//g_xChk_P[15] = 0;
	g_xChk_P[16] = Trim_iov_Off_P;
	g_xChk_P[17] = Trim_iuvMinus_P;
	g_xChk_P[18] = Trim_uvDelay_P;
	g_xChk_P[19] = Trim_Loff_AR_P;
	g_xChk_P[20] = Trim_DisablAR_P;
	g_xChk_P[21] = Trim_didtComp_P;
	g_xChk_P[22] = Trim_OT_Hys_P;
	g_xChk_P[23] = Trim_LoffwOT_P;
	g_xChk_P[24] = Trim_iLselOff_P;
	g_xChk_P[25] = Trim_iLStdIcr_P;
	g_xChk_P[26] = Trim_iL20dn_P;
	g_xChk_P[27] = Trim_iL20up_P;
	g_xChk_P[28] = Trim_SAM_P;
	g_xChk_P[29] = Trim_OTP1_P;
	g_xChk_P[30] = Trim_OTP2_P;
	g_xChk_P[31] = Trim_OTP3_P;
	g_xChk_P[32] = Trim_SDSoff_P;
	g_xChk_P[33] = Trim_Rcv1_P;
	g_xChk_P[34] = Trim_Rcv2_P;
	g_xChk_P[35] = Trim_RcvSign_P;
	g_xChk_P[36] = Trim_drvSize1_P;
	g_xChk_P[37] = Trim_drvSize2_P;
	g_xChk_P[38] = Trim_drvSize3_P;
	g_xChk_P[39] = Trim_drvSize4_P;
	g_xChk_P[40] = Trim_RsenseUp_P;
	g_xChk_P[41] = Trim_vxAdj1_P;
	g_xChk_P[42] = Trim_vxAdj2_P;
	g_xChk_P[43] = Trim_vxAdj3_P;
	g_xChk_P[44] = Trim_vxAdj4_P;
	g_xChk_P[45] = Trim_vxAdj5_P;
	g_xChk_P[46] = Trim_iLRatio1_P;
	g_xChk_P[47] = Trim_iLRatio2_P;
	g_xChk_P[48] = Trim_iLRatio3_P;
	g_xChk_P[49] = Trim_iLRatio4_P;
	g_xChk_P[50] = Trim_iLTC1_P;
	g_xChk_P[51] = Trim_iLTC2_P;
	g_xChk_P[52] = Trim_iLTC3_P;
	g_xChk_P[53] = Trim_iLTC4_P;
	g_xChk_P[54] = Trim_AR_req_P;

	// Test Time End //
	if (g_TstTime_Enble_P)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		Fetur_Trim_P_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_Fetur_Trim_P_TT, Fetur_Trim_P_TT, 26, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}
