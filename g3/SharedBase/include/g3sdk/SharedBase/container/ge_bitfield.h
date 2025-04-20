#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCBitField
{
  public:
    bCBitField(bCBitField const &);
    explicit bCBitField(GEInt Count = 64);
    ~bCBitField();

  public:
    bCBitField &operator=(bCBitField const &);
    bCOStream &operator>>(bCOStream &) const;
    bCBitField const &operator>>(GEI32) const;
    bCIStream &operator<<(bCIStream &);
    bCBitField const &operator<<(GEI32) const;
    GEBool operator==(bCBitField const &) const;
    GEBool operator!=(bCBitField const &) const;
    GEBool operator[](GEInt) const;
    bCBitField const &operator&(bCBitField const &) const;
    bCBitField const &operator~() const;
    bCBitField const &operator^(bCBitField const &) const;
    bCBitField const &operator|(bCBitField const &) const;
    bCBitField &operator>>=(GEI32);
    bCBitField &operator<<=(GEI32);
    bCBitField &operator&=(bCBitField const &);
    bCBitField &operator|=(bCBitField const &);
    bCBitField &operator^=(bCBitField const &);

  public:
    GEU32 *AccessBitField();
    void And(bCBitField const &);
    void CopyFrom(bCBitField const &);
    void CopyTo(bCBitField &) const;
    void Disable(GEInt);
    void DisableAll();
    void Enable(GEInt);
    void EnableAll();
    void ExpandAnd(bCBitField const &);
    void ExpandOr(bCBitField const &);
    void ExpandXor(bCBitField const &);
    GEBool GetAt(GEInt) const;
    GEInt GetCapacity() const;
    GEInt GetCount() const;
    GEInt GetCountDisabled() const;
    GEInt GetCountEnabled() const;
    GEInt GetFirstDisabled() const;
    GEInt GetFirstEnabled() const;
    GEInt GetNextDisabled() const;
    GEInt GetNextEnabled() const;
    GEInt GetUpperBound() const;
    void Invert();
    GEBool IsAnyDisabled() const;
    GEBool IsAnyEnabled() const;
    GEBool IsDisabled(GEInt) const;
    GEBool IsEmpty() const;
    GEBool IsEnabled(GEInt) const;
    GEBool IsValidIndex(GEInt) const;
    void Or(bCBitField const &);
    void SetAt(GEInt, GEBool);
    void SetCount(GEInt);
    void ShiftLeft(GEI32);
    void ShiftRight(GEI32);
    void Toggle(GEInt);
    void Xor(bCBitField const &);

  protected:
    static GEU32 const bEBits_All;

  protected:
    GEU32 GetMask(GEInt) const;
    GEInt GetOffset(GEInt) const;
    GEInt GetSlotIndex(GEInt) const;
};
