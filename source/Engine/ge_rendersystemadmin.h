#ifndef GE_RENDERSYSTEMADMIN_H_INCLUDED
#define GE_RENDERSYSTEMADMIN_H_INCLUDED

class eCFrustumDatabase {
    public:
        struct eSCaps;
};
class eCOcclusionProcessor;
struct eSRenderStatistics;
class eCVertexbufferPool;

class GE_DLLIMPORT eCRenderSystemAdmin :
    public eCEngineComponentBase
{
    public: virtual GEU16          GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult       Write( bCOStream & );
    public: virtual bEResult       Read( bCIStream & );
    public: virtual void           Destroy( void );
    public: virtual bEResult       Create( void );
    public: virtual bEResult       CopyFrom( bCObjectBase const & );
    public: virtual GEU32 const    GetProfileLastTicksFirst( void ) const;
    public: virtual GEU32 const    GetProfileLastTicksSecond( void ) const;
    public: virtual GEU32 const    GetProfileLastTicksThird( void ) const;
    public: virtual               ~eCRenderSystemAdmin( void );
    public: virtual bCGuid const & GetID( void ) const;
    public: virtual bEResult       PostInitialize( void );
    public: virtual bEResult       PreShutdown( void );
    public: virtual bEResult       ResetResources( GEBool );
    public: virtual bEResult       RestoreResources( GEBool );
    public: virtual void           Process( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCRenderSystemAdmin( eCRenderSystemAdmin const & );
        eCRenderSystemAdmin( void );

    public:
        eCRenderSystemAdmin const & operator = ( eCRenderSystemAdmin const & );

    public:
        void                        DrawBatchLineList( bTSmallArray<bCVector> const &, GEU32, GEBool, GEBool );
        void                        DrawBatchLineList( bCVector const &, bCVector const &, GEU32, GEBool, GEBool );
        void                        DrawBatchTLLineList( bTSmallArray<bCVector4> const &, GEU32, GEBool, GEBool );
        void                        DrawBatchTLLineList( bCVector4 const &, bCVector4 const &, GEU32, GEBool, GEBool );
        void                        EnablePrefetchEntityCallback( GEBool );
        void                        ExecuteBatchedLineList( void );
        GEBool                      FlushThreadQueues( void );
        GEBool                      GetDontResetRenderers( void ) const;
        eCFrustumDatabase::eSCaps & GetFrustumDatabaseCapsTemplate( void );
        eCOcclusionProcessor &      GetOcclusionProcessor( void );
        eCPVSPrefetcher3 &          GetPVSPrefetcher3( void );
        GEBool ( GE_STDCALL*GetPrefetchEntityCallback( void ) const )( GEInt, GEInt );
        eSRenderStatistics &       GetRenderStatistics( void );
        eSRenderStatistics const & GetRenderStatistics( void ) const;
        GEU32                      GetTimeStamp( void );
        eCVertexbufferPool &       GetVertexBufferPool( void );
        void GE_STDCALL            OnToggleBoundingBoxes( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL            OnToggleOcclusionCulling( bCObjectRefBase *, bCEvent * );
        GEBool                     RegisterDatabase( eCFrustumDatabase & );
        void                       Render( eCFrustumDatabase & );
        void                       RenderEntity( eCFrustumDatabase &, eCEntity * );
        void                       RenderShadowMap( eCFrustumDatabase &, eCShadowMapBase *, eCFrustumDatabase * );
        bEResult                   ResetRenderers( void );
        void                       SetDontResetRenderers( GEBool );
        void                       SetPrefetchEntityCallback( GEBool ( GE_STDCALL* )( GEInt, GEInt ));
        GEBool                     UnregisterDatabase( eCFrustumDatabase & );

    protected:
        void Invalidate( void );

};

#endif
