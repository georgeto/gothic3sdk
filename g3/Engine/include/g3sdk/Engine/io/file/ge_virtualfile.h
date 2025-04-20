#pragma once

#include <FileSystem.h>

class GE_DLLIMPORT eCVirtualFile : public bCFile
{
    // clang-format off
    public: virtual GEBool IsEof() const;
    public: virtual bCString GetFileName() const;
    public: virtual GEBool IsReadOnly() const;
    public: virtual void SetReadOnly(GEBool);
    public: virtual GEBool Open(bCString const &, bEFileCreationMode, GEU8);
    // Overrides for bCIStream
    public: GEU32 Read(GELPVoid, GEU32) override;
    public: ~eCVirtualFile() override;
    public: GEI64 GetPosition() const override;
    public: GEBool Seek(GEI64, bEStreamSeekMode) override;
    public: GEBool IsValid() const override;
    public: GEBool IsOpen() const override;
    public: GEI64 GetLength() const override;
    public: GEBool Close() override;
    // Overrides for bCOStream
    public: GEU32 Write(GELPCVoid, GEU32) override;
    // clang-format on

  public:
    eCVirtualFile(eCVirtualFile const &);
    explicit eCVirtualFile(IFFVirtualFile *File = nullptr);

  public:
    eCVirtualFile &operator=(eCVirtualFile const &);
    eCVirtualFile &operator=(IFFVirtualFile *);

  public:
    GEBool GetPhysicalPath(bCString &) const;

  protected:
    void Destroy();
    void Invalidate();
    void SetFile(IFFVirtualFile *);

  private:
    // 0000 // eCVirtualFile::`vftable'{for `bCIStream'}
    // 0004 // eCVirtualFile::`vftable'{for `bCOStream'}
    /* 0008 */ IFFVirtualFile *m_pFile;
};

GE_ASSERT_SIZEOF(eCVirtualFile, 0xc)
