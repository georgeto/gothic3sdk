#pragma once

#include <Engine.h>

class gCMusicSequencer;
class gCMusicSystem;
struct gSMusicTrigger;

class GE_DLLIMPORT gCMusicModule : public eCEngineComponentBase
{
    // clang-format off
    public: ~gCMusicModule() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: void Process() override;
    public: void GetDebugLines(bTObjArray<eSModuleDebugLine> &) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMusicModule, eCEngineComponentBase)

  public:
    static gCMusicModule &GE_STDCALL GetInstance();

  public:
    void EnableAutoUpdate(GEBool);
    gCMusicSequencer *GetSequencer() const;
    gCMusicSystem *GetSystem() const;
    GEBool IsAutoUpdateEnabled() const;
    void SetDayTime(bCString const &);
    void SetLocation(bCString const &);
    void SetSituation(bCString const &);
    void Trigger(gSMusicTrigger const &);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(8)
};

GE_ASSERT_SIZEOF(gCMusicModule, 0x1c)
