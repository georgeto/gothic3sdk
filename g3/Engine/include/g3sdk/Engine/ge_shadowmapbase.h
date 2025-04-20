#pragma once

#include <Engine/ge_depthmap.h>

#include <SharedBase.h>

class eCCameraBase;
class eCEntity;
class eCFrustumDatabase;

class GE_DLLIMPORT eCShadowMapBase : public eCDepthMap
{
    // clang-format off
    public: virtual GEFloat GetLightRange() const = 0;
    public: virtual bTValArray<eCEntity *> const * GetShadowCaster() const;
    public: virtual GEBool IsShadowCusterCullingEnabled() const;
    protected: virtual bEResult Create(GEInt, GEBool, eEDepthMapFormat, GEU32, GEBool);
    protected: virtual GEBool UpdateCamera(eCGfxShared::eECubeMapFace) = 0;
    protected: virtual GEBool RenderShadowScene();
    public: virtual GEBool RenderShadowMap();
    public: virtual GEBool OnPostExtraction();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    protected: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCShadowMapBase() override;
    public: void SetSize(GEInt) override;
    // clang-format on

  public:
    eCShadowMapBase(eCShadowMapBase const &);
    eCShadowMapBase();

  public:
    eCShadowMapBase &operator=(eCShadowMapBase const &);

  public:
    eCFrustumDatabase &GetFrustumDatabase();
    eCCameraBase const *GetShadowMapCamera() const;
    eCGfxImageData *GetShadowMapImage() const;

  protected:
    void Invalidate();
};
