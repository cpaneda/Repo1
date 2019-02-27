//==============================================================================
// Fosc_post_S.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void Fosc_post_S_user_init(test_function& func);

// ***********************************************************

void initialize_Fosc_post_S(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	Fosc_post_S_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_Fosc_post_S(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
enum Fosc_post_S{
	A_Func_Num_Fosc_post_S,
	A_Fosc_Sim_S,
	A_FOSC_Sim_Chg_S,
	A_Fosc_WeakBPS,
	A_HS_PASS_post,
	A_Fosc_post_S_TT
};