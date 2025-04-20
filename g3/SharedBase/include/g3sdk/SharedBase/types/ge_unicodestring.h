#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCString;

class GE_DLLIMPORT bCUnicodeString
{
  protected:
    struct bSUnicodeStringData;

  public:
    static bCUnicodeString GE_CCALL GetFormattedString(GELPCUnicodeChar, ...);

  public:
    bCUnicodeString(bCUnicodeString const &);
    bCUnicodeString(bCUnicodeString const &, GEInt);
    explicit bCUnicodeString(GEInt);
    explicit bCUnicodeString(GEI32);
    explicit bCUnicodeString(GEU32);
    bCUnicodeString(GEFloat, GEInt);
    bCUnicodeString(GELPCChar);
    bCUnicodeString(GELPCChar, GEInt);
    bCUnicodeString(GELPCUnicodeChar);
    bCUnicodeString(GELPCUnicodeChar, GEInt);
    bCUnicodeString();
    bCUnicodeString(GEUnicodeChar, GEInt);
    ~bCUnicodeString();

  public:
    operator GELPUnicodeChar();
    operator GELPCUnicodeChar() const;
    bCUnicodeString &operator=(bCUnicodeString const &);
    bCUnicodeString &operator=(GELPCChar);
    bCUnicodeString &operator=(GELPCUnicodeChar);
    bCUnicodeString &operator=(GEUnicodeChar);
    GEBool operator==(bCUnicodeString const &) const;
    GEBool operator==(GELPCUnicodeChar) const;
    GEBool operator!=(bCUnicodeString const &) const;
    GEBool operator!=(GELPCUnicodeChar) const;
    GEUnicodeChar &operator[](GEInt);
    GEUnicodeChar operator[](GEInt) const;
    bCUnicodeString operator+(bCUnicodeString const &) const;
    bCUnicodeString operator+(GELPCUnicodeChar) const;
    bCUnicodeString operator+(GEUnicodeChar) const;
    GEBool operator<(bCUnicodeString const &) const;
    GEBool operator<(GELPCUnicodeChar) const;
    GEBool operator<=(bCUnicodeString const &) const;
    GEBool operator<=(GELPCUnicodeChar) const;
    GEBool operator>(bCUnicodeString const &) const;
    GEBool operator>(GELPCUnicodeChar) const;
    GEBool operator>=(bCUnicodeString const &) const;
    GEBool operator>=(GELPCUnicodeChar) const;
    bCUnicodeString &operator+=(bCUnicodeString const &);
    bCUnicodeString &operator+=(GELPCUnicodeChar);
    bCUnicodeString &operator+=(GEUnicodeChar);

