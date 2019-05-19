#ifndef GE_PROPERTYSETPROXY_H_INCLUDED
#define GE_PROPERTYSETPROXY_H_INCLUDED

class GE_DLLIMPORT eCPropertySetProxy :
    public eCEntityProxy
{
    public:    virtual void             SetAddress( bCString const & );
    protected: virtual eCEntity const * ResolveEntity( void );
    public:    virtual GEU16            GetVersion( void ) const;
    public:    virtual bCString         GetAddress( void ) const;
    public:    virtual bEResult         Read( bCIStream & );
    public:    virtual bEResult         Write( bCOStream & );
    protected: virtual bEResult         CopyFrom( eCEntityProxy const & );
    protected: virtual GEBool           Compare( eCEntityProxy const & ) const;
    public:    virtual                 ~eCPropertySetProxy( void );

    public:
        // 0000 // eCPropertySetProxy::`vftable'
        // 0004 // eCEntityProxyInternal* mEntityProxyInternal;
        // 0008 // bCPropertyID mEntityID;
        /* 001C */ eCEntityPropertySet * m_EntityPropertySet;
        /* 0020 */ bCString *            m_pEntityPropertySetName;

    public:
        eCPropertySetProxy( eCPropertySetProxy const & );
        eCPropertySetProxy( void );

    public:
        eCPropertySetProxy const & operator =  ( eCPropertySetProxy const & );
        bCOStream &                operator >> ( bCOStream & );
        bCIStream &                operator << ( bCIStream & );

    public:
        eCEntityPropertySet *       GetAccessToPropertySet( void );
        eCEntityPropertySet const * GetPropertySet( void ) const;
        bCString const &            GetPropertySetType( void ) const;
        GEBool                      IsPropertySetNameValid( void ) const;
        GEBool                      IsPropertySetValid( void ) const;
        void                        SetPropertySet( bCString const & );
        void                        SetPropertySet( eCEntityPropertySet const * );
        void                        SetPropertySetComfort( eCEntityPropertySet const * );

    protected:
        bEResult Create( void );
        void     Destroy( void );
        void     Invalidate( void );
        void     SetPropertySetInternal( eCEntityPropertySet const * );

};

GE_ASSERT_SIZEOF( eCPropertySetProxy, 0x24 );

template<>
static inline GEU32 g_GetHashValue< eCPropertySetProxy >( eCPropertySetProxy const & _e )
{
    return g_GetHashValue( _e.GetEntityID() );
}

#endif
