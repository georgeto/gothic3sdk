#pragma once

#include <Engine/ge_geometrycollisiondesc.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCPolyGeometryCollisionDesc : public eCGeometryCollisionDesc
{
    // clang-format off
    public: virtual bCTriangle GetLocalPolygon(GEInt) const = 0;
    public: virtual GEBool GetLocalPolygon(bCTriangle &, GEInt) const = 0;
    public: virtual bCTriangle GetWorldPolygon(GEInt) const = 0;
    public: virtual GEBool GetWorldPolygon(bCTriangle &, GEInt) const = 0;
    protected: ~eCPolyGeometryCollisionDesc() override;
    // clang-format on

  public:
    eCPolyGeometryCollisionDesc(eCPolyGeometryCollisionDesc const &);
    explicit eCPolyGeometryCollisionDesc(eCGeometryCollisionDesc const &);
    eCPolyGeometryCollisionDesc();

  public:
    eCPolyGeometryCollisionDesc &operator=(eCPolyGeometryCollisionDesc const &);
};
