#include "Common.h"

namespace
{
    static mCCallHook Hook_AfterApplicationProcess;
    typedef void (GE_STDCALL * gFStartNewGame)();
    void GE_STDCALL AfterApplicationProcess()
    {
        // eCApplication::OnRun() wiederherstellen
        Hook_AfterApplicationProcess.Disable();

        reinterpret_cast<gFStartNewGame>(RVA_Game(0x909E0))();
    }

    mCFunctionHook HookOpenTutorial;
    GEBool OpenTutorial(bCUnicodeString const & a_Message)
    {
        if (!GetModSettings().Game_HideTips)
            return HookOpenTutorial.GetOriginalFunction(&OpenTutorial)(a_Message);

        if (eCEntity * pHero = gCSession::GetInstance().GetHero())
        {
            if (gCPlayerMemory_PS * pPlayerMemory = dynamic_cast<gCPlayerMemory_PS *>(pHero->GetPropertySet(eEPropertySetType_PlayerMemory)))
                pPlayerMemory->SetHideTips(GETrue);
        }

        if (GELPByte pHUDPageTutorial = GetGamePage(HookOpenTutorial.GetSelf<gCGUIManager *>(), gEGamePage_Tutorial))
        {
            CFFGFCCheckBox * pHideTutorialCheckBox = reinterpret_cast<CFFGFCCheckBox *>(pHUDPageTutorial + 0x58);
            if (pHideTutorialCheckBox)
                pHideTutorialCheckBox->SetCheck(GETrue);
        }

        return GETrue;
    }
}

ME_MODULE(EasyStart)
{
    // Tutorial nicht anzeigen
    HookOpenTutorial.Hook(PROC_Game("?OpenTutorial@gCGUIManager@@QAE_NABVbCUnicodeString@@@Z"), &OpenTutorial, mCBaseHook::mEHookType_ThisCall);

    bCCommandLine CommandLine(eCApplication::GetInstance().GetCommandLineA());
    bTStringObjMap<bCString> const & Options = CommandLine.GetOptions();
    GEBool bAutostart = GetModSettings().Game_AutoStart;
    if(Options.IsValidKey("autostart"))
        bAutostart = Options.GetAt("autostart").GetBool();

    // Hauptmenü überspringen und direkt neues Spiel starten
    if(bAutostart)
    {
        /*
            Wird über eCApplication::OnIdle().eCApplication::OnRun().eCApplication::Process().eCModuleAdmin::Process().gCScriptAdmin::Process().gCScriptAdmin::LoadAllDLLs()
            aufgerufen. Wir klemmen uns hinter den eCApplication::Process() Aufruf in eCApplication::OnRun().
        */
        Hook_AfterApplicationProcess
            .Prepare(RVA_Engine(0x1677C), &AfterApplicationProcess)
            .InsertCall().Hook();
    }
}
