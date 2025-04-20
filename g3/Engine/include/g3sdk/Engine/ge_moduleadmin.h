#pragma once

#include <Engine/io/ge_inputdispatcher.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCModuleAdmin : public eCInputDispatcher
{
    // clang-format off
    public: virtual bEResult ResetResources(GEBool);
    public: virtual bEResult RestoreResources(GEBool);
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCModuleAdmin() override;
    public: bCGuid const & GetID() const override;
    public: GEBool RegisterModule(eCEngineComponentBase &) override;
    public: GEBool UnregisterModule(eCEngineComponentBase &) override;
    // clang-format on

  public:
    static eCModuleAdmin &GE_STDCALL GetInstance();

  public:
    eCModuleAdmin(eCModuleAdmin const &);
    eCModuleAdmin();

  public:
    void DoBeginRenderAlpha();
    void DoBeginRenderSolid();
    void DoEndRenderAlpha();
    void DoEndRenderSolid();
    bEResult DoInitializeModules();
    bEResult DoOnAppInitializeModules();
    bEResult DoPostInitializeModules();
    void DoPostRender();
    bEResult DoPreShutdownModules();
    bEResult DoShutdownModules();
    bEResult DoWorldActivate();
    bEResult DoWorldDeactivate();
    eCEngineComponentBase *FindModule(bCString const &) const;
    eCEngineComponentBase *GetModule(GEInt) const;
    GEInt GetModuleCount() const;
    GEBool IsEngineComponent(bCPropertyObjectBase const &) const;
    void PostProcess();
    void Process();

  protected:
    eCModuleAdmin const &operator=(eCModuleAdmin const &);

  protected:
    void Invalidate();
};
