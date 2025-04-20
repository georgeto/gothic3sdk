#pragma once

#include <Game/ge_dummyvisualbase_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT gCPropertyDummyVisual_PS : public gCDummyVisualBase_PS
{
    // clang-format off
    public: ~gCPropertyDummyVisual_PS() override;
    protected: void OnUpdatedWorldMatrix() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCPropertyDummyVisual_PS, gCDummyVisualBase_PS)

  public:
    eEPropertySetType GetVisPSType() const;
    eCEntityPropertySet *GetVisPropertySet() const;
    void SetBlockApplyExternal(GEBool);
    void SetVisPSType(eEPropertySetType);
    void SetVisPropertySet(eCEntityPropertySet *);

  protected:
    void Invalidate();
    void SetBlockApplyInternal(GEBool);

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(gCPropertyDummyVisual_PS, 0x44)
