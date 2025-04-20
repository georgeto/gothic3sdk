#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>
#include <SharedBase/types/ge_windows.h>

class bCString;

class GE_DLLIMPORT bCDateTime
{
  public:
    explicit bCDateTime(_FILETIME const &);
    bCDateTime(bCDateTime const &);
    bCDateTime();
    explicit bCDateTime(GEU64);
    ~bCDateTime();

  public:
    explicit operator _FILETIME();
    explicit operator _FILETIME const() const;
    bCDateTime const &operator=(_FILETIME const &);
    bCDateTime const &operator=(bCDateTime const &);
    GEBool operator==(bCDateTime const &) const;
    GEBool operator!=(bCDateTime const &) const;
    bCDateTime operator-(bCDateTime const &) const;
    bCDateTime operator+(bCDateTime const &) const;
    GEBool operator<(bCDateTime const &) const;
    GEBool operator<=(bCDateTime const &) const;
    GEBool operator>(bCDateTime const &) const;
    GEBool operator>=(bCDateTime const &) const;
    bCDateTime const &operator+=(bCDateTime const &);
    bCDateTime const &operator-=(bCDateTime const &);

  public:
    GEU64 &AccessDateTime();
    void Add(bCDateTime const &);
    void CopyFrom(bCDateTime const &);
    void CopyTo(bCDateTime &) const;
    void GetDateString(bCString &) const;
    void GetDateTime(GEU64 &) const;
    GEU64 GetDateTime() const;
    void GetShortDateString(bCString &) const;
    void GetTimeString(bCString &) const;
    void SetDateTime(_FILETIME const &);
    void SetDateTime(GEU64);
    void Sub(bCDateTime const &);
    void Update();

  protected:
    void Clear();
    void Init();

  private:
    GEU64 m_u64DateTime;
};
