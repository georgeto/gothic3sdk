#ifndef GS_PSRIGIDBODY_H_INCLUDED
#define GS_PSRIGIDBODY_H_INCLUDED

class eCRigidBody_PS;

GS_DECLARE_PROPERTYSET( PSRigidBody, eCRigidBody_PS )
public:
    GS_DECLARE_PROPERTY( AngularDamping, GEFloat )
    GS_DECLARE_PROPERTY( LinearDamping,  GEFloat )

public:
    void   AddForce( bCVector const & );
    void   HoverTo( bCVector const &, GEFloat );
    GEBool IsValid( void ) const;
    void   SetTimeScale( GEFloat );

};

#endif
