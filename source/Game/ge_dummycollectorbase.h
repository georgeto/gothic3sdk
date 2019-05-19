#ifndef GE_DUMMYCOLLECTORBASE_H_INCLUDED
#define GE_DUMMYCOLLECTORBASE_H_INCLUDED

class GE_DLLIMPORT gCDummyCollectorBase
{
    public: virtual bEResult   Apply( bCBox const & )                   = 0;
    public: virtual bEResult   Collect( eCEntity & )                    = 0;
    public: virtual bEResult   Apply( eCEntity & )                      = 0;
    public: virtual bEResult   Collect( bCBox const & )                 = 0;
    public: virtual bEResult   Apply( void )                            = 0;
    public: virtual bEResult   UpdateCollection( eCEntity & )           = 0;
    public: virtual bEResult   UpdateCollection( void )                 = 0;
    public: virtual bEResult   ClearCollection( void )                  = 0;
    public: virtual bEResult   RemoveFromCollection( eCEntity & )       = 0;
    public: virtual GEU32      GetReferencedEntitiesCount( void ) const = 0;
    public: virtual eCEntity * GetReferencedEntityAt( GEU32 ) const = 0;
    public: virtual GEBool     IsInUpdateCollection( void ) const = 0;
    public: virtual           ~gCDummyCollectorBase( void );

    public:
        eCEntity *m_pRootEntity;

    public:
        gCDummyCollectorBase( gCDummyCollectorBase const & );

    public:
        gCDummyCollectorBase & operator = ( gCDummyCollectorBase const & );

    protected:
        gCDummyCollectorBase( eCEntity & );

};

#endif
