#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCGfxImageData;

class GE_DLLIMPORT eCGfxTextureBlock : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxTextureBlock const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxTextureBlock() override;
    // clang-format on

  public:
    eCGfxTextureBlock(eCGfxTextureBlock const &);
    eCGfxTextureBlock();

  public:
    eCGfxTextureBlock &operator=(eCGfxTextureBlock const &);

  public:
    bEResult AttachImageData(eCGfxImageData *);
    bEResult Execute();
    bEResult GetAlphaCalc(eCGfxShared::eETexOperation &, eCGfxShared::eETexArgument &,
                          eCGfxShared::eETexArgument &) const;
    bEResult GetAttachedImageData(eCGfxImageData *&) const;
    bEResult GetColorCalc(eCGfxShared::eETexOperation &, eCGfxShared::eETexArgument &,
                          eCGfxShared::eETexArgument &) const;
    bEResult GetTextureAdressing(eCGfxShared::eETexAddress &, eCGfxShared::eETexAddress &,
                                 eCGfxShared::eETexAddress &) const;
    bEResult GetTextureCoordCalc(eCGfxShared::eETexCoordCalc &) const;
    bEResult GetTextureCoordIndex(GEU32 &) const;
    bEResult GetTextureCoordTrafo(GEU32 &) const;
    bEResult GetTextureFiltering(eCGfxShared::eETexFilter &, eCGfxShared::eETexFilter &,
                                 eCGfxShared::eETexFilter &) const;
    bEResult GetTextureMatrix(bCMatrix &) const;
    bEResult GetTextureResultArgument(eCGfxShared::eETexArgument &) const;
    bEResult GetUnitNumber(GEU32 &) const;
    void Invalidate();
    bEResult SetAlphaCalc(eCGfxShared::eETexOperation, eCGfxShared::eETexArgument, eCGfxShared::eETexArgument);
    bEResult SetColorCalc(eCGfxShared::eETexOperation, eCGfxShared::eETexArgument, eCGfxShared::eETexArgument);
    bEResult SetTextureAdressing(eCGfxShared::eETexAddress, eCGfxShared::eETexAddress, eCGfxShared::eETexAddress);
    bEResult SetTextureCoordCalc(eCGfxShared::eETexCoordCalc);
    bEResult SetTextureCoordIndex(GEU32);
    bEResult SetTextureCoordTrafo(GEU32);
    bEResult SetTextureFiltering(eCGfxShared::eETexFilter, eCGfxShared::eETexFilter, eCGfxShared::eETexFilter);
    bEResult SetTextureMatrix(bCMatrix const &);
    bEResult SetTextureResultArgument(eCGfxShared::eETexArgument);
    bEResult SetUnitNumber(GEU32);

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxTextureBlock **ms_pActiveTextureBlock;
    static eCGfxTextureBlock **ms_pMasterTextureBlock;
    static void(GE_STDCALL *ms_pRegisterTextureBlockExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxTextureBlock *GE_STDCALL sGetActiveTextureBlock(GEU32);
    static eCGfxTextureBlock *GE_STDCALL sGetMasterTextureBlock(GEU32);
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetMasterTextureBlock(GEU32, eCGfxTextureBlock *);
    static void GE_STDCALL sSetTextureBlockExecuteCallback(void(GE_STDCALL *)());
};
