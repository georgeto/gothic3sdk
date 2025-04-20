#pragma once

#include <Engine.h>

class gCAmbientSystem;

class GE_DLLIMPORT gCAmbientModule : public eCAmbientModuleBase
{
    // clang-format off
    public: ~gCAmbientModule() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: void Process() override;
    public: GEBool Register(eCSpeedTree_PS const *) override;
    public: GEBool Unregister(eCSpeedTree_PS const *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCAmbientModule, eCAmbientModuleBase)

  public:
    static gCAmbientModule &GE_STDCALL GetInstance();

  public:
    gCAmbientSystem *GetSystem() const;
    void SetClimate(eEAmbientClimate);
    void SetDayTime(eEAmbientDayTime);
    void SetEnvironment(eEAmbientEnvironment);

  protected:
    void Invalidate();
    void UpdateClimate();
    void UpdateEnvironment();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(gCAmbientModule, 0x18)
