//==============================================================================
// Fosc_Trim_P.cpp (User function)
// 
//    void Fosc_Trim_P_user_init(test_function& func)
//    void Fosc_Trim_P(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)

#include "Fosc_Trim_P.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void Fosc_Trim_P_user_init(test_function& func)
{
	Fosc_Trim_P_params *ours;
    ours = (Fosc_Trim_P_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void Fosc_Trim_P(test_function& func)
{
    // The two lines below must be the first two in the function.
    Fosc_Trim_P_params *ours;
    ours = (Fosc_Trim_P_params *)func.params;

	// Increment function number //
	gFuncNum++;	
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_Fosc_Trim_P, gFuncNum, 14, POWER_UNIT);
	
	// Skip Test if AbortTest set //
	if (AbortTest)
		return;

	// Skip trimming if g_p_Trim_Enable set //
	if (g_p_Trim_Enable == 0)
		return;

	if (g_Fn_Fosc_Trim_P == 0 )  return;

	// Test Time Begin //
	 if (g_p_TstTime_Enble)
	 	g_begintime = g_mytimer.GetElapsedTime();

	// Declare Variables //
	float IZtr_F1_P1_P =0.0;
	float IZtr_F2_P2_P =0.0;
	float IZtr_F3_M4_P =0.0;
	float trim_weight[8]={0};
	float trim_target=0.0;
	float trim_exp=0.0;
	float trim_needed =0.0;
	float trim_result =0.0;
	float delta;
	int trim_code=0; 
	int plot_code;
	int previous_addr; 
	int trim_addr;
	int clks;
	int i;
	float Fosc_Trim_P_TT = 0;
	Pulse pulse;
								// DN, UP, UP	
	// Trim Weights //			// F3, F2, F1		Trim Code	Plot Code
	trim_weight[0] = 0.0;		// Code: 000			0			 0
	trim_weight[1] = 5.0;		// Code: 001			1			+1
	trim_weight[2] = 10;		// Code: 010			2			+2	
	trim_weight[3] = 15;		// Code: 011			3			+3
	trim_weight[4] = -5;		// Code: 100			4			-1
	trim_weight[5] = -10;		// Code: 101			5			-2
	trim_weight[6] = -15;		// Code: 110			6			-3
	trim_weight[7] = -20; 		// Code: 111			7			-4

	trim_target = gFOSC_TARGET_P_Trimops;

	if(gFosc_pt_P !=0)
		trim_needed = 100.0 * ((trim_target / gFosc_pt_P) -1);	
	else
	{
		trim_needed = 999.0;
		return;
	}

	// Determine Trim Code //
	trim_code = 0;
	delta = 9.99e6; 

	// Auto Trim Code
	for(i =0; i<8 ;i++) // i< 2^(#of bits)
	{
		trim_result =  gFosc_pt_P*(trim_weight[i]/100.0 +1);
		if(fabs(trim_result - trim_target) < delta)
		{
			trim_code = i;
			delta = fabs(trim_result - trim_target);
		}
	}

	if (!g_p_Trim_Enable)
		return;

	// Trim Anti-fuses //
	Powerup_to_trim_primary();
	previous_addr =0;
	trim_addr     =0;
	if(trim_code & 1)
	{
		trim_addr = gP_AF_Start_Addr_Freq;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_F1_P1_P);
		previous_addr =  trim_addr;

		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
		g_xChk_P[13] = 1;

		// Datalog
		PiDatalog(func, A_IZtr_F1_P1_P,	IZtr_F1_P1_P, 14, POWER_MILLI);	
	}
	if(trim_code & 2)
	{
		trim_addr = gP_AF_Start_Addr_Freq + 1;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_F2_P2_P);
		previous_addr =  trim_addr;

		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
		g_xChk_P[14] = 1;
		
		// Datalog
		PiDatalog(func, A_IZtr_F2_P2_P,	IZtr_F2_P2_P, 14, POWER_MILLI);	
	}
	if(trim_code & 4)
	{
		trim_addr = gP_AF_Start_Addr_Freq + 2;
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_F3_M4_P);
		previous_addr =  trim_addr;

		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
		g_xChk_P[15] = 1;

		// Datalog
		PiDatalog(func, A_IZtr_F3_M4_P,	IZtr_F3_M4_P, 14, POWER_MILLI);	
	}
	

	if(trim_code >= 4)
		plot_code = (trim_code -3)*-1;
	else 
		plot_code = trim_code;

	gFOSC_exp_P = trim_weight[trim_code]; // Save value for post-trim change calculation 

	// Powerdown //
	Powerdown_from_trim_primary();

	// Datalog
	PiDatalog(func, A_gFOSC_TARGET_P,trim_target, 14, POWER_KILO);	
	PiDatalog(func, A_Fosc_code_P,	plot_code, 14, POWER_UNIT);	
	PiDatalog(func, A_Fosc_table_P,	trim_weight[trim_code], 14,	POWER_UNIT);	
	PiDatalog(func, A_Fosc_needed_P,trim_needed, 14, POWER_UNIT);	

	// Test Time End //
	if (g_p_TstTime_Enble)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		Fosc_Trim_P_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_Fosc_Trim_P_TT, Fosc_Trim_P_TT, 14, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}
