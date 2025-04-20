#pragma once

#include <Engine/ge_materialcanvas.h>

#include <SharedBase.h>

class eCWnd;

class GE_DLLIMPORT eCCaret : public eCMaterialCanvas
{
    // clang-format off
    protected: bEResult Write(bCOStream &) override;
    protected: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCCaret() override;
    public: void Process() override;
    public: void Render() override;
    // clang-format on

  public:
    eCCaret();

  public:
    GEBool Create(eCWnd *, GEInt, GEInt);
    GEU32 GetBlinkTime() const;
    void GetBlinkTime(GEU32 &) const;
    bCPoint const &GetPosition() const;
    void GetPosition(bCPoint &) const;
    GEBool Hide(eCWnd *);
    GEBool IsVisible() const;
    void SetBlinkTime(GEU32);
    void SetPosition(bCPoint const &);
    void SetPosition(GEInt, GEInt);
    GEBool Show(eCWnd *);

  protected:
    eCCaret(eCCaret const &);

  protected:
    eCCaret &operator=(eCCaret const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  protected:
    GEU32 &AccessBlinkTime();
    bCPoint &AccessDimensions();
    eCWnd *&AccessOwner();
    bCPoint &AccessPosition();
    void CopyFrom(eCCaret const &);
    void CopyTo(eCCaret &) const;
    bCPoint const &GetDimensions() const;
    void GetDimensions(bCPoint &) const;
    eCWnd *GetOwner();
    eCWnd const *GetOwner() const;
    void GetOwner(eCWnd *&) const;
    void Invalidate();
    void SetDimensions(bCPoint const &);
    void SetOwner(eCWnd *);
};
