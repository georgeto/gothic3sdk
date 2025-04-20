#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCUnicodeString;

class GE_DLLIMPORT bCString
{
  protected:
    struct bSStringData
    {
        GEU32 m_u32Length;
        GEU32 m_u32RefCount;
        GELPChar m_pcText;
    };

  public:
    static bCString GE_CCALL GetFormattedString(GELPCChar, ...);

  public:
    bCString(bCString const &);
    bCString(bCString const &, GEInt);
    explicit bCString(bCUnicodeString const &);
    bCString(GEChar, GEInt);
    bCString(GEFloat, GEInt);
    bCString(GELPCChar);
    bCString(GELPCChar, GEInt);
    bCString();
    ~bCString();

  public:
    operator GELPCChar() const;
    bCString &operator=(bCString const &);
    bCString &operator=(GEChar);
    bCString &operator=(GELPCChar);
    GEBool operator==(bCString const &) const;
    GEBool operator==(GELPCChar) const;
    GEBool operator!=(bCString const &) const;
    GEBool operator!=(GELPCChar) const;
    GEChar &operator[](GEInt);
    GEChar operator[](GEInt) const;
    bCString operator+(bCString const &) const;
    bCString operator+(GEChar) const;
    bCString operator+(GELPCChar) const;
    GEBool operator<(bCString const &) const;
    GEBool operator<(GELPCChar) const;
    GEBool operator<=(bCString const &) const;
    GEBool operator<=(GELPCChar) const;
    GEBool operator>(bCString const &) const;
    GEBool operator>(GELPCChar) const;
    GEBool operator>=(bCString const &) const;
    GEBool operator>=(GELPCChar) const;
    bCString &operator+=(bCString const &);
    bCString &operator+=(GEChar);
    bCString &operator+=(GELPCChar);

