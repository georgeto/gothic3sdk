#ifndef GE_HUDVIEWQUESTS_H_INCLUDED
#define GE_HUDVIEWQUESTS_H_INCLUDED

class gCHUDViewQuests2 : public gCHUDPageView
{
    public:
        gCHUDStaticQuest    m_HUDStaticQuest;
        gCHUDListCtrlQuests m_HUDListCtrlQuests;
        /* ... */
};

GE_ASSERT_SIZEOF( gCHUDViewQuests2, 0x48 )

#endif
