#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCAPIHLSLShader
{
    // clang-format off
    public: virtual bEResult Compile(eCGfxShared::eSGfxHLSLShaderSrc const &) = 0;
    public: virtual GELPVoid CreateConstantTable() = 0;
    public: virtual void DestroyConstantTable(GELPVoid) = 0;
    public: virtual bEResult GetFunctionData(GELPVoid*, GEU32 &) const = 0;
    public: virtual bEResult GetShaderType(eCGfxShared::eEGfxHLSLShaderType &) const = 0;
    public: virtual bEResult GetShaderVersion(GELPVoid, GEU32 &) const = 0;
    public: virtual bEResult GetConstantCount(GELPVoid, GEUInt &) = 0;
    public: virtual bEResult GetConstantDescription(GELPVoid, GELPVoid const, GEUInt, eCGfxShared::eSGfxHLSLConstantDesc &, GEBool) const = 0;
    public: virtual bEResult SetConstant(GELPVoid, GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult SetConstantMatrix(GELPVoid, GELPVoid const, bCMatrix const *) = 0;
    public: virtual bEResult SetConstantTransposedMatrix(GELPVoid, GELPVoid const, bCMatrix const *) = 0;
    public: virtual bEResult SetConstantBoolArray(GELPVoid, GELPVoid const, GEInt const *, GEUInt) = 0;
    public: virtual bEResult SetConstantFloatArray(GELPVoid, GELPVoid const, GEFloat const *, GEUInt) = 0;
    public: virtual bEResult SetConstantIntArray(GELPVoid, GELPVoid const, GEInt const *, GEUInt) = 0;
    public: virtual bEResult SetConstantMatrixArray(GELPVoid, GELPVoid const, bCMatrix const *, GEUInt) = 0;
    public: virtual bEResult SetConstantMatrixPtrArray(GELPVoid, GELPVoid const, bCMatrix const **, GEUInt) = 0;
    public: virtual bEResult SetConstantMatrixTransposeArray(GELPVoid, GELPVoid const, bCMatrix const *, GEUInt) = 0;
    public: virtual bEResult SetConstantVectorArray(GELPVoid, GELPVoid const, bCVector4 const *, GEUInt) = 0;
    public: virtual bEResult GetSamplerIndex(GELPVoid, GELPVoid const, GEUInt &) = 0;
    public: virtual bEResult Execute() = 0;
    public: virtual bEResult DestroyShader() = 0;
    public: virtual bEResult Read(bCIStream &) = 0;
    public: virtual bEResult Write(bCOStream &) = 0;
    public: virtual ~eCAPIHLSLShader();
    // clang-format on

  public:
    eCAPIHLSLShader(eCAPIHLSLShader const &);

  public:
    eCAPIHLSLShader &operator=(eCAPIHLSLShader const &);

  public:
    GEU32 AddRef();
    GEU32 Release();

  protected:
    eCAPIHLSLShader();

  private:
    GEU32 m_u32ReferenceCount;
};
