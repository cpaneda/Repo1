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
	A_Fosc_Pre_P_TT,


	fnum_TMin_Tr_P,
	TonMin_pt_P,
	TonMin_target_P,
	TonMin_code_P,
	TonMin_BitCode_P,
	TonMin_needed_P,
	EeTr77_TonM0_P,
	EeTr78_TonM1_P,
	EeTr79_TonM2_P,
	TonMin_Sim,
	TonM_Sim_Chg,
	TonMin_pst_P,
	TonMin_Tr_P_TT,

};