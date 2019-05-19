#ifndef GE_ENCLAVE_PS_H_INCLUDED
#define GE_ENCLAVE_PS_H_INCLUDED

class GE_DLLIMPORT gCEnclave_PS :
    public eCEntityPropertySet
{
    public:    virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                                   Write( bCOStream & );
    public:    virtual bEResult                                   Read( bCIStream & );
    public:    virtual void                                       Destroy( void );
    public:    virtual bEResult                                   Create( void );
    public:    virtual                                           ~gCEnclave_PS( void );
    public:    virtual bEResult                                   PostInitializeProperties( void );
    public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public:    virtual GEBool                                     IsVisual( void ) const;
    public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public:    virtual void                                       GetBoundary( bCBox &, GEBool );
    protected: virtual void                                       OnPropertySetAdded( void );
    protected: virtual void                                       OnPropertySetRemoved( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCEnclave_PS( gCEnclave_PS const & );
        gCEnclave_PS( void );

    public:
        gCEnclave_PS const & operator = ( gCEnclave_PS const & );

    public:
        bTValArray<GEI32> &                               AccessCrimeCount( void );
        bTPropertyContainer<gEPlayerCrime> &              AccessKnownPlayerCrime( void );
        GEBool &                                          AccessMusicPlayed( void );
        GEI32 &                                           AccessPlayerFame( void );
        bTPropertyContainer<gEPoliticalAlignment> &       AccessPoliticalAlignment( void );
        GEBool &                                          AccessRaid( void );
        GEBool &                                          AccessRevolution( void );
        bTPropertyContainer<gEEnclaveStatus> &            AccessStatus( void );
        bTValArray<GEI32> &                               AccessSuspectComment( void );
        GEBool &                                          AccessSwitched( void );
        GEBool                                            AddMember( eCEntity * );
        void                                              BuildMemberList( GEBool );
        bTValArray<GEI32> const &                         GetCrimeCount( void ) const;
        eCLocString const                                 GetDisplayName( void ) const;
        bTPropertyContainer<gEPlayerCrime> const &        GetKnownPlayerCrime( void ) const;
        bTObjArray<eCEntityProxy> const &                 GetMembers( void ) const;
        GEBool const &                                    GetMusicPlayed( void ) const;
        GEI32 const &                                     GetPlayerFame( void ) const;
        bTPropertyContainer<gEPoliticalAlignment> const & GetPoliticalAlignment( void ) const;
        GEBool const &                                    GetRaid( void ) const;
        GEBool const &                                    GetRevolution( void ) const;
        bTPropertyContainer<gEEnclaveStatus> const &      GetStatus( void ) const;
        bTValArray<GEI32> const &                         GetSuspectComment( void ) const;
        GEBool const &                                    GetSwitched( void ) const;
        GEBool                                            RemoveMember( eCEntity * );
        void                                              SetCrimeCount( bTValArray<GEI32> const & );
        void                                              SetKnownPlayerCrime( bTPropertyContainer<gEPlayerCrime> const & );
        void                                              SetMusicPlayed( GEBool const & );
        void                                              SetPlayerFame( GEI32 const & );
        void                                              SetPoliticalAlignment( bTPropertyContainer<gEPoliticalAlignment> const & );
        void                                              SetRaid( GEBool const & );
        void                                              SetRevolution( GEBool const & );
        void                                              SetStatus( bTPropertyContainer<gEEnclaveStatus> const & );
        void                                              SetSuspectComment( bTValArray<GEI32> const & );
        void                                              SetSwitched( GEBool const & );

    protected:
        void Invalidate( void );

};

#endif
