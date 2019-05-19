#ifndef GE_HUDDIALOGMENU_H_INCLUDED
#define GE_HUDDIALOGMENU_H_INCLUDED

#include "Game.h"

class gCHUDDialogMenu2 :
    public gCHUDDialog
{
    public:
        gCHUDMenu *m_arrMenu[14];
        GEInt      m_iSelectedMenu;
        bCRect     field_4C;
        bCRect     field_5C;
        GEBool     m_bCreationDone;
        GE_PADDING( 3 )
};

GE_ASSERT_SIZEOF( gCHUDDialogMenu2, 0x70 )

#endif
