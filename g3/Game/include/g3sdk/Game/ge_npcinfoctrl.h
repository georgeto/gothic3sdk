#pragma once

#include <Engine.h>

class gCEntity;

class GE_DLLIMPORT gCNpcInfoCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCNpcInfoCtrl() override;
    public: void OnSize(GEU32, GEInt, GEInt) override;
    public: void Process() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCNpcInfoCtrl, eCWnd)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(gCNpcInfoCtrl const &);
    void CopyTo(gCNpcInfoCtrl &) const;
    GEBool Init();
    void GE_STDCALL OnCaretIndexChangedNPCPropertySets(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnCaretIndexChangedNPCs(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnNotifyList(bCObjectRefBase *, eCNotifyEventArg *);

  protected:
    void FindNPCsRecursive(eCNode &, bTPtrArray<gCEntity const *> &);
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(2236)
};

GE_ASSERT_SIZEOF(gCNpcInfoCtrl, 0x9ac)
