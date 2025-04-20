#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCImageList
{
    // clang-format off
    public: virtual ~eCImageList();
    // clang-format on

  public:
    eCImageList(eCImageList const &);
    eCImageList();

  public:
    eCImageList &operator=(eCImageList const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    GEInt AddImage(bCString const &);
    void CopyFrom(eCImageList const &);
    void CopyTo(eCImageList &) const;
    bCString GetImage(GEInt) const;
    GEInt GetImageCount() const;
    GEBool GetImageSize(GEInt, bCPoint &) const;
    GEBool GetMaxImageSize(bCPoint &) const;
    GEInt InsertImage(GEInt, bCString const &);
    bEResult Read(bCIStream &);
    GEBool RemoveImage(GEInt);
    bEResult Write(bCOStream &);

  protected:
    void Destroy();
    void Invalidate();
};
