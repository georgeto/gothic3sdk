#ifndef GE_INTERACTION_PS_H_INCLUDED
#define GE_INTERACTION_PS_H_INCLUDED

GE_IMPORT_PROPERTY_SET( gCInteraction_PS, eCEntityPropertySet )
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
        GE_IMPORT_DECLARE_ENUMPROP( gEFocusPriority, FocusPriority, m_enuFocusPri )
        GE_IMPORT_DECLARE_PROPERTY( eCEntityProxy, Owner, m_Owner ) // Read only
        GE_IMPORT_DECLARE_PROPERTY( eCEntityProxy, User, m_User ) // Read only
        GE_IMPORT_DECLARE_ENUMPROP( gEUseType, UseType, m_enuUseType )
        GE_IMPORT_DECLARE_PROPERTY( bCString, ScriptUseFunc, m_strScriptUseFunc )
        GE_IMPORT_DECLARE_PROPERTY( eCEntityProxy, AnchorPoint, m_AnchorPoint ) // Read only
        GE_IMPORT_DECLARE_ENUMPROP( gEFocusNameType, FocusNameType, m_enuFocusNameType )
        GE_IMPORT_DECLARE_PROPERTY( bCString, FocusNameBone, m_strFocusNameBone )
        GE_IMPORT_DECLARE_PROPERTY( bCVector, FocusViewOffset, m_vecFocusViewOffset )
        GE_IMPORT_DECLARE_PROPERTY( bCVector, FocusWorldOffset, m_vecFocusWorldOffset )
        GE_IMPORT_DECLARE_PROPERTY( bool, UsedByPlayer, m_bUsedByPlayer ) // Read only
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_PROPERTY( bCString, EnterROIScript, m_strEnterROIScript )
        GE_IMPORT_DECLARE_PROPERTY( bCString, ExitROIScript, m_strExitROIScript )
        GE_IMPORT_DECLARE_PROPERTY( eCTemplateEntityProxy, Spell, m_entSpell )

    public:
        gCInteraction_PS( gCInteraction_PS const & );
        gCInteraction_PS( void );

    public:
        gCInteraction_PS const & operator = ( gCInteraction_PS const & );

    public:
        bCString &                                   AccessUseFunc( void );
        eCPropertySetProxy &                         GetAccessToZoneProxy( void );
        bCString const &                             GetUseFunc( void ) const;
        eCEntity const *                             GetZoneEntity( void );
        eCPropertySetProxy const &                   GetZoneProxy( void ) const;
        GEBool                                       IsZoneProxyValid( void ) const;
        void                                         SetUseFunc( bCString const & );

    protected:
        void Invalidate( void );

    private:
        eCPropertySetProxy m_NavZone;
        GEBool             m_bZoneProxyValid;
        GE_PADDING( 3 )
};

GE_ASSERT_SIZEOF( gCInteraction_PS, 0xE0 );

#endif
