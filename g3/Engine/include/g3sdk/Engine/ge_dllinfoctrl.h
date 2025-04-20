#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCDllInfoCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCDllInfoCtrl() override;
    public: void OnSize(GEU32, GEInt, GEInt) override;
    public: void Process() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCDllInfoCtrl, eCWnd)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCDllInfoCtrl const &);
    void CopyTo(eCDllInfoCtrl &) const;
    GEBool Init();
    void GE_STDCALL OnCaretIndexChangedDates(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnCaretIndexChangedNames(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnCaretIndexChangedVersions(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnNotifyList(bCObjectRefBase *, eCNotifyEventArg *);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(868)
};

GE_ASSERT_SIZEOF(eCDllInfoCtrl, 0x454)
