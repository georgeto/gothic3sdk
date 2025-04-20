#pragma once

#include <SharedBase/math/2d/ge_point.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;
struct tagRECT;

class GE_DLLIMPORT bCRect
{
  public:
    explicit bCRect(tagRECT const &);
    bCRect(bCRect const &);
    bCRect(bCPoint const &, bCPoint const &);
    bCRect(GEI32 a_TopLeftX, GEI32 a_TopLeftY, GEI32 a_BottomRightX, GEI32 a_BottomRightY);
    bCRect();
    ~bCRect();

  public:
    explicit operator tagRECT &();
    explicit operator tagRECT *();
    explicit operator tagRECT const &() const;
    explicit operator tagRECT const *() const;
    bCRect &operator=(tagRECT const &);
    bCRect &operator=(bCRect const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCRect const &) const;
    GEBool operator!=(bCRect const &) const;
    bCPoint &operator[](GEInt);
    bCPoint const &operator[](GEInt) const;
    bCRect operator-(bCPoint const &) const;
    bCRect operator+(bCPoint const &) const;
    bCRect operator&(bCRect const &) const;
    GEI32 &operator()(GEInt);
    GEI32 operator()(GEInt) const;
    bCRect operator|(bCRect const &) const;
    bCRect &operator+=(bCPoint const &);
    bCRect &operator-=(bCPoint const &);
    bCRect &operator&=(bCRect const &);
    bCRect &operator|=(bCRect const &);

  public:
    GEI32 &AccessBottom();
    bCPoint &AccessBottomRight();
    GEI32 &AccessCoordinate(GEInt);
    GEI32 &AccessLeft();
    bCPoint &AccessPoint(GEInt);
    GEI32 &AccessRight();
    GEI32 &AccessTop();
    bCPoint &AccessTopLeft();
    GEBool Contains(bCRect const &) const;
    GEBool Contains(bCPoint const &) const;
    GEBool ContainsExclusive(bCPoint const &) const;
    GEBool ContainsInclusive(bCPoint const &) const;
    GEI32 GetBottom() const;
    void GetBottom(GEI32 &) const;
    bCPoint const &GetBottomRight() const;
    void GetBottomRight(bCPoint &) const;
    bCPoint GetCenterPoint() const;
    GEI32 GetCoordinate(GEInt) const;
    void GetCoordinate(GEI32 &, GEInt) const;
    GEI32 GetHeight() const;
    bCRect GetIntersected(bCRect const &) const;
    GEI32 GetLeft() const;
    void GetLeft(GEI32 &) const;
    bCPoint GetMagnitude() const;
    bCRect GetMerged(bCRect const &) const;
    bCPoint const &GetPoint(GEInt) const;
    void GetPoint(bCPoint &, GEInt) const;
    GEI32 GetRight() const;
    void GetRight(GEI32 &) const;
    GEI32 GetTop() const;
    void GetTop(GEI32 &) const;
    bCPoint const &GetTopLeft() const;
    void GetTopLeft(bCPoint &) const;
    GEI32 GetWidth() const;
    void Inflate(GEI32 const &);
    void Intersect(bCRect const &);
    GEBool Intersects(bCRect const &) const;
    void InvTranslate(bCPoint const &);
    void InvTranslate(GEI32, GEI32);
    void Invalidate();
    GEBool IsEmpty() const;
    GEBool IsNormalized() const;
    GEBool IsValid() const;
    void Merge(bCRect const &);
    void Merge(bCPoint const &);
    void Normalize();
    void SetBottom(GEI32);
    void SetBottomRight(bCPoint const &);
    void SetCoordinate(GEI32, GEInt);
    void SetLeft(GEI32);
    void SetPoint(bCPoint const &, GEInt);
    void SetRect(tagRECT const &);
    void SetRect(bCRect const &);
    void SetRect(bCPoint const &, bCPoint const &);
    void SetRect(GEI32, GEI32, GEI32, GEI32);
    void SetRect();
    void SetRight(GEI32);
    void SetTop(GEI32);
    void SetTopLeft(bCPoint const &);
    void Shrink(bCRect const &);
    void Shrink(bCPoint const &);
    void Translate(bCPoint const &);
    void Translate(GEI32, GEI32);
    void Widen(bCRect const &);
    void Widen(bCPoint const &);

  private:
    bCPoint m_TopLeft;
    bCPoint m_BottomRight;
};
