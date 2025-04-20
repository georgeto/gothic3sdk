#pragma once

#include <Engine/EngineEnum.h>

#include <SharedBase.h>

class eCVertexStructArrayBase;

struct eSVertexStreamArrayToStructMap
{
    GE_UNIMPL_STRUCT(eSVertexStreamArrayToStructMap)
};

class GE_DLLIMPORT eCVertexStreamFactory
{
  public:
    static eSVertexStreamArrayToStructMap const *const ms_arrVertexStreamToStructMap;

  public:
    static eCVertexStreamFactory &GE_STDCALL GetInstance();

  public:
    eCVertexStreamFactory();

  public:
    eCVertexStreamFactory &operator=(eCVertexStreamFactory const &);

  public:
    eCVertexStructArrayBase *Create(GEU32);
    eCVertexStructArrayBase *Create(eEVertexStreamArrayType);
    eCVertexStructArrayBase const *GetTemplate(eEVertexStreamArrayType);
    GEInt GetVertexStreamArrayCount() const;
    eEVertexStreamArrayType GetVertexStreamArrayTypeFromFVF(GEU32) const;
    GEBool IsValidIndex(eEVertexStreamArrayType);
    eCVertexStructArrayBase *Read(bCIStream &);
};
