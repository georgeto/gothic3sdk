#ifndef GFC_ANIMATECTRL_H_INCLUDED
#define GFC_ANIMATECTRL_H_INCLUDED

class GE_DLLIMPORT CFFGFCAnimateCtrl :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCAnimateCtrl( void );

    public:
        CFFGFCAnimateCtrl( CFFGFCAnimateCtrl const & );
        CFFGFCAnimateCtrl( void );

    public:
        CFFGFCAnimateCtrl & operator = ( CFFGFCAnimateCtrl const & );

    public:
        GEBool Close( void );
        GEBool Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        GEBool Open( bCString const & );
        GEBool Play( GEInt, GEInt, GEInt );
        GEBool Seek( GEInt );
        GEBool Stop( void );

};

#endif
