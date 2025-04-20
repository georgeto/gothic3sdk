#pragma once

#include <Engine/ge_basecache.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCSoundCache : public eCBaseCache
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCSoundCache() override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCSoundCache, eCBaseCache)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCSoundCache, 0xa8)