  public:
    void Clear();
    GEInt Compare(bCUnicodeString const &) const;
    GEInt Compare(GELPCUnicodeChar) const;
    GEInt CompareNoCase(bCUnicodeString const &) const;
    GEInt CompareNoCase(GELPCUnicodeChar) const;
    GEBool Contains(GELPCUnicodeChar, GEInt) const;
    GEBool Contains(GEUnicodeChar, GEInt) const;
    GEBool ContainsOneOf(GELPCUnicodeChar, GEInt) const;
    GEInt CountWords(bCUnicodeString const &) const;
    GEInt Delete(GEInt, GEInt);
    GEInt Find(GELPCUnicodeChar, GEInt) const;
    GEInt Find(GEUnicodeChar, GEInt) const;
    GEInt FindOneOf(GELPCUnicodeChar, GEInt) const;
    void GE_CCALL Format(GELPCUnicodeChar, ...);
    void FreeExtra();
    GEInt GetAllocLength() const;
    bCString GetAnsiText() const;
    bCString GetAsHexCodedString() const;
    GEUnicodeChar GetAt(GEInt) const;
    GEBool GetBool() const;
    GELPUnicodeChar GetBuffer(GEInt);
    GELPUnicodeChar GetBufferSetLength(GEInt);
    GEDouble GetDouble() const;
    GEFloat GetFloat() const;
    GEInt GetInteger() const;
    GEInt GetLength() const;
    GELPUnicodeChar GetText();
    GELPCUnicodeChar GetText() const;
    GEInt GetWord(GEInt a_iWordNumber, bCUnicodeString const &a_strDelimiters, bCUnicodeString &o_strDestString,
                  GEBool a_bTrimLeft = GETrue, GEBool a_bTrimRight = GETrue) const;
    GEInt Insert(GEInt, bCUnicodeString const &);
    GEInt Insert(GEInt, GELPCUnicodeChar);
    GEInt Insert(GEInt, GEUnicodeChar);
    GEBool IsAnsiText() const;
    GEBool IsEmpty() const;
    bCUnicodeString Left(GEInt) const;
    GELPUnicodeChar LockBuffer();
    void MakeLower();
    void MakeReverse();
    void MakeUpper();
    bCUnicodeString Mid(GEInt) const;
    bCUnicodeString Mid(GEInt, GEInt) const;
    void ReleaseBuffer(GEInt);
    GEInt Remove(GELPCUnicodeChar);
    GEInt Remove(GEUnicodeChar);
    GEInt Replace(GELPCUnicodeChar, GELPCUnicodeChar);
    GEInt Replace(GEUnicodeChar, GEUnicodeChar);
    GEInt ReverseFind(GELPCUnicodeChar) const;
    GEInt ReverseFind(GELPCUnicodeChar, GEInt) const;
    GEInt ReverseFind(GEUnicodeChar) const;        // !!! Implementation is not working !!!
    GEInt ReverseFind(GEUnicodeChar, GEInt) const; // !!! Implementation is not working !!!
    GEInt ReverseFindOneOf(GELPCUnicodeChar) const;
    GEInt ReverseFindOneOf(GELPCUnicodeChar, GEInt) const;
    bCUnicodeString Right(GEInt) const;
    void SetAnsiText(bCString const &);
    void SetAnsiText(bCString const &, GEInt);
    void SetAnsiText(GELPCChar);
    void SetAnsiText(GELPCChar, GEInt);
    void SetAt(GEInt, GEUnicodeChar);
    GEBool SetFromHexCodedString(bCString const &);
    void SetText(bCUnicodeString const &);
    void SetText(bCUnicodeString const &, GEInt);
    void SetText(GELPCUnicodeChar);
    void SetText(GELPCUnicodeChar, GEInt);
    void SetText(GEUnicodeChar, GEInt);
    bCUnicodeString SpanExcluding(GELPCUnicodeChar) const;
    bCUnicodeString SpanIncluding(GELPCUnicodeChar) const;
    void ToLower();
    void ToUpper();
    void Trim(GELPCUnicodeChar);
    void Trim();
    void Trim(GEBool, GEBool);
    void Trim(GEUnicodeChar);
    void TrimLeft(GELPCUnicodeChar);
    void TrimLeft();
    void TrimLeft(GEUnicodeChar);
    void TrimRight(GELPCUnicodeChar);
    void TrimRight();
    void TrimRight(GEUnicodeChar);
    void UnlockBuffer();

  protected:
    static GEInt GE_STDCALL Decrement(bSUnicodeStringData *);
    static void GE_STDCALL FreeData(bSUnicodeStringData *);
    static void GE_STDCALL Increment(bSUnicodeStringData *);
    static void GE_STDCALL Release(bSUnicodeStringData *);

  protected:
    void Alloc(GEInt);
    void ConcatCopy(GELPCUnicodeChar, GEInt, GELPCUnicodeChar, GEInt);
    void ConcatInPlace(GELPCUnicodeChar, GEInt);
    void CopyAnsi(GELPCChar, GEInt);
    void CopyBeforeWrite();
    bSUnicodeStringData *GetData() const;
    GEInt GetRefCount() const;
    void Realloc(GEInt);
    void Release();

  private:
    GELPUnicodeChar m_pwText;
};

GEBool GE_STDCALL operator==(GELPCUnicodeChar, bCUnicodeString const &);
GEBool GE_STDCALL operator!=(GELPCUnicodeChar, bCUnicodeString const &);
bCUnicodeString GE_STDCALL operator+(GELPCUnicodeChar, bCUnicodeString const &);
bCUnicodeString GE_STDCALL operator+(GEUnicodeChar, bCUnicodeString const &);
GEBool GE_STDCALL operator<(GELPCUnicodeChar, bCUnicodeString const &);
GEBool GE_STDCALL operator<=(GELPCUnicodeChar, bCUnicodeString const &);
GEBool GE_STDCALL operator>(GELPCUnicodeChar, bCUnicodeString const &);
GEBool GE_STDCALL operator>=(GELPCUnicodeChar, bCUnicodeString const &);
