#ifndef GE_QUEST_PS_H_INCLUDED
#define GE_QUEST_PS_H_INCLUDED

GE_IMPORT_PROPERTY_SET( gCQuest_PS, bCObjectRefBase )
public:
    struct SLogEntry
    {
        eCLocString Heading;
        eCLocString Text;

        GE_DECLARE_NO_STREAM_OPERATORS_INLINE( SLogEntry );
    };

public: virtual GEBool            IsEditorRelevant( void ) const;
public: virtual eEPropertySetType GetPropertySetType( void ) const;
public: virtual void              OnProcess( void );
public: virtual void              OnPreProcess( void );
public: virtual GEU16             GetVersion( void ) const;
public: using bCObjectBase::Write;
public: virtual bEResult          Write( bCOStream & );
public: virtual bEResult          Read( bCIStream & );
public: virtual void              Destroy( void );
public: virtual bEResult          Create( void );
public: virtual bEResult          CopyFrom( bCObjectBase const & );
public: virtual ~gCQuest_PS( void );
public: virtual bEResult PostInitializeProperties( void );

public:
    GE_IMPORT_DECLARE_PROPERTY( bCString, Name, m_strName )
    GE_IMPORT_DECLARE_ENUMPROP( gEQuestType, Type, m_enuType )
    GE_IMPORT_DECLARE_PROPERTY( bTObjArray<bCString>,  FinishedQuests,   m_arrFinishedQuests )
    GE_IMPORT_DECLARE_PROPERTY( eCLocString,           LogTopic,         m_strLogTopic )
    GE_IMPORT_DECLARE_PROPERTY( bTObjArray<SLogEntry>, LogText,          m_arrLogText )
    GE_IMPORT_DECLARE_PROPERTY( GEI32,                 ExperiencePoints, m_iXP )
    GE_IMPORT_DECLARE_ENUMPROP( gEPoliticalAlignment, PoliticalSuccess, m_enuPoliticalSuccess )
    GE_IMPORT_DECLARE_PROPERTY( GEI32,                PoliticalSuccessAmount, m_politicalSuccessAmount )
    GE_IMPORT_DECLARE_PROPERTY( bCString,             EnclaveSuccess,         m_enclaveSuccess )
    GE_IMPORT_DECLARE_PROPERTY( GEI32,                EnclaveSuccessAmount,   m_enclaveSuccessAmount )
    GE_IMPORT_DECLARE_PROPERTY( bCString,             AttribSuccess,          m_attribSuccess )
    GE_IMPORT_DECLARE_PROPERTY( GEI32,                AttribSuccessAmount,    m_attribSuccessAmount )
    GE_IMPORT_DECLARE_PROPERTY( bTObjArray<bCString>, DeliveryEntities,       m_arrDeliveryEntities )
    GE_IMPORT_DECLARE_PROPERTY( bTValArray<GEU32>,    DeliveryAmounts,        m_arrDeliveryAmounts )
    GE_IMPORT_DECLARE_PROPERTY( bTValArray<GEI32>,    DeliveryCounter,        m_arrDeliveryCounter )
    GE_IMPORT_DECLARE_PROPERTY( bCString,             DestinationEntity,      m_destinationEntity )
    GE_IMPORT_DECLARE_PROPERTY( GEI32,                RunningTimeYears,       m_u32RunningTimeYears )
    GE_IMPORT_DECLARE_PROPERTY( GEI32,                RunningTimeDays,        m_u32RunningTimeDays )
    GE_IMPORT_DECLARE_PROPERTY( GEI32,                RunningTimeHours,       m_u32RunningTimeHours )
protected:
    eCLocString m_strQuestDesc;
    bCString    m_SpellName;
