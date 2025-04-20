#pragma once

#include <Engine/localization/ge_loctable.h>

#include <SharedBase.h>

class eCLocString;

class GE_DLLIMPORT eCLocAdmin
{
  public:
    static eCLocAdmin &GE_STDCALL GetInstance();

  public:
    eCLocAdmin(eCLocAdmin const &);

  public:
    eCLocAdmin &operator=(eCLocAdmin const &);

  public:
    GEBool AddLanguage(bCString const &);
    GEBool AddReference(bCString const &);
    GEBool AddReference(eCLocString *);
    bCString AddString(bCString const &, eCLocTable::SEntry const &, bCString const &);
    bCString AddString(bCString const &, eCLocTable::SEntry const &);
    GEBool AreIDsEqual(bCString const &, bCString const &) const;
    GEBool Create();
    void Destroy();
    GEBool DuplicateID(bCString const &, bCString const &);
    GEBool ExistsID(bCString const &) const;
    GEBool ExistsLanguage(bCString const &) const;
    GEBool ExistsString(eCLocTable::SEntry &) const;
    GEBool ExistsString(eCLocTable::SEntry &, bCString const &) const;
    bCString FindLanguage(GEInt) const;
    GEInt FindLanguageIndex(bCString const &) const;
    bCString const &GetCurrentAudioLanguage() const;
    bCString const &GetCurrentLanguage() const;
    GEUInt const &GetCurrentRevision() const;
    eCLocTable::SEntry const GetEntry(bCString const &, bCString const &) const;
    eCLocTable::SEntry const GetEntry(bCString const &) const;
    bCString GetID(eCLocTable::SEntry &) const;
    bCString GetID(eCLocTable::SEntry &, bCString const &) const;
    GEInt GetIDCount() const;
    GEBool GetIDList(bTObjArray<bCString> &) const;
    GEInt GetLanguageCount() const;
    eCLocTable const &GetLocTable(bCString const &);
    bCString GetNewID(bCString const &) const;
    GEU32 GetReferenceCount(bCString const &) const;
    GEU32 GetReferenceCount() const;
    GEUInt GetRevision(bCString const &) const;
    bCUnicodeString const GetStageDirection(bCString const &, bCString const &) const;
    bCUnicodeString const GetStageDirection(bCString const &) const;
    bCUnicodeString const GetString(bCString const &, bCString const &) const;
    bCUnicodeString const GetString(bCString const &) const;
    bCString GetStringTableFile() const;
    bTObjMap<bCString, eCLocTable> const &GetTables() const;
    void Invalidate();
    GEBool IsModified() const;
    GEBool IsReadOnly() const;
    GEBool Read(bCString const &a_strPath, GEBool a_bExtend);
    GEBool Read();
    GEBool ReadBinary(bCString const &a_strPath);
    GEBool ReadCSV(bCString const &a_strPath, GEBool a_bExtend);
    GEBool RemoveDuplicateID(bCString const &);
    GEBool RemoveDuplicateIDs();
    GEBool RemoveID(bCString const &);
    GEBool RemoveLanguage(bCString const &);
    GEBool RemoveReference(bCString const &);
    GEBool RemoveReference(eCLocString *);
    GEU32 RemoveUnusedIDs();
    GEBool RenameID(bCString const &, bCString const &);
    GEBool ReserveString(bCString const &, eCLocTable::SEntry const &, bCString const &);
    GEBool ReserveString(bCString const &, eCLocTable::SEntry const &);
    void SetCurrentAudioLanguage(bCString const &);
    void SetCurrentLanguage(bCString const &);
    void SetCurrentRevision(GEUInt const &);
    GEBool SetString(bCString const &key, eCLocTable::SEntry const &entry, bCString const &lang);
    GEBool SetString(bCString const &key, eCLocTable::SEntry const &entry);
    GEBool Write(bCString const &) const;
    GEBool Write() const;
    void WriteBinary(bCString const &);
    GEBool WriteCSV(bCString const &) const;

  protected:
    eCLocAdmin();
    ~eCLocAdmin();

  protected:
    GEBool ReadASCII(bCString const &a_strPath, GEBool a_bExtend);
    GEBool ReadUnicode(bCString const &a_strPath, GEBool a_bExtend);
};
