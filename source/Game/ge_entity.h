#ifndef GE_GENTITY_H_INCLUDED
#define GE_GENTITY_H_INCLUDED

enum gECombatMode;

class GE_DLLIMPORT gCEntity :
    public eCDynamicEntity
{
    public: using eCDynamicEntity::DoDamage;
    public:    virtual void                             DoDamage( eCEntity *, eCEntity *, GEInt, GEInt, GEInt, eCContactIterator & );
    public:    virtual GEU16                            GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                         Write( bCOStream & );
    public:    virtual bEResult                         Read( bCIStream & );
    public:    virtual void                             Destroy( void );
    public:    virtual bEResult                         Create( void );
    public:    virtual bEResult                         CopyFrom( bCObjectBase const & );
    protected: virtual                                 ~gCEntity( void );
    public:    virtual gCEntity *                       DoClone( void ) const;
    protected: virtual void                             OnUpdatedWorldMatrix( void );
    public:    virtual GEBool                           CreateFromTemplate( bCString const & );
    public:    virtual void                             CopyEntityPrivateData( eCEntity const &, GEBool );
    public:    virtual eCDynamicEntity::eECreatureClass GetCreatureClass( void ) const;
    public:    virtual void                             OnDamage( eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator & );

    public:
        static gECombatMode GE_STDCALL GetCombatMode( eCEntity * );
        static gEUseType GE_STDCALL    GetUseType( eCEntity * );
        static eCEntity * GE_STDCALL   GetWeapon( eCEntity *, GEBool );
        static GEBool GE_STDCALL       IsCharacter( eCEntity * );
        static GEBool GE_STDCALL       IsDead( eCEntity * );
        static GEBool GE_STDCALL       IsDown( eCEntity * );
        static GEBool GE_STDCALL       IsInteractable( eCEntity * );
        static GEBool GE_STDCALL       IsItem( eCEntity * );
        static GEBool GE_STDCALL       IsNPC( eCEntity * );
        static GEBool GE_STDCALL       IsPlayer( eCEntity * );
        static GEBool GE_STDCALL       IsReady( eCEntity * );

    public:
        gECombatMode GetCombatMode( void ) const;
        gEUseType    GetUseType( void ) const;
        eCEntity *   GetWeapon( GEBool ) const;
        gCItem_PS *  GetWeaponItem( GEBool ) const;

    protected:
        gCEntity( gCEntity const & );
        gCEntity( void );

    protected:
        gCEntity const & operator = ( gCEntity const & );

    protected:
        GEBool DoExplode( void );
        void   Invalidate( void );

    private:
        GEBool AddPropertySetToProcessingEntityThisIsAnE3HackDoNotUseLetsTalkAboutItLater( eCEntityPropertySet *, GEBool );
        GEBool RemovePropertySetToProcessingEntityThisIsAnE3HackDoNotUseLetsTalkAboutItLater( GEInt );

};

#endif
