#pragma once

#include <Engine/io/ge_inputreceiver.h>

#include <SharedBase.h>

class eCMenu;

struct eSModuleDebugLine
{
    GE_UNIMPL_STRUCT(eSModuleDebugLine)
};

class GE_DLLIMPORT eCEngineComponentBase : public eCInputReceiver
{
    // clang-format off
    public: virtual bCGuid const & GetID() const;
    public: virtual bEResult Initialize();
    public: virtual bEResult PostInitialize();
    public: virtual bEResult PreShutdown();
    public: virtual bEResult Shutdown();
    public: virtual void OnAppInitialized();
    public: virtual bEResult WorldActivate();
    public: virtual bEResult WorldDeactivate();
    public: virtual bEResult ResetResources(GEBool);
    public: virtual bEResult RestoreResources(GEBool);
    public: virtual void Process();
    public: virtual void PostProcess();
    public: virtual void OnBeginRenderSolid();
    public: virtual void OnEndRenderSolid();
    public: virtual void OnBeginRenderAlpha();
    public: virtual void OnEndRenderAlpha();
    public: virtual void OnPostRender();
    public: virtual void CreateMenu(eCMenu *);
    public: virtual void GetDebugLines(bTObjArray<eSModuleDebugLine> &) const;
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCEngineComponentBase() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCEngineComponentBase, eCInputReceiver)

  public:
    void Enable(GEBool);
    GEBool IsEnabled() const;

  protected:
    void Invalidate();

  private:
    GEBool m_bEnabled;
    GEBool __UNK_0011;
    GE_PADDING(2)
};

GE_ASSERT_SIZEOF(eCEngineComponentBase, 0x14)
