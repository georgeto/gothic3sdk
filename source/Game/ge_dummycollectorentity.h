#ifndef GE_DUMMYCOLLECTORENTITY_H_INCLUDED
#define GE_DUMMYCOLLECTORENTITY_H_INCLUDED

class GE_DLLIMPORT gCDummyCollectorEntity :
    public gCDummyCollectorBase
{
    public: virtual bEResult   Apply( bCBox const & );
    public: virtual bEResult   Collect( eCEntity & );
    public: virtual bEResult   Apply( eCEntity & );
    public: virtual bEResult   Collect( bCBox const & );
    public: virtual bEResult   Apply( void );
    public: virtual bEResult   UpdateCollection( eCEntity & );
    public: virtual bEResult   UpdateCollection( void );
    public: virtual bEResult   ClearCollection( void );
    public: virtual bEResult   RemoveFromCollection( eCEntity & );
    public: virtual GEU32      GetReferencedEntitiesCount( void ) const;
    public: virtual eCEntity * GetReferencedEntityAt( GEU32 ) const;
    public: virtual GEBool     IsInUpdateCollection( void ) const;
    public: virtual           ~gCDummyCollectorEntity( void );

    public:
        gCDummyCollectorEntity( eCEntity & );
        gCDummyCollectorEntity( gCDummyCollectorEntity const & );

    public:
        gCDummyCollectorEntity & operator = ( gCDummyCollectorEntity const & );

};

#endif
