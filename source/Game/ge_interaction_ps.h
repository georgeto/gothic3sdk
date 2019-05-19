#ifndef GE_INTERACTION_PS_H_INCLUDED
#define GE_INTERACTION_PS_H_INCLUDED

class GE_DLLIMPORT gCInteraction_PS :
    public eCEntityPropertySet
{
    public:    virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                                   Write( bCOStream & );
    public:    virtual bEResult                                   Read( bCIStream & );
    public:    virtual void                                       Destroy( void );
    public:    virtual bEResult                                   Create( void );
    public:    virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public:    virtual                                           ~gCInteraction_PS( void );
    public:    virtual bEResult                                   PostInitializeProperties( void );
    public:    virtual GEBool                                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
    public:    virtual GEBool                                     IsVisual( void ) const;
    public:    virtual bEResult                                   ReadSaveGame( bCIStream & );
    public:    virtual bEResult                                   WriteSaveGame( bCOStream & );
    public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public:    virtual void                                       GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    protected: virtual void                                       OnEnterProcessingRange( void );
    protected: virtual void                                       OnExitProcessingRange( void );
    public:    virtual void                                       OnRender( GEI16 );
    public:    virtual void                                       OnPropertySetAdded( void );
    public:    virtual void                                       OnPropertySetRemoved( void );
    public:    virtual void                                       OnCustomPatch( eCEntityPropertySet const * );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCInteraction_PS( gCInteraction_PS const & );
        gCInteraction_PS( void );

    public:
        gCInteraction_PS const & operator = ( gCInteraction_PS const & );

    public:
        eCEntityProxy &                              AccessAnchorPoint( void );
        bCString &                                   AccessEnterROIScript( void );
        bCString &                                   AccessExitROIScript( void );
        bCString &                                   AccessFocusNameBone( void );
        bTPropertyContainer<gEFocusNameType> &       AccessFocusNameType( void );
        bTPropertyContainer<gEFocusPriority> &       AccessFocusPriority( void );
        bCVector &                                   AccessFocusViewOffset( void );
        bCVector &                                   AccessFocusWorldOffset( void );
        eCEntityProxy &                              AccessOwner( void );
        eCTemplateEntityProxy &                      AccessSpell( void );
        bCString &                                   AccessUseFunc( void );
        bTPropertyContainer<gEUseType> &             AccessUseType( void );
        GEBool &                                     AccessUsedByPlayer( void );
        eCEntityProxy &                              AccessUser( void );
        eCPropertySetProxy &                         GetAccessToZoneProxy( void );
        eCEntityProxy const &                        GetAnchorPoint( void ) const;
        bCString const &                             GetEnterROIScript( void ) const;
        bCString const &                             GetExitROIScript( void ) const;
        bCString const &                             GetFocusNameBone( void ) const;
        bTPropertyContainer<gEFocusNameType> const & GetFocusNameType( void ) const;
        bTPropertyContainer<gEFocusPriority> const & GetFocusPriority( void ) const;
        bCVector const &                             GetFocusViewOffset( void ) const;
        bCVector const &                             GetFocusWorldOffset( void ) const;
        eCEntityProxy const &                        GetOwner( void ) const;
        eCTemplateEntityProxy const &                GetSpell( void ) const;
        bCString const &                             GetUseFunc( void ) const;
        bTPropertyContainer<gEUseType> const &       GetUseType( void ) const;
        GEBool const &                               GetUsedByPlayer( void ) const;
        eCEntityProxy const &                        GetUser( void ) const;
        eCEntity const *                             GetZoneEntity( void );
        eCPropertySetProxy const &                   GetZoneProxy( void ) const;
        GEBool                                       IsZoneProxyValid( void ) const;
        void                                         SetAnchorPoint( eCEntityProxy const & );
        void                                         SetEnterROIScript( bCString const & );
        void                                         SetExitROIScript( bCString const & );
        void                                         SetFocusNameBone( bCString const & );
        void                                         SetFocusNameType( bTPropertyContainer<gEFocusNameType> const & );
        void                                         SetFocusPriority( bTPropertyContainer<gEFocusPriority> const & );
        void                                         SetFocusViewOffset( bCVector const & );
        void                                         SetFocusWorldOffset( bCVector const & );
        void                                         SetOwner( eCEntityProxy const & );
        void                                         SetSpell( eCTemplateEntityProxy const & );
        void                                         SetUseFunc( bCString const & );
        void                                         SetUseType( bTPropertyContainer<gEUseType> const & );
        void                                         SetUsedByPlayer( GEBool const & );
        void                                         SetUser( eCEntityProxy const & );

    protected:
        void Invalidate( void );

};

#endif
