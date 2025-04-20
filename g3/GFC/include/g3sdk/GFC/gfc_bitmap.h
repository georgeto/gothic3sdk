#pragma once

#include <GUI.h>

class GE_DLLIMPORT CFFGFCBitmap
{
    // clang-format off
    public: virtual ~CFFGFCBitmap();
    // clang-format on

  public:
    static CFFGFCBitmap *GE_STDCALL FromHandle(IFFGUIBitmap *);

  public:
    CFFGFCBitmap(CFFGFCBitmap const &);
    CFFGFCBitmap();

  public:
    CFFGFCBitmap &operator=(CFFGFCBitmap const &);

  public:
    GEBool Create(bCString const &);
    void Destroy();
    IFFGUIBitmap *GetHandle() const;
    GEBool IsAttached() const;

  protected:
    void SetHandle(IFFGUIBitmap *);

  private:
    IFFGUIBitmap *m_pHandle;
};

GE_ASSERT_SIZEOF(CFFGFCBitmap, 0x8)
