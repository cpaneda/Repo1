//==============================================================================
// ILIM_Trim.cpp (User function)
// 
//    void ILIM_Trim_user_init(test_function& func)
//    void ILIM_Trim(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)
#include "ILIM_Trim.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void ILIM_Trim_user_init(test_function& func)
{
	ILIM_Trim_params *ours;
    ours = (ILIM_Trim_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void ILIM_Trim(test_function& func)
{
    // The two lines below must be the first two in the function.
    ILIM_Trim_params *ours;
    ours = (ILIM_Trim_params *)func.params;

	// Increment function number //
	gFuncNum++;	
/*
	// Datalog gFuncNum variable //
	if(gDisplay_FuncNum)
		PiDatalog(func, A_Func_Num_ILIM_Trim, gFuncNum, 9,	POWER_UNIT);

	// Skip Test if AbortTest set //
	if (AbortTest)
		return;

	// Skip trimming if g_p_Trim_Enable set //
	if (g_p_Trim_Enable == 0)
		return;

	if (g_Fn_ILIM_Trim == 0 )  return;

	// Test Time Begin //
	 if (g_p_TstTime_Enble)
	 	g_begintime = g_mytimer.GetElapsedTime();

	// Temporary set to 1
	gHandShake_PASS = 1;

	// If Handshake wasn't done properly, I2f calculation will be base on primary fosc, which is wrong. 
	if (!gHandShake_PASS)
		return;

	// Declare Variables //
	float IZtr_L1_P =0.0;
	float IZtr_L2_P =0.0;
	float IZtr_L3_P =0.0;
	float IZtr_L4_P =0.0;
	float IZtr_ZF_P =0.0;
	float IZtr_ILIM_Plus30pct_P =0.0;
	float trim_weight[16] ={0}; // Double of what's needed
	float trim_target =0.0;
	float trim_exp =0.0;
	float trim_needed =0.0; 
	float trim_result =0.0;
	float delta =0;
	int trim_code =0;
	int plot_code;
	int previous_addr =0; 
	int	trim_addr =0;
	int	clks =0;
	int i =0;
	float ILIM_Trim_TT =0;
	Pulse pulse;

	//						 DN   ,   UP,   UP,    UP
	// L4,L3,L2,L1		-40.0%, +20.0%, +10%, +5%		Trim Code	Plot Code
	trim_weight[0] = 0.0;		// Code: 0000					0			 0
	trim_weight[1] = 4.87;		// Code: 0001					1			+1
	trim_weight[2] = 9.442;		// Code: 0010					2			+2
	trim_weight[3] = 13.47;		// Code: 0011					3			+3
	trim_weight[4] = 18.527;		// Code: 0100					4			+4
	trim_weight[5] = 23.5;		// Code: 0101					5			+5
	trim_weight[6] = 28.55;		// Code: 0110					6			+6
	trim_weight[7] = 33.31;		// Code: 0111					7			+7
	trim_weight[8] = -4.7;		// Code: 1000					8			-1
	trim_weight[9] = -8.983;		// Code: 1001					9			-2
	trim_weight[10] = -13.772;	// Code: 1010					10			-3
	trim_weight[11] = -18.038;	// Code: 1011					11			-4
	trim_weight[12] = -22.708;	// Code: 1100					12			-5
	trim_weight[13] = -27.81;	// Code: 1101					13			-6
	trim_weight[14] = -32.083;	// Code: 1110					14			-7
	trim_weight[15] = -36.78;	// Code: 1111					15			-8

	// Require Fosc_post_S and ILIM_pt_P to determine target and how much we want to trim.
	if(gFOSC_pt_S !=0)
		trim_target = gILIM_TARGET_S_Trimops;	
	else
	{
		trim_target = 999.0;
		PiDatalog(func, A_gILIM_TARGET_S,gILIM_TARGET_S_Trimops, 9, POWER_MILLI);	
		return;
	}

	if(gILIM_pt_S !=0 && gILIM_pt_S < 990.0)
		trim_needed = 100.0 * ((trim_target / gILIM_pt_S) -1);	
	else
	{
		trim_needed = 999.0;
		return;
	}

	// Determine Trim Code //
	trim_code = 0;
	delta = 9.99e6; 

	// Auto Trim Code
	for(i =0; i<16 ;i++) // i< 2^(#of bits)
	{
		trim_result =  gILIM_pt_S*(trim_weight[i]/100.0 +1);
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

	if(trim_code & 1) // L1
	{
		trim_addr = gP_AF_Start_Addr_ILIM; // 12
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_L1_P);
		previous_addr =  trim_addr;

		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
		g_xChk_P[6] = 1;

		// Datalog
		PiDatalog(func, A_IZtr_L1_P, IZtr_L1_P, 9, POWER_MILLI);	
	}
	if(trim_code & 2)		//L2
	{
		trim_addr = gP_AF_Start_Addr_ILIM + 1; 
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_L2_P);
		previous_addr =  trim_addr;

		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
		g_xChk_P[7] = 1;

		// Datalog
		PiDatalog(func, A_IZtr_L2_P, IZtr_L2_P, 9, POWER_MILLI);	
	}
	if(trim_code & 4)		//L3
	{
		trim_addr = gP_AF_Start_Addr_ILIM + 2; 
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_L3_P);
		previous_addr =  trim_addr;

		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
		g_xChk_P[8] = 1;

		// Datalog
		PiDatalog(func, A_IZtr_L3_P, IZtr_L3_P, 9, POWER_MILLI);	
	}
	if(trim_code & 8)		//C4, ILIM4
	{
		trim_addr = gP_AF_Start_Addr_ILIM + 3; 
		clks = trim_addr - previous_addr;
		DDD_Clock_UV_Antifuse(clks);
		Trim_Anti_fuse_primary(&IZtr_L4_P);
		previous_addr =  trim_addr;

		// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
		g_xChk_P[9] = 1;

		// Datalog
		PiDatalog(func, A_IZtr_L4_P, IZtr_L4_P, 9, POWER_MILLI);	
	}

	trim_addr = gP_AF_Start_Addr_ZF; //48
	clks = trim_addr - previous_addr;
	DDD_Clock_UV_Antifuse(clks);
	Trim_Anti_fuse_primary(&IZtr_ZF_P);
	previous_addr =  trim_addr;

	// Save required trimmed bits to Antifuse array, for checking later in Iz_xChk_TrmCode_P.cpp function. //
	g_xChk_P[55] = 1;

	// Datalog
	PiDatalog(func, A_IZtr_ZF_P, IZtr_ZF_P, 9, POWER_MILLI);	

	if(trim_code >= 8)
		plot_code = (trim_code -7)*-1;
	else 
		plot_code = trim_code;

	gILIM_exp_S = trim_weight[trim_code];	// Save value for post-trim change calculation 

	// Powerdown //
	Powerdown_from_trim_primary();

	// Powerdown //
	//Powerdown_from_trim_primary();
	//Power_Down_Everything();
	//Open_All_Relays();

	// Datalog
	PiDatalog(func, A_gILIM_TARGET_S,gILIM_TARGET_S_Trimops, 9, POWER_MILLI);	
	//PiDatalog(func, A_ILIM_target_adj_P,trim_target, 9, POWER_MILLI);	

	PiDatalog(func, A_ILIM_code_P, plot_code, 9, POWER_UNIT);	
	PiDatalog(func, A_ILIM_table_P, trim_weight[trim_code], 9, POWER_UNIT);	
	PiDatalog(func, A_ILIM_needed_P, trim_needed, 9, POWER_UNIT);	

	// Test Time End //
	if (g_p_TstTime_Enble)
	{
		g_endtime = g_mytimer.GetElapsedTime();
		ILIM_Trim_TT = (g_endtime - g_begintime)*1e-6;
		PiDatalog(func, A_ILIM_Trim_TT, ILIM_Trim_TT, 9, POWER_MILLI);
	}

	// Check any test failed //
	if (PiGetAnyFailStatus())		
	{
		g_PartFailed = 1;
	}
*/
}
