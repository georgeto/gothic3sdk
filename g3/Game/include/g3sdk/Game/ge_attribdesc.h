#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT gCAttribDesc
{
  public:
    gCAttribDesc(gCAttribDesc const &);
    gCAttribDesc();
    ~gCAttribDesc();

  public:
    gCAttribDesc &operator=(gCAttribDesc const &);

  public:
    void Create(bCString const &);
    void EnableCap(GEBool);
    bCUnicodeString GetDesc(GEBool) const;
    bCString GetDescTag(GEBool) const;
    bCString GetEnum() const;
    bCUnicodeString GetName(GEBool) const;
    bCString GetNameTag(GEBool) const;
    bCString GetTag() const;
    GEBool IsCapEnabled() const;
    void SetEnum(bCString const &);
    void SetTag(bCString const &);
};
