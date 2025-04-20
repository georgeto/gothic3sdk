#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT gCAttribModDesc
{
  public:
    enum EOperation
    {
        // TODO: Enumerator values
    };

  public:
    gCAttribModDesc();
    ~gCAttribModDesc();

  public:
    gCAttribModDesc &operator=(gCAttribModDesc const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(gCAttribModDesc const &) const;

  public:
    void Apply(GEInt &, GEInt &) const;
    void ApplyMax(GEInt &) const;
    void ApplyVal(GEInt &, GEInt) const;
    void Create(GEInt, EOperation, GEInt);
    GEInt GetArg() const;
    GEInt GetAttrib() const;
    bCUnicodeString GetAttribDesc(GEBool) const;
    bCUnicodeString GetDesc(GEBool, GEBool) const;
    EOperation GetOp() const;
    void SetArg(GEInt);
    void SetAttrib(GEInt);
    void SetOp(EOperation);
};
