#pragma once

#include <SharedBase.h>

class eCShaderEllementBase;

class GE_DLLIMPORT eCShaderEllementProxy
{
    // clang-format off
    public: virtual eCShaderEllementBase * GetShaderEllement() const = 0;
    public: virtual GEBool SetShaderEllement(eCShaderEllementBase *) = 0;
    public: virtual GEBool IsVertexTexCoordUsed(GEInt, GEBool) const = 0;
    public: virtual GEBool IsVertexDiffuseUsed(GEBool) const = 0;
    public: virtual void Read(bCIStream &) = 0;
    public: virtual void Write(bCOStream &) = 0;
    public: virtual ~eCShaderEllementProxy();
    // clang-format on

  public:
    eCShaderEllementProxy(eCShaderEllementProxy const &);
    eCShaderEllementProxy();

  public:
    eCShaderEllementProxy &operator=(eCShaderEllementProxy const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);
};
