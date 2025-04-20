#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class eCEntity;
class eCEntityPropertySet;

class GE_DLLIMPORT eCEntityCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCEntityCtrl() override;
    public: void OnSize(GEU32, GEInt, GEInt) override;
    public: void Process() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCEntityCtrl, eCWnd)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCEntityCtrl const &);
    void CopyTo(eCEntityCtrl &) const;
    eCEntity const *GetEntity() const;
    void GE_STDCALL OnCaretIndexChanged(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnClickList(bCObjectRefBase *, eCClickEventArg *);
    GEBool SetEntity(eCEntity const *);
    void ShowPS(eCEntityPropertySet *);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(1940)
};

GE_ASSERT_SIZEOF(eCEntityCtrl, 0x884)
