#pragma once

#include <SharedBase/container/array/ge_objarray.h>
#include <SharedBase/container/map/ge_stringmap.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_string.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCCommandLine
{
  public:
    bCCommandLine(bCCommandLine const &);
    explicit bCCommandLine(bCString const &);
    bCCommandLine();
    ~bCCommandLine();

  public:
    bCCommandLine &operator=(bCCommandLine const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(bCCommandLine const &);
    void CopyTo(bCCommandLine &) const;
    GEBool Create(bCString const &);
    void Destroy();
    bTObjArray<bCString> const &GetArguments() const;
    void GetArguments(bTObjArray<bCString> &) const;
    bTStringObjMap<bCString> const &GetOptions() const;
    void GetOptions(bTStringObjMap<bCString> &) const;
    GEBool Read(bCIStream &);
    void Write(bCOStream &);

  protected:
    static GEBool GE_STDCALL SkipOption(bCString &, bCString &, bCString &);
    static GEBool GE_STDCALL SkipOptionDelimiter(bCString &);
    static GEBool GE_STDCALL SkipValue(bCString &, bCString &);
    static GEBool GE_STDCALL SkipValue(bCString &, bCString &, GELPCChar);
    static GEBool GE_STDCALL SkipValueDelimiter(bCString &);
    static GEInt GE_STDCALL SkipWordDelimiters(bCString &);

  protected:
    bTObjArray<bCString> &AccessArguments();
    bTStringObjMap<bCString> &AccessOptions();
    GEInt InsertArgument(bCString const &);
    GEBool InsertOption(bCString const &, bCString const &);
    GEBool InsertOption(bCString const &);
    void Invalidate();
    GEBool ParseArgument(bCString &);
    GEBool ParseOption(bCString &);
    void SetArguments(bTObjArray<bCString> const &);
    void SetOptions(bTStringObjMap<bCString> const &);

  private:
    bTStringObjMap<bCString> m_mapOptions; // 0000
    bTObjArray<bCString> m_arrArguments;   // 0010
};
