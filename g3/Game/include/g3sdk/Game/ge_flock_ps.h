#pragma once

#include <Game/ge_boid.h>

#include <Engine.h>

class GE_DLLIMPORT gCFlock_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual void OnBoidStateChanged(eEBoidState);
    public: virtual GEBool Process(eEBoidState);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCFlock_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: void OnTouch(eCEntity *, eCContactIterator &) override;
    public: void OnEnterProcessingRange() override;
    public: void OnExitProcessingRange() override;
    public: void OnCacheIn() override;
    public: void OnCacheOut() override;
    public: void OnPostRead() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCFlock_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, IsLeader, m_bIsLeader)
    GE_PROPERTY(GEBool, IsGround, m_bIsGround)
    GE_PADDING(2)
    GE_PROPERTY(GEU32, MinMembers, m_u32MinMembers)
    GE_PROPERTY(GEU32, MaxMembers, m_u32MaxMembers)
    GE_PROPERTY(GEFloat, SeekMemberDist, m_fSeekMemberDist)
    GE_PROPERTY(GEFloat, NeighbourDist, m_fNeigbourDist)
    GE_PROPERTY(GEFloat, POIVeloScale, m_fPOIVeloScale)
    GE_PROPERTY(GEFloat, NeighbourVeloScale, m_fNeighbourVeloScale)
    GE_PROPERTY(GEFloat, FreeWillPropabilitySecsMin, m_fFreeWillPropabilitySecsMin)
    GE_PROPERTY(GEFloat, FreeWillPropabilitySecsMax, m_fFreeWillPropabilitySecsMax)
    GE_PROPERTY(GEFloat, RoamPropabilitySecsMin, m_fRoamPropabilitySecsMin)
    GE_PROPERTY(GEFloat, RoamPropabilitySecsMax, m_fRoamPropabilitySecsMax)
    GE_PROPERTY(GEFloat, DistanceDampener, m_fDistanceDampener) // Read only
    GE_PROPERTY(bCAnimationResourceString, RoamAni, m_strRoamAni)
    GE_PROPERTY(bCAnimationResourceString, Roam2Ani, m_strRoam2Ani)
    GE_PROPERTY(bCAnimationResourceString, ScatterAni, m_strScatterAni)
    GE_PROPERTY(bCAnimationResourceString, StartAni, m_strStartAni)
    GE_PROPERTY(bCAnimationResourceString, LandAni, m_strLandAni)
    GE_PROPERTY(bCAnimationResourceString, PerchAni, m_strPerchAni)
    GE_PROPERTY(bCAnimationResourceString, FallAni, m_strFallAni)
    GE_PROPERTY(bCAnimationResourceString, MoveAni, m_strMoveAni)
    GE_PROPERTY(bCAnimationResourceString, CurrentAni, m_strAniCurrent) // Read only
    GE_PROPERTY(GEFloat, GroundTimer, m_fGroundTimer)                   // Read only
    GE_PROPERTY(GEFloat, FreeWillTimer, m_fFreeWillTimer)               // Read only
    GE_PROPERTY(GEFloat, FollowTimer, m_fFollowTimer)                   // Read only
    GE_PROPERTY(GEFloat, AmbientTimer, m_fAmbientTimer)                 // Read only
    GE_PROPERTY(GEFloat, AmbientDuration, m_fAmbientDuration)           // Read only
    GE_PROPERTY(bCVector, TouchNormal, m_vecTouchNormal)                // Read only
    GE_PROPERTY(GEBool, IsDead, m_bIsDead)                              // Read only
    GE_PROPERTY(GEBool, FoundGround, m_bFoundGround)                    // Read only
    GE_PROPERTY(GEBool, AmbientAniPlaying, m_bAmbientAniPlaying)        // Read only
    GE_PADDING(1)

  public:
    void ApplyAmbientVelocity(bCVector &);
    bCVector &GetStartPos();
    eEBoidState GetState() const;

  protected:
    void Invalidate();
    void PlayAni(bCAnimationResourceString &);

  private:
    GE_UNIMPL_MEMBERS(16)
};

GE_ASSERT_SIZEOF(gCFlock_PS, 0x9c)

GE_ASSERT_PROPERTY(gCFlock_PS, m_bIsLeader, 0x14, 1)
GE_ASSERT_PROPERTY(gCFlock_PS, m_bIsGround, 0x15, 1)
GE_ASSERT_PROPERTY(gCFlock_PS, m_u32MinMembers, 0x18, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_u32MaxMembers, 0x1c, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fSeekMemberDist, 0x20, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fNeigbourDist, 0x24, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fPOIVeloScale, 0x28, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fNeighbourVeloScale, 0x2c, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fFreeWillPropabilitySecsMin, 0x30, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fFreeWillPropabilitySecsMax, 0x34, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fRoamPropabilitySecsMin, 0x38, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fRoamPropabilitySecsMax, 0x3c, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fDistanceDampener, 0x40, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_strRoamAni, 0x44, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_strRoam2Ani, 0x48, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_strScatterAni, 0x4c, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_strStartAni, 0x50, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_strLandAni, 0x54, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_strPerchAni, 0x58, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_strFallAni, 0x5c, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_strMoveAni, 0x60, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_strAniCurrent, 0x64, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fGroundTimer, 0x68, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fFreeWillTimer, 0x6c, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fFollowTimer, 0x70, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fAmbientTimer, 0x74, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_fAmbientDuration, 0x78, 4)
GE_ASSERT_PROPERTY(gCFlock_PS, m_vecTouchNormal, 0x7c, 12)
GE_ASSERT_PROPERTY(gCFlock_PS, m_bIsDead, 0x88, 1)
GE_ASSERT_PROPERTY(gCFlock_PS, m_bFoundGround, 0x89, 1)
GE_ASSERT_PROPERTY(gCFlock_PS, m_bAmbientAniPlaying, 0x8a, 1)
