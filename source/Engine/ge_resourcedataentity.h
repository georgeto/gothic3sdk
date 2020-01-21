#ifndef GE_RESOURCEDATAENTITY_H_INCLUDED
#define GE_RESOURCEDATAENTITY_H_INCLUDED

class GE_DLLIMPORT eCResourceDataEntity :
    public eCNode
{
    public:    virtual GEBool                 AddPropertySet( eCResourceBase_PS * );
    public:    virtual GEU16                  GetVersion( void ) const;
    public:    virtual GEBool                 IsValid( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult               Write( bCOStream & );
    public:    virtual bEResult               Read( bCIStream & );
    public:    virtual void                   Destroy( void );
    public:    virtual bEResult               Create( void );
    public:    virtual bEResult               CopyFrom( bCObjectBase const & );
    public:    virtual GEU32                  AddReference( void );
    public:    virtual GEU32                  ReleaseReference( void );
    protected: virtual                       ~eCResourceDataEntity( void );
    public:    virtual eCResourceDataEntity * DoClone( void ) const;

    public:
        eCResourceDataEntity const & operator =                         ( eCResourceDataEntity const & );
                                     operator eCResourceBase_PS *       ( void );
                                     operator eCResourceBase_PS const * ( void ) const;

    public:
        bEResult            Convert( eEResourceCacheBehavior );
        GEBool              CreateResourceFromFile( bCString const & );
        GEBool              CreateResourceFromType( bCString const & );
        GEU32               GetCacheTimeStamp( void ) const;
        GEU32               GetCurrentResourceSize( void ) const;
        bCString            GetFileName( void ) const;
        bCString            GetFilePath( void ) const;
        bCObjectRefBase *   GetRenderBufferHook( void ) const;
        GEBool              IsLocked( void ) const;
        bEResult            Load( eEResourceCacheBehavior );
        GEU16               Lock( void );
        bEResult            Reload( eEResourceCacheBehavior );
        bEResult            Save( bCString const &, eEResourceCacheBehavior );
        eCResourceBase_PS * SearchResourcePropertySet( void ) const;
        void                SetCacheTimeStamp( GEU32 );
        void                SetRenderBufferHook( bCObjectRefBase * );
        bEResult            Unload( eEResourceCacheBehavior );
        GEU16               Unlock( void );

    protected:
        eCResourceDataEntity( eCResourceDataEntity const & );
        eCResourceDataEntity( void );

    protected:
        void Invalidate( void );

    public:
        GE_PADDING( 0x18 )
        eCResourceBase_PS * m_pResource;
        GE_PADDING( 0x04 )
};

GE_ASSERT_SIZEOF( eCResourceDataEntity, 0x50 );

#endif
