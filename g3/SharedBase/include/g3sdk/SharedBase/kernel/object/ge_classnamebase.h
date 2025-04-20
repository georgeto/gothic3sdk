#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_string.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCClassNameBase
{
  public:
    static bCString GE_STDCALL UnMangle(GELPCChar);

  public:
    bCClassNameBase &operator=(bCClassNameBase const &);
};
