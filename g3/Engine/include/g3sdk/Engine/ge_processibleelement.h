#pragma once

#include <SharedBase.h>

class eCArchiveFile;

class GE_DLLIMPORT eCProcessibleElement : public bCObjectRefBase
{
  public:
    enum eEResult
    {
        // TODO: Enumerator values
    };

    enum eEState
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: virtual GEBool IsDataAvailable() const;
    protected: virtual GEFloat QueryProgress() const;
    public: virtual bCString GetFileExt() const;
    public: virtual bCString GetFileType() const;
    public: virtual bCString GetDataFileExt() const;
    public: virtual bCString GetDataFileType() const;
    public: virtual GEU16 GetFileVersion() const;
    public: virtual bCString GetFileDir() const;
    protected: virtual eEResult DoLoadData(bCIStream &);
    protected: virtual eEResult DoSaveData(bCOStream &, bCString const &);
    protected: virtual eEResult Load(bCString const &);
    protected: virtual eEResult Load(eCArchiveFile &);
    public: virtual eEResult Save();
    protected: virtual void OnModify();
    protected: virtual void OnActivate();
    protected: virtual GEBool CanGotoState(eEState);
    protected: virtual void UpdateState();
    public: virtual eEResult Activate();
    protected: virtual eEResult CreateFileA(bCString const &, bCString const &);
    protected: virtual eEResult CreateData();
    protected: virtual eEResult ReleaseData();
    protected: virtual eEResult Create(bCString const &, bCString const &);
    public: GEBool IsValid() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCProcessibleElement() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCProcessibleElement, bCObjectRefBase)
    GE_PROPERTY(GEBool, IsPersistable, m_bIsPersistable)
    GE_PADDING(1)

  public:
    GEBool CanHaveData() const;
    eEResult Deactivate();
    bCString GetDataFilePath() const;
    bCString GetFileBaseName() const;
    bCString GetFileName() const;
    bCString GetFilePath() const;
    eEState GetState() const;
    GEBool IsActive();
    GEBool IsModified() const;
    eEState QueryState();
    void SetFileBaseName(bCString const &);
    void SetModified();

  protected:
    void Invalidate();
    eEResult LoadData();
    eEResult SaveData();

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(eCProcessibleElement, 0x1c)

GE_ASSERT_PROPERTY(eCProcessibleElement, m_bIsPersistable, 0xc, 1)
