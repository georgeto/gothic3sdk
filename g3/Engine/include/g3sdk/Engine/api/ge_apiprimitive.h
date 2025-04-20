#pragma once

#include <Engine/ge_gfxshared.h>

class eCAPIIndexData;
class eCAPIVertexData;

class GE_DLLIMPORT eCAPIPrimitive
{
    // clang-format off
    public: virtual GEBool SetStream(GEU32, eCAPIVertexData *) = 0;
    public: virtual GEBool SetIndexData(eCAPIIndexData *) = 0;
    public: virtual GEBool SetVertexDecl(GELPVoid) = 0;
    public: virtual GEBool SetFVF(GEU32) = 0;
    public: virtual GEBool SetStreamSrcFrequency(GEU32, GEU32) = 0;
    public: virtual GEU32 GetStreamSrcFrequency(GEU32) const = 0;
    public: virtual GEBool SetStreamOffset(GEU32, GEU32) = 0;
    public: virtual GEU32 GetStreamOffset(GEU32) const = 0;
    public: virtual GEBool SetStreamStride(GEU32, GEU32) = 0;
    public: virtual GEU32 GetStreamStride(GEU32) const = 0;
    public: virtual GEBool SetDrawCallDescription(eCGfxShared::eSGfxDrawCallDesc const &) = 0;
    public: virtual eCGfxShared::eSGfxDrawCallDesc & GetDrawCallDescription() = 0;
    public: virtual eCGfxShared::eSGfxDrawCallDesc const & GetDrawCallDescription() const = 0;
    public: virtual void EnableStream(GEU32, GEBool) = 0;
    public: virtual GEBool IsStreamEnabled(GEU32) const = 0;
    public: virtual GEBool Execute() = 0;
    public: virtual ~eCAPIPrimitive();
    // clang-format on

  public:
    eCAPIPrimitive(eCAPIPrimitive const &);

  public:
    eCAPIPrimitive &operator=(eCAPIPrimitive const &);

  protected:
    eCAPIPrimitive();

  private:
    GEU32 m_u32ReferenceCount;
};
