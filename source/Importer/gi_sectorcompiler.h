#ifndef GI_SECTORCOMPILER_H_INCLUDED
#define GI_SECTORCOMPILER_H_INCLUDED

class GE_DLLIMPORT iCSectorCompiler
{
    public: virtual ~iCSectorCompiler( void );

    public:
        iCSectorCompiler( gCSector * );

    public:
        iCSectorCompiler & operator = ( iCSectorCompiler const & );

    public:
        GEU32  GetCompiledToHybridEntities( void ) const;
        GEU32  GetCompiledToStaticEntities( void ) const;
        GEU32  GetRemovedEntities( void ) const;
        GEU32  GetScannedEntities( void ) const;
        GEBool IsValid( void ) const;
        GEBool Process( void );
        void   SetLowPolyLayer( gCGeometryLayer * );
        void   SetLowPolyMasterEntity( eCDynamicEntity * );

    protected:
        iCSectorCompiler( iCSectorCompiler const & );
        iCSectorCompiler( void );

    protected:
        void                       CheckEntitiesForLowPoly( eCEntity * );
        void                       CheckEntityForLowPoly( eCEntity * );
        void                       CheckEntityForSpeedTree( eCEntity * );
        bEResult                   Create( gCSector * );
        GEBool                     CreateHybridLayer( void );
        void                       Destroy( void );
        eCGeometrySpatialContext & GetDefaultContext( void );
        eCGeometrySpatialContext * GetHybridContext( void );
        void                       Invalidate( void );

};

#endif
