#ifndef GS_PSINVENTORY_H_INCLUDED
#define GS_PSINVENTORY_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSInventory, gCInventory_PS )
public:
    GEBool         ActivateSkill( Template const & );
    GEInt          ApplyQuality( GEInt, GEU32, GEInt );
    void           ArrangeStacks( void );
    GEBool         AssignStackToQuickSlot( GEInt, GEInt );
    void           AssureAll( void );
    GEInt          AssureItems( Template const & a_Item, GEU32 a_u32Quality, GEInt a_iAmount );
    GEInt          AssureItemsEx( Template const & a_Item, GEU32 a_u32Quality, GEInt a_iAmount, GEInt a_iSlot, GEBool a_bLearn );
    GEBool         ConsumeItems( GEInt, GEInt );
    GEInt          CreateItems( Template const & a_Item, GEU32 a_u32Quality, GEInt a_iAmount );
    GEBool         DeactivateSkill( Template const & );
    GEBool         DeleteItems( GEInt, GEInt );
    GEBool         DeleteStack( GEInt );
    Entity         DropItemFromSlot( gESlot );
    Entity         DropItemsFromSlot( gESlot, GEInt );
    Entity         DropStack( GEInt, bCMatrix const & );
    GEBool         EquipStack( GEInt );
    GEBool         EquipStackToSlot( GEInt, gESlot );
    GEBool         ExecuteItem( GEInt );
    GEInt          FindStackIndex( Template const &, GEInt a_iStartIndexExclusive = -1, GEBool a_bNotLinked = GEFalse ) const;
    GEInt          FindStackIndex( gESlot ) const;
    GEInt          FindStackIndexByQuickSlot( GEInt ) const;
    GEBool         GeneratePlunderInvFromTreasureSets( void );
    GEBool         GenerateTradeInvFromTreasureSets( void );
    GEInt          GetAmount( GEInt ) const;
    gEItemCategory GetCategory( GEInt ) const;
    Entity         GetDefaultItemFromSlot( gESlot ) const;
    gESlot         GetEquipSlot( gEUseType );
    gESlot         GetEquipSlotAlt( gEUseType );
    GEInt          GetGeneratedStackCount( void ) const;
    GEInt          GetItemAmount( Template const & ) const;
    GEInt          GetItemAmount( gEUseType ) const;
    Entity         GetItemFromSlot( gESlot ) const;
    GEInt          GetLargestStackForTransfer( Template const &, GEInt );
    bCString       GetName( GEInt );
    GEU32          GetQuality( GEInt ) const;
    GEU32          GetSkillActivationCount( Template const & ) const;
    gESlot         GetSlotFromStack( GEInt ) const;
    GEInt          GetStackCount( void ) const;
    Template       GetTemplate( GEInt ) const;
    Entity         GetTemplateItem( GEInt ) const;
    Entity         GetTreasureSet1( void ) const;
    Entity         GetTreasureSet2( void ) const;
    Entity         GetTreasureSet3( void ) const;
    Entity         GetTreasureSet4( void ) const;
    Entity         GetTreasureSet5( void ) const;
    gEUseType      GetUseType( GEInt ) const;
    GEBool         HasItems( Template const &, GEInt ) const;
    GEBool         HasItems( gEUseType, GEInt ) const;
    GEBool         HasLearnedSkill( Template const & ) const;
    GEBool         HasLearnedSpell( Template const & ) const;
    GEBool         HoldLeftStack( GEInt );
    GEBool         HoldRightStack( GEInt );
    GEBool         HoldStacks( GEInt a_iIndexLeft, GEInt a_iIndexRight ); // Hat im Gegensatz zu AI_HoldInventory Items keine 'Raushol'-Animation
    GEInt          InsertStack( Entity const & );
    GEBool         IsGenerated( GEInt ) const;
    GEBool         IsGeneratedPlunder( void ) const;
    GEBool         IsGeneratedTrade( void ) const;
    GEBool         IsPermanent( GEInt ) const;
    GEBool         IsSkillActive( Template const & ) const;
    GEBool         IsStackMerchandise( GEInt );
    GEBool         IsValid( void ) const;
    void           MergeStacks( void );
    GEBool         PrintMissingRequirements( int, GEBool ) const;
    void           PurgeItems( Template const &, GEInt );
    GEBool         RefreshTradeInvFromTreasureSets( void );
    GEBool         SetAmount( GEInt, GEU32 );
    void           SetGeneratedPlunder( GEBool );
    GEInt          SetQuality( GEInt, GEU32, GEU32 );
    void           SortStacks( void );
    GEInt          SplitStack( GEInt, GEInt );
    void           StackTradingGold( void );
    void           SwapSlots( gESlot, gESlot );
    GEInt          Synthesize( Entity const &, GEInt );
    GEBool         TeachSkill( Template const & );
    GEBool         TeachSpell( Template const & );
    GEBool         TransferAllTo( Entity & );
    GEBool         TransferAmountTo( GEInt, GEInt, Entity & );
    GEBool         UnEquipStack( GEInt );
    void           UpdateVisibility( void );
    GEBool         UseStack( GEInt );

};

#endif
