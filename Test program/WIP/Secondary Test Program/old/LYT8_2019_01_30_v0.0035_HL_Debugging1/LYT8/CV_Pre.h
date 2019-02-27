//==============================================================================
// CV_Pre.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void CV_Pre_user_init(test_function& func);

// ***********************************************************

void initialize_CV_Pre(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	CV_Pre_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_CV_Pre(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
enum CV_Pre{
	A_Func_Num_CV_Pre,
	A_CV_pt_S,
	A_CV_target_S,
	A_CV_TrCode_S,
	A_CV_BitCode_S,
	A_Iztr_Vref0_S,
	A_Iztr_Vref1_S,
	A_Iztr_Vref2_S,
	A_Iztr_Vref3_S,
	A_CV_Sim_S,
	A_CV_Sim_Chg_S,
	A_CV_pst_S,
	A_CV_Pre_TT
};