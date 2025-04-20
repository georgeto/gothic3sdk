#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCDesktop : public eCWnd
{
    // clang-format off
    protected: void Destroy() override;
    public: ~eCDesktop() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    static eCDesktop &GE_STDCALL GetInstance();

  public:
    eCDesktop(eCDesktop const &);
    eCDesktop();

  public:
    eCDesktop &operator=(eCDesktop const &);

  public:
    void ReSize();

  protected:
    void Invalidate();
};
