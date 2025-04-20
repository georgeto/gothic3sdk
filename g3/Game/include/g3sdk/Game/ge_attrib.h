#pragma once

#include <SharedBase.h>

class gCAttribCondDesc;
class gCAttribDesc;
class gCAttribModDesc;

class GE_DLLIMPORT gCAttrib
{
  public:
    gCAttrib(gCAttrib const &);
    gCAttrib();
    ~gCAttrib();

  public:
    gCAttrib &operator=(gCAttrib const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    GEInt AddMod(gCAttribModDesc const &);
    void Apply(gCAttribModDesc const &);
    GEBool CanConsume(gCAttribModDesc const &) const;
    GEBool Create(GEInt);
    GEBool DoesSatisfy(gCAttribCondDesc const &) const;
    GEInt GetBaseMaximum() const;
    GEInt GetBaseValue() const;
    gCAttribDesc *GetDesc() const;
    GEInt GetID() const;
    GEInt GetMaximum() const;
    void GetValMax(GEInt &, GEInt &) const;
    GEInt GetValue() const;
    GEBool RemoveMod(gCAttribModDesc const &);
    void SetBaseMaximum(GEInt);
    void SetBaseValMax(GEInt, GEInt);
    void SetBaseValue(GEInt);

  protected:
    void Cap();
    void Cap(GEInt &, GEInt) const;
    void RemoveAllMods();
};
