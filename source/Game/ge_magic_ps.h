#ifndef GE_MAGIC_PS_H_INCLUDED
#define GE_MAGIC_PS_H_INCLUDED

class GE_DLLIMPORT gCMagic_PS :
    public eCEntityPropertySet
{
    public: virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult          Write( bCOStream & );
    public: virtual bEResult          Read( bCIStream & );
    public: virtual void              Destroy( void );
    public: virtual bEResult          Create( void );
    public: virtual bEResult          CopyFrom( bCObjectBase const & );
    public: virtual                  ~gCMagic_PS( void );
    public: virtual bEResult          PostInitializeProperties( void );
    public: virtual eEPropertySetType GetPropertySetType( void ) const;
    public: virtual GEBool            IsEditorRelevant( void ) const;
    public: virtual GEBool            SupportsRenderDebugOutput( void ) const;
    public: virtual void              GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    public: virtual void              GetOnScreenDebugLines( GEU32, bTObjArray<eSPropertySetDebugLine> & ) const;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCMagic_PS( gCMagic_PS const & );
        gCMagic_PS( void );

    public:
        gCMagic_PS const & operator = ( gCMagic_PS const & );

    public:
        bCString &                                 AccessAnimActionCast( void );
        bCString &                                 AccessAnimActionPowerCast( void );
        GEBool &                                   AccessAutoReload( void );
        bTPropertyContainer<gECastType> &          AccessCastType( void );
        bCString &                                 AccessEffectCasterCast( void );
        bCString &                                 AccessEffectCasterHold( void );
        bCString &                                 AccessEffectCasterLoad( void );
        bCString &                                 AccessEffectCasterPower( void );
        bCString &                                 AccessEffectItemCast( void );
        bCString &                                 AccessEffectItemHold( void );
        bCString &                                 AccessEffectItemLoad( void );
        bCString &                                 AccessEffectItemPower( void );
        bCString &                                 AccessEffectTargetCast( void );
        bCString &                                 AccessEffectTargetLoad( void );
        bCString &                                 AccessEffectTargetPower( void );
        bCString &                                 AccessFuncOnCast( void );
        bCString &                                 AccessFuncOnTargetHit( void );
        GEInt &                                    AccessLearnPoints( void );
        GEInt &                                    AccessMaxManaCost( void );
        GEInt &                                    AccessMinManaCost( void );
        GEFloat &                                  AccessReloadDelaySeconds( void );
        bCString &                                 AccessReqAttrib1Tag( void );
        GEInt &                                    AccessReqAttrib1Value( void );
        bCString &                                 AccessReqAttrib2Tag( void );
        GEInt &                                    AccessReqAttrib2Value( void );
        bCString &                                 AccessReqAttrib3Tag( void );
        GEInt &                                    AccessReqAttrib3Value( void );
        bCString &                                 AccessReqAttrib4Tag( void );
        GEInt &                                    AccessReqAttrib4Value( void );
        eCTemplateEntityProxy &                    AccessReqSkill1( void );
        eCTemplateEntityProxy &                    AccessSpawn( void );
        bTPropertyContainer<gESpellDeity> &        AccessSpellDeity( void );
        bTPropertyContainer<gESpellTarget> &       AccessSpellTarget( void );
        bTPropertyContainer<gESpellType> &         AccessSpellType( void );
        GEInt                                      CompareTo( gCMagic_PS const & ) const;
        bCString const &                           GetAnimActionCast( void ) const;
        bCString const &                           GetAnimActionPowerCast( void ) const;
        GEBool const &                             GetAutoReload( void ) const;
        bTPropertyContainer<gECastType> const &    GetCastType( void ) const;
        bCString const &                           GetEffectCasterCast( void ) const;
        bCString const &                           GetEffectCasterHold( void ) const;
        bCString const &                           GetEffectCasterLoad( void ) const;
        bCString const &                           GetEffectCasterPower( void ) const;
        bCString const &                           GetEffectItemCast( void ) const;
        bCString const &                           GetEffectItemHold( void ) const;
        bCString const &                           GetEffectItemLoad( void ) const;
        bCString const &                           GetEffectItemPower( void ) const;
        bCString const &                           GetEffectTargetCast( void ) const;
        bCString const &                           GetEffectTargetLoad( void ) const;
        bCString const &                           GetEffectTargetPower( void ) const;
        bCString const &                           GetFuncOnCast( void ) const;
        bCString const &                           GetFuncOnTargetHit( void ) const;
        GEInt const &                              GetLearnPoints( void ) const;
        GEInt const &                              GetMaxManaCost( void ) const;
        GEInt const &                              GetMinManaCost( void ) const;
        GEFloat const &                            GetReloadDelaySeconds( void ) const;
        bCString const &                           GetReqAttrib1Tag( void ) const;
        GEInt const &                              GetReqAttrib1Value( void ) const;
        bCString const &                           GetReqAttrib2Tag( void ) const;
        GEInt const &                              GetReqAttrib2Value( void ) const;
        bCString const &                           GetReqAttrib3Tag( void ) const;
        GEInt const &                              GetReqAttrib3Value( void ) const;
        bCString const &                           GetReqAttrib4Tag( void ) const;
        GEInt const &                              GetReqAttrib4Value( void ) const;
        GEInt                                      GetReqINT( void ) const;
        eCTemplateEntityProxy const &              GetReqSkill1( void ) const;
        eCTemplateEntityProxy const &              GetSpawn( void ) const;
        bTPropertyContainer<gESpellDeity> const &  GetSpellDeity( void ) const;
        bTPropertyContainer<gESpellTarget> const & GetSpellTarget( void ) const;
        bTPropertyContainer<gESpellType> const &   GetSpellType( void ) const;
        void                                       SetAnimActionCast( bCString const & );
        void                                       SetAnimActionPowerCast( bCString const & );
        void                                       SetAutoReload( GEBool const & );
        void                                       SetCastType( bTPropertyContainer<gECastType> const & );
        void                                       SetEffectCasterCast( bCString const & );
        void                                       SetEffectCasterHold( bCString const & );
        void                                       SetEffectCasterLoad( bCString const & );
        void                                       SetEffectCasterPower( bCString const & );
        void                                       SetEffectItemCast( bCString const & );
        void                                       SetEffectItemHold( bCString const & );
        void                                       SetEffectItemLoad( bCString const & );
        void                                       SetEffectItemPower( bCString const & );
        void                                       SetEffectTargetCast( bCString const & );
        void                                       SetEffectTargetLoad( bCString const & );
        void                                       SetEffectTargetPower( bCString const & );
        void                                       SetFuncOnCast( bCString const & );
        void                                       SetFuncOnTargetHit( bCString const & );
        void                                       SetLearnPoints( int const & );
        void                                       SetMaxManaCost( GEInt const & );
        void                                       SetMinManaCost( GEInt const & );
        void                                       SetReloadDelaySeconds( GEFloat const & );
        void                                       SetReqAttrib1Tag( bCString const & );
        void                                       SetReqAttrib1Value( GEInt const & );
        void                                       SetReqAttrib2Tag( bCString const & );
        void                                       SetReqAttrib2Value( GEInt const & );
        void                                       SetReqAttrib3Tag( bCString const & );
        void                                       SetReqAttrib3Value( GEInt const & );
        void                                       SetReqAttrib4Tag( bCString const & );
        void                                       SetReqAttrib4Value( GEInt const & );
        void                                       SetReqSkill1( eCTemplateEntityProxy const & );
        void                                       SetSpawn( eCTemplateEntityProxy const & );
        void                                       SetSpellDeity( bTPropertyContainer<gESpellDeity> const & );
        void                                       SetSpellTarget( bTPropertyContainer<gESpellTarget> const & );
        void                                       SetSpellType( bTPropertyContainer<gESpellType> const & );

    protected:
        void Invalidate( void );

};

#endif
