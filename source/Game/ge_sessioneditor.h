#ifndef GE_SESSIONEDITOR_H_INCLUDED
#define GE_SESSIONEDITOR_H_INCLUDED

class GE_DLLIMPORT gCSessionEditor :
    public eCInputReceiver
{
    public: using eCInputReceiver::CopyFrom;
    public:    virtual void                             CopyFrom( gCSessionEditor const & );
    public: using bCObjectBase::Write;
    public:    virtual bEResult                         Write( bCOStream & );
    public:    virtual bEResult                         Read( bCIStream & );
    public:    virtual void                             Destroy( void );
    public:    virtual bEResult                         Create( void );
    public:    virtual                                 ~gCSessionEditor( void );
    protected: virtual eCInputReceiver::eEInputPriority GetInputPriority( void ) const;
    protected: virtual GEInt                            OnAction( eCInpShared::eSGameKeyMessage const & );
    protected: virtual GEInt                            OnKeyboard( eCInpShared::eSInputMessage const & );
    protected: virtual GEInt                            OnMouse( eCInpShared::eSInputMessage const & );

    public:
        static bTPropertyType<gCSessionEditor, bTPropertyContainer<gESessionEditorState> > ms_PropertyMember_m_enuState;
        static bTPropertyObject<gCSessionEditor, eCInputReceiver>                          ms_PropertyObjectInstance_gCSessionEditor;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCSessionEditor( void );

    public:
        gCSessionEditor const & operator =  ( gCSessionEditor const & );
        bCOStream &             operator >> ( bCOStream & );
        bCIStream &             operator << ( bCIStream & );

    public:
        bTPropertyContainer<gESessionEditorState> &       AccessState( void );
        NxActor *                                         GetCurrentDragActor( void ) const;
        eCEntity *                                        GetCurrentEntity( void ) const;
        bTPropertyContainer<gESessionEditorState> const & GetState( void ) const;
        void                                              Invalidate( void );
        void                                              OnPostRender( void );
        void                                              PreShutdown( void );
        void                                              Process( void );
        void                                              SetCurrentDragActor( NxActor * );
        void                                              SetCurrentEntity( eCEntity * );
        void                                              SetState( bTPropertyContainer<gESessionEditorState> const & );
        void                                              Show( GEBool );

    protected:
        gCSessionEditor( gCSessionEditor const & );

    protected:
        void            LineDrag( bCVector const &, bCVector const & );
        void            LinePick( bCVector const &, bCVector const &, bCVector const & );
        void GE_STDCALL OnConsoleCommand( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnDesktopClick( bCObjectRefBase *, eCClickEventArg * );
        void GE_STDCALL OnEditMenuClicked( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnFreeCamMode( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnNavigateMode( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnPhysicsMode( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnPropertyMode( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnSteeringMode( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnToggleOption( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnViewMenuClicked( bCObjectRefBase *, bCEvent * );
        void            RemoveAddedPSets( void );
        void            UnPick( void );

    private:
        void DeregisterEvents( void );
        void RegisterEvents( void );

};

#endif
