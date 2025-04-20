#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSPlayerMemory : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSPlayerMemory, gCPlayerMemory_PS)
    GS_PROPERTY(GEI32, BookOfFlood)
    GS_PROPERTY(GEI32, BookOfRhobar)
    GS_PROPERTY(GEI32, BookOfZuben)
    GS_PROPERTY(GEI32, Chapter)
    GS_PROPERTY(GEI32, DuskToDawnStartHour)
    GS_PROPERTY(GEBool, IsConsumingItem)
    GS_PROPERTY(GEI32, LPAttribs)
    GS_PROPERTY(GEI32, LPPerks)
    GS_PROPERTY(bCPropertyID, LastSpell)
    GS_PROPERTY(gEWeaponConfig, LastWeaponConfig)
    GS_PROPERTY(GEFloat, SecondsMistRemain)
    GS_PROPERTY(GEFloat, SecondsTransformRemain)
    GS_PROPERTY(GEBool, TalkedToDiego)
    GS_PROPERTY(GEBool, TalkedToGorn)
    GS_PROPERTY(GEBool, TalkedToLester)
    GS_PROPERTY(GEBool, TalkedToMilten)
    GS_PROPERTY(GEFloat, TimeStampStart)
    GS_PROPERTY(GEI32, XP)

  public:
    void AddAlchemy(GEInt);
    void AddBaseValue(bCString const &, GEInt);
    void AddDexterity(GEInt);
    void AddHitPoints(GEInt);
    void AddHitPointsMax(GEInt);
    void AddIntelligence(GEInt);
    void AddManaPoints(GEInt);
    void AddManaPointsMax(GEInt);
    void AddMaximum(bCString const &, GEInt);
    void AddModifier(bCString const &, GEInt);
    void AddProtectionBlades(GEInt);
    void AddProtectionFire(GEInt);
    void AddProtectionIce(GEInt);
    void AddProtectionImpact(GEInt);
    void AddProtectionLightning(GEInt);
    void AddProtectionMissile(GEInt);
    void AddSmithing(GEInt);
    void AddStaminaPoints(GEInt);
    void AddStaminaPointsMax(GEInt);
    void AddStrength(GEInt);
    void AddTheft(GEInt);
    void AddValue(bCString const &, GEInt);
    GEBool ClearGameEvent(bCString const &);
    void EnableTutorial(gETutorialFlag, GEBool);
    GEInt GetAlchemy() const;
    GEInt GetBaseValue(bCString const &) const;
    GEInt GetDexterity() const;
    GEInt GetHitPoints() const;
    GEInt GetHitPointsMax() const;
    GEFloat GetHitPointsPercent() const;
    GEInt GetIntelligence() const;
    GEInt GetManaPoints() const;
    GEInt GetManaPointsMax() const;
    GEFloat GetManaPointsPercent() const;
    GEInt GetMaximum(bCString const &) const;
    GEInt GetModifier(bCString const &) const;
    GEI32 GetPoliticalCrimeCount(gEPoliticalAlignment);
    GEI32 GetPoliticalFame(gEPoliticalAlignment);
    GEBool GetPoliticalPlayerCrime(gEPoliticalAlignment);
    GEI32 GetPoliticalSuspectComment(gEPoliticalAlignment);
    GEInt GetProtectionBlades() const;
    GEInt GetProtectionFire() const;
    GEInt GetProtectionIce() const;
    GEInt GetProtectionImpact() const;
    GEInt GetProtectionLightning() const;
    GEInt GetProtectionMissile() const;
    GEInt GetSmithing() const;
    GEInt GetStaminaPoints() const;
    GEInt GetStaminaPointsMax() const;
    GEFloat GetStaminaPointsPercent() const;
    GEInt GetStrength() const;
    GEInt GetTheft() const;
    GEInt GetValue(bCString const &) const;
    GEBool IsSetGameEvent(bCString const &);
    GEBool IsTutorialEnabled(gETutorialFlag) const;
    void PrintAddMaximum(bCString const &, GEInt);
    void PrintAddValue(bCString const &, GEInt);
    void SetAlchemy(GEInt);
    void SetBaseValue(bCString const &, GEInt);
    void SetDexterity(GEInt);
    GEBool SetGameEvent(bCString const &);
    void SetHitPoints(GEInt);
    void SetHitPointsMax(GEInt);
    void SetIntelligence(GEInt);
    void SetManaPoints(GEInt);
    void SetManaPointsMax(GEInt);
    void SetMaximum(bCString const &, GEInt);
    void SetModifier(bCString const &, GEInt);
    void SetPoliticalCrimeCount(gEPoliticalAlignment, GEI32);
    void SetPoliticalFame(gEPoliticalAlignment, GEI32);
    void SetPoliticalPlayerCrime(gEPoliticalAlignment, GEBool);
    void SetPoliticalSuspectComment(gEPoliticalAlignment, GEI32);
    void SetProtectionBlades(GEInt);
    void SetProtectionFire(GEInt);
    void SetProtectionIce(GEInt);
    void SetProtectionImpact(GEInt);
    void SetProtectionLightning(GEInt);
    void SetProtectionMissile(GEInt);
    void SetSmithing(GEInt);
    void SetStaminaPoints(GEInt);
    void SetStaminaPointsMax(GEInt);
    void SetStrength(GEInt);
    void SetTheft(GEInt);
    void SetValue(bCString const &, GEInt);
};
