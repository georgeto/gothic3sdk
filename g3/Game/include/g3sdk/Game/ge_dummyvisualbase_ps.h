#pragma once

#include <Engine.h>

class gCDummyCollectorBase;

class GE_DLLIMPORT gCDummyVisualBase_PS : public eCEditorEntityPropertySet
{
    // clang-format off
    public: void Destroy() override;
    public: ~gCDummyVisualBase_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCDummyVisualBase_PS, eCEditorEntityPropertySet)

  public:
    gCDummyCollectorBase *GetVisCollector() const;
    eCEntity *GetVisGameEntity() const;
    void SetVisCollector(gCDummyCollectorBase *);
    void SetVisGameEntity(eCEntity *);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(8)
};

GE_ASSERT_SIZEOF(gCDummyVisualBase_PS, 0x38)
