#ifndef GE_ENTITYPROXY_H_INCLUDED
#define GE_ENTITYPROXY_H_INCLUDED

class GE_DLLIMPORT eCEntityProxy
{
    protected: virtual eCEntity const * ResolveEntity( void );
    public:    virtual GEU16            GetVersion( void ) const;
    public:    virtual bCString         GetAddress( void ) const;
    public:    virtual bEResult         Read( bCIStream & );
    public:    virtual bEResult         Write( bCOStream & );
    protected: virtual bEResult         CopyFrom( eCEntityProxy const & );
    protected: virtual GEBool           Compare( eCEntityProxy const & ) const;
    public:    virtual                 ~eCEntityProxy( void );

    private:
        // 0000 // eCEntityProxy::`vftable'
        /* 0004 */ eCEntityProxyInternal* mEntityProxyInternal;
        /* 0008 */ bCPropertyID           mEntityID;

    public:
        eCEntityProxy( eCEntityProxy const & );
        eCEntityProxy( eCEntity * );
        eCEntityProxy( void );

    public:
        eCEntityProxy const & operator =                ( eCEntityProxy const & );
        bCOStream &           operator >>               ( bCOStream & );
        bCIStream &           operator <<               ( bCIStream & );
        GEBool                operator ==               ( eCEntityProxy const & ) const;
        GEBool                operator !=               ( eCEntityProxy const & ) const;
                              operator eCEntity *       ( void );
                              operator eCEntity const * ( void ) const;
        eCEntity *            operator ->               ( void );
        eCEntity const *      operator ->               ( void ) const;

    public:
        eCEntity *           GetEntity( void );
        eCEntity const *     GetEntity( void ) const;
        bCPropertyID const & GetEntityID( void ) const;
        GEBool               IsEntityIDValid( void ) const;
        void                 SetEntity( bCPropertyID const & );
        void                 SetEntity( bCString const & );
        void                 SetEntity( eCEntity const * );

    protected:
        bEResult Create( void );
        void     Destroy( void );
        void     Invalidate( void );

};

bCIStream & operator >> ( bCIStream &, eCEntityProxy & );
bCOStream & operator << ( bCOStream &, eCEntityProxy & );

GE_ASSERT_SIZEOF( eCEntityProxy, 0x1C );

template<>
static inline GEU32 g_GetHashValue< eCEntityProxy >( eCEntityProxy const & _e )
{
    return g_GetHashValue( _e.GetEntityID() );
}

#endif
