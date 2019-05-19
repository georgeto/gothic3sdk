#ifndef GE_RANGE4_H_INCLUDED
#define GE_RANGE4_H_INCLUDED

class GE_DLLIMPORT bCRange4
{

    public:
         bCRange4( bCRange4 const & );
         bCRange4( void );
        ~bCRange4( void );

    public:
        bCRange4 &  operator =  ( bCRange4 const & );
        bCOStream & operator >> ( bCOStream & ) const;
        bCIStream & operator << ( bCIStream & );

    public:
        bCVector4 GetCenter( void ) const;
        void      GetCenter( bCVector4 & ) const;
        bCVector4 GetMagnitude( void ) const;
        void      GetMagnitude( bCVector4 & ) const;
        bCVector4 GetRandom( void ) const;
        void      GetRandom( bCVector4 & ) const;
        void      SetAverageAndVariance( bCVector4 const &, bCVector4 const & );
        void      SetMinMax( bCVector4 const &, bCVector4 const & );

};

#endif
