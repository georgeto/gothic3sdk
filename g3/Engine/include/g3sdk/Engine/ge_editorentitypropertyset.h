#pragma once

#include <Engine/entity/ge_entitypropertyset.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCEditorEntityPropertySet : public eCEntityPropertySet
{
    // clang-format off
    public: virtual GEBool Setup(bCString const &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCEditorEntityPropertySet() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsPersistable() const override;
    public: GEBool IsCopyable() const override;
    public: GEBool IsEditorRelevant() const override;
    public: eCEditorEntityPropertySet * Clone(eCEntity *) const override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    protected: void OnUpdateInternals() override;
    protected: void OnPostUpdateInternals() override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void OnUpdatedWorldTreeBoundary() override;
    protected: void OnCacheIn() override;
    protected: void OnCacheOut() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnProcess() override;
    public: void OnPreProcess() override;
    public: void OnPostRead() override;
    public: void OnDeinitialize() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCEditorEntityPropertySet, eCEntityPropertySet)
    GE_PROPERTY(bCString, MeshFileName, m_strMeshFileName)

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(24)
};

GE_ASSERT_SIZEOF(eCEditorEntityPropertySet, 0x30)

GE_ASSERT_PROPERTY(eCEditorEntityPropertySet, m_strMeshFileName, 0x14, 4)
