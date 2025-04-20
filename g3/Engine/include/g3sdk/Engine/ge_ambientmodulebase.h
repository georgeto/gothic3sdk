#pragma once

#include <Engine/ge_enginecomponentbase.h>

class eCSpeedTree_PS;

class GE_DLLIMPORT eCAmbientModuleBase : public eCEngineComponentBase
{
    // clang-format off
    public: virtual GEBool Register(eCSpeedTree_PS const *) = 0;
    public: virtual GEBool Unregister(eCSpeedTree_PS const *) = 0;
    public: ~eCAmbientModuleBase() override;
    // clang-format on

  public:
    eCAmbientModuleBase(eCAmbientModuleBase const &);
    eCAmbientModuleBase();

  public:
    eCAmbientModuleBase &operator=(eCAmbientModuleBase const &);
};
