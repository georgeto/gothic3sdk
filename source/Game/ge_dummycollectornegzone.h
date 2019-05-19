#ifndef GE_DUMMYCOLLECTORNEGZONE_H_INCLUDED
#define GE_DUMMYCOLLECTORNEGZONE_H_INCLUDED

class GE_DLLIMPORT gCDummyCollectorNegZone :
    public gCDummyCollectorPSet_Base
{
    public:    virtual bEResult          Collect( eCEntity & );
    public:    virtual bEResult          Collect( bCBox const & );
    public:    virtual bEResult          Apply( eCEntity & );
    public:    virtual bEResult          Apply( bCBox const & );
    public:    virtual                  ~gCDummyCollectorNegZone( void );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    public:    virtual bEResult          AddPropertySetMember( eCEntity &, eCEntity * &, GEInt, GEInt, GEInt );
    protected: virtual bEResult          DeleteIndexInPropertySet( GEInt, GEInt );
    protected: virtual bEResult          AddIndexInPropertySet( GEInt, GEInt, GEInt, GEInt );
    protected: virtual bEResult          VisualizeCollectionMember( GEInt, GEBool );

    public:
        gCDummyCollectorNegZone( eCEntity & );
        gCDummyCollectorNegZone( gCDummyCollectorNegZone const & );

    public:
        gCDummyCollectorNegZone & operator = ( gCDummyCollectorNegZone const & );

    protected:
        void RefreshAdditionalProperties( eCEntityPropertySet *, GEInt );

};

#endif
