#ifndef GS_PSDOOR_H_INCLUDED
#define GS_PSDOOR_H_INCLUDED

class gCDoor_PS;

GS_DECLARE_PROPERTYSET( PSDoor, gCDoor_PS )
public:
    void   Close( GEBool );
    GEBool IsClosed( void ) const;
    GEBool IsOpen( void ) const;
    GEBool IsValid( void ) const;
    void   Open( GEBool );

};

#endif
