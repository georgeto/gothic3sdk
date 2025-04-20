#pragma once

#include <Engine/io/ge_dialog.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCMessageBox : public eCDialog
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCMessageBox() override;
    public: GEU32 DoModal() override;
    protected: GEBool IsModalFinished() const override;
    protected: void OnParentNotify(GEU32, GEU32, GEU32, GEI32 *) override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    eCMessageBox(eCMessageBox const &);
    eCMessageBox();

  public:
    eCMessageBox &operator=(eCMessageBox const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    GEBool const CancelPressed() const;
    void CopyFrom(eCMessageBox const &);
    void CopyTo(eCMessageBox &) const;
    bCString GetCancelText() const;
    bCString GetNoText() const;
    bCString GetYesText() const;
    GEBool const NoPressed() const;
    void ResizeButtons();
    void SetCancelText(bCString const &);
    void SetNoText(bCString const &);
    void SetYesText(bCString const &);
    GEBool const YesPressed() const;

  protected:
    void Invalidate();
};
