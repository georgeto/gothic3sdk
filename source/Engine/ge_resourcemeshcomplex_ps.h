#ifndef GE_RESOURCEMESHCOMPLEX_PS_H_INCLUDED
#define GE_RESOURCEMESHCOMPLEX_PS_H_INCLUDED

class GE_DLLIMPORT eCResourceMeshComplex_PS :
    public eCResourceBase_PS
{
    public:    virtual GEU16                          GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                       Write( bCOStream & );
    public:    virtual bEResult                       Read( bCIStream & );
    public:    virtual void                           Destroy( void );
    public:    virtual bEResult                       Create( void );
    public:    virtual bEResult                       CopyFrom( bCObjectBase const & );
    public:    virtual                               ~eCResourceMeshComplex_PS( void );
    public:    virtual bCString const &               GetNativeFileExt( void ) const;
    public:    virtual bCString const &               GetProprietaryFileExt( void ) const;
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
    public:    virtual GEBool                         IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;
    public:    virtual GEBool                         IntersectsVolume( bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool ) const;

    public:
        static bTPropertyType<eCResourceMeshComplex_PS, bCBox> ms_PropertyMember_m_BoundingBox;

    private:
        static bTPropertyObject<eCResourceMeshComplex_PS, eCResourceBase_PS> ms_PropertyObjectInstance_eCResourceMeshComplex_PS;

    public:
        static void GE_STDCALL                         GetProprietaryFileExt( bCString & );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static GEBool GE_STDCALL                       IsNativeFileType( bCString const & );
        static GEBool GE_STDCALL                       IsProprietaryFileType( bCString const & );

    public:
        eCResourceMeshComplex_PS( eCResourceMeshComplex_PS const & );
        eCResourceMeshComplex_PS( void );

    public:
        eCResourceMeshComplex_PS const & operator = ( eCResourceMeshComplex_PS const & );

    public:
        bCBox &                AccessBoundingBox( void );
        GEBool                 AddMeshElement( eCMeshElement * );
        GEBool                 AddMeshFile( bCString const & );
        bCBox const &          GetBoundingBox( void ) const;
        eCMeshElement *        GetMeshElement( GEInt ) const;
        GEInt                  GetMeshResourceCount( void ) const;
        eCResourceDataEntity * QueryDefaultLightmap( GEBool );
        GEBool                 RemoveMeshFileAt( GEInt );
        void                   SetBoundingBox( bCBox const & );

    protected:
        void DeleteResources( void );
        void Invalidate( void );

};

#endif