protected:
    GE_IMPORT_DECLARE_PROPERTY( bCString, Folder, m_strFolder )
    GE_IMPORT_DECLARE_ENUMPROP( gEPoliticalAlignment, PoliticalFailure, m_enuPoliticalFailure )
    GE_IMPORT_DECLARE_PROPERTY( GEI32,    PoliticalFailureAmount, m_politicalFailureAmount )
    GE_IMPORT_DECLARE_PROPERTY( bCString, EnclaveFailure,         m_enclaveFailure )
    GE_IMPORT_DECLARE_PROPERTY( GEI32,    EnclaveFailureAmount,   m_enclaveFailureAmount )
    GE_IMPORT_DECLARE_ENUMPROP( gEQuestStatus, Status, m_status )
    GE_IMPORT_DECLARE_PROPERTY( GEI32, ActivationTime_Year, m_activationTime_Year )
    GE_IMPORT_DECLARE_PROPERTY( GEI32, ActivationTime_Day,  m_activationTime_Day )
    GE_IMPORT_DECLARE_PROPERTY( GEI32, ActivationTime_Hour, m_activationTime_Hour )

public:
    static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

public:
    gCQuest_PS( gCQuest_PS const & );
    gCQuest_PS( void );

public:
    gCQuest_PS const & operator = ( gCQuest_PS const & );

public:
    eCLocString &       AccessQuestDesc( void );
    bCString &          AccessSpellName( void );
    GEBool              AreFinishedQuestsFinished( void ) const;
    GEBool              AreInfosForFinishedQuestsAvailable( void ) const;
    void                CheckDeliveryEntitiesStatus( void );
    eCLocString const & GetQuestDesc( void ) const;
    bCString const &    GetSpellName( void ) const;
    GEBool              HasNPCallRequiredItems( bCPropertyID const & );
    GEBool              HasNPCpartOfRequiredItems( bCPropertyID const & );
    GEBool              HaveNPCsAllRequiredItems( bCPropertyID const &, bCPropertyID const & );
    GEBool              IsEntityDeliveryEntity( bCString const & ) const;
    GEBool              IsFinished( void ) const;
    GEBool              IsInFinalState( void ) const;
    GEBool              IsOvertime( void ) const;
    GEBool              IsSucceeded( void ) const;
    void                OnEnclaveStateChanged( eCEntity const & );
    void                OnEnter( eCEntity const &, bCString const & );
    void                OnLeave( eCEntity const &, bCString const & );
    void                OnNPCDefeated( eCEntity const & );
    void                OnNPCKilled( eCEntity const & );
    void                OnReceiveItem( eCEntity const *, eCEntity const *, bCPropertyID const &, GEU32 );
    void                OnSpellCast( eCEntity const &, eCEntity const &, bCString );
    GEBool              Read( bCString const & );
    bEResult            ReadRuntimeData( bCIStream & );
    void                Reset( void );
    GEBool              SetCancelled( void );
    GEBool              SetFailed( void );
    void                SetQuestDesc( eCLocString const & );
    void                SetSpellName( bCString const & );
    GEBool              SetStatus( gEQuestStatus const & );
    bCString            Validate( void ) const;
    GEBool              Write( bCString const & ) const;
    bEResult            WriteRuntimeData( bCOStream & );

protected:
    gCEntity *                GetEntity( bCPropertyID const & ) const;
    gCEntity *                GetEntity( bCString const & ) const;
    gCInfoManager_PS *        GetInfoManager( void );
    gCInfoManager_PS const *  GetInfoManager( void ) const;
    gCInventory_PS *          GetInventory( bCPropertyID const & ) const;
    gCInventory_PS *          GetInventory( bCString const & ) const;
    gCNPC_PS *                GetNPC( bCPropertyID const & ) const;
    gCNPC_PS *                GetNPC( bCString const & ) const;
    bCPropertyID const        GetPropertyIDFromString( bCString const & ) const;
    gCQuestManager_PS *       GetQuestManager( void );
    gCQuestManager_PS const * GetQuestManager( void ) const;
    void                      Invalidate( void );
    GEBool                    IsDead( bCPropertyID const & ) const;
    GEBool                    IsDead( bCString const & ) const;
    GEBool                    IsDead( gCEntity * ) const;
};

GE_ASSERT_SIZEOF( gCQuest_PS, 0xBC )

#endif
