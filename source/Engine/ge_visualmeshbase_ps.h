#ifndef GE_VISUALMESHBASE_PS_H_INCLUDED
#define GE_VISUALMESHBASE_PS_H_INCLUDED

class bCMeshResourceString : public bCString
{
};

class GE_DLLIMPORT eCVisualMeshBase_PS :
    public eCEntityPropertySet
{
    public:    virtual GEBool                 IsResourceLoaded( void ) const;
    public:    virtual eCResourceDataEntity * GetResourceDataEntity( void );
    public:    virtual void                   SetResourceDataEntity( eCResourceDataEntity * );
    public:    virtual eCResourceDataEntity * GetLightmapResourceDataEntity( GEU16, GEBool );
    public:    virtual GEBool                 CopyLightmapsFrom( eCVisualMeshBase_PS *, GEBool );
    protected: virtual void                   SetLightmapResource( eCResourceDataEntity *, GEU16 );
    public:    virtual GEBool                 ConvertFrom( eCVisualMeshBase_PS const & );
    public:    virtual GEU16                  GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult               Write( bCOStream & );
    public:    virtual bEResult               Read( bCIStream & );
    public:    virtual void                   Destroy( void );
    public:    virtual bEResult               Create( void );
    public:    virtual bEResult               CopyFrom( bCObjectBase const & );
    public:    virtual                       ~eCVisualMeshBase_PS( void );
    public:    virtual GEBool                 HasRenderAlphaComponent( void ) const;
    public:    virtual bEResult               PostInitializeProperties( void );
    public:    virtual GEBool                 OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    public:    virtual eEPropertySetType      GetPropertySetType( void ) const;
    public:    virtual GEBool                 IsVisual( void ) const;
    public:    virtual GEBool                 IsEditorRelevant( void ) const;
    public:    virtual eCRenderContext *      QueryRenderContext( void );
    public:    virtual void                   GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    public:    virtual eCVisualMeshBase_PS *  Clone( eCEntity * ) const;
    protected: virtual void                   OnUpdateInternals( void );
    protected: virtual void                   OnCacheIn( void );
    protected: virtual void                   OnCacheOut( void );
    public:    virtual void                   GetBoundary( bCBox &, GEBool );
    public:    virtual GEBool                 IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;
    public:    virtual GEBool                 IntersectsVolume( bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool ) const;
    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCVisualMeshBase_PS( eCVisualMeshBase_PS const & );
        eCVisualMeshBase_PS( void );

    public:
        eCVisualMeshBase_PS const & operator = ( eCVisualMeshBase_PS const & );

    public:
        bTPropertyContainer<eELightmapAmbientOcclusion> &       AccessLightmapAmbientOcclusion( void );
        bTPropertyContainer<eELightmapType> &                   AccessLightmapType( void );
        GEInt &                                                 AccessMaterialSwitch( void );
        bCMeshResourceString &                                  AccessResourceFileName( void );
        bTPropertyContainer<eEStaticLighingType> &              AccessStaticLightingType( void );
        GEFloat &                                               AccessUnitsPerLightmapTexel( void );
        eCResourceDataEntity *                                  CreateLightmapResource( GEBool, GEU16 );
        bTPropertyContainer<eELightmapAmbientOcclusion> const & GetLightmapAmbientOcclusion( void ) const;
        bTPropertyContainer<eELightmapType> const &             GetLightmapType( void ) const;
        GEInt const &                                           GetMaterialSwitch( void ) const;
        bCMeshResourceString const &                            GetResourceFileName( void ) const;
        bTPropertyContainer<eEStaticLighingType> const &        GetStaticLightingType( void ) const;
        GEFloat const &                                         GetUnitsPerLightmapTexel( void ) const;
        void                                                    SetLightmapAmbientOcclusion( bTPropertyContainer<eELightmapAmbientOcclusion> const & );
        void                                                    SetLightmapType( bTPropertyContainer<eELightmapType> const & );
        void                                                    SetMaterialSwitch( GEInt const & );
        void                                                    SetResourceFileName( bCMeshResourceString const & );
        void                                                    SetStaticLightingType( bTPropertyContainer<eEStaticLighingType> const & );
        void                                                    SetUnitsPerLightmapTexel( GEFloat const & );

    protected:
        void Invalidate( void );
        void OnCacheOutLightmaps( void );

};

#endif
