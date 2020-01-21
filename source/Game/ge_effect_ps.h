#ifndef GE_EFFECT_PS_H_INCLUDED
#define GE_EFFECT_PS_H_INCLUDED

GE_IMPORT_PROPERTY_SET(gCEffect_PS, eCEntityPropertySet)
    public: virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult          Write( bCOStream & );
    public: virtual bEResult          Read( bCIStream & );
    public: virtual void              Destroy( void );
    public: virtual bEResult          Create( void );
    public: virtual bEResult          CopyFrom( bCObjectBase const & );
    public: virtual                  ~gCEffect_PS( void );
    public: virtual bEResult          PostInitializeProperties( void );
    public: virtual eEPropertySetType GetPropertySetType( void ) const;
    public: virtual GEBool            IsProcessable( void ) const;
    public: virtual GEBool            IsEditorRelevant( void ) const;
    public: virtual GEBool            IsAutoKillEnabled( void ) const;
    public: virtual void              GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    public: virtual void              OnEnterProcessingRange( void );
    public: virtual void              OnExitProcessingRange( void );
    public: virtual GEBool            SupportsRenderDebugOutput( void ) const;
    public: virtual void              Decay( void );
    public: virtual void              GetOnScreenDebugLines( GEU32, bTObjArray<eSPropertySetDebugLine> & ) const;
    public: virtual void              OnCacheOut( void );
    public: virtual void              GetBoundary( bCBox &, GEBool );
    public: virtual void              OnProcess( void );

    private:
        static bTPropertyObject<gCEffect_PS, eCEntityPropertySet> ms_PropertyObjectInstance_gCEffect_PS;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        GE_IMPORT_DECLARE_PROPERTY( bCString, Effect,      m_strEffect )
        GE_IMPORT_DECLARE_PROPERTY( bCVector, Offset,      m_vecOffset )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat,  Probability, m_fProbability )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,   Static,      m_bStatic )
        GE_PADDING( 1 )

    public:
        gCEffect_PS( gCEffect_PS const & );
        gCEffect_PS( void );

    public:
        gCEffect_PS const & operator = ( gCEffect_PS const & );

    public:
        GEBool IsRuntimeEffectStarted( bCString const & );
        GEBool StartEffect( bCString const &, GEBool );
        GEBool StartRuntimeEffect( bCString const &, bCVector * );
        GEBool StopAllRuntimeEffects( GEBool );
        GEBool StopRuntimeEffect( bCString const &, GEBool );

    protected:
        void CreateEffect( void );
        void DestroyEffect( GEBool );
        void Invalidate( void );
};

#endif
