#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCTrackBitField
{
  public:
    bCTrackBitField(bCTrackBitField const &);
    explicit bCTrackBitField(GEInt Count = 64);
    ~bCTrackBitField();

  public:
    bCTrackBitField &operator=(bCTrackBitField const &);
    bCOStream &operator>>(bCOStream &) const;
    bCTrackBitField const &operator>>(GEI32) const;
    bCIStream &operator<<(bCIStream &);
    bCTrackBitField const &operator<<(GEI32) const;
    GEBool operator==(bCTrackBitField const &) const;
    GEBool operator!=(bCTrackBitField const &) const;
    GEBool operator[](GEInt) const;
    bCTrackBitField const &operator&(bCTrackBitField const &) const;
    bCTrackBitField const &operator~() const;
    bCTrackBitField const &operator^(bCTrackBitField const &) const;
    bCTrackBitField const &operator|(bCTrackBitField const &) const;
    bCTrackBitField &operator>>=(GEI32);
    bCTrackBitField &operator<<=(GEI32);
    bCTrackBitField &operator&=(bCTrackBitField const &);
    bCTrackBitField &operator|=(bCTrackBitField const &);
    bCTrackBitField &operator^=(bCTrackBitField const &);

  public:
    GEU32 *AccessBitField();
    void And(bCTrackBitField const &);
    void CopyFrom(bCTrackBitField const &);
    void CopyTo(bCTrackBitField &) const;
    void Disable(GEInt);
    void DisableAll();
    void Enable(GEInt);
    void EnableAll();
    void ExpandAnd(bCTrackBitField const &);
    void ExpandOr(bCTrackBitField const &);
    void ExpandXor(bCTrackBitField const &);
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
    void Or(bCTrackBitField const &);
    void SetAt(GEInt, GEBool);
    void SetCount(GEInt);
    void ShiftLeft(GEI32);
    void ShiftRight(GEI32);
    void Toggle(GEInt);
    void Xor(bCTrackBitField const &);

  protected:
    static GEU32 const bEBits_All;

  protected:
    GEU32 GetMask(GEInt) const;
    GEInt GetOffset(GEInt) const;
    GEInt GetSlotIndex(GEInt) const;
};
