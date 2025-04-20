#pragma once

#include <FileSystem.h>

class GE_DLLIMPORT eCVirtualFileFind
{
    // clang-format off
    public: virtual ~eCVirtualFileFind();
    // clang-format on

  public:
    eCVirtualFileFind(eCVirtualFileFind const &);
    eCVirtualFileFind();

  public:
    eCVirtualFileFind &operator=(eCVirtualFileFind const &);

  public:
    void Close();
    GEBool FindFile(bCString const &);
    GEBool FindNext();
    bCString GetFileName() const;
    bCString GetFilePath() const;
    bCString GetFileTitle() const;
    bCString GetPhysicleFilePath() const;
    bCString GetRoot() const;
    GEBool GetTimeCreated(SFFFileTime &) const;
    GEBool GetTimeLastAccessed(SFFFileTime &) const;
    GEBool GetTimeLastModified(SFFFileTime &) const;
    GEBool IsArchive() const;
    GEBool IsCompressed() const;
    GEBool IsDeleted() const;
    GEBool IsDirectory() const;
    GEBool IsDots() const;
    GEBool IsEncrypted() const;
    GEBool IsHidden() const;
    GEBool IsPacked() const;
    GEBool IsReadOnly() const;
    GEBool IsSystem() const;
    GEBool IsTemporary() const;
    GEBool IsVirtual() const;
    GEBool MatchesMask(GEU32) const;

  protected:
    void Invalidate();
};
