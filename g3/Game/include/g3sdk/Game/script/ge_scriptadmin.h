#pragma once

#include <Game/script/ge_scriptinit.h>
#include <Game/script/ge_scriptprocessingunit.h>

#include <Engine.h>

struct gSScriptDLL
{
    GELPVoid m_hModule;
    bCString m_strFileName;
    bTObjArray<gSScriptAIState> m_arrScriptAIStates;
    bTObjArray<gSScriptAIFunction> m_arrScriptAIFunctions;
    bTObjArray<gSScriptAICallback> m_arrScriptAICallbacks;
    bTObjArray<gSScriptAIRoutine> m_arrScriptAIRoutines;
    bTObjArray<gSScript> m_arrScripts;
};

GE_ASSERT_SIZEOF(gSScriptDLL, 0x44)

class GE_DLLIMPORT gCScriptAdmin : public eCScriptAdminBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: GEU32 const GetProfileLastTicksFirst() const override;
    public: ~gCScriptAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: void Process() override;
    public: void PostProcess() override;
    public: GEInt CallScript(bCString const &, eCEntity *, eCEntity *, GEInt) override;
    public: GEBool LoadAllScriptDLLs() override;
    public: GEBool UnloadAllScriptDLLs() override;
    public: GEBool LoadScriptDLL(bCString const &) override;
    public: GEBool UnloadScriptDLL(bCString const &) override;
    public: GEBool IsScriptDLLLoaded(bCString const &) const override;
    public: GEBool GetScriptDLLWithState(bCString const &, bCString &) const override;
    public: GEBool GetScriptDLLWithFunction(bCString const &, bCString &) const override;
    public: GEBool GetScriptDLLWithCallback(bCString const &, bCString &) const override;
    public: GEBool GetScriptDLLWithRoutine(bCString const &, bCString &) const override;
    public: GEBool GetScriptDLLWithScript(bCString const &, bCString &) const override;
    public: GEBool GetScriptSourceFileWithState(bCString const &, bCString &) const override;
    public: GEBool GetScriptSourceFileWithFunction(bCString const &, bCString &) const override;
    public: GEBool GetScriptSourceFileWithCallback(bCString const &, bCString &) const override;
    public: GEBool GetScriptSourceFileWithRoutine(bCString const &, bCString &) const override;
    public: GEBool GetScriptSourceFileWithScript(bCString const &, bCString &) const override;
    public: GEBool GetScriptDLL(bCString const &, bCString &) const override;
    public: GEBool GetScriptSourceFile(bCString const &, bCString &) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCScriptAdmin, eCEngineComponentBase)

  public:
    void AddProfileTicks(GEU32);
    GEInt CallScriptFromScript(bCString const &, GELPVoid, GELPVoid, GEInt = 0);
    void ClearDLLList();
    GEInt RunScript(bCString const &, gCScriptProcessingUnit *);
    GEBool RunScriptCallback(bCString const &, gCScriptProcessingUnit *);
    GEInt RunScriptFromScript(bCString const &, gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt);
    GEBool RunScriptFunction(bCString const &, bTObjStack<gScriptRunTimeSingleState> &, gCScriptProcessingUnit *);
    GEBool RunScriptRoutine(bCString const &, gCScriptProcessingUnit *);
    GEBool RunScriptState(bCString const &, bTObjStack<gScriptRunTimeSingleState> &, gCScriptProcessingUnit *);

  protected:
    gCScriptProcessingUnit m_SPU;
    GEBool m_bAllScriptDllsLoaded;
    bTPtrArray<gSScriptDLL *> m_arrDLLs;
    bTValMap<bCString, gSScriptAIState *> m_ScriptAIStates;
    bTValMap<bCString, gSScriptAIFunction *> m_ScriptAIFunctions;
    bTValMap<bCString, gSScriptAICallback *> m_ScriptAICallbacks;
    bTValMap<bCString, gSScriptAIRoutine *> m_ScriptAIRoutines;
    bTValMap<bCString, gSScript *> m_Scripts;
    GEU32 m_uProfileLastTicks;
    GEU32 m_uProfileTicks;
};

GE_ASSERT_SIZEOF(gCScriptAdmin, 0x208)

gCScriptAdmin &GetScriptAdmin();
