#pragma once

#include <Engine/ge_enginecomponentbase.h>

class eCEffectSystemBase;

class GE_DLLIMPORT eCEffectModuleBase : public eCEngineComponentBase
{
    // clang-format off
    public: virtual eCEffectSystemBase * GetSystemBase() const = 0;
    public: ~eCEffectModuleBase() override;
    // clang-format on

  public:
    eCEffectModuleBase(eCEffectModuleBase const &);
    eCEffectModuleBase();

  public:
    eCEffectModuleBase &operator=(eCEffectModuleBase const &);
};
