#pragma once

#include <Engine.h>

class gCEffectCommand;
class gCEffectCommandSequence;

class GE_DLLIMPORT gCEffect
{
    // clang-format off
    public: virtual ~gCEffect();
    // clang-format on

  public:
    gCEffect(gCEffect const &);
    gCEffect();

  public:
    gCEffect &operator=(gCEffect const &);

  public:
    void Decay();
    void EnablePermanent(GEBool);
    void EnableProcessing(GEBool);
    gCEffectCommandSequence &GetCommandSequence();
    gCEffectCommandSequence const &GetCommandSequence() const;
    GEFloat GetElapsedTime() const;
    GEFloat GetEndTime() const;
    GEBool HasFinished() const;
    GEBool IsPermanentEnabled() const;
    GEBool IsProcessingEnabled() const;
    void Process(GEFloat);
    void Start(eCEntity *, eCEntity *, bCMatrix const &, GEBool);

  protected:
    void Destroy();
    void Execute(gCEffectCommand const *);
    void Invalidate();
    void KillSpawnees();
    void Reset();
};
