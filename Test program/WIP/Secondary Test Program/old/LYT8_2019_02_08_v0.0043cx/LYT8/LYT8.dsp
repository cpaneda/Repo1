# Microsoft Developer Studio Project File - Name="LYT8" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=LYT8 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TMPL.MAK".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TMPL.MAK" CFG="LYT8 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LYT8 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /Zp1 /MDd /W3 /GR /GX /ZI /Od /I "$(CSC_VATE_BASE)\system\include" /I "C:\visualATE\Asl_71\System\Include" /I "D:\Program Files\Gage\CompuScope\include" /D "_DEBUG" /D "WIN32" /D "_MT" /D "_DLL" /D "_WINDOWS" /D "_MBCS" /D "NT" /D "USER_CODE" /D "TEST_EXE" /Yu"asl.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 StatusReport.lib CommonShared.lib smartvariable.lib WFType.lib sitemanager.lib "D:\Program Files\Gage\CompuScope\lib\CsAppSupport.lib" "D:\Program Files\Gage\CompuScope\lib\CsSsm.lib" "C:\visualATE\Asl_71\System\Library\PIClasses.lib" "C:\visualATE\Asl_71\System\Library\PIBase.lib" "C:\visualATE\Asl_71\System\Library\PILimitMgr.lib" "C:\visualATE\Asl_71\System\Library\PIFunc.lib" "C:\visualATE\Asl_71\System\Library\QCSample.lib" "C:\visualATE\Asl_71\System\Library\HardwareID.lib" "C:\visualATE\Asl_71\System\Library\ProcComm.lib" "C:\visualATE\Asl_71\System\Library\NETAPI32.LIB" "C:\visualATE\Asl_71\System\Library\PiAutoCorr.lib" "C:\visualATE\Asl_71\System\Library\WS2_32.LIB"  utilities.lib test.lib board.lib develop.lib screen.lib meter.lib handler.lib devices.lib msvcrtd.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib UserCode.lib gpib-32.obj /nologo /entry:"_DllMainCRTStartup@12" /subsystem:windows /dll /debug /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"libcmt.lib" /nodefaultlib:"msvcrt.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libcmtd.lib" /libpath:"$(CSC_VATE_BASE)\system\library"
# SUBTRACT LINK32 /map
# Begin Target

# Name "LYT8 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "*.cpp"
# Begin Source File

SOURCE=.\First.cpp
# End Source File
# Begin Source File

SOURCE=.\Continuity.cpp
# End Source File
# Begin Source File

SOURCE=.\Leakage.cpp
# End Source File
# Begin Source File

SOURCE=.\EEprom_DevID.cpp
# End Source File
# Begin Source File

SOURCE=.\Scan_Pre_Stress.cpp
# End Source File
# Begin Source File

SOURCE=.\Is_Pre_Stress.cpp
# End Source File
# Begin Source File

SOURCE=.\STRESS.cpp
# End Source File
# Begin Source File

SOURCE=.\Is_Post_Stress.cpp
# End Source File
# Begin Source File

SOURCE=.\Scan_Post_Stress.cpp
# End Source File
# Begin Source File

SOURCE=.\Leakage_Post_Stress.cpp
# End Source File
# Begin Source File

SOURCE=.\BV_Vpin.cpp
# End Source File
# Begin Source File

SOURCE=.\BV_Drain.cpp
# End Source File
# Begin Source File

SOURCE=.\VBP_Init.cpp
# End Source File
# Begin Source File

SOURCE=.\IzPre.cpp
# End Source File
# Begin Source File

SOURCE=.\Feature_Trim_P.cpp
# End Source File
# Begin Source File

SOURCE=.\Feature_Trim_S.cpp
# End Source File
# Begin Source File

SOURCE=.\BPS_STRESS.cpp
# End Source File
# Begin Source File

SOURCE=.\BPP_STRESS.cpp
# End Source File
# Begin Source File

SOURCE=.\HBP_Pre_S.cpp
# End Source File
# Begin Source File

SOURCE=.\IOV_Pre_P.cpp
# End Source File
# Begin Source File

