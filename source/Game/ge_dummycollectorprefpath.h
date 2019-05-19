#ifndef GE_DUMMYCOLLECTORPREFPATH_H_INCLUDED
#define GE_DUMMYCOLLECTORPREFPATH_H_INCLUDED

class GE_DLLIMPORT gCDummyCollectorPrefPath :
    public gCDummyCollectorPSet_Base
{
    public:    virtual bEResult          Collect( eCEntity & );
    public:    virtual bEResult          Collect( bCBox const & );
    public:    virtual bEResult          Apply( eCEntity & );
    public:    virtual bEResult          Apply( bCBox const & );
    public:    virtual                  ~gCDummyCollectorPrefPath( void );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    public:    virtual bEResult          AddPropertySetMember( eCEntity &, eCEntity * &, GEInt, GEInt, GEInt );
    protected: virtual bEResult          DeleteIndexInPropertySet( GEInt, GEInt );
    protected: virtual bEResult          AddIndexInPropertySet( GEInt, GEInt, GEInt, GEInt );
    protected: virtual bEResult          VisualizeCollectionMember( GEInt, GEBool );

    public:
        gCDummyCollectorPrefPath( eCEntity & );
        gCDummyCollectorPrefPath( gCDummyCollectorPrefPath const & );

    public:
        gCDummyCollectorPrefPath & operator = ( gCDummyCollectorPrefPath const & );

    protected:
        void RefreshAdditionalProperties( eCEntityPropertySet *, GEInt );

};

#endif
