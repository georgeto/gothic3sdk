#include "Common.h"

namespace
{
    struct mSAmbientOcclusionFixup
    {
        GEU32 uOffset;
        GEUInt uSize;
        bTObjArray<bTValArray<GEU32>> arrData;
    };

    bTObjArray<mSAmbientOcclusionFixup> AmbientOcclusionFixups;

    mCFunctionHook Hook_eCWrapper_emfx2Actor_ReadAmbientOcclusion;
    void eCWrapper_emfx2Actor_ReadAmbientOcclusion(/*bTObjArray<bTValArray<GEU32>> *o_arrData@<edi>, */bCIStream * a_pInput)
    {
        eCArchiveFile * pArchiveFile = dynamic_cast<eCArchiveFile *>(a_pInput);
        mSAmbientOcclusionFixup & Fixup = AmbientOcclusionFixups.AddNew();
        Fixup.uOffset =  static_cast<GEU32>(pArchiveFile->GetPosition());

        Hook_eCWrapper_emfx2Actor_ReadAmbientOcclusion.GetOriginalFunction(&eCWrapper_emfx2Actor_ReadAmbientOcclusion)(a_pInput);

        Fixup.uSize =  static_cast<GEUInt>(pArchiveFile->GetPosition() - Fixup.uOffset);
    }

    mCFunctionHook Hook_eCWrapper_emfx2Actor_Read;
    bEResult eCWrapper_emfx2Actor_Read(bCIStream * a_pInput)
    {
        bEResult Result = Hook_eCWrapper_emfx2Actor_Read.GetOriginalFunction(&eCWrapper_emfx2Actor_Read)(a_pInput);

        eCWrapper_emfx2Actor * pActor = Hook_eCWrapper_emfx2Actor_Read.GetSelf<eCWrapper_emfx2Actor *>();
        mSAmbientOcclusionFixup & Fixup = AmbientOcclusionFixups.AccessAt(AmbientOcclusionFixups.GetCount() - 1);
        pActor->CalculateAmbientOcclusion(Fixup.arrData, 0.60000002f);

        return Result;
    }

    bCString CalculateAmbientOcclusion(bCString const & a_strActorName, bCString const & a_strTargetActorName)
    {
        AmbientOcclusionFixups.Clear();

        eCResourceDataEntity * pActorData = FindModule<eCResourceAdmin>()->QueryResourceDataEntity(a_strActorName, eEResourceCacheBehavior_Immediate);
        if(!pActorData)
            return "Failed to query resource data entity.";

        eCArchiveFile SrcFile = eCArchiveManager::GetInstance().GetFile(a_strActorName);
        if(!SrcFile.Open(eCArchiveFile::bEArchiveFileAccessMode_Read, GEFalse))
            return "Failed to open source file.";

        eCArchiveFile DstFile = eCArchiveManager::GetInstance().CreateFileA(a_strTargetActorName);
        if(!DstFile.Open(eCArchiveFile::bEArchiveFileAccessMode_Write, GEFalse))
            return "Failed to open destination file.";

        bCMemoryStream Buffer;
        GE_ARRAY_FOR_EACH(Fixup, AmbientOcclusionFixups)
        {
            // Copy unchanged data
            GEUInt uCopySize = static_cast<GEUInt>(Fixup->uOffset - SrcFile.GetPosition());
            Buffer.SetCount(uCopySize);
            SrcFile.Read(Buffer.AccessBuffer(0), uCopySize);
            DstFile.Write(Buffer.GetBuffer(0), uCopySize);

            // Write recalculated ambient occlusion data
            SrcFile.SkipBytes(Fixup->uSize);
            Fixup->arrData >> DstFile;

            if(SrcFile.GetPosition() != DstFile.GetPosition())
                return  bCString::GetFormattedString("Failed because the size of the ambient occlusion data at offset %x has changed.", Fixup->uOffset);
        }

        // Copy unchanged data
        GEUInt uCopySize = static_cast<GEUInt>(SrcFile.GetFileSize() - SrcFile.GetPosition());
        Buffer.SetCount(uCopySize);
        SrcFile.Read(Buffer.AccessBuffer(0), uCopySize);
        DstFile.Write(Buffer.GetBuffer(0), uCopySize);

        SrcFile.Close();
        DstFile.Close();
        return "Done!";
    }
}

// Recalculate the ambient occlusion data for all the LoDs in a eCResourceAnimationActor_PS.
ME_MODULE(FixResourceAnimationActor)
{
    static const GELPCChar ROOT_PATH = "Data/_compiledAnimation/FixMe/";

    bTObjArray<bCString> arrFiles;
    eCVirtualFileSystem::GetInstance().FindFiles(ROOT_PATH, arrFiles);

    if(arrFiles.IsEmpty())
        return;

    Hook_eCWrapper_emfx2Actor_Read.Hook(PROC_Engine("?Read@eCWrapper_emfx2Actor@@UAE?AW4bEResult@@AAVbCIStream@@@Z"), &eCWrapper_emfx2Actor_Read, mCBaseHook::mEHookType_ThisCall);
    Hook_eCWrapper_emfx2Actor_ReadAmbientOcclusion.Hook(RVA_Engine(0x4FFB0), &eCWrapper_emfx2Actor_ReadAmbientOcclusion, mCBaseHook::mEHookType_Mixed, mCRegisterBase::mERegisterType_Edi);


    mCFileLogger & Logger = mCLoggingAdmin<mCFileLogger>::GetLogger("Data\\_compiledAnimation\\FixMe\\FixMe.log");
    GE_ARRAY_FOR_EACH(FileName, arrFiles)
    {
        if(!EndsWith(*FileName, ".xact") || EndsWith(*FileName, "_FIXED.xact"))
            continue;

        Logger.LogFormat("Calculating ambient occlusion for %s...", *FileName);
        bCString TargetName = ROOT_PATH + *FileName;
        TargetName.Replace(".xact", "_FIXED.xact");
        bCString Result = CalculateAmbientOcclusion(*FileName, TargetName);
        Logger.LogFormat("\n  %s\n\n", Result);
    }

    Hook_eCWrapper_emfx2Actor_ReadAmbientOcclusion.~mCFunctionHook();
    Hook_eCWrapper_emfx2Actor_Read.~mCFunctionHook();
}
