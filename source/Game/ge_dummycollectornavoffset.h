#ifndef GE_DUMMYCOLLECTORNAVOFFSET_H_INCLUDED
#define GE_DUMMYCOLLECTORNAVOFFSET_H_INCLUDED

class GE_DLLIMPORT gCDummyCollectorNavOffset :
    public gCDummyCollectorPSet_Base
{
    public:    virtual bEResult          Collect( eCEntity & );
    public:    virtual bEResult          Collect( bCBox const & );
    public:    virtual bEResult          Apply( eCEntity & );
    public:    virtual bEResult          Apply( bCBox const & );
    public:    virtual                  ~gCDummyCollectorNavOffset( void );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    public:    virtual bEResult          AddPropertySetMember( eCEntity &, eCEntity * &, GEInt, GEInt, GEInt );
    protected: virtual bEResult          DeleteIndexInPropertySet( GEInt, GEInt );
    protected: virtual bEResult          AddIndexInPropertySet( GEInt, GEInt, GEInt, GEInt );
    protected: virtual bEResult          VisualizeCollectionMember( GEInt, GEBool );

    public:
        gCDummyCollectorNavOffset( eCEntity & );
        gCDummyCollectorNavOffset( gCDummyCollectorNavOffset const & );

    public:
        gCDummyCollectorNavOffset & operator = ( gCDummyCollectorNavOffset const & );

};

#endif
