#ifndef GE_TREASURESET_PS_H_INCLUDED
#define GE_TREASURESET_PS_H_INCLUDED

class gCInventory_PS;

class GE_DLLIMPORT gCTreasureSet_PS :
    public eCEntityPropertySet
{
    public: virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult          Write( bCOStream & );
    public: virtual bEResult          Read( bCIStream & );
    public: virtual void              Destroy( void );
    public: virtual bEResult          Create( void );
    public: virtual                  ~gCTreasureSet_PS( void );
    public: virtual eEPropertySetType GetPropertySetType( void ) const;
    public: virtual GEBool            IsVisual( void ) const;
    public: virtual void              GetBoundary( bCBox &, GEBool );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCTreasureSet_PS( gCTreasureSet_PS const & );
        gCTreasureSet_PS( void );

    public:
        gCTreasureSet_PS const & operator = ( gCTreasureSet_PS const & );

    public:
        GEU32 &                                             AccessMaxTransferStacks( void );
        GEU32 &                                             AccessMinTransferStacks( void );
        bTPropertyContainer<gETreasureDistribution> &       AccessTreasureDistribution( void );
        GEBool                                              GeneratePlunderInventory( gCInventory_PS * );
        GEBool                                              GenerateTradeInventory( gCInventory_PS * );
        GEU32 const &                                       GetMaxTransferStacks( void ) const;
        GEU32 const &                                       GetMinTransferStacks( void ) const;
        bTPropertyContainer<gETreasureDistribution> const & GetTreasureDistribution( void ) const;
        GEBool                                              RefreshTradeInventory( gCInventory_PS * );
        void                                                SetMaxTransferStacks( GEU32 const & );
        void                                                SetMinTransferStacks( GEU32 const & );
        void                                                SetTreasureDistribution( bTPropertyContainer<gETreasureDistribution> const & );

    protected:
        void Invalidate( void );

};

#endif
