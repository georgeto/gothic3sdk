#pragma once

#include "gs_propertymacros.h"

#include <Engine.h>

class GE_DLLIMPORT PSStrip : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSStrip, eCStrip_PS)
    GS_PROPERTY(GEBool, Enabled)
};
