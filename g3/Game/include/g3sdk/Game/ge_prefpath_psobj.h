#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT gCPrefPath_PSObj
{
    // clang-format off
    public: virtual ~gCPrefPath_PSObj();
    // clang-format on

  public:
    gCPrefPath_PSObj(gCPrefPath_PSObj const &);
    gCPrefPath_PSObj();

  public:
    gCPrefPath_PSObj &operator=(gCPrefPath_PSObj const &);

  public:
    bCPropertyID &AccessNavZoneEntityID();
    GEBool ConeTriangleContains(bCVector const &, bCVector const &, bCVector const &);
    GEBool ConeTriangleIntersects(bCVector const &, bCVector const &, bCVector &, bCVector &, GEBool &);
    GEBool ContainsPosition(bCVector const &);
    bEResult CopyFrom(gCPrefPath_PSObj const &);
    void Destroy();
    bCPropertyID const &GetNavZoneEntityID() const;
    bTValArray<GEFloat> const &GetPointRadius() const;
    GEFloat const &GetRadius() const;
    GEInt GetRegIndex() const;
    bTValArray<bCVector> const &GetWorldPoint() const;
    bCVector const &GetWorldRadiusOffset() const;
    GEBool LimitSectionToCone(bCVector &, bCVector &, bCVector const &, bCVector const &, GEBool &);
    void SetNavZoneEntityID(bCPropertyID const &);
    void SetPointRadius(bTValArray<GEFloat> const &);
    void SetRadius(GEFloat const &);
    void SetRegIndex(GEInt);
    void SetWorldPoint(bTValArray<bCVector> const &);
    void SetWorldRadiusOffset(bCVector const &);
    GEBool TestPreferredPathUse(bCStretch const &, GEFloat &, bCVector const &);
    GEBool UsePreferredPath(bCVector &, bCVector &, GEInt &, GEInt &);

  protected:
    void Invalidate();
};
