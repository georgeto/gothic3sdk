#pragma once

#include <Game/dummycollector/ge_dummycollectorpset_base.h>

#include <Engine.h>

class GE_DLLIMPORT gCDummyCollectorTreasureSet : public gCDummyCollectorPSet_Base
{
    // clang-format off
    public: bEResult Collect(bCBox const &) override;
    public: bEResult Collect(eCEntity &) override;
    public: bEResult Apply(bCBox const &) override;
    public: bEResult Apply(eCEntity &) override;
    public: ~gCDummyCollectorTreasureSet() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: bEResult AddPropertySetMember(eCEntity &, eCEntity *&, GEInt, GEInt, GEInt) override;
    protected: bEResult DeleteIndexInPropertySet(GEInt, GEInt) override;
    protected: bEResult AddIndexInPropertySet(GEInt, GEInt, GEInt, GEInt) override;
    protected: bEResult VisualizeCollectionMember(GEInt, GEBool) override;
    // clang-format on

  public:
    using gCDummyCollectorPSet_Base::Apply;

  public:
    explicit gCDummyCollectorTreasureSet(eCEntity &);
    gCDummyCollectorTreasureSet(gCDummyCollectorTreasureSet const &);

  public:
    gCDummyCollectorTreasureSet &operator=(gCDummyCollectorTreasureSet const &);
};
