//==============================================================================
// nDAC_Pt.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void nDAC_Pt_user_init(test_function& func);

// ***********************************************************

void initialize_nDAC_Pt(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	nDAC_Pt_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_nDAC_Pt(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
enum nDAC_Pt{
	A_fNum_nDAC_Pt,
	A_nDAC_Pt_S,
	A_nDAC_Pt_dlta,
	A_nDAC_Target_S,
	A_nDAC_TrCode_S,
	A_nDAC_BitCode_S,
	A_nDAC_Exp_Chg_S,
	A_EEtr_nDAC1_S,
	A_EEtr_nDAC2_S,
	A_EEtr_nDAC3_S,
	A_EEtr_nDAC4_S,
	A_EEtr_nDAC5_S,
	A_nDAC_Sim_S,
	A_nDAC_Sim_Chg_S,
	A_nDAC_Pt_TT
};