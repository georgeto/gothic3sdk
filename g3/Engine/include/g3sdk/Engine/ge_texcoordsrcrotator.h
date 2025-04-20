#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_texcoordsrcbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTexCoordSrcRotator : public eCTexCoordSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCTexCoordSrcRotator() override;
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
    GE_PROPERTY_SET(eCTexCoordSrcRotator, eCTexCoordSrcBase)
    GE_ENUMPROP(eETexCoordSrcRotatorType, RotationType, m_eRotationType)
    GE_PROPERTY(bCEulerAngles, Angle, m_eulAngle)
    GE_PROPERTY(bCVector2, Offset, m_vecOffset)
    GE_PROPERTY(bCEulerAngles, Rate, m_eulRate)
    GE_PROPERTY(bCEulerAngles, Amplitude, m_eulAmplitude)
    GE_PROPERTY(bCEulerAngles, Phase, m_eulPhase)

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(100)
};

GE_ASSERT_SIZEOF(eCTexCoordSrcRotator, 0xe8)

GE_ASSERT_PROPERTY(eCTexCoordSrcRotator, m_eRotationType, 0x44, 8)
GE_ASSERT_PROPERTY(eCTexCoordSrcRotator, m_eulAngle, 0x4c, 12)
GE_ASSERT_PROPERTY(eCTexCoordSrcRotator, m_vecOffset, 0x58, 8)
GE_ASSERT_PROPERTY(eCTexCoordSrcRotator, m_eulRate, 0x60, 12)
GE_ASSERT_PROPERTY(eCTexCoordSrcRotator, m_eulAmplitude, 0x6c, 12)
GE_ASSERT_PROPERTY(eCTexCoordSrcRotator, m_eulPhase, 0x78, 12)
