#ifndef GS_PSMOVER_H_INCLUDED
#define GS_PSMOVER_H_INCLUDED

class gCMover_PS;

GS_DECLARE_PROPERTYSET( PSMover, gCMover_PS )
public:
    GS_DECLARE_PROPERTY( MoverState, gEMoverState )

public:
    GEBool IsValid( void ) const;
    void   Toggle( void );

};

#endif
