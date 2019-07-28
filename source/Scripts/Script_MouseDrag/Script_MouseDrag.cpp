#include "Script_MouseDrag.h"

#include "util/Memory.h"
#include "util/Hook.h"

namespace
{

template<mCFunctionHook & Hook>
GEChar GE_STDCALL ProcessMouseClickEvents(UINT uMsg, bCPoint const * pMousePos, WPARAM wParam, LPARAM lParam)
{
    static bCPoint s_ButtonDownPosition;

    if(uMsg == WM_LBUTTONDOWN)
        s_ButtonDownPosition = *pMousePos;

    // Filter mouse move events, when the left mouse button is down and the position hasn't changed.
    if(uMsg == WM_MOUSEMOVE && (wParam & MK_LBUTTON) && s_ButtonDownPosition == *pMousePos)
        return 1;

    return Hook.GetOriginalFunction(ProcessMouseClickEvents<Hook>)(uMsg, pMousePos, wParam, lParam);
}

mCFunctionHook Hook_ListCtrl_ProcessMouseClickEvents;
mCFunctionHook Hook_MenuBar_ProcessMouseClickEvents;

void ApplyHooks()
{
    /*
        Under certain circumstances, e.g. on Windows 10 or when Eclipse is running in the background,
        Gothic 3 receives two additional WM_MOUSEMOVE events between WM_LBUTTONDOWN and WM_LBUTTONUP.
        This makes the game mistakenly recognize a mouse drag gesture, instead of registering a mouse click.
        The mouse position of all these events is the same, so in reality there is no mouse movement.
    */
    Hook_ListCtrl_ProcessMouseClickEvents.Hook(RVA_Gui(0x29800), ProcessMouseClickEvents<Hook_ListCtrl_ProcessMouseClickEvents>, mCBaseHook::mEHookType_ThisCall);
    Hook_MenuBar_ProcessMouseClickEvents.Hook(RVA_Gui(0x24AF0), ProcessMouseClickEvents<Hook_MenuBar_ProcessMouseClickEvents>, mCBaseHook::mEHookType_ThisCall);
}

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
