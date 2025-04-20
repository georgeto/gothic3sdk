#pragma once

#include <GUI.h>

class CFFGFCBitmap;

class GE_DLLIMPORT CFFGFCImageList
{
    // clang-format off
    public: virtual ~CFFGFCImageList();
    // clang-format on

  public:
    static CFFGFCImageList *GE_STDCALL FromHandle(IFFGUIImageList *);

  public:
    CFFGFCImageList(CFFGFCImageList const &);
    CFFGFCImageList();

  public:
    CFFGFCImageList &operator=(CFFGFCImageList const &);

  public:
    GEInt AddImage(CFFGFCBitmap *);
    void Create();
    void Destroy();
    IFFGUIImageList *GetHandle() const;
    GEInt GetImageCount() const;
    GEBool GetImageInfo(GEInt, SFFGUIBitmap &) const;
    GEBool IsAttached() const;
    GEBool LoadBitmapA(CFFGFCBitmap *, GEInt, GEInt, GEInt, GEU32);
    GEBool RemoveImage(GEInt);
    GEBool ReplaceImage(GEInt, CFFGFCBitmap *);
    GEBool SetImageCount(GEInt);

  protected:
    void SetHandle(IFFGUIImageList *);

  private:
    unsigned __int32 __UNK_0004;
};

GE_ASSERT_SIZEOF(CFFGFCImageList, 0x8)
