#ifndef GE_RANGE1_H_INCLUDED
#define GE_RANGE1_H_INCLUDED

class GE_DLLIMPORT bCRange1
{

    public:
        bCRange1 &  operator =  ( bCRange1 const & );
        bCOStream & operator >> ( bCOStream & ) const;
        bCIStream & operator << ( bCIStream & );

    public:
        GEFloat GetCenter( void ) const;
        void    GetCenter( GEFloat & ) const;
        GEFloat GetMagnitude( void ) const;
        void    GetMagnitude( GEFloat & ) const;
        GEFloat GetRandom( void ) const;
        void    GetRandom( GEFloat & ) const;
        GEInt   GetRandomInt( void ) const;
        void    GetRandomInt( GEInt & ) const;
        void    SetAverageAndVariance( GEFloat, GEFloat );
        void    SetMinMax( GEFloat, GEFloat );

};

#endif