SOURCE=.\IOV_Trim.cpp
# End Source File
# Begin Source File

SOURCE=.\IOV_post_P.cpp
# End Source File
# Begin Source File

SOURCE=.\Fosc_Pre_P.cpp
# End Source File
# Begin Source File

SOURCE=.\Fosc_Trim_P.cpp
# End Source File
# Begin Source File

SOURCE=.\Fosc_post_P.cpp
# End Source File
# Begin Source File

SOURCE=.\tOVL_Pre_S.cpp
# End Source File
# Begin Source File

SOURCE=.\tOVL_Trim.cpp
# End Source File
# Begin Source File

SOURCE=.\tOVL_post_S.cpp
# End Source File
# Begin Source File

SOURCE=.\Fosc_Pre_S.cpp
# End Source File
# Begin Source File

SOURCE=.\Fosc_Trim_S.cpp
# End Source File
# Begin Source File

SOURCE=.\Fosc_post_S.cpp
# End Source File
# Begin Source File

SOURCE=.\OSC_Pt.cpp
# End Source File
# Begin Source File

SOURCE=.\ILIM_Pre.cpp
# End Source File
# Begin Source File

SOURCE=.\ILIM_Trim.cpp
# End Source File
# Begin Source File

SOURCE=.\ILIM.cpp
# End Source File
# Begin Source File

SOURCE=.\CV_Pre.cpp
# End Source File
# Begin Source File

SOURCE=.\VDDA_Pre.cpp
# End Source File
# Begin Source File

SOURCE=.\IRSET_Pre.cpp
# End Source File
# Begin Source File

SOURCE=.\ZTtimer_Pre.cpp
# End Source File
# Begin Source File

SOURCE=.\VADC_Pre.cpp
# End Source File
# Begin Source File

SOURCE=.\CLOCK1M_Pre.cpp
# End Source File
# Begin Source File

SOURCE=.\CCOffset_Pre.cpp
# End Source File
# Begin Source File

SOURCE=.\CDC_Pre.cpp
# End Source File
# Begin Source File

SOURCE=.\CCoff_Pt.cpp
# End Source File
# Begin Source File

SOURCE=.\IsCal_Pt.cpp
# End Source File
# Begin Source File

SOURCE=.\ADC_Pt.cpp
# End Source File
# Begin Source File

SOURCE=.\EEPROM_Write.cpp
# End Source File
# Begin Source File

SOURCE=.\IzPost.cpp
# End Source File
# Begin Source File

SOURCE=.\SoftStart.cpp
# End Source File
# Begin Source File

SOURCE=.\VBP_Supply.cpp
# End Source File
# Begin Source File

SOURCE=.\IBP_Supply.cpp
# End Source File
# Begin Source File

SOURCE=.\IOV_IUV_OT.cpp
# End Source File
# Begin Source File

SOURCE=.\FOSC_Ton_ARST.cpp
# End Source File
# Begin Source File

SOURCE=.\FWPK.cpp
# End Source File
# Begin Source File

SOURCE=.\SR_Delay_tREQinh.cpp
# End Source File
# Begin Source File

SOURCE=.\SOA_SDS_TW50.cpp
# End Source File
# Begin Source File

SOURCE=.\IsCal_Final.cpp
# End Source File
# Begin Source File

SOURCE=.\Iout.cpp
# End Source File
# Begin Source File

SOURCE=.\CV_nDAC_pDAC.cpp
# End Source File
# Begin Source File

SOURCE=.\Vesr.cpp
# End Source File
# Begin Source File

SOURCE=.\Isvth3X_AR_ISSC.cpp
# End Source File
# Begin Source File

SOURCE=.\Vovp.cpp
# End Source File
# Begin Source File

SOURCE=.\UVP.cpp
# End Source File
# Begin Source File

SOURCE=.\VBD_uVCC.cpp
# End Source File
# Begin Source File

SOURCE=.\OSC_Final.cpp
# End Source File
# Begin Source File

SOURCE=.\DofA_Final.cpp
# End Source File
# Begin Source File

