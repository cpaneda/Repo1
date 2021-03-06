//==============================================================================
// Fosc_Pre_P.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void Fosc_Pre_P_user_init(test_function& func);

// ***********************************************************

void initialize_Fosc_Pre_P(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	Fosc_Pre_P_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_Fosc_Pre_P(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
enum Fosc_Pre_P{
	A_fnum_Fosc_Pre_P,
	A_Fosc_pt_P,
	A_Fosc_Pre_P_TT
};