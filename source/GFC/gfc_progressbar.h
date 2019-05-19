#ifndef GFC_PROGRESSBAR_H_INCLUDED
#define GFC_PROGRESSBAR_H_INCLUDED

class GE_DLLIMPORT CFFGFCProgressBar :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCProgressBar( void );

    public:
        CFFGFCProgressBar( CFFGFCProgressBar const & );
        CFFGFCProgressBar( void );

    public:
        CFFGFCProgressBar & operator = ( CFFGFCProgressBar const & );

    public:
        GEBool Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        GEU32  GetBarColor( void ) const;
        GEU32  GetBkColor( void ) const;
        GEInt  GetPos( void ) const;
        void   GetRange( GEInt &, GEInt & ) const;
        void   OffsetPos( GEInt );
        void   SetBarColor( bCByteAlphaColor const & );
        void   SetBarColor( GEU32 );
        void   SetBkColor( bCByteAlphaColor const & );
        void   SetBkColor( GEU32 );
        void   SetPos( GEInt );
        void   SetRange( GEInt, GEInt );
        void   SetStep( GEInt );
        void   StepIt( void );

};

#endif
