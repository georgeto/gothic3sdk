#include "ResourceCompiler.h"

#include "Common.h"

namespace
{
    void CreateCollisionMeshFromCommandLine()
    {
        bCCommandLine CommandLine(eCApplication::GetInstance().GetCommandLineA());
        bTStringObjMap<bCString> const & Options = CommandLine.GetOptions();

        if(Options.IsValidKey("cmin"))
        {
            bCString strMeshName = Options.GetAt("cmin");

            // ConvexHull
            GEBool bConvex = GEFalse;
            if(Options.IsValidKey("convex"))
                bConvex = Options.GetAt("convex").GetBool();

            // Skalierung
            bCVector Scaling(1.0f, 1.0f, 1.0f);
            if(Options.IsValidKey("scale"))
            {
                GEFloat fScaling = Options.GetAt("scale").GetFloat();
                Scaling = bCVector(fScaling, fScaling, fScaling);
            }
            else
            {
                if(Options.IsValidKey("scalex"))
                    Scaling.SetX(Options.GetAt("scalex").GetFloat());

                if(Options.IsValidKey("scaley"))
                    Scaling.SetY(Options.GetAt("scaley").GetFloat());

                if(Options.IsValidKey("scalez"))
                    Scaling.SetZ(Options.GetAt("scalez").GetFloat());
            }

            // CollisionMesh
            bCString strColMeshPath = "";
            if(Options.IsValidKey("cmout"))
                strColMeshPath = Options.GetAt("cmout");
            else
            {
                strColMeshPath = "Data/_compiledPhysic/" + strMeshName;
                strColMeshPath.Replace(".xcmsh", bConvex ? "_CV.xnvmsh" : ".xnvmsh");
            }

            ResourceCompiler::CreateCollisionMesh(strMeshName, strColMeshPath, bConvex, &Scaling);
        }
    }
}

namespace ResourceCompiler
{
    GEBool CreateCollisionMesh(bCString const & a_strMeshName, bCString const & a_strColMeshPath, GEBool a_bConvex, bCVector const * a_Scaling)
    {
        eCResourceAdmin * pResourceAdmin = dynamic_cast< eCResourceAdmin * >( eCModuleAdmin::GetInstance().FindModule( "eCResourceAdmin" ) );
        eCResourceDataEntity * pMeshData = pResourceAdmin->QueryResourceDataEntity(a_strMeshName, eEResourceCacheBehavior_Immediate);
        eCResourceDataEntity * pColShapeData = pResourceAdmin->QueryNewResourceDataEntity();
        if(pMeshData && pColShapeData)
        {
            pColShapeData->CreateResourceFromType(bTClassName<eCResourceCollisionMesh_PS>::GetUnmangled());
            GEBool bUniformScaling = GETrue;
            GEFloat fUniformScaling = 1.0f;
            bCString strColMeshPath = a_strColMeshPath;

            // Nur konvexe Collision Meshes müssen skaliert werden
            if(a_Scaling) {
                if(a_Scaling->GetX() == a_Scaling->GetY() && a_Scaling->GetX() == a_Scaling->GetZ()) {
                    fUniformScaling = a_Scaling->GetX();

                    if(fUniformScaling != 1.0f)
                    {
                        bCString prefix = bCString::GetFormattedString("_SC_%.4f", fUniformScaling);
                        prefix.SetAt(5, '_');
                        strColMeshPath.Replace(".xnvmsh", prefix + ".xnvmsh");
                    }
                }
                else
                {
                    // Erstmal Collision Mesh mit einer Skalierung von 1.0f erstellen und danach Kopie mit der richtigen Skalierung erzeugen.
                    bUniformScaling = GEFalse;

                    bCString prefixX = bCString::GetFormattedString("_SCX_%.4f", a_Scaling->GetX());
                    prefixX.SetAt(6, '_');
                    bCString prefixY = bCString::GetFormattedString("_SCY_%.4f", a_Scaling->GetY());
                    prefixY.SetAt(6, '_');
                    bCString prefixZ = bCString::GetFormattedString("_SCZ_%.4f", a_Scaling->GetZ());
                    prefixZ.SetAt(6, '_');
                    strColMeshPath.Replace(".xnvmsh", prefixX + prefixY + prefixZ + ".xnvmsh");
                }
            }

            eCResourceCollisionMesh_PS * pTempColShape = dynamic_cast<eCResourceCollisionMesh_PS *>(pColShapeData->SearchResourcePropertySet());
            if(pTempColShape)
            {
                pTempColShape->Compute(pMeshData, a_bConvex, 0, 0, 1.0f); //Test ResolveMaterials difference

                // Apply Scale
                eCResourceDataEntity * pScaledColShapeData = pResourceAdmin->QueryNewResourceDataEntity();
                pScaledColShapeData->CreateResourceFromType(bTClassName<eCResourceCollisionMesh_PS>::GetUnmangled());
                eCResourceCollisionMesh_PS * pScaledColShape = dynamic_cast<eCResourceCollisionMesh_PS *>(pScaledColShapeData->SearchResourcePropertySet());
                if(!pScaledColShape)
                    return GEFalse;

                // ConvexHull hat immer nur ein SubMesh (zumindest in den Originaldaten)
                // Wenn CopyWithScaling für ein Mesh mit n SubMeshes aufgerufen wird, haben die IndexedBoundarys fälschlicherweise ein Scaling von scaling^n,
                // da die Berechnung in jedem Schleifendurchlauf ausgeführt wird. Gilt auch für alle anderen Berechnungen?!
                if(bUniformScaling)
                    pScaledColShape->CopyWithScaling(*pTempColShape, fUniformScaling);
                else
                    pScaledColShape->CopyWithScaling(*pTempColShape, a_Scaling->GetX(), a_Scaling->GetY(), a_Scaling->GetZ());

                return pScaledColShape->GetEntity()->Save(strColMeshPath, eEResourceCacheBehavior_Immediate) == bEResult_Ok;
            }
        }
        return GEFalse;
    }
}

ME_MODULE(ResourceCompiler)
{
    CreateCollisionMeshFromCommandLine();
}
