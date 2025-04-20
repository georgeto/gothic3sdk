#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_texcoordsrcbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTexCoordSrcOscillator : public eCTexCoordSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCTexCoordSrcOscillator() override;
    protected: bEResult PostInitializeProperties() override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: void SetTime(GEFloat) override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool GetVSImplementation(bCString &, GEInt, GEBool) override;
    public: GEBool GetPSImplementation(bCString &, GEInt, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCTexCoordSrcOscillator, eCTexCoordSrcBase)
    GE_ENUMPROP(eETexCoordSrcOscillatorType, OscillatorTypeU, m_eOscillatorTypeU)
    GE_ENUMPROP(eETexCoordSrcOscillatorType, OscillatorTypeV, m_eOscillatorTypeV)
    GE_PROPERTY(bCVector2, Amplitude, m_vecAmplitude)
    GE_PROPERTY(bCVector2, Rate, m_vecRate)
    GE_PROPERTY(bCVector2, Phase, m_vecPhase)
    GE_PROPERTY(bCVector2, Offset, m_vecOffset)

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(116)
};

GE_ASSERT_SIZEOF(eCTexCoordSrcOscillator, 0xe8)

GE_ASSERT_PROPERTY(eCTexCoordSrcOscillator, m_eOscillatorTypeU, 0x44, 8)
GE_ASSERT_PROPERTY(eCTexCoordSrcOscillator, m_eOscillatorTypeV, 0x4c, 8)
GE_ASSERT_PROPERTY(eCTexCoordSrcOscillator, m_vecAmplitude, 0x54, 8)
GE_ASSERT_PROPERTY(eCTexCoordSrcOscillator, m_vecRate, 0x5c, 8)
GE_ASSERT_PROPERTY(eCTexCoordSrcOscillator, m_vecPhase, 0x64, 8)
GE_ASSERT_PROPERTY(eCTexCoordSrcOscillator, m_vecOffset, 0x6c, 8)
