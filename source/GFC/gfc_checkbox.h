#ifndef GFC_CHECKBOX_H_INCLUDED
#define GFC_CHECKBOX_H_INCLUDED

class GE_DLLIMPORT CFFGFCCheckBox :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCCheckBox( void );

    public:
        CFFGFCCheckBox( CFFGFCCheckBox const & );
        CFFGFCCheckBox( void );

    public:
        CFFGFCCheckBox & operator = ( CFFGFCCheckBox const & );

    public:
        GEBool Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        GEBool GetCheck( void ) const;
        void   SetCheck( GEBool );

};

#endif
