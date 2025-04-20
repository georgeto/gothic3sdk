#pragma once

#include <SharedBase.h>

class gCNavigation_PS;
enum gENavObstacleType;

class GE_DLLIMPORT gCCollisionCircle_PSObj
{
    // clang-format off
    public: virtual ~gCCollisionCircle_PSObj();
    // clang-format on

  public:
    gCCollisionCircle_PSObj(gCCollisionCircle_PSObj const &);
    gCCollisionCircle_PSObj();

  public:
    gCCollisionCircle_PSObj &operator=(gCCollisionCircle_PSObj const &);

  public:
    bTSmallArray<gCCollisionCircle_PSObj *> *AccessClusteredCollisionCirclePSObj(bCPropertyID const &);
    bTValArray<bCPropertyID> &AccessNavZoneEntityIDs();
    bTSmallArray<gCCollisionCircle_PSObj *> &AddAndAccessClusteredCollisionCirclePSObj(bCPropertyID const &);
    void AddCollisionCircleOffset(bTValArray<bCMotion> &, bCVector const &, bCVector const &, GEBool);
    bEResult CalculateEvade(bCStretch const &, GEFloat, GEInt);
    bEResult CopyFrom(gCCollisionCircle_PSObj const &);
    void Destroy();
    void DetectCollisionCircleExit(gCNavigation_PS *, bCVector &);
    bTSmallArray<gCCollisionCircle_PSObj *> const &GetClusteredCollisionCirclePSObj(bCPropertyID const &);
    GEBool GetEnabled() const;
    bCPropertyID const &GetEntityID() const;
    bCVector2 const &GetEvade() const;
    GEBool GetNPCCircle() const;
    gENavObstacleType const &GetNavObstacleType() const;
    bTValArray<bCPropertyID> const &GetNavZoneEntityIDs() const;
    bTValArray<GEFloat> const &GetRadius() const;
    GEInt GetRegIndex() const;
    bTValArray<bCVector> const &GetWorldOffset() const;
    GEFloat GetWorldPositionY() const;
    GEBool Intersects(gCCollisionCircle_PSObj *);
    GEBool Intersects(bCInfCylinder *);
    GEBool Intersects(bCInfDoubleCylinder *);
    GEBool IntersectsPoint(bCVector const &, GEBool);
    GEBool IntersectsStretch(bCStretch const &, GEFloat &, GEBool);
    void SetEnabled(GEBool);
    void SetEntityID(bCPropertyID const &);
    void SetNPCCircle(GEBool);
    void SetNavObstacleType(gENavObstacleType const &);
    void SetNavZoneEntityIDs(bTValArray<bCPropertyID> const &);
    void SetRadius(bTValArray<GEFloat> const &, GEFloat);
    void SetRegIndex(GEInt);
    void SetWorldOffset(bTValArray<bCVector> const &);
    void SetWorldPositionY(GEFloat);
    GEBool TestPoint(bCVector const &, GEBool);
    GEBool TestStretch(bCStretch const &, GEBool);

  protected:
    static bTSmallArray<gCCollisionCircle_PSObj *> s_arrDummyCollisionCircle;

  protected:
    void Invalidate();
};
