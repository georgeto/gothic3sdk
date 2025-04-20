#pragma once

#include <Engine/io/file/ge_archivefile.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCArchiveManager : public bCObjectBase
{
    // clang-format off
    public: virtual void CopyTo(eCArchiveManager &) const;
    public: virtual void CopyFrom(eCArchiveManager const &);
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCArchiveManager() override;
    // clang-format on

  public:
    static eCArchiveManager &GE_STDCALL GetInstance();

  public:
    eCArchiveManager(eCArchiveManager const &);
    eCArchiveManager();

  public:
    eCArchiveFile CreateFileA(bCString const &);
    GEBool FindDirectories(bCString, bTObjArray<bCString> &);
    GEBool FindFiles(bCString, bTObjArray<bCString> &);
    GEBool FindFiles(bCString, bTObjArray<eCArchiveFile> &);
    GEBool FindFilesWithExt(bCString, bCString const &, bTObjArray<bCString> &);
    eCArchiveFile GetFile(bCString const &);
    GEBool GetFile(bCString const &, eCArchiveFile &);
    bCString const &GetRootPath();
    void SplitPath(bCString const &, bCString *, bCString *, bCString *);

  protected:
    eCArchiveManager const &operator=(eCArchiveManager const &);

  protected:
    void Invalidate();
};
