#ifndef GS_PSARENA_H_INCLUDED
#define GS_PSARENA_H_INCLUDED

class gCArena_PS;

GS_DECLARE_PROPERTYSET( PSArena, gCArena_PS )
public:
    GS_DECLARE_PROPERTY( Status, gEArenaStatus )

public:
    GEBool IsValid( void ) const;

};

#endif
