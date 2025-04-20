#pragma once

#include <Engine/io/file/ge_virtualfile.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCArchiveFile : public bCIOStream
{
  public:
    enum bEArchiveFileAccessMode
    {
        bEArchiveFileAccessMode_Read,
        bEArchiveFileAccessMode_Write,
        bEArchiveFileAccessMode_ReadWrite,
        bEArchiveFileAccessMode_ForceDWORD = GE_FORCE_DWORD
    };

    // clang-format off
    public: virtual void Destroy();
    public: virtual bEResult Create();
    public: virtual GEU32 ReadLine(bCString &);
    public: virtual GEU32 WriteLine(GELPCChar);
    // Overrides for bCIStream
    public: GEU32 Read(GELPVoid, GEU32) override;
    public: GEU32 Read(bCString &) override;
    public: ~eCArchiveFile() override;
    public: GEI64 GetPosition() const override;
    public: GEBool Seek(GEI64, bEStreamSeekMode) override;
    // Overrides for bCOStream
    public: GEU32 Write(GELPCVoid, GEU32) override;
    public: GEU32 Write(bCString const &) override;
    // clang-format on

  public:
    using bCIStream::Read;
    using bCOStream::Write;

  public:
    eCArchiveFile(eCArchiveFile const &);
    eCArchiveFile();

  public:
    eCArchiveFile const &operator=(eCArchiveFile const &);

  public:
    void Clear();
    GEBool Close();
    void CopyFrom(eCArchiveFile const &);
    void CopyTo(eCArchiveFile &) const;
    bCString GetFileBaseName() const;
    void GetFileBaseName(bCString &) const;
    bCString GetFileDir() const;
    bCString GetFileExtension() const;
    void GetFileExtension(bCString &) const;
    bCString GetFileName() const;
    void GetFileName(bCString &) const;
    bCString GetFilePath() const;
    void GetFilePath(bCString &) const;
    GEI64 GetFileSize() const;
    bCDateTime GetFileTime() const;
    GEBool GetPhysicalPath(bCString &) const;
    bCString GetRootPath() const;
    void GetRootPath(bCString &) const;
    GEU16 GetVersion() const;
    GEBool IsInLegacyMode() const;
    GEBool IsOpen() const;
    GEBool IsOpenForWrite() const;
    GEBool IsReadOnly() const;
    GEBool IsValid() const;
    // Fails if the file does not exist. In that case use eCArchiveManager::CreateFileA() to create the file.
    GEBool Open(bEArchiveFileAccessMode a_enuAccessMode, GEBool a_bHandleGenomfleHeader);
    void SetReadOnly(GEBool);
    void SetType(bCString &) const;
    void SetVersion(GEU16);

  protected:
    void Invalidate();

  public:
    /* 0008 */ bCString m_strFileName;
    /* 000C */ eCVirtualFile m_VirtualFile;
    /* 0018 */ bTObjArray<bCString> *m_pStringtableArray;
    /* 001C */ bTValMap<bCString, GEInt> *m_pStringtableMap;
    /* 0020 */ GEBool m_bOpenForWrite;
    GE_PADDING(0x3)
};

GE_ASSERT_SIZEOF(eCArchiveFile, 0x24)
