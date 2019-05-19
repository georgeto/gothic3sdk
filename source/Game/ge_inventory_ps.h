#ifndef GE_INVENTORY_PS_H_INCLUDED
#define GE_INVENTORY_PS_H_INCLUDED

class gCInventory_PS_AH;
struct SMissingAttrib;
struct SMissingSkill;
enum gEInventoryFindQuality
{
    gEInventoryFindQuality_Ignore  = 0,
    gEInventoryFindQuality_Equal   = 1,
    gEInventoryFindQuality_Highest = 2,
    gEInventoryFindQuality_Lowset  = 3
};
enum EEvent;


class GE_DLLIMPORT gCInventory_PS :
    public eCEntityPropertySet,
    public gCInventoryListener
{
    public: virtual void                                       AddListener( gCInventoryListener * );
    public: virtual void                                       RemoveListener( gCInventoryListener * );
    public: virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult                                   Write( bCOStream & );
    public: virtual bEResult                                   Read( bCIStream & );
    public: virtual void                                       Destroy( void );
    public: virtual bEResult                                   Create( void );
    public: virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public: virtual                                           ~gCInventory_PS( void );
    public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public: virtual GEBool                                     IsReferencedByTemplate( void ) const;
    public: virtual GEBool                                     SupportsRenderDebugOutput( void ) const;
    public: virtual bEResult                                   ReadSaveGame( bCIStream & );
    public: virtual bEResult                                   WriteSaveGame( bCOStream & );
    public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public: virtual void                                       GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    public: virtual void                                       GetOnScreenDebugLines( GEU32, bTObjArray<eSPropertySetDebugLine> & ) const;
    public: virtual void                                       OnPostRead( void );
    public: virtual void                                       OnChildrenAvailable( GEU32, GEU32, eCTemplateEntity * );
    public: virtual void                                       OnStackCreate( GEInt, gCInventoryStack const * );
    public: virtual void                                       OnStackChange( GEInt, gCInventoryStack const * );
    public: virtual void                                       OnStackDelete( GEInt, gCInventoryStack const * );
    public: virtual void                                       OnSortInventory( void );
    public: virtual void                                       OnDestroyInventory( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static GEBool GE_STDCALL                       IsSkinnedSlot( gESlot );

    public:
        gCInventory_PS( gCInventory_PS const & );
        gCInventory_PS( void );

    public:
        gCInventory_PS const & operator = ( gCInventory_PS const & );

    public:
        GEBool &                 AccessGeneratedPlunder( void );
        GEBool &                 AccessGeneratedTrade( void );
        bCString &               AccessTreasureSet1( void );
        bCString &               AccessTreasureSet2( void );
        bCString &               AccessTreasureSet3( void );
        bCString &               AccessTreasureSet4( void );
        bCString &               AccessTreasureSet5( void );
        GEBool                   ActivateSkill( eCTemplateEntity const * );
        GEInt                    AssureItems( bCPropertyID const &, GEU32, GEU32 );
        GEBool                   CanEquip( GEInt, bTObjArray<SMissingAttrib> &, bTValArray<SMissingSkill> & ) const;
        GEBool                   CanLearnSkill( eCTemplateEntity const * ) const;
        GEBool                   ConsumeItems( GEInt, GEU32 );
        GEInt                    CreateItems( bCPropertyID const &, GEU32, GEU32 );
        GEInt                    CreateItems( eCTemplateEntity const *, GEU32, GEU32 );
        GEInt                    CreateItems( eCTemplateEntity const *, GEU32, GEU32, gEStackType );
        GEInt                    CreateStack( void );
        GEBool                   DeactivateSkill( eCTemplateEntity const * );
        GEBool                   DeleteItems( GEInt, GEU32 );
        GEBool                   DeleteStack( GEInt );
        eCEntity *               DropItemsFromSlot( gESlot, GEInt, bCMatrix const * );
        eCEntity *               DropItemsFromStack( GEInt, GEInt, bCMatrix const * );
        eCEntity *               DropSlot( gESlot, bCMatrix const * );
        eCEntity *               DropStack( GEInt, bCMatrix const * );
        void                     Dump( void ) const;
        GEBool                   EquipStack( GEInt );
        GEBool                   EquipStackToSlot( GEInt, gESlot );
        gCInventoryStack const * FindStack( bCPropertyID const &, gEInventoryFindQuality, GEU32 a_u32Quality, GEInt a_iStartIndexExclusive = -1 ) const; // Nur bei gEInventoryFindQuality_Equal ist a_u32Quality relevant
        gCInventoryStack const * FindStack( bCString const &, gEInventoryFindQuality, GEU32 a_u32Quality, GEInt a_iStartIndexExclusive = -1 ) const;
        gCInventoryStack const * FindStack( eCTemplateEntity const *, gEInventoryFindQuality, GEU32 a_u32Quality, GEInt a_iStartIndexExclusive = -1 ) const;
        gCInventoryStack const * FindStack( gESlot ) const;
        gCInventoryStack const * FindStack( gEUseType, gEInventoryFindQuality, GEU32 a_u32Quality, GEInt a_iStartIndexExclusive = -1 ) const;
        GEInt                    FindStackIndex( bCPropertyID const &, gEInventoryFindQuality, GEU32 a_u32Quality, GEInt a_iStartIndexExclusive = -1 ) const;
        GEInt                    FindStackIndex( bCString const &, gEInventoryFindQuality, GEU32 a_u32Quality, GEInt a_iStartIndexExclusive = -1 ) const;
        GEInt                    FindStackIndex( eCTemplateEntity const *, gEInventoryFindQuality, GEU32 a_u32Quality, GEInt a_iStartIndexExclusive = -1 ) const;
        GEInt                    FindStackIndex( gESlot ) const;
        GEInt                    FindStackIndex( gEUseType, gEInventoryFindQuality, GEU32 a_u32Quality, GEInt a_iStartIndexExclusive = -1 ) const;
        GEInt                    FindStackIndexByHotKey( GEU32 ) const;
        GEBool                   GeneratePlunderInvFromTreasureSets( void );
        GEBool                   GenerateTradeInvFromTreasureSets( void );
        void                     GetDefaultItem( gESlot, bCPropertyID & ) const;
        gCInventorySlot *        GetDefaultSlot( gESlot );
        gCInventorySlot const *  GetDefaultSlot( gESlot ) const;
        void                     GetEquipSlots( gEUseType, gESlot &, gESlot &, gESlot & ) const;
        GEBool const &           GetGeneratedPlunder( void ) const;
        GEBool const &           GetGeneratedTrade( void ) const;
        gESlot                   GetLeftEquipSlot( GEInt );
        gESlot                   GetRightEquipSlot( GEInt );
        GEInt                    GetSkillActivationCount( eCTemplateEntity const * ) const;
        gCInventoryStack *       GetStack( GEInt );
        gCInventoryStack const * GetStack( GEInt ) const;
        gEItemCategory           GetStackCategory( GEInt ) const;
        GEInt                    GetStackCount( void ) const;
        eCEntity *               GetStackFromSlot( gESlot ) const;
        gEUseType                GetStackUseType( GEInt ) const;
        GEInt                    GetTransactionAmount( GEInt ) const;
        bCString const &         GetTreasureSet1( void ) const;
        bCString const &         GetTreasureSet2( void ) const;
        bCString const &         GetTreasureSet3( void ) const;
        bCString const &         GetTreasureSet4( void ) const;
        bCString const &         GetTreasureSet5( void ) const;
        gCTreasureSet_PS *       GetTreasureSetPS1( void ) const;
        gCTreasureSet_PS *       GetTreasureSetPS2( void ) const;
        gCTreasureSet_PS *       GetTreasureSetPS3( void ) const;
        gCTreasureSet_PS *       GetTreasureSetPS4( void ) const;
        gCTreasureSet_PS *       GetTreasureSetPS5( void ) const;
        gCTreasureSet_PS *       GetTreasureSetPS( gETreasureDistribution ) const;
        GEBool                   HasLearnedSkill( eCTemplateEntity const * ) const;
        GEBool                   HasLearnedSpell( eCTemplateEntity const * ) const;
        GEBool                   HasTreasureSet( gETreasureDistribution ) const;
        GEBool                   HoldStackLeftHand( GEInt );
        GEBool                   HoldStackRightHand( GEInt );
        GEBool                   HoldStacks( GEInt a_iIndexLeft, GEInt a_iIndexRight );
        GEInt                    InsertStack( eCEntity * );
        GEBool                   IsDisplaySlot( gESlot ) const;
        GEBool                   IsDisplayStack( GEInt ) const;
        GEBool                   IsEquipped( gCArmorSet_PS const * ) const;
        GEBool                   IsSkillActive( eCTemplateEntity const * ) const;
        GEBool                   IsValidIndex( GEInt ) const;
        GEBool                   LearnSkill( eCTemplateEntity const * );
        GEBool                   LearnSpell( eCTemplateEntity const * );
        GEBool                   LearnStack( GEInt );
        GEBool                   LinkStackToSlot( GEInt, gESlot, GEBool );
        void                     MergeStacks( void );
        GEBool                   PerformTransaction( gCInventory_PS *, gEStackType, gEStackType );
        GEBool                   RefreshTradeInvFromTreasureSets( void );
        void                     SetDefaultItem( gESlot, bCPropertyID const & );
        void                     SetGeneratedPlunder( GEBool const & );
        void                     SetGeneratedTrade( GEBool const & );
        GEBool                   SetStackAmount( GEInt, GEU32 );
        void                     SetStackHotKey( GEInt, GEU32 );
        GEBool                   SetStackQuality( GEInt, GEU32 );
        GEBool                   SetTransactionAmount( GEInt, GEInt );
        void                     SetTreasureSet1( bCString const & );
        void                     SetTreasureSet2( bCString const & );
        void                     SetTreasureSet3( bCString const & );
        void                     SetTreasureSet4( bCString const & );
        void                     SetTreasureSet5( bCString const & );
        GEBool                   ShowSlot( GEBool, gESlot );
        void                     SortStacks( void );
        GEBool                   SplitStack( GEInt, GEU32, GEInt & );
        GEBool                   TransferAllTo( gCInventory_PS *, gEStackType );
        GEBool                   TransferItemsTo( gCInventory_PS *, GEInt, GEInt, gEStackType );
        GEBool                   TransferStackTo( gCInventory_PS *, GEInt, gEStackType );
        GEBool                   UnEquipStack( GEInt );
        GEInt                    UnlinkStackFromSlot( gESlot );
        GEBool                   UpdateVisibility( void );

    protected:
        GEBool ClearDefaultItems( void );
        GEInt  FindListenerIndex( gCInventoryListener * ) const;
        void   Invalidate( void );
        GEBool IsArmorPieceEquipped( eCTemplateEntity const * ) const;
        GEBool LinkDefaultItemToSlot( gESlot );
        GEBool LinkDefaultItems( void );
        void   NotifyListeners( EEvent, GEInt, gCInventoryStack const * );
        void   NotifyQuestManager( eCEntity const *, eCEntity const *, bCPropertyID const &, GEInt );
        GEBool PatchDefaultItems( void );
        GEBool PatchTreasureSets( void );
        void   PurgeListeners( void );
        GEBool ReadV3( bCIStream & );
        GEBool ReadV4( bCIStream & );
        GEBool ReadV5( bCIStream & );
        GEBool ReadV6( bCIStream & );
        GEBool ReadV7( bCIStream & );
        GEBool ReadV8( bCIStream & );
        GEBool ReadV9( bCIStream & );
        GEBool TransferTransactionItemsTo( gCInventory_PS *, gEStackType );
        GEBool UnlinkDefaultItemFromSlot( gESlot );
        GEBool UnlinkDefaultItems( void );

    private:
        GEInt FindSkillStackIndex( eCTemplateEntity const * ) const;
        GEInt FindSpellStackIndex( eCTemplateEntity const * ) const;

    private:
        friend gCInventory_PS_AH;

};

class gCInventory_PS_AH {
    public:
        static inline GEInt FindSkillStackIndex( gCInventory_PS const * a_pInventory, eCTemplateEntity const * a_pSkill ) {
            return a_pInventory->FindSkillStackIndex( a_pSkill );
        };
        static inline GEInt FindSpellStackIndex( gCInventory_PS const * a_pInventory, eCTemplateEntity const * a_pSpell ) {
            return a_pInventory->FindSpellStackIndex( a_pSpell );
        };
};

#endif
