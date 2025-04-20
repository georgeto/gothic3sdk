#pragma once

#include <Game/ge_attribconddesc.h>
#include <Game/ge_attribmoddesc.h>

#include <SharedBase.h>

class GE_DLLIMPORT gCTraitDesc
{
  public:
    gCTraitDesc(gCTraitDesc const &);
    gCTraitDesc();
    ~gCTraitDesc();

  public:
    gCTraitDesc &operator=(gCTraitDesc const &);

  public:
    void Create(bCString const &);
    bTObjArray<gCAttribCondDesc> &GetConditions();
    bTObjArray<gCAttribCondDesc> const &GetConditions() const;
    bTObjArray<gCAttribModDesc> &GetCosts();
    bTObjArray<gCAttribModDesc> const &GetCosts() const;
    bTValArray<GEInt> &GetDependencies();
    bTValArray<GEInt> const &GetDependencies() const;
    bCUnicodeString GetDesc(GEBool) const;
    bCString GetDescTag(GEBool) const;
    bCString GetEnum() const;
    bTObjArray<gCAttribModDesc> &GetMods();
    bTObjArray<gCAttribModDesc> const &GetMods() const;
    bCUnicodeString GetName(GEBool) const;
    bCString GetNameTag(GEBool) const;
    bCString GetTag() const;
    void SetEnum(bCString const &);
    void SetTag(bCString const &);
};
