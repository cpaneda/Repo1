//==============================================================================
// ISvth3X_Pre_S.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void ISvth3X_Pre_S_user_init(test_function& func);

// ***********************************************************

void initialize_ISvth3X_Pre_S(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	ISvth3X_Pre_S_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_ISvth3X_Pre_S(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
enum ISvth3X_Pre_S{
	A_Func_Num_ISvth_Pre_S,
	A_ISvth3X_pt_S,
	A_gISvth_TARGET_S,
	A_ISvth_TrCode_S,
	A_ISvth_BitCode_S,
	A_IZtr_ISvth3X1_S,
	A_IZtr_ISvth3X2_S,
	A_IZtr_ISvth3X3_S,
	A_IZtr_ISvth3X4_S,
	A_IZtr_ISvth3X5_S,
	A_IZtr_ISvth3X6_S,
	A_ISvth3X_Sim_S,
	A_ISvth_Sim_Chg_S,
	A_ISvth_Pre_S_TT
};