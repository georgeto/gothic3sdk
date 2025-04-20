#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCEditorEntityPropertySet : public eCEditorEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCEditorEntityPropertySet() override;
    public: GEBool IsEditorRelevant() const override;
    protected: void OnUpdatedWorldMatrix() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEditorEntityPropertySet, eCEditorEntityPropertySet)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCEditorEntityPropertySet, 0x30)
