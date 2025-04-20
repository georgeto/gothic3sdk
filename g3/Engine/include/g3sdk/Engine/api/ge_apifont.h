#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCAPITexture;

class GE_DLLIMPORT eCAPIFont
{
    // clang-format off
    public: virtual bEResult GetGlyphData(GEUInt, bCRect &, bCVector2 &, eCAPITexture *&, eCGfxShared::eSGfxLayersDesc &) = 0;
    public: virtual bEResult GetTextIndices(bCString const &, GEU16 *&, GEU16 &) = 0;
    public: virtual bEResult GetTextIndices(bCUnicodeString const &, GEU16 *&, GEU16 &) = 0;
    public: virtual bEResult GetDeviceContext(HDC &) = 0;
    public: virtual bEResult DrawTextA(bCUnicodeString, bCRect *, GEU32, GEU32) = 0;
    public: virtual ~eCAPIFont();
    // clang-format on

  public:
    eCAPIFont(eCAPIFont const &);

  public:
    eCAPIFont &operator=(eCAPIFont const &);

  public:
    GEU32 AddRef();
    GEU32 Release();

  protected:
    eCAPIFont();

  private:
    GEU32 m_u32ReferenceCount;
};
