#ifndef GE_INVENTORYSTACK_H_INCLUDED
#define GE_INVENTORYSTACK_H_INCLUDED

class GE_DLLIMPORT gCInventoryStack :
    public gCInventorySlot
{
    public:    virtual void               Destroy( void );
    public:    virtual                   ~gCInventoryStack( void );
    public:    virtual bEResult           PostInitializeProperties( void );
    protected: virtual void               OnApplyStats( eCEntity *, eCEntity * );
    protected: virtual void               OnUnApplyStats( eCEntity *, eCEntity * );
    public:    virtual gCInventoryStack * Clone( void ) const;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCInventoryStack( gCInventoryStack const & );
        gCInventoryStack( void );

    public:
        gCInventoryStack const & operator = ( gCInventoryStack const & );

    public:
        GEInt &                                  AccessActivationCount( void );
        GEInt &                                  AccessAmount( void );
        GEBool &                                 AccessLearned( void );
        GEInt &                                  AccessQuality( void );
        GEInt &                                  AccessQuickSlot( void );
        GEInt &                                  AccessSortIndex( void );
        GEInt &                                  AccessTransactionCount( void );
        bTPropertyContainer<gEStackType> &       AccessType( void );
        GEBool                                   CanMerge( gCInventoryStack const & ) const;
        GEInt                                    Compare( gCInventoryStack const & ) const;
        eCEntity *                               Drop( eCEntity * );
        GEInt const &                            GetActivationCount( void ) const;
        GEInt const &                            GetAmount( void ) const;
        GEU32                                    GetCombinedQuality( void ) const;
        CFFGFCBitmap *                           GetIcon( void );
        GEInt                                    GetItemGoldValue( void ) const;
        GEBool const &                           GetLearned( void ) const;
        GEInt const &                            GetQuality( void ) const;
        GEInt const &                            GetQuickSlot( void ) const;
        GEInt const &                            GetSortIndex( void ) const;
        GEInt                                    GetStackGoldValue( void ) const;
        GEInt                                    GetTransactionAmount( void ) const;
        GEInt const &                            GetTransactionCount( void ) const;
        GEInt                                    GetTransferAmount( void ) const;
        GEInt                                    GetTransferRemainder( void ) const;
        bTPropertyContainer<gEStackType> const & GetType( void ) const;
        GEBool                                   IsDisposable( void ) const;
        GEBool                                   IsEmpty( void ) const;
        GEBool                                   IsEquipped( eCEntity const * ) const;
        GEBool                                   IsEquippedInAlternative( eCEntity const * ) const;
        GEBool                                   IsEquippedInPrimary( eCEntity const * ) const;
        GEBool                                   IsEquippedToSlot( gESlot ) const;
        GEBool                                   IsMergable( void ) const;
        GEBool                                   Merge( gCInventoryStack * );
        GEBool                                   MustSplitBeforeLinking( gESlot, eCEntity * ) const;
        void                                     SetActivationCount( GEInt const & );
        void                                     SetAmount( GEInt const & );
        void                                     SetLearned( GEBool const & );
        void                                     SetQuality( GEInt const & );
        void                                     SetQuickSlot( GEInt const & );
        void                                     SetSortIndex( GEInt const & );
        void                                     SetTransactionAmount( GEInt );
        void                                     SetTransactionCount( GEInt const & );
        void                                     SetType( bTPropertyContainer<gEStackType> const & );
        gCInventoryStack *                       Split( GEInt );

    protected:
        void  ApplyDefaults( void );
        GEInt CompareAlchemy( gCInventoryStack const & ) const;
        GEInt CompareArmor( gCInventoryStack const & ) const;
        GEInt CompareArmorType( gCInventoryStack const & ) const;
        GEInt CompareArtefact( gCInventoryStack const & ) const;
        GEInt CompareDamage( gCInventoryStack const & ) const;
        GEInt CompareDefault( gCInventoryStack const & ) const;
        GEInt CompareDocument( gCInventoryStack const & ) const;
        GEInt CompareFocusName( gCInventoryStack const & ) const;
        GEInt CompareMisc( gCInventoryStack const & ) const;
        GEInt CompareName( gCInventoryStack const & ) const;
        GEInt ComparePotionType( gCInventoryStack const & ) const;
        GEInt CompareProtection( gCInventoryStack const & ) const;
        GEInt CompareQuality( gCInventoryStack const & ) const;
        GEInt CompareQuickSlot( gCInventoryStack const & ) const;
        GEInt CompareRecipe( gCInventoryStack const & ) const;
        GEInt CompareSkill( gCInventoryStack const & ) const;
        GEInt CompareSlot( gCInventoryStack const & ) const;
        GEInt CompareSpell( gCInventoryStack const & ) const;
        GEInt CompareTemplate( gCInventoryStack const & ) const;
        GEInt CompareType( gCInventoryStack const & ) const;
        GEInt CompareValue( gCInventoryStack const & ) const;
        GEInt CompareWeapon( gCInventoryStack const & ) const;
        GEInt CompareWeaponType( gCInventoryStack const & ) const;
        void  CreateIcons( void );
        void  GetIconFileNames( bCString &, bCString & ) const;
        void  Invalidate( void );

};

#endif
