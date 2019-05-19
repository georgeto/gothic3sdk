#ifndef GI_MESHIMPORTER_H_INCLUDED
#define GI_MESHIMPORTER_H_INCLUDED

class GE_DLLIMPORT iCMeshImporter
{
    public: virtual void   Destroy( void );
    public: virtual GEBool Create( void );
    public: virtual GEBool CopyFrom( iCMeshImporter const & );
    public: virtual       ~iCMeshImporter( void );

    public:
        iCMeshImporter( iCMeshImporter const & );
        iCMeshImporter( void );

    public:
        iCMeshImporter & operator = ( iCMeshImporter const & );

    public:
        GEBool           Cellifier( bCString const &, gCGeometryLayer * );
        void             FillImportMeshValues( void );
        void             FillImportSceneValues( GEBool );
        void             FillStandardValues( void );
        GEFloat          GetAOShadowSoftness( void ) const;
        GEBool           GetCalculateAmbientOcclusion( void ) const;
        GEFloat          GetCellSize( void ) const;
        bCString const & GetCellifiedMeshName( void ) const;
        GEBool           GetCellifierEnabled( void ) const;
        GEBool           GetFixScaling( void ) const;
        bCString const & GetImageFilePath( void ) const;
        bCString const & GetImportFilePath( void ) const;
        bCString const & GetLayerName( void ) const;
        bCString const & GetMaterialFilePath( void ) const;
        GEBool           GetMaterialWrite( void ) const;
        bCString const & GetMeshFilePath( void ) const;
        GEBool           GetMeshWrite( void ) const;
        GEBool           GetReplaceOldMaterialFiles( void ) const;
        GEBool           GetReplaceOldMeshFiles( void ) const;
        GEFloat          GetScaleFactor( void ) const;
        gCSector *       GetSector( void ) const;
        GEBool           GetSkipCollisionMeshes( void ) const;
        GEBool           GetWriteStaticEntities( void ) const;
        GEBool           Process( void );
        GEBool           ProcessMeshOnly( void );
        void             SetAOShadowSoftness( GEFloat );
        void             SetCalculateAmbientOcclusion( GEBool );
        void             SetCellSize( GEFloat );
        void             SetCellifiedMeshName( bCString const & );
        void             SetCellifierEnable( GEBool );
        void             SetFixScaling( GEBool );
        void             SetImageFilePath( bCString const & );
        void             SetImportFilePath( bCString const & );
        void             SetLayerName( bCString const & );
        void             SetMaterialFilePath( bCString const & );
        void             SetMaterialWrite( GEBool );
        void             SetMeshFilePath( bCString const & );
        void             SetMeshWrite( GEBool );
        void             SetReplaceOldMaterialFiles( GEBool );
        void             SetReplaceOldMeshFiles( GEBool );
        void             SetScaleFactor( GEFloat );
        void             SetSector( gCSector * );
        void             SetSkipCollisionMeshes( GEBool );
        void             SetWriteStaticEntities( GEBool );

    protected:
        GEBool                     CollectCellEntities( eCEntity *, bTPtrArray<eCEntity *> & );
        eLoDMesh::eCProgMeshData * CollectMeshes( bTPtrArray<eCEntity *> const &, GEBool );
        eCEntity *                 CreateVisualEntity( eCEntity *, bCString const &, GEBool );
        void                       Invalidate( void );

};

#endif
