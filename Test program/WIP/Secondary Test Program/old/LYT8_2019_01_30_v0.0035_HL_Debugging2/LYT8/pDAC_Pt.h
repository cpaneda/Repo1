//==============================================================================
// pDAC_Pt.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void pDAC_Pt_user_init(test_function& func);

// ***********************************************************

void initialize_pDAC_Pt(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	pDAC_Pt_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_pDAC_Pt(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
enum pDAC_Pt{
	A_fNum_pDAC_Pt,
	A_pDAC_Pt_S,
	A_pDAC_Pt_dlta,
	A_pDAC_Target_S,
	A_pDAC_TrCode_S,
	A_pDAC_BitCode_S,
	A_EEtr_pDAC1_S,
	A_EEtr_pDAC2_S,
	A_EEtr_pDAC3_S,
	A_EEtr_pDAC4_S,
	A_EEtr_pDAC5_S,
	A_pDAC_Sim_S,
	A_pDAC_Sim_Chg_S,
	A_pDAC_Pt_TT	
};