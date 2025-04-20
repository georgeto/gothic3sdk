#pragma once

#include <Engine/io/ge_dialog.h>

#include <SharedBase.h>

class eCScopeInstance;
struct eIDispatch;

class GE_DLLIMPORT eCObjectInspectorDlg : public eCDialog
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    protected: void Destroy() override;
    public: ~eCObjectInspectorDlg() override;
    protected: void OnSize(GEU32, GEInt, GEInt) override;
    protected: GEBool OnChildNotify(GEU32, GEU32, GEU32, GEI32 *) override;
    protected: void OnRender() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    public: GEInt OnKeyDown(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &) override;
    // clang-format on

  public:
    eCObjectInspectorDlg(eCObjectInspectorDlg const &);
    eCObjectInspectorDlg();

  public:
    eCObjectInspectorDlg &operator=(eCObjectInspectorDlg const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCObjectInspectorDlg const &);
    void CopyTo(eCObjectInspectorDlg &) const;
    void Resize();
    GEBool SetInstance(eCScopeInstance *);

  protected:
    void AddControls(eIDispatch *);
    void AddControls(eCScopeInstance *);
    void Invalidate();
    void RemoveControls();
};
