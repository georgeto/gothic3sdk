#pragma once

#include <Engine/api/ge_apihlslshader.h>

#include <SharedBase.h>

struct ID3DXBuffer;
struct IDirect3DDevice9;

class GE_DLLIMPORT eCDX9HLSLShader : public eCAPIHLSLShader
{
    // clang-format off
    public: bEResult Compile(eCGfxShared::eSGfxHLSLShaderSrc const &) override;
    public: GELPVoid CreateConstantTable() override;
    public: void DestroyConstantTable(GELPVoid) override;
    public: bEResult GetFunctionData(GELPVoid*, GEU32 &) const override;
    public: bEResult GetShaderType(eCGfxShared::eEGfxHLSLShaderType &) const override;
    public: bEResult GetShaderVersion(GELPVoid, GEU32 &) const override;
    public: bEResult GetConstantCount(GELPVoid, GEUInt &) override;
    public: bEResult GetConstantDescription(GELPVoid, GELPVoid const, GEUInt, eCGfxShared::eSGfxHLSLConstantDesc &, GEBool) const override;
    public: bEResult SetConstant(GELPVoid, GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult SetConstantMatrix(GELPVoid, GELPVoid const, bCMatrix const *) override;
    public: bEResult SetConstantTransposedMatrix(GELPVoid, GELPVoid const, bCMatrix const *) override;
    public: bEResult SetConstantBoolArray(GELPVoid, GELPVoid const, GEInt const *, GEUInt) override;
    public: bEResult SetConstantFloatArray(GELPVoid, GELPVoid const, GEFloat const *, GEUInt) override;
    public: bEResult SetConstantIntArray(GELPVoid, GELPVoid const, GEInt const *, GEUInt) override;
    public: bEResult SetConstantMatrixArray(GELPVoid, GELPVoid const, bCMatrix const *, GEUInt) override;
    public: bEResult SetConstantMatrixPtrArray(GELPVoid, GELPVoid const, bCMatrix const **, GEUInt) override;
    public: bEResult SetConstantMatrixTransposeArray(GELPVoid, GELPVoid const, bCMatrix const *, GEUInt) override;
    public: bEResult SetConstantVectorArray(GELPVoid, GELPVoid const, bCVector4 const *, GEUInt) override;
    public: bEResult GetSamplerIndex(GELPVoid, GELPVoid const, GEUInt &) override;
    public: bEResult Execute() override;
    public: bEResult DestroyShader() override;
    public: bEResult Read(bCIStream &) override;
    public: bEResult Write(bCOStream &) override;
    public: ~eCDX9HLSLShader() override;
    // clang-format on

  public:
    eCDX9HLSLShader(eCDX9HLSLShader const &);

  public:
    eCDX9HLSLShader &operator=(eCDX9HLSLShader const &);

  protected:
    static GEBool s_bFogEnabled;

  protected:
    explicit eCDX9HLSLShader(IDirect3DDevice9 *);

  protected:
    bEResult Create(ID3DXBuffer *, eCGfxShared::eEGfxHLSLShaderType);
    void Destroy();
    GEBool IsValid() const;
};
