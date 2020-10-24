#ifndef GE_DIALOG_PS_H_INCLUDED
#define GE_DIALOG_PS_H_INCLUDED

GE_IMPORT_PROPERTY_SET( gCDialog_PS, eCEntityPropertySet )
    public: virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult                                   Write( bCOStream & );
    public: virtual bEResult                                   Read( bCIStream & );
    public: virtual void                                       Destroy( void );
    public: virtual bEResult                                   Create( void );
    public: virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public: virtual                                           ~gCDialog_PS( void );
    public: virtual bEResult                                   PostInitializeProperties( void );
    public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public: virtual GEBool                                     IsProcessable( void ) const;
    public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public: virtual void                                       OnProcess( void );
    public: virtual void                                       OnPreProcess( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        GE_IMPORT_DECLARE_PROPERTY( GEBool, TalkedToPlayer, m_bTalkedToPlayer )
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, EndDialogTimestamp, m_fEndDialogTimestamp )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,  TradeEnabled,       m_bTradeEnabled )
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_ENUMPROP( gETradeCategory, TradeCategory, m_enuTradeCategory )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, TeachEnabled,   m_bTeachEnabled )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, PartyEnabled,   m_bPartyEnabled )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, MobEnabled,     m_bMobEnabled )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, SlaveryEnabled, m_bSlaveryEnabled )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, PickedPocket,   m_bPickedPocket )
        GE_PADDING( 3 )

    public:
        gCDialog_PS( gCDialog_PS const & );
        gCDialog_PS( void );

    public:
        gCDialog_PS const & operator = ( gCDialog_PS const & );

    public:
        GEInt      AddTalkedToBy( eCEntity * );
        eCEntity * GetTalkedToBy( GEInt ) const;
        GEInt      GetTalkedToByCount( void ) const;
        eCEntity * GetTalkingTo( void ) const;
        GEBool     RemoveTalkedToBy( eCEntity * );
        void       SetTalkingTo( eCEntity * );

    protected:
        void Invalidate( void );

    private:
        eCEntityProxy             m_TalkingTo;
        bTObjArray<eCEntityProxy> m_arrTalkedToBy;
};

GE_ASSERT_SIZEOF( gCDialog_PS, 0x58 )

#endif
