#pragma once

#include <SharedBase/SharedBaseEnum.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCVector2;
class bCVector;

enum bENoiseAmplitude
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT bCNoise
{
    // clang-format off
    public: virtual void SetSeed(GEInt) = 0;
    public: virtual GEFloat GetNoise(GEFloat) const = 0;
    public: virtual GEFloat GetNoise(GEFloat, GEFloat) const = 0;
    public: virtual GEFloat GetNoise(GEFloat, GEFloat, GEFloat) const = 0;
    public: virtual ~bCNoise();
    // clang-format on

  public:
    GEFloat GetNoise(bCVector2 const &) const;
    GEFloat GetNoise(bCVector const &) const;
    GEFloat GetTurbulence(bCVector2 const &, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat) const;
    GEFloat GetTurbulence(bCVector const &, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat) const;
    GEFloat GetTurbulence(GEFloat, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat) const;
    GEFloat GetTurbulence(GEFloat, GEFloat, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat) const;
    GEFloat GetTurbulence(GEFloat, GEFloat, GEFloat, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat) const;
    void SetTimedSeed();

  protected:
    bCNoise(bCNoise const &);
    bCNoise();

  protected:
    bCNoise &operator=(bCNoise const &);

  protected:
    void CopyFrom(bCNoise const &);
    void CopyTo(bCNoise &) const;
};
