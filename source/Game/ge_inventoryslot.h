#ifndef GE_INVENTORYSLOT_H_INCLUDED
#define GE_INVENTORYSLOT_H_INCLUDED

enum ELink;

class GE_DLLIMPORT gCInventorySlot :
    public bCObjectRefBase
{
    protected: virtual void              OnApplyStats( eCEntity *, eCEntity * );
    protected: virtual void              OnUnApplyStats( eCEntity *, eCEntity * );
    public:    virtual gCInventorySlot * Clone( void ) const;
    public:    virtual void              Destroy( void );
    public:    virtual                  ~gCInventorySlot( void );
    public:    virtual bEResult          PostInitializeProperties( void );

    public:
        static GEBool GE_STDCALL                       GetBone( gESlot, gEUseType, bCString &, ELink & );
        static GEBool GE_STDCALL                       GetEquipSlots( gEUseType, gESlot &, gESlot &, eCEntity const * );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCInventorySlot( gCInventorySlot const & );
        gCInventorySlot( void );

    public:
        gCInventorySlot const & operator = ( gCInventorySlot const & );

    public:
        eCEntityProxy &                     AccessItem( void );
        bTPropertyContainer<gESlot> &       AccessSlot( void );
        eCTemplateEntityProxy &             AccessTemplate( void );
        GEBool                              EnableRendering( GEBool, eCEntity * );
        gESlot                              GetAlternativeEquipSlot( eCEntity const * ) const;
        gEItemCategory                      GetCategory( void ) const;
        GEBool                              GetEquipSlots( gESlot &, gESlot &, eCEntity const * ) const;
        eCEntityProxy const &               GetItem( void ) const;
        gESlot                              GetPrimaryEquipSlot( eCEntity const * ) const;
        bTPropertyContainer<gESlot> const & GetSlot( void ) const;
        eCTemplateEntityProxy const &       GetTemplate( void ) const;
        gEUseType                           GetUseType( void ) const;
        GEBool                              IsConsumable( void ) const;
        GEBool                              IsEquipment( void ) const;
        GEBool                              IsLinked( void ) const;
        GEBool                              IsPermanent( void ) const;
        GEBool                              LinkToSlot( eCEntity *, gESlot );
        GEBool                              ReBuildSlot( eCEntity * );
        void                                SetItem( eCEntityProxy const & );
        void                                SetSlot( bTPropertyContainer<gESlot> const & );
        void                                SetTemplate( eCTemplateEntityProxy const & );
        GEBool                              UnLinkFromSlot( eCEntity * );
        GEBool                              UpdateVisibility( eCEntity * );

    protected:
        static GEBool GE_STDCALL     AttachItemToSekelton( eCEntity *, eCEntity *, gESlot );
        static GEBool GE_STDCALL     DetachItemFromSkeleton( eCEntity *, eCEntity *, gESlot );
        static GEBool GE_STDCALL     EnableItemRendering( eCEntity *, eCEntity *, gESlot, GEBool );
        static eCEntity * GE_STDCALL SpawnItem( eCEntity *, eCTemplateEntity const *, GEBool );
        static GEBool GE_STDCALL     UpdateItemVisibility( eCEntity *, eCEntity *, gESlot );

    protected:
        void       ApplyDefaults( void );
        void       Invalidate( void );
        eCEntity * SpawnItem( eCEntity * ) const;
        eCEntity * SpawnPickUp( eCEntity * ) const;

};

#endif
