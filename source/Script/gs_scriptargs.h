#ifndef GS_SCRIPTARGS_H_INCLUDED
#define GS_SCRIPTARGS_H_INCLUDED

class gScrArgument
{
    public: virtual ~gScrArgument( void );
};

class gSArgsFor__AI_HoldInventoryItems :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_HoldInventoryItems( void );

    public:
        Entity m_Holder;
        GEInt  m_iLeftIndex;
        GEInt  m_iRightIndex;
};

class gSArgsFor__AI_AniStateAction :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_AniStateAction( void );

    public:
        Entity   m_Entity;
        gEAction m_enuAction;
};

class gSArgsFor__AI_HoldItems :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_HoldItems( void );

    public:
        Entity   m_Holder;
        Template m_LeftItem;
        Template m_RightItem;
};

class gSArgsFor__AI_UseInventoryItem :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_UseInventoryItem( void );

    public:
        Entity m_Consumer;
        GEUInt m_iIndex;
};

class gSArgsFor__PS_HUD__OnPlayerFryStack
{
    public:
        GEInt m_iRawItem;
        GEInt m_iAmount;
};

class gSArgsFor__AI_Say :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_Say( void );

    public:
        Entity   m_Entity1;
        Entity   m_Entity2;
        GEInt    m_Unk1;
        gEPhase  m_PhaseGesture;
        bCString m_strTextID;
        GEBool   m_bShowText;
        GE_PADDING( 3 )
};

class gSArgsFor__AI_Say_Ex :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_Say_Ex( void );

    public:
        Entity   m_Entity1;
        Entity   m_Entity2;
        GEInt    m_Unk1;
        gEPhase  m_PhaseGesture;
        bCString m_strFormattedSampleName;
        bCString m_strTextID;
        GEBool   m_bShowText;
        GEBool   m_bNoSoundFile;
        GE_PADDING( 2 )
};

class gSArgsFor__AI_SaySVM :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_SaySVM( void );

    public:
        Entity   m_Entity1;
        Entity   m_Entity2;
        GEInt    m_Unk1;
        gEPhase  m_PhaseGesture;
        bCString m_strTextID;
        GEBool   m_bShowText;
        GE_PADDING( 3 )
};

class gSArgsFor__AI_StandUp :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_StandUp( void );

    public:
        Entity m_Entity;
};

class gSArgsFor__AI_Action :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_Action( void );

    public:
        Entity   m_Entity;
        gEAction m_enuAction;
        GEInt    m_iDuration;
};

class gSArgsFor__AI_Goto_Ext :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_Goto_Ext( void );

    public:
        Entity      m_Entity;
        Entity      m_Destination;
        gEWalkMode  m_enuWalkMode;
        gEDirection m_enuDirection;
};

class gSArgsFor__AI_Unlock :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_Unlock( void );

    public:
        Entity m_SelfEntity;
        Entity m_TargetEntity;
};

class gSArgsFor__AI_ChangeAction :
    public gScrArgument
{
    public: virtual ~gSArgsFor__AI_ChangeAction( void );

    public:
        Entity   m_Entity;
        Entity   m_InteractEntity;
        gEAction m_enuAction;
};

#endif
