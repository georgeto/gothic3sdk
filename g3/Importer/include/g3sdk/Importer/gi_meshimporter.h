#pragma once

#include <Game.h>

class GE_DLLIMPORT iCMeshImporter
{
    // clang-format off
    public: virtual void Destroy();
    public: virtual GEBool Create();
    public: virtual GEBool CopyFrom(iCMeshImporter const &);
    public: virtual ~iCMeshImporter();
    // clang-format on

  public:
    iCMeshImporter(iCMeshImporter const &);
    iCMeshImporter();

  public:
    iCMeshImporter &operator=(iCMeshImporter const &);

  public:
    GEBool Cellifier(bCString const &, gCGeometryLayer *);
    void FillImportMeshValues();
    void FillImportSceneValues(GEBool);
    void FillStandardValues();
    GEFloat GetAOShadowSoftness() const;
    GEBool GetCalculateAmbientOcclusion() const;
    GEFloat GetCellSize() const;
    bCString const &GetCellifiedMeshName() const;
    GEBool GetCellifierEnabled() const;
    GEBool GetFixScaling() const;
    bCString const &GetImageFilePath() const;
    bCString const &GetImportFilePath() const;
    bCString const &GetLayerName() const;
    bCString const &GetMaterialFilePath() const;
    GEBool GetMaterialWrite() const;
    bCString const &GetMeshFilePath() const;
    GEBool GetMeshWrite() const;
    GEBool GetReplaceOldMaterialFiles() const;
    GEBool GetReplaceOldMeshFiles() const;
    GEFloat GetScaleFactor() const;
    gCSector *GetSector() const;
    GEBool GetSkipCollisionMeshes() const;
    GEBool GetWriteStaticEntities() const;
    GEBool Process();
    GEBool ProcessMeshOnly();
    void SetAOShadowSoftness(GEFloat);
    void SetCalculateAmbientOcclusion(GEBool);
    void SetCellSize(GEFloat);
    void SetCellifiedMeshName(bCString const &);
    void SetCellifierEnable(GEBool);
    void SetFixScaling(GEBool);
    void SetImageFilePath(bCString const &);
    void SetImportFilePath(bCString const &);
    void SetLayerName(bCString const &);
    void SetMaterialFilePath(bCString const &);
    void SetMaterialWrite(GEBool);
    void SetMeshFilePath(bCString const &);
    void SetMeshWrite(GEBool);
    void SetReplaceOldMaterialFiles(GEBool);
    void SetReplaceOldMeshFiles(GEBool);
    void SetScaleFactor(GEFloat);
    void SetSector(gCSector *);
    void SetSkipCollisionMeshes(GEBool);
    void SetWriteStaticEntities(GEBool);

  protected:
    GEBool CollectCellEntities(eCEntity *, bTPtrArray<eCEntity *> &);
    eLoDMesh::eCProgMeshData *CollectMeshes(bTPtrArray<eCEntity *> const &, GEBool);
    eCEntity *CreateVisualEntity(eCEntity *, bCString const &, GEBool);
    void Invalidate();
};
