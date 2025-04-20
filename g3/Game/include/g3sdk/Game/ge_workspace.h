#pragma once

#include <Engine.h>

class gCDatabase;
class gCProject;

class GE_DLLIMPORT gCWorkspace : public eCProcessibleElement
{
    // clang-format off
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCWorkspace() override;
    protected: bEResult PostInitializeProperties() override;
    public: GEBool IsDataAvailable() const override;
    public: bCString GetFileExt() const override;
    public: bCString GetFileType() const override;
    public: bCString GetDataFileExt() const override;
    public: bCString GetDataFileType() const override;
    public: GEU16 GetFileVersion() const override;
    public: bCString GetFileDir() const override;
    protected: eCProcessibleElement::eEResult DoLoadData(bCIStream &) override;
    protected: eCProcessibleElement::eEResult DoSaveData(bCOStream &, bCString const &) override;
    protected: void OnActivate() override;
    protected: eCProcessibleElement::eEResult ReleaseData() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCWorkspace, eCProcessibleElement)
    GE_PROPERTY(bTRefPtrArray<bCPropertyObjectBase *>, Projects, m_arrProjects)
    GE_PROPERTY(bTRefPtrArray<bCPropertyObjectBase *>, Databases, m_arrDatabases)
    GE_PROPERTY(bCString, ActiveProject, m_strCurrentActiveProject)
    GE_PROPERTY(bCString, ActiveDatabase, m_strCurrentActiveDatabase)

  public:
    static void GE_STDCALL GetFileExt(bCString &);
    static gCWorkspace &GE_STDCALL GetInstance();

  public:
    gCProject *AccessCurrentProject();
    eCProcessibleElement::eEResult Create(bCString const &);
    gCDatabase *GetCurrentDatabase();
    gCDatabase *GetDatabase(bCString const &);
    gCDatabase const *GetDatabase(bCString const &) const;
    GEInt GetDatabaseIndex(bCString const &) const;
    gCProject *GetProject(bCString const &);
    gCProject *GetProject(GEInt);
    gCProject const *GetProject(bCString const &) const;
    gCProject const *GetProject(GEInt) const;
    GEInt GetProjectIndex(bCString const &) const;
    eCProcessibleElement::eEResult Import(bCString const &);
    gCDatabase *ImportDatabase(eCArchiveFile &);
    gCDatabase *ImportDatabase(bCString const &);
    gCProject *ImportProject(eCArchiveFile &);
    gCProject *ImportProject(bCString const &);
    gCDatabase *InsertNewDatabase(bCString const &);
    gCProject *InsertNewProject(bCString const &);
    void RemoveAll();
    eCProcessibleElement::eEResult RemoveDatabase(gCDatabase *);
    void RemoveDatabases();
    eCProcessibleElement::eEResult RemoveProject(gCProject *);
    void RemoveProjects();

  protected:
    eCProcessibleElement::eEResult InsertDatabase(gCDatabase *);
    eCProcessibleElement::eEResult InsertProject(gCProject *);
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(gCWorkspace, 0x40)

GE_ASSERT_PROPERTY(gCWorkspace, m_arrProjects, 0x1c, 12)
GE_ASSERT_PROPERTY(gCWorkspace, m_arrDatabases, 0x28, 12)
GE_ASSERT_PROPERTY(gCWorkspace, m_strCurrentActiveProject, 0x34, 4)
GE_ASSERT_PROPERTY(gCWorkspace, m_strCurrentActiveDatabase, 0x38, 4)
