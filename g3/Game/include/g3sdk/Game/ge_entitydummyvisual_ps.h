#pragma once

#include <Game/ge_dummyvisualbase_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT gCEntityDummyVisual_PS : public gCDummyVisualBase_PS
{
    // clang-format off
    public: void Destroy() override;
    public: ~gCEntityDummyVisual_PS() override;
    protected: void OnUpdatedWorldMatrix() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEntityDummyVisual_PS, gCDummyVisualBase_PS)

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(gCEntityDummyVisual_PS, 0x3c)