SOURCE=.\IsDAC_Final.cpp
# End Source File
# Begin Source File

SOURCE=.\Gain_Final.cpp
# End Source File
# Begin Source File

SOURCE=.\CDC_Final.cpp
# End Source File
# Begin Source File

SOURCE=.\Ccoff_Final.cpp
# End Source File
# Begin Source File

SOURCE=.\VPK.cpp
# End Source File
# Begin Source File

SOURCE=.\ADC_Final.cpp
# End Source File
# Begin Source File

SOURCE=.\DATT.cpp
# End Source File
# Begin Source File

SOURCE=.\zLast.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "*.h"
# Begin Source File

SOURCE=.\First.h
# End Source File
# Begin Source File

SOURCE=.\Continuity.h
# End Source File
# Begin Source File

SOURCE=.\Leakage.h
# End Source File
# Begin Source File

SOURCE=.\EEprom_DevID.h
# End Source File
# Begin Source File

SOURCE=.\Scan_Pre_Stress.h
# End Source File
# Begin Source File

SOURCE=.\Is_Pre_Stress.h
# End Source File
# Begin Source File

SOURCE=.\STRESS.h
# End Source File
# Begin Source File

SOURCE=.\Is_Post_Stress.h
# End Source File
# Begin Source File

SOURCE=.\Scan_Post_Stress.h
# End Source File
# Begin Source File

SOURCE=.\Leakage_Post_Stress.h
# End Source File
# Begin Source File

SOURCE=.\BV_Vpin.h
# End Source File
# Begin Source File

SOURCE=.\BV_Drain.h
# End Source File
# Begin Source File

SOURCE=.\VBP_Init.h
# End Source File
# Begin Source File

SOURCE=.\IzPre.h
# End Source File
# Begin Source File

SOURCE=.\Feature_Trim_P.h
# End Source File
# Begin Source File

SOURCE=.\Feature_Trim_S.h
# End Source File
# Begin Source File

SOURCE=.\BPS_STRESS.h
# End Source File
# Begin Source File

SOURCE=.\BPP_STRESS.h
# End Source File
# Begin Source File

SOURCE=.\HBP_Pre_S.h
# End Source File
# Begin Source File

SOURCE=.\IOV_Pre_P.h
# End Source File
# Begin Source File

SOURCE=.\IOV_Trim.h
# End Source File
# Begin Source File

SOURCE=.\IOV_post_P.h
# End Source File
# Begin Source File

SOURCE=.\Fosc_Pre_P.h
# End Source File
# Begin Source File

SOURCE=.\Fosc_Trim_P.h
# End Source File
# Begin Source File

SOURCE=.\Fosc_post_P.h
# End Source File
# Begin Source File

SOURCE=.\tOVL_Pre_S.h
# End Source File
# Begin Source File

SOURCE=.\tOVL_Trim.h
# End Source File
# Begin Source File

SOURCE=.\tOVL_post_S.h
# End Source File
# Begin Source File

SOURCE=.\Fosc_Pre_S.h
# End Source File
# Begin Source File

SOURCE=.\Fosc_Trim_S.h
# End Source File
# Begin Source File

SOURCE=.\Fosc_post_S.h
# End Source File
# Begin Source File

SOURCE=.\OSC_Pt.h
# End Source File
# Begin Source File

SOURCE=.\ILIM_Pre.h
# End Source File
# Begin Source File

SOURCE=.\ILIM_Trim.h
# End Source File
# Begin Source File

SOURCE=.\ILIM.h
# End Source File
# Begin Source File

SOURCE=.\CV_Pre.h
# End Source File
# Begin Source File

SOURCE=.\VDDA_Pre.h
# End Source File
# Begin Source File

SOURCE=.\IRSET_Pre.h
# End Source File
# Begin Source File

SOURCE=.\ZTtimer_Pre.h
# End Source File
# Begin Source File

SOURCE=.\VADC_Pre.h
# End Source File
# Begin Source File

SOURCE=.\CLOCK1M_Pre.h
# End Source File
# Begin Source File

SOURCE=.\CCOffset_Pre.h
# End Source File
# Begin Source File

