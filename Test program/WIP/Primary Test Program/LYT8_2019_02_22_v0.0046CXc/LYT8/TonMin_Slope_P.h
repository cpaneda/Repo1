//==============================================================================
// TonMin_Slope_P.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void TonMin_Slope_P_user_init(test_function& func);

// ***********************************************************

void initialize_TonMin_Slope_P(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	TonMin_Slope_P_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_TonMin_Slope_P(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