  public:
    void Clear();
    GEInt Compare(bCString const &) const;
    GEInt Compare(GELPCChar) const;
    GEBool CompareFast(bCString const &) const;
    GEInt CompareNoCase(bCString const &) const;
    GEInt CompareNoCase(GELPCChar) const;
    GEBool CompareNoCaseFast(bCString const &) const;
    GEBool Contains(GEChar a_chPattern, GEInt a_iOffset = 0) const;
    GEBool Contains(GELPCChar a_strPattern, GEInt a_iOffset = 0) const;
    GEBool ContainsOneOf(GELPCChar, GEInt) const;
    GEInt CountWords(bCString const &a_strDelimiters) const;
    GEInt Delete(GEInt, GEInt);
    GEInt Find(GEChar a_chPattern, GEInt a_iOffset = 0, GEBool a_bUnicode = GEFalse) const;
    GEInt Find(GELPCChar a_strPattern, GEInt a_iOffset = 0, GEBool a_bUnicode = GEFalse) const;
    GEInt FindNoCase(GELPCChar a_strPattern, GEInt a_iOffset = 0) const;
    GEInt FindNoiseChar(GEInt, GEBool) const;
    GEInt FindNumericalChar(GEInt, GEBool) const;
    GEInt FindOneOf(GELPCChar, GEInt) const;
    GEBool GE_CCALL Format(GELPCChar, ...);
    void FreeExtra();
    GEInt GetAllocLength() const;
    GEChar GetAt(GEInt a_iOffset, GEBool __UNUSED__ = GEFalse) const;
    GEBool GetBool() const;
    GELPChar GetBuffer(GEInt);
    GELPChar GetBufferSetLength(GEInt);
    GEDouble GetDouble(GEInt a_iOffset = 0) const;
    GEFloat GetFloat(GEInt a_iOffset = 0) const;
    GEI64 GetI64(GEInt a_iOffset = 0) const;
    GEInt GetInteger(GEInt a_iOffset = 0, GEBool a_bUnsafe = GEFalse) const;
    GEInt GetLength() const;
    GELPCChar GetText() const;
    bCUnicodeString GetUnicodeText() const;
    GEInt GetWord(GEInt a_iWordNumber, bCString const &a_strDelimiters, bCString &o_strDestString, GEBool a_bTrimLeft,
                  GEBool a_bTrimRight) const;
    GEInt Insert(GEInt, bCString const &);
    GEInt Insert(GEInt, GEChar);
    GEInt Insert(GEInt, GELPCChar);
    GEBool IsEmpty() const;
    bCString Left(GEInt) const;
    GELPChar LockBuffer();
    bCString &MakeLower();
    void MakeReverse();
    bCString &MakeUpper();
    bCString Mid(GEInt) const;
    bCString Mid(GEInt, GEInt) const;
    void ReleaseBuffer(GEInt);
    GEInt Remove(bCString const &);
    GEInt Remove(GEChar);
    GEInt Remove(GELPCChar);
    GEInt Replace(GEChar, GEChar);
    GEInt Replace(GELPCChar, GELPCChar);
    GEInt ReverseFind(GEChar) const;
    GEInt ReverseFind(GEChar, GEInt) const;
    GEInt ReverseFind(GELPCChar) const;
    GEInt ReverseFind(GELPCChar, GEInt) const;
    GEInt ReverseFindOneOf(GELPCChar) const;
    GEInt ReverseFindOneOf(GELPCChar, GEInt) const;
    bCString Right(GEInt) const;
    void SetAt(GEInt, GEChar);
    void SetText(bCString const &);
    void SetText(bCString const &, GEInt);
    void SetText(GEChar, GEInt);
    void SetText(GELPCChar);
    void SetText(GELPCChar, GEInt);
    void SetUnicodeText(bCUnicodeString const &);
    void SetUnicodeText(bCUnicodeString const &, GEInt);
    void SetUnicodeText(GELPCUnicodeChar);
    void SetUnicodeText(GELPCUnicodeChar, GEInt);
    bCString SpanExcluding(GELPCChar) const;
    bCString SpanIncluding(GELPCChar) const;
    void ToLower();
    void ToUpper();
    void Trim(GEChar);
    void Trim(GELPCChar);
    void Trim();
    void Trim(GEBool, GEBool);
    void TrimLeft(GEChar);
    void TrimLeft(GELPCChar);
    void TrimLeft();
    void TrimRight(GEChar);
    void TrimRight(GELPCChar);
    void TrimRight();
    void UnlockBuffer();

  protected:
    static GEInt GE_STDCALL Decrement(bSStringData *);
    static void GE_STDCALL FreeData(bSStringData *);
    static void GE_STDCALL Increment(bSStringData *);
    static void GE_STDCALL Release(bSStringData *);

  protected:
    void Alloc(GEInt);
    void ConcatCopy(GELPCChar, GEInt, GELPCChar, GEInt);
    void ConcatInPlace(GELPCChar, GEInt);
    void CopyBeforeWrite();
    void CopyUnicode(GELPCUnicodeChar, GEInt);
    void Decrement();
    void FreeData();
    bSStringData *GetData() const;
    GEInt GetRefCount() const;
    void Realloc(GEInt);
    void Release();

  private:
    GELPChar m_pcText;
};

GEBool GE_STDCALL operator==(GELPCChar, bCString const &);
GEBool GE_STDCALL operator!=(GELPCChar, bCString const &);
bCString GE_STDCALL operator+(GEChar, bCString const &);
bCString GE_STDCALL operator+(GELPCChar, bCString const &);
GEBool GE_STDCALL operator<(GELPCChar, bCString const &);
GEBool GE_STDCALL operator<=(GELPCChar, bCString const &);
GEBool GE_STDCALL operator>(GELPCChar, bCString const &);
GEBool GE_STDCALL operator>=(GELPCChar, bCString const &);

GE_DLLIMPORT_EXTC bCString const g_strDefault;
