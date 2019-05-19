#ifndef GE_PLAYERMEMORY_PS_H_INCLUDED
#define GE_PLAYERMEMORY_PS_H_INCLUDED

enum gETutorialFlag;

class GE_DLLIMPORT gCPlayerMemory_PS :
    public eCEntityPropertySet
{
    public: virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult                                   Write( bCOStream & );
    public: virtual bEResult                                   Read( bCIStream & );
    public: virtual void                                       Destroy( void );
    public: virtual bEResult                                   Create( void );
    public: virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public: virtual                                           ~gCPlayerMemory_PS( void );
    public: virtual bEResult                                   PostInitializeProperties( void );
    public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public: virtual GEBool                                     IsReferencedByTemplate( void ) const;
    public: virtual bEResult                                   ReadSaveGame( bCIStream & );
    public: virtual bEResult                                   WriteSaveGame( bCOStream & );
    public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public: virtual void                                       OnSaveGameEntityPostRead( void );
    public: virtual void                                       OnPostRead( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCPlayerMemory_PS( gCPlayerMemory_PS const & );
        gCPlayerMemory_PS( void );

    public:
        gCPlayerMemory_PS const & operator = ( gCPlayerMemory_PS const & );

    public:
        GEI32 &                                     AccessBookOfFlood( void );
        GEI32 &                                     AccessBookOfRhobar( void );
        GEI32 &                                     AccessBookOfZuben( void );
        GEI32 &                                     AccessChapter( void );
        GEI32 &                                     AccessDuskToDawnStartHour( void );
        GEBool &                                    AccessHideTips( void );
        GEBool &                                    AccessIsConsumingItem( void );
        GEI32 &                                     AccessLPAttribs( void );
        GEI32 &                                     AccessLPPerks( void );
        bCPropertyID &                              AccessLastSpell( void );
        bTPropertyContainer<gEWeaponConfig> &       AccessLastWeaponConfig( void );
        bTObjArray<bCString> &                      AccessPlayerKnows( void );
        bTValArray<GEI32> &                         AccessPoliticalCrimeCount( void );
        bTValArray<GEI32> &                         AccessPoliticalFame( void );
        bTValArray<GEBool> &                        AccessPoliticalPlayerCrime( void );
        bTValArray<GEI32> &                         AccessPoliticalSuspectComment( void );
        GEFloat &                                   AccessSecondsMistRemain( void );
        GEFloat &                                   AccessSecondsTransformRemain( void );
        GEBool &                                    AccessTalkedToDiego( void );
        GEBool &                                    AccessTalkedToGorn( void );
        GEBool &                                    AccessTalkedToLester( void );
        GEBool &                                    AccessTalkedToMilten( void );
        GEFloat &                                   AccessTimeStampStart( void );
        GEU32 &                                     AccessTutorialFlags( void );
        GEI32 &                                     AccessXP( void );
        GEBool                                      AddBaseValue( bCString const &, GEInt );
        GEBool                                      AddMaximum( bCString const &, GEInt );
        GEBool                                      AddModifier( bCString const &, GEInt );
        GEBool                                      AddValue( bCString const &, GEInt );
        GEBool                                      ApplyMod( bCString const &, GEInt, EAttribModOperation );
        GEInt                                       CalcMissingValue( bCString const &, GEInt ) const;
        GEBool                                      Consume( bCString const &, GEInt, EAttribModOperation );
        void                                        EnableTutorial( gETutorialFlag, GEBool );
        gCAttribute *                               GetAttribute( bCString const & ) const;
        bTObjMap<bCString, gCAttribute *> const &   GetAttributes( void ) const;
        GEInt                                       GetBaseValue( bCString const & ) const;
        GEI32 const &                               GetBookOfFlood( void ) const;
        GEI32 const &                               GetBookOfRhobar( void ) const;
        GEI32 const &                               GetBookOfZuben( void ) const;
        GEI32 const &                               GetChapter( void ) const;
        GEI32 const &                               GetDuskToDawnStartHour( void ) const;
        GEBool const &                              GetHideTips( void ) const;
        GEBool const &                              GetIsConsumingItem( void ) const;
        GEI32 const &                               GetLPAttribs( void ) const;
        GEI32 const &                               GetLPPerks( void ) const;
        bCPropertyID const &                        GetLastSpell( void ) const;
        bTPropertyContainer<gEWeaponConfig> const & GetLastWeaponConfig( void ) const;
        GEInt                                       GetMaximum( bCString const & ) const;
        GEInt                                       GetModifier( bCString const & ) const;
        bTObjArray<bCString> const &                GetPlayerKnows( void ) const;
        bTValArray<GEI32> const &                   GetPoliticalCrimeCount( void ) const;
        bTValArray<GEI32> const &                   GetPoliticalFame( void ) const;
        bTValArray<GEBool> const &                  GetPoliticalPlayerCrime( void ) const;
        bTValArray<GEI32> const &                   GetPoliticalSuspectComment( void ) const;
        GEFloat const &                             GetSecondsMistRemain( void ) const;
        GEFloat const &                             GetSecondsTransformRemain( void ) const;
        GEBool const &                              GetTalkedToDiego( void ) const;
        GEBool const &                              GetTalkedToGorn( void ) const;
        GEBool const &                              GetTalkedToLester( void ) const;
        GEBool const &                              GetTalkedToMilten( void ) const;
        GEFloat const &                             GetTimeStampStart( void ) const;
        GEU32 const &                               GetTutorialFlags( void ) const;
        GEInt                                       GetValue( bCString const & ) const;
        GEI32 const &                               GetXP( void ) const;
        GEBool                                      IsTutorialEnabled( gETutorialFlag ) const;
        GEBool                                      SetBaseValue( bCString const &, GEInt );
        void                                        SetBookOfFlood( GEI32 const & );
        void                                        SetBookOfRhobar( GEI32 const & );
        void                                        SetBookOfZuben( GEI32 const & );
        void                                        SetChapter( GEI32 const & );
        void                                        SetDuskToDawnStartHour( GEI32 const & );
        void                                        SetHideTips( GEBool const & );
        void                                        SetIsConsumingItem( GEBool const & );
        void                                        SetLPAttribs( GEI32 const & );
        void                                        SetLPPerks( GEI32 const & );
        void                                        SetLastSpell( bCPropertyID const & );
        void                                        SetLastWeaponConfig( bTPropertyContainer<gEWeaponConfig> const & );
        GEBool                                      SetMaximum( bCString const &, GEInt );
        GEBool                                      SetModifier( bCString const &, GEInt );
        void                                        SetPlayerKnows( bTObjArray<bCString> const & );
        void                                        SetPoliticalCrimeCount( bTValArray<GEI32> const & );
        void                                        SetPoliticalFame( bTValArray<GEI32> const & );
        void                                        SetPoliticalPlayerCrime( bTValArray<GEBool> const & );
        void                                        SetPoliticalSuspectComment( bTValArray<GEI32> const & );
        void                                        SetSecondsMistRemain( GEFloat const & );
        void                                        SetSecondsTransformRemain( GEFloat const & );
        void                                        SetTalkedToDiego( GEBool const & );
        void                                        SetTalkedToGorn( GEBool const & );
        void                                        SetTalkedToLester( GEBool const & );
        void                                        SetTalkedToMilten( GEBool const & );
        void                                        SetTimeStampStart( GEFloat const & );
        void                                        SetTutorialFlags( GEU32 const & );
        GEBool                                      SetValue( bCString const &, GEInt );
        void                                        SetXP( GEI32 const & );
        GEBool                                      UnapplyMod( bCString const &, GEInt, EAttribModOperation );

    protected:
        GEBool CreateAttrib( bCString const & );
        GEInt  CreateAttributes( void );
        GEBool CreateStat( bCString const & );
        void   DestroyAttributes( void );
        void   Invalidate( void );
        GEBool ReadAttributes( bCIStream & );
        GEBool ReadAttributesV3( bCIStream & );
        GEBool ReadAttributesV4( bCIStream & );
        GEBool WriteAttributes( bCOStream & );

};

#endif
