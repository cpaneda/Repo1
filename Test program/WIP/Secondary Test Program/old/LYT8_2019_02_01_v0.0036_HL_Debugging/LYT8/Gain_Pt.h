//==============================================================================
// Gain_Pt.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void Gain_Pt_user_init(test_function& func);

// ***********************************************************

void initialize_Gain_Pt(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	Gain_Pt_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_Gain_Pt(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
enum Gain_Pt{
	A_fNum_Gain_Pt,
	A_Gain_Pt_S,
	A_Gain_Target_S,
	A_Gain_TrCode_S,
	A_Gain_BitCode_S,
	A_EEtr_Gain1_S,
	A_EEtr_Gain2_S,
	A_EEtr_Gain3_S,
	A_EEtr_Gain4_S,
	A_Gain_Sim_S,
	A_Gain_Sim_Chg_S,
	A_Gain_Pt_TT	
};