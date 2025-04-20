#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_gfxshared.h>
#include <Engine/ge_shaderellementbase.h>
#include <Engine/ge_stringwrapper.h>

#include <SharedBase.h>

class eCGfxImageData;
class eCTerrainShadowMap;

struct eSShaderMaterialPass
{
    GE_UNIMPL_STRUCT(eSShaderMaterialPass)
};

enum eEShaderMaterialLightmapCombi
{
    // TODO: Enumerator values
};

enum eEShaderMaterialOverwriteIndicator
{
    // TODO: Enumerator values
};

enum eEShaderMaterialSpecialPassType
{
    // TODO: Enumerator values
};

class eCShaderVersionBase
{
    GE_UNIMPL_STRUCT(eCShaderVersionBase)
};

struct eSShaderMaterialIllumination
{
    GE_UNIMPL_STRUCT(eSShaderMaterialIllumination)
};

class GE_DLLIMPORT eCShaderBase : public eCShaderEllementBase
{
    // clang-format off
    public: virtual GEBool SupportsInstancing() const;
    public: virtual GEBool Prefetch(GEInt);
    protected: virtual GEBool DestroyShaderVersion(eEShaderMaterialVersion);
    protected: virtual GEBool CreateShaderVersion(eEShaderMaterialVersion);
    public: virtual GEBool HasOpacity() const;
    public: virtual GEBool IsBlended() const;
    public: virtual GEBool IsMasked() const;
    public: virtual GEBool IsRefracted() const;
    public: virtual GEInt GetPasses(GEU8, eSShaderMaterialIllumination *, eEShaderMaterialLightmapCombi, eCTerrainShadowMap *, GEBool);
    public: virtual GEBool ExecutePass(GEInt, eCGfxImageData *, GEInt);
    public: virtual GEBool ExecuteZPass();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCShaderBase() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: void SetSwitch(GEInt) override;
    public: void GetUniqueConstantDeclerations(bTObjArray<bCString> &, bTObjMap<bCString, GEInt> &) override;
    public: void BeforeCompileShader() override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCShaderBase, eCShaderEllementBase)
    GE_ENUMPROP(eEShaderMaterialBlendMode, BlendMode, m_eBlendMode)
    GE_PROPERTY(GEU8, MaskReference, m_u8MaskReference)
    GE_PADDING(3)
    GE_ENUMPROP(eEShaderMaterialVersion, MaxShaderVersion, m_eMaxShaderVersion)
    GE_PROPERTY(bCImageOrMaterialResourceString, FallbackMaterial, m_strFallbackMaterial)
    GE_PROPERTY(GEBool, UseDepthBias, m_bUseDepthBias)
    GE_PADDING(1)

  public:
    GEBool AddEllement(eCShaderEllementBase *);
    GEBool AddSwitchEllement(eCShaderEllementBase *);
    void AutoArangeLayout();
    void ClearConstantTables();
    GEBool CompileAll(GEBool);
    GEBool CompileSpecialPass(eEShaderMaterialVersion, eEShaderMaterialSpecialPassType);
    GEBool CompileVersion(eEShaderMaterialVersion, GEBool);
    eCShaderEllementConstant *FindShaderEllementConstant(eCGfxShared::eSGfxHLSLConstantDesc);
    eCShaderEllementBase *GetShaderEllement(GEInt) const;
    GEInt GetShaderEllementCount() const;
    bCString const &GetShaderFile() const;
    eCShaderVersionBase *GetShaderVersion(eEShaderMaterialVersion) const;
    GEBool RemoveEllement(eCShaderEllementBase *);
    GEBool RemoveSwitchEllement(eCShaderEllementBase *);
    void SetIndicatorRenderStates(eEShaderMaterialOverwriteIndicator) const;
    void SetShaderRenderStates(GEBool) const;
    void SetupShaderMacros(bCString const &, bTValArray<eCGfxShared::eSGfxEffectMacro> &,
                           bTObjArray<eSShaderMaterialDeclaration> &, bTObjArray<bCString> &, GEBool);

  protected:
    static bTValArray<eSShaderMaterialPass> ms_arrShaderPasses;

  protected:
    GEInt AutoArangeEllement(eCShaderEllementBase *, GEInt, GEInt);
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(96)
};

GE_ASSERT_SIZEOF(eCShaderBase, 0xc0)

GE_ASSERT_PROPERTY(eCShaderBase, m_eBlendMode, 0x44, 8)
GE_ASSERT_PROPERTY(eCShaderBase, m_u8MaskReference, 0x4c, 1)
GE_ASSERT_PROPERTY(eCShaderBase, m_eMaxShaderVersion, 0x50, 8)
GE_ASSERT_PROPERTY(eCShaderBase, m_strFallbackMaterial, 0x58, 4)
GE_ASSERT_PROPERTY(eCShaderBase, m_bUseDepthBias, 0x5c, 1)
