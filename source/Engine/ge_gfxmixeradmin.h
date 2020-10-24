#ifndef GE_GFXMIXERADMIN_H_INCLUDED
#define GE_GFXMIXERADMIN_H_INCLUDED


class eCGfxVertexProgram;
class eCGfxTextureBlock;
class eCGfxShader;
class eCGfxPixelProgram;
class eCGfxMaterial;
class eCGfxLight;
class eCGfxImageAVIData;
class eCGfxFog;
class eCGfxEffect;
class eCGfxCamera;
class eCGfxCameraStates;


class GE_DLLIMPORT eCGfxMixerAdmin :
    public bCObjectRefBase
{
    public:    virtual bEResult PostInitialize( void );
    public:    virtual GEBool   IsValid( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );
    protected: virtual         ~eCGfxMixerAdmin( void );

    protected:
        static GEBool ms_bOptimize;

    public:
        eCGfxMixerAdmin( eCGfxMixerAdmin const & );

    public:
        eCGfxMixerAdmin & operator = ( eCGfxMixerAdmin const & );

    public:
        bEResult        AddSpriteToSpriteList( eCGfxImageData *, bCRect const *, bCVector const *, bCVector const *, GEU32 );
        bEResult        AttachMasterCamera( eCGfxCamera * ) const;
        bEResult        AttachMasterCameraStates( eCGfxCameraStates * ) const;
        bEResult        AttachMasterEffect( eCGfxEffect * ) const;
        bEResult        AttachMasterFog( eCGfxFog * ) const;
        bEResult        AttachMasterImageAVIData( GEU32, eCGfxImageAVIData * ) const;
        bEResult        AttachMasterImageData( GEU32, eCGfxImageData * ) const;
        bEResult        AttachMasterLight( eCGfxLight * ) const;
        bEResult        AttachMasterMaterial( eCGfxMaterial * ) const;
        bEResult        AttachMasterPixelProgram( eCGfxPixelProgram * ) const;
        bEResult        AttachMasterShader( eCGfxShader * ) const;
        bEResult        AttachMasterTextureBlock( GEU32, eCGfxTextureBlock * ) const;
        bEResult        AttachMasterVertexProgram( eCGfxVertexProgram * ) const;
        bEResult        BeginScene( void ) const;
        bEResult        BeginSpriteList( eCGfxShared::eESpriteRenderOpt ) const;
        GEInt           CalcTextRect( eCGfxFont *, GELPCChar, GEInt, bCRect &, GEU32 );
        GEInt           CalcTextRect( eCGfxFont *, GELPCUnicodeChar, GEInt, bCRect &, GEU32 );
        bEResult        ClearViewport( eCGfxShared::eEViewportClear, GEU32, GEFloat, GEU32 ) const;
        bEResult        CreateSpecialDepthBuffer( GEU32, GEU32, eCGfxShared::eEDepthFormat, GELPVoid & ) const;
        bEResult        DestroySpecialDepthBuffer( GELPVoid const ) const;
        bEResult        DrawBox( bCBox const &, GEU32, bCMatrix const &, GEBool, GEBool, GEBool );
        bEResult        DrawCircle( bCVector const &, GEFloat, bCVector const &, GEU32, bCMatrix const &, GEBool, GEBool, GEBool );
        bEResult        DrawCone( bCVector const &, GEFloat, GEFloat, bCVector const &, GEU32, bCMatrix const &, GEBool, GEBool, GEBool );
        bEResult        DrawCylinder( bCVector const &, GEFloat, GEFloat, GEFloat, bCVector const &, GEU32, bCMatrix const &, GEBool, GEBool, GEBool );
        bEResult        DrawLineList( bTSmallArray<bCVector> const &, GEU32, eCGfxShared::eECmpFunc, GEBool ) const;
        bEResult        DrawLineList( bTSmallArray<bCVector> const &, GEU32, GEBool, GEBool ) const;
        bEResult        DrawRay( bCUnitedRay const &, GEU32, bCMatrix const &, GEBool, GEBool );
        bEResult        DrawSphere( bCSphere const &, GEU32, bCMatrix const &, GEBool, GEBool, GEBool );
        bEResult        DrawTLLineList( bTSmallArray<eCGfxShared::eSTLColVertex> const &, eCGfxShared::eECmpFunc ) const;
        bEResult        DrawTLLineList( bTSmallArray<eCGfxShared::eSTLColVertex> const &, GEBool ) const;
        bEResult        DrawTLLineList( bTSmallArray<bCVector4> const &, GEU32, eCGfxShared::eECmpFunc ) const;
        bEResult        DrawTLLineList( bTSmallArray<bCVector4> const &, GEU32, GEBool ) const;
        bEResult        DrawTLTriangleFan( bTSmallArray<eCGfxShared::eSTLTexDiffuseVertex> const & ) const;
        bEResult        DrawTLTriangleFan( bTSmallArray<eCGfxShared::eSTLTexVertex> const & ) const;
        bEResult        DrawTLTriangleList( bTSmallArray<eCGfxShared::eSTLTexDiffuseVertex> const & ) const;
        bEResult        DrawTLTriangleList( bTSmallArray<eCGfxShared::eSTLTexVertex> const & ) const;
        bEResult        DrawTLTriangleStrip( bTSmallArray<eCGfxShared::eSTLTexDiffuseVertex> const & ) const;
        bEResult        DrawTLTriangleStrip( bTSmallArray<eCGfxShared::eSTLTexVertex> const & ) const;
        GEInt           DrawTextViaSpriteList( eCGfxFont *, bCString const &, GEInt, bCRect const *, GEU32, GEU32 );
        GEInt           DrawTextViaSpriteList( eCGfxFont *, bCUnicodeString const &, GEInt, bCRect const *, GEU32, GEU32 );
        bEResult        DrawTorus( bCVector const &, GEFloat, GEFloat, bCVector const &, GEU32, bCMatrix const &, GEBool, GEBool, GEBool );
        bEResult        DrawTriangleFan( bTSmallArray<eCGfxShared::eSTexVertex> const & ) const;
        bEResult        DrawTriangleList( bTSmallArray<eCGfxShared::eSTexVertex> const & ) const;
        bEResult        DrawTriangleList( bTSmallArray<bCVector> const &, GEU32, eCGfxShared::eECmpFunc, GEBool ) const;
        bEResult        DrawTriangleList( bTSmallArray<bCVector> const &, GEU32, GEBool, GEBool ) const;
        bEResult        DrawTriangleStrip( bTSmallArray<eCGfxShared::eSTexVertex> const & ) const;
        bEResult        EnableClipping( GEBool ) const;
        bEResult        EnableScissor( GEBool ) const;
        bEResult        EndScene( void ) const;
        bEResult        EndSpriteList( void ) const;
        bEResult        FlushSpriteList( void ) const;
        bEResult        GetActiveCamera( eCGfxCamera * & ) const;
        bEResult        GetActiveCameraStates( eCGfxCameraStates * & ) const;
        bEResult        GetActiveEffect( eCGfxEffect * & ) const;
        bEResult        GetActiveFog( eCGfxFog * & ) const;
        bEResult        GetActiveImageAVIData( GEU32, eCGfxImageAVIData * & ) const;
        bEResult        GetActiveImageData( GEU32, eCGfxImageData * & ) const;
        bEResult        GetActiveLight( eCGfxLight * & ) const;
        bEResult        GetActiveMaterial( eCGfxMaterial * & ) const;
        bEResult        GetActivePixelProgram( eCGfxPixelProgram * & ) const;
        bEResult        GetActiveShader( eCGfxShader * & ) const;
        bEResult        GetActiveTextureBlock( GEU32, eCGfxTextureBlock * & ) const;
        bEResult        GetActiveVertexProgram( eCGfxVertexProgram * & ) const;
        bEResult        GetAttachedMasterCamera( eCGfxCamera * & ) const;
        bEResult        GetAttachedMasterCameraStates( eCGfxCameraStates * & ) const;
        bEResult        GetAttachedMasterEffect( eCGfxEffect * & ) const;
        bEResult        GetAttachedMasterFog( eCGfxFog * & ) const;
        bEResult        GetAttachedMasterImageAVIData( GEU32, eCGfxImageAVIData * & ) const;
        bEResult        GetAttachedMasterImageData( GEU32, eCGfxImageData * & ) const;
        bEResult        GetAttachedMasterLight( eCGfxLight * & ) const;
        bEResult        GetAttachedMasterMaterial( eCGfxMaterial * & ) const;
        bEResult        GetAttachedMasterPixelProgram( eCGfxPixelProgram * & ) const;
        bEResult        GetAttachedMasterShader( eCGfxShader * & ) const;
        bEResult        GetAttachedMasterTextureBlock( GEU32, eCGfxTextureBlock * & ) const;
        bEResult        GetAttachedMasterVertexProgram( eCGfxVertexProgram * & ) const;
        bEResult        GetClipPlane( GEU32, GEBool & ) const;
        bEResult        GetClipPlaneData( GEU32, eCGfxShared::eSGfxPlaneData & ) const;
        bEResult        GetClippingEnables( GEBool & ) const;
        GEU32           GetDrawnVisualIndices( void ) const;
        GEU32           GetDrawnVisualVertices( void ) const;
        bEResult        GetEffectBlueGamma( GEFloat & ) const;
        bEResult        GetEffectBrightness( GEFloat & ) const;
        bEResult        GetEffectContrast( GEFloat & ) const;
        bEResult        GetEffectGreenGamma( GEFloat & ) const;
        bEResult        GetEffectRedGamma( GEFloat & ) const;
        bEResult        GetFVFSize( GEU32, GEU32 & ) const;
        bEResult        GetForceLowestMipMapLevel( GEBool & ) const;
        bEResult        GetMasterAlphaBlending( GEBool & ) const;
        bEResult        GetMasterAlphaTesting( eCGfxShared::eEMasterAlphaTest &, eCGfxShared::eSGfxAlphaTestData & ) const;
        bEResult        GetMasterAlphaWriting( GEBool & ) const;
        bEResult        GetMasterBlending( eCGfxShared::eEMasterBlending &, eCGfxShared::eEMasterBlending & ) const;
        bEResult        GetMasterBlueGamma( GEFloat & ) const;
        bEResult        GetMasterBrightness( GEFloat & ) const;
        bEResult        GetMasterColorWriting( GEBool & ) const;
        bEResult        GetMasterContrast( GEFloat & ) const;
        bEResult        GetMasterCullingMode( eCGfxShared::eEMasterCullingMode & ) const;
        bEResult        GetMasterDepthBias( GEBool &, GEFloat &, GEFloat & ) const;
        bEResult        GetMasterDepthTesting( eCGfxShared::eEMasterCmpFunc & ) const;
        bEResult        GetMasterDepthWrite( eCGfxShared::eEMasterWrite & ) const;
        bEResult        GetMasterFogging( eCGfxShared::eEMasterFogging & ) const;
        bEResult        GetMasterGammaRamp( eCGfxShared::eSGfxGammaRamp & ) const;
        bEResult        GetMasterGreenGamma( GEFloat & ) const;
        bEResult        GetMasterLighting( GEBool & ) const;
        bEResult        GetMasterRedGamma( GEFloat & ) const;
        bEResult        GetMasterRenderMode( eCGfxShared::eEMasterRenderMode & ) const;
        bEResult        GetMasterShadeMode( eCGfxShared::eEMasterShadeMode & ) const;
        bEResult        GetMasterStencilTesting( eCGfxShared::eEMasterStencil &, eCGfxShared::eSGfxStencilData & ) const;
        bEResult        GetMasterZBias( GEBool &, GEU32 & ) const;
        GEU32           GetNumDrawCalls( void ) const;
        bEResult        GetPixelProgramRegisterB( GEU32, GEInt *, GEU32 );
        bEResult        GetPixelProgramRegisterF( GEU32, GEFloat *, GEU32 );
        bEResult        GetPixelProgramRegisterI( GEU32, GEInt *, GEU32 );
        bEResult        GetRenderTarget( GELPVoid &, GELPVoid & ) const;
        bEResult        GetScissor( bCRect & ) const;
        bEResult        GetSpriteTrafo( bCMatrix & ) const;
        bEResult        GetUserTextureFilter( eCGfxShared::eETexFilter &, GEInt & ) const;
        bEResult        GetVertexProgramRegisterB( GEU32, GEInt *, GEU32 );
        bEResult        GetVertexProgramRegisterF( GEU32, GEFloat *, GEU32 );
        bEResult        GetVertexProgramRegisterI( GEU32, GEInt *, GEU32 );
        bEResult        GetViewMatrix( bCMatrix & ) const;
        bEResult        GetViewport( eCGfxShared::eSGfxViewport & ) const;
        bEResult        GetWorldMatrix( bCMatrix & ) const;
        void            Invalidate( void );
        GEBool          IsScissorEnabled( void ) const;
        void GE_STDCALL OnToggleRenderMode( bCObjectRefBase *, bCEvent * );
        bEResult        SetClipPlane( GEU32, GEBool );
        bEResult        SetClipPlaneData( GEU32, eCGfxShared::eSGfxPlaneData const & ) const;
        bEResult        SetEffectBlueGamma( GEFloat );
        bEResult        SetEffectBrightness( GEFloat );
        bEResult        SetEffectContrast( GEFloat );
        bEResult        SetEffectGreenGamma( GEFloat );
        bEResult        SetEffectRedGamma( GEFloat );
        bEResult        SetForceLowestMipMapLevel( GEBool );
        bEResult        SetMasterAlphaBlending( GEBool ) const;
        bEResult        SetMasterAlphaTesting( eCGfxShared::eEMasterAlphaTest, eCGfxShared::eSGfxAlphaTestData const & ) const;
        bEResult        SetMasterAlphaWriting( GEBool ) const;
        bEResult        SetMasterBlending( eCGfxShared::eEMasterBlending, eCGfxShared::eEMasterBlending ) const;
        bEResult        SetMasterBlueGamma( GEFloat );
        bEResult        SetMasterBrightness( GEFloat );
        bEResult        SetMasterColorWriting( GEBool ) const;
        bEResult        SetMasterContrast( GEFloat );
        bEResult        SetMasterCullingMode( eCGfxShared::eEMasterCullingMode ) const;
        bEResult        SetMasterDepthBias( GEBool, GEFloat, GEFloat ) const;
        bEResult        SetMasterDepthTesting( eCGfxShared::eEMasterCmpFunc ) const;
        bEResult        SetMasterDepthWrite( eCGfxShared::eEMasterWrite ) const;
        bEResult        SetMasterFogging( eCGfxShared::eEMasterFogging ) const;
        bEResult        SetMasterGammaRamp( GEBool, eCGfxShared::eSGfxGammaRamp const & ) const;
        bEResult        SetMasterGreenGamma( GEFloat );
        bEResult        SetMasterLighting( GEBool ) const;
        bEResult        SetMasterRedGamma( GEFloat );
        bEResult        SetMasterRenderMode( eCGfxShared::eEMasterRenderMode ) const;
        bEResult        SetMasterShadeMode( eCGfxShared::eEMasterShadeMode ) const;
        bEResult        SetMasterStencilTesting( eCGfxShared::eEMasterStencil, eCGfxShared::eSGfxStencilData const & ) const;
        bEResult        SetMasterZBias( GEBool, GEU32 ) const;
        bEResult        SetPixelProgramRegisterB( GEU32, GEInt const *, GEU32 );
        bEResult        SetPixelProgramRegisterF( GEU32, GEFloat const *, GEU32 );
        bEResult        SetPixelProgramRegisterI( GEU32, GEInt const *, GEU32 );
        bEResult        SetRenderTarget( GELPVoid const, GELPVoid const, GELPVoid const ) const;
        bEResult        SetSamplerState( GEU32, eCGfxShared::eESamplerState, GEU32 ) const;
        bEResult        SetScissor( bCRect const & ) const;
        bEResult        SetSpriteTrafo( bCMatrix const & );
        bEResult        SetTextureCoordIndex( GEU32, GEU32 ) const;
        bEResult        SetUserTextureFilter( eCGfxShared::eETexFilter, GEInt );
        bEResult        SetVertexProgramRegisterB( GEU32, GEInt const *, GEU32 );
        bEResult        SetVertexProgramRegisterF( GEU32, GEFloat const *, GEU32 );
        bEResult        SetVertexProgramRegisterI( GEU32, GEInt const *, GEU32 );
        bEResult        SetViewMatrix( bCMatrix const & );
        bEResult        SetViewport( eCGfxShared::eSGfxViewport const & ) const;
        bEResult        SetWorldMatrix( bCMatrix const & );
        void            SkipNextSwapScreens( GEInt );
        bEResult        SwapScreen( HWND__ * const, bCRect const *, bCRect const * );

    protected:
        static void ( GE_STDCALL * ms_pRegisterScreenSwapCall )( void );
        static void ( GE_STDCALL * ms_pRegisterViewportClearCall )( void );
        static void GE_STDCALL sDisableOptimization( void );
        static void GE_STDCALL sEnableOptimization( void );
        static void GE_STDCALL sResetCachedStates( void );
        static void GE_STDCALL sSetScreenSwapCallback( void ( GE_STDCALL* )( void ) );
        static void GE_STDCALL sSetViewportClearCallback( void ( GE_STDCALL* )( void ) );

    protected:
        eCGfxMixerAdmin( void );

    protected:
        bEResult UpdateGammaRamp( void );

};

#endif
