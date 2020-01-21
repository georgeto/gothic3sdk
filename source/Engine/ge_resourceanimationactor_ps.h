#ifndef GE_RESOURCEANIMATIONACTOR_PS_H_INCLUDED
#define GE_RESOURCEANIMATIONACTOR_PS_H_INCLUDED

struct eSLookAtConstraintData
{
    bCString m_strName;
    GEFloat  m_fInterpolationSpeed;
    bCVector m_MinConstraints;
    bCVector m_MaxConstraints;
};

GE_ASSERT_SIZEOF( eSLookAtConstraintData, 0x20 )

class GE_DLLIMPORT eCResourceAnimationActor_PS :
    public eCResourceBase_PS
{
    public:    virtual GEU16                          GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                       Write( bCOStream & );
    public:    virtual bEResult                       Read( bCIStream & );
    public:    virtual void                           Destroy( void );
    public:    virtual bEResult                       Create( void );
    public:    virtual bEResult                       CopyFrom( bCObjectBase const & );
    public:    virtual                               ~eCResourceAnimationActor_PS( void );
    public:    virtual bCString const &               GetProprietaryFileExt( void ) const;
    public:    virtual bCString const &               GetNativeFileExt( void ) const;
    public:    virtual eCResourceBase_PS::eECacheType GetCacheType( void ) const;
    public:    virtual bEResult                       DoLoad( void );
    public:    virtual bEResult                       DoUnload( void );
    public:    virtual bEResult                       DoReload( void );
    public:    virtual bEResult                       DoConvert( void );
    public:    virtual bEResult                       DoSave( void );
    protected: virtual void                           CalculateSize( void );
    public:    virtual void                           GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    public:    virtual void                           GetBoundary( bCBox &, GEBool );
    public:    virtual void                           OnUpdateInternals( void );

    public:
        static void GE_STDCALL                         GetNativeFileExt( bCString & );
        static void GE_STDCALL                         GetProprietaryFileExt( bCString & );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static GEBool GE_STDCALL                       IsNativeFileType( bCString const & );
        static GEBool GE_STDCALL                       IsProprietaryFileType( bCString const & );

    public:
        eCResourceAnimationActor_PS( eCResourceAnimationActor_PS const & );
        eCResourceAnimationActor_PS( void );

    public:
        eCResourceAnimationActor_PS const & operator = ( eCResourceAnimationActor_PS const & );

    public:
        eCWrapper_emfx2Actor const &               GetEMFX2Actor( void ) const;
        bTObjArray<eSLookAtConstraintData> const & GetLookAtConstraints( void ) const;

    protected:
        void DeleteResources( void );
        void ImportLookAtConstraints( void );
        void Invalidate( void );

    public:
        eCWrapper_emfx2Actor *             m_EMFX2Actor;
        bCDateTime                         m_NativeFileTime;
        GEUInt                             m_NativeFileSize;
        bTObjArray<eSLookAtConstraintData> m_arrLookAtConstraints;
        bCBox                              m_Boundary;
};

GE_ASSERT_SIZEOF( eCResourceAnimationActor_PS, 0x60 )

#endif
