#pragma once

#include <Engine/ge_colorsrcbase.h>
#include <Engine/ge_stringwrapper.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCColorSrcCubeSampler : public eCColorSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCColorSrcCubeSampler() override;
    protected: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: void BeforeCompileShader() override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool Prefetch(GEBool, GEInt) override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: GEBool GetImplementation(bCString &, eEShaderColorSrcComponent, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCColorSrcCubeSampler, eCColorSrcBase)
    GE_PROPERTY(bCImageResourceString, ImageFilePath, m_strImageFilePath)

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(56)
};

GE_ASSERT_SIZEOF(eCColorSrcCubeSampler, 0x80)

GE_ASSERT_PROPERTY(eCColorSrcCubeSampler, m_strImageFilePath, 0x44, 4)
