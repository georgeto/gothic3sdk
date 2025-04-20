#pragma once

#include <Game/GameEnum.h>
#include <Game/ge_infoscript_ps.h>

#include <Engine.h>

class gCInfoManager_PS;
class gCInventory_PS;
class gCNPC_PS;
class gCQuestManager_PS;

class GE_DLLIMPORT gCInfo_PS : public bCObjectRefBase
{
    // clang-format off
    public: virtual GEBool IsEditorRelevant() const;
    public: virtual eEPropertySetType GetPropertySetType() const;
    public: virtual bEResult ReadRuntimeData(bCIStream &);
    public: virtual bEResult WriteRuntimeData(bCOStream &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCInfo_PS() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCInfo_PS, bCObjectRefBase)
    GE_PROPERTY(bCString, Name, m_strName)
    GE_PROPERTY(GEU32, SortID, m_sortID)
    GE_PROPERTY(bCString, Owner, m_owner)
    GE_PROPERTY(GEBool, InfoGiven, m_bInfoGiven)
    GE_PADDING(3)
    GE_PROPERTY(bCString, Parent, m_strParent)
    GE_PROPERTY(bCString, Quest, m_strQuest)
    GE_ENUMPROP(gEInfoCondType, ConditionType, m_enuCondType)
    GE_ENUMPROP(gEInfoType, Type, m_enuType)
    GE_PROPERTY(GEI32, GoldCost, m_iInfoGoldCost)
    GE_PROPERTY(bCString, ConditionOwnerNearEntity, m_condOwnerNearEntity)
    GE_PROPERTY(bTObjArray<bCString>, ConditionPlayerKnows, m_arrCondPlayerKnows)
    GE_PROPERTY(bCString, ConditionItemContainer, m_condItemContainer)
    GE_PROPERTY(bTObjArray<bCString>, CondItems, m_arrCondItems)
    GE_PROPERTY(bTValArray<GEU32>, CondItemAmounts, m_arrCondItemAmounts)
    GE_PROPERTY(bTObjArray<bCString>, CondSecondaryNPC, m_arrCondSecondaryNPC)
    GE_PROPERTY(bTValArray<GEU32>, CondSecondaryNPCStatus, m_arrCondSecondaryNPCStatus)
    GE_PROPERTY(eCTemplateEntityProxy, TeachSkill, m_teachSkill)
    GE_PROPERTY(bCString, TeachAttrib, m_teachAttrib)
    GE_PROPERTY(GEI32, TeachAttribValue, m_teachAttribValue)
    GE_PROPERTY(GEBool, ClearChildren, m_bClearChildren)
    GE_PROPERTY(GEBool, Permanent, m_bPermanent)
    GE_PADDING(2)

  public:
    GEU32 m_uEndTimestamp;

    GE_PROPERTY(bCString, Folder, m_strFolder)
    GE_PROPERTY(bTObjArray<bCString>, ConditionPlayerKnowsNot, m_arrCondPlayerKnowsNot)
    GE_PROPERTY(bTObjArray<bCString>, CondWearsItem, m_arrCondWearsItem)
    GE_PROPERTY(bTObjArray<bCString>, CondHasSkill, m_arrCondHasSkill)
    GE_PROPERTY(bTObjArray<bCString>, CondReputGroup, m_arrCondReputGroup)
    GE_PROPERTY(bTObjArray<GEU32>, CondReputAmount, m_arrCondReputAmount)
    GE_PROPERTY(bTObjArray<bCString>, CondReputRelation, m_arrCondReputRelation)
    GE_PROPERTY(bTObjArray<bCString>, CondPAL, m_arrCondPAL)
    GE_PROPERTY(bTObjArray<bCString>, CondPlayerPartyMember, m_arrCondPlayerPartyMember)
    GE_PROPERTY(GEBool, SuppressLog, m_bSuppressLog)
    GE_PADDING(3)
    GE_OBJECTPROP(gCInfoScript_PS, bCObjectRefBase, InfoScript, m_infoScript)

