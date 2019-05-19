#ifndef GE_INVENTORYLISTENER_H_INCLUDED
#define GE_INVENTORYLISTENER_H_INCLUDED

class GE_DLLIMPORT gCInventoryListener
{
    public: virtual void OnStackCreate( GEInt, gCInventoryStack const * );
    public: virtual void OnStackChange( GEInt, gCInventoryStack const * );
    public: virtual void OnStackDelete( GEInt, gCInventoryStack const * );
    public: virtual void OnSortInventory( void );
    public: virtual void OnDestroyInventory( void );

    public:
        gCInventoryListener( gCInventoryListener const & );
        gCInventoryListener( void );

    public:
        gCInventoryListener & operator = ( gCInventoryListener const & );

};

GE_ASSERT_SIZEOF(gCInventoryListener, 0x04)

#endif
