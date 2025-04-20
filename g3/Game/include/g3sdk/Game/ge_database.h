#pragma once

#include <Game/ge_workspace.h>

#include <Engine.h>

class gCTemplateLayer;

class GE_DLLIMPORT gCDatabase : public eCProcessibleElement
{
    // clang-format off
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCDatabase() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool IsDataAvailable() const override;
    public: bCString GetFileExt() const override;
    public: bCString GetFileType() const override;
    public: bCString GetDataFileExt() const override;
    public: bCString GetDataFileType() const override;
    public: GEU16 GetFileVersion() const override;
    public: bCString GetFileDir() const override;
    protected: eCProcessibleElement::eEResult DoLoadData(bCIStream &) override;
    protected: eCProcessibleElement::eEResult DoSaveData(bCOStream &, bCString const &) override;
    protected: void OnModify() override;
    public: eCProcessibleElement::eEResult Activate() override;
    protected: eCProcessibleElement::eEResult ReleaseData() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCDatabase, eCProcessibleElement)
    GE_PROPERTY(bTRefPtrArray<bCPropertyObjectBase *>, TemplateLayers, m_arrTemplateLayers)
    GE_PROPERTY(bTPOSmartPtr<gCWorkspace>, WorkspacePtr, m_pWorkspace)

  public:
    static void GE_STDCALL GetFileExt(bCString &);
    static void GE_STDCALL SplitTemplatePath(bCString const &, bCString *, bCString *, bCString *, bCString *);

  public:
    gCWorkspace &AccessWorkspace();
    eCProcessibleElement::eEResult Create(gCWorkspace &, bCString const &);
    bCString GetAnimationPath() const;
    bCString GetCompiledAnimationPath() const;
    bCString GetCompiledImagePath() const;
    bCString GetCompiledMaterialLibPath() const;
    bCString GetCompiledMeshPath() const;
    bCString GetCompiledPhysicPath() const;
    bCString GetMaterialImagePath() const;
    bCString GetMaterialLibPath() const;
    bCString GetMeshPath() const;
    bCString GetSaveGamePath() const;
    bCString GetSpeedTreePath() const;
    gCTemplateLayer *GetTemplateLayer(bCString const &);
    gCTemplateLayer *GetTemplateLayer(eCTemplateEntity const &);
    gCTemplateLayer const *GetTemplateLayer(bCString const &) const;
    gCTemplateLayer const *GetTemplateLayer(eCTemplateEntity const &) const;
    gCTemplateLayer *GetTemplateLayerAt(GEInt);
    gCTemplateLayer const *GetTemplateLayerAt(GEInt) const;
    GEInt GetTemplateLayerCount() const;
    GEInt GetTemplateLayerIndex(bCString const &) const;
    bCString GetTemplatePath() const;
    gCWorkspace const &GetWorkspace() const;
    gCTemplateLayer *ImportTemplateLayer(eCArchiveFile &);
    gCTemplateLayer *ImportTemplateLayer(bCString const &);
    gCTemplateLayer *InsertNewTemplateLayer(bCString const &);
    GEBool ReadTemplateLayerHeaders();
    void RemoveAll();
    GEBool RemoveAllTemplateLayers();
    void SaveTemplateLayerHeaders();

  protected:
    void AddToDatabase(bCString const &);
    eCProcessibleElement::eEResult InsertTemplateLayer(gCTemplateLayer *);
    void Invalidate();
    eCProcessibleElement::eEResult RemoveTemplateLayer(gCTemplateLayer *);
    void SetWorkspace(bCPropertyObjectBase const *);
    void SetWorkspace(gCWorkspace const *);

  private:
    GE_UNIMPL_MEMBERS(20)
};

GE_ASSERT_SIZEOF(gCDatabase, 0x44)

GE_ASSERT_PROPERTY(gCDatabase, m_arrTemplateLayers, 0x1c, 12)
GE_ASSERT_PROPERTY(gCDatabase, m_pWorkspace, 0x28, 8)
