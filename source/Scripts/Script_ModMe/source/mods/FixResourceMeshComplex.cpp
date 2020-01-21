#include "Common.h"

namespace
{
    void FixResourceMeshComplex(bCString const & a_strMeshName, bCString const & a_strTargetMeshName, mCFileLogger & a_Logger)
    {
        a_Logger.LogFormat("Fixing %s...\n", a_strMeshName);


        eCResourceDataEntity * pMeshData = FindModule<eCResourceAdmin>()->QueryResourceDataEntity(a_strMeshName, eEResourceCacheBehavior_Immediate);
        if(!pMeshData)
            return a_Logger.LogString("Failed to query resource data entity.\n");

        eCResourceMeshComplex_PS * pMesh = dynamic_cast<eCResourceMeshComplex_PS *>(pMeshData->SearchResourcePropertySet());
        for(GEInt i = 0; i < pMesh->GetMeshResourceCount(); i++)
        {
            a_Logger.PushIndent();
            eCMeshElement * pMeshElement = pMesh->GetMeshElement(i);
            a_Logger.LogFormat("MeshElement %d (%s)\n", i, pMeshElement->GetMaterialName());
            a_Logger.PushIndent();

            a_Logger.LogFormat("Building spatial hierarchy... ");
            {
                GEBool bSuccess = pMeshElement->BuildSpatialHierarchy(GETrue);
                a_Logger.LogString(bSuccess ? "done.\n" : "failed.\n");
            }

            a_Logger.LogFormat("Creating lightmap UV groups... ");
            {
                GEBool bSuccess = pMeshElement->CreateLightmapUVGroups(GETrue);
                a_Logger.LogString(bSuccess ? "done.\n" : "failed.\n");
            }

            a_Logger.PopIndent();
            a_Logger.PopIndent();
        }

        // Save original file name
        bCString strOriginalFileBaseName = pMesh->m_strFileBaseName;

        // Save fixed mesh file
        eCArchiveManager::GetInstance().CreateFileA(a_strTargetMeshName);
        pMesh->m_strFileBaseName = a_strTargetMeshName;
        // Strip file extension (automatically added in DoSave)
        pMesh->m_strFileBaseName.Replace(".xcmsh", "");
        pMesh->DoSave();

        // Restore original file name
        pMesh->m_strFileBaseName = strOriginalFileBaseName;

        return a_Logger.LogString("Done!\n");
    }
}

// Recalculate the spatial hierachy and the lightmap UV groups for eCResourceMeshComplex_PS.
ME_MODULE(FixResourceMeshComplex)
{
    static const GELPCChar ROOT_PATH = "Data/_compiledMesh/FixMe/";

    bTObjArray<bCString> arrFiles;
    eCVirtualFileSystem::GetInstance().FindFiles(ROOT_PATH, arrFiles);

    if(arrFiles.IsEmpty())
        return;

    mCFileLogger & Logger = mCLoggingAdmin<mCFileLogger>::GetLogger("Data\\_compiledMesh\\FixMe\\FixMe.log");
    GE_ARRAY_FOR_EACH(FileName, arrFiles)
    {
        if(!EndsWith(*FileName, ".xcmsh") || EndsWith(*FileName, "_FIXED.xcmsh"))
            continue;

        bCString TargetName = ROOT_PATH + *FileName;
        TargetName.Replace(".xcmsh", "_FIXED.xcmsh");
        FixResourceMeshComplex(*FileName, TargetName, Logger);
    }
}
