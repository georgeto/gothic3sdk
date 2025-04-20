#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_weatherstates.h>

#include <SharedBase.h>

class eCWeatherEnvironment;
class eCWeatherZone_PS;

enum eEWeatherAdminMode
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCWeatherAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: GEBool IsValid() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCWeatherAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: bEResult RestoreResources(GEBool) override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCWeatherAdmin, eCEngineComponentBase)

  public:
    GEBool AddWeatherEnvironment(eCWeatherEnvironment *);
    GEBool AddWeatherStates(eCWeatherStates *);
    eEAmbientClimate GetCurrentClimate() const;
    GEFloat GetCurrentDayTime() const;
    eEWeatherAdminMode GetCurrentMode() const;
    bCString const &GetCurrentMusicLocation() const;
    eCWeatherStates::eCWeatherState const &GetCurrentStates() const;
    bCVector const &GetPlayerPosition() const;
    eCWeatherEnvironment *GetWeatherEnvironmentAt(GEInt) const;
    eCWeatherEnvironment *GetWeatherEnvironmentByName(bCString const &) const;
    GEInt GetWeatherEnvironmentCount() const;
    eCWeatherStates *GetWeatherStatesAt(GEInt) const;
    eCWeatherStates *GetWeatherStatesByName(bCString const &) const;
    GEInt GetWeatherStatesCount() const;
    GEBool LoadWeatherStates();
    void OnWeatherStatesRenamed(bCString const &, bCString const &);
    GEBool RegisterWeatherZone(eCWeatherZone_PS *);
    GEBool RemoveWeatherEnvironment(eCWeatherEnvironment *);
    GEBool RemoveWeatherStates(eCWeatherStates *);
    GEBool SaveWeatherStates();
    void SetCurrentDayTime(GEFloat);
    void SetCurrentMode(eEWeatherAdminMode);
    void SetPlayerPosition(bCVector const &);
    GEBool UnregisterWeatherZone(eCWeatherZone_PS *);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(644)
};

GE_ASSERT_SIZEOF(eCWeatherAdmin, 0x298)

extern GE_DLLIMPORT bCString const *const g_pstrAmbientClimates;
extern GE_DLLIMPORT bCString const *const g_pstrAmbientDayTimes;
extern GE_DLLIMPORT bCString const *const g_pstrAmbientEnvironments;
