#ifndef GE_DUMMYCOLLECTORPSET_BASE_H_INCLUDED
#define GE_DUMMYCOLLECTORPSET_BASE_H_INCLUDED

class GE_DLLIMPORT gCDummyCollectorPSet_Base :
    public gCDummyCollectorBase
{
    protected: virtual void              RemoveFromCollectionInternal( eCEntity &, bTSmallArray<eCEntity *> & );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const = 0;
    public:    virtual GEU32             GetPropertySetMemberCount( eCEntity & ) const;
    public:    virtual bEResult          AddPropertySetMember( eCEntity &, eCEntity * &, GEInt, GEInt, GEInt ) = 0;
    protected: virtual bEResult          DeleteIndexInPropertySet( GEInt, GEInt )                              = 0;
    protected: virtual bEResult          AddIndexInPropertySet( GEInt, GEInt, GEInt, GEInt )                   = 0;
    protected: virtual bEResult          VisualizeCollectionMember( GEInt, GEBool )                            = 0;
    public:    virtual bEResult          Apply( void );
    public:    virtual bEResult          UpdateCollection( eCEntity & );
    public:    virtual bEResult          UpdateCollection( void );
    public:    virtual bEResult          ClearCollection( void );
    public:    virtual bEResult          RemoveFromCollection( eCEntity & );
    public:    virtual GEU32             GetReferencedEntitiesCount( void ) const;
    public:    virtual eCEntity *        GetReferencedEntityAt( GEU32 ) const;
    public:    virtual GEBool            IsInUpdateCollection( void ) const;
    public:    virtual                  ~gCDummyCollectorPSet_Base( void );

    public:
        struct gSCollectionMember
        {
            eCEntity *             m_pEntity;
            eCEntityPropertySet *  m_pPropertySet;
            eCEntity *             m_pDummyEntity;
            bTObjArray<eCEntity *> field_12;
            bTObjArray<eCEntity *> field_24;
        };

    public:
        eCEntity *                     m_pBaseRootyEntity;
        bTObjArray<gSCollectionMember> m_arrCollectionMembers;
        GEBool                         m_bInUpdateCollection;
        GE_PADDING(3)

    public:
        gCDummyCollectorPSet_Base( gCDummyCollectorPSet_Base const & );

    public:
        gCDummyCollectorPSet_Base & operator = ( gCDummyCollectorPSet_Base const & );

    public:
        bEResult   DeletePropertySetMember( eCEntity &, GEInt );
        bEResult   DeletePropertySetMember( eCEntity &, eCEntity * );
        void       EnableRenderingForIndex( eCEntity &, GEInt, GEBool );
        eCEntity * GetDummyEntity( eCEntity const & ) const;
        eCEntity * GetDummyEntityAtIndex( eCEntity &, GEInt ) const;
        GEInt      GetEntityAndMemberIndex( eCEntity const *, eCEntity * & );

    protected:
        gCDummyCollectorPSet_Base( eCEntity & );

    protected:
        bEResult AddNewPropertySetMember( eCEntity &, eCEntity * &, GEInt, GEInt, GEInt );
        bEResult ApplyPropertySet( bCBox const &, eEPropertySetType const & );
        bEResult BlockAllDummyVisuals( GEInt );
        bEResult CollectPropertySets( eCEntity &, eEPropertySetType const & );
        bEResult CollectPropertySets( bCBox const &, eEPropertySetType const & );
        bEResult UnblockAllDummyVisuals( GEInt );

};

GE_ASSERT_SIZEOF( gCDummyCollectorPSet_Base, 0x1C );

#endif
