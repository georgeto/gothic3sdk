#pragma once

#include <Engine/ge_shadowmapbase.h>

#include <SharedBase.h>

class eCDirectionalLight_PS;

class GE_DLLIMPORT eCShadowMapDirectionalLightBase : public eCShadowMapBase
{
    // clang-format off
    public: virtual bCMatrix const & GetShadowMapMatrix() const = 0;
    public: virtual eCDirectionalLight_PS * GetLight() const;
    public: virtual void SetLight(eCDirectionalLight_PS *);
    public: virtual bCVector const & GetLightDirection() const;
    public: virtual void SetLightDirection(bCVector const &);
    public: virtual bTValArray<eCEntity *> const & GetShadowReciver() const;
    public: virtual void AddShadowReciver(eCEntity *);
    public: virtual void RemoveShadowReciver(eCEntity *);
    public: virtual void AddShadowCaster(eCEntity *);
    public: virtual void RemoveShadowCaster(eCEntity *);
    public: virtual bEResult Create(GEInt, eEDepthMapFormat, GEBool);
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: ~eCShadowMapDirectionalLightBase() override;
    // clang-format on

  public:
    eCShadowMapDirectionalLightBase(eCShadowMapDirectionalLightBase const &);
    eCShadowMapDirectionalLightBase();

  public:
    eCShadowMapDirectionalLightBase &operator=(eCShadowMapDirectionalLightBase const &);

  public:
    GEBool IsEmpty() const;

  protected:
    void Invalidate();
};
