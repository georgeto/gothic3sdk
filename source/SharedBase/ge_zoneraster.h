#ifndef GE_ZONERASTER_H_INCLUDED
#define GE_ZONERASTER_H_INCLUDED

class GE_DLLIMPORT bCZoneRaster
{

    public:
         bCZoneRaster( bCZoneRaster const & );
        ~bCZoneRaster( void );

    public:
        bCZoneRaster & operator = ( bCZoneRaster const & );

    public:
        bCZoneRaster( bTValArray<bCVector> const & );

};

#endif
