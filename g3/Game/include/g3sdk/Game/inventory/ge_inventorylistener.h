#pragma once

#include <SharedBase.h>

class gCInventoryStack;

class GE_DLLIMPORT gCInventoryListener
{
    // clang-format off
    public: virtual void OnStackCreate(GEInt, gCInventoryStack const *) = 0;
    public: virtual void OnStackChange(GEInt, gCInventoryStack const *) = 0;
    public: virtual void OnStackDelete(GEInt, gCInventoryStack const *) = 0;
    public: virtual void OnSortInventory() = 0;
    public: virtual void OnDestroyInventory() = 0;
    // clang-format on

  public:
    gCInventoryListener(gCInventoryListener const &);
    gCInventoryListener();

  public:
    gCInventoryListener &operator=(gCInventoryListener const &);
};

GE_ASSERT_SIZEOF(gCInventoryListener, 0x4)
