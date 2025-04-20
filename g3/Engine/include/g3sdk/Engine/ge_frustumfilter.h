#pragma once

#include <SharedBase.h>

class eCCameraBase;
class eCEntity;
class eCFrustumDatabase;

class GE_DLLIMPORT eCFrustumFilter : public bCObjectRefBase
{
  public:
    enum eECullStatus
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCFrustumFilter() override;
    // clang-format on

  public:
    eCFrustumFilter(eCFrustumFilter const &);
    eCFrustumFilter();

  public:
    GEFloat CalculateAreaFactor(bCSphere const &);
    eECullStatus CullCamera(bCBox const &) const;
    eECullStatus CullCamera(bCBox const &, bCSphere const &) const;
    GEFloat CullSmallObjects(GEFloat, eCEntity const &);
    GEBool CullVPTFrustum(bCVector const &);
    eCCameraBase *GetCamera();
    eCCameraBase const *GetCamera() const;
    bCVector4 const &GetCameraZProj() const;
    GEFloat GetNearPlaneDistance(bCBox const &) const;
    GEFloat GetOCPriority(bCBox const &) const;
    void UpdateFrameDependencies(eCFrustumDatabase const &);

  protected:
    eECullStatus CullFrustum(bCBox const &) const;
    eECullStatus CullFrustum(bCSphere const &) const;
    void FillViewFrustum(bCMatrix const &, bCFrustum &);
    void Invalidate();
    void UpdateCameraObject();

  private:
    eCFrustumFilter const &operator=(eCFrustumFilter const &);
};
