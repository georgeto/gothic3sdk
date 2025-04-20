#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSSkill : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSSkill, gCSkill_PS)
    GS_PROPERTY_COPY_ONLY(LearnPoints)
    GS_PROPERTY_COPY_ONLY(ReqAttrib1Tag)
    GS_PROPERTY_COPY_ONLY(ReqAttrib1Value)
    GS_PROPERTY_COPY_ONLY(ReqAttrib2Tag)
    GS_PROPERTY_COPY_ONLY(ReqAttrib2Value)
    GS_PROPERTY_COPY_ONLY(ReqAttrib3Tag)
    GS_PROPERTY_COPY_ONLY(ReqAttrib3Value)
    GS_PROPERTY_COPY_ONLY(ReqAttrib4Tag)
    GS_PROPERTY_COPY_ONLY(ReqAttrib4Value)
    GS_PROPERTY_COPY_ONLY(Tag)

  public:
    Entity GetRequiredSkill() const;
};
