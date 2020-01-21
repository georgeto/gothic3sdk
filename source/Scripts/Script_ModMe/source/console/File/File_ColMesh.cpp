#include "File_ColMesh.h"

#include "Script.h"
#include "mods/ResourceCompiler.h"
#include "util/Util.h"

namespace
{
    bCString CreateCollisionMesh( bTObjArray< bCString > const & a_arrParams, GEBool a_bConvex )
    {
        bCString strMeshName = a_arrParams[0];
        bCString strColMeshPath = "Data/_compiledPhysic/" + strMeshName;
        if(a_bConvex)
            strColMeshPath.Replace(".xcmsh", "_CV.xnvmsh");
        else
            strColMeshPath.Replace(".xcmsh", ".xnvmsh");

        bCVector Scaling(1.0f, 1.0f, 1.0f);
        if(a_arrParams.GetCount() == 2)
        {
            GEFloat fScaling = a_arrParams[1].GetFloat();
            Scaling = bCVector(fScaling, fScaling, fScaling);
        }
        else if(a_arrParams.GetCount() == 4)
        {
            Scaling.SetX(a_arrParams[1].GetFloat());
            Scaling.SetY(a_arrParams[2].GetFloat());
            Scaling.SetZ(a_arrParams[3].GetFloat());
        }

        GELPCChar strMeshType = a_bConvex ? "ConvexHull" : "TriMesh";
        if(ResourceCompiler::CreateCollisionMesh(strMeshName, strColMeshPath, a_bConvex, &Scaling))
            return bCString::GetFormattedString( "Created %s CollisionMesh '%s' for the mesh '%s' with scaling %.4f/%.4f/%.4f.", strMeshType, strColMeshPath, strMeshName, Scaling.GetX(), Scaling.GetY(), Scaling.GetZ() );

        return bCString::GetFormattedString( "$Creation of %s CollisionMesh '%s' for the mesh '%s' failed.", strMeshType, strColMeshPath, strMeshName );
    }
}

bCString CMD_File_Sub::ColMeshTriMesh( bTObjArray< bCString > a_arrParams )
{
    return CreateCollisionMesh(a_arrParams, GEFalse);
}

bCString CMD_File_Sub::ColMeshConvexHull( bTObjArray< bCString > a_arrParams )
{
    return CreateCollisionMesh(a_arrParams, GETrue);
}
