#pragma once

#include <Game/ge_attribconddesc.h>
#include <Game/ge_attribmoddesc.h>

#include <SharedBase.h>

class GE_DLLIMPORT gCItemStats
{
  public:
    gCItemStats(gCItemStats const &);
    gCItemStats();
    ~gCItemStats();

  public:
    gCItemStats &operator=(gCItemStats const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    bTObjArray<gCAttribModDesc> &GetConsumeMods();
    bTObjArray<gCAttribModDesc> const &GetConsumeMods() const;
    bTObjArray<gCAttribCondDesc> &GetEquipConditions();
    bTObjArray<gCAttribCondDesc> const &GetEquipConditions() const;
    bTObjArray<gCAttribModDesc> &GetEquipMods();
    bTObjArray<gCAttribModDesc> const &GetEquipMods() const;
    bTValArray<GEInt> &GetEquipTraits();
    bTValArray<GEInt> const &GetEquipTraits() const;
};
