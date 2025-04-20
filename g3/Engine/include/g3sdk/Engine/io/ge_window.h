#pragma once

#include <Engine/io/ge_messagehandler.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCWindow : public eCMessageHandler
{
  public:
    enum eEWindowMode
    {
        eEWindowMode_Window = 1,
        eEWindowMode_Fullscreen = 2,
    };

    struct eSCreate
    {
        GE_UNIMPL_STRUCT(eSCreate)
    };

    // clang-format off
    public: virtual GEBool Create(eSCreate const &);
    protected: void Destroy() override;
    protected: bEResult Create() override;
    public: ~eCWindow() override;
    protected: GEInt OnActivate(GEUInt, GEI32) override;
    protected: GEInt OnDestroy(GEUInt, GEI32) override;
    protected: GEInt OnQuit(GEUInt, GEI32) override;
    protected: GEInt OnPaint(GEUInt, GEI32) override;
    // clang-format on

  public:
    eCWindow(eCWindow const &);
    eCWindow();

  public:
    operator HINSTANCE();
    operator HINSTANCE const() const;
    operator HWND();
    operator HWND const() const;
    eCWindow &operator=(eCWindow const &);

  public:
    void AttachTo(HINSTANCE const, HDC const);
    void AttachTo(HINSTANCE const, HWND const);
    void Center();
    HDC GetDeviceContext() const;
    HWND GetHandle() const;
    HINSTANCE GetInstance() const;
    bCRect const &GetPosition() const;
    eEWindowMode GetWindowMode() const;
    GEBool IsAttached() const;
    GEBool IsCreated() const;
    GEBool IsSubClassed() const;
    void Restore();
    GEI32 GE_STDCALL SendMessageA(GEUInt, GEUInt, GEI32);
    void SetPosition(bCRect const &);
    void SetWindowMode(eEWindowMode);
    void Validate();

  protected:
    static GEI32 GE_STDCALL Receive(HWND, GEUInt, GEUInt, GEI32);
    static void GE_STDCALL RegisterWindow(HWND, eCWindow *);

  protected:
    GEBool Create(HINSTANCE, GELPVoid, bCString const &, bCRect const &, eEWindowMode);
    GEBool Create(HINSTANCE, GELPVoid, eEWindowMode);
    void Invalidate();
};
