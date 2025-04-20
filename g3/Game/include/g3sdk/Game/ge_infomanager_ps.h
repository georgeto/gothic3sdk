#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCEntity;
class gCInfo_PS;
class gCMagic_PS;
class gCQuestManager_PS;
class gCQuest_PS;
class gCScriptProcessingUnit;
class gCSkill_PS;

class GE_DLLIMPORT gCInfoManager_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCInfoManager_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void OnProcess() override;
    public: void OnPreProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCInfoManager_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, IsRunning, m_bIsRunning) // Read only
    GE_PADDING(3)
    GE_PROPERTY(GEInt, CurrentInfoIndex, m_currentInfoIndex) // Read only
    GE_PROPERTY(GEBool, WaitForScript, m_bWaitforScript)     // Read only
    GE_PROPERTY(GEBool, ChildMode, m_bChildMode)             // Read only
    GE_PROPERTY(GEBool, EndRequested, m_bEndRequested)       // Read only
    GE_PADDING(1)
    GE_ENUMPROP(gESession_State, LastSessionState, m_lastSessionState) // Read only
    GE_PROPERTY(GEBool, LastInfoExecuted, m_bLastInfoExecuted)         // Read only
    GE_PADDING(1)

  public:
    static bCString GE_STDCALL GetInfoDir();
    static bCString GE_STDCALL GetInfoFilePath(gCInfo_PS const *);
    static bCString GE_STDCALL GetInfoManagerFile();
    static gCInfoManager_PS *GE_STDCALL GetInstance();
    static gCMagic_PS *GE_STDCALL GetMagicPS(eCEntity *);
    static gCSkill_PS *GE_STDCALL GetSkillPS(eCEntity *);
    static void GE_STDCALL RemoveDuplicatedInfos(bTPtrArray<gCInfo_PS *> &, gEInfoCondType);
    static void GE_STDCALL SortInfos(GEInt, bTPtrArray<gCInfo_PS *> &);
    static GEInt GE_CCALL SortInfosCbk(GELPCVoid, GELPCVoid);

  public:
    bTPtrArray<gCInfo_PS *> &AccessInfos();
    gCInfo_PS *AddInfo(bCString const &);
    GEBool AreChildInfosAvailable(gCInfo_PS const &) const;
    GEBool AreOnlyEndInfosAvailable() const;
    GEBool ChangeInfoName(bCString const &, bCString const &);
    void EndInfoManager(gCInfo_PS *);
    GEBool ExecuteDialogInfo(gCInfo_PS *);
    eCEntity *FindEntityFromString(bCString const &);
    gCInfo_PS *GetAvailableInfo(GEInt);
    GEInt GetAvailableInfoCount();
    void GetChildInfos(gCInfo_PS const &, bTPtrArray<gCInfo_PS *> &);
    gCInfo_PS *GetCurrentInfo();
    gCEntity *GetCurrentOther();
    gCEntity *GetCurrentSelf();
    gCEntity *GetDialogPartner1() const;
    gCEntity *GetDialogPartner2() const;
    gCEntity *GetDialogPartnerNPC() const; // GetDialogPartner2
    GEU32 GetHighestSortID() const;
    gCInfo_PS *GetInfo(bCString const &);
    bTPtrArray<gCInfo_PS *> const &GetInfos() const;
    gCQuestManager_PS *GetQuestManager();
    gCQuestManager_PS const *GetQuestManager() const;
    gCScriptProcessingUnit &GetSPU();
    GEBool HasChildInfos(gCInfo_PS const &);
    GEBool HasCommentInfo(eCEntity *);
    GEBool HasImportantInfo(eCEntity *);
    GEBool HasInfos(eCEntity *);
    GEBool IsDialogInfo(gCInfo_PS const &) const;
    GEBool IsParentInfoAvailable(gCInfo_PS const &) const;
    // Name of this acessor function collides with the "IsRunning" property.
    // GEBool IsRunning();
    GEBool IsSuccessOrFailedInfoAvailable(gCQuest_PS const &) const;
    GEBool IsWaitingForScript();
    GEBool LoadInfosFromInis();
    void OnCommandCompleted(GEBool);
    void OnEndInfoManager();
    void OnInfoScriptFinished(gCInfo_PS const *);
    void OnInfoScriptStarted(gCInfo_PS const *, bCString const &);
    GEBool ReadCompiledInfoManager(bCString const &);
    GEBool RemoveInfo(bCString const &);
    GEBool StartComment(eCEntity *);
    GEBool StartInfoManager(eCEntity &, eCEntity &);
    GEBool SwapInfos(bCString const &, bCString const &);
    GEBool WriteCompiledInfoManager(bCString const &);

  protected:
    bTPtrArray<gCInfo_PS *> &GetChildInfoList(bTPtrArray<gCInfo_PS *> &, gCInfo_PS &);
    bTPtrArray<gCInfo_PS *> &GetInfoList(bTPtrArray<gCInfo_PS *> &, bCString const &, bCString const &, GEBool, GEBool,
                                         GEBool, GEBool, GEBool, GEBool);
    void HideDialogManager();
    void Invalidate();
    void ShowDialogManager();

  private:
    void BuildMapInfosByOwners();

  protected:
    bTPtrArray<gCInfo_PS *> m_arrInfos;
    bTPtrArray<gCInfo_PS *> m_arrAvailableInfos;
    gCEntity *m_pDialogPartner1;
    gCEntity *m_pDialogPartner2; // returned by GetDialogPartnerNPC
    GE_UNIMPL_MEMBERS(0x10)      // Unknown map
    bTObjMap<bCString, bTPtrArray<gCInfo_PS *>> m_mapInfosByOwners;
};

GE_ASSERT_SIZEOF(gCInfoManager_PS, 0x6c)

GE_ASSERT_PROPERTY(gCInfoManager_PS, m_bIsRunning, 0x14, 1)
GE_ASSERT_PROPERTY(gCInfoManager_PS, m_currentInfoIndex, 0x18, 4)
GE_ASSERT_PROPERTY(gCInfoManager_PS, m_bWaitforScript, 0x1c, 1)
GE_ASSERT_PROPERTY(gCInfoManager_PS, m_bChildMode, 0x1d, 1)
GE_ASSERT_PROPERTY(gCInfoManager_PS, m_bEndRequested, 0x1e, 1)
GE_ASSERT_PROPERTY(gCInfoManager_PS, m_lastSessionState, 0x20, 8)
GE_ASSERT_PROPERTY(gCInfoManager_PS, m_bLastInfoExecuted, 0x28, 1)
