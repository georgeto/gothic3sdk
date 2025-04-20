#pragma once

#include <Engine/ge_basecache.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCCollisionMeshCache : public eCBaseCache
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCCollisionMeshCache() override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCCollisionMeshCache, eCBaseCache)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCCollisionMeshCache, 0xa8)
