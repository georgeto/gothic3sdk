#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT gCAttribCondDesc
{
  public:
    enum EOperation
    {
        // TODO: Enumerator values
    };

  public:
    gCAttribCondDesc();
    ~gCAttribCondDesc();

  public:
    gCAttribCondDesc &operator=(gCAttribCondDesc const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void Create(GEInt, EOperation, GEInt);
    GEBool DoesSatisfy(GEInt, GEInt) const;
    GEInt GetArg() const;
    GEInt GetAttrib() const;
    bCUnicodeString GetDesc(GEBool) const;
    EOperation GetOp() const;
    void SetArg(GEInt);
    void SetAttrib(GEInt);
    void SetOp(EOperation);
};
