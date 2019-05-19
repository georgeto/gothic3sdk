#ifndef GS_PSANIMATION_H_INCLUDED
#define GS_PSANIMATION_H_INCLUDED

class eCVisualAnimation_PS;

GS_DECLARE_PROPERTYSET( PSAnimation, eCVisualAnimation_PS )
public:
    void     AddForceAtPos( bCVector, bCVector );
    void     EnableControllerCollision( GEBool );
    bCString GetResourceName( void ) const;
    GEBool   GetSkeletonName( bCString & ) const;
    GEBool   IsValid( void ) const;
    void     PauseControllers( GEBool, GEFloat );
    void     PullTo( bCVector, GEFloat );
    void     SetTimeScale( GEFloat );

};

#endif
