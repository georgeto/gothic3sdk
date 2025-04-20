#pragma once

#include <SharedBase.h>

class eCCollisionDesc;
class eCVisualAnimationLoD;
class eCVisualAnimation_PS;
class eCWrapper_emfx2Actor;
struct eSRayIntersectionDesc;

class GE_DLLIMPORT eCVisualAnimationFactory
{
  public:
    struct eSAdditionalBodyPart
    {
        bCString m_strName;
        eCVisualAnimationLoD *m_pVisAnimLoD;
        eCVisualAnimationLoD *m_pFacialAnimationLoD;
        GEBool m_bVisible;
    };

  public:
    eCVisualAnimationFactory(eCVisualAnimationFactory const &);
    eCVisualAnimationFactory();
    ~eCVisualAnimationFactory();

  public:
    GEBool AddBodyPart(bCString const &, eCVisualAnimation_PS *);
    void CacheInResources();
    void CacheOutResources();
    bEResult CopyFrom(eCVisualAnimationFactory const &);
    bEResult Create();
    GEBool CreateActorInstance();
    void Destroy();
    GEBool DestroyActorInstance();
    bTObjArray<eSAdditionalBodyPart> const &GetAdditionalBodyParts() const;
    eCWrapper_emfx2Actor *GetAssembledActor();
    eCWrapper_emfx2Actor const *GetAssembledActor() const;
    bCString const &GetFacialActorFileName() const;
    eCVisualAnimationLoD *GetFacialAnimationLoD();
    bCString const &GetMainActorFileName() const;
    void GetMeshBoundary(bCBox &) const;
    bTValArray<bCMatrix> const &GetRenderMatrices() const;
    GEU16 GetVersion() const;
    eCVisualAnimationLoD *GetVisualAnimationLoD();
    GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const;
    GEBool IsBodyPartVisible(bCString const &);
    GEBool IsFacialAnimationStarted() const;
    bEResult Read(bCIStream &);
    GEBool RemoveBodyPart(bCString const &);
    GEBool SetBodyPartVisible(bCString const &, GEBool);
    void SetFacialActorFileName(bCString const &);
    void SetMainActorFileName(bCString const &);
    GEBool StartFacialAnimation();
    GEBool StopFacialAnimation();
    GEBool UpdateRenderMatrices(GEU32, bCMatrix const &);
    bEResult Write(bCOStream &);

  protected:
    eCVisualAnimationFactory const &operator=(eCVisualAnimationFactory const &);

  protected:
    void Invalidate();
    void RemoveNotUsedBones();

  public:
    GEU32 __UNK_0000;
    eCWrapper_emfx2Actor *m_pAssembledActor;
    eCVisualAnimationLoD *m_pVisualAnimationLoD;
    eCVisualAnimationLoD *m_pFacialAnimationLoD;
    bTObjArray<eSAdditionalBodyPart> m_arrAdditionalBodyParts;
    GEBool m_bIsFacialAnimationStarted;
    GE_PADDING(0x3)
    bTValArray<bCMatrix> m_arrRenderMatrices;
    GEUInt m_bLastRenderMatricesUpdateFrame;
};

GE_ASSERT_SIZEOF(eCVisualAnimationFactory, 0x30)
