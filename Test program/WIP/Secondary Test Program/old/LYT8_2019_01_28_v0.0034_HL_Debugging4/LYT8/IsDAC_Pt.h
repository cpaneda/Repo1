//==============================================================================
// IsDAC_Pt.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void IsDAC_Pt_user_init(test_function& func);

// ***********************************************************

void initialize_IsDAC_Pt(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	IsDAC_Pt_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_IsDAC_Pt(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
enum IsDAC_Pt{
	A_fNum_IsDAC_Pt,
	A_IsDAC_Pt_S,
	A_IsDAC_Target_S,
	A_IsDAC_TrCode_S,
	A_IsDAC_BitCode_S,
	A_EEtr_IsDAC1_S,
	A_EEtr_IsDAC2_S,
	A_EEtr_IsDAC3_S,
	A_EEtr_IsDAC4_S,
	A_EEtr_IsDAC5_S,
	A_IsDAC_Sim_S,
	A_IsDAC_Sim_Chg_S,
	A_IsDAC_Pt_TT
};