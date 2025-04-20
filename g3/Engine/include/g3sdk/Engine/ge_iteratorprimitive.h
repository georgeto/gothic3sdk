#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCPrimitiveCollisionDesc;
struct eSRayIntersectionDesc;

class GE_DLLIMPORT eCIteratorPrimitive
{
    // clang-format off
    public: virtual void Destroy();
    public: virtual bEResult Create();
    public: virtual bEResult CopyFrom(eCIteratorPrimitive const &);
    public: virtual void Render(bCMatrix const *, eCGfxShared::eECmpFunc, GEBool, GEU8) = 0;
    public: virtual GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCPrimitiveCollisionDesc **) const = 0;
    public: virtual GEBool IntersectsVolume(bCVolume &, bCMatrix const &, GEBool) const = 0;
    public: virtual ~eCIteratorPrimitive();
    // clang-format on

  public:
    eCIteratorPrimitive(eCIteratorPrimitive const &);
    eCIteratorPrimitive();

  public:
    eCIteratorPrimitive &operator=(eCIteratorPrimitive const &);

  protected:
    void Invalidate();
};
