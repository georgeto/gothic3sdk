#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCStaticCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCStaticCtrl() override;
    public: void Process() override;
    protected: void OnSysColorChange() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    eCStaticCtrl(eCStaticCtrl const &);
    eCStaticCtrl();

  public:
    eCStaticCtrl &operator=(eCStaticCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCStaticCtrl const &);
    void CopyTo(eCStaticCtrl &) const;

  protected:
    void Invalidate();
};
