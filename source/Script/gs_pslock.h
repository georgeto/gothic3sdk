#ifndef GS_PSLOCK_H_INCLUDED
#define GS_PSLOCK_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSLock, gCLock_PS )
public:
    GS_DECLARE_PROPERTY( Difficulty, GEInt )
    GS_DECLARE_PROPERTY( KeyAmount,  GEInt )
    GS_DECLARE_PROPERTY( Status,     gELockStatus )

public:
    Template GetKey( void ) const;
    GEBool   IsLocked( void ) const;
    GEBool   IsUnlocked( void ) const;
    GEBool   IsValid( void ) const;

};

#endif
