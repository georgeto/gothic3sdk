#ifndef GE_INFOMANAGER_PS_H_INCLUDED
#define GE_INFOMANAGER_PS_H_INCLUDED

GE_IMPORT_PROPERTY_SET( gCInfoManager_PS, eCEntityPropertySet )
    public: virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult                                   Write( bCOStream & );
    public: virtual bEResult                                   Read( bCIStream & );
    public: virtual void                                       Destroy( void );
    public: virtual bEResult                                   Create( void );
    public: virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public: virtual                                           ~gCInfoManager_PS( void );
    public: virtual bEResult                                   PostInitializeProperties( void );
    public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public: virtual GEBool                                     IsProcessable( void ) const;
    public: virtual GEBool                                     IsEditorRelevant( void ) const;
    public: virtual bEResult                                   ReadSaveGame( bCIStream & );
    public: virtual bEResult                                   WriteSaveGame( bCOStream & );
    public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public: virtual void                                       OnProcess( void );
    public: virtual void                                       OnPreProcess( void );

    public:
        GE_IMPORT_DECLARE_PROPERTY( bool, IsRunning, m_bIsRunning ) // Read only
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_PROPERTY( int, CurrentInfoIndex, m_currentInfoIndex ) // Read only
        GE_IMPORT_DECLARE_PROPERTY( bool, WaitForScript, m_bWaitforScript ) // Read only
        GE_IMPORT_DECLARE_PROPERTY( bool, ChildMode, m_bChildMode ) // Read only
        GE_IMPORT_DECLARE_PROPERTY( bool, EndRequested, m_bEndRequested ) // Read only
        GE_PADDING( 1 )
        GE_IMPORT_DECLARE_ENUMPROP( gESession_State, LastSessionState, m_lastSessionState ) // Read only
        GE_IMPORT_DECLARE_PROPERTY( bool, LastInfoExecuted, m_bLastInfoExecuted ) // Read only

    public:
        static bCString GE_STDCALL                     GetInfoDir( void );
        static bCString GE_STDCALL                     GetInfoFilePath( gCInfo_PS const * );
        static bCString GE_STDCALL                     GetInfoManagerFile( void );
        static gCInfoManager_PS * GE_STDCALL           GetInstance( void );
        static gCMagic_PS * GE_STDCALL                 GetMagicPS( eCEntity * );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static gCSkill_PS * GE_STDCALL                 GetSkillPS( eCEntity * );
        static void GE_STDCALL                         RemoveDuplicatedInfos( bTPtrArray<gCInfo_PS *> &, gEInfoCondType );
        static void GE_STDCALL                         SortInfos( GEInt, bTPtrArray<gCInfo_PS *> & );
        static GEInt GE_CCALL                          SortInfosCbk( GELPCVoid, GELPCVoid );

    public:
        gCInfoManager_PS( gCInfoManager_PS const & );
        gCInfoManager_PS( void );

    public:
        gCInfoManager_PS const & operator = ( gCInfoManager_PS const & );

        bTPtrArray<gCInfo_PS *> &       AccessInfos( void );
        gCInfo_PS *                     AddInfo( bCString const & );
        GEBool                          AreChildInfosAvailable( gCInfo_PS const & ) const;
        GEBool                          AreOnlyEndInfosAvailable( void ) const;
        GEBool                          ChangeInfoName( bCString const &, bCString const & );
        void                            EndInfoManager( gCInfo_PS * );
        GEBool                          ExecuteDialogInfo( gCInfo_PS * );
        eCEntity *                      FindEntityFromString( bCString const & );
        gCInfo_PS *                     GetAvailableInfo( GEInt );
        GEInt                           GetAvailableInfoCount( void );
        void                            GetChildInfos( gCInfo_PS const &, bTPtrArray<gCInfo_PS *> & );
        gCInfo_PS *                     GetCurrentInfo( void );
        gCEntity *                      GetCurrentOther( void );
        gCEntity *                      GetCurrentSelf( void );
        gCEntity *                      GetDialogPartner1( void ) const;
        gCEntity *                      GetDialogPartner2( void ) const;
        gCEntity *                      GetDialogPartnerNPC( void ) const; // GetDialogPartner2
        GEU32                           GetHighestSortID( void ) const;
        gCInfo_PS *                     GetInfo( bCString const & );
        bTPtrArray<gCInfo_PS *> const & GetInfos( void ) const;
        gCQuestManager_PS *             GetQuestManager( void );
        gCQuestManager_PS const *       GetQuestManager( void ) const;
        gCScriptProcessingUnit &        GetSPU( void );
        GEBool                          HasChildInfos( gCInfo_PS const & );
        GEBool                          HasCommentInfo( eCEntity * );
        GEBool                          HasImportantInfo( eCEntity * );
        GEBool                          HasInfos( eCEntity * );
        GEBool                          IsDialogInfo( gCInfo_PS const & ) const;
        GEBool                          IsParentInfoAvailable( gCInfo_PS const & ) const;
        GEBool                          IsRunning( void );
        GEBool                          IsSuccessOrFailedInfoAvailable( gCQuest_PS const & ) const;
        GEBool                          IsWaitingForScript( void );
        GEBool                          LoadInfosFromInis( void );
        void                            OnCommandCompleted( GEBool );
        void                            OnEndInfoManager( void );
        void                            OnInfoScriptFinished( gCInfo_PS const * );
        void                            OnInfoScriptStarted( gCInfo_PS const *, bCString const & );
        GEBool                          ReadCompiledInfoManager( bCString const & );
        GEBool                          RemoveInfo( bCString const & );
        GEBool                          StartComment( eCEntity * );
        GEBool                          StartInfoManager( eCEntity &, eCEntity & );
        GEBool                          SwapInfos( bCString const &, bCString const & );
        GEBool                          WriteCompiledInfoManager( bCString const & );

    protected:
        bTPtrArray<gCInfo_PS *> & GetChildInfoList( bTPtrArray<gCInfo_PS *> &, gCInfo_PS & );
        bTPtrArray<gCInfo_PS *> & GetInfoList( bTPtrArray<gCInfo_PS *> &, bCString const &, bCString const &, GEBool, GEBool, GEBool, GEBool, GEBool, GEBool );
        void                      HideDialogManager( void );
        void                      Invalidate( void );
        void                      ShowDialogManager( void );

    private:
        void BuildMapInfosByOwners( void );

    protected:
        bTPtrArray<gCInfo_PS *> m_arrInfos;
        bTPtrArray<gCInfo_PS *> m_arrAvailableInfos;
        gCEntity *              m_pDialogPartner1;
        gCEntity *              m_pDialogPartner2; // returned by GetDialogPartnerNPC
        GE_PADDING( 0x10 ) // Unknown map
        bTObjMap<bCString, bTPtrArray<gCInfo_PS *> > m_mapInfosByOwners;
};

GE_ASSERT_SIZEOF( gCInfoManager_PS, 0x6C )

#endif
