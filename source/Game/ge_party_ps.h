#ifndef GE_PARTY_PS_H_INCLUDED
#define GE_PARTY_PS_H_INCLUDED

class GE_DLLIMPORT gCParty_PS :
    public eCEntityPropertySet
{
    public:    virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                                   Write( bCOStream & );
    public:    virtual bEResult                                   Read( bCIStream & );
    public:    virtual void                                       Destroy( void );
    public:    virtual bEResult                                   Create( void );
    public:    virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public:    virtual                                           ~gCParty_PS( void );
    public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
    protected: virtual GEBool                                     IsReferencedByTemplate( void ) const;
    public:    virtual GEBool                                     SupportsRenderDebugOutput( void ) const;
    public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public:    virtual void                                       GetOnScreenDebugLines( GEU32, bTObjArray<eSPropertySetDebugLine> & ) const;
    protected: virtual void                                       OnChildrenAvailable( GEU32, GEU32, eCTemplateEntity * );

    public:
        static bTPropertyType<gCParty_PS, eCEntityProxy>                           ms_PropertyMember_m_PartyLeader;
        static bTPropertyType<gCParty_PS, GEBool>                                  ms_PropertyMember_m_bWaiting;
        static bTPropertyType<gCParty_PS, bTPropertyContainer<gEPartyMemberType> > ms_PropertyMember_m_enuPartyMemberType;

    private:
        static bTPropertyObject<gCParty_PS, eCEntityPropertySet> ms_PropertyObjectInstance_gCParty_PS;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCParty_PS( gCParty_PS const & );
        gCParty_PS( void );

    public:
        gCParty_PS const & operator = ( gCParty_PS const & );

    public:
        eCEntityProxy &                                AccessPartyLeaderEntity( void );
        bTPropertyContainer<gEPartyMemberType> &       AccessPartyMemberType( void );
        GEBool &                                       AccessWaiting( void );
        bTObjArray<eCEntityProxy> &                    GetMembers( void );
        bTObjArray<eCEntityProxy> const &              GetMembers( void ) const;
        eCEntityProxy const &                          GetPartyLeaderEntity( void ) const;
        bTPropertyContainer<gEPartyMemberType> const & GetPartyMemberType( void ) const;
        GEBool const &                                 GetWaiting( void ) const;
        void                                           SetPartyLeaderEntity( eCEntityProxy const & );
        void                                           SetPartyMemberType( bTPropertyContainer<gEPartyMemberType> const & );
        void                                           SetWaiting( GEBool const & );

    protected:
        void Invalidate( void );

};

#endif
