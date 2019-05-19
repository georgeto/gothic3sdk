#ifndef GFC_FONT_H_INCLUDED
#define GFC_FONT_H_INCLUDED

class GE_DLLIMPORT CFFGFCFont
{
    public: virtual ~CFFGFCFont( void );

    public:
        CFFGFCFont( CFFGFCFont const & );
        CFFGFCFont( void );

    public:
        CFFGFCFont & operator = ( CFFGFCFont const & );

    public:
        GEBool Create( tagLOGFONTA const & );
        GEBool Create( GELPCChar, GEInt, GEInt, GEBool, GEBool, GEBool );
        GEU32  GetHandle( void ) const;
        void   SetHandle( GEU32 );

};

#endif
