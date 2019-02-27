//==============================================================================
// Fosc_post_P.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void Fosc_post_P_user_init(test_function& func);

// ***********************************************************

void initialize_Fosc_post_P(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	Fosc_post_P_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_Fosc_post_P(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
enum Fosc_post_P{
	A_Func_Num_Fosc_post_P,
	A_Fosc_post_P,
	A_Fosc_post_P_TT
};