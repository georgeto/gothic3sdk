#include "util/Memory.h"
#include "util/Hook.h"
#include "util/Util.h"

#include "Script.h"

namespace
{

enum mESubtitleDisplayTime
{
    mESubtitleDisplayTime_Short    = 0,
    mESubtitleDisplayTime_Normal   = 1,
    mESubtitleDisplayTime_Long     = 2,
    mESubtitleDisplayTime_Infinite = 3
};

mESubtitleDisplayTime g_enuSubtitleDisplayTime = mESubtitleDisplayTime_Normal;

void LoadSettings() {
    eCConfigFile config = eCConfigFile();
    if (config.ReadFile(bCString("subtitles.ini"))) {
        bCString const & DisplayTime = config.GetString("Subtitles", "DisplayTime");
        if (DisplayTime.CompareNoCaseFast("Short"))
            g_enuSubtitleDisplayTime = mESubtitleDisplayTime_Short;
        else if (DisplayTime.CompareNoCaseFast("Normal"))
            g_enuSubtitleDisplayTime = mESubtitleDisplayTime_Normal;
        else if (DisplayTime.CompareNoCaseFast("Long"))
            g_enuSubtitleDisplayTime = mESubtitleDisplayTime_Long;
        else if (DisplayTime.CompareNoCaseFast("Infinite"))
            g_enuSubtitleDisplayTime = mESubtitleDisplayTime_Infinite;
    }
}

struct gSAIOutputInstr_Args
{
    eCEntity * m_pEntity;
    bCString   m_strSampleName;
};

struct gSAIOutputInstr_Args_Ext
{
    eCEntity * m_pEntity;
    bCString   m_strSampleName;
    bCString   m_strTextID;
};

mCCallHook Hook_SayEx_sAIOutputInstr;
GEBool GE_STDCALL SayEx_sAIOutputInstr( gSAIOutputInstr_Args * a_pArgs, gCScriptProcessingUnit * a_pSPU, GEBool a_bUnk /* , gSArgsFor__AI_Say_Ex * a_pSayArgs@<esi> */ )
{
    gSAIOutputInstr_Args_Ext AIOutputInstrArgs;
    AIOutputInstrArgs.m_pEntity = a_pArgs->m_pEntity;
    AIOutputInstrArgs.m_strSampleName = a_pArgs->m_strSampleName;
    AIOutputInstrArgs.m_strTextID = Hook_SayEx_sAIOutputInstr.GetEsi<gSArgsFor__AI_Say_Ex *>()->m_strTextID;
    return gCScriptProcessingUnit::sAIOutputInstr(&AIOutputInstrArgs, a_pSPU, a_bUnk);
}

mCCallHook Hook_SaySound_sAIOutputInstr;
GEBool GE_STDCALL SaySound_sAIOutputInstr( gSAIOutputInstr_Args * a_pArgs, gCScriptProcessingUnit * a_pSPU, GEBool a_bUnk )
{
    gSAIOutputInstr_Args_Ext AIOutputInstrArgs;
    AIOutputInstrArgs.m_pEntity = a_pArgs->m_pEntity;
    AIOutputInstrArgs.m_strSampleName = a_pArgs->m_strSampleName;
    AIOutputInstrArgs.m_strTextID = a_pArgs->m_strSampleName;
    return gCScriptProcessingUnit::sAIOutputInstr(&AIOutputInstrArgs, a_pSPU, a_bUnk);
}

// Milliseconds per word for short, normal and long subtitle display time
const GEFloat g_arrMsPerWord[3] = { 250.0f, 500.0f, 1000.0f };

bCString const * GE_STDCALL gCScriptProcessingUnit_CalcSubtitleDisplayTime(gCScriptProcessingUnit * a_pSPU, gSAIOutputInstr_Args_Ext * a_pArgs)
{
    GEFloat fSubtitleDisplayTime = g_fPosInfinity;
    if(g_enuSubtitleDisplayTime != mESubtitleDisplayTime_Infinite)
    {
        bCUnicodeString strText = eCLocString(a_pArgs->m_strTextID);
        GEInt iWordCount = Max(strText.CountWords(" "), 4);
        fSubtitleDisplayTime = iWordCount * g_arrMsPerWord[g_enuSubtitleDisplayTime];
    }

    a_pSPU->m_fInstrDuration = fSubtitleDisplayTime;

    return &a_pArgs->m_strSampleName;
}

}

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    // Ensure that Script_Game.dll is loaded.
    GetScriptAdmin().LoadScriptDLL("Script_Game.dll");

    LoadSettings();

    Hook_SayEx_sAIOutputInstr.Hook(RVA_ScriptGame(0x49472), &SayEx_sAIOutputInstr, mCBaseHook::mEHookType_Mixed, mCRegisterBase::mERegisterType_Esi);
    Hook_SaySound_sAIOutputInstr.Hook(RVA_ScriptGame(0xBA441), &SaySound_sAIOutputInstr);

    static mCSkipCode Skip_SetInstructionDuration(RVA_Game(0x169504), 0x08);

    static mCCallHook Hook_CalcSubtitleDisplayTime;
    Hook_CalcSubtitleDisplayTime
        .Prepare(RVA_Game(0x1694E8), &gCScriptProcessingUnit_CalcSubtitleDisplayTime)
        .AddRegArg(mCRegisterBase::mERegisterType_Esi) // gCScriptProcessingUnit
        .AddRegArg(mCRegisterBase::mERegisterType_Edi) // gSAIOutputInstr_Args_Ext
        .ReplaceSize(0x13).Hook();

    static gSScriptInit s_ScriptInit;
    return &s_ScriptInit;
}

//
// Entry Point
//

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID )
{
    switch( dwReason )
    {
    case DLL_PROCESS_ATTACH:
        ::DisableThreadLibraryCalls( hModule );
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}