#pragma once

#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_illuminationadmin.h>

#include <SharedBase.h>

class eCGfxImageData;
class eCGfxVisual;
class eCResourceMaterialObjectExtended_PS;
class eCResourceMaterialObject_PS;

class GE_DLLIMPORT eCMaterialAdmin : public eCEngineComponentBase
{
  public:
    enum eEAvSIndicator
    {
        // TODO: Enumerator values
    };

    enum eEIndicatorStatus
    {
        // TODO: Enumerator values
    };

    enum eELODIndicator
    {
        // TODO: Enumerator values
    };

    enum eELightingType
    {
        // TODO: Enumerator values
    };

    enum eEMaterialMode
    {
        // TODO: Enumerator values
    };

    enum eEPerfIndicator
    {
        // TODO: Enumerator values
    };

    enum eEQualIndicator
    {
        // TODO: Enumerator values
    };

    enum eETransformAniType
    {
        // TODO: Enumerator values
    };

    struct eSDefaultFXDescription
    {
        GE_UNIMPL_STRUCT(eSDefaultFXDescription)
    };

    struct eSDescShadowMapRendering
    {
        GE_UNIMPL_STRUCT(eSDescShadowMapRendering)
    };

    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCMaterialAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: bEResult RestoreResources(GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCMaterialAdmin, eCEngineComponentBase)

  public:
    bEResult ActivateAlphaVSolidIndicator(eEIndicatorStatus);
    bEResult ActivateAmbientOcclusionIndicator(eEIndicatorStatus);
    bEResult ActivateColorMappingIndicator(GEBool);
    bEResult ActivateDepthBufferFillMaterial(GEBool);
    bEResult ActivateLODIndicator(eEIndicatorStatus);
    bEResult ActivateObjectOverdrawIndicator(GEBool);
    bEResult ActivatePerformanceIndicator(eEIndicatorStatus);
    bEResult ActivatePixelOverdrawIndicator(GEBool);
    bEResult ActivateQualityIndicator(eEIndicatorStatus);
    bEResult ActivateSolidPlusWireframe(GEBool);
    bEResult ActivateUntexturedIndicator(GEBool);
    void BeginFX();
    void BlockPoolEffectLoading(GEBool, GEBool, GEBool, GEBool, GEBool, GEBool, GEBool, GEBool, GEBool);
    bEResult EnableSkydome(GEBool);
    void EndFX();
    bEResult ExecuteDefaultFX(eSDefaultFXDescription &);
    GEInt ExecutePoolFX(GEInt, eCGfxVisual *, eCResourceMaterialObject_PS *, eCResourceMaterialObjectExtended_PS *,
                        eEMaterialMode, eETransformAniType, eCGfxImageData *, eCIlluminationAdmin::eSIllumination *);
    eEIndicatorStatus GetAlphaVSolidIndicatorStatus() const;
    eEIndicatorStatus GetAmbientOcclusionIndicatorStatus() const;
    GEFloat GetGlobalMaterialAlpha();
    eEIndicatorStatus GetLODIndicatorStatus() const;
    eELightingType GetLightingType() const;
    GEInt GetMax4x3UserMatrixCount() const;
    GEInt GetMax4x4UserMatrixCount() const;
    eEIndicatorStatus GetPerformanceIndicatorStatus() const;
    eEIndicatorStatus GetQualityIndicatorStatus() const;
    eSDescShadowMapRendering const &GetShadowMapRendering() const;
    GEBool GetShadowMapRendering(eSDescShadowMapRendering &) const;
    GEBool GetSolidPlusWireFrameIndicatorStatus() const;
    GEBool GetToggleState_AvSObjectOverdraw() const;
    GEBool GetToggleState_AvSPixelOverdraw() const;
    GEBool GetToggleState_AvSSolid() const;
    GEBool GetToggleState_ColorMapping() const;
    GEBool GetToggleState_ObjectOverdraw() const;
    GEBool GetToggleState_PerfObjectOverdraw() const;
    GEBool GetToggleState_PerfPixelOverdraw() const;
    GEBool GetToggleState_PerfSolid() const;
    GEBool GetToggleState_PixelOverdraw() const;
    GEBool GetToggleState_SolidPlusWireframe() const;
    GEBool GetToggleState_Untexture() const;
    GEInt GetUserMatixCount() const;
    bCMatrix const *GetUserMatrices() const;
    void Invalidate();
    GEBool IsColorMappingEnabled() const;
    GEBool IsSkydomeEffectLoaded();
    GEBool IsSkydomeEnabled() const;
    void GE_STDCALL OnToggleAvSObjectOverdraw(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleAvSPixelOverdraw(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleAvSSolid(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleColorMapping(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleObjectOverdraw(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnTogglePerfObjectOverdraw(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnTogglePerfPixelOverdraw(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnTogglePerfSolid(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnTogglePixelOverdraw(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleSolid(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleSolidPlusWireframe(bCObjectRefBase *, bCEvent *);
    bEResult RunAlphaVSolidIndicator(eEAvSIndicator, eCGfxVisual *);
    bEResult RunAmbientOcclusionIndicator(eCGfxVisual *);
    bEResult RunLODIndicator(eELODIndicator, eCGfxVisual *);
    bEResult RunPerformanceIndicator(eEPerfIndicator, eCGfxVisual *);
    bEResult RunQualityIndicator(eEQualIndicator, eCGfxVisual *);
    bEResult SetFullLighting(GEBool);
    void SetGlobalMaterialAlpha(GEFloat);
    bEResult SetLightingType(eELightingType);
    bEResult SetLoadingResMaterial(eCGfxVisual *);
    GEBool SetShadowMapRendering(eSDescShadowMapRendering const &);
    void SetUserMatix(GEInt, bCMatrix const &);
    void SetUserMatixCount(GEInt);
    bEResult SetXimgMissingMaterial(eCGfxVisual *);
    bEResult SetXmatMissingMaterial(eCGfxVisual *);

  private:
    GE_UNIMPL_MEMBERS(10828)
};

GE_ASSERT_SIZEOF(eCMaterialAdmin, 0x2a60)
