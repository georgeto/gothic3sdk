#pragma once

#include <Engine/ge_shaderbase.h>

#include <SharedBase.h>

class eCColorSrcProxy;

class GE_DLLIMPORT eCShaderVegetation : public eCShaderBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCShaderVegetation() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: void SetTime(GEFloat) override;
    public: GEBool IsVertexTexCoordUsed(GEInt, GEBool) const override;
    public: GEBool IsVertexDiffuseUsed(GEBool) const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    protected: GEBool CreateShaderVersion(eEShaderMaterialVersion) override;
    public: GEBool HasOpacity() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCShaderVegetation, eCShaderBase)

  public:
    GEFloat &AccessAlphaDisolveEnd();
    GEFloat &AccessAlphaDisolveStart();
    bCVector2 &AccessWindAmplitude();
    bCVector2 &AccessWindPhaseConstant();
    bCVector2 &AccessWindWaveLenght();
    GEFloat const &GetAlphaDisolveEnd() const;
    GEFloat const &GetAlphaDisolveStart() const;
    eCColorSrcProxy &GetColorSrcAlphaDisolve();
    eCColorSrcProxy &GetColorSrcDiffuse();
    bCVector2 const &GetWindAmplitude() const;
    bCVector2 const &GetWindPhaseConstant() const;
    bCVector2 const &GetWindWaveLenght() const;
    void SetAlphaDisolveEnd(GEFloat const &);
    void SetAlphaDisolveStart(GEFloat const &);
    void SetWindAmplitude(bCVector2 const &);
    void SetWindPhaseConstant(bCVector2 const &);
    void SetWindWaveLenght(bCVector2 const &);

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(332)
};

GE_ASSERT_SIZEOF(eCShaderVegetation, 0x20c)
