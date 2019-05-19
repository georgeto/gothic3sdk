#ifndef GE_DUMMYCOLLECTORNAVZONE_H_INCLUDED
#define GE_DUMMYCOLLECTORNAVZONE_H_INCLUDED

class GE_DLLIMPORT gCDummyCollectorNavZone :
    public gCDummyCollectorPSet_Base
{
    public:    virtual bEResult          Collect( eCEntity & );
    public:    virtual bEResult          Collect( bCBox const & );
    public:    virtual bEResult          Apply( eCEntity & );
    public:    virtual bEResult          Apply( bCBox const & );
    public:    virtual                  ~gCDummyCollectorNavZone( void );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    public:    virtual bEResult          AddPropertySetMember( eCEntity &, eCEntity * &, GEInt, GEInt, GEInt );
    protected: virtual bEResult          DeleteIndexInPropertySet( GEInt, GEInt );
    protected: virtual bEResult          AddIndexInPropertySet( GEInt, GEInt, GEInt, GEInt );
    protected: virtual bEResult          VisualizeCollectionMember( GEInt, GEBool );

    public:
        gCDummyCollectorNavZone( eCEntity & );
        gCDummyCollectorNavZone( gCDummyCollectorNavZone const & );

    public:
        gCDummyCollectorNavZone & operator = ( gCDummyCollectorNavZone const & );

    protected:
        void RefreshAdditionalProperties( eCEntityPropertySet *, GEInt );

};

#endif
