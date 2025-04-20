#pragma once

#include <Game/ge_quest_ps.h>

#include <Engine.h>

class gCInfoManager_PS;

class GE_DLLIMPORT gCQuestManager_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCQuestManager_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCQuestManager_PS, eCEntityPropertySet)
    GE_PROPERTY(bTObjArray<bTAutoPOSmartPtr<gCQuest_PS>>, Quests, m_arrQuests)

  public:
    static gCQuestManager_PS *GE_STDCALL GetInstance();
    static bCString GE_STDCALL GetQuestDir();
    static bCString GE_STDCALL GetQuestFilePath(gCQuest_PS const *);
    static GEInt GE_CCALL SortQuestsCbk(GELPCVoid, GELPCVoid);

  public:
    gCQuest_PS *AddQuest(bCString const &);
    void BuildArrQuestsByType();
    GEBool CloseQuest(bCString const &);
    GEBool FailQuest(bCString const &);
    gCInfoManager_PS *GetInfoManager();
    gCInfoManager_PS const *GetInfoManager() const;
    gCQuest_PS *GetQuest(bCString const &);
    gCQuest_PS const *GetQuest(bCString const &) const;
    GEBool LoadQuestsFromInis();
    GEBool OnEnclaveStateChanged(eCEntity const &);
    GEBool OnEnter(eCEntity const &, bCString const &);
    GEBool OnLeave(eCEntity const &, bCString const &);
    GEBool OnNPCDefeated(eCEntity const &);
    GEBool OnNPCKilled(eCEntity const &);
    GEBool OnReceiveItem(eCEntity const *, eCEntity const *, bCPropertyID const &, GEU32);
    GEBool OnSpellCast(eCEntity const &, eCEntity const &, bCString);
    GEBool RemoveQuest(bCString const &);
    GEBool RenameQuest(bCString const &, bCString const &);
    void ResetQuests();
    GEBool RunQuest(bCString const &);
    GEBool SucceedQuest(bCString const &);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(184)
};

GE_ASSERT_SIZEOF(gCQuestManager_PS, 0xd8)

GE_ASSERT_PROPERTY(gCQuestManager_PS, m_arrQuests, 0x14, 12)
