#ifndef RESOURCECOMPILER_H_INCLUDED
#define RESOURCECOMPILER_H_INCLUDED

#include "SharedBase.h"

namespace ResourceCompiler
{
    GEBool CreateCollisionMesh(bCString const & a_strMeshName, bCString const & a_strColMeshPath, GEBool a_bConvex, bCVector const * a_Scaling = 0);
}

#endif