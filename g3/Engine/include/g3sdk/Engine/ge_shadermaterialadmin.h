#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_depthmap.h>
#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_gfxhlslshader.h>
#include <Engine/ge_gfxshared.h>
#include <Engine/ge_shaderbase.h>
#include <Engine/ge_shaderellementbase.h>
#include <Engine/ge_speedtreerenderbuffer.h>

#include <SharedBase.h>

class eCGfxCamera;
class eCGfxFog;
class eCGfxImageData;
class eCGfxVertexData;

template <typename T>
class bTSphericalHarmonics2;

class eCShaderMaterialAdmin;
class eCShaderConstantTable;
class eCShaderPoolEllement
{
  public:
    virtual ~eCShaderPoolEllement();

    eCShaderMaterialAdmin *m_pShaderMaterialAdmin;
    bCPropertyID m_DerviedFromShaderAndMaterialNameID;
    eCGfxHLSLShader *m_pShader;
    bCString m_strFileName;
    bCDateTime m_FileTime;
    GEU32 field_30;
    eCShaderConstantTable *m_pShaderConstantTable;
    GEU16 field_38;
};
GE_ASSERT_SIZEOF(eCShaderPoolEllement, 0x40)

class eCLookUpTextureBase
{
    GE_UNIMPL_STRUCT(eCLookUpTextureBase)
};

struct eSShaderRenderStates
{
    GE_UNIMPL_STRUCT(eSShaderRenderStates)
};

class GE_DLLIMPORT eCShaderMaterialAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCShaderMaterialAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: bEResult RestoreResources(GEBool) override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCShaderMaterialAdmin, eCEngineComponentBase)

  public:
    void AddSphericalHarmonics(bTSphericalHarmonics2<bCVector4> const &);
    GEBool BeginMaterial();
    GEBool BeginZPass(eCDepthMap *, GEBool);
    void ClearSphericalHarmonics();
    void CompileAllSystemDependencies(eCShaderBase *);
    void DeregisterShaderEllement(eCShaderEllementBase *);
    void EnableDepthBias(GEBool);
    void EnableErrorHandling(GEBool);
    void EnableFallback(GEBool);
    GEBool EndMaterial();
    GEBool EndZPass();
    eCShaderEllementConstant *FindGlobalConstant(eCGfxShared::eSGfxHLSLConstantDesc);
    void GetCurrentRenderStates(eSShaderRenderStates &) const;
    eEShaderMaterialVersion GetCurrentShaderVersion() const;
    eEDepthMapFormat GetDirectionalLightShadowMapFormat() const;
    GEFloat GetGlobalAlpha() const;
    eCGfxVertexData *GetHardwareInstancingVertexData();
    eEShaderMaterialInstancing GetInstancing() const;
    GEFloat GetLeafLoDSizeAdjustment() const;
    eCLookUpTextureBase *GetLookupTextureByName(bCString const &);
    GEInt GetMax4x3UserMatrixCount() const;
    GEInt GetMaxShaderInstances() const;
    eEShaderMaterialVersion GetMaxShaderVersion() const;
    eEShaderMaterialVersion GetMinShaderVersion() const;
    eEShaderMaterialOverwriteIndicator GetOverwriteIndicator() const;
    eEDepthMapFormat GetPointLightShadowMapFormat() const;
    eCShaderEllementBase *GetShaderEllement(bCGuid const &) const;
    GEInt GetShaderInstanceCount() const;
    eCShaderPoolEllement *GetShaderPoolEllement(bCPropertyID &, eEShaderMaterialVersion);
    eCGfxShared::eEGfxHLSLShaderVersion GetShaderVersionPS2X() const;
    eCGfxShared::eEGfxHLSLShaderVersion GetShaderVersionVS2X() const;
    GEU32 GetSystemDependencies() const;
    bCMatrix &GetUserMatrix(GEInt);
    bCMatrix const &GetUserMatrix(GEInt) const;
    GEInt GetUserMatrixCount() const;
    eEShaderMaterialSpecialPassType GetZPassType() const;
    void Invalidate();
    GEBool IsDepthBiasEnabled() const;
    GEBool IsErrorHandlingEnabled();
    GEBool IsFallbackEnabled();
    GEBool IsInExecution() const;
    GEBool IsInZPass() const;
    GEBool IsZWriteEnabled() const;
    void OnCameraChanged(eCGfxCamera *);
    void OnFogChanged(eCGfxFog *);
    void OnIsTimedChanged(eCShaderEllementBase *);
    void GE_STDCALL OnToggleIndicator(bCObjectRefBase *, bCEvent *);
    void OnWorldMatrixChanged(bCMatrix const &);
    void RegisterShaderEllement(eCShaderEllementBase *);
    bEResult SaveShaderPool();
    void SetCurrentRenderStates(eSShaderRenderStates const &) const;
    void SetCurrentShaderVersion(eEShaderMaterialVersion);
    void SetDepthImage(eCGfxImageData *);
    void SetDepthOutputOffset(bCVector2 const &);
    void SetGlobalAlpha(GEFloat);
    void SetLeafLoDSizeAdjustment(GEFloat);
    void SetLightmap(eCGfxImageData *);
    void SetOverwriteIndicator(eEShaderMaterialOverwriteIndicator);
    void SetRefractmap(eCGfxImageData *);
    void SetShaderInstanceCount(GEInt);
    void SetShaderInstanceGlobalAlpha(GEInt, GEFloat);
    void SetShaderInstanceMatrix(GEInt, bCMatrix const *);
    void SetShaderInstanceStaticLightData(GEInt, bCVector4 *);
    void SetSphericalHarmonics(bTSphericalHarmonics2<bCVector4> const &);
    void SetTerrainShadowMapData(bCVector2 const &, GEFloat);
    void SetUserMatrix(GEInt, bCMatrix const &);
    void SetUserMatrixCount(GEInt);
    void SetupShaderMacros(bTObjArray<eSShaderMaterialDeclaration> &);

  protected:
    eCShaderPoolEllement *CompilePreviewShaderPoolEllement(eCGfxShared::eSGfxHLSLShaderSrc const &);
    eCShaderPoolEllement *CompileShaderPoolEllement(eCGfxShared::eSGfxHLSLShaderSrc const &,
                                                    bTPtrMap<bCPropertyID, eCShaderPoolEllement *> &);
    eCShaderPoolEllement *CompileShaderPoolEllement(eCGfxShared::eSGfxHLSLShaderSrc const &, eEShaderMaterialVersion,
                                                    GEU32);
    bEResult ReadShaderPool(bCIStream &, bTPtrMap<bCPropertyID, eCShaderPoolEllement *> &,
                            bTObjMap<bCPropertyID, bCPropertyID> &, GEBool);
    bEResult WriteShaderPool(bCOStream &, bTPtrMap<bCPropertyID, eCShaderPoolEllement *> &,
                             bTObjMap<bCPropertyID, bCPropertyID> &);

  private:
    GE_UNIMPL_MEMBERS(2464)
};

GE_ASSERT_SIZEOF(eCShaderMaterialAdmin, 0x9b4)
