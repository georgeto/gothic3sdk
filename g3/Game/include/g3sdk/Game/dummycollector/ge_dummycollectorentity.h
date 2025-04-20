#pragma once

#include <Game/dummycollector/ge_dummycollectorbase.h>

#include <Engine.h>

class GE_DLLIMPORT gCDummyCollectorEntity : public gCDummyCollectorBase
{
    // clang-format off
    public: bEResult Collect(bCBox const &) override;
    public: bEResult Collect(eCEntity &) override;
    public: bEResult Apply() override;
    public: bEResult Apply(bCBox const &) override;
    public: bEResult Apply(eCEntity &) override;
    public: bEResult UpdateCollection() override;
    public: bEResult UpdateCollection(eCEntity &) override;
    public: bEResult ClearCollection() override;
    public: bEResult RemoveFromCollection(eCEntity &) override;
    public: GEU32 GetReferencedEntitiesCount() const override;
    public: eCEntity * GetReferencedEntityAt(GEU32) const override;
    public: GEBool IsInUpdateCollection() const override;
    public: ~gCDummyCollectorEntity() override;
    // clang-format on

  public:
    explicit gCDummyCollectorEntity(eCEntity &);
    gCDummyCollectorEntity(gCDummyCollectorEntity const &);

  public:
    gCDummyCollectorEntity &operator=(gCDummyCollectorEntity const &);
};
