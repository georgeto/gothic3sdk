#ifndef GFC_EDIT_H_INCLUDED
#define GFC_EDIT_H_INCLUDED

class GE_DLLIMPORT CFFGFCEdit :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCEdit( void );

    public:
        CFFGFCEdit( CFFGFCEdit const & );
        CFFGFCEdit( void );

    public:
        CFFGFCEdit & operator = ( CFFGFCEdit const & );

    public:
        GEBool Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );

};

#endif
