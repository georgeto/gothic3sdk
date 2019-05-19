#ifndef GE_CLOCK_PS_H_INCLUDED
#define GE_CLOCK_PS_H_INCLUDED

class GE_DLLIMPORT gCClock_PS :
    public eCEntityPropertySet
{
    public: virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult                                   Write( bCOStream & );
    public: virtual bEResult                                   Read( bCIStream & );
    public: virtual void                                       Destroy( void );
    public: virtual bEResult                                   Create( void );
    public: virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public: virtual                                           ~gCClock_PS( void );
    public: virtual bEResult                                   PostInitializeProperties( void );
    public: virtual GEBool                                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public: virtual GEBool                                     IsProcessable( void ) const;
    public: virtual bEResult                                   ReadSaveGame( bCIStream & );
    public: virtual bEResult                                   WriteSaveGame( bCOStream & );
    public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public: virtual void                                       OnProcess( void );
    public: virtual void                                       OnPreProcess( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCClock_PS( gCClock_PS const & );
        gCClock_PS( void );

    public:
        gCClock_PS const & operator = ( gCClock_PS const & );

    public:
        GEU32 &         AccessDay( void );
        GEFloat &       AccessFactor( void );
        GEU32 &         AccessHour( void );
        GEU32 &         AccessMinute( void );
        GEU32 &         AccessSecond( void );
        GEU32 &         AccessYear( void );
        GEU32 const &   GetDay( void ) const;
        GEFloat const & GetFactor( void ) const;
        GEU32 const &   GetHour( void ) const;
        GEU32 const &   GetMinute( void ) const;
        GEU32 const &   GetSecond( void ) const;
        GEU32           GetTimeStampInSeconds( void ) const;
        GEU32 const &   GetYear( void ) const;
        GEBool          IsPaused( void ) const;
        void            PauseClock( void );
        void            ResumeClock( void );
        void            SetDay( GEU32 const & );
        void            SetFactor( GEFloat const & );
        void            SetHour( GEU32 const & );
        void            SetMinute( GEU32 const & );
        void            SetSecond( GEU32 const & );
        void            SetYear( GEU32 const & );

    protected:
        void Invalidate( void );

};

#endif
