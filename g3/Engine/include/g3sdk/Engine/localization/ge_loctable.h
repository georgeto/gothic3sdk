#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCLocTable
{
  public:
    struct SEntry
    {
        bCUnicodeString Text;
        bCUnicodeString StageDirection;
    };

  public:
    eCLocTable(eCLocTable const &);
    explicit eCLocTable(bCString const &);
    eCLocTable();
    ~eCLocTable();

  public:
    eCLocTable &operator=(eCLocTable const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    GEBool ExistsID(bCString const &) const;
    GEBool ExistsString(SEntry const &) const;
    SEntry GetEntry(bCString const &) const;
    bCString const GetID(SEntry const &) const;
    bCString const &GetName() const;
    bCUnicodeString GetStageDirection(bCString const &) const;
    bCUnicodeString GetString(bCString const &) const;
    GEInt GetStringCount() const;
    bTObjMap<bCString, SEntry> const &GetStrings() const;
    void Invalidate();
    void Read(bCIStream &);
    void Write(bCOStream &);

  protected:
    GEBool RemoveID(bCString const &);
    GEBool RenameID(bCString const &, bCString const &);
    void SetName(bCString const &);
    void SetString(bCString const &, SEntry const &);

  private:
    bTObjMap<bCString, SEntry> m_Strings;
    bCString m_Name;
};

GE_ASSERT_SIZEOF(eCLocTable, 0x14)

bCIStream &GE_STDCALL operator>>(bCIStream &, eCLocTable &);
bCOStream &GE_STDCALL operator<<(bCOStream &, eCLocTable &);
bCIStream &GE_STDCALL operator>>(bCIStream &, eCLocTable::SEntry &);
bCOStream &GE_STDCALL operator<<(bCOStream &, eCLocTable::SEntry &);
