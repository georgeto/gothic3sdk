#pragma once

#include <SharedBase.h>

class eCAnimation_BaseRenderActor;
class eCCollisionDesc;
class eCResourceAnimationActor_PS;
class eCResourceDataEntity;
class eCVisualAnimationFactory;
class eCWrapper_emfx2Actor;
struct eSRayIntersectionDesc;

class GE_DLLIMPORT eCVisualAnimationLoD : public bCObjectBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCVisualAnimationLoD() override;
    // clang-format on

  public:
    eCVisualAnimationLoD(eCVisualAnimationLoD const &);
    explicit eCVisualAnimationLoD(eCVisualAnimationFactory *);

  public:
    eCResourceAnimationActor_PS *GetActor();
    bCString const &GetActorFileName() const;
    eCWrapper_emfx2Actor const *GetActorWrapper() const;
    eCVisualAnimationFactory *GetAnimationFactory();
    eCVisualAnimationFactory const *GetAnimationFactory() const;
    eCAnimation_BaseRenderActor *GetAnimationRenderHook();
    bTValArray<GEInt> const &GetHardBufferBoneMap() const;
    GEInt GetMaterialSwitch() const;
    void GetMeshBoundary(bCBox &) const;
    GEBool HasMeshData() const;
    GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const;
    GEBool ReleaseResources();
    GEBool RequestResources();
    GEBool SetActorFileName(bCString const &);
    void SetAnimationRenderHook(eCAnimation_BaseRenderActor *);
    void SetMaterialSwitch(GEInt);

  protected:
    eCVisualAnimationLoD const &operator=(eCVisualAnimationLoD const &);

  protected:
    void Invalidate();
    GEBool SetActor(eCResourceDataEntity *);

  public:
    bCString m_strActorFileName;
    eCResourceAnimationActor_PS *m_pActor;
    eCAnimation_BaseRenderActor *m_pAnimationRenderHook;
    GEBool m_bHasMeshData;
    GE_PADDING(0x3)
    bTValArray<GEInt> m_HardBufferBoneMap;
    eCVisualAnimationFactory *m_pVisAnimFactory;
    GEInt m_iMaterialSwitch;
    GEU32 __UNK_0028;
};

GE_ASSERT_SIZEOF(eCVisualAnimationLoD, 0x2c)
