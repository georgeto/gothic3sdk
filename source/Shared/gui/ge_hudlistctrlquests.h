#ifndef GE_HUDLISTCTRLQUESTS_H_INCLUDED
#define GE_HUDLISTCTRLQUESTS_H_INCLUDED

class gCHUDListCtrlQuests : public CFFGFCListCtrl
    {
        public:
            gEQuestStatus QuestStatus;
            GEInt iEnclaveIndex;
            CFFGFCImageList ImageList;
            GEBool bListNeedsUpdate;
            GE_PADDING(3)
    };

GE_ASSERT_SIZEOF( gCHUDListCtrlQuests, 0x24 )

#endif
