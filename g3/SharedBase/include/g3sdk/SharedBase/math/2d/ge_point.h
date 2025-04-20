#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;
struct tagPOINT;

class GE_DLLIMPORT bCPoint
{
  public:
    explicit bCPoint(tagPOINT const &);
    bCPoint(bCPoint const &);
    bCPoint(GEI32, GEI32);
    bCPoint();
    ~bCPoint();

  public:
    explicit operator tagPOINT &();
    explicit operator tagPOINT *();
    explicit operator tagPOINT const &() const;
    explicit operator tagPOINT const *() const;
    bCPoint const &operator=(tagPOINT const &);
    bCPoint const &operator=(bCPoint const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCPoint const &) const;
    GEBool operator!=(bCPoint const &) const;
    GEI32 &operator[](GEInt);
    GEI32 operator[](GEInt) const;
    bCPoint operator*(GEFloat) const;
    bCPoint operator-(bCPoint const &) const;
    bCPoint operator-() const;
    bCPoint operator+(bCPoint const &) const;
    bCPoint const &operator+() const;
    bCPoint operator/(GEFloat) const;
    bCPoint &operator*=(GEFloat);
    bCPoint const &operator+=(bCPoint const &);
    bCPoint const &operator-=(bCPoint const &);
    bCPoint &operator/=(GEFloat);

  public:
    GEI32 &AccessX();
    GEI32 &AccessY();
    void Clear();
    bCPoint GetInvScaled(GEFloat) const;
    bCPoint GetScaled(GEFloat) const;
    GEI32 GetX() const;
    void GetX(GEI32 &) const;
    GEI32 GetY() const;
    void GetY(GEI32 &) const;
    void InvScale(GEFloat);
    void InvTranslate(bCPoint const &);
    void InvTranslate(GEI32, GEI32);
    void Scale(GEFloat);
    void SetPoint(tagPOINT const &);
    void SetPoint(bCPoint const &);
    void SetPoint(GEI32, GEI32);
    void SetX(GEI32);
    void SetY(GEI32);
    void Translate(bCPoint const &);
    void Translate(GEI32, GEI32);

  private:
    GEI32 m_iX;
    GEI32 m_iY;
};
