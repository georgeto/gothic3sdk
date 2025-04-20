#pragma once

#include <Engine/io/ge_dialog.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCConsoleDlg : public eCDialog
{
    // clang-format off
    public: virtual bCString Execute(bCString const &);
    protected: virtual GEBool OnExecute(bCString const &, bCString &);
    protected: virtual GEBool OnComplete(bCString &);
    public: virtual void PrintChoices(bCString const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    protected: void Destroy() override;
    public: ~eCConsoleDlg() override;
    protected: void OnSize(GEU32, GEInt, GEInt) override;
    protected: GEBool OnChildNotify(GEU32, GEU32, GEU32, GEI32 *) override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    public: GEInt OnKeyDown(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &) override;
    // clang-format on

  public:
    eCConsoleDlg(eCConsoleDlg const &);
    eCConsoleDlg();

  public:
    eCConsoleDlg &operator=(eCConsoleDlg const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCConsoleDlg const &);
    void CopyTo(eCConsoleDlg &) const;
    void PrintHistory();
    void PrintOutput(bCString const &, bCByteAlphaColor const &);
    void ReSize();

  protected:
    bTObjArray<bCString> &AccessHistory();
    void Complete();
    void Execute();
    bTObjArray<bCString> const &GetHistory() const;
    void GetHistory(bTObjArray<bCString> &) const;
    void GotoEntry(GEInt);
    void Invalidate();
    void NextEntry();
    void PrevEntry();
    void SetHistory(bTObjArray<bCString> const &);
};
