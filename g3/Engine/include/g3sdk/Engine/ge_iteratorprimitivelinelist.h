#pragma once

#include <Engine/ge_iteratorprimitive.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIteratorPrimitiveLineList : public eCIteratorPrimitive
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCIteratorPrimitiveLineList const &);
    public: void Destroy() override;
    public: bEResult Create() override;
    public: void Render(bCMatrix const *, eCGfxShared::eECmpFunc, GEBool, GEU8) override;
    public: GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCPrimitiveCollisionDesc **) const override;
    public: GEBool IntersectsVolume(bCVolume &, bCMatrix const &, GEBool) const override;
    public: ~eCIteratorPrimitiveLineList() override;
    // clang-format on

  public:
    eCIteratorPrimitiveLineList(eCIteratorPrimitiveLineList const &);
    eCIteratorPrimitiveLineList();

  public:
    eCIteratorPrimitiveLineList &operator=(eCIteratorPrimitiveLineList const &);

  public:
    GEU32 GetColor() const;
    bTSmallArray<bCVector> &GetLineList();
    bTSmallArray<bCVector> const &GetLineList() const;
    void SetColor(GEU32);
    void SetLineList(bTSmallArray<bCVector> const &);

  protected:
    void Invalidate();
};
