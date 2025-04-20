#pragma once

#include <Script/effect/gs_effect.h>

#include <SharedBase.h>

class Entity;

class GE_DLLIMPORT EffectSystem
{
  public:
    static GEBool GE_STDCALL ExistsEffect(bCString const &);
    static Effect GE_STDCALL StartEffect(bCString const &, Entity const &, Entity const &);
    static Effect GE_STDCALL StartEffect(bCString const &, Entity const &);
    static Effect GE_STDCALL StartEffect(bCString const &, bCMatrix const &);
    static Effect GE_STDCALL StartEffect(bCString const &, bCMatrix const &, Entity const &);
    static Effect GE_STDCALL StartEffect(bCString const &, bCVector const &);
    static Effect GE_STDCALL StartEffect(bCString const &, bCVector const &, Entity const &);
    static GEBool GE_STDCALL StopEffect(Effect const &, GEBool a_bDecay);

  public:
    EffectSystem();
    ~EffectSystem();

  public:
    EffectSystem &operator=(EffectSystem const &);
};
