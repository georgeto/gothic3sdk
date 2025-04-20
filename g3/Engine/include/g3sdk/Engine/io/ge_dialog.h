#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCDialog : public eCWnd
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCDialog() override;
    protected: void OnActivate(GEU32, eCWnd *, GEBool) override;
    protected: void OnSysColorChange() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    eCDialog(eCDialog const &);
    eCDialog();

  public:
    eCDialog &operator=(eCDialog const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCDialog const &);
    void CopyTo(eCDialog &) const;
    GEU32 GetDefID() const;
    void GetDefID(GEU32 &) const;
    void GotoDlgCtrl(eCWnd *);
    void MapDialogRect(bCRect &) const;
    void NextDlgCtrl();
    void PrevDlgCtrl();
    void SetDefID(GEU32);

  protected:
    GEU32 &AccessDefID();
    void Invalidate();
};
