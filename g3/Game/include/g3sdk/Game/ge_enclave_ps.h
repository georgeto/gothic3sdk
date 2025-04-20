#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCEnclave_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCEnclave_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnPropertySetAdded() override;
    protected: void OnPropertySetRemoved() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEnclave_PS, eCEntityPropertySet)
    GE_ENUMPROP(gEPoliticalAlignment, PoliticalAlignment, m_enuPoliticalAlignment)
    GE_PROPERTY(GEI32, PlayerFame, m_i32PlayerFame)
    GE_PROPERTY(bTValArray<GEI32>, SuspectComment, m_arrSuspectComment)
    GE_PROPERTY(bTValArray<GEI32>, CrimeCount, m_arrCrimeCount)
    GE_ENUMPROP(gEPlayerCrime, KnownPlayerCrime, m_enuKnownPlayerCrime)
    GE_PROPERTY(GEBool, Revolution, m_bRevolution)
    GE_PROPERTY(GEBool, Raid, m_bRaid)
    GE_PROPERTY(GEBool, Switched, m_bSwitched)
    GE_PROPERTY(GEBool, MusicPlayed, m_bMusicPlayed)
    GE_ENUMPROP(gEEnclaveStatus, Status, m_enuStatus)

  public:
    GEBool AddMember(eCEntity *);
    void BuildMemberList(GEBool);
    eCLocString const GetDisplayName() const;
    bTObjArray<eCEntityProxy> const &GetMembers() const;
    GEBool RemoveMember(eCEntity *);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(gCEnclave_PS, 0x58)

GE_ASSERT_PROPERTY(gCEnclave_PS, m_enuPoliticalAlignment, 0x14, 8)
GE_ASSERT_PROPERTY(gCEnclave_PS, m_i32PlayerFame, 0x1c, 4)
GE_ASSERT_PROPERTY(gCEnclave_PS, m_arrSuspectComment, 0x20, 12)
GE_ASSERT_PROPERTY(gCEnclave_PS, m_arrCrimeCount, 0x2c, 12)
GE_ASSERT_PROPERTY(gCEnclave_PS, m_enuKnownPlayerCrime, 0x38, 8)
GE_ASSERT_PROPERTY(gCEnclave_PS, m_bRevolution, 0x40, 1)
GE_ASSERT_PROPERTY(gCEnclave_PS, m_bRaid, 0x41, 1)
GE_ASSERT_PROPERTY(gCEnclave_PS, m_bSwitched, 0x42, 1)
GE_ASSERT_PROPERTY(gCEnclave_PS, m_bMusicPlayed, 0x43, 1)
GE_ASSERT_PROPERTY(gCEnclave_PS, m_enuStatus, 0x44, 8)
