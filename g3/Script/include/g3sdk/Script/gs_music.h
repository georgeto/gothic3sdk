#pragma once

#include <Game.h>

class GE_DLLIMPORT Music
{
  public:
    Music();
    ~Music();

  public:
    Music &operator=(Music const &);

  public:
    GEBool TriggerExplore();
    GEBool TriggerFight();
    GEBool TriggerRevolution();
    GEBool TriggerShowdown();
    GEBool TriggerSituation(bCString const &);
    GEBool TriggerVictory();

  protected:
    GEBool Trigger(bCString const &, bCString const &, bCString const &, gEMusicFragmentPosition, gEMusicTriggerTime,
                   gEMusicTransition, GEInt, GEInt, GEBool);
};

GE_DLLIMPORT_EXTC Music music;
