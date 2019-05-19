#include "Script_RemoteControl.h"

#include "me_ipcadmin.h"

#include "Script.h"

gSScriptInit & GetScriptInit()
{
    static gSScriptInit s_ScriptInit;
    return s_ScriptInit;
}

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    // Ensure that that Script_Game.dll is loaded.
    GetScriptAdmin().LoadScriptDLL( "Script_Game.dll" );

    // Register IpcAdmin engine component.
    static bCAccessorCreator IpcAdmin( bTClassName<mCIpcAdmin>::GetUnmangled() );

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