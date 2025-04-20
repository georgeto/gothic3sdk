#pragma once

#include <Engine.h>

class gCCharacterMovement_PS;
class gCNavZone_PS;
class gCNavigation_PS;

class GE_DLLIMPORT gCDynamicCollisionCircle_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCDynamicCollisionCircle_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: void OnEnterProcessingRange() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnPostRead() override;
    public: void OnPropertySetAdded() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCDynamicCollisionCircle_PS, eCEntityPropertySet)
    GE_PROPERTY(GEFloat, Radius, m_fRadius)

  public:
    bTValArray<bCMotion> &AccessCorrectedPose();
    bCMotion &AccessLastFramePose();
    bCMotion &AccessWantedPose();
    bCMotion CalcAltStandInterPose(gCDynamicCollisionCircle_PS const *, GEInt);
    void CalcEvadeForFrontalMeeting(gCDynamicCollisionCircle_PS *, gCDynamicCollisionCircle_PS *, bCVector const &,
                                    bCVector const &, GEBool, GEBool, GEBool);
    void CalcEvadeForOverhaul(gCDynamicCollisionCircle_PS *, gCDynamicCollisionCircle_PS *, bCVector const &,
                              bCVector const &, GEBool, GEBool);
    void CalcEvadeForStandardMeeting(gCDynamicCollisionCircle_PS *, gCDynamicCollisionCircle_PS *, bCVector const &,
                                     bCVector const &, GEBool, GEBool);
    void CalcMoveInterPose(bCVector const &, gCDynamicCollisionCircle_PS *, bCVector const &, GEBool, GEBool, GEBool);
    void CalcNewWantedPose(GEFloat);
    bCMotion CalcPreferedStandInterPose(bCVector const &, gCDynamicCollisionCircle_PS const *, eCEntity const *,
                                        gCNavigation_PS *, GEBool);
    void CreateCollisionCirclePSObject(gCNavZone_PS *);
    void DestroyCollisionCirclePSObject();
    gCCharacterMovement_PS *GetCharacterMovement() const;
    bTValArray<bCMotion> const &GetCorrectedPose() const;
    GEFloat GetCurrentRadius() const;
    GEBool GetDCCEnabled() const;
    GEBool GetEnabled() const;
    bCMotion const &GetLastFramePose() const;
    gCNavigation_PS *GetNavigation() const;
    bCMotion const &GetWantedPose() const;
    void SetCharacterMovement(gCCharacterMovement_PS *);
    void SetCorrectedPose(bTValArray<bCMotion> const &);
    void SetDCCEnabled(GEBool);
    void SetEnabled(GEBool);
    void SetLastFramePose(bCMotion const &);
    void SetNavigation(gCNavigation_PS *);
    void SetWantedPose(bCMotion const &);
    GEBool TestNewInterPose(bCMotion &, GEBool);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(176)
};

GE_ASSERT_SIZEOF(gCDynamicCollisionCircle_PS, 0xc8)

GE_ASSERT_PROPERTY(gCDynamicCollisionCircle_PS, m_fRadius, 0x14, 4)
