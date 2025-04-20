#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT Template
{
  public:
    Template(Template const &);
    explicit Template(bCPropertyID const &);
    Template(GELPCChar);
    Template();
    ~Template();

  public:
    explicit operator bCPropertyID &();
    operator bCPropertyID const &() const;
    Template &operator=(Template const &);
    Template &operator=(bCPropertyID const &);
    Template &operator=(GELPCChar);
    GEBool operator==(bCPropertyID const &) const;
    GEBool operator!=(bCPropertyID const &) const;

  public:
    GEBool IsValid() const;

  private:
    void Create(GELPCChar);

  private:
    GELPVoid pguid_Data1;
    GELPVoid pguid_Data2;
    GELPVoid pguid_Data3;
    GELPVoid pguid_Data4;
    GEU32 count;
};
