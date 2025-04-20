#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/ge_entitypropertyset.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCStrip_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCStrip_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    public: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    public: GEBool HasRenderAlphaComponent() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void OnRender(GEI16) override;
    public: void OnRenderAlpha(GEI16) override;
    public: void OnUpdatedWorldMatrix() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCStrip_PS, eCEntityPropertySet)
    GE_PROPERTY(bCFloatColor, StartColor, m_colStart)
    GE_PROPERTY(GEFloat, StartAlpha, m_fAlphaStart)
    GE_PROPERTY(bCFloatColor, EndColor, m_colEnd)
    GE_PROPERTY(GEFloat, EndAlpha, m_fAlphaEnd)
    GE_PROPERTY(bCVector, OffsetLeft, m_vecOffsetLeft)
    GE_PROPERTY(bCVector, OffsetRight, m_vecOffsetRight)
    GE_PROPERTY(GEFloat, SegmentsPerSecond, m_fSegmentsPerSecond)
    GE_PROPERTY(GEFloat, SegmentLifeTime, m_fSegmentLifeTime)
    GE_PROPERTY(GEInt, MaxSegmentCount, m_iMaxSegmentCount)
    GE_ENUMPROP(eEStripSpawning, SpawnMode, m_enuSpawning)
    GE_ENUMPROP(eEFinalBlend, FinalBlend, m_enuFinalBlend)
    GE_PROPERTY(bCString, Texture, m_strTexture)
    GE_PROPERTY(GEBool, Enabled, m_bEnabled)
    GE_PADDING(1)

  public:
    void OnDeviceReset();

  protected:
    void ApplyFinalBlend();
    void CalculateExtents(bCBox &);
    GEBool CreateImage();
    GEBool CreateVertices();
    GEBool CreateVisual();
    void Initialize();
    void Invalidate();
    void OnCapacityChanged();
    void OnProcess(GEFloat, bCMatrix const &);
    void OnTextureChanged();
    void OnTransform(bCMatrix const &);
    void PushSegment(bCMatrix const &);
    void RenderInternal();
    void RenderVertices();
    void Reset();
    GEBool UpdateVertices();

  private:
    GE_UNIMPL_MEMBERS(40)
};

GE_ASSERT_SIZEOF(eCStrip_PS, 0xa0)

GE_ASSERT_PROPERTY(eCStrip_PS, m_colStart, 0x14, 16)
GE_ASSERT_PROPERTY(eCStrip_PS, m_fAlphaStart, 0x24, 4)
GE_ASSERT_PROPERTY(eCStrip_PS, m_colEnd, 0x28, 16)
GE_ASSERT_PROPERTY(eCStrip_PS, m_fAlphaEnd, 0x38, 4)
GE_ASSERT_PROPERTY(eCStrip_PS, m_vecOffsetLeft, 0x3c, 12)
GE_ASSERT_PROPERTY(eCStrip_PS, m_vecOffsetRight, 0x48, 12)
GE_ASSERT_PROPERTY(eCStrip_PS, m_fSegmentsPerSecond, 0x54, 4)
GE_ASSERT_PROPERTY(eCStrip_PS, m_fSegmentLifeTime, 0x58, 4)
GE_ASSERT_PROPERTY(eCStrip_PS, m_iMaxSegmentCount, 0x5c, 4)
GE_ASSERT_PROPERTY(eCStrip_PS, m_enuSpawning, 0x60, 8)
GE_ASSERT_PROPERTY(eCStrip_PS, m_enuFinalBlend, 0x68, 8)
GE_ASSERT_PROPERTY(eCStrip_PS, m_strTexture, 0x70, 4)
GE_ASSERT_PROPERTY(eCStrip_PS, m_bEnabled, 0x74, 1)
