#ifndef GE_GEOMETRYSPATIALCONTEXT_H_INCLUDED
#define GE_GEOMETRYSPATIALCONTEXT_H_INCLUDED

class GE_DLLIMPORT eCGeometrySpatialContext :
    public eCContextBase
{
    public: using eCContextBase::CopyFrom;
    public: virtual void              CopyFrom( eCGeometrySpatialContext const & );
    public: virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult          Write( bCOStream & );
    public: virtual bEResult          Read( bCIStream & );
    public: virtual void              Destroy( void );
    public: virtual bEResult          Create( void );
    public: virtual                  ~eCGeometrySpatialContext( void );
    public: virtual void              SetGraph( eCNode * );
    public: virtual GEBool            IsProcessing( void ) const;
    public: virtual eCSpatialEntity * CreateSpecificEntity( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCGeometrySpatialContext( eCGeometrySpatialContext const & );
        eCGeometrySpatialContext( void );

    public:
        eCGeometrySpatialContext const & operator = ( eCGeometrySpatialContext const & );

    public:
        void     Activate( void );
        void     CacheIn( void );
        void     CacheOut( void );
        void     Deactivate( void );
        void     EnableHybridContext( GEBool );
        bCString GetFileBaseName( void ) const;
        void     GetFileBaseName( bCString & ) const;
        GEU32    GetNodeFileSize( void ) const;
        GEBool   IsCachedIn( void ) const;
        GEBool   IsHybridContext( void ) const;
        GEBool   IsInvalid( void ) const;
        GEBool   IsLocked( void ) const;
        GEBool   IsSignaledCacheOut( void ) const;
        void     Lock( void );
        void     PurgeRenderHooks( void );
        bEResult ReadNodes( void );
        void     SignalCacheOut( void );
        void     Unlock( void );
        bEResult WriteNodes( void );

    protected:
        void     Invalidate( void );
        bEResult ReadNodesOld( eCArchiveFile &, GEU16 );
        bEResult ReadNodesV56( eCArchiveFile & );
        bEResult ReadNodesV83( eCArchiveFile & );

    private:
        void TraversePurgeRenderHookEntities( eCSpatialEntity * );
        void TraversePurgeRenderHookEntity( eCSpatialEntity & );

};

#endif
