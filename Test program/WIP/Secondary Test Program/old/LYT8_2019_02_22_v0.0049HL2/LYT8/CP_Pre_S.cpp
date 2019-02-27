//==============================================================================
// CP_Pre_S.cpp (User function)
// 
//    void CP_Pre_S_user_init(test_function& func)
//    void CP_Pre_S(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "CP_Pre_S.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void CP_Pre_S_user_init(test_function& func)
{
	CP_Pre_S_params *ours;
    ours = (CP_Pre_S_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void CP_Pre_S(test_function& func)
{
    // The two lines below must be the first two in the function.
    CP_Pre_S_params *ours;
    ours = (CP_Pre_S_params *)func.params;

}
