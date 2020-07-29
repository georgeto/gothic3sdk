#include "World_CompileLightmaps.h"

#include <math.h>

#include "Script.h"
#include "Importer.h"

#include "util/Hook.h"
#include "util/Memory.h"
#include "util/Logging.h"
#include "util/Util.h"

GEBool bEnableAreaCheck = GEFalse;
GEInt iMinGridIndexX, iMaxGridIndexX, iMinGridIndexZ, iMaxGridIndexZ;

GEBool bEnableEntityCheck = GEFalse;
bCBox EntityCompileBox;

// Nur bestimmten Bereich der Welt kompilieren
GEBool GE_STDCALL IsInCompileArea(GEInt a_iCurrentGridIndexX, GEInt a_iCurrentGridIndexZ)
{
    if(!bEnableAreaCheck)
        return GETrue;

    return a_iCurrentGridIndexX >= iMinGridIndexX && a_iCurrentGridIndexX <= iMaxGridIndexX &&
           a_iCurrentGridIndexZ >= iMinGridIndexZ && a_iCurrentGridIndexZ <= iMaxGridIndexZ;
}

const GEInt GRID_CELL_SIZE = 10000;
const GEInt WORLD_RADIUS = 1000000;
const GEInt GRID_COUNT = 199;

GEInt PositionToGridIndex(GEInt a_iPosition)
{
    return GRID_COUNT - ((a_iPosition + WORLD_RADIUS) / GRID_CELL_SIZE);
}


// CurrentGridCell hochzählen


// Remounten von Projects_compiled verhindern
GEBool GE_STDCALL UmountDir( bCString const & )
{
    return GETrue;
}
GEUInt GE_STDCALL MountDir( bCString const &, bCString const &, bTObjArray<bCString> &, GEBool )
{
    return 0;
}

mCFunctionHook HookComputeStaticLightData;
GEBool GE_STDCALL ComputeStaticLightData( eCEntity * a_pEntity , GEBool a_bUnk )
{
    if(bEnableEntityCheck && !EntityCompileBox.Contains(a_pEntity->GetWorldPosition()))
        return GETrue;

    GEBool Result = HookComputeStaticLightData.GetOriginalFunction(&ComputeStaticLightData)(a_pEntity, a_bUnk);
    if(Result && a_pEntity)
    {
        GEBool bUsingLightmap = GEFalse;
        eCVisualMeshBase_PS * pMeshBase = GetPropertySet<eCVisualMeshBase_PS>(a_pEntity, eEPropertySetType_MeshVisual);
        bUsingLightmap = pMeshBase && pMeshBase->GetResourceDataEntity() && pMeshBase->GetStaticLightingType() == eEStaticLighingType_Lightmap;

        eCIlluminated_PS * pIlluminated = GetPropertySet<eCIlluminated_PS>(a_pEntity, eEPropertySetType_Illuminated);
        if(pIlluminated && pIlluminated->GetStaticIlluminated() == eEStaticIlluminated_Static && !bUsingLightmap)
        {
            bCMemoryStream StreamOut;
            StreamOut << a_pEntity->GetName();
            StreamOut << a_pEntity->GetID().GetText();
            StreamOut << pIlluminated->m_uStaticLightCount;
            StreamOut.Write(pIlluminated->m_StaticLightData, sizeof(pIlluminated->m_StaticLightData));
            ToFile(StreamOut, "Data\\StaticLightdata\\" + a_pEntity->GetName() + "_" + a_pEntity->GetID().GetText() + ".sldat");
            mCLoggingAdmin<mCFileLogger>::GetLogger("logs\\StaticLightdata.log").LogFormat("Writing %s_%s_.sldat\n", a_pEntity->GetName(), a_pEntity->GetID().GetText());
        }
    }
    return Result;
}

mCFunctionHook HookComputeStaticLighting;
GEBool GE_STDCALL ComputeStaticLighting( eCEntity * a_pEntity, GEBool a_bUnk1, GEBool a_bUnk2, GEBool a_bUnk3, GEBool a_bUnk4 )
{
    if(bEnableEntityCheck && !EntityCompileBox.Intersects(a_pEntity->GetWorldNodeBoundary()))
        return GETrue;

    return HookComputeStaticLighting.GetOriginalFunction(&ComputeStaticLighting)(a_pEntity, a_bUnk1, a_bUnk2, a_bUnk3, a_bUnk4);
}

