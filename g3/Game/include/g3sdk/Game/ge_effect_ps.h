#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCEffect_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCEffect_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void OnEnterProcessingRange() override;
    public: void OnExitProcessingRange() override;
    public: GEBool IsAutoKillEnabled() const override;
    public: void Decay() override;
    public: void GetOnScreenDebugLines(GEU32, bTObjArray<eSPropertySetDebugLine> &) const override;
    public: void OnCacheOut() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffect_PS, eCEntityPropertySet)
    GE_PROPERTY(bCString, Effect, m_strEffect)
    GE_PROPERTY(bCVector, Offset, m_vecOffset)
    GE_PROPERTY(GEFloat, Probability, m_fProbability)
    GE_PROPERTY(GEBool, Static, m_bStatic)
    GE_PADDING(1)

  public:
    GEBool IsRuntimeEffectStarted(bCString const &);
    GEBool StartEffect(bCString const &, GEBool);
    GEBool StartRuntimeEffect(bCString const &, bCVector *);
    GEBool StopAllRuntimeEffects(GEBool);
    GEBool StopRuntimeEffect(bCString const &, GEBool);

  protected:
    void CreateEffect();
    void DestroyEffect(GEBool);
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(20)
};

GE_ASSERT_SIZEOF(gCEffect_PS, 0x40)

GE_ASSERT_PROPERTY(gCEffect_PS, m_strEffect, 0x14, 4)
GE_ASSERT_PROPERTY(gCEffect_PS, m_vecOffset, 0x18, 12)
GE_ASSERT_PROPERTY(gCEffect_PS, m_fProbability, 0x24, 4)
GE_ASSERT_PROPERTY(gCEffect_PS, m_bStatic, 0x28, 1)
