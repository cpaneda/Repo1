//==============================================================================
// OSC_Pt.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void OSC_Pt_user_init(test_function& func);

// ***********************************************************

void initialize_OSC_Pt(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	OSC_Pt_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_OSC_Pt(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
enum OSC_Pt{
	A_fNum_OSC_Pt,
	A_OSC_Pt_S,
	A_OSC_Target_S,
	A_OSC_TrCode_S,
	A_OSC_BitCode_S,
	A_EEtr_OSC0_S,
	A_EEtr_OSC1_S,
	A_EEtr_OSC2_S,
	A_EEtr_OSC3_S,
	A_OSC_Sim,
	A_OSC_Sim_Chg,
	A_OSC_Pt_TT
};