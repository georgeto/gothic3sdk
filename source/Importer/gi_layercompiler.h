#ifndef GI_LAYERCOMPILER_H_INCLUDED
#define GI_LAYERCOMPILER_H_INCLUDED

struct iSCompileDesc;

class GE_DLLIMPORT iCLayerCompiler
{
    public: virtual ~iCLayerCompiler( void );

    public:
        iCLayerCompiler( iCSectorCompiler & );

    public:
        GEU32  GetCompiledToHybridEntities( void ) const;
        GEU32  GetCompiledToStaticEntities( void ) const;
        GEU32  GetRemovedEntities( void ) const;
        GEU32  GetScannedEntities( void ) const;
        GEBool IsValid( void ) const;
        GEBool Process( bTSmallArray<gCDynamicLayer *> & );

    protected:
        iCLayerCompiler( iCLayerCompiler const & );

    protected:
        GEBool   AddEntityToContext( eCEntity *, eCGeometrySpatialContext & );
        bEResult Create( void );
        void     Destroy( void );
        GEBool   HasHybridPropertysets( eCDynamicEntity * ) const;
        void     Invalidate( void );
        GEBool   IsEntityRemovable( eCDynamicEntity * ) const;
        GEBool   IsolateEntity( eCEntity * );
        GEBool   MoveEntitiesTo( bTSmallArray<eCEntity *> &, eCGeometrySpatialContext * );
        GEBool   ProcessEntities( eCDynamicEntity *, iSCompileDesc & );
        GEBool   ProcessEntity( eCDynamicEntity *, iSCompileDesc & );
        GEBool   RemoveIllegalPropertySets( eCEntity * );

};

#endif
