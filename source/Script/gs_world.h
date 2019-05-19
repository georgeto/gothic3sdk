#ifndef GS_WORLD_H_INCLUDED
#define GS_WORLD_H_INCLUDED

class GE_DLLIMPORT World
{
    public:
         World( void );
        ~World( void );

    public:
        World & operator = ( World const & );

    public:
        GEBool EnableSectorFolder( bCString const &, GEBool );
        GEBool GetSectorStatus( bCString const & );
        GEBool SetSectorStatus( bCString const &, GEBool );

};

GE_DLLIMPORT_EXTC World world;

#endif
