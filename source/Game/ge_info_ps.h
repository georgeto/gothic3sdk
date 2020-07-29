#ifndef GE_INFO_PS_H_INCLUDED
#define GE_INFO_PS_H_INCLUDED

class gCNPC_PS;
class gCInfoManager_PS;
class gCQuestManager_PS;

GE_IMPORT_PROPERTY_SET( gCInfo_PS, bCObjectRefBase )
    public: virtual GEBool            IsEditorRelevant( void ) const;
    public: virtual eEPropertySetType GetPropertySetType( void ) const;
    public: virtual bEResult          ReadRuntimeData( bCIStream & );
    public: virtual bEResult          WriteRuntimeData( bCOStream & );
    public: virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult          Write( bCOStream & );
    public: virtual bEResult          Read( bCIStream & );
    public: virtual void              Destroy( void );
    public: virtual bEResult          Create( void );
    public: virtual bEResult          CopyFrom( bCObjectBase const & );
    public: virtual                  ~gCInfo_PS( void );
    public: virtual bEResult          PostInitializeProperties( void );

    public:
        static eCEntity * GE_STDCALL                   GetEntity( bCPropertyID const & );
        static eCEntity * GE_STDCALL                   GetEntity( bCString const & );
        static bCPropertyID GE_STDCALL                 GetEntityID( bCString const & );
        static bCString GE_STDCALL                     GetEntityName( bCPropertyID const & );
        static gCInventory_PS * GE_STDCALL             GetInventory( bCPropertyID const & );
        static gCInventory_PS * GE_STDCALL             GetInventory( bCString const & );
        static gCNPC_PS * GE_STDCALL                   GetNPC( bCPropertyID const & );
        static gCNPC_PS * GE_STDCALL                   GetNPC( bCString const & );
        static eCDynamicEntity * GE_STDCALL            GetPlayer( void );
        static gCNPC_PS * GE_STDCALL                   GetPlayerNPC( void );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static GEBool GE_STDCALL                       Give( bCPropertyID const &, bCPropertyID const &, bCPropertyID const &, GEU32 const & );
        static GEBool GE_STDCALL                       Give( eCEntity *, eCEntity *, bCPropertyID const &, GEU32 );
        static GEBool GE_STDCALL                       Give( eCEntity *, eCEntity *, GEInt, GEU32 );
        static GEBool GE_STDCALL                       Give( eCEntity *, eCEntity *, eCTemplateEntity const *, GEU32 );
        static bCString GE_STDCALL                     NPCstatusToString( gEInfoNPCStatus );
        static GEBool GE_STDCALL                       SetPartyLeader( eCEntity *, eCEntity * );
        static gEInfoNPCStatus GE_STDCALL              StringToNPCstatus( bCString const & );

    public:
        GE_IMPORT_DECLARE_PROPERTY( bCString, Name,      m_strName )
        GE_IMPORT_DECLARE_PROPERTY( GEU32,    SortID,    m_sortID )
        GE_IMPORT_DECLARE_PROPERTY( bCString, Owner,     m_owner )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,   InfoGiven, m_bInfoGiven )
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_PROPERTY( bCString, Parent, m_strParent )
        GE_IMPORT_DECLARE_PROPERTY( bCString, Quest,  m_strQuest )
        GE_IMPORT_DECLARE_ENUMPROP( gEInfoCondType, ConditionType, m_enuCondType )
        GE_IMPORT_DECLARE_ENUMPROP( gEInfoType,     Type,          m_enuType )
        GE_IMPORT_DECLARE_PROPERTY( GEI32,                      GoldCost,                 m_iInfoGoldCost )
        GE_IMPORT_DECLARE_PROPERTY( bCString,                   ConditionOwnerNearEntity, m_condOwnerNearEntity )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bCString>, ConditionPlayerKnows,     m_arrCondPlayerKnows )
        GE_IMPORT_DECLARE_PROPERTY( bCString,                   ConditionItemContainer,   m_condItemContainer )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bCString>, CondItems,                m_arrCondItems )
        GE_IMPORT_DECLARE_PROPERTY( bTValArray<GEU32>,          CondItemAmounts,          m_arrCondItemAmounts )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bCString>, CondSecondaryNPC,         m_arrCondSecondaryNPC )
        GE_IMPORT_DECLARE_PROPERTY( bTValArray<GEU32>,          CondSecondaryNPCStatus,   m_arrCondSecondaryNPCStatus )
        GE_IMPORT_DECLARE_PROPERTY( eCTemplateEntityProxy,      TeachSkill,               m_teachSkill )
        GE_IMPORT_DECLARE_PROPERTY( bCString,                   TeachAttrib,              m_teachAttrib )
        GE_IMPORT_DECLARE_PROPERTY( GEI32,                      TeachAttribValue,         m_teachAttribValue )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,                     ClearChildren,            m_bClearChildren )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,                     Permanent,                m_bPermanent )
        GE_PADDING( 2 )

    public:
        GEU32 m_uEndTimestamp;

    public:
        GE_IMPORT_DECLARE_PROPERTY( bCString,                   Folder,                  m_strFolder )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bCString>, ConditionPlayerKnowsNot, m_arrCondPlayerKnowsNot )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bCString>, CondWearsItem,           m_arrCondWearsItem )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bCString>, CondHasSkill,            m_arrCondHasSkill )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bCString>, CondReputGroup,          m_arrCondReputGroup )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<GEU32>,          CondReputAmount,         m_arrCondReputAmount )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bCString>, CondReputRelation,       m_arrCondReputRelation )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bCString>, CondPAL,                 m_arrCondPAL )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bCString>, CondPlayerPartyMember,   m_arrCondPlayerPartyMember )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,                     SuppressLog,             m_bSuppressLog )
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_OBJECTPROP( gCInfoScript_PS, bCObjectRefBase, InfoScript, m_infoScript )

    public:
        gCInfo_PS( gCInfo_PS const & );
        gCInfo_PS( void );

    public:
        gCInfo_PS const & operator = ( gCInfo_PS const & );

    public:
        GEU32 &                   AccessRunningTimeHours( void );
        GEBool                    Execute( gCInfoManager_PS * );
        eCEntity *                FindEntityFromString( bCString const & ) const;
        bCUnicodeString           GetDialogDescription( void ) const;
        gCInfoManager_PS *        GetInfoManager( void );
        gCInfoManager_PS const *  GetInfoManager( void ) const;
        eCEntity *                GetOwnerEntity( void ) const;
        gCQuestManager_PS *       GetQuestManager( void );
        gCQuestManager_PS const * GetQuestManager( void ) const;
        GEU32 const &             GetRunningTimeHours( void ) const;
        bCUnicodeString           GetTitle( void ) const;
        GEBool                    IsAvailable( void ) const;
        GEBool                    IsChildInfo( void ) const;
        GEBool                    IsDead( eCEntity * ) const;
        GEBool                    IsInfoValid( void ) const;
        GEBool                    IsOwnerPlayer( void ) const;
        GEBool                    IsPermanent( void ) const;
        GEBool                    OnDelivery( void );
        void                      OnEndInfo( void );
        void                      Read( eCArchiveFile & );
        void                      Read( bCString const & );
        void                      SetAsAssigned( void );
        void                      SetRunningTimeHours( GEU32 const & );
        bCString                  Validate( void ) const;
        GEBool                    Write( bCString const & ) const;

    protected:
        GEBool     AreConditionsFulfilled( void ) const;
        GEFloat    GetDistOwnerToEntity( bCPropertyID const & ) const;
        GEFloat    GetDistOwnerToEntity( bCString const & ) const;
        gCNPC_PS * GetOwnerNPC( void ) const;
        void       Invalidate( void );

    public:
        gCInfoManager_PS * m_pInfoManager;
};

GE_ASSERT_SIZEOF( gCInfo_PS, 0x114 );

#endif
