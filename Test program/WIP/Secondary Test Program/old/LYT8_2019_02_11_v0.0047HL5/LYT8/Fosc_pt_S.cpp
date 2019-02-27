//==============================================================================
// Fosc_pt_S.cpp (User function)
// 
//    void Fosc_pt_S_user_init(test_function& func)
//    void Fosc_pt_S(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "Fosc_pt_S.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void Fosc_pt_S_user_init(test_function& func)
{
	Fosc_pt_S_params *ours;
    ours = (Fosc_pt_S_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void Fosc_pt_S(test_function& func)
{
    // The two lines below must be the first two in the function.
    Fosc_pt_S_params *ours;
    ours = (Fosc_pt_S_params *)func.params;

}
