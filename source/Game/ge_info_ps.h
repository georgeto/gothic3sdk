#ifndef GE_INFO_PS_H_INCLUDED
#define GE_INFO_PS_H_INCLUDED

class gCNPC_PS;
class gCInfoManager_PS;
class gCQuestManager_PS;

class GE_DLLIMPORT gCInfo_PS :
    public bCObjectRefBase
{
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
        gCInfo_PS( gCInfo_PS const & );
        gCInfo_PS( void );

    public:
        gCInfo_PS const & operator = ( gCInfo_PS const & );

    public:
        GEBool &                                                   AccessClearChildren( void );
        bTObjArray<bCString> &                                     AccessCondHasSkill( void );
        bTValArray<GEU32> &                                        AccessCondItemAmounts( void );
        bTObjArray<bCString> &                                     AccessCondItems( void );
        bTObjArray<bCString> &                                     AccessCondPAL( void );
        bTObjArray<bCString> &                                     AccessCondPlayerPartyMember( void );
        bTObjArray<GEU32> &                                        AccessCondReputAmount( void );
        bTObjArray<bCString> &                                     AccessCondReputGroup( void );
        bTObjArray<bCString> &                                     AccessCondReputRelation( void );
        bTObjArray<bCString> &                                     AccessCondSecondaryNPC( void );
        bTValArray<GEU32> &                                        AccessCondSecondaryNPCStatus( void );
        bTObjArray<bCString> &                                     AccessCondWearsItem( void );
        bCString &                                                 AccessConditionItemContainer( void );
        bCString &                                                 AccessConditionOwnerNearEntity( void );
        bTObjArray<bCString> &                                     AccessConditionPlayerKnows( void );
        bTObjArray<bCString> &                                     AccessConditionPlayerKnowsNot( void );
        bTPropertyContainer<gEInfoCondType> &                      AccessConditionType( void );
        bCString &                                                 AccessFolder( void );
        GEI32 &                                                    AccessGoldCost( void );
        GEBool &                                                   AccessInfoGiven( void );
        bTPropertyObject<gCInfoScript_PS, bCObjectRefBase> &       AccessInfoScript( void );
        bCString &                                                 AccessName( void );
        bCString &                                                 AccessOwner( void );
        bCString &                                                 AccessParent( void );
        GEBool &                                                   AccessPermanent( void );
        bCString &                                                 AccessQuest( void );
        GEU32 &                                                    AccessRunningTimeHours( void );
        GEU32 &                                                    AccessSortID( void );
        GEBool &                                                   AccessSuppressLog( void );
        bCString &                                                 AccessTeachAttrib( void );
        GEI32 &                                                    AccessTeachAttribValue( void );
        eCTemplateEntityProxy &                                    AccessTeachSkill( void );
        bTPropertyContainer<gEInfoType> &                          AccessType( void );
        GEBool                                                     Execute( gCInfoManager_PS * );
        eCEntity *                                                 FindEntityFromString( bCString const & ) const;
        GEBool const &                                             GetClearChildren( void ) const;
        bTObjArray<bCString> const &                               GetCondHasSkill( void ) const;
        bTValArray<GEU32> const &                                  GetCondItemAmounts( void ) const;
        bTObjArray<bCString> const &                               GetCondItems( void ) const;
        bTObjArray<bCString> const &                               GetCondPAL( void ) const;
        bTObjArray<bCString> const &                               GetCondPlayerPartyMember( void ) const;
        bTObjArray<GEU32> const &                                  GetCondReputAmount( void ) const;
        bTObjArray<bCString> const &                               GetCondReputGroup( void ) const;
        bTObjArray<bCString> const &                               GetCondReputRelation( void ) const;
        bTObjArray<bCString> const &                               GetCondSecondaryNPC( void ) const;
        bTValArray<GEU32> const &                                  GetCondSecondaryNPCStatus( void ) const;
        bTObjArray<bCString> const &                               GetCondWearsItem( void ) const;
        bCString const &                                           GetConditionItemContainer( void ) const;
        bCString const &                                           GetConditionOwnerNearEntity( void ) const;
        bTObjArray<bCString> const &                               GetConditionPlayerKnows( void ) const;
        bTObjArray<bCString> const &                               GetConditionPlayerKnowsNot( void ) const;
        bTPropertyContainer<gEInfoCondType> const &                GetConditionType( void ) const;
        bCUnicodeString                                            GetDialogDescription( void ) const;
        bCString const &                                           GetFolder( void ) const;
        GEI32 const &                                              GetGoldCost( void ) const;
        GEBool const &                                             GetInfoGiven( void ) const;
        bTPropertyObject<gCInfoScript_PS, bCObjectRefBase> const & GetInfoScript( void ) const;
        gCInfoManager_PS *                                         GetInfoManager( void );
        gCInfoManager_PS const *                                   GetInfoManager( void ) const;
        bCString const &                                           GetName( void ) const;
        bCString const &                                           GetOwner( void ) const;
        eCEntity *                                                 GetOwnerEntity( void ) const;
        bCString const &                                           GetParent( void ) const;
        GEBool const &                                             GetPermanent( void ) const;
        bCString const &                                           GetQuest( void ) const;
        gCQuestManager_PS *                                        GetQuestManager( void );
        gCQuestManager_PS const *                                  GetQuestManager( void ) const;
        GEU32 const &                                              GetRunningTimeHours( void ) const;
        GEU32 const &                                              GetSortID( void ) const;
        GEBool const &                                             GetSuppressLog( void ) const;
        bCString const &                                           GetTeachAttrib( void ) const;
        GEI32 const &                                              GetTeachAttribValue( void ) const;
        eCTemplateEntityProxy const &                              GetTeachSkill( void ) const;
        bCUnicodeString                                            GetTitle( void ) const;
        bTPropertyContainer<gEInfoType> const &                    GetType( void ) const;
        GEBool                                                     IsAvailable( void ) const;
        GEBool                                                     IsChildInfo( void ) const;
        GEBool                                                     IsDead( eCEntity * ) const;
        GEBool                                                     IsInfoValid( void ) const;
        GEBool                                                     IsOwnerPlayer( void ) const;
        GEBool                                                     IsPermanent( void ) const;
        GEBool                                                     OnDelivery( void );
        void                                                       OnEndInfo( void );
        void                                                       Read( eCArchiveFile & );
        void                                                       Read( bCString const & );
        void                                                       SetAsAssigned( void );
        void                                                       SetClearChildren( GEBool const & );
        void                                                       SetCondHasSkill( bTObjArray<bCString> const & );
        void                                                       SetCondItemAmounts( bTValArray<GEU32> const & );
        void                                                       SetCondItems( bTObjArray<bCString> const & );
        void                                                       SetCondPAL( bTObjArray<bCString> const & );
        void                                                       SetCondPlayerPartyMember( bTObjArray<bCString> const & );
        void                                                       SetCondReputAmount( bTObjArray<GEU32> const & );
        void                                                       SetCondReputGroup( bTObjArray<bCString> const & );
        void                                                       SetCondReputRelation( bTObjArray<bCString> const & );
        void                                                       SetCondSecondaryNPC( bTObjArray<bCString> const & );
        void                                                       SetCondSecondaryNPCStatus( bTValArray<GEU32> const & );
        void                                                       SetCondWearsItem( bTObjArray<bCString> const & );
        void                                                       SetConditionItemContainer( bCString const & );
        void                                                       SetConditionOwnerNearEntity( bCString const & );
        void                                                       SetConditionPlayerKnows( bTObjArray<bCString> const & );
        void                                                       SetConditionPlayerKnowsNot( bTObjArray<bCString> const & );
        void                                                       SetConditionType( bTPropertyContainer<gEInfoCondType> const & );
        void                                                       SetFolder( bCString const & );
        void                                                       SetGoldCost( GEI32 const & );
        void                                                       SetInfoGiven( GEBool const & );
        void                                                       SetInfoScript( bTPropertyObject<gCInfoScript_PS, bCObjectRefBase> const & );
        void                                                       SetName( bCString const & );
        void                                                       SetOwner( bCString const & );
        void                                                       SetParent( bCString const & );
        void                                                       SetPermanent( GEBool const & );
        void                                                       SetQuest( bCString const & );
        void                                                       SetRunningTimeHours( GEU32 const & );
        void                                                       SetSortID( GEU32 const & );
        void                                                       SetSuppressLog( GEBool const & );
        void                                                       SetTeachAttrib( bCString const & );
        void                                                       SetTeachAttribValue( GEI32 const & );
        void                                                       SetTeachSkill( eCTemplateEntityProxy const & );
        void                                                       SetType( bTPropertyContainer<gEInfoType> const & );
        bCString                                                   Validate( void ) const;
        GEBool                                                     Write( bCString const & ) const;

    protected:
        GEBool     AreConditionsFulfilled( void ) const;
        GEFloat    GetDistOwnerToEntity( bCPropertyID const & ) const;
        GEFloat    GetDistOwnerToEntity( bCString const & ) const;
        gCNPC_PS * GetOwnerNPC( void ) const;
        void       Invalidate( void );

    public:
        bCString Name;
        GEI32    SortID;
        bCString Owner;
        GEBool   InfoGiven;
        GE_PADDING( 3 )
        bCString Parent;
        bCString                            Quest;
        bTPropertyContainer<gEInfoCondType> ConditionType;
        bTPropertyContainer<gEInfoType>     Type;
        GEI32                               GoldCost;
        bCString                            ConditionOwnerNearEntity;
        bTObjArray<bCString>                ConditionPlayerKnows;
        bCString                            ConditionItemContainer;
        bTObjArray<bCString>                CondItems;
        bTValArray<GEU32>                   CondItemAmounts;
        bTObjArray<bCString>                CondSecondaryNPC;
        bTValArray<GEU32>                   CondSecondaryNPCStatus;
        eCTemplateEntityProxy               TeachSkill;
        bCString                            TeachAttrib;
        GEI32                               TeachAttribValue;
        GEBool                              ClearChildren;
        GEBool                              Permanent;
        GE_PADDING( 6 )
        bCString Folder;
        bTObjArray<bCString> ConditionPlayerKnowsNot;
        bTObjArray<bCString> CondWearsItem;
        bTObjArray<bCString> CondHasSkill;
        bTObjArray<bCString> CondReputGroup;
        bTObjArray<GEU32>    CondReputAmount;
        bTObjArray<bCString> CondReputRelation;
        bTObjArray<bCString> CondPAL;
        bTObjArray<bCString> CondPlayerPartyMember;
        GEBool               SuppressLog;
        GE_PADDING( 3 )
        bTPropertyObject<gCInfoScript_PS, bCObjectRefBase> InfoScript;
        gCInfoManager_PS * m_pInfoManager;
};

GE_ASSERT_SIZEOF( gCInfo_PS, 0x114 );

#endif
