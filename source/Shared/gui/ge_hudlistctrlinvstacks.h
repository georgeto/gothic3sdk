#ifndef GE_HUDLISTCTRLINVSTACKS_H_INCLUDED
#define GE_HUDLISTCTRLINVSTACKS_H_INCLUDED

#include "ge_hudlistctrlinventory.h"

class gCHUDListCtrlInvStacks : public gCHUDListCtrlInventory
{
    public:
        GEBool __UNK_0028;
        GE_PADDING( 3 )
        gEItemCategory m_FilterItemCategory;
        gEUseType m_FilterUseType;

    public:
        GEBool IsItemInSelectedCategory( GEUInt a_uIndex );
};

GE_ASSERT_SIZEOF( gCHUDListCtrlInvStacks, 0x34 )

#endif
