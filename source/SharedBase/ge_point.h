#ifndef GE_POINT_H_INCLUDED
#define GE_POINT_H_INCLUDED

class GE_DLLIMPORT bCPoint
{

    public:
         bCPoint( tagPOINT const & );
         bCPoint( bCPoint const & );
         bCPoint( void );
        ~bCPoint( void );

    public:
        bCPoint const & operator =                ( tagPOINT const & );
        bCPoint const & operator =                ( bCPoint const & );
        bCOStream &     operator >>               ( bCOStream & ) const;
        bCIStream &     operator <<               ( bCIStream & );
        GEBool          operator ==               ( bCPoint const & ) const;
        GEBool          operator !=               ( bCPoint const & ) const;
        GEI32 &         operator []               ( GEInt );
        GEI32           operator []               ( GEInt ) const;
                        operator tagPOINT &       ( void );
                        operator tagPOINT *       ( void );
                        operator tagPOINT const & ( void ) const;
                        operator tagPOINT const * ( void ) const;
        bCPoint         operator *                ( GEFloat ) const;
        bCPoint         operator -                ( bCPoint const & ) const;
        bCPoint         operator -                ( void ) const;
        bCPoint         operator +                ( bCPoint const & ) const;
        bCPoint const & operator +                ( void ) const;
        bCPoint         operator /                ( GEFloat ) const;
        bCPoint &       operator *=               ( GEFloat );
        bCPoint const & operator +=               ( bCPoint const & );
        bCPoint const & operator -=               ( bCPoint const & );
        bCPoint &       operator /=               ( GEFloat );

    public:
                bCPoint( GEI32, GEI32 );
        GEI32 & AccessX( void );
        GEI32 & AccessY( void );
        void    Clear( void );
        bCPoint GetInvScaled( GEFloat ) const;
        bCPoint GetScaled( GEFloat ) const;
        GEI32   GetX( void ) const;
        void    GetX( GEI32 & ) const;
        GEI32   GetY( void ) const;
        void    GetY( GEI32 & ) const;
        void    InvScale( GEFloat );
        void    InvTranslate( bCPoint const & );
        void    InvTranslate( GEI32, GEI32 );
        void    Scale( GEFloat );
        void    SetPoint( tagPOINT const & );
        void    SetPoint( bCPoint const & );
        void    SetPoint( GEI32, GEI32 );
        void    SetX( GEI32 );
        void    SetY( GEI32 );
        void    Translate( bCPoint const & );
        void    Translate( GEI32, GEI32 );

    private:
        GEI32 m_iX;
        GEI32 m_iY;

};

#endif
