#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/proxy/ge_templateentityproxy.h>

#include <SharedBase.h>

class NxShape;
class eCEntity;

class GE_DLLIMPORT eCCollisionShape : public bCObjectRefBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCCollisionShape() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCCollisionShape, bCObjectRefBase)
    GE_ENUMPROP(eECollisionShapeType, ShapeType, m_eType) // Read only
    GE_ENUMPROP(eEShapeGroup, Group, m_enuGroup)
    GE_ENUMPROP(eEShapeMaterial, Material, m_enuMaterial)
    GE_ENUMPROP(eEShapeAABBAdapt, ShapeAABBAdaptMode, m_enuShapeAABBAdapt)
    GE_PROPERTY(GEBool, IgnoredByTraceRay, m_bIgnoredByTraceRay)
    GE_PROPERTY(GEBool, EnableCCD, m_bEnableCCD)
    GE_PROPERTY(GEBool, OverrideEntityAABB, m_bOverrideEntityAABB)
    GE_PROPERTY(GEBool, DisableCollision, m_bDisableCollision)
    GE_PROPERTY(GEBool, DisableResponse, m_bDisableResponse)
    GE_PROPERTY(GEBool, TriggersOnTouch, m_bTriggersOnTouch)
    GE_PROPERTY(GEBool, TriggersOnUntouch, m_bTriggersOnUntouch)
    GE_PROPERTY(GEBool, TriggersOnIntersect, m_bTriggersOnIntersect)
    GE_PROPERTY(GEFloat, SkinWidth, m_fSkinWidth)
    GE_PROPERTY(GEBool, IsLazyGenerated, m_bIsLazyGenerated) // Read only
    GE_PADDING(1)
    GE_PROPERTY(GEU16, FileVersion, m_u16FileVersion) // Read only
    GE_PADDING(2)

  public:
    static bCString GE_STDCALL GetMaterialName(eEShapeMaterial);

  public:
    GEFloat &AccessAdaptScale();
    GEBool &AccessAdaptToAABB();
    GEFloat const &GetAdaptScale() const;
    GEBool const &GetAdaptToAABB() const;
    bCOrientedBox &GetBox();
    bCOrientedBox const &GetBox() const;
    bCCapsule &GetCapsule();
    bCCapsule const &GetCapsule() const;
    bCVector &GetCenter();
    bCVector const &GetCenter() const;
    void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &);
    GEFloat GetDepth();
    GEFloat const GetDepth() const;
    eCEntity *GetEntity() const;
    GEFloat GetHeight();
    GEFloat const GetHeight() const;
    GEBool GetIsCachedIn() const;
    bCVector &GetLastPosition();
    bCVector const &GetLastPosition() const;
    bCString &GetMeshResourceName();
    bCString const &GetMeshResourceName() const;
    bCMatrix3 &GetOrientation();
    bCMatrix3 const &GetOrientation() const;
    bCBox &GetOuterAABBLocal();
    bCBox const &GetOuterAABBLocal() const;
    bCVector &GetPoint();
    bCVector const &GetPoint() const;
    NxShape *GetProprietaryShape() const;
    GEU16 GetResourceIndex() const;
    bCMatrix3 &GetRuntimeOrientation();
    bCMatrix3 const &GetRuntimeOrientation() const;
    bCSphere &GetSphere();
    bCSphere const &GetSphere() const;
    GEFloat GetWidth();
    GEFloat const GetWidth() const;
    GEBool IntersectsRay(bCRay const &);
    GEBool IsTrigger() const;
    void SetAdaptScale(GEFloat const &);
    void SetAdaptToAABB(GEBool const &);
    bEResult SetByLocalAABB(bCBox const &);
    void SetCenter(bCVector const &);
    void SetDepth(GEFloat);
    void SetHeight(GEFloat);
    void SetIsCachedIn(GEBool);
    void SetLastPosition(bCVector const &);
    void SetMeshResourceName(bCString &);
    void SetOrientation(bCMatrix3 const &);
    void SetProprietaryShape(NxShape *);
    void SetRuntimeOrientation(bCMatrix3 const &);
    bEResult SetShape(eCCollisionShape const &);
    bEResult SetShape(bCCapsule const &);
    bEResult SetShape(bCOrientedBox const &);
    bEResult SetShape(bCSphere const &);
    bEResult SetShape(bCString const &, GEU16, GEBool);
    bEResult SetShape(bCVector const &);
    bEResult SetShapeAABBLocal(bCBox const &);
    void SetWidth(GEFloat);

  protected:
    void CalcShapeAABBLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(56)
};

GE_ASSERT_SIZEOF(eCCollisionShape, 0x78)

GE_ASSERT_PROPERTY(eCCollisionShape, m_eType, 0xc, 8)
GE_ASSERT_PROPERTY(eCCollisionShape, m_enuGroup, 0x14, 8)
GE_ASSERT_PROPERTY(eCCollisionShape, m_enuMaterial, 0x1c, 8)
GE_ASSERT_PROPERTY(eCCollisionShape, m_enuShapeAABBAdapt, 0x24, 8)
GE_ASSERT_PROPERTY(eCCollisionShape, m_bIgnoredByTraceRay, 0x2c, 1)
GE_ASSERT_PROPERTY(eCCollisionShape, m_bEnableCCD, 0x2d, 1)
GE_ASSERT_PROPERTY(eCCollisionShape, m_bOverrideEntityAABB, 0x2e, 1)
GE_ASSERT_PROPERTY(eCCollisionShape, m_bDisableCollision, 0x2f, 1)
GE_ASSERT_PROPERTY(eCCollisionShape, m_bDisableResponse, 0x30, 1)
GE_ASSERT_PROPERTY(eCCollisionShape, m_bTriggersOnTouch, 0x31, 1)
GE_ASSERT_PROPERTY(eCCollisionShape, m_bTriggersOnUntouch, 0x32, 1)
GE_ASSERT_PROPERTY(eCCollisionShape, m_bTriggersOnIntersect, 0x33, 1)
GE_ASSERT_PROPERTY(eCCollisionShape, m_fSkinWidth, 0x34, 4)
GE_ASSERT_PROPERTY(eCCollisionShape, m_bIsLazyGenerated, 0x38, 1)
GE_ASSERT_PROPERTY(eCCollisionShape, m_u16FileVersion, 0x3a, 2)
