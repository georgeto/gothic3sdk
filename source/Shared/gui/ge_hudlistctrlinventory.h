#ifndef GE_HUDLISTCTRLINVENTORY_H_INCLUDED
#define GE_HUDLISTCTRLINVENTORY_H_INCLUDED

#include "Game.h"

class gCHUDListCtrlInventory : public CFFGFCListCtrl
{
    public:
        gCInventoryListener m_InventoryListener;
        gCInventory_PS *    m_pInventory;
        CFFGFCImageList     m_ImageList1;
        CFFGFCImageList     m_ImageList2;
};

GE_ASSERT_SIZEOF( gCHUDListCtrlInventory, 0x28 )

#endif
