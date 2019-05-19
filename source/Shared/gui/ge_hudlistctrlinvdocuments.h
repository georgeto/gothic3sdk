#ifndef GE_HUDLISTCTRLINVDOCUMENTS_H_INCLUDED
#define GE_HUDLISTCTRLINVDOCUMENTS_H_INCLUDED

#include "ge_hudlistctrlinvstacks.h"

class gCHUDListCtrlInvDocuments : public gCHUDListCtrlInvStacks
{
    public:
        enum gEDocumentFilterType
        {
            gEDocumentFilterType_Map          = 0,
            gEDocumentFilterType_Written      = 1,
            gEDocumentFilterType_Alchemy      = 2,
            gEDocumentFilterType_Cooking      = 3,
            gEDocumentFilterType_Smithing     = 4,
            gEDocumentFilterType_Scrolls      = 5,
            gEDocumentFilterType_GoldSmithing = 6
        };

        gEDocumentFilterType m_enuFilterType;
};

GE_ASSERT_SIZEOF( gCHUDListCtrlInvDocuments, 0x38 )

#endif
