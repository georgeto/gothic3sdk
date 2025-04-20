#pragma once

#include <Engine/animation/ge_animation_baserenderactor.h>
#include <Engine/ge_gfxindexdata.h>
#include <Engine/ge_gfxvertexdata.h>
#include <Engine/ge_gfxvisual.h>

#include <SharedBase.h>

class eCGfxVertexDecl;
class eCTerrainShadowMap;
class eCVisualAnimation_PS;
struct eSShaderMaterialIllumination;

class GE_DLLIMPORT eCAnimation_HardRenderActor : public eCAnimation_BaseRenderActor
{
  public:
    struct eSHardPrimitive
    {
        GE_UNIMPL_STRUCT(eSHardPrimitive)
    };

    // clang-format off
    public: virtual void Render(eCVisualAnimation_PS *, eCVisualAnimationLoD &, GEBool, GEBool);
    public: bEResult Create(eCResourceAnimationActor_PS *) override;
    protected: bEResult Create() override;
    public: void Destroy() override;
    public: GEBool RemoveFromList(eCVisualAnimationLoD &) override;
    public: void Prefetch(GEInt) override;
    public: ~eCAnimation_HardRenderActor() override;
    // clang-format on

  public:
    eCAnimation_HardRenderActor(eCAnimation_HardRenderActor const &);
    eCAnimation_HardRenderActor();

  public:
    eCAnimation_HardRenderActor &operator=(eCAnimation_HardRenderActor const &);

  public:
    bTValArray<GEInt> const &GetBoneIDMap() const;

  protected:
    static GEFloat ms_fMaxBoneLODDistance;
    static eCGfxVertexDecl *ms_pGfXVertexDeclaration;

  protected:
    GEBool CreateLoD(GEU16, GEU16 &, GEU16 &);
    void Invalidate();
    void RenderPrimitive(eSHardPrimitive const &, GEInt, eSShaderMaterialIllumination *, eCTerrainShadowMap *, GEInt);

  public:
    eCResourceAnimationActor_PS *m_pResourceAnimationActor;
    bTPtrArray<eCGfxVertexData *> m_arrVertexData;
    bTPtrArray<eCGfxIndexData *> m_arrIndexData;
    GE_UNIMPL_MEMBERS(0x10)
    bTValArray<GEInt> m_BoneIDMap;
    GE_UNIMPL_MEMBERS(0xc)
    eCGfxVisual *m_pGfxVisual;
};

GE_ASSERT_SIZEOF(eCAnimation_HardRenderActor, 0x50)
