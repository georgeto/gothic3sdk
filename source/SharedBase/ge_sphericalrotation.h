#ifndef GE_SPHERICALROTATION_H_INCLUDED
#define GE_SPHERICALROTATION_H_INCLUDED

class GE_DLLIMPORT bCSphericalRotation
{

    public:
         bCSphericalRotation( void );
        ~bCSphericalRotation( void );

    public:
        bCSphericalRotation & operator =  ( bCSphericalRotation const & );
        bCOStream &           operator >> ( bCOStream & ) const;
        bCIStream &           operator << ( bCIStream & );

    public:
        GEFloat & AccessAzimuth( void );
        GEFloat & AccessLatitude( void );
        GEFloat & AccessLongitude( void );
        GEFloat   GetAzimuth( void ) const;
        void      GetAzimuth( GEFloat & ) const;
        GEFloat   GetLatitude( void ) const;
        void      GetLatitude( GEFloat & ) const;
        GEFloat   GetLongitude( void ) const;
        void      GetLongitude( GEFloat & ) const;
        void      SetAzimuth( GEFloat );
        void      SetLatitude( GEFloat );
        void      SetLongitude( GEFloat );

};

#endif
