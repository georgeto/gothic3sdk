#ifndef GE_INFOSCRIPT_PS_H_INCLUDED
#define GE_INFOSCRIPT_PS_H_INCLUDED

class gCInfo_PS;

GE_IMPORT_PROPERTY_SET( gCInfoScript_PS, bCObjectRefBase )
    public: virtual GEBool            IsEditorRelevant( void ) const;
    public: virtual eEPropertySetType GetPropertySetType( void ) const;
    public: virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult          Write( bCOStream & );
    public: virtual bEResult          Read( bCIStream & );
    public: virtual void              Destroy( void );
    public: virtual bEResult          Create( void );
    public: virtual bEResult          CopyFrom( bCObjectBase const & );
    public: virtual ~gCInfoScript_PS( void );
    public: virtual bEResult PostInitializeProperties( void );

    public:
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bTAutoPOSmartPtr<class gCInfoScriptLine_PS> >, InfoScriptLines,   m_arrInfoScriptLines )
        GE_IMPORT_DECLARE_PROPERTY( GEInt,                                                          CurrentScriptLine, m_currentScriptLine ) // Read only
        GE_IMPORT_DECLARE_PROPERTY( GEBool,                                                         ScriptIsRunnig,    m_bScriptIsRunning ) // Read only

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCInfoScript_PS( gCInfoScript_PS const & );
        gCInfoScript_PS( void );

    public:
        gCInfoScript_PS const & operator = ( gCInfoScript_PS const & );

    public:
        void                        AddCommand( bCString const &, bCString const &, bCString const &, bCString const &, bCString const &, eCLocString const & );
        GEBool                      Execute( gCInfo_PS * );
        gCInfoScriptLine_PS *       GetCommand( GEInt );
        gCInfoScriptLine_PS const * GetCommand( GEInt ) const;
        GEInt                       GetCommandCount( void ) const;
        gCInfoScriptLine_PS *       GetCurrentCommand( void );
        gCInfoScriptLine_PS const * GetCurrentCommand( void ) const;
        gCInfo_PS *                 GetInfo( void );
        GEBool                      IsRunning( void ) const;
        void                        OnCommandCompleted( GEBool );
        void                        SetInfo( gCInfo_PS * );

    protected:
        void Invalidate( void );

    protected:
        gCInfo_PS * m_pInfo;
};

GE_ASSERT_SIZEOF( gCInfoScript_PS, 0x24 )

#endif
