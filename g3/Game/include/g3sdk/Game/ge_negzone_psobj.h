#pragma once

#include <SharedBase.h>

class gCNavigation_PS;

class GE_DLLIMPORT gCNegZone_PSObj
{
    // clang-format off
    public: virtual ~gCNegZone_PSObj();
    // clang-format on

  public:
    gCNegZone_PSObj(gCNegZone_PSObj const &);
    gCNegZone_PSObj();

  public:
    gCNegZone_PSObj &operator=(gCNegZone_PSObj const &);

  public:
    bCPropertyID &AccessNavZoneEntityID();
    bEResult CopyFrom(gCNegZone_PSObj const &);
    void Destroy();
    bCVector const &Get3DEvade();
    bCPropertyID const &GetEntityID() const;
    bCVector2 const &GetEvade();
    bCPropertyID const &GetNavZoneEntityID() const;
    GEFloat const &GetRadius() const;
    GEInt GetRegIndex() const;
    bTValArray<bCVector> const &GetWorldPoint() const;
    bCVector const &GetWorldRadiusOffset() const;
    GEBool const &GetZoneIsCCW() const;
    GEBool IntersectsPoint(bCVector const &, GEBool);
    GEBool IntersectsStretch(bCStretch const &, GEFloat &, gCNavigation_PS *, GEBool);
    GEBool IsZoneIllegal();
    void OnStakesChanged();
    void SetEntityID(bCPropertyID const &);
    void SetNavZoneEntityID(bCPropertyID const &);
    void SetRadius(GEFloat const &);
    void SetRegIndex(GEInt);
    void SetWorldPoint(bTValArray<bCVector> const &);
    void SetWorldRadiusOffset(bCVector const &);
    void SetZoneIsCCW(GEBool const &);
    GEBool Test3DPointInZone(bCVector const &, GEBool);
    GEBool TestPoint(bCVector const &, GEBool);
    GEBool TestStretch(bCStretch const &);

  protected:
    bEResult AddLeftAndRightAngle(bCVector &, bCVector &, GEFloat &, GEFloat &);
    GEFloat CalcAngleSumStakeA(GEInt &);
    GEFloat CalcAngleSumStakeB(GEInt &);
    bEResult GetAngleSums(GEFloat &, GEFloat &);
    void Invalidate();
    bCVector2 const &RunNPCInZoneNavigation(GEBool);
    bCVector2 const &RunTargetBehindZoneNavigation();
    bCVector2 const &RunTargetInZoneNavigation(GEBool);
    GEBool SetFirstIntersection(GEFloat &);
    bEResult TestNPCAndTargetLocation(GEBool &, GEBool &);
    GEBool TestRealIntersection(bCStretch const &, GEFloat &, GEBool);
};
