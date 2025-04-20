#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCEntity;
class gCInfoManager_PS;
class gCInventory_PS;
class gCNPC_PS;
class gCQuestManager_PS;

class GE_DLLIMPORT gCQuest_PS : public bCObjectRefBase
{
  public:
    struct SLogEntry
    {
        eCLocString Heading;
        eCLocString Text;

        GE_DECLARE_NO_STREAM_OPERATORS_INLINE(SLogEntry);
    };

    // clang-format off
    public: virtual GEBool IsEditorRelevant() const;
    public: virtual eEPropertySetType GetPropertySetType() const;
    public: virtual void OnPreProcess();
    public: virtual void OnProcess();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCQuest_PS() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCQuest_PS, bCObjectRefBase)
    GE_PROPERTY(bCString, Name, m_strName)
    GE_ENUMPROP(gEQuestType, Type, m_enuType)
    GE_PROPERTY(bTObjArray<bCString>, FinishedQuests, m_arrFinishedQuests)
    GE_PROPERTY(eCLocString, LogTopic, m_strLogTopic)
    GE_PROPERTY(bTObjArray<SLogEntry>, LogText, m_arrLogText)
    GE_PROPERTY(GEU32, ExperiencePoints, m_iXP)
    GE_ENUMPROP(gEPoliticalAlignment, PoliticalSuccess, m_enuPoliticalSuccess)
    GE_PROPERTY(GEI32, PoliticalSuccessAmount, m_politicalSuccessAmount)
    GE_PROPERTY(bCString, EnclaveSuccess, m_enclaveSuccess)
    GE_PROPERTY(GEI32, EnclaveSuccessAmount, m_enclaveSuccessAmount)
    GE_PROPERTY(bCString, AttribSuccess, m_attribSuccess)
    GE_PROPERTY(GEI32, AttribSuccessAmount, m_attribSuccessAmount)
    GE_PROPERTY(bTObjArray<bCString>, DeliveryEntities, m_arrDeliveryEntities)
    GE_PROPERTY(bTValArray<GEU32>, DeliveryAmounts, m_arrDeliveryAmounts)
    GE_PROPERTY(bTValArray<GEI32>, DeliveryCounter, m_arrDeliveryCounter)
    GE_PROPERTY(bCString, DestinationEntity, m_destinationEntity)
    GE_PROPERTY(GEU32, RunningTimeYears, m_u32RunningTimeYears)
    GE_PROPERTY(GEU32, RunningTimeDays, m_u32RunningTimeDays)
    GE_PROPERTY(GEU32, RunningTimeHours, m_u32RunningTimeHours)

  protected:
    eCLocString m_strQuestDesc;
    bCString m_SpellName;

    GE_PROPERTY(bCString, Folder, m_strFolder)
    GE_ENUMPROP(gEPoliticalAlignment, PoliticalFailure, m_enuPoliticalFailure)
    GE_PROPERTY(GEI32, PoliticalFailureAmount, m_politicalFailureAmount)
    GE_PROPERTY(bCString, EnclaveFailure, m_enclaveFailure)
    GE_PROPERTY(GEI32, EnclaveFailureAmount, m_enclaveFailureAmount)
    GE_ENUMPROP(gEQuestStatus, Status, m_status)
    GE_PROPERTY(GEU32, ActivationTime_Year, m_activationTime_Year)
    GE_PROPERTY(GEU32, ActivationTime_Day, m_activationTime_Day)
    GE_PROPERTY(GEU32, ActivationTime_Hour, m_activationTime_Hour)

  public:
    eCLocString &AccessQuestDesc();
    bCString &AccessSpellName();
    GEBool AreFinishedQuestsFinished() const;
    GEBool AreInfosForFinishedQuestsAvailable() const;
    void CheckDeliveryEntitiesStatus();
    eCLocString const &GetQuestDesc() const;
    bCString const &GetSpellName() const;
    GEBool HasNPCallRequiredItems(bCPropertyID const &);
    GEBool HasNPCpartOfRequiredItems(bCPropertyID const &);
    GEBool HaveNPCsAllRequiredItems(bCPropertyID const &, bCPropertyID const &);
    GEBool IsEntityDeliveryEntity(bCString const &) const;
    GEBool IsFinished() const;
    GEBool IsInFinalState() const;
    GEBool IsOvertime() const;
    GEBool IsSucceeded() const;
    void OnEnclaveStateChanged(eCEntity const &);
    void OnEnter(eCEntity const &, bCString const &);
    void OnLeave(eCEntity const &, bCString const &);
    void OnNPCDefeated(eCEntity const &);
    void OnNPCKilled(eCEntity const &);
    void OnReceiveItem(eCEntity const *, eCEntity const *, bCPropertyID const &, GEU32);
    void OnSpellCast(eCEntity const &, eCEntity const &, bCString);
    GEBool Read(bCString const &);
    bEResult ReadRuntimeData(bCIStream &);
    void Reset();
    GEBool SetCancelled();
    GEBool SetFailed();
    void SetQuestDesc(eCLocString const &);
    void SetSpellName(bCString const &);
    GEBool SetStatus(gEQuestStatus const &);
    bCString Validate() const;
    GEBool Write(bCString const &) const;
    bEResult WriteRuntimeData(bCOStream &);

  protected:
    gCEntity *GetEntity(bCPropertyID const &) const;
    gCEntity *GetEntity(bCString const &) const;
    gCInfoManager_PS *GetInfoManager();
    gCInfoManager_PS const *GetInfoManager() const;
    gCInventory_PS *GetInventory(bCPropertyID const &) const;
    gCInventory_PS *GetInventory(bCString const &) const;
    gCNPC_PS *GetNPC(bCPropertyID const &) const;
    gCNPC_PS *GetNPC(bCString const &) const;
    bCPropertyID const GetPropertyIDFromString(bCString const &) const;
    gCQuestManager_PS *GetQuestManager();
    gCQuestManager_PS const *GetQuestManager() const;
    void Invalidate();
    GEBool IsDead(bCPropertyID const &) const;
    GEBool IsDead(bCString const &) const;
    GEBool IsDead(gCEntity *) const;
};

