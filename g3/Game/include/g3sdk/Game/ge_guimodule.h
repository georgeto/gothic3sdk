#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCGUIModule : public eCEngineComponentBase
{
    // clang-format off
    public: ~gCGUIModule() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: void OnAppInitialized() override;
    public: void OnPostRender() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCGUIModule, eCEngineComponentBase)

  public:
    static gCGUIModule &GE_STDCALL GetInstance();

  public:
    void AddFocusNameEntity(eCEntity const *, GEFloat);
    void Render();

  protected:
    GEBool Draw();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(gCGUIModule, 0x18)
