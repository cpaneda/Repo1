//==============================================================================
// _0_First.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void _0_First_user_init(test_function& func);

// ***********************************************************

void initialize__0_First(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	_0_First_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup__0_First(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
