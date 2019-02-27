#include "asl.h"
#include "Misc.h"
#include "FLibExp.h"

extern "C" __declspec(dllexport) short GetNTestDescriptions (void);
extern "C" __declspec(dllexport) test_descriptions *GetTestDescription (short i);
extern "C" __declspec(dllexport) BOOL AssignFunctionLibraryExportInfo (FUNCTION_LIBRARY_EXPORT_INFO& callers_fle);
extern "C" __declspec(dllexport) unsigned short GetMaxSlots (void);
extern "C" __declspec(dllexport) unsigned short GetRequiredBoardCount (unsigned short function_index);
extern "C" __declspec(dllexport) board_desc *GetBoardDescs (unsigned short function_index);

BOOL InitializeProcessData (void);

extern short g_test_descr_n;
extern test_descriptions g_test_list[];

extern unsigned short g_slots_n;
extern FUNCTION_LIBRARY_EXPORT_INFO g_fle;

extern unsigned short *g_pBoard_count;
extern board_desc **g_pBoard_descs;

void initialize_required_board_configs (void);

short GetNTestDescriptions (void)
{
	return g_test_descr_n;
}

test_descriptions *GetTestDescription (short i)
{
	if ( (0 <= i) && (i < g_test_descr_n) ) {
		return(&g_test_list[i]);
	}

	return(NULL);
}

// This function copies the FUNCTION_LIBRARY_EXPORT_INFO object in this FUNCTION.DLL
// to the callers object. This allows a caller (TEST.EXE) to get/set information

BOOL AssignFunctionLibraryExportInfo (FUNCTION_LIBRARY_EXPORT_INFO& callers_fle)
{
    BOOL iret = InitializeProcessData ();
	if ( TRUE != iret ) {
        return FALSE;
	}

	// Find out how big the data is in this object and allocate a temporary transfer buffer

	long data_size = g_fle.GetStorageSizeBytes();
	BYTE *pData = new BYTE[data_size];

	if ( NULL == pData ) {
        return FALSE;
	}
	
	// Transfer the data (byte for byte) from the object in this DLL to the caller's object
	// LoadFromBuffer will allocation the memory needed

	g_fle.SaveToBuffer (pData);
	callers_fle.LoadFromBuffer (pData);

	delete [] pData;
	
	return TRUE;
}

unsigned short GetMaxSlots (void)
{
	return g_slots_n;
}

unsigned short GetRequiredBoardCount (unsigned short function_index)
{
	if ( NULL != g_pBoard_count ) {
		return(g_pBoard_count[function_index]);
	}

	return(0);
}

board_desc *GetBoardDescs (unsigned short function_index)
{
	if ( NULL != g_pBoard_descs ) {
		return(g_pBoard_descs[function_index]);
	}

	return(NULL);
}