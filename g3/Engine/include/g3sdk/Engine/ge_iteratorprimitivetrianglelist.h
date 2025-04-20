#pragma once

#include <Engine/ge_iteratorprimitive.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIteratorPrimitiveTriangleList : public eCIteratorPrimitive
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCIteratorPrimitiveTriangleList const &);
    public: void Destroy() override;
    public: bEResult Create() override;
    public: void Render(bCMatrix const *, eCGfxShared::eECmpFunc, GEBool, GEU8) override;
    public: GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCPrimitiveCollisionDesc **) const override;
    public: GEBool IntersectsVolume(bCVolume &, bCMatrix const &, GEBool) const override;
    public: ~eCIteratorPrimitiveTriangleList() override;
    // clang-format on

  public:
    eCIteratorPrimitiveTriangleList(eCIteratorPrimitiveTriangleList const &);
    eCIteratorPrimitiveTriangleList();

  public:
    eCIteratorPrimitiveTriangleList &operator=(eCIteratorPrimitiveTriangleList const &);

  public:
    GEU32 GetColor() const;
    bTSmallArray<bCVector> &GetTriangleList();
    bTSmallArray<bCVector> const &GetTriangleList() const;
    void SetColor(GEU32);
    void SetTriangleList(bTSmallArray<bCVector> const &);

  protected:
    void Invalidate();
};
