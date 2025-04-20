#pragma once

#include <Engine/ge_colorsrcbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCColorSrcSkydomeSampler : public eCColorSrcBase
{
    // clang-format off
    public: virtual GEBool Prefetch();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCColorSrcSkydomeSampler() override;
    protected: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: void BeforeCompileShader() override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool GetImplementation(bCString &, eEShaderColorSrcComponent, GEBool) override;
    // clang-format on

  public:
    using eCShaderEllementBase::Prefetch;

  public:
    GE_PROPERTY_SET(eCColorSrcSkydomeSampler, eCColorSrcBase)
    GE_PROPERTY(GEFloat, UpdateRateInSec, m_fUpdateRateInSec)
    GE_PROPERTY(GEInt, MinSize, m_iMinSize)

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(88)
};

GE_ASSERT_SIZEOF(eCColorSrcSkydomeSampler, 0xa4)

GE_ASSERT_PROPERTY(eCColorSrcSkydomeSampler, m_fUpdateRateInSec, 0x44, 4)
GE_ASSERT_PROPERTY(eCColorSrcSkydomeSampler, m_iMinSize, 0x48, 4)
