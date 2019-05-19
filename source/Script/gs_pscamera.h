#ifndef GS_PSCAMERA_H_INCLUDED
#define GS_PSCAMERA_H_INCLUDED

class gCCameraAI_PS;
enum gECameraMode;

GS_DECLARE_PROPERTYSET( PSCamera, gCCameraAI_PS )
public:
    void         EnableSpecialBowMode( GEBool );
    void         EnableTempFirstPerson( GEBool );
    gECameraMode GetLastMode( void ) const;
    gECameraMode GetMode( void ) const;
    bCVector     GetScreenCenterPickPoint( void ) const;
    GEBool       IsInFirstPerson( void ) const;
    GEBool       IsInSpecialBowMode( void ) const;
    GEBool       IsInTempFirstPerson( void ) const;
    GEBool       IsValid( void ) const;
    void         SetDialogRoles( Entity &, Entity & );
    void         SetMode( gECameraMode, GEBool, GEBool );
    void         StopDialogCamera( void );

};

#endif
