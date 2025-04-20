#pragma once

#include <SharedBase.h>

class gCAttrib;
class gCItemStats;
class gCTrait;

class GE_DLLIMPORT gCStats
{
  public:
    gCStats();
    ~gCStats();

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void ActivateTrait(GEInt);
    GEBool CanConsume(gCItemStats const &) const;
    GEBool CanEquip(gCItemStats const &) const;
    GEBool CanLearnTrait(GEInt) const;
    GEBool CanPayTraitLearnCosts(GEInt) const;
    void Consume(gCItemStats &);
    void DeactivateTrait(GEInt);
    void Equip(gCItemStats &);
    gCAttrib *GetAttrib(GEInt) const;
    GEInt GetAttribCount() const;
    gCTrait *GetTrait(GEInt) const;
    GEInt GetTraitActivationCount(GEInt) const;
    GEInt GetTraitCount() const;
    GEBool HasLearnedTraitDependencies(GEInt) const;
    GEBool HasRequiredAttributeValues(GEInt) const;
    GEBool IsTraitActive(GEInt) const;
    GEBool IsTraitLearned(GEInt) const;
    void LearnTrait(GEInt);
    void Unequip(gCItemStats &);

  protected:
    void ApplyModifiers(gCTrait &);
    void DestroyAttribs();
    void DestroyTraits();
    void PayLearnCosts(gCTrait &);
    void UnapplyModifiers(gCTrait &);
};
