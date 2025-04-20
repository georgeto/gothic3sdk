#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTreeCtrl : public eCWnd
{
    // clang-format off
    public: virtual GEInt OnKeyboardInput(GEU32, GEU32);
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCTreeCtrl() override;
    public: void Process() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    eCTreeCtrl(eCTreeCtrl const &);
    eCTreeCtrl();

  public:
    eCTreeCtrl &operator=(eCTreeCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCTreeCtrl const &);
    void CopyTo(eCTreeCtrl &) const;

  protected:
    void Invalidate();
};
