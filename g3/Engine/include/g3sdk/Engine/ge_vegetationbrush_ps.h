#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_vegetation_gridnode.h>

#include <SharedBase.h>

class eCVegetation_PS;

class GE_DLLIMPORT eCVegetationBrush_PS : public eCEntityPropertySet
{
  public:
    struct eSBrushEntry
    {
        GE_UNIMPL_STRUCT(eSBrushEntry)
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCVegetationBrush_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    public: GEBool IsEditorRelevant() const override;
    protected: void OnRender(GEI16) override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCVegetationBrush_PS, eCEntityPropertySet)
    GE_ENUMPROP(eEVegetationBrushMode, Mode, m_eBrushMode)
    GE_ENUMPROP(eEVegetationBrushShape, Shape, m_eBrushShape)
    GE_ENUMPROP(eEVegetationBrushPlace, Placement, m_eBrushPlacement)
    GE_PROPERTY(GEFloat, Size, m_fSize)
    GE_PROPERTY(GEFloat, Density, m_fDensity)
    GE_PROPERTY(GEFloat, Variation, m_fVariation)
    GE_PROPERTY(GEBool, UniformDistribution, m_bUniformDistribution)
    GE_PADDING(3)
    GE_ENUMPROP(eEVegetationBrushProbabilityFunction, ProbabilityFunction, m_eProbabilityFunction)
    GE_PROPERTY(GEInt, ProbabilityNoiseOctaves, m_iProbabilityNoiseOctaves)
    GE_PROPERTY(GEFloat, ProbabilityNoiseScale, m_fProbabilityNoiseScale)
    GE_PROPERTY(bCVector2, ProbabilityNoiseModify, m_vecProbabilityNoiseModify)
    GE_ENUMPROP(bENoiseTurbulence, ProbabilityNoiseTurbulence, m_eProbabilityNoiseTurbulence)
    GE_PROPERTY(bCVector2, MinScaling, m_fMinScaling)
    GE_PROPERTY(bCVector2, MaxScaling, m_fMaxScaling)
    GE_PROPERTY(GEBool, AlignRotation, m_bAlignRotation)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, RandomRotation, m_fRandomRotation)
    GE_PROPERTY(bCFloatColor, ColorSalt, m_colSalt)
    GE_PROPERTY(bCFloatColor, ColorPepper, m_colPepper)
    GE_ENUMPROP(eEVegetationBrushColorFunction, ColorFunction, m_eColorFunction)
    GE_PROPERTY(GEInt, ColorNoiseOctaves, m_iColorNoiseOctaves)
    GE_PROPERTY(GEFloat, ColorNoiseScale, m_fColorNoiseScale)
    GE_PROPERTY(bCVector2, ColorNoiseModify, m_vecColorNoiseModify)
    GE_ENUMPROP(bENoiseTurbulence, ColorNoiseTurbulence, m_eColorNoiseTurbulence)

  public:
    void CalcColorAt(bCFloatColor &, bCNoise const *, GEFloat, GEFloat);
    void CalcColorDistribution(bTValArray<eSBrushEntry> &);
    void CalcDistribution(bTValArray<eSBrushEntry> &);
    eSVegetationMeshID CalcMeshDistribution(bCVector2 const &);
    GEFloat CalcProbabilityAt(bCNoise const *, GEFloat, GEFloat);
    void Enable(GEBool);
    bCNoise const *GetColorNoise() const;
    eCVegetation_PS *GetCurrentVegetationPS() const;
    bCNoise const *GetProbabilityNoise() const;
    bTObjArray<eSVegetationMeshID> &GetVegetationIDs();
    GEBool IsEnabled() const;
    void ReviseDistribution(bTValArray<eSBrushEntry> &);
    void SetCurrentVegetationPS(eCVegetation_PS *);
    void SetSeed(GEInt);

  protected:
    void FindWorldPosAndNormal(bTValArray<eSBrushEntry> &);
    void InsertEntries(bTValArray<eSBrushEntry> &);
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(120)
};

GE_ASSERT_SIZEOF(eCVegetationBrush_PS, 0x12c)

GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_eBrushMode, 0x14, 8)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_eBrushShape, 0x1c, 8)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_eBrushPlacement, 0x24, 8)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_fSize, 0x2c, 4)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_fDensity, 0x30, 4)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_fVariation, 0x34, 4)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_bUniformDistribution, 0x38, 1)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_eProbabilityFunction, 0x3c, 8)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_iProbabilityNoiseOctaves, 0x44, 4)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_fProbabilityNoiseScale, 0x48, 4)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_vecProbabilityNoiseModify, 0x4c, 8)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_eProbabilityNoiseTurbulence, 0x54, 8)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_fMinScaling, 0x5c, 8)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_fMaxScaling, 0x64, 8)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_bAlignRotation, 0x6c, 1)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_fRandomRotation, 0x70, 4)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_colSalt, 0x74, 16)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_colPepper, 0x84, 16)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_eColorFunction, 0x94, 8)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_iColorNoiseOctaves, 0x9c, 4)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_fColorNoiseScale, 0xa0, 4)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_vecColorNoiseModify, 0xa4, 8)
GE_ASSERT_PROPERTY(eCVegetationBrush_PS, m_eColorNoiseTurbulence, 0xac, 8)
