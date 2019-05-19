#ifndef GS_PSANCHOR_H_INCLUDED
#define GS_PSANCHOR_H_INCLUDED

class gCAnchor_PS;

GS_DECLARE_PROPERTYSET( PSAnchor, gCAnchor_PS )
public:
    GS_DECLARE_PROPERTY( AnchorType,  gEAnchorType )
    GS_DECLARE_PROPERTY( MaxUsers,    GEU32 )
    GS_DECLARE_PROPERTY( PatrolIndex, GEU32 )
    GS_DECLARE_PROPERTY( UserCount,   GEU32 )

public:
    bTObjArray<Entity> GetInteractPoints( GEBool ) const;
    GEBool             IsValid( void ) const;

};

#endif