#pragma once

#include <Game/ge_workspace.h>

#include <Engine.h>

class gCWorld;

class GE_DLLIMPORT gCProject : public eCProcessibleElement
{
    // clang-format off
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCProject() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool IsDataAvailable() const override;
    public: bCString GetFileExt() const override;
    public: bCString GetFileType() const override;
    public: bCString GetDataFileExt() const override;
    public: bCString GetDataFileType() const override;
    public: GEU16 GetFileVersion() const override;
    protected: eCProcessibleElement::eEResult DoLoadData(bCIStream &) override;
    protected: eCProcessibleElement::eEResult DoSaveData(bCOStream &, bCString const &) override;
    protected: void OnModify() override;
    protected: void OnActivate() override;
    public: eCProcessibleElement::eEResult Activate() override;
    protected: eCProcessibleElement::eEResult ReleaseData() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCProject, eCProcessibleElement)
    GE_PROPERTY(bTRefPtrArray<bCPropertyObjectBase *>, Worlds, m_arrWorlds)
    GE_PROPERTY(bCString, ActiveWorld, m_strCurrentActiveWorld)
    GE_PROPERTY(bTPOSmartPtr<gCWorkspace>, WorkspacePtr, m_pWorkspace)

  public:
    static gCProject *GE_STDCALL GetCurrentProject();
    static void GE_STDCALL GetFileExt(bCString &);

  public:
    gCWorkspace &AccessWorkspace();
    gCWorld *AccessWorld(bCString const &);
    gCWorld *AccessWorld(GEInt);
    eCProcessibleElement::eEResult Create(gCWorkspace &, bCString const &);
    gCWorkspace const &GetWorkspace() const;
    gCWorld const *GetWorld(bCString const &) const;
    gCWorld const *GetWorld(GEInt) const;
    GEInt GetWorldIndex(bCString const &) const;
    gCWorld *ImportWorld(eCArchiveFile &);
    gCWorld *ImportWorld(bCString const &);
    gCWorld *InsertNewWorld(bCString const &);
    eCProcessibleElement::eEResult InsertWorld(gCWorld *);
    void RemoveAll();
    eCProcessibleElement::eEResult RemoveWorld(gCWorld *);

  protected:
    void Invalidate();
    void SetWorkspace(bCPropertyObjectBase const *);
    void SetWorkspace(gCWorkspace const *);
};

GE_ASSERT_SIZEOF(gCProject, 0x34)

GE_ASSERT_PROPERTY(gCProject, m_arrWorlds, 0x1c, 12)
GE_ASSERT_PROPERTY(gCProject, m_strCurrentActiveWorld, 0x28, 4)
GE_ASSERT_PROPERTY(gCProject, m_pWorkspace, 0x2c, 8)
