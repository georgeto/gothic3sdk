#ifndef GE_GUIADMIN_H_INCLUDED
#define GE_GUIADMIN_H_INCLUDED

class IFFGUIRenderer
{
};

struct SFFGUIFont
{
    bCString FaceName;
    GEU32    Height;
    GEU32    Width;
    GEU32    Weight;
    GEByte   CharSet;
    GEByte   OutPrecision;
    GEByte   Quality;
    GEByte   PitchAndFamily;
    GEByte   Italic;
    GE_PADDING(3)
};

class IFFGUITheme;
class eCGUIDatabase;
class eCGUIRenderer;
class eCGUIStreamer;

class GE_DLLIMPORT eCGUIAdmin :
    public IFFGUIRenderer
{
    public: virtual GEU32    CreateFontA( GELPCChar, GEInt, GEInt, GEBool, GEBool, GEBool );
    public: virtual GEU32    CreateFontA( tagLOGFONTA const & );
    public: virtual GEU32    CreateFontA( SFFGUIFont const & );
    public: virtual GEU32    CreateTexture( GELPCChar );
    public: virtual GEU32    CreateTexture( bCByteAlphaColor );
    public: virtual GELPVoid GetFontDC( GEU32 );
    public: virtual GEInt    GetFontHeight( GEU32 );
    public: virtual GEBool   GetFontDesc( GEU32, SFFGUIFont & );
    public: virtual GEInt    CalcTextRect( GEU32, GELPCChar, GEInt, bCRect *, GEU32 );
    public: virtual GEInt    CalcTextRect( GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32 );
    public: virtual GEBool   BeginFrame( void );
    public: virtual GEBool   EndFrame( void );
    public: virtual GEBool   DrawRect( bCRect const *, GEU32 );
    public: virtual GEBool   DrawSprite( GEU32, bCRect const *, bCVector const *, bCVector const *, bCMatrix const *, bCMatrix const *, GEU32 );
    public: virtual GEBool   DrawTextA( GEU32, GELPCChar, GEInt, bCRect *, GEU32, GEU32 );
    public: virtual GEBool   DrawTextA( GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32, GEU32 );
    public: virtual GEBool   SetClipRect( bCRect const * );
    public: virtual GEBool   LoadBitmapA( bCString const &, SFFGUIBitmap & );
    public: virtual GEBool   LoadTheme( IFFGUITheme * );
    public: virtual GEBool   SaveTheme( IFFGUITheme * );
    public: virtual GEBool   VideoPause( GEU32, GEBool );
    public: virtual GEBool   VideoStart( GEU32 );
    public: virtual GEBool   VideoStop( GEU32 );
    public: virtual GEBool   VideoSetPosition( GEU32, GEInt );
    public: virtual GEInt    VideoGetPosition( GEU32 );
    public: virtual GEBool   VideoEnableLooping( GEU32, GEBool );
    public: virtual GEBool   VideoMoveBackward( GEU32, GEInt );
    public: virtual GEBool   VideoMoveForward( GEU32, GEInt );
    public: virtual GEBool   VideoIsLoopingEnabled( GEU32 );
    public: virtual GEBool   VideoIsPaused( GEU32 );
    public: virtual GEBool   VideoIsRunning( GEU32 );
    public: virtual         ~eCGUIAdmin( void );

    public:
        eCGUIAdmin( eCGUIAdmin const & );
        eCGUIAdmin( void );

    public:
        eCGUIAdmin & operator = ( eCGUIAdmin const & );

    public:
        GEBool                Create( void );
        void                  Destroy( void );
        eCGUIDatabase &       GetDatabase( void );
        eCGUIDatabase const & GetDatabase( void ) const;
        eCGUIRenderer &       GetRenderer( void );
        eCGUIRenderer const & GetRenderer( void ) const;
        eCGUIStreamer &       GetStreamer( void );
        eCGUIStreamer const & GetStreamer( void ) const;

    protected:
        void Invalidate( void );

};

#endif
