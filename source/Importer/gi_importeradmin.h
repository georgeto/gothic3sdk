#ifndef GI_IMPORTERADMIN_H_INCLUDED
#define GI_IMPORTERADMIN_H_INCLUDED

class GE_DLLIMPORT iCImporterAdmin
{
    public: virtual GEBool Create( void );
    public: virtual void   Destroy( void );
    public: virtual       ~iCImporterAdmin( void );

    public:
        iCImporterAdmin( iCImporterAdmin const & );
        iCImporterAdmin( void );

    public:
        iCImporterAdmin & operator = ( iCImporterAdmin const & );

    public:
        void                         EnableAmbientOcclusion( GEBool );
        void                         EnableCollisionMeshSkip( GEBool );
        void                         EnableDynamicEntityWrite( GEBool );
        void                         EnableEmptyEntitySkip( GEBool );
        void                         EnableEntityGroupWrite( GEBool );
        void                         EnableGeomEntityWrite( GEBool );
        void                         EnableMaterialWrite( GEBool );
        void                         EnableMeshWrite( GEBool );
        void                         EnablePureMatrixCorrectPass( GEBool );
        void                         EnableReplaceOldFiles( GEBool );
        void                         EnableReplaceOldMaterialFiles( GEBool );
        void                         EnableReplaceOldMeshFiles( GEBool );
        void                         EnableStopOnCrash( GEBool );
        void                         EnableStrippifier( GEBool );
        void                         EnableUseCellifier( GEBool );
        GEFloat                      GetAmbientOcclusionShadowSoftnes( void ) const;
        GEBool                       GetEnableAmbientOcclusion( void ) const;
        GEBool                       GetEnableCollisionMeshSkip( void ) const;
        GEBool                       GetEnableDynamicEntityWrite( void ) const;
        GEBool                       GetEnableEmptyEntitySkip( void ) const;
        GEBool                       GetEnableEntityGroupWrite( void ) const;
        GEBool                       GetEnableGeomEntityWrite( void ) const;
        GEBool                       GetEnableMaterialWrite( void ) const;
        GEBool                       GetEnableMeshWrite( void ) const;
        GEBool                       GetEnableReplaceOldFiles( void ) const;
        GEBool                       GetEnableReplaceOldMaterialFiles( void ) const;
        GEBool                       GetEnableReplaceOldMeshFiles( void ) const;
        GEBool                       GetEnableStopOnCrash( void ) const;
        GEBool                       GetEnableStrippifier( void ) const;
        void                         GetImagePath( bCString & ) const;
        bTObjArray<bCString> const & GetListOfEmptyEntites( void ) const;
        void                         GetMaterialPath( bCString & ) const;
        void          ( GE_STDCALL * GetMeshConvertCallback( void ) const )( bCString const & );
        void                         GetMeshPath( bCString & ) const;
        GEBool                       GetPureMatrixCorrectPass( void ) const;
        GEFloat                      GetScaleFactor( void ) const;
        void                         GetSpatialLayer( gCGeometryLayer * & ) const;
        GEBool                       GetUseCellifier( void ) const;
        void                         GetWorld( gCWorld * & ) const;
        GEBool                       ImportFile( bCString );
        void                         SetAmbientOcclusionShadowSoftnes( GEFloat );
        void                         SetImagePath( bCString );
        void                         SetMaterialPath( bCString );
        void                         SetMeshConvertCallback( void ( GE_STDCALL* )( bCString const & ));
        void                         SetMeshPath( bCString );
        void                         SetScaleFactor( GEFloat );
        void                         SetSpatialLayer( gCGeometryLayer * );
        void                         SetWorld( gCWorld * );

    protected:
        GEBool RunAllDynamicEntityPasses( bCString );
        GEBool RunAllEntityGroupPasses( bCString );
        GEBool RunAllGeomEntityPasses( bCString, GEBool );
        GEBool RunAllMaterialPasses( bCString );
        GEBool RunAllMeshPasses( bCString, GEBool );
        GEBool RunAllSplinePasses( bCString );

};

#endif
