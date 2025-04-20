#pragma once

#include <Engine.h>

class gCQuestManager_PS;

class GE_DLLIMPORT gCQuestLogCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCQuestLogCtrl() override;
    public: void OnSize(GEU32, GEInt, GEInt) override;
    public: void Process() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCQuestLogCtrl, eCWnd)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(gCQuestLogCtrl const &);
    void CopyTo(gCQuestLogCtrl &) const;
    GEBool Init(gCQuestManager_PS const &);
    void GE_STDCALL OnCaretIndexChangedDates(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnCaretIndexChangedNames(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnCaretIndexChangedTypes(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnCaretIndexChangedVersions(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnNotifyList(bCObjectRefBase *, eCNotifyEventArg *);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(1152)
};

GE_ASSERT_SIZEOF(gCQuestLogCtrl, 0x570)
