#ifndef GE_RANGE2_H_INCLUDED
#define GE_RANGE2_H_INCLUDED

class GE_DLLIMPORT bCRange2
{

    public:
         bCRange2( bCRange2 const & );
         bCRange2( void );
        ~bCRange2( void );

    public:
        bCRange2 &  operator =  ( bCRange2 const & );
        bCOStream & operator >> ( bCOStream & ) const;
        bCIStream & operator << ( bCIStream & );

    public:
        bCVector2 GetCenter( void ) const;
        void      GetCenter( bCVector2 & ) const;
        bCVector2 GetMagnitude( void ) const;
        void      GetMagnitude( bCVector2 & ) const;
        bCVector2 GetRandom( void ) const;
        void      GetRandom( bCVector2 & ) const;
        void      SetAverageAndVariance( bCVector2 const &, bCVector2 const & );
        void      SetMinMax( bCVector2 const &, bCVector2 const & );

};

#endif
