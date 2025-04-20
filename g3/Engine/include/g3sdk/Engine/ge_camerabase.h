#pragma once

#include <SharedBase.h>

class eCEntity;
class eCFrustumDatabase;
class eCShadowMapBase;

enum eECamUpdate
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCCameraBase : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult Init(HWND, GEFloat, GEFloat, GEFloat);
    public: virtual bEResult Init(bCRect const &, GEFloat, GEFloat, GEFloat);
    public: virtual bEResult Create(GEBool, GEBool);
    public: virtual void UpdateViewport(GEBool);
    public: virtual void UpdateProjection(GEBool);
    public: GEU16 GetVersion() const override;
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: GEU32 AddReference() override;
    public: GEU32 ReleaseReference() override;
    public: ~eCCameraBase() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCCameraBase, bCObjectRefBase)
    GE_PROPERTY(bCMatrix, ViewMatrix, m_matView)
    GE_PROPERTY(bCMatrix, ProjectionMatrix, m_matProjection)
    GE_PROPERTY(bCVector, Position, m_vecPosition)
    GE_PROPERTY(bCVector, Rotation, m_vecRotation)
    GE_PROPERTY(bCVector, Scale, m_vecScale)
    GE_PROPERTY(bCVector2, ClipProjection, m_vecClipProjection)
    GE_PROPERTY(bCVector2, ClipDepth, m_vecClipDepth)
    GE_PROPERTY(bCRect, Screen, m_recScreen)
    GE_PROPERTY(GEFloat, FieldOfView, m_fFieldOfView)
    GE_PROPERTY(GEFloat, AspectRatio, m_fAspectRatio)
    GE_PROPERTY(GEBool, Perspective, m_bPerspective)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, DepthBias, m_fDepthBias)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void ExecuteGfxCamera();
    eCFrustumDatabase &GetFrustumDatabase();
    eCFrustumDatabase const &GetFrustumDatabase() const;
    eCFrustumDatabase &GetLowPolyFrustumDatabase();
    eCFrustumDatabase const &GetLowPolyFrustumDatabase() const;
    bCMatrix GetScreenToWorldMatrix() const;
    bCMatrix GetWorldToScreenMatrix() const;
    void GetZAxis(bCVector &) const;
    void GoToEntity(eCEntity const &);
    GEBool IsInLowPolyFrame() const;
    GEBool IsOrthogonal() const;
    void LookAt(bCVector const &);
    void Move(bCVector const &);
    void MoveForward(GEFloat, GEBool);
    void MoveHeight(GEFloat);
    void MoveLocal(bCVector const &);
    void MoveSideways(GEFloat);
    void PointToRay(bCPoint const &, bCRay &) const;
    void PointToRay(bCPoint const &, bCUnitedRay &) const;
    void RectToBox(bCRect const &, bCBox &) const;
    bCFrustum RectToFrustum(bCRect const &) const;
    void RectToFrustum(bCRect const &, bCFrustum &) const;
    void Render(GEBool, GEBool);
    void RenderEntity(eCEntity *, GEBool);
    void RenderLowPoly();
    void RenderShadowMap(GEBool, eCShadowMapBase *);
    void Roll(GEFloat);
    void RotateAngularAbs(bCVector const &);
    void RotateAngularRel(bCVector const &);
    void RotateHeigth(GEFloat);
    void RotateSideways(GEFloat);
    void ScreenToView(bCVector &) const;
    void ScreenToWorld(bCVector &) const;
    void TogglePerspectiveOrthogonal();
    void UpdateInitialValuesFromApp();
    void ViewToScreen(bCVector &) const;
    void WorldToScreen(bCVector &) const;

  protected:
    void CalcProjectionMatrix();
    void CalcViewMatrix();
    void CopyTo(eCCameraBase &) const;
    void InitializeCamera();
    void Invalidate();
    void Update(eECamUpdate);

  private:
    GE_UNIMPL_MEMBERS(32)
};

GE_ASSERT_SIZEOF(eCCameraBase, 0x100)

GE_ASSERT_PROPERTY(eCCameraBase, m_matView, 0xc, 64)
GE_ASSERT_PROPERTY(eCCameraBase, m_matProjection, 0x4c, 64)
GE_ASSERT_PROPERTY(eCCameraBase, m_vecPosition, 0x8c, 12)
GE_ASSERT_PROPERTY(eCCameraBase, m_vecRotation, 0x98, 12)
GE_ASSERT_PROPERTY(eCCameraBase, m_vecScale, 0xa4, 12)
GE_ASSERT_PROPERTY(eCCameraBase, m_vecClipProjection, 0xb0, 8)
GE_ASSERT_PROPERTY(eCCameraBase, m_vecClipDepth, 0xb8, 8)
GE_ASSERT_PROPERTY(eCCameraBase, m_recScreen, 0xc0, 16)
GE_ASSERT_PROPERTY(eCCameraBase, m_fFieldOfView, 0xd0, 4)
GE_ASSERT_PROPERTY(eCCameraBase, m_fAspectRatio, 0xd4, 4)
GE_ASSERT_PROPERTY(eCCameraBase, m_bPerspective, 0xd8, 1)
GE_ASSERT_PROPERTY(eCCameraBase, m_fDepthBias, 0xdc, 4)
