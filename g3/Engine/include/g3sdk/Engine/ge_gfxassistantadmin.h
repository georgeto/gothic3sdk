#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCGfxImageData;
class eCGfxIndexData;
class eCGfxVertexData;

class GE_DLLIMPORT eCGfxAssistantAdmin : public bCObjectRefBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxAssistantAdmin() override;
    // clang-format on

  public:
    eCGfxAssistantAdmin(eCGfxAssistantAdmin const &);

  public:
    eCGfxAssistantAdmin &operator=(eCGfxAssistantAdmin const &);

  public:
    bEResult AssembleProgram(bCString const &, GEU32);
    bEResult AssembleProgramFromFile(bCString const &);
    bEResult BeginOcclusionTest(GELPVoid const) const;
    bEResult CompileEffect(eCGfxShared::eSGfxEffectSource const &);
    bEResult CompileEffectFromFile(eCGfxShared::eSGfxEffectFileSource const &);
    bEResult ComputeNormalMap(eCGfxImageData &, eCGfxImageData &, eCGfxShared::eENormalMapGen, eCGfxShared::eEChannel,
                              GEFloat) const;
    bEResult CopyCurrentRTToImage(eCGfxImageData &, eCGfxShared::eETexFilter, bCRect *, bCRect *) const;
    bEResult CopyImageToCurrentRT(eCGfxImageData &, eCGfxShared::eETexFilter, bCRect *, bCRect *) const;
    bEResult CreateBox(eCGfxShared::eSGfxBoxData const &, eCGfxVertexData &, eCGfxIndexData &) const;
    bEResult CreateCylinder(eCGfxShared::eSGfxCylinderData const &, eCGfxVertexData &, eCGfxIndexData &) const;
    bEResult CreateImageFromFile(eCGfxImageData &, eCGfxShared::eEPoolType, bCString const &, GEUInt) const;
    bEResult CreateImageFromMemory(eCGfxImageData &, eCGfxShared::eEPoolType, GELPVoid const, GEUInt, GEUInt) const;
    bEResult CreateOcclusionQuery(GELPVoid &) const;
    bEResult CreatePolygon(eCGfxShared::eSGfxPolygonData const &, eCGfxVertexData &, eCGfxIndexData &) const;
    bEResult CreateSphere(eCGfxShared::eSGfxSphereData const &, eCGfxVertexData &, eCGfxIndexData &) const;
    bEResult CreateTeapot(eCGfxVertexData &, eCGfxIndexData &) const;
    bEResult CreateText(eCGfxShared::eSGfxTextData const &, eCGfxVertexData &, eCGfxIndexData &) const;
    bEResult CreateTorus(eCGfxShared::eSGfxTorusData const &, eCGfxVertexData &, eCGfxIndexData &) const;
    bEResult CreateUVAtlas(bTValArray<bCVector> const &, bTValArray<GEU32> &, bTValArray<bCVector2> &,
                           bTValArray<GEU32> &, bTValArray<GEU32> &, GEFloat);
    bEResult DestroyOcclusionQuery(GELPVoid const) const;
    bEResult DrawTextA(bCString const &, GEU32, bCRect const &) const;
    bEResult EndOcclusionTest(GELPVoid const) const;
    bEResult FillImageFromFile(eCGfxImageData &, eCGfxShared::eSGfxLayersDesc &, bCString const &) const;
    bEResult FillImageFromFile(eCGfxImageData &, bCString const &) const;
    bEResult FillImageFromMemory(eCGfxImageData &, eCGfxShared::eSGfxLayersDesc &, GELPVoid const, GEUInt) const;
    bEResult FillImageFromMemory(eCGfxImageData &, GELPVoid const, GEUInt) const;
    bEResult GenerateLODMesh(eCGfxVertexData &, eCGfxIndexData &, eCGfxShared::eSGfxAttributeWeigths const &,
                             bTValArray<GEFloat> const *, GEU32, eCGfxVertexData &, eCGfxIndexData &, GEBool) const;
    bEResult GenerateMipMaps(eCGfxImageData &, GEUInt, eCGfxShared::eECopyFilter) const;
    bEResult GetAuxBuffer(eCGfxShared::eEAuxBufferType, GELPVoid *, GEU32 &) const;
    bEResult GetMethodSupport(eCGfxShared::eSGfxAssistantMethods &) const;
    bEResult GetOcclusionTestInfo(GELPVoid const, GEU32 &, GEBool) const;
    void Invalidate();
    bEResult LoadSurfaceFromSurface(eCGfxImageData *, GEUInt, GELPCVoid, bCRect const *, eCGfxImageData *, GEUInt,
                                    GELPCVoid, bCRect const *, GEU32, GEU32) const;
    bEResult PreprocessShader(eCGfxShared::eSGfxHLSLShaderSrc const &, bCString &) const;
    bEResult SaveImageToFile(eCGfxImageData *, bCString const &) const;
    bEResult SaveImageToMemory(eCGfxImageData *, bCMemoryStream &) const;

  protected:
    eCGfxAssistantAdmin();
};
