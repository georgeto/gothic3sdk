#pragma once

#include <Engine.h>

class gCInteraction_PS;

class GE_DLLIMPORT gCInteractionAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: ~gCInteractionAdmin() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCInteractionAdmin, eCEngineComponentBase)

  public:
    static gCInteractionAdmin &GE_STDCALL GetInstance();

  public:
    GEBool AddInteractionInROI(gCInteraction_PS *);
    bTValArray<gCInteraction_PS *> const &GetInteractionsInROI();
    void Invalidate();
    GEBool RemoveInteractionInROI(gCInteraction_PS *);

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(gCInteractionAdmin, 0x20)
