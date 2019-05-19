#ifndef GFC_SLIDER_H_INCLUDED
#define GFC_SLIDER_H_INCLUDED

class GE_DLLIMPORT CFFGFCSlider :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCSlider( void );

    public:
        CFFGFCSlider( CFFGFCSlider const & );
        CFFGFCSlider( void );

    public:
        CFFGFCSlider & operator = ( CFFGFCSlider const & );

    public:
        GEBool Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        GEInt  GetPos( void ) const;
        void   GetRange( GEInt &, GEInt & ) const;
        GEInt  GetRangeMax( void ) const;
        GEInt  GetRangeMin( void ) const;
        void   GetThumbRect( bCRect & ) const;
        void   SetPos( GEInt );
        void   SetRange( GEInt, GEInt );
        void   SetRangeMax( GEInt );
        void   SetRangeMin( GEInt );

};

#endif
