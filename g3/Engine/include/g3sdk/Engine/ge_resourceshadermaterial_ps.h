#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCResourceMaterialObject_PS;
class eCShaderBase;

class GE_DLLIMPORT eCResourceShaderMaterial_PS : public eCResourceBase_PS
{
    // clang-format off
    public: virtual GEBool IsMapChannelUsed(GEInt, GEBool) const;
    public: virtual GEBool IsDiffuseColorUsed(GEBool) const;
    public: virtual bEResult ConvertFrom(eCResourceMaterialObject_PS *);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceShaderMaterial_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    protected: void CalculateSize() override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceShaderMaterial_PS, eCResourceBase_PS)
    GE_ENUMPROP(eEShapeMaterial, PhysicMaterial, m_enuPhysicMaterial)
    GE_PROPERTY(GEBool, IgnoredByTraceRay, m_bIgnoredByTraceRay)
    GE_PROPERTY(GEBool, DisableCollision, m_bDisableCollision)
    GE_PROPERTY(GEBool, DisableResponse, m_bDisableResponse)
    GE_PADDING(1)

  public:
    static void GE_STDCALL GetProprietaryFileExt(bCString &);
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    eCShaderBase *GetShader() const;
    GEBool IsAlphaTested() const;
    GEBool IsBlended() const;
    GEBool IsRefracted() const;
    void SetShader(eCShaderBase *);

  protected:
    void DeleteResources();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(eCResourceShaderMaterial_PS, 0x3c)

GE_ASSERT_PROPERTY(eCResourceShaderMaterial_PS, m_enuPhysicMaterial, 0x2c, 8)
GE_ASSERT_PROPERTY(eCResourceShaderMaterial_PS, m_bIgnoredByTraceRay, 0x34, 1)
GE_ASSERT_PROPERTY(eCResourceShaderMaterial_PS, m_bDisableCollision, 0x35, 1)
GE_ASSERT_PROPERTY(eCResourceShaderMaterial_PS, m_bDisableResponse, 0x36, 1)
