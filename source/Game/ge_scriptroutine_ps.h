#ifndef GE_SCRIPTROUTINE_PS_H_INCLUDED
#define GE_SCRIPTROUTINE_PS_H_INCLUDED

class bCScriptString;
class gCScriptProcessingUnit;

class GE_DLLIMPORT gCScriptRoutine_PS :
    public eCEntityPropertySet
{
    public:    virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                                   Write( bCOStream & );
    public:    virtual bEResult                                   Read( bCIStream & );
    public:    virtual void                                       Destroy( void );
    public:    virtual bEResult                                   Create( void );
    public:    virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public:    virtual                                           ~gCScriptRoutine_PS( void );
    public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
    public:    virtual GEBool                                     IsProcessable( void ) const;
    public:    virtual GEBool                                     SupportsRenderDebugOutput( void ) const;
    public:    virtual bEResult                                   ReadSaveGame( bCIStream & );
    public:    virtual bEResult                                   WriteSaveGame( bCOStream & );
    public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public:    virtual void                                       OnSaveGameEntityPostRead( void );
    public:    virtual void                                       GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    public:    virtual void                                       GetOnScreenDebugLines( GEU32, bTObjArray<eSPropertySetDebugLine> & ) const;
    protected: virtual void                                       OnRenderDebug( void );
    public:    virtual void                                       OnProcess( void );
    public:    virtual void                                       OnPreProcess( void );
    public:    virtual void                                       OnPostRead( void );
    public:    virtual void                                       OnPostCopy( eCEntityPropertySet const & );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCScriptRoutine_PS( gCScriptRoutine_PS const & );
        gCScriptRoutine_PS( void );

    public:
        gCScriptRoutine_PS const & operator = ( gCScriptRoutine_PS const & );

    public:
        void                                         AIContinueRoutine( void );
        void                                         AIFullStop( void );
        void                                         AISetLocalCallback( bCString const & );
        void                                         AISetState( bCString const & );
        void                                         AISetStateTime( GEFloat );
        void                                         AISetTask( bCString const & );
        void                                         AISetTaskCallback( bCString const & );
        void                                         AISetTaskTime( GEFloat );
        void                                         AIStopCombatMove( void );
        void                                         AIStopGoto( void );
        void                                         AIStopOutput( void );
        void                                         AIStopPlayAnimation( void );
        void                                         AIStopWait( void );
        bTPropertyContainer<gEAIMode> &              AccessAIMode( void );
        bTPropertyContainer<gEAction> &              AccessAction( void );
        bTPropertyContainer<gEAmbientAction> &       AccessAmbientAction( void );
        bTPropertyContainer<gEAniState> &            AccessAniState( void );
        GEI32 &                                      AccessCommandTime( void );
        GEI32 &                                      AccessCurrentBreakBlock( void );
        bCString &                                   AccessCurrentState( void );
        bCString &                                   AccessCurrentTask( void );
        bTPropertyContainer<gEHitDirection> &        AccessHitDirection( void );
        bCString &                                   AccessLastTask( void );
        bCScriptString &                             AccessRoutine( void );
        GEI32 &                                      AccessStatePosition( void );
        GEFloat &                                    AccessStateTime( void );
        GEI32 &                                      AccessTaskPosition( void );
        GEFloat &                                    AccessTaskTime( void );
        void                                         EnableDebugging( GEBool );
        bTPropertyContainer<gEAIMode> const &        GetAIMode( void ) const;
        bTPropertyContainer<gEAction> const &        GetAction( void ) const;
        bTPropertyContainer<gEAmbientAction> const & GetAmbientAction( void ) const;
        bTPropertyContainer<gEAniState> const &      GetAniState( void ) const;
        GEI32 const &                                GetCommandTime( void ) const;
        GEI32 const &                                GetCurrentBreakBlock( void ) const;
        bCString const &                             GetCurrentState( void ) const;
        bCString const &                             GetCurrentTask( void ) const;
        bTPropertyContainer<gEHitDirection> const &  GetHitDirection( void ) const;
        bCString const &                             GetLastTask( void ) const;
        bCScriptString const &                       GetRoutine( void ) const;
        gCScriptProcessingUnit &                     GetSPU( void );
        GEI32 const &                                GetStatePosition( void ) const;
        GEFloat const &                              GetStateTime( void ) const;
        GEI32 const &                                GetTaskPosition( void ) const;
        GEFloat const &                              GetTaskTime( void ) const;
        GEBool                                       IsDebuggingEnabled( void ) const;
        void                                         SetAIMode( bTPropertyContainer<gEAIMode> const & );
        void                                         SetAction( bTPropertyContainer<gEAction> const & );
        void                                         SetAmbientAction( bTPropertyContainer<gEAmbientAction> const & );
        void                                         SetAniState( bTPropertyContainer<gEAniState> const & );
        void                                         SetCommandTime( GEI32 const & );
        void                                         SetCurrentBreakBlock( GEI32 const & );
        void                                         SetCurrentState( bCString const & );
        void                                         SetCurrentTask( bCString const & );
        void                                         SetHitDirection( bTPropertyContainer<gEHitDirection> const & );
        void                                         SetLastTask( bCString const & );
        void                                         SetRoutine( bCScriptString const & );
        void                                         SetStatePosition( GEI32 const & );
        void                                         SetStateTime( GEFloat const & );
        void                                         SetTaskPosition( GEI32 const & );
        void                                         SetTaskTime( GEFloat const & );
        GEBool                                       StartOutput( bCString const & );
        GEBool                                       StopOutput( void );

    protected:
        void GameReset( void );
        void Invalidate( void );

};

#endif
