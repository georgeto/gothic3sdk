#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCLocString
{
  public:
    eCLocString(eCLocString const &);
    explicit eCLocString(bCString const &);
    explicit eCLocString(eCLocString const *);
    eCLocString();
    ~eCLocString();

  public:
    operator bCUnicodeString const() const;
    eCLocString &operator=(eCLocString const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  public:
    bCString const &GetID() const;
    bCUnicodeString const GetStageDirection(bCString const &) const;
    bCUnicodeString const GetStageDirection() const;
    bCUnicodeString const GetString(bCString const &) const;
    bCUnicodeString const GetString() const;
    void Read(bCIStream &);
    void SetID(bCString const &);
    void Write(bCOStream &) const;

  private:
    bCString id;
};

GE_ASSERT_SIZEOF(eCLocString, 0x4)

bCIStream &GE_STDCALL operator>>(bCIStream &, eCLocString &);
bCOStream &GE_STDCALL operator<<(bCOStream &, eCLocString const &);
