#pragma once

#include <Engine.h>

class gCStats;

class GE_DLLIMPORT gCStatistics_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCStatistics_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCStatistics_PS, eCEntityPropertySet)

  public:
    gCStats &GetStats();
    gCStats const &GetStats() const;

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(24)
};

GE_ASSERT_SIZEOF(gCStatistics_PS, 0x2c)
