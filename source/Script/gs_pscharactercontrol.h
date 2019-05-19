#ifndef GS_PSCHARACTERCONTROL_H_INCLUDED
#define GS_PSCHARACTERCONTROL_H_INCLUDED

class gCCharacterControl_PS;

GS_DECLARE_PROPERTYSET( PSCharacterControl, gCCharacterControl_PS )
public:
    GS_DECLARE_PROPERTY( ControlFrameOfReference, gECharacterControlFOR )
    GS_DECLARE_PROPERTY( DurationPressedMSecs,    GEU32 )
    GS_DECLARE_PROPERTY( IsPressed,               GEBool )
    GS_DECLARE_PROPERTY( IsPressedBefore,         GEBool )
    GS_DECLARE_PROPERTY( PressedKey,              gESessionKey )

public:
    GEBool IsValid( void ) const;
    void   SetMovementConstraints( GEFloat );

};

#endif