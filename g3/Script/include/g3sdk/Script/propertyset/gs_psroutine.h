#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSRoutine : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSRoutine, gCScriptRoutine_PS)
    GS_PROPERTY(gEAIMode, AIMode)
    GS_PROPERTY(gEAction, Action)
    GS_PROPERTY(gEAmbientAction, AmbientAction)
    GS_PROPERTY(gEAniState, AniState)
    GS_PROPERTY(GEI32, CommandTime)
    GS_PROPERTY(gEHitDirection, HitDirection)
    GS_PROPERTY(GEU32, StatePosition)
    GS_PROPERTY(GEU32, TaskPosition)

  public:
    // Effectively calls gCScriptProcessingUnit::DetectDailyRoutineTask
    void ContinueRoutine();
    // Stop the currently executed AI instruction
    void FullStop();
    bCString GetCurrentRoutineTask() const;
    bCString GetCurrentState() const;
    bCString GetCurrentTask() const;
    bCString GetLastTask() const;
    // Unit is seconds, advanced by gCScriptProcessingUnit::ProcessScript
    GEFloat GetStateTime() const;
    GEFloat GetTaskTime() const;
    // Callback local to the current state (per RunTimeStack entry)
    void SetLocalCallback(bCString);
    void SetState(bCString);
    void SetStateTime(GEFloat);
    void SetTask(bCString);
    // Task callback, is reset when SetTask() is called
    void SetTaskCallback(bCString);
    void SetTaskTime(GEFloat);
    void SetTimeScale(GEFloat);
    void StartOutput(bCString);
    void StopAICombatMove();
    void StopAIGoto();
    void StopAIOutput();
    void StopAIPlayAnimation();
    void StopAIWait();
};
