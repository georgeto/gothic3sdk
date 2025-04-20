#pragma once

#include <Game.h>

class GE_DLLIMPORT iCImporterAdmin
{
    // clang-format off
    public: virtual GEBool Create();
    public: virtual void Destroy();
    public: virtual ~iCImporterAdmin();
    // clang-format on

  public:
    iCImporterAdmin(iCImporterAdmin const &);
    iCImporterAdmin();

  public:
    iCImporterAdmin &operator=(iCImporterAdmin const &);

  public:
    void EnableAmbientOcclusion(GEBool);
    void EnableCollisionMeshSkip(GEBool);
    void EnableDynamicEntityWrite(GEBool);
    void EnableEmptyEntitySkip(GEBool);
    void EnableEntityGroupWrite(GEBool);
    void EnableGeomEntityWrite(GEBool);
    void EnableMaterialWrite(GEBool);
    void EnableMeshWrite(GEBool);
    void EnablePureMatrixCorrectPass(GEBool);
    void EnableReplaceOldFiles(GEBool);
    void EnableReplaceOldMaterialFiles(GEBool);
    void EnableReplaceOldMeshFiles(GEBool);
    void EnableStopOnCrash(GEBool);
    void EnableStrippifier(GEBool);
    void EnableUseCellifier(GEBool);
    GEFloat GetAmbientOcclusionShadowSoftnes() const;
    GEBool GetEnableAmbientOcclusion() const;
    GEBool GetEnableCollisionMeshSkip() const;
    GEBool GetEnableDynamicEntityWrite() const;
    GEBool GetEnableEmptyEntitySkip() const;
    GEBool GetEnableEntityGroupWrite() const;
    GEBool GetEnableGeomEntityWrite() const;
    GEBool GetEnableMaterialWrite() const;
    GEBool GetEnableMeshWrite() const;
    GEBool GetEnableReplaceOldFiles() const;
    GEBool GetEnableReplaceOldMaterialFiles() const;
    GEBool GetEnableReplaceOldMeshFiles() const;
    GEBool GetEnableStopOnCrash() const;
    GEBool GetEnableStrippifier() const;
    void GetImagePath(bCString &) const;
    bTObjArray<bCString> const &GetListOfEmptyEntites() const;
    void GetMaterialPath(bCString &) const;
    void(GE_STDCALL *GetMeshConvertCallback() const)(bCString const &);
    void GetMeshPath(bCString &) const;
    GEBool GetPureMatrixCorrectPass() const;
    GEFloat GetScaleFactor() const;
    void GetSpatialLayer(gCGeometryLayer *&) const;
    GEBool GetUseCellifier() const;
    void GetWorld(gCWorld *&) const;
    GEBool ImportFile(bCString);
    void SetAmbientOcclusionShadowSoftnes(GEFloat);
    void SetImagePath(bCString);
    void SetMaterialPath(bCString);
    void SetMeshConvertCallback(void(GE_STDCALL *)(bCString const &));
    void SetMeshPath(bCString);
    void SetScaleFactor(GEFloat);
    void SetSpatialLayer(gCGeometryLayer *);
    void SetWorld(gCWorld *);

  protected:
    GEBool RunAllDynamicEntityPasses(bCString);
    GEBool RunAllEntityGroupPasses(bCString);
    GEBool RunAllGeomEntityPasses(bCString, GEBool);
    GEBool RunAllMaterialPasses(bCString);
    GEBool RunAllMeshPasses(bCString, GEBool);
    GEBool RunAllSplinePasses(bCString);
};
