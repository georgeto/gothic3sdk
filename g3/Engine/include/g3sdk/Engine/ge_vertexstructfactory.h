#pragma once

#include <SharedBase.h>

class eCVertexStructArrayBase;

enum eEVertexTypeStruct
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCVertexStructFactory
{
  public:
    static eCVertexStructFactory &GE_STDCALL GetInstance();

  public:
    eCVertexStructFactory(eCVertexStructFactory const &);
    eCVertexStructFactory();
    ~eCVertexStructFactory();

  public:
    eCVertexStructFactory &operator=(eCVertexStructFactory const &);

  public:
    eCVertexStructArrayBase *Create(eEVertexTypeStruct);
    eCVertexStructArrayBase *Read(bCIStream &);
    GEBool Register(eCVertexStructArrayBase &, eEVertexTypeStruct);

  protected:
    eCVertexStructArrayBase const *GetTemplate(eEVertexTypeStruct);
};
