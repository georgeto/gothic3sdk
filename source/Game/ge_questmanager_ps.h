#ifndef GE_QUESTMANAGER_PS_H_INCLUDED
#define GE_QUESTMANAGER_PS_H_INCLUDED

class GE_DLLIMPORT gCQuestManager_PS :
    public eCEntityPropertySet
{
    public: virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult                                   Write( bCOStream & );
    public: virtual bEResult                                   Read( bCIStream & );
    public: virtual void                                       Destroy( void );
    public: virtual bEResult                                   Create( void );
    public: virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public: virtual                                           ~gCQuestManager_PS( void );
    public: virtual bEResult                                   PostInitializeProperties( void );
    public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public: virtual GEBool                                     IsEditorRelevant( void ) const;
    public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;

    public:
        static gCQuestManager_PS * GE_STDCALL          GetInstance( void );
        static bCString GE_STDCALL                     GetQuestDir( void );
        static bCString GE_STDCALL                     GetQuestFilePath( gCQuest_PS const * );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static GEInt GE_CCALL                          SortQuestsCbk( GELPCVoid, GELPCVoid );

    public:
        gCQuestManager_PS( gCQuestManager_PS const & );
        gCQuestManager_PS( void );

    public:
        gCQuestManager_PS const & operator = ( gCQuestManager_PS const & );

    public:
        bTObjArray<bTAutoPOSmartPtr<gCQuest_PS> > &       AccessQuests( void );
        gCQuest_PS *                                      AddQuest( bCString const & );
        void                                              BuildArrQuestsByType( void );
        GEBool                                            CloseQuest( bCString const & );
        GEBool                                            FailQuest( bCString const & );
        gCInfoManager_PS *                                GetInfoManager( void );
        gCInfoManager_PS const *                          GetInfoManager( void ) const;
        gCQuest_PS *                                      GetQuest( bCString const & );
        gCQuest_PS const *                                GetQuest( bCString const & ) const;
        bTObjArray<bTAutoPOSmartPtr<gCQuest_PS> > const & GetQuests( void ) const;
        GEBool                                            LoadQuestsFromInis( void );
        GEBool                                            OnEnclaveStateChanged( eCEntity const & );
        GEBool                                            OnEnter( eCEntity const &, bCString const & );
        GEBool                                            OnLeave( eCEntity const &, bCString const & );
        GEBool                                            OnNPCDefeated( eCEntity const & );
        GEBool                                            OnNPCKilled( eCEntity const & );
        GEBool                                            OnReceiveItem( eCEntity const *, eCEntity const *, bCPropertyID const &, GEU32 );
        GEBool                                            OnSpellCast( eCEntity const &, eCEntity const &, bCString );
        GEBool                                            RemoveQuest( bCString const & );
        GEBool                                            RenameQuest( bCString const &, bCString const & );
        void                                              ResetQuests( void );
        GEBool                                            RunQuest( bCString const & );
        void                                              SetQuests( bTObjArray<bTAutoPOSmartPtr<gCQuest_PS> > const & );
        GEBool                                            SucceedQuest( bCString const & );

    protected:
        void Invalidate( void );

};

#endif
