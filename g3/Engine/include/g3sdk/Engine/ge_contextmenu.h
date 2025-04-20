#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCContextMenu : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCContextMenu() override;
    public: void Process() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCContextMenu, eCWnd)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    GEInt AddString(bCString const &, bCByteAlphaColor &);
    void CopyFrom(eCContextMenu const &);
    void CopyTo(eCContextMenu &) const;
    void Hide();
    void GE_STDCALL OnKeyDownList(bCObjectRefBase *, eCKeyDownEventArg *);
    void GE_STDCALL OnNotifyList(bCObjectRefBase *, eCNotifyEventArg *);
    void Reset();
    void Show(bCPoint const &, bCString const &);

  protected:
    void Invalidate();
    GEInt UpdateHeight();

  private:
    GE_UNIMPL_MEMBERS(308)
};

GE_ASSERT_SIZEOF(eCContextMenu, 0x224)
