#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCProgressCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCProgressCtrl() override;
    public: void Process() override;
    protected: void OnSysColorChange() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    eCProgressCtrl(eCProgressCtrl const &);
    eCProgressCtrl();

  public:
    eCProgressCtrl &operator=(eCProgressCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    GEFloat CalcPercentOf(GEFloat, GEFloat, GEFloat);
    void CopyFrom(eCProgressCtrl const &);
    void CopyTo(eCProgressCtrl &) const;
    GEInt GetProgressPercent() const;
    void ResetProgress();
    void ResetRange();
    void SetMinimumStep(GEInt);
    void SetProgressPercent(GEInt, bCString);
    void SetProgressTexture(bCString const &);
    void SetRange(GEInt, GEInt);

  protected:
    void Invalidate();
};
