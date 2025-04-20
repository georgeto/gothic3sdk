#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCWaterZone_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCWaterZone_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    protected: void OnTouch(eCEntity *, eCContactIterator &) override;
    protected: void OnIntersect(eCEntity *, eCContactIterator &) override;
    protected: void OnUntouch(eCEntity *, eCContactIterator &) override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnPostRead() override;
    public: void OnPropertySetAdded() override;
    public: void OnPropertySetRemoved() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCWaterZone_PS, eCEntityPropertySet)
    GE_PROPERTY(bCVector, FaceNormal, m_vecFaceNormal)
    GE_PROPERTY(bTValArray<bCVector>, CoveringPoint, m_arrCoveringPoint)
    GE_PROPERTY(GEFloat, SquareRadius, m_fSquareRadius)
    GE_PROPERTY(bCVector, RadiusOffset, m_vecRadiusOffset)
    GE_PROPERTY(GEFloat, MinX, m_fMinX)
    GE_PROPERTY(GEFloat, MaxX, m_fMaxX)
    GE_PROPERTY(GEFloat, MinZ, m_fMinZ)
    GE_PROPERTY(GEFloat, MaxZ, m_fMaxZ)

  public:
    bEResult FillProperties(bTValArray<bCVector> const &);
    GEFloat GetRadius();
    GEFloat GetUnderWaterDepth(bCVector const &);
    GEBool Test3DPointInCoveringZone(bCVector const &);
    GEBool Test3DPointInWaterAABBox(bCVector const &);
    GEBool Test3DPointInWaterRadius(bCVector const &);
    GEBool Test3DPointUnderWaterMesh(bCVector const &);

  protected:
    void FillCoveringPoint(bTValArray<bCVector> const &);
    void GameReset();
    void Invalidate();
    void QuickHull(bCVector const &, bCVector const &, bTValArray<bCVector> const &, bTValArray<bCStretch> &);

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(gCWaterZone_PS, 0x58)

GE_ASSERT_PROPERTY(gCWaterZone_PS, m_vecFaceNormal, 0x14, 12)
GE_ASSERT_PROPERTY(gCWaterZone_PS, m_arrCoveringPoint, 0x20, 12)
GE_ASSERT_PROPERTY(gCWaterZone_PS, m_fSquareRadius, 0x2c, 4)
GE_ASSERT_PROPERTY(gCWaterZone_PS, m_vecRadiusOffset, 0x30, 12)
GE_ASSERT_PROPERTY(gCWaterZone_PS, m_fMinX, 0x3c, 4)
GE_ASSERT_PROPERTY(gCWaterZone_PS, m_fMaxX, 0x40, 4)
GE_ASSERT_PROPERTY(gCWaterZone_PS, m_fMinZ, 0x44, 4)
GE_ASSERT_PROPERTY(gCWaterZone_PS, m_fMaxZ, 0x48, 4)
