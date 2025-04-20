#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCLogoCtrl : public eCWnd
{
    // clang-format off
    public: void Destroy() override;
    public: ~eCLogoCtrl() override;
    public: void Process() override;
    protected: GEBool OnChildNotify(GEU32, GEU32, GEU32, GEI32 *) override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    eCLogoCtrl(eCLogoCtrl const &);
    eCLogoCtrl();

  public:
    eCLogoCtrl &operator=(eCLogoCtrl const &);

  public:
    void CopyFrom(eCLogoCtrl const &);
    void CopyTo(eCLogoCtrl &) const;
    GEU32 GetLogoStyle() const;
    bCString GetTexture() const;
    void SetFlashTime(GEFloat);
    void SetLogoStyle(GEU32);
    void SetTexture(bCString const &);
    void UpdatePlacement();

  protected:
    void Invalidate();
};
