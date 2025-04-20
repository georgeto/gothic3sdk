#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_colorsrcbase.h>
#include <Engine/ge_stringwrapper.h>

#include <SharedBase.h>

class eCResourceImage_PS;
class eCTexCoordSrcProxy;

enum eEColorSrcSamplerType
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCColorSrcSampler : public eCColorSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCColorSrcSampler() override;
    protected: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: void SetSwitch(GEInt) override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: void SetTime(GEFloat) override;
    public: void BeforeCompileShader() override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool Prefetch(GEBool, GEInt) override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: GEBool GetImplementation(bCString &, eEShaderColorSrcComponent, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCColorSrcSampler, eCColorSrcBase)
    GE_PROPERTY(bCImageResourceString, ImageFilePath, m_strImageFilePath)
    GE_ENUMPROP(eEColorSrcSampleTexRepeat, TexRepeatU, m_eTexRepeatU)
    GE_ENUMPROP(eEColorSrcSampleTexRepeat, TexRepeatV, m_eTexRepeatV)
    GE_PROPERTY(GEFloat, AnimationSpeed, m_fAnimationSpeed)
    GE_ENUMPROP(eEColorSrcSwitchRepeat, SwitchRepeat, m_eSwitchRepeat)

  public:
    eCResourceImage_PS *GetImageResource() const;
    eEColorSrcSamplerType GetSamplerType() const;
    eCTexCoordSrcProxy &GetTexCoordSrc();
    void SetImageResource(eCResourceImage_PS *);

  protected:
    void DestroyLocal();
    void Invalidate();
    void SetSamplerType(eEColorSrcSamplerType);

  private:
    GE_UNIMPL_MEMBERS(108)
};

GE_ASSERT_SIZEOF(eCColorSrcSampler, 0xd0)

GE_ASSERT_PROPERTY(eCColorSrcSampler, m_strImageFilePath, 0x44, 4)
GE_ASSERT_PROPERTY(eCColorSrcSampler, m_eTexRepeatU, 0x48, 8)
GE_ASSERT_PROPERTY(eCColorSrcSampler, m_eTexRepeatV, 0x50, 8)
GE_ASSERT_PROPERTY(eCColorSrcSampler, m_fAnimationSpeed, 0x58, 4)
GE_ASSERT_PROPERTY(eCColorSrcSampler, m_eSwitchRepeat, 0x5c, 8)