  public:
    static eCEntity *GE_STDCALL GetEntity(bCPropertyID const &);
    static eCEntity *GE_STDCALL GetEntity(bCString const &);
    static bCPropertyID GE_STDCALL GetEntityID(bCString const &);
    static bCString GE_STDCALL GetEntityName(bCPropertyID const &);
    static gCInventory_PS *GE_STDCALL GetInventory(bCPropertyID const &);
    static gCInventory_PS *GE_STDCALL GetInventory(bCString const &);
    static gCNPC_PS *GE_STDCALL GetNPC(bCPropertyID const &);
    static gCNPC_PS *GE_STDCALL GetNPC(bCString const &);
    static eCDynamicEntity *GE_STDCALL GetPlayer();
    static gCNPC_PS *GE_STDCALL GetPlayerNPC();
    static GEBool GE_STDCALL Give(bCPropertyID const &, bCPropertyID const &, bCPropertyID const &, GEU32 const &);
    static GEBool GE_STDCALL Give(eCEntity *, eCEntity *, bCPropertyID const &, GEU32);
    static GEBool GE_STDCALL Give(eCEntity *, eCEntity *, GEInt, GEU32);
    static GEBool GE_STDCALL Give(eCEntity *, eCEntity *, eCTemplateEntity const *, GEU32);
    static bCString GE_STDCALL NPCstatusToString(gEInfoNPCStatus);
    static GEBool GE_STDCALL SetPartyLeader(eCEntity *, eCEntity *);
    static gEInfoNPCStatus GE_STDCALL StringToNPCstatus(bCString const &);

  public:
    GEU32 &AccessRunningTimeHours();
    GEBool Execute(gCInfoManager_PS *);
    eCEntity *FindEntityFromString(bCString const &) const;
    bCUnicodeString GetDialogDescription() const;
    gCInfoManager_PS *GetInfoManager();
    gCInfoManager_PS const *GetInfoManager() const;
    eCEntity *GetOwnerEntity() const;
    gCQuestManager_PS *GetQuestManager();
    gCQuestManager_PS const *GetQuestManager() const;
    GEU32 const &GetRunningTimeHours() const;
    bCUnicodeString GetTitle() const;
    GEBool IsAvailable() const;
    GEBool IsChildInfo() const;
    GEBool IsDead(eCEntity *) const;
    GEBool IsInfoValid() const;
    GEBool IsOwnerPlayer() const;
    GEBool IsPermanent() const;
    GEBool OnDelivery();
    void OnEndInfo();
    void Read(eCArchiveFile &);
    void Read(bCString const &);
    void SetAsAssigned();
    void SetRunningTimeHours(GEU32 const &);
    bCString Validate() const;
    GEBool Write(bCString const &) const;

  protected:
    GEBool AreConditionsFulfilled() const;
    GEFloat GetDistOwnerToEntity(bCPropertyID const &) const;
    GEFloat GetDistOwnerToEntity(bCString const &) const;
    gCNPC_PS *GetOwnerNPC() const;
    void Invalidate();

  public:
    gCInfoManager_PS *m_pInfoManager;
};

GE_ASSERT_SIZEOF(gCInfo_PS, 0x114)

GE_ASSERT_PROPERTY(gCInfo_PS, m_strName, 0xc, 4)
GE_ASSERT_PROPERTY(gCInfo_PS, m_sortID, 0x10, 4)
GE_ASSERT_PROPERTY(gCInfo_PS, m_owner, 0x14, 4)
GE_ASSERT_PROPERTY(gCInfo_PS, m_bInfoGiven, 0x18, 1)
GE_ASSERT_PROPERTY(gCInfo_PS, m_strParent, 0x1c, 4)
GE_ASSERT_PROPERTY(gCInfo_PS, m_strQuest, 0x20, 4)
GE_ASSERT_PROPERTY(gCInfo_PS, m_enuCondType, 0x24, 8)
GE_ASSERT_PROPERTY(gCInfo_PS, m_enuType, 0x2c, 8)
GE_ASSERT_PROPERTY(gCInfo_PS, m_iInfoGoldCost, 0x34, 4)
GE_ASSERT_PROPERTY(gCInfo_PS, m_condOwnerNearEntity, 0x38, 4)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondPlayerKnows, 0x3c, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_condItemContainer, 0x48, 4)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondItems, 0x4c, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondItemAmounts, 0x58, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondSecondaryNPC, 0x64, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondSecondaryNPCStatus, 0x70, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_teachSkill, 0x7c, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_teachAttrib, 0x88, 4)
GE_ASSERT_PROPERTY(gCInfo_PS, m_teachAttribValue, 0x8c, 4)
GE_ASSERT_PROPERTY(gCInfo_PS, m_bClearChildren, 0x90, 1)
GE_ASSERT_PROPERTY(gCInfo_PS, m_bPermanent, 0x91, 1)
GE_ASSERT_PROPERTY(gCInfo_PS, m_strFolder, 0x98, 4)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondPlayerKnowsNot, 0x9c, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondWearsItem, 0xa8, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondHasSkill, 0xb4, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondReputGroup, 0xc0, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondReputAmount, 0xcc, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondReputRelation, 0xd8, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondPAL, 0xe4, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_arrCondPlayerPartyMember, 0xf0, 12)
GE_ASSERT_PROPERTY(gCInfo_PS, m_bSuppressLog, 0xfc, 1)
GE_ASSERT_PROPERTY(gCInfo_PS, m_infoScript, 0x100, 16)
