#pragma once

#include <Engine.h>

class gCEffectSystem;

class GE_DLLIMPORT gCEffectModule : public eCEffectModuleBase
{
    // clang-format off
    public: ~gCEffectModule() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: void Process() override;
    public: eCEffectSystemBase * GetSystemBase() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffectModule, eCEngineComponentBase)

  public:
    static gCEffectModule &GE_STDCALL GetInstance();

  public:
    gCEffectSystem *GetSystem() const;

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(gCEffectModule, 0x18)
