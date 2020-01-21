#include "Common.h"

#include "Importer.h"

namespace
{
    GEBool GE_STDCALL SetProprietaryShapes_SupportsNonUniformScaling()
    {
        return GETrue;
    }

    void GE_STDCALL SetProprietaryShapes_ScaleBoxShape(bCVector & This, GEBool const & a_bUniformScaling, GEFloat const & a_fXAxisScale, GEFloat const & a_fYAxisScale, GEFloat const & a_fZAxisScale,  bCVector & a_BoxShapeDimensions, GEFloat)
    {
        if(!a_bUniformScaling)
        {
            This.Scale(bCVector(a_fXAxisScale, a_fYAxisScale, a_fZAxisScale));
            // Revert scaling with a_fXAxisScale applied by original code and apply non uniform scaling
            a_BoxShapeDimensions.m_fY = (a_BoxShapeDimensions.m_fY / a_fXAxisScale) * a_fYAxisScale;
            a_BoxShapeDimensions.m_fZ = (a_BoxShapeDimensions.m_fZ / a_fXAxisScale) * a_fZAxisScale;
        }
        else
            This.Scale(a_fXAxisScale);
    }

    mCCallHook Hook_eCPhysicObject_Create;
    eCResourceDataEntity * GE_STDCALL eCPhysicObject_Create(/*eCCollisionShape * a_pShape@<esi>,*/ bCString const & a_ScaledName, GEFloat const & a_fUniformScaling)
    {
        eCCollisionShape * pShape = Hook_eCPhysicObject_Create.GetEsi<eCCollisionShape *>();
        eCResourceAdmin * pResourceAdmin = FindModule<eCResourceAdmin>();

        if(eCResourceDataEntity * pOriginalColMeshData = pResourceAdmin->QueryResourceDataEntity(a_ScaledName, eEResourceCacheBehavior_3))
            return pOriginalColMeshData;


        eCResourceDataEntity * pOriginalColMeshData = pResourceAdmin->QueryResourceDataEntity(pShape->GetMeshResourceName(), eEResourceCacheBehavior_3);
        if(!pOriginalColMeshData)
        {
            // GE_MESSAGE_WARN( "C: eCPhysicObject::Create(): could not create scaled collision-resource, original resource is missing:  " + pShape->GetMeshResourceName() )
            return 0;
        }

        // Erst danach loggen, da im Falle dass die Originale Resource nicht existiert, der Originale Logging Code ausgeführt wird
        GE_MESSAGE_WARN( "C: eCPhysicObject::Create(): could not cache-in scaled collision-resource, lazy create: " + a_ScaledName );

        eCResourceCollisionMesh_PS * pOriginalColMesh = dynamic_cast<eCResourceCollisionMesh_PS *>(pOriginalColMeshData->SearchResourcePropertySet());
        if(!pOriginalColMesh->IsDataAvailable())
            pOriginalColMeshData->Load(eEResourceCacheBehavior_Immediate);

        eCResourceDataEntity * pScaledColMeshData = pResourceAdmin->QueryNewResourceDataEntity();
        pScaledColMeshData->CreateResourceFromType(bTClassName<eCResourceCollisionMesh_PS>::GetUnmangled());
        eCResourceCollisionMesh_PS * pScaledColMesh = dynamic_cast<eCResourceCollisionMesh_PS *>(pScaledColMeshData->SearchResourcePropertySet());
        pScaledColMesh->CopyWithScaling(*pOriginalColMesh, a_fUniformScaling);

        bCString ScaledFileName;
        eCArchiveManager::GetInstance().SplitPath(a_ScaledName, 0, &ScaledFileName, 0);
        pScaledColMeshData->Save(eCApplication::GetInstance().GetCompiledPhysicPath() + ScaledFileName + g_strResourceMeshCollisionFileExt, eEResourceCacheBehavior_Immediate);
        return pScaledColMeshData;
    }
}

/*
    Fix creation of PhysX box collision shapes for non-uniform scaled entities.
*/
ME_MODULE(CollisionShape)
{
    static mCCallHook Hook_SetProprietaryShapes_SupportsNonUniformScaling;
    Hook_SetProprietaryShapes_SupportsNonUniformScaling.Hook(RVA_Engine(0x17D542), &SetProprietaryShapes_SupportsNonUniformScaling);

    static mCCallHook Hook_SetProprietaryShapes_ScaleBoxShape;
    Hook_SetProprietaryShapes_ScaleBoxShape
        .Prepare(RVA_Engine(0x17EF41), &SetProprietaryShapes_ScaleBoxShape)
        .AddThisArg()
        .AddStackArg(0x3B) // & bUniformScaling
        .AddStackArg(0x30) // & fXAxisScaling
        .AddStackArg(0x70) // & fYAxisScaling
        .AddStackArg(0x6C) // & fZAxisScaling
        .AddStackArg(0x68, mCRegisterBase::mERegisterType_Edi) // & pBoxShape->dimensions
        .Hook();

    static mCCallHook Hook_eCPhysicObject_Create_SupportsNonUniformScaling;
    Hook_eCPhysicObject_Create_SupportsNonUniformScaling.Hook(RVA_Engine(0x162AF1), &SetProprietaryShapes_SupportsNonUniformScaling);

    static mCCallHook Hook_eCPhysicObject_Create_ScaleBoxShape;
    Hook_eCPhysicObject_Create_ScaleBoxShape
        .Prepare(RVA_Engine(0x164753), &SetProprietaryShapes_ScaleBoxShape)
        .AddThisArg()
        .AddStackArg(0x37) // & bUniformScaling
        .AddStackArg(0x38) // & fXAxisScaling
        .AddStackArg(0x68) // & fYAxisScaling
        .AddStackArg(0x70) // & fZAxisScaling
        .AddStackArg(0x68, mCRegisterBase::mERegisterType_Edi) // & pBoxShape->dimensions
        .Hook();

    Hook_eCPhysicObject_Create
        .Prepare(RVA_Engine(0x163FB3), &eCPhysicObject_Create, mCBaseHook::mEHookType_Mixed, mCRegisterBase::mERegisterType_Esi)
        .ReplaceSize(0x13)
        .AddStackArg(0x50)
        .AddStackArg(0x34).Hook();
}
