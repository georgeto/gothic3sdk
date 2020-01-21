#ifndef GE_LIGHTMAP_H_INCLUDED
#define GE_LIGHTMAP_H_INCLUDED

class eCLightmapBitmap;
class eCLightmapTexture;
class eCVertexbufferPoolItem;

class GE_DLLIMPORT eCLightmap :
    public bCObjectRefBase
{
    public: virtual GEU16    GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual         ~eCLightmap( void );

    public:
        eCLightmap( eCLightmap const & );
        eCLightmap( void );

    public:
        eCLightmap & operator = ( eCLightmap const & );

    public:
                                             eCLightmap( eCResourceMeshComplex_PS *, eCResourceDataEntity *, GEInt, GEFloat, eELightmapType );
        void                                 Blur( void );
        GEBool                               ClearStaticLight( void );
        GEBool                               CopyDefaultValuesFromMesh( void );
        void                                 FillVertices( GELPChar, GEInt );
        bTObjArray<eCLightmapBitmap> const & GetBitmaps( void ) const;
        eCLightmapTexture *                  GetLightmapTexture( void ) const;
        eELightmapType                       GetLightmapType( void ) const;
        eCMeshElement *                      GetMeshElement( GEBool );
        bTValArray<GEU32> &                  GetPerVertexColors( void );
        bTValArray<GEU32> const &            GetPerVertexColors( void ) const;
        bTValArray<bCVector> &               GetPerVertexIncident( void );
        bTValArray<bCVector> const &         GetPerVertexIncident( void ) const;
        eCResourceDataEntity *               GetResourceDataEntity( void ) const;
        GEFloat                              GetScaling( void ) const;
        GEU32                                GetSize( void ) const;
        GEU32                                GetTextureSize( void );
        GEInt                                GetVertexCount( void );
        eCVertexbufferPoolItem *             GetVertexbufferPoolItem( void ) const;
        void                                 Invalidate( void );
        GEBool                               IsDirty( void );
        void                                 SetDirty( GEBool );
        GEBool                               SetLightmapTexture( eCLightmapTexture * );
        void                                 SetLightmapType( eELightmapType );
        void                                 SetScaling( GEFloat );
        void                                 SetVertexbufferPoolItem( eCVertexbufferPoolItem * );
        void                                 UnloadResources( void );
        void                                 UpdateVertexbufferPoolItem( void );

};

#endif
