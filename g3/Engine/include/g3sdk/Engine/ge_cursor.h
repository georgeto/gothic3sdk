#pragma once

#include <Engine/ge_materialcanvas.h>

#include <SharedBase.h>

class eCImage
{
    GE_UNIMPL_STRUCT(eCImage)
};

class GE_DLLIMPORT eCCursor : public eCMaterialCanvas
{
    // clang-format off
    protected: bEResult Write(bCOStream &) override;
    protected: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCCursor() override;
    public: void Render() override;
    // clang-format on

  public:
    eCCursor();

  public:
    bEResult Create(eCImage *, GEInt, GEInt, GEInt, GEInt);
    bCPoint const &GetPosition() const;
    void GetPosition(bCPoint &) const;
    void Hide();
    GEBool IsVisible() const;
    void SetPosition(bCPoint const &);
    void SetPosition(GEInt, GEInt);
    void Show();

  protected:
    eCCursor(eCCursor const &);

  protected:
    eCCursor &operator=(eCCursor const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  protected:
    bCPoint &AccessDimensions();
    bCPoint &AccessHotSpot();
    bCPoint &AccessPosition();
    void CopyFrom(eCCursor const &);
    void CopyTo(eCCursor &) const;
    bCPoint const &GetDimensions() const;
    void GetDimensions(bCPoint &) const;
    bCPoint const &GetHotSpot() const;
    void GetHotSpot(bCPoint &) const;
    void Invalidate();
    void SetDimensions(bCPoint const &);
    void SetHotSpot(bCPoint const &);
};
