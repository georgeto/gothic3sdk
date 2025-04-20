#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/collision/ge_collisionshapebase_ps.h>
#include <Engine/ge_refptrarray.h>

#include <SharedBase.h>

class NxShape;

class GE_DLLIMPORT eCCollisionShape_PS : public eCCollisionShapeBase_PS
{
    // clang-format off
    public: virtual bEResult SetShape(bCString const &, GEBool);
    public: virtual bEResult AddShape(bCString const &, GEBool);
    public: virtual bEResult AddShape(eECollisionShapeType, eEShapeGroup, bCVector const &, bCVector const &);
    public: virtual bEResult AddDynamicShape(eECollisionShapeType, eEShapeGroup, eEShapeAABBAdapt, GEFloat);
    public: virtual bEResult AddPointShape(eEShapeGroup, bCVector const &);
    public: virtual NxShape * GetProprietaryShapeAtIndex(GEU32) const;
    public: virtual void RemoveShapes();
    public: virtual void RemoveShapes(eEShapeGroup);
    public: virtual void RemoveShapes(eECollisionShapeType);
    public: virtual void RemoveShape(eCCollisionShape *);
    public: virtual void RemoveShapeAt(GEInt);
    protected: virtual void EnableShapeGroupCollisionInternal(eEShapeGroup, GEBool, GEInt);
    protected: virtual void SetShapeGroupInternal(eEShapeGroup, eEShapeGroup);
    protected: virtual void RemoveShapesInternal();
    protected: virtual void RemoveShapesInternal(eEShapeGroup);
    protected: virtual void RemoveShapesInternal(eECollisionShapeType);
    protected: virtual void RemoveShapesInternal(NxShape *);
    public: virtual void OnPreTouch(eCEntity *, eCContactIterator &);
    public: virtual void OnPreUntouch(eCEntity *, eCContactIterator &);
    public: virtual void OnPostTouch(eCEntity *, eCContactIterator &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCCollisionShape_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: GEBool IsPhysicRelevant() const override;
    public: GEBool IsEditorRelevant() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    protected: void OnExitProcessingRange() override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void OnUpdatedWorldTreeBoundary() override;
    protected: void OnCacheIn() override;
    protected: void OnCacheOut() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnPostRead() override;
    public: bEResult SetShape(eCCollisionShape *) override;
    public: bEResult AddShape(eCCollisionShape *) override;
    public: GEU32 GetNumShapes() const override;
    public: eCCollisionShape * GetShapeAtIndex(GEU32) const override;
    // clang-format on

  public:
    using eCCollisionShapeBase_PS::AddShape;
    using eCCollisionShapeBase_PS::SetShape;

  public:
    GE_PROPERTY_SET(eCCollisionShape_PS, eCCollisionShapeBase_PS)
    GE_ENUMPROP(eECollisionGroup, Group, m_enuGroup)
    GE_ENUMPROP(eEPhysicRangeType, Range, m_enuRange)
    GE_PROPERTY(GEBool, DisableCollision, m_bDisableCollision)
    GE_PROPERTY(GEBool, DisableResponse, m_bDisableResponse)
    GE_PROPERTY(GEBool, IgnoredByTraceRay, m_bIgnoredByTraceRay)
    GE_PADDING(1)

  public:
    void ClearTouchingShapes();
    void EnableShapeGroupCollision(eEShapeGroup, GEBool, GEInt);
    GEU32 GetNumTouchingShapes() const;
    NxShape *GetProprietaryTouchingShape(GEU32) const;
    bTRefPtrArray<eCCollisionShape *> &GetShapes();
    bTRefPtrArray<eCCollisionShape *> const &GetShapes() const;
    eEPropertySetType GetTouchType() const;
    bCString const &GetTouchingBone() const;
    eCCollisionShape *GetTouchingShapeAtIndex(GEU32) const;
    GEBool const HasConvexMesh() const;
    GEBool const HasGroup(eEShapeGroup) const;
    GEBool const HasScalableMesh() const;
    GEBool const HasTriangleMesh() const;
    void SetShapeGroup(eEShapeGroup, eEShapeGroup);
    void SetShapes(bTRefPtrArray<eCCollisionShape *> const &);
    GEBool TraceRayFirstHit(bCRay &);

  protected:
    void Invalidate();
    void OnProprietaryShapesChanged();
    void SetProprietaryShapes();
    void ShrinkTouchingShapes();

  private:
    GE_UNIMPL_MEMBERS(36)
};

GE_ASSERT_SIZEOF(eCCollisionShape_PS, 0x4c)

GE_ASSERT_PROPERTY(eCCollisionShape_PS, m_enuGroup, 0x14, 8)
GE_ASSERT_PROPERTY(eCCollisionShape_PS, m_enuRange, 0x1c, 8)
GE_ASSERT_PROPERTY(eCCollisionShape_PS, m_bDisableCollision, 0x24, 1)
GE_ASSERT_PROPERTY(eCCollisionShape_PS, m_bDisableResponse, 0x25, 1)
GE_ASSERT_PROPERTY(eCCollisionShape_PS, m_bIgnoredByTraceRay, 0x26, 1)
