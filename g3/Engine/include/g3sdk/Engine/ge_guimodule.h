#pragma once

#include <Engine/ge_enginecomponentbase.h>

#include <GFC.h>

class eCGUIAdmin;

class GE_DLLIMPORT eCGUIModule : public eCEngineComponentBase, public IFFGFCClient
{
    // clang-format off
    // Overrides for eCEngineComponentBase
    public: GEU32 const GetProfileLastTicksFirst() const override;
    public: ~eCGUIModule() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: void OnAppInitialized() override;
    public: void OnPostRender() override;
    // Overrides for IFFGFCClient
    public: GEBool DoModalFrame() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCGUIModule, eCEngineComponentBase)

  public:
    static eCGUIModule &GE_STDCALL GetInstance();

  public:
    GEBool ActivateTheme(bCString const &);
    void EnableDrawScale(GEBool);
    void EnableInput(GEBool);
    void EnableMouseScale(GEBool);
    eCGUIAdmin &GetAdmin();
    bCPoint GetVirtualResolution() const;
    GEBool HandleMessage(GELPVoid, GEUInt, GEUInt, GEI32);
    GEBool IsDrawScaleEnabled() const;
    GEBool IsMouseScaleEnabled() const;
    GEBool ReSize();
    void Render();
    void RenderEdit(HWND, GEU32);
    void SetVirtualResolution(bCPoint const &);
    void ShowCursor(GEBool);
    void ToVirtualCoords(GEUInt, GEUInt &, GEI32 &) const;

  protected:
    GEBool Draw();
    void Invalidate();
    GEBool LoadResources();

  private:
    GE_UNIMPL_MEMBERS(144)
};

GE_ASSERT_SIZEOF(eCGUIModule, 0xa8)
