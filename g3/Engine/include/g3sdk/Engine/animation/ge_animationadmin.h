#pragma once

#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCAnimation_HardwareSkinner;
class eCResourceDataEntity;
class eCVisualAnimation_PS;

class GE_DLLIMPORT eCAnimationAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: GEU32 const GetProfileLastTicksFirst() const override;
    public: ~eCAnimationAdmin() override;
    public: bCGuid const & GetID() const override;
    public: bEResult Initialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCAnimationAdmin, eCEngineComponentBase)

  public:
    void AddMissingAnimation(bCString const &);
    void AddProfileTicks(GEU32);
    void ClearMissingAnimations();
    GEFloat GetAniExtroBlending(bCString &) const;
    GEFloat GetAniIntroBlending(bCString &) const;
    void GetAniVariation(bCString &) const;
    eCAnimation_HardwareSkinner *GetHardwareSkinner();
    GEFloat GetPhysicControllerDistance() const;
    GEFloat GetStandardAniFadeTime();
    GEBool IsAnimationMissed(bCString const &) const;
    void Prefetch(eCVisualAnimation_PS &);
    eCResourceDataEntity *QueryMotionDataEntity(bCString const &, eEResourceCacheBehavior);
    void Render(eCVisualAnimation_PS &, GEBool, GEBool);
    void SetAniVariationMax(bCString const &);
    void SetPhysicControllerDistance(GEFloat);
    void SetStandardAniFadeTime(GEFloat);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(88)
};

GE_ASSERT_SIZEOF(eCAnimationAdmin, 0x6c)
