#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_weatherstates.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCWeatherEnvironment
{
  public:
    struct eSProbability
    {
        GE_UNIMPL_STRUCT(eSProbability)
    };

    // clang-format off
    public: virtual bEResult Create();
    public: virtual void Destroy();
    public: virtual bEResult CopyFrom(eCWeatherEnvironment const &);
    public: virtual bEResult Read(bCIStream &);
    public: virtual bEResult Write(bCOStream &);
    // clang-format on

  public:
    eCWeatherEnvironment(eCWeatherEnvironment const &);
    eCWeatherEnvironment();
    ~eCWeatherEnvironment();

  public:
    eCWeatherEnvironment &operator=(eCWeatherEnvironment const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    GEBool AddWeatherStateBlendFactor(GEFloat);
    eEAmbientClimate GetClimate() const;
    GEFloat GetCurrentBlendFactor() const;
    GEBool GetCurrentWeatherStates(eCWeatherStates::eCWeatherState &);
    bCString const &GetMusicLocation() const;
    bCString const &GetName() const;
    GEBool GetProbability(bCString const &, eSProbability &);
    GEU16 GetVersion() const;
    void OnWeatherStatesAdded(bCString const &, GEFloat);
    void OnWeatherStatesRemoved(bCString const &);
    void OnWeatherStatesRenamed(bCString const &, bCString const &);
    void Process(GEFloat);
    void SetClimate(eEAmbientClimate);
    void SetMusicLocation(bCString const &);
    void SetName(bCString const &);
    void SetProbability(bCString const &, eSProbability const &);

  protected:
    void Invalidate();
};
