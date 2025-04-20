#pragma once

#include <SharedBase/container/array/ge_smallarray.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_string.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCStringConverter
{
  public:
    static bCString GE_STDCALL ConvertFloatsToString(bTSmallArray<GEFloat> const &);
    static GEBool GE_STDCALL ConvertStringToFloats(bCString const &, bTSmallArray<GEFloat> &);

  public:
    bCStringConverter &operator=(bCStringConverter const &);
};
