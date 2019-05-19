#ifndef GE_CAMERABASE_H_INCLUDED
#define GE_CAMERABASE_H_INCLUDED

class eCFrustumDatabase;
class eCShadowMapBase;
enum eECamUpdate;

class GE_DLLIMPORT eCCameraBase :
    public bCObjectRefBase
{
    public: virtual bEResult Init( bCRect const &, GEFloat, GEFloat, GEFloat );
    public: virtual bEResult Init( HWND__ *, GEFloat, GEFloat, GEFloat );
    public: virtual bEResult Create( GEBool, GEBool );
    public: virtual void     UpdateViewport( GEBool );
    public: virtual void     UpdateProjection( GEBool );
    public: virtual GEU16    GetVersion( void ) const;
    public: virtual GEBool   IsValid( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual bEResult CopyFrom( bCObjectBase const & );
    public: virtual GEU32    AddReference( void );
    public: virtual GEU32    ReleaseReference( void );
    public: virtual         ~eCCameraBase( void );
    public: virtual bEResult PostInitializeProperties( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCCameraBase( eCCameraBase const & );
        eCCameraBase( void );

    public:
        eCCameraBase const & operator =  ( eCCameraBase const & );
        bCOStream &          operator >> ( bCOStream & );
        bCIStream &          operator << ( bCIStream & );

    public:
        GEFloat &                 AccessAspectRatio( void );
        bCVector2 &               AccessClipDepth( void );
        bCVector2 &               AccessClipProjection( void );
        GEFloat &                 AccessDepthBias( void );
        GEFloat &                 AccessFieldOfView( void );
        GEBool &                  AccessPerspective( void );
        bCVector &                AccessPosition( void );
        bCMatrix &                AccessProjectionMatrix( void );
        bCVector &                AccessRotation( void );
        bCVector &                AccessScale( void );
        bCRect &                  AccessScreen( void );
        bCMatrix &                AccessViewMatrix( void );
        void                      ExecuteGfxCamera( void );
        GEFloat const &           GetAspectRatio( void ) const;
        bCVector2 const &         GetClipDepth( void ) const;
        bCVector2 const &         GetClipProjection( void ) const;
        GEFloat const &           GetDepthBias( void ) const;
        GEFloat const &           GetFieldOfView( void ) const;
        eCFrustumDatabase &       GetFrustumDatabase( void );
        eCFrustumDatabase const & GetFrustumDatabase( void ) const;
        eCFrustumDatabase &       GetLowPolyFrustumDatabase( void );
        eCFrustumDatabase const & GetLowPolyFrustumDatabase( void ) const;
        GEBool const &            GetPerspective( void ) const;
        bCVector const &          GetPosition( void ) const;
        bCMatrix const &          GetProjectionMatrix( void ) const;
        bCVector const &          GetRotation( void ) const;
        bCVector const &          GetScale( void ) const;
        bCRect const &            GetScreen( void ) const;
        bCMatrix                  GetScreenToWorldMatrix( void ) const;
        bCMatrix const &          GetViewMatrix( void ) const;
        bCMatrix                  GetWorldToScreenMatrix( void ) const;
        void                      GetZAxis( bCVector & ) const;
        void                      GoToEntity( eCEntity const & );
        GEBool                    IsInLowPolyFrame( void ) const;
        GEBool                    IsOrthogonal( void ) const;
        void                      LookAt( bCVector const & );
        void                      Move( bCVector const & );
        void                      MoveForward( GEFloat, GEBool );
        void                      MoveHeight( GEFloat );
        void                      MoveLocal( bCVector const & );
        void                      MoveSideways( GEFloat );
        void                      PointToRay( bCPoint const &, bCRay & ) const;
        void                      PointToRay( bCPoint const &, bCUnitedRay & ) const;
        void                      RectToBox( bCRect const &, bCBox & ) const;
        bCFrustum                 RectToFrustum( bCRect const & ) const;
        void                      RectToFrustum( bCRect const &, bCFrustum & ) const;
        void                      Render( GEBool, GEBool );
        void                      RenderEntity( eCEntity *, GEBool );
        void                      RenderLowPoly( void );
        void                      RenderShadowMap( GEBool, eCShadowMapBase * );
        void                      Roll( GEFloat );
        void                      RotateAngularAbs( bCVector const & );
        void                      RotateAngularRel( bCVector const & );
        void                      RotateHeigth( GEFloat );
        void                      RotateSideways( GEFloat );
        void                      ScreenToView( bCVector & ) const;
        void                      ScreenToWorld( bCVector & ) const;
        void                      SetAspectRatio( GEFloat const & );
        void                      SetClipDepth( bCVector2 const & );
        void                      SetClipProjection( bCVector2 const & );
        void                      SetDepthBias( GEFloat const & );
        void                      SetFieldOfView( GEFloat const & );
        void                      SetPerspective( GEBool const & );
        void                      SetPosition( bCVector const & );
        void                      SetProjectionMatrix( bCMatrix const & );
        void                      SetRotation( bCVector const & );
        void                      SetScale( bCVector const & );
        void                      SetScreen( bCRect const & );
        void                      SetViewMatrix( bCMatrix const & );
        void                      TogglePerspectiveOrthogonal( void );
        void                      UpdateInitialValuesFromApp( void );
        void                      ViewToScreen( bCVector & ) const;
        void                      WorldToScreen( bCVector & ) const;

    protected:
        void CalcProjectionMatrix( void );
        void CalcViewMatrix( void );
        void CopyTo( eCCameraBase & ) const;
        void InitializeCamera( void );
        void Invalidate( void );
        void Update( eECamUpdate );

};

#endif
