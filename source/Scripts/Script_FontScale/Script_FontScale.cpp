#include "Script_FontScale.h"

#include "util/Memory.h"
#include "util/Hook.h"
#include "util/Util.h"

namespace
{
    const GEFloat FOCUS_NAME_FONT_SCALE_FACTOR = 1 / 1080.0f;
    const GEInt DEFAULT_FONT_HEIGHT = 24;

    void GE_STDCALL DrawFocusNames_UpdateFont(gCGUIEntityRenderer & a_FocusNameRenderer)
    {
        static GEU32 s_LastViewportHeight = 1080;

        eCGfxShared::eSGfxViewport Viewport {};
        if (eCGfxAdmin * pGfxAdmin = FindModule<eCGfxAdmin>())
            pGfxAdmin->GetAccessToMixer().GetViewport(Viewport);

        GEU32 ViewportHeight = Viewport.Height - Viewport.Y;
        if(s_LastViewportHeight != ViewportHeight)
        {
            s_LastViewportHeight = ViewportHeight;

            // GUI scaling has changed, recalculate the font size
            GEFloat FontScaleHeight = ViewportHeight * FOCUS_NAME_FONT_SCALE_FACTOR;
            GEInt FontHeight = RoundFloat(DEFAULT_FONT_HEIGHT * FontScaleHeight);

            eSSetupEngine const & Setup = eCApplication::GetInstance().GetSetupEngineDesc();

            // Create font
            SFFGUIFont FontConfig;
            FontConfig.FaceName = Setup.m_DefaultFont;
            FontConfig.Height = FontHeight;
            FontConfig.Width = 0;
            FontConfig.Weight = Setup.m_bDefaultFontBold ? 800 : 400;
            FontConfig.CharSet = 1;
            FontConfig.OutPrecision = 0;
            FontConfig.Quality = 0;
            FontConfig.PitchAndFamily = 0;
            FontConfig.Italic = 0;

            a_FocusNameRenderer.m_FontIndex = eCGUIModule::GetInstance().GetAdmin().CreateFontA(FontConfig);
        }
    }
}

void ApplyHooks()
{
    // The focus name is rendered with a constant pixel size.
    // Therefore when in fullscreen mode, the focus name looks larger in lower resolutions,
    // and smaller in higher resolutions.

    // Update font used for focus name rendering
    static mCCallHook Hook_DrawFocusNames_UpdateFont;
    Hook_DrawFocusNames_UpdateFont
        .Prepare(RVA_Game(0x7981C), &DrawFocusNames_UpdateFont)
        .AddRegArg(mCRegisterBase::mERegisterType_Edi) // gCGUIEntityRenderer &
        .InsertCall().Hook();
}


gSScriptInit & GetScriptInit()
{
    static gSScriptInit s_ScriptInit;
    return s_ScriptInit;
}

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    ApplyHooks();

    return &GetScriptInit();
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
