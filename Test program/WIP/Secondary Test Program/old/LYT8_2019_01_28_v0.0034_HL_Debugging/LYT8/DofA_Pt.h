//==============================================================================
// DofA_Pt.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void DofA_Pt_user_init(test_function& func);

// ***********************************************************

void initialize_DofA_Pt(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	DofA_Pt_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_DofA_Pt(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
enum DofA_Pt{
	A_fNum_DofA_Pt,
	A_DofA_Pt_S,
	A_DofA_Target_S,
	A_DofA_TrCode_S,
	A_DofA_BitCode_S,
	A_EEtr_DofA1_S,
	A_EEtr_DofA2_S,
	A_EEtr_DofA3_S,
	A_EEtr_DofA4_S,
	A_EEtr_DofA5_S,
	A_DofA_Sim_S,
	A_DofA_Sim_Chg_S,
	A_DofA_Pt_TT
};