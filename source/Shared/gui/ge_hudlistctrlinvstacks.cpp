#include "ge_hudlistctrlinvstacks.h"

#include "util/Memory.h"
#include "util/Util.h"

GEBool gCHUDListCtrlInvStacks::IsItemInSelectedCategory(GEUInt a_uIndex)
{
    UNREFERENCED_PARAMETER(a_uIndex);

    typedef GEBool (*pIsItemInSelectedCategory)(GEUInt a_uIndex);
    static pIsItemInSelectedCategory fIsItemInSelectedCategory = force_cast<pIsItemInSelectedCategory>(RVA_Game(0xA1570));
    __asm {
        mov ecx, this
        push a_uIndex
        call fIsItemInSelectedCategory
    }
}
