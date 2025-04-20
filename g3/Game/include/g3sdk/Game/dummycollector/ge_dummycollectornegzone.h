#pragma once

#include <Game/dummycollector/ge_dummycollectorpset_base.h>

#include <Engine.h>

class GE_DLLIMPORT gCDummyCollectorNegZone : public gCDummyCollectorPSet_Base
{
    // clang-format off
    public: bEResult Collect(bCBox const &) override;
    public: bEResult Collect(eCEntity &) override;
    public: bEResult Apply(bCBox const &) override;
    public: bEResult Apply(eCEntity &) override;
    public: ~gCDummyCollectorNegZone() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: bEResult AddPropertySetMember(eCEntity &, eCEntity *&, GEInt, GEInt, GEInt) override;
    protected: bEResult DeleteIndexInPropertySet(GEInt, GEInt) override;
    protected: bEResult AddIndexInPropertySet(GEInt, GEInt, GEInt, GEInt) override;
    protected: bEResult VisualizeCollectionMember(GEInt, GEBool) override;
    // clang-format on

  public:
    using gCDummyCollectorPSet_Base::Apply;

  public:
    explicit gCDummyCollectorNegZone(eCEntity &);
    gCDummyCollectorNegZone(gCDummyCollectorNegZone const &);

  public:
    gCDummyCollectorNegZone &operator=(gCDummyCollectorNegZone const &);

  protected:
    void RefreshAdditionalProperties(eCEntityPropertySet *, GEInt);
};
