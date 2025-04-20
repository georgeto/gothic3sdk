#pragma once

#include <Engine.h>

class gCInfoManager_PS;
class gCInfo_PS;

class GE_DLLIMPORT gCDialogManagerCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCDialogManagerCtrl() override;
    public: void OnSize(GEU32, GEInt, GEInt) override;
    public: void Process() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCDialogManagerCtrl, eCWnd)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void AddInfo(gCInfo_PS *);
    void ClearInfos();
    void CopyFrom(gCDialogManagerCtrl const &);
    void CopyTo(gCDialogManagerCtrl &) const;
    void DoSelectEntry(GEInt);
    GEBool Init();
    void GE_STDCALL OnKeyDownList(bCObjectRefBase *, eCKeyDownEventArg *);
    void GE_STDCALL OnNotifyList(bCObjectRefBase *, eCNotifyEventArg *);
    void GE_STDCALL OnNotifyWindow(bCObjectRefBase *, eCNotifyEventArg *);
    void SetInfoManager(gCInfoManager_PS *);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(300)
};

GE_ASSERT_SIZEOF(gCDialogManagerCtrl, 0x21c)
