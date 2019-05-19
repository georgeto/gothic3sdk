#ifndef GFC_ANIMATEDIMAGE_H_INCLUDED
#define GFC_ANIMATEDIMAGE_H_INCLUDED

class GE_DLLIMPORT CFFGFCAnimatedImage :
    public virtual CFFGFCWnd
{
    public: virtual void OnPaint( void );
    public: virtual     ~CFFGFCAnimatedImage( void );

    public:
        CFFGFCAnimatedImage( CFFGFCAnimatedImage const & );
        CFFGFCAnimatedImage( void );

    public:
        CFFGFCAnimatedImage & operator = ( CFFGFCAnimatedImage const & );

    public:
        void           AddImage( bCUnicodeString );
        void           AddImageByName( bCUnicodeString );
        GEBool         Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        void           CreateImageList( bTValArray<bCUnicodeString>);
        GEInt          GetAniSpeed( void );
        IFFGUIBitmap * GetBitmap( void ) const;
        IFFGUIBitmap * GetImage( void );
        GEInt          GetTimer( void );
        void           GotoImage( GEInt );
        GEBool         IsAutoplay( void );
        GEBool         IsRepeat( void );
        void           Pause( void );
        void           Play( void );
        void           ResetTimer( void );
        void           SetAniSpeed( GEInt );
        GEBool         SetAutoplay( GEBool );
        IFFGUIBitmap * SetBitmap( IFFGUIBitmap * );
        GEBool         SetRepeat( GEBool );
        void           ShowPicture( void );
        void           UpdateTimer( void );

};

#endif
