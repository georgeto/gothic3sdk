#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCAccessorProperty;
class bCString;

class GE_DLLIMPORT bCAccessorEnum
{
  public:
    explicit bCAccessorEnum(bCAccessorProperty &);

  public:
    GEInt GetEnumTypeInt(GEInt) const;
    bCString const &GetEnumTypeString(GEInt) const;
    GEInt GetTypeCount() const;
    GEInt GetValue() const;
    GEBool IsValid() const;
    void SetValue(GEInt);
};