void InitHooks()
{
    CreateDirectory("Data\\StaticLightdata", NULL);
    if(!HookComputeStaticLightData.IsValid())
        HookComputeStaticLightData.Prepare(PROC_Engine("?ComputeStaticLightData@eCStaticLightPreprocessor@@QAE_NPAVeCEntity@@_N@Z"), &ComputeStaticLightData, mCBaseHook::mEHookType_ThisCall).Hook();

    if(!HookComputeStaticLighting.IsValid())
        HookComputeStaticLighting.Hook(PROC_Engine("?ComputeStaticLighting@eCStaticLightPreprocessor@@QAE_NPAVeCEntity@@_N111@Z"), &ComputeStaticLighting, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook HookUnmountDir;
    if(!HookUnmountDir.IsValid())
        HookUnmountDir.Hook(RVA_Importer(0x2B02F), &UmountDir, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook HookMountDir;
    if(!HookMountDir.IsValid())
        HookMountDir.Hook(RVA_Importer(0x2B054), &MountDir, mCBaseHook::mEHookType_ThisCall);

    static GEBool s_bAreaHookDone = GEFalse;
    if(!s_bAreaHookDone)
    {
        s_bAreaHookDone = GETrue;
        USE_X86_ASSEMBLER("CompileLightmaps")
        a.mov(ptr(esp, 0x24), eax);
        // IsInCompileArea aufrufen
        a.mov(eax, ptr(esp, 0x44)); //CurrentGridIndexZ
        a.mov(ecx, ptr(esp, 0x48)); //CurrentGridIndexX
        a.push(eax);
        a.push(ecx);
        a.call(imm_ptr(&IsInCompileArea));
        a.test(al, al);
        Label LabelSkipCell = a.newLabel();
        a.jz(LabelSkipCell);
        // Zelle wird bearbeitet
        a.fild(dword_ptr(esp, 0x24));
        a.jmp(RVA_Importer(0x2D1FD));
        // Zelle wird übersprungen
        a.bind(LabelSkipCell);
        a.inc(dword_ptr(esp, 0x38)); //CurrentGridCell erhöhen
        a.jmp(RVA_Importer(0x2D587));

        GELPVoid pCode = JitRuntimeAdd(a);
        a.reset();

        a.setBaseAddress(RVA_Importer(0x2D1F5));
        a.jmp(imm_ptr(pCode));
        G3SCRIPT_ASSERT(WriteAssemblerData(a, 0x8, GETrue, GETrue));
    }
}

bCString CMD_World_Sub::CompileLightmaps( bTObjArray< bCString > a_arrParams )
{
    InitHooks();

    bCString AreaMessage;

    if(a_arrParams.GetCount() >= 2 && a_arrParams.GetCount() <= 4)
    {
        GEInt iMinPositionX, iMaxPositionX, iMinPositionZ, iMaxPositionZ;

        bEnableEntityCheck = GEFalse;

        if(a_arrParams.GetCount() < 4)
        {
            Entity Origin = Entity::GetEntity(a_arrParams[0]);
            if(Origin == None)
                return bCString::GetFormattedString("$Could not find a entity with the name %s.", a_arrParams[0]);

            bCVector Position = Origin.GetPosition();
            GEFloat fEdge = a_arrParams[1].GetFloat(0) / 2;

            iMinPositionX = static_cast<GEInt>(floor((Position.GetX() - fEdge) / 10000) * 10000);
            iMaxPositionX = static_cast<GEInt>(ceil((Position.GetX() + fEdge) / 10000) * 10000);
            iMinPositionZ = static_cast<GEInt>(floor((Position.GetZ() - fEdge) / 10000) * 10000);
            iMaxPositionZ = static_cast<GEInt>(ceil((Position.GetZ() + fEdge) / 10000) * 10000);

            bEnableEntityCheck = GETrue;
            if(a_arrParams.GetCount() == 3)
            {
                float fYCorrection = a_arrParams[2].GetFloat(0);
                Position.AccessY() += fYCorrection;
            }

            bCVector Extent = bCVector(fEdge, fEdge, fEdge);
            EntityCompileBox = bCBox(Position - Extent, Position + Extent);

            AreaMessage += bCString::GetFormattedString("Only Entities within [min: %f/%f/%f//, max: %f/%f/%f//] will be taken into account.\n", EntityCompileBox.GetMin().GetX(), EntityCompileBox.GetMin().GetY(), EntityCompileBox.GetMin().GetZ(), EntityCompileBox.GetMax().GetX(), EntityCompileBox.GetMax().GetY(), EntityCompileBox.GetMax().GetZ());
        }
        else
        {
            iMinPositionX = a_arrParams[0].GetInteger(0, GEFalse);
            iMaxPositionX = a_arrParams[1].GetInteger(0, GEFalse);
            iMinPositionZ = a_arrParams[2].GetInteger(0, GEFalse);
            iMaxPositionZ = a_arrParams[3].GetInteger(0, GEFalse);
        }

        if(iMinPositionX % 10000 || iMaxPositionX % 10000 || iMinPositionZ % 10000 || iMaxPositionZ % 10000)
            return "$Coordinates have to be divisible by 10000.";

        bEnableAreaCheck = GETrue;
        iMinGridIndexX = PositionToGridIndex(iMaxPositionX);
        iMaxGridIndexX = PositionToGridIndex(iMinPositionX);
        iMinGridIndexZ = PositionToGridIndex(iMaxPositionZ);
        iMaxGridIndexZ = PositionToGridIndex(iMinPositionZ);

        AreaMessage += bCString::GetFormattedString("Compiling Lightmaps only for the area (x: %d to %d, z: %d to %d) which is contained in the cells (x: %d to %d, z: %d to %d).\n",
            iMinPositionX, iMaxPositionX, iMinPositionZ, iMaxPositionZ, iMinGridIndexX, iMaxGridIndexX, iMinGridIndexZ, iMaxGridIndexZ);
        GetDefaultLogger().LogString(AreaMessage);
    }

    gCWorld* pWorld = gCWorld::GetCurrentWorld();
    iCSceneCompiler SceneCompiler;
    bEResult Result = SceneCompiler.CompileWorld(pWorld->GetFileBaseName(), iCSceneCompiler::iECompileOptions_CompileLightmaps, GEFalse);

    bEnableAreaCheck = GEFalse;
    if(Result)
        return AreaMessage + "Successfully compiled Lightmaps for " + pWorld->GetFileBaseName();
    else
        return "$" + AreaMessage + "Failed to compile Lightmaps for " + pWorld->GetFileBaseName();
}