#ifndef GE_RECT_H_INCLUDED
#define GE_RECT_H_INCLUDED

class GE_DLLIMPORT bCRect
{

    public:
         bCRect( tagRECT const & );
         bCRect( bCRect const & );
         bCRect( void );
        ~bCRect( void );

    public:
        bCRect &        operator =               ( tagRECT const & );
        bCRect &        operator =               ( bCRect const & );
        bCOStream &     operator >>              ( bCOStream & ) const;
        bCIStream &     operator <<              ( bCIStream & );
        GEBool          operator ==              ( bCRect const & ) const;
        GEBool          operator !=              ( bCRect const & ) const;
        bCPoint &       operator []              ( int );
        bCPoint const & operator []              ( int ) const;
                        operator tagRECT &       ( void );
                        operator tagRECT *       ( void );
                        operator tagRECT const & ( void ) const;
                        operator tagRECT const * ( void ) const;
        bCRect          operator -               ( bCPoint const & ) const;
        bCRect          operator +               ( bCPoint const & ) const;
        bCRect          operator &               ( bCRect const & ) const;
        GEI32 &         operator ()              ( GEInt );
        GEI32           operator ()              ( GEInt ) const;
        bCRect          operator |               ( bCRect const & ) const;
        bCRect &        operator +=              ( bCPoint const & );
        bCRect &        operator -=              ( bCPoint const & );
        bCRect &        operator &=              ( bCRect const & );
        bCRect &        operator |=              ( bCRect const & );

    public:
                        bCRect( bCPoint const &, bCPoint const & );
                        bCRect( GEI32 a_TopLeftX, GEI32 a_TopLeftY, GEI32 a_BottomRightX, GEI32 a_BottomRightY );
        GEI32 &         AccessBottom( void );
        bCPoint &       AccessBottomRight( void );
        GEI32 &         AccessCoordinate( GEInt );
        GEI32 &         AccessLeft( void );
        bCPoint &       AccessPoint( int );
        GEI32 &         AccessRight( void );
        GEI32 &         AccessTop( void );
        bCPoint &       AccessTopLeft( void );
        GEBool          Contains( bCRect const & ) const;
        GEBool          Contains( bCPoint const & ) const;
        GEBool          ContainsExclusive( bCPoint const & ) const;
        GEBool          ContainsInclusive( bCPoint const & ) const;
        GEI32           GetBottom( void ) const;
        void            GetBottom( GEI32 & ) const;
        bCPoint const & GetBottomRight( void ) const;
        void            GetBottomRight( bCPoint & ) const;
        bCPoint         GetCenterPoint( void ) const;
        GEI32           GetCoordinate( GEInt ) const;
        void            GetCoordinate( GEI32 &, GEInt ) const;
        GEI32           GetHeight( void ) const;
        bCRect          GetIntersected( bCRect const & ) const;
        GEI32           GetLeft( void ) const;
        void            GetLeft( GEI32 & ) const;
        bCPoint         GetMagnitude( void ) const;
        bCRect          GetMerged( bCRect const & ) const;
        bCPoint const & GetPoint( int ) const;
        void            GetPoint( bCPoint &, int ) const;
        GEI32           GetRight( void ) const;
        void            GetRight( GEI32 & ) const;
        GEI32           GetTop( void ) const;
        void            GetTop( GEI32 & ) const;
        bCPoint const & GetTopLeft( void ) const;
        void            GetTopLeft( bCPoint & ) const;
        GEI32           GetWidth( void ) const;
        void            Inflate( GEI32 const & );
        void            Intersect( bCRect const & );
        GEBool          Intersects( bCRect const & ) const;
        void            InvTranslate( bCPoint const & );
        void            InvTranslate( GEI32, GEI32 );
        void            Invalidate( void );
        GEBool          IsEmpty( void ) const;
        GEBool          IsNormalized( void ) const;
        GEBool          IsValid( void ) const;
        void            Merge( bCRect const & );
        void            Merge( bCPoint const & );
        void            Normalize( void );
        void            SetBottom( GEI32 );
        void            SetBottomRight( bCPoint const & );
        void            SetCoordinate( GEI32, GEInt );
        void            SetLeft( GEI32 );
        void            SetPoint( bCPoint const &, int );
        void            SetRect( tagRECT const & );
        void            SetRect( bCRect const & );
        void            SetRect( bCPoint const &, bCPoint const & );
        void            SetRect( GEI32, GEI32, GEI32, GEI32 );
        void            SetRect( void );
        void            SetRight( GEI32 );
        void            SetTop( GEI32 );
        void            SetTopLeft( bCPoint const & );
        void            Shrink( bCRect const & );
        void            Shrink( bCPoint const & );
        void            Translate( bCPoint const & );
        void            Translate( GEI32, GEI32 );
        void            Widen( bCRect const & );
        void            Widen( bCPoint const & );

    private:
        bCPoint m_TopLeft;
        bCPoint m_BottomRight;
};

#endif
