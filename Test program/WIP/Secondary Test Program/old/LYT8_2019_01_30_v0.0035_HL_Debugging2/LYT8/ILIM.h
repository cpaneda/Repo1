//==============================================================================
// ILIM.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void ILIM_user_init(test_function& func);

// ***********************************************************

void initialize_ILIM(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	ILIM_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_ILIM(test_function &func,char **function_name,char *heading_line,unsigned short *want_Srint,char manual_setup)
{
}

// ***********************************************************
enum ILIM{
	A_Func_Num_ILIM,
	A_ILIM_S,
	A_ILIM_exp_S,
	A_ILIM_act_S,
	A_DIDT_S,
	A_TON_S,
	A_I2F_S,
	A_ILIM_Low_S,
	A_ILIM_Med_S,
	A_ILIM_High_S,
	A_ILIM_RTM_Slope,
	A_tDelta_RTM_Slope_30us_S,
	A_i_pct_drop_RTM,
	A_tDelta_RTM_Slope_200us_S,
	A_ILIM_200us_S,
	A_ILIM_200us_pct_S,
	A_RxTx_CycReq_cnt,
	A_RxTx_Hi_BPS_Low_Rcv,
	A_RxTx_Lo_BPS_Low_Rcv,
	A_RxTx_Hi_BPS_High_Rcv,	//char only
	A_RxTx_Lo_BPS_High_Rcv,	//char only
	A_ILIM_P1_S,
	A_DIDT_P1_S,
	A_TON_P1_S,
	A_I2F_ILIM_Incr_P,
	A_RDSON_P1_S,
	A_Disable_BP_cap,
	A_tSS_hold,
	A_ILIM_TT
};