#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCPropertyCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCPropertyCtrl() override;
    public: void Process() override;
    protected: void OnSysColorChange() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    eCPropertyCtrl(eCPropertyCtrl const &);
    eCPropertyCtrl();

  public:
    eCPropertyCtrl &operator=(eCPropertyCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCPropertyCtrl const &);
    void CopyTo(eCPropertyCtrl &) const;

  protected:
    void Invalidate();

  private:
    bCObjectRefBase *GetProperty() const;
    void SetProperty(bCObjectRefBase *);
};
