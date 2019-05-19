#ifndef GFC_TOOLBARCTRL_H_INCLUDED
#define GFC_TOOLBARCTRL_H_INCLUDED

class GE_DLLIMPORT CFFGFCToolBarCtrl :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCToolBarCtrl( void );

    public:
        CFFGFCToolBarCtrl( CFFGFCToolBarCtrl const & );
        CFFGFCToolBarCtrl( void );

    public:
        CFFGFCToolBarCtrl & operator = ( CFFGFCToolBarCtrl const & );

    public:
        GEBool Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );

};

#endif
