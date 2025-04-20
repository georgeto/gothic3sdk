#pragma once

#include <Engine.h>

class gCSector;

class GE_DLLIMPORT gCSectorPersistence_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCSectorPersistence_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCSectorPersistence_PS, eCEntityPropertySet)

  public:
    GEBool CollectSectors();
    GEBool UpdateSector(gCSector *, GEBool);
    GEBool UpdateSectors();

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(gCSectorPersistence_PS, 0x20)
