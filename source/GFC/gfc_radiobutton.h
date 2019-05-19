#ifndef GFC_RADIOBUTTON_H_INCLUDED
#define GFC_RADIOBUTTON_H_INCLUDED

class GE_DLLIMPORT CFFGFCRadioButton :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCRadioButton( void );

    public:
        CFFGFCRadioButton( CFFGFCRadioButton const & );
        CFFGFCRadioButton( void );

    public:
        CFFGFCRadioButton & operator = ( CFFGFCRadioButton const & );

    public:
        GEBool Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );

};

#endif
