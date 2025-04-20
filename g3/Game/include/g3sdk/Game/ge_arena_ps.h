#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCArena_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCArena_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void GetBoundary(bCBox &, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCArena_PS, eCEntityPropertySet)
    GE_ENUMPROP(gEArenaStatus, Status, m_enuStatus)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCArena_PS, 0x1c)

GE_ASSERT_PROPERTY(gCArena_PS, m_enuStatus, 0x14, 8)
