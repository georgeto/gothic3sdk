#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCScriptProcessingUnit;

class GE_DLLIMPORT gCScriptRoutine_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCScriptRoutine_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: GEBool IsProcessable() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void OnSaveGameEntityPostRead() override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void GetOnScreenDebugLines(GEU32, bTObjArray<eSPropertySetDebugLine> &) const override;
    protected: void OnRenderDebug() override;
    public: void OnProcess() override;
    public: void OnPreProcess() override;
    public: void OnPostRead() override;
    public: void OnPostCopy(eCEntityPropertySet const &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCScriptRoutine_PS, eCEntityPropertySet)
    GE_PROPERTY(bCScriptString, Routine, m_strRoutine)
    GE_PROPERTY(bCString, CurrentTask, m_strCurrentTask)
    GE_PROPERTY(GEFloat, TaskTime, m_fTaskTime)
    GE_PROPERTY(GEI32, TaskPosition, m_iTaskPosition)
    GE_PROPERTY(GEFloat, StateTime, m_fStateTime)
    GE_PROPERTY(GEI32, StatePosition, m_iStatePosition)
    GE_PROPERTY(GEI32, CommandTime, m_iCommandTime)
    GE_PROPERTY(bCString, LastTask, m_strLastTask)
    GE_PROPERTY(bCString, CurrentState, m_strCurrentState)
    GE_PROPERTY(GEI32, CurrentBreakBlock, m_iCurrentBreakBlock)
    GE_ENUMPROP(gEAniState, AniState, m_enuAniState)
    GE_ENUMPROP(gEAction, Action, m_enuAction)
    GE_ENUMPROP(gEAmbientAction, AmbientAction, m_enuAmbientAction)
    GE_ENUMPROP(gEAIMode, AIMode, m_enuAIMode)
    GE_ENUMPROP(gEHitDirection, HitDirection, m_enuHitDirection)

  public:
    void AIContinueRoutine();
    void AIFullStop();
    void AISetLocalCallback(bCString const &);
    void AISetState(bCString const &);
    void AISetStateTime(GEFloat);
    void AISetTask(bCString const &);
    void AISetTaskCallback(bCString const &);
    void AISetTaskTime(GEFloat);
    void AIStopCombatMove();
    void AIStopGoto();
    void AIStopOutput();
    void AIStopPlayAnimation();
    void AIStopWait();
    void EnableDebugging(GEBool);
    gCScriptProcessingUnit &GetSPU();
    GEBool IsDebuggingEnabled() const;
    GEBool StartOutput(bCString const &);
    GEBool StopOutput();

  protected:
    void GameReset();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(400)
};

GE_ASSERT_SIZEOF(gCScriptRoutine_PS, 0x1f4)

GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_strRoutine, 0x14, 4)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_strCurrentTask, 0x18, 4)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_fTaskTime, 0x1c, 4)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_iTaskPosition, 0x20, 4)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_fStateTime, 0x24, 4)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_iStatePosition, 0x28, 4)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_iCommandTime, 0x2c, 4)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_strLastTask, 0x30, 4)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_strCurrentState, 0x34, 4)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_iCurrentBreakBlock, 0x38, 4)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_enuAniState, 0x3c, 8)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_enuAction, 0x44, 8)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_enuAmbientAction, 0x4c, 8)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_enuAIMode, 0x54, 8)
GE_ASSERT_PROPERTY(gCScriptRoutine_PS, m_enuHitDirection, 0x5c, 8)
