#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCConfigFile_KeyObject
{
  public:
    eCConfigFile_KeyObject(eCConfigFile_KeyObject &);
    eCConfigFile_KeyObject(bCString const &, bCString const &, bCString const &);
    eCConfigFile_KeyObject(bCString const &, bCString const &);
    explicit eCConfigFile_KeyObject(bCString const &);
    eCConfigFile_KeyObject();
    ~eCConfigFile_KeyObject();

  public:
    eCConfigFile_KeyObject const &operator=(eCConfigFile_KeyObject const &);

  public:
    void Clear();
    void CopyFrom(eCConfigFile_KeyObject const &);
    void Create();
    void Destroy();
    bCString const &GetComment() const;
    bCString const &GetKey() const;
    bCString &GetValue();
    bCString const &GetValue() const;
    GEBool HasKeyOnly() const;
    void Invalidate();
    GEBool IsComment() const;
    GEBool IsEmpty() const;
    void SetComment(bCString const &);
    void SetKey(bCString const &);
    void SetValue(bCString const &);
    void Write(bCOStream &);
};
