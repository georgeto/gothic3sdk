#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCAttribute;

enum gETutorialFlag
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT gCPlayerMemory_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCPlayerMemory_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void OnSaveGameEntityPostRead() override;
    public: void OnPostRead() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCPlayerMemory_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, HideTips, m_bHideTips) // Read only
    GE_PADDING(3)
    GE_PROPERTY(bTObjArray<bCString>, PlayerKnows, m_arrPlayerKnows)
    GE_PROPERTY(bTValArray<GEI32>, PoliticalFame, m_arrPoliticalFame)
    GE_PROPERTY(bTValArray<GEI32>, PoliticalSuspectComment, m_arrPoliticalSuspectComment)
    GE_PROPERTY(bTValArray<GEI32>, PoliticalCrimeCount, m_arrPoliticalCrimeCount)
    GE_PROPERTY(bTValArray<GEBool>, PoliticalPlayerCrime, m_arrPoliticalPlayerCrime)
    GE_PROPERTY(GEI32, XP, m_iXP)
    GE_PROPERTY(GEI32, LPAttribs, m_iLPAttribs)
    GE_PROPERTY(GEI32, LPPerks, m_iLPPerks)
    GE_ENUMPROP(gEWeaponConfig, LastWeaponConfig, m_enuLastWeaponConfig)    // Read only
    GE_PROPERTY(bCPropertyID, LastSpell, m_LastSpell)                       // Read only
    GE_PROPERTY(GEFloat, SecondsTransformRemain, m_fSecondsTransformRemain) // Read only
    GE_PROPERTY(GEFloat, SecondsMistRemain, m_fSecondsMistRemain)           // Read only
    GE_PROPERTY(GEI32, BookOfFlood, m_BookOfFlood)
    GE_PROPERTY(GEI32, BookOfRhobar, m_BookOfRhobar)
    GE_PROPERTY(GEI32, BookOfZuben, m_BookOfZuben)
    GE_PROPERTY(GEI32, DuskToDawnStartHour, m_iDuskToDawnStartHour)
    GE_PROPERTY(GEI32, Chapter, m_iChapter)
    GE_PROPERTY(GEU32, TutorialFlags, m_u32TutorialFlags)    // Read only
    GE_PROPERTY(GEBool, TalkedToDiego, m_bTalkedToDiego)     // Read only
    GE_PROPERTY(GEBool, TalkedToGorn, m_bTalkedToGorn)       // Read only
    GE_PROPERTY(GEBool, TalkedToMilten, m_bTalkedToMilten)   // Read only
    GE_PROPERTY(GEBool, TalkedToLester, m_bTalkedToLester)   // Read only
    GE_PROPERTY(GEFloat, TimeStampStart, m_fTimeStampStart)  // Read only
    GE_PROPERTY(GEBool, IsConsumingItem, m_bIsConsumingItem) // Read only
    GE_PADDING(1)

  public:
    GEBool AddBaseValue(bCString const &, GEInt);
    GEBool AddMaximum(bCString const &, GEInt);
    GEBool AddModifier(bCString const &, GEInt);
    GEBool AddValue(bCString const &, GEInt);
    GEBool ApplyMod(bCString const &, GEInt, EAttribModOperation);
    GEInt CalcMissingValue(bCString const &, GEInt) const;
    GEBool Consume(bCString const &, GEInt, EAttribModOperation);
    void EnableTutorial(gETutorialFlag, GEBool);
    gCAttribute *GetAttribute(bCString const &) const;
    bTObjMap<bCString, gCAttribute *> const &GetAttributes() const;
    GEInt GetBaseValue(bCString const &) const;
    GEInt GetMaximum(bCString const &) const;
    GEInt GetModifier(bCString const &) const;
    GEInt GetValue(bCString const &) const;
    GEBool IsTutorialEnabled(gETutorialFlag) const;
    GEBool SetBaseValue(bCString const &, GEInt);
    GEBool SetMaximum(bCString const &, GEInt);
    GEBool SetModifier(bCString const &, GEInt);
    GEBool SetValue(bCString const &, GEInt);
    GEBool UnapplyMod(bCString const &, GEInt, EAttribModOperation);

  protected:
    GEBool CreateAttrib(bCString const &);
    GEInt CreateAttributes();
    GEBool CreateStat(bCString const &);
    void DestroyAttributes();
    void Invalidate();
    GEBool ReadAttributes(bCIStream &);
    GEBool ReadAttributesV3(bCIStream &);
    GEBool ReadAttributesV4(bCIStream &);
    GEBool WriteAttributes(bCOStream &);

  private:
    GE_UNIMPL_MEMBERS(16)
};

GE_ASSERT_SIZEOF(gCPlayerMemory_PS, 0xb8)

GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_bHideTips, 0x14, 1)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_arrPlayerKnows, 0x18, 12)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_arrPoliticalFame, 0x24, 12)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_arrPoliticalSuspectComment, 0x30, 12)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_arrPoliticalCrimeCount, 0x3c, 12)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_arrPoliticalPlayerCrime, 0x48, 12)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_iXP, 0x54, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_iLPAttribs, 0x58, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_iLPPerks, 0x5c, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_enuLastWeaponConfig, 0x60, 8)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_LastSpell, 0x68, 20)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_fSecondsTransformRemain, 0x7c, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_fSecondsMistRemain, 0x80, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_BookOfFlood, 0x84, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_BookOfRhobar, 0x88, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_BookOfZuben, 0x8c, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_iDuskToDawnStartHour, 0x90, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_iChapter, 0x94, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_u32TutorialFlags, 0x98, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_bTalkedToDiego, 0x9c, 1)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_bTalkedToGorn, 0x9d, 1)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_bTalkedToMilten, 0x9e, 1)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_bTalkedToLester, 0x9f, 1)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_fTimeStampStart, 0xa0, 4)
GE_ASSERT_PROPERTY(gCPlayerMemory_PS, m_bIsConsumingItem, 0xa4, 1)
