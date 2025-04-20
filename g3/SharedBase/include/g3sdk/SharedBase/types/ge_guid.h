#pragma once

#include <SharedBase/container/map/ge_mapbase.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_string.h>
#include <SharedBase/types/ge_types.h>
#include <SharedBase/types/ge_windows.h>

struct _GUID;

class GE_DLLIMPORT bCGuid
{
  public:
    static bCGuid const &GE_STDCALL GetInvalidGuid();
    static bCGuid const &GE_STDCALL GetNullGuid();

  public:
    explicit bCGuid(_GUID const &);
    bCGuid(bCGuid const &);
    explicit bCGuid(bCString const &);
    explicit bCGuid(_GUID const *);
    bCGuid();
    ~bCGuid();

  public:
    explicit operator _GUID &();
    explicit operator _GUID *();
    explicit operator _GUID const &() const;
    explicit operator _GUID const *() const;
    bCGuid &operator=(_GUID const &);
    bCGuid &operator=(bCGuid const &);
    bCGuid &operator=(bCString const &);
    bCGuid &operator=(_GUID const *);
    GEBool operator==(bCGuid const &) const;
    GEBool operator!=(bCGuid const &) const;
    GEBool operator<(bCGuid const &) const;
    GEBool operator<=(bCGuid const &) const;
    GEBool operator>(bCGuid const &) const;
    GEBool operator>=(bCGuid const &) const;

  public:
    void CopyFrom(bCGuid const &);
    void CopyTo(bCGuid &) const;
    void Generate();
    _GUID *GetGuid();
    _GUID const *GetGuid() const;
    bCString GetText() const;
    GEBool IsNull() const;
    GEBool IsValid() const;
    void MakeInvalidGuid();
    void MakeNullGuid();
    void SetGuid(_GUID const &);
    void SetGuid(bCString const &);
    void SetGuid(_GUID const *);
    GEBool SetText(bCString const &);

  protected:
    void Clear();
    GEInt Compare(bCGuid const &) const;
    void Init();
    GEBool IsEqualTo(bCGuid const &) const;
    GEBool IsGreaterThan(bCGuid const &) const;
    GEBool IsLessThan(bCGuid const &) const;

  private:
    _GUID mGuid;
    GEBool mValid;
    GE_PADDING(0x3)
};

GE_ASSERT_SIZEOF(bCGuid, 0x14)

template <>
GE_DLLIMPORT GEU32 GE_STDCALL g_GetHashValue<bCGuid>(bCGuid const &);
