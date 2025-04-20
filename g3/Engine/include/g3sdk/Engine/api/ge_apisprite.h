#pragma once

#include <SharedBase.h>

class eCAPIFont;
class eCAPITexture;

class GE_DLLIMPORT eCAPISprite
{
    // clang-format off
    public: virtual bEResult Begin(GEU32) = 0;
    public: virtual bEResult Draw(eCAPITexture *, bCRect const *, bCVector const *, bCVector const *, GEU32) = 0;
    public: virtual bEResult DrawTextA(eCAPIFont *, GELPCChar, GEInt, bCRect *, GEU32, GEU32) = 0;
    public: virtual bEResult DrawTextA(eCAPIFont *, GELPCUnicodeChar, GEInt, bCRect *, GEU32, GEU32) = 0;
    public: virtual bEResult Flush() = 0;
    public: virtual bEResult End() = 0;
    public: virtual bEResult GetTransform(bCMatrix *) = 0;
    public: virtual bEResult SetTransform(bCMatrix const *) = 0;
    public: virtual bEResult SetWorldViewLH(bCMatrix const *, bCMatrix const *) = 0;
    public: virtual bEResult SetWorldViewRH(bCMatrix const *, bCMatrix const *) = 0;
    public: virtual ~eCAPISprite();
    // clang-format on

  public:
    eCAPISprite(eCAPISprite const &);

  public:
    eCAPISprite &operator=(eCAPISprite const &);

  public:
    GEU32 AddRef();
    GEU32 Release();

  protected:
    eCAPISprite();

  private:
    GEU32 m_u32ReferenceCount;
};
