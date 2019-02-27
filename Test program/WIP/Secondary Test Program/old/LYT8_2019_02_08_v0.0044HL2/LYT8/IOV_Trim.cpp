//==============================================================================
// IOV_Trim.cpp (User function)
// 
//    void IOV_Trim_user_init(test_function& func)
//    void IOV_Trim(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "IOV_Trim.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void IOV_Trim_user_init(test_function& func)
{
	IOV_Trim_params *ours;
    ours = (IOV_Trim_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void IOV_Trim(test_function& func)
{
    // The two lines below must be the first two in the function.
    IOV_Trim_params *ours;
    ours = (IOV_Trim_params *)func.params;

	// Increment function number //
	gFuncNum++;	

////	// Datalog gFuncNum variable //
////	if(gDisplay_FuncNum)
////		PiDatalog(func, A_Func_Num_IOV_Trim, gFuncNum, 24, POWER_UNIT);
////
////	//Skip Test if AbortTest set 
////	if (AbortTest)
////		return;
////						
////	// Skip trimming if g_p_Trim_Enable set //
////	if (g_p_Trim_Enable == 0)
////		return;
////
////	if (g_Fn_IOV_Trim == 0 )  return;
////
////	// Test Time Begin //
////	 if (g_p_TstTime_Enble)
////	 	g_begintime = g_mytimer.GetElapsedTime();
////
////	// Declare Variables //
////	float IZtr_IOV1_P		=0.0,
////		  IZtr_IOV2_P		=0.0,
////		  IZtr_IOV3_P		=0.0,
////		  IZtr_IOV4_P		=0.0,
////		  IZtr_IOV5_P		=0.0,
////		  IZtr_iov_Off_P	=0.0;
////	float IOV_Trim_TT = 0;
////
////	float trim_weight[32]={0};		
////	float trim_target=0.0,trim_exp=0.0;
////	float trim_needed =0.0, trim_result =0.0;
////	float delta=0;
////	int	  trim_code=0, plot_code;
////	//int	  Force_Trim =0;
////
////	int   previous_addr=0, trim_addr=0, clks=0;
////	int	  i=0;
////	Pulse pulse;
////
/////*****************************************************************************
/////*************************** Bitweight Table *********************************
/////*****************************************************************************
////		(Active)										(Don't use)
////	IOV5, IOV4, IOV3, IOV2, IOV1				IOV5, IOV4, IOV3, IOV2, IOV1				
////	----------------------------				----------------------------
////	sign  -8%	-4%	  -2%   -1%					sign  +8%	+4%	  +2%   +1%	
////	----------------------------				----------------------------
////
////	Code(Bin)	Code(Int)	Bitweight(%)		Code(Bin)	Code(Int)	Bitweight(%)		
////							Plot_code(ForceCode)						Plot_code
////	------------------------------------		------------------------------------		
////	00000		=0			=0					00000		=0			=0					
////	00001		=1			=-1					00001		=1			=1					
////	00010		=2			=-2					00010		=2			=2					
////	00011		=3			=-3					00011		=3			=3					
////	00100		=4			=-4					00100		=4			=4					
////	00101		=5			=-5					00101		=5			=5					
////	00110		=6			=-6					00110		=6			=6					
////	00111		=7			=-7					00111		=7			=7					
////	01000		=8			=-8					01000		=8			=8					
////	01001		=9			=-9					01001		=9			=9					
////	01010		=10			=-10				01010		=10			=10					
////	01011		=11			=-11				01011		=11			=11					
////	01100		=12			=-12				01100		=12			=12					
////	01101		=13			=-13				01101		=13			=13					
////	01110		=14			=-14				01110		=14			=14					
////	01111		=15			=-15				01111		=15			=15					
////	10000		=16			=1					10000		=16			=-1					
////	10001		=17			=2					10001		=17			=-2					
////	10010		=18			=3					10010		=18			=-3					
////	10011		=19			=4					10011		=19			=-4					
////	10100		=20			=5					10100		=20			=-5					
////	10101		=21			=6					10101		=21			=-6					
////	10110		=22			=7					10110		=22			=-7					
////	10111		=23			=8					10111		=23			=-8					
////	11000		=24			=9					11000		=24			=-9					
////	11001		=25			=10					11001		=25			=-10					
////	11010		=26			=11					11010		=26			=-11						
////	11011		=27			=12					11011		=27			=-12				
////	11100		=28			=13					11100		=28			=-13			
////	11101		=29			=14					11101		=29			=-14				
////	11110		=30			=15					11110		=30			=-15				
////	11111		=31			=16					11111		=31			=-16				
////*****************************************************************************/
////
////	trim_weight[0] = 0;	
////	trim_weight[1] = -1;	
////	trim_weight[2] = -2;	
////	trim_weight[3] = -3;	
////	trim_weight[4] = -4;	
////	trim_weight[5] = -5;	
////	trim_weight[6] = -6;	
////	trim_weight[7] = -7;	
////	trim_weight[8] = -8;	
////	trim_weight[9] = -9;	
////	trim_weight[10] = -10;
////	trim_weight[11] = -11;
////	trim_weight[12] = -12;
////	trim_weight[13] = -13;
////	trim_weight[14] = -14;
////	trim_weight[15] = -15;
////	trim_weight[16] = 1;
////	trim_weight[17] = 2;
////	trim_weight[18] = 3;
////	trim_weight[19] = 4;
////	trim_weight[20] = 5;
////	trim_weight[21] = 6;
////	trim_weight[22] = 7;
////	trim_weight[23] = 8;
////	trim_weight[24] = 9;
////	trim_weight[25] = 10;
////	trim_weight[26] = 11;
////	trim_weight[27] = 12;
////	trim_weight[28] = 13;
////	trim_weight[29] = 14;
////	trim_weight[30] = 15;
////	trim_weight[31] = 16;
////	//trim_weight[30] = 16;
////	//trim_weight[31] = 18;
////
////	trim_target = giOV_plus_TARGET_Trimops;
////
////	/***************************************************************************************************************
////	******************	Equation to use for calcuating iOV trim_needed => [(Pre/tgt) - 1] * 100				********
////	****************************************************************************************************************
////	Note that fabs[(tgt/Pre-1)*100] does not equal to fabs[(Pre/tgt-1)*100]
////	
////	i.e.  Pre = 124uA		Target = 115uA
////	(tgt/Pre-1)*100 => -7.258%
////	(Pre/tgt-1)*100 => +7.826%	(They are not equal to each other)
////
////	iOV is design to work with (Pre/tgt -1)*100 formula 
////	(It is the only parameter does this.  To make the trimweight make sense when we look at datalog, define the 
////	 trimweight inversely instead so there won't be confusion.  Pre=124uA trim to Tgt=115 require -7.826% trim down)
////	 So, trim_needed function will be [(Pre/tgt-1) * 100]*-1
////	***************************************************************************************************************/
////
////	if(giOV_plus_Pt_P !=0 && giOV_plus_Pt_P < 990.0)
////		trim_needed = ((giOV_plus_Pt_P / trim_target) -1)*100*-1;	
////	else
////	{
////		trim_needed = 999.0;
////		return;
////	}
////
////// ********** Determine Trim Code ****** //
////	trim_code = 0;
////	delta = 9.99e6; 
////
////	// Auto Trim Code
////	for(i =0; i<32 ;i++)			// i< 2^(#of bits)
////	{
////		trim_result =  giOV_plus_Pt_P / (1 - trim_weight[i]/100.0);
////		//trim_result =  giOV_plus_Pt_P*(trim_weight[i]/100.0 +1);
////		if(fabs(trim_result - trim_target) < delta)
////		{
////			trim_code = i;
////			delta = fabs(trim_result - trim_target);
////		}
////	}
////
////	if (!g_p_Trim_Enable)
////		return;
////
////// ********** Trim Anti-fuses **************//
////	Powerup_to_trim_primary();
////
////	previous_addr =0;
////	trim_addr     =0;
////	if(trim_code & 1)		//IOV1
////	{
////		trim_addr = gP_AF_Start_Addr_IOV; //12
////		clks = trim_addr - previous_addr;
////		DDD_Clock_UV_Antifuse(clks);
////
////		Trim_Anti_fuse_primary(&IZtr_IOV1_P);
////		previous_addr =  trim_addr;
////		
////		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
////		g_xChk_P[1] = 1;
////
////		// Datalog
////		PiDatalog(func, A_IZtr_IOV1_P,	IZtr_IOV1_P,		24,	POWER_MILLI);	
////	}
////	if(trim_code & 2)		//IOV2
////	{
////		trim_addr = gP_AF_Start_Addr_IOV + 1; 
////		clks = trim_addr - previous_addr;
////		DDD_Clock_UV_Antifuse(clks);
////
////		Trim_Anti_fuse_primary(&IZtr_IOV2_P);
////		previous_addr =  trim_addr;
////
////		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
////		g_xChk_P[2] = 1;
////
////		// Datalog
////		PiDatalog(func, A_IZtr_IOV2_P,	IZtr_IOV2_P,		24,	POWER_MILLI);	
////	}
////	if(trim_code & 4)		//IOV3
////	{
////		trim_addr = gP_AF_Start_Addr_IOV + 2; 
////		clks = trim_addr - previous_addr;
////		DDD_Clock_UV_Antifuse(clks);
////
////		Trim_Anti_fuse_primary(&IZtr_IOV3_P);
////		previous_addr =  trim_addr;
////		
////		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
////		g_xChk_P[3] = 1;
////
////		// Datalog
////		PiDatalog(func, A_IZtr_IOV3_P,	IZtr_IOV3_P,		24,	POWER_MILLI);	
////	}
////	if(trim_code & 8)		//IOV4
////	{
////		trim_addr = gP_AF_Start_Addr_IOV + 3; 
////		clks = trim_addr - previous_addr;
////		DDD_Clock_UV_Antifuse(clks);
////
////		Trim_Anti_fuse_primary(&IZtr_IOV4_P);
////		previous_addr =  trim_addr;
////
////		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
////		g_xChk_P[4] = 1;
////
////		// Datalog
////		PiDatalog(func, A_IZtr_IOV4_P,	IZtr_IOV4_P,		24,	POWER_MILLI);	
////	}	
////	if(trim_code & 16)		//IOV5
////	{
////		trim_addr = gP_AF_Start_Addr_IOV + 4; 
////		clks = trim_addr - previous_addr;
////		DDD_Clock_UV_Antifuse(clks);
////
////		Trim_Anti_fuse_primary(&IZtr_IOV5_P);
////		previous_addr =  trim_addr;
////
////		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
////		g_xChk_P[5] = 1;
////
////		//Datalog
////		PiDatalog(func, A_IZtr_IOV5_P,	IZtr_IOV5_P,		24,	POWER_MILLI);	
////	}
////	if(trim_code >= 16)
////		plot_code = (trim_code -15);
////	else 
////		plot_code = -trim_code;
////
////	giOV_plus_exp = trim_weight[trim_code];	// Save value for post-trim change calculation 
////
////
////	if(gTrim_iov_Off_P_Trimops)
////	{
////		trim_addr = gP_AF_Start_Addr_IuvIov_Disable;
////		clks = trim_addr - previous_addr;
////		DDD_Clock_UV_Antifuse(clks);
////
////		Trim_Anti_fuse_primary(&IZtr_iov_Off_P);
////		previous_addr =  trim_addr;
////
////		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
////		g_xChk_P[16] = 1;
////
////		// Datalog
////		PiDatalog(func, A_IZtr_iov_Off_P,	IZtr_iov_Off_P,		24,	POWER_MILLI);	
////	}
////
////	// Powerdown //
////	Powerdown_from_trim_primary();
////
////	//Datalog
////	PiDatalog(func, A_giOV_plus_TARGET, trim_target, 24, POWER_MICRO);	
////	PiDatalog(func, A_iOV_plus_code_P, plot_code, 24, POWER_UNIT);	
////	PiDatalog(func, A_iOV_plus_table_P, trim_weight[trim_code], 24, POWER_UNIT);	
////	PiDatalog(func, A_iOV_plus_needed_P, trim_needed, 24, POWER_UNIT);
////
////	// Test Time End //
////	if (g_p_TstTime_Enble)
////	{
////		g_endtime = g_mytimer.GetElapsedTime();
////		IOV_Trim_TT = (g_endtime - g_begintime)*1e-6;
////		PiDatalog(func, A_IOV_Trim_TT, IOV_Trim_TT, 24, POWER_MILLI);
////	}
////
////	// Check any test failed //
////	if (PiGetAnyFailStatus())		
////	{
////		g_PartFailed = 1;
////	}
}
