#pragma once

#include <Engine/ge_enginecomponentbase.h>

#include <SharedBase.h>

class eCStatisticCtrl;

class GE_DLLIMPORT eCPerformanceAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCPerformanceAdmin() override;
    public: bCGuid const & GetID() const override;
    public: bEResult PreShutdown() override;
    public: void PostProcess() override;
    public: void CreateMenu(eCMenu *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCPerformanceAdmin, eCEngineComponentBase)

  public:
    void AddStatisticCtrl(eCStatisticCtrl *, bCString const &);
    GEBool CheckIfCtrlExists(bCString const &, bCEvent *) const;
    eCStatisticCtrl *GetOveralPerformanceCtrl();
    eCStatisticCtrl const *GetOveralPerformanceCtrl() const;
    eCStatisticCtrl *GetStatisticCtrl(bCString const &);
    eCStatisticCtrl const *GetStatisticCtrl(bCString const &) const;
    eCStatisticCtrl *GetStatisticCtrlAt(GEInt);
    eCStatisticCtrl const *GetStatisticCtrlAt(GEInt) const;
    GEInt GetStatisticCtrlCount() const;
    eCStatisticCtrl *InsertNewStatisticCtrl(bCString const &);
    GEBool IsProfilingEnabled() const;
    GEBool IsStatisticCtrlValid(GEInt) const;
    GEBool RemoveStatisticCtrl(bCString const &);
    GEBool RemoveStatisticCtrl(eCStatisticCtrl *);

  protected:
    void Invalidate();
    void GE_STDCALL OnMenuDebugMemory(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileAnis(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileEntity(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileFPS(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileGUI(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileIllumination(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileOverall(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfilePFX(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfilePhysics(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileRays(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileRender(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileSceneAlphaPolys(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileScenePolys(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileSound(bCObjectRefBase *, bCEvent *);

  private:
    GE_UNIMPL_MEMBERS(16)
};

GE_ASSERT_SIZEOF(eCPerformanceAdmin, 0x24)