SOURCE=.\CDC_Pre.h
# End Source File
# Begin Source File

SOURCE=.\CCoff_Pt.h
# End Source File
# Begin Source File

SOURCE=.\IsCal_Pt.h
# End Source File
# Begin Source File

SOURCE=.\ADC_Pt.h
# End Source File
# Begin Source File

SOURCE=.\EEPROM_Write.h
# End Source File
# Begin Source File

SOURCE=.\IzPost.h
# End Source File
# Begin Source File

SOURCE=.\SoftStart.h
# End Source File
# Begin Source File

SOURCE=.\VBP_Supply.h
# End Source File
# Begin Source File

SOURCE=.\IBP_Supply.h
# End Source File
# Begin Source File

SOURCE=.\IOV_IUV_OT.h
# End Source File
# Begin Source File

SOURCE=.\FOSC_Ton_ARST.h
# End Source File
# Begin Source File

SOURCE=.\FWPK.h
# End Source File
# Begin Source File

SOURCE=.\SR_Delay_tREQinh.h
# End Source File
# Begin Source File

SOURCE=.\SOA_SDS_TW50.h
# End Source File
# Begin Source File

SOURCE=.\IsCal_Final.h
# End Source File
# Begin Source File

SOURCE=.\Iout.h
# End Source File
# Begin Source File

SOURCE=.\CV_nDAC_pDAC.h
# End Source File
# Begin Source File

SOURCE=.\Vesr.h
# End Source File
# Begin Source File

SOURCE=.\Isvth3X_AR_ISSC.h
# End Source File
# Begin Source File

SOURCE=.\Vovp.h
# End Source File
# Begin Source File

SOURCE=.\UVP.h
# End Source File
# Begin Source File

SOURCE=.\VBD_uVCC.h
# End Source File
# Begin Source File

SOURCE=.\OSC_Final.h
# End Source File
# Begin Source File

SOURCE=.\DofA_Final.h
# End Source File
# Begin Source File

SOURCE=.\IsDAC_Final.h
# End Source File
# Begin Source File

SOURCE=.\Gain_Final.h
# End Source File
# Begin Source File

SOURCE=.\CDC_Final.h
# End Source File
# Begin Source File

SOURCE=.\Ccoff_Final.h
# End Source File
# Begin Source File

SOURCE=.\VPK.h
# End Source File
# Begin Source File

SOURCE=.\ADC_Final.h
# End Source File
# Begin Source File

SOURCE=.\DATT.h
# End Source File
# Begin Source File

SOURCE=.\zLast.h
# End Source File
# End Group
# Begin Group "System Files"
# Begin Source File

SOURCE=.\BRD_CFG.CPP
# End Source File
# Begin Source File

SOURCE=.\DLLMAIN.CPP
# End Source File
# Begin Source File

SOURCE=.\FUNCTION.H
# End Source File
# Begin Source File

SOURCE=.\LIST.CPP
# End Source File
# Begin Source File

SOURCE=.\USER.CPP
# ADD CPP /Yc"asl.h"
# End Source File
# Begin Source File

SOURCE=.\USER.H
# End Source File
# Begin Source File

SOURCE=.\REGISTER.CPP
# End Source File
# Begin Source File

SOURCE="$(CSC_PLG_BASE)\Include\OVI.h"
# End Source File
# Begin Source File

SOURCE="$(CSC_PLG_BASE)\Include\PV3.h"
# End Source File
# Begin Source File

SOURCE="$(CSC_PLG_BASE)\Include\TMU.h"
# End Source File
# Begin Source File

SOURCE="$(CSC_PLG_BASE)\Include\DDD.h"
# End Source File
# Begin Source File

SOURCE="$(CSC_PLG_BASE)\Include\DVI.h"
# End Source File
# Begin Source File

SOURCE="$(CSC_PLG_BASE)\Include\MUX.h"
# End Source File
# Begin Source File

SOURCE="$(CSC_PLG_BASE)\Include\HVS.h"
# End Source File

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Data.ipd
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\"LYT8.rc"
# End Source File
# End Group
# End Target
# End Project
