#ifndef FILE_COLSHAPE_H_INCLUDED
#define FILE_COLSHAPE_H_INCLUDED

#include "../m_commandhandler.h"

namespace CMD_File_Sub
{
    bCString ColMeshTriMesh( bTObjArray< bCString > a_arrParams );
    bCString ColMeshConvexHull( bTObjArray< bCString > a_arrParams );
}

#endif