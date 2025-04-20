#pragma once

#include <GUI.h>

class CFFGFCBitmap;
class CFFGFCImageList;
class CFFGFCWnd;

class GE_DLLIMPORT CFFGFCDeviceContext
{
    // clang-format off
    public: virtual ~CFFGFCDeviceContext();
    // clang-format on

  public:
    static CFFGFCDeviceContext *GE_STDCALL FromHandle(IFFGUIDeviceContext *);

  public:
    CFFGFCDeviceContext(CFFGFCDeviceContext const &);
    explicit CFFGFCDeviceContext(CFFGFCWnd * = nullptr);

  public:
    CFFGFCDeviceContext &operator=(CFFGFCDeviceContext const &);

  public:
    GEInt CalcTextRect(GEU32, GELPCChar, GEInt, bCRect &, GEU32);
    GEInt CalcTextRect(GEU32, GELPCUnicodeChar, GEInt, bCRect &, GEU32);
    void Destroy();
    GEBool DrawBitmap(CFFGFCBitmap *, bCRect const *, GEU32, GEFloat);
    GEBool DrawBitmap(CFFGFCImageList *, GEInt, bCRect const *, GEU32, GEFloat);
    GEBool DrawTextA(GEU32, GELPCChar, GEInt, bCRect *, GEU32, bCFloatAlphaColor, bCFloatAlphaColor *);
    GEBool DrawTextA(GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32, bCFloatAlphaColor, bCFloatAlphaColor *);
    IFFGUIDeviceContext *GetHandle() const;
    GEBool IsAttached() const;

  protected:
    void SetHandle(IFFGUIDeviceContext *);

  private:
    IFFGUIDeviceContext *m_pHandle;
};

GE_ASSERT_SIZEOF(CFFGFCDeviceContext, 0x8)
