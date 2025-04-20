#pragma once

#include <Engine.h>

class gCAttribDesc;
class gCTraitDesc;

class GE_DLLIMPORT gCStatsAdmin
{
  public:
    static gCStatsAdmin &GE_STDCALL GetInstance();

  public:
    gCStatsAdmin(gCStatsAdmin const &);
    ~gCStatsAdmin();

  public:
    gCStatsAdmin &operator=(gCStatsAdmin const &);

  public:
    GEInt AddAttrib(bCString const &);
    GEInt AddTrait(bCString const &);
    gCAttribDesc *GetAttrib(bCString const &) const;
    gCAttribDesc *GetAttrib(GEInt) const;
    GEInt GetAttribCount() const;
    GEInt GetAttribIndex(bCString const &) const;
    void GetHeaderContent(bCString &) const;
    gCTraitDesc *GetTrait(bCString const &) const;
    gCTraitDesc *GetTrait(GEInt) const;
    GEInt GetTraitCount() const;
    GEInt GetTraitIndex(bCString const &) const;
    GEBool Read();
    GEBool RemoveAttrib(bCString const &);
    GEBool RemoveAttrib(GEInt);
    GEBool RemoveTrait(bCString const &);
    GEBool RemoveTrait(GEInt);
    GEBool Write() const;

  protected:
    gCStatsAdmin();

  protected:
    GEBool Read(bCString const &);
    GEBool Read(eCConfigFile const &);
    GEBool Write(eCConfigFile &) const;
    GEBool Write(bCString const &) const;
    GEBool WriteHeaderFile(bCString const &) const;
};
