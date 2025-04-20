#pragma once

#include <Engine/ge_configfile_sectionobject.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCConfigFile
{
  public:
    struct eSConfigValue
    {
        bCString *m_pstrKey;
        bCString *m_pstrValue;
    };
    GE_ASSERT_SIZEOF(eSConfigValue, 0x0008)

    // clang-format off
    protected: virtual GEBool ReadFile(bCIStream &);
    // clang-format on

  public:
    eCConfigFile(eCConfigFile const &);
    explicit eCConfigFile(bCString const &);
    eCConfigFile();
    ~eCConfigFile();

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);
    bCString &operator()(bCString const &, bCString const &);
    bCString const &operator()(bCString const &, bCString const &) const;

  public:
    void AddComment(bCString const &);
    void AddEmptyLine();
    void Clear();
    GEBool Contains(bCString const &, bCString const &) const;
    GEBool Contains(bCString const &) const;
    void CopyFrom(eCConfigFile const &);
    void Create();
    void Destroy();
    GEBool GetBool(bCString const &, bCString const &) const;
    GEBool GetBool(bCString const &, bCString const &, GEBool) const;
    bCString const &GetFilePath() const;
    GEFloat GetFloat(bCString const &, bCString const &) const;
    GEFloat GetFloat(bCString const &, bCString const &, GEFloat) const;
    GEI16 GetI16(bCString const &, bCString const &) const;
    GEI16 GetI16(bCString const &, bCString const &, GEI16) const;
    GEI32 GetI32(bCString const &, bCString const &) const;
    GEI32 GetI32(bCString const &, bCString const &, GEI32) const;
    GEI8 GetI8(bCString const &, bCString const &) const;
    GEI8 GetI8(bCString const &, bCString const &, GEI8) const;
    GEInt GetInt(bCString const &, bCString const &) const;
    GEInt GetInt(bCString const &, bCString const &, GEInt) const;
    bTObjArray<eCConfigFile_SectionObject> &GetSectionArray();
    bTObjArray<eCConfigFile_SectionObject> const &GetSectionArray() const;
    GEBool GetSectionBlock(bCString, bTObjArray<eSConfigValue> &) const;
    GEBool GetSections(bTObjArray<bCString> &) const;
    bCString &GetString(bCString const &, bCString const &, bCString const &) const;
    bCString &GetString(bCString const &, bCString const &) const;
    GEU16 GetU16(bCString const &, bCString const &) const;
    GEU16 GetU16(bCString const &, bCString const &, GEU16) const;
    GEU32 GetU32(bCString const &, bCString const &) const;
    GEU32 GetU32(bCString const &, bCString const &, GEU32) const;
    GEU8 GetU8(bCString const &, bCString const &) const;
    GEU8 GetU8(bCString const &, bCString const &, GEU8) const;
    bCString &GetValue(bCString const &, bCString const &);
    bCString const &GetValue(bCString const &, bCString const &) const;
    GEBool GetValue(bCString const &, bCString const &, GEI8 &) const;
    GEBool GetValue(bCString const &, bCString const &, GEU8 &) const;
    GEBool GetValue(bCString const &, bCString const &, GEI16 &) const;
    GEBool GetValue(bCString const &, bCString const &, GEU16 &) const;
    GEBool GetValue(bCString const &, bCString const &, GEInt &) const;
    GEBool GetValue(bCString const &, bCString const &, GEI32 &) const;
    GEBool GetValue(bCString const &, bCString const &, GEU32 &) const;
    GEBool GetValue(bCString const &, bCString const &, GEFloat &) const;
    GEBool GetValue(bCString const &, bCString const &, GEDouble &) const;
    GEBool GetValue(bCString const &, bCString const &, bCString &) const;
    GEBool GetValue(bCString const &, bCString const &, GEBool &) const;
    void Invalidate();
    GEBool IsOpen() const;
    GEBool ReadFile(bCString const &);
    GEBool RemoveKey(bCString const &, bCString const &);
    GEBool RemoveSection(bCString const &);
    GEBool RemoveValue(bCString const &, bCString const &);
    GEBool SetSection(bCString const &, bCString const &);
    GEBool SetSection(bCString const &);
    GEBool SetValue(bCString const &, bCString const &, bCString const &);
    GEBool SetValue(bCString const &, bCString const &, GEI8);
    GEBool SetValue(bCString const &, bCString const &, GEU8);
    GEBool SetValue(bCString const &, bCString const &, GEI16);
    GEBool SetValue(bCString const &, bCString const &, GEU16);
    GEBool SetValue(bCString const &, bCString const &, GEInt);
    GEBool SetValue(bCString const &, bCString const &, GEI32);
    GEBool SetValue(bCString const &, bCString const &, GEU32);
    GEBool SetValue(bCString const &, bCString const &, GEFloat);
    GEBool SetValue(bCString const &, bCString const &, GEDouble);
    GEBool SetValue(bCString const &, bCString const &, GEBool);
    GEBool Sort();
    GEBool Update();
    GEBool WriteFile(bCString const &);
    GEBool WriteFile();

  protected:
    eCConfigFile const &operator=(eCConfigFile const &);

  protected:
    eCConfigFile_SectionObject *AccessSection(bCString const &);

  protected:
    bCString m_strFilePath;
    bTObjArray<eCConfigFile_SectionObject> m_arrSectionArray;
    GEBool m_bValid;
    GE_PADDING(0x3)
};

GE_ASSERT_SIZEOF(eCConfigFile, 0x18)
