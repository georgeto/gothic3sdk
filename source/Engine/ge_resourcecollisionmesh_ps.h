#ifndef GE_RESOURCECOLLISIONMESH_PS_H_INCLUDED
#define GE_RESOURCECOLLISIONMESH_PS_H_INCLUDED

struct eSVertexPosition;
struct eSPhysicMaterialInfos;
class NxConvexMesh;
class NxTriangleMesh;

class GE_DLLIMPORT eCResourceCollisionMesh_PS :
    public eCResourceBase_PS
{
    public:    virtual GEU16                          GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                       Write( bCOStream & );
    public:    virtual bEResult                       Read( bCIStream & );
    public:    virtual void                           Destroy( void );
    public:    virtual bEResult                       Create( void );
    public:    virtual bEResult                       CopyFrom( bCObjectBase const & );
    public:    virtual                               ~eCResourceCollisionMesh_PS( void );
    public:    virtual bCString const &               GetProprietaryFileExt( void ) const;
    public:    virtual bCString const &               GetNativeFileExt( void ) const;
    public:    virtual eCResourceBase_PS::eECacheType GetCacheType( void ) const;
    public:    virtual bEResult                       DoLoad( void );
    public:    virtual bEResult                       DoUnload( void );
    public:    virtual bEResult                       DoReload( void );
    public:    virtual bEResult                       DoConvert( void );
    public:    virtual bEResult                       DoSave( void );
    protected: virtual void                           CalculateSize( void );
    public:    virtual void                           GetBoundary( bCBox &, GEBool );
    public:    virtual void                           OnUpdateInternals( void );

    public:
        static void GE_STDCALL                         GetProprietaryFileExt( bCString & );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static GEBool GE_STDCALL                       IsNativeFileType( bCString const & );
        static GEBool GE_STDCALL                       IsProprietaryFileType( bCString const & );

    public:
        eCResourceCollisionMesh_PS( eCResourceCollisionMesh_PS const & );
        eCResourceCollisionMesh_PS( void );

    public:
        eCResourceCollisionMesh_PS const & operator = ( eCResourceCollisionMesh_PS const & );

    public:
        bTValArray<GEU32> &                  AccessIndexArray( void );
        eSVertexPosition &                   AccessVertexPosition( GEInt );
        GEBool                               Compute( eCResourceDataEntity *, GEBool a_bConvex, GEBool a_bAutoResolveMaterialInfos = GEFalse, bTObjArray<eSPhysicMaterialInfos> * a_pArrMaterialInfos = 0, GEFloat a_fNovodexScale = 1.0f); // a_pArrMaterialInfos ist optional, a_bAutoResolveMaterialInfos wird nur wirksam wenn a_pArrMaterialInfos == 0
        GEBool                               ComputeNovodexMesh( GEBool a_bConvex, GEBool a_bNotFlipNormals );
        void                                 CopyWithScaling( eCResourceCollisionMesh_PS &, GEFloat );
        void                                 CopyWithScaling( eCResourceCollisionMesh_PS &, GEFloat, GEFloat, GEFloat );
        GEU32                                GetIndex( GEInt ) const;
        bTValArray<GEU32> const &            GetIndexArray( void ) const;
        GEInt                                GetIndexDataCount( void ) const;
        void                                 GetIndexedBoundary( bCBox &, GEU16 );
        GEBool                               GetIndexedMaterial( eSPhysicMaterialInfos &, GEU16 );
        GEU32                                GetNumConvexMeshes( void ) const;
        GEU32                                GetNumMeshes( void ) const;
        NxConvexMesh *                       GetProprietaryConvexMesh( GEInt ) const;
        NxTriangleMesh *                     GetProprietaryMesh( GEInt ) const;
        bCDateTime                           GetUnscaledResourceModTime( void );
        GEInt                                GetVertexDataCount( void ) const;
        eSVertexPosition const &             GetVertexPosition( GEInt ) const;
        bTValArray<eSVertexPosition> const & GetVertexPositionArray( void ) const;
        GEBool                               HasConvexResource( void ) const;

    protected:
        GEBool ComputeMesh( GEBool );
        void   DeleteResources( void );
        void   Invalidate( void );

};

GE_DLLIMPORT_EXTC bCString const g_strResourceMeshCollisionFileExt;

#endif
