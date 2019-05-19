#ifndef GE_KEYBOARD_H_INCLUDED
#define GE_KEYBOARD_H_INCLUDED

class GE_DLLIMPORT eCKeyboard :
    public bCObjectRefBase
{
    public: virtual GEBool   IsValid( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual         ~eCKeyboard( void );

    public:
        eCKeyboard( eCKeyboard const & );
        eCKeyboard( void );

    public:
        eCKeyboard & operator = ( eCKeyboard const & );

    public:
        GEBool                                     AnyKeyPressed( void ) const;
        void                                       ClearKeyBuffer( void );
        bEResult                                   Create( HWND__ *, eCInpShared::eECoopLevel );
        bEResult                                   Execute( void );
        bEResult                                   GetBufferSize( GEU32 & ) const;
        bEResult                                   GetBufferedData( GEU32 &, eCInpShared::eSInpBufferedData *, GEBool & ) const;
        GEBool                                     GetCapsLock( void ) const;
        eCInpShared::eEKeyboardStateOffset const & GetKeyByName( bCString const & );
        bCString                                   GetKeyName( eCInpShared::eEKeyboardStateOffset & );
        bCUnicodeString                            GetLocalizedKeyName( eCInpShared::eEKeyboardStateOffset & );
        GEBool                                     GetNumLock( void ) const;
        GEU32                                      GetNumOccuredEvents( void );
        eCInpShared::eSInputMessage const &        GetOccuredEvent( GEU32 ) const;
        bEResult                                   GetState( eCInpShared::eSInpKeyboardState & ) const;
        void                                       Invalidate( void );
        GEBool                                     KeyPressed( eCInpShared::eEKeyboardStateOffset ) const;
        GEBool                                     KeyToggled( eCInpShared::eEKeyboardStateOffset ) const;
        void                                       ResetRepeatKey( GEBool );
        bEResult                                   SetBufferSize( GEU32 );
        void                                       SetCapsLock( GEBool );
        void                                       SetNumLock( GEBool );
        void                                       ToggleCapsLock( void );
        void                                       ToggleNumLock( void );

    protected:
        void   CreateKeyNames( void );
        void   CreateOccuredKeyList( void );
        GEChar GetCharacter( eCInpShared::eSInputMessage & );
        void   HandleAutoRepeat( void );
        void   HandleBufferOverflow( bTObjArray<eCInpShared::eSInputMessage> & );

};

#endif