GE_ASSERT_SIZEOF(gCQuest_PS, 0xbc)

GE_ASSERT_PROPERTY(gCQuest_PS, m_strName, 0xc, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_enuType, 0x10, 8)
GE_ASSERT_PROPERTY(gCQuest_PS, m_arrFinishedQuests, 0x18, 12)
GE_ASSERT_PROPERTY(gCQuest_PS, m_strLogTopic, 0x24, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_arrLogText, 0x28, 12)
GE_ASSERT_PROPERTY(gCQuest_PS, m_iXP, 0x34, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_enuPoliticalSuccess, 0x38, 8)
GE_ASSERT_PROPERTY(gCQuest_PS, m_politicalSuccessAmount, 0x40, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_enclaveSuccess, 0x44, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_enclaveSuccessAmount, 0x48, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_attribSuccess, 0x4c, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_attribSuccessAmount, 0x50, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_arrDeliveryEntities, 0x54, 12)
GE_ASSERT_PROPERTY(gCQuest_PS, m_arrDeliveryAmounts, 0x60, 12)
GE_ASSERT_PROPERTY(gCQuest_PS, m_arrDeliveryCounter, 0x6c, 12)
GE_ASSERT_PROPERTY(gCQuest_PS, m_destinationEntity, 0x78, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_u32RunningTimeYears, 0x7c, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_u32RunningTimeDays, 0x80, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_u32RunningTimeHours, 0x84, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_strFolder, 0x90, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_enuPoliticalFailure, 0x94, 8)
GE_ASSERT_PROPERTY(gCQuest_PS, m_politicalFailureAmount, 0x9c, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_enclaveFailure, 0xa0, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_enclaveFailureAmount, 0xa4, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_status, 0xa8, 8)
GE_ASSERT_PROPERTY(gCQuest_PS, m_activationTime_Year, 0xb0, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_activationTime_Day, 0xb4, 4)
GE_ASSERT_PROPERTY(gCQuest_PS, m_activationTime_Hour, 0xb8, 4)
