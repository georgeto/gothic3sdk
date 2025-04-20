#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCGfxHLSLShader : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult Create(eCGfxShared::eSGfxHLSLShaderSrc const &);
    public: virtual bEResult CopyFrom(eCGfxHLSLShader const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxHLSLShader() override;
    // clang-format on

  public:
    eCGfxHLSLShader(eCGfxHLSLShader const &);
    eCGfxHLSLShader();

  public:
    eCGfxHLSLShader &operator=(eCGfxHLSLShader const &);

  public:
    GELPVoid CreateConstantTable();
    void DestroyConstantTable(GELPVoid);
    bEResult DestroyShader();
    bEResult Execute();
    bEResult GetConstantCount(GELPVoid, GEUInt &);
    bEResult GetConstantDescription(GELPVoid, GELPVoid const, GEUInt, eCGfxShared::eSGfxHLSLConstantDesc &,
                                    GEBool) const;
    bEResult GetFunctionData(GELPVoid *, GEU32 &) const;
    bEResult GetSamplerIndex(GELPVoid, GELPVoid const, GEUInt &);
    bEResult GetShaderType(eCGfxShared::eEGfxHLSLShaderType &) const;
    bEResult GetShaderVersion(GELPVoid, GEU32 &) const;
    void Invalidate();
    bEResult SetConstant(GELPVoid, GELPVoid const, GELPVoid const, GEUInt);
    bEResult SetConstantBoolArray(GELPVoid, GELPVoid const, GEInt const *, GEUInt);
    bEResult SetConstantFloatArray(GELPVoid, GELPVoid const, GEFloat const *, GEUInt);
    bEResult SetConstantIntArray(GELPVoid, GELPVoid const, GEInt const *, GEUInt);
    bEResult SetConstantMatrix(GELPVoid, GELPVoid const, bCMatrix const *);
    bEResult SetConstantMatrixArray(GELPVoid, GELPVoid const, bCMatrix const *, GEUInt);
    bEResult SetConstantMatrixPtrArray(GELPVoid, GELPVoid const, bCMatrix const **, GEUInt);
    bEResult SetConstantMatrixTransposeArray(GELPVoid, GELPVoid const, bCMatrix const *, GEUInt);
    bEResult SetConstantTransposedMatrix(GELPVoid, GELPVoid const, bCMatrix const *);
    bEResult SetConstantVectorArray(GELPVoid, GELPVoid const, bCVector4 const *, GEUInt);
};
