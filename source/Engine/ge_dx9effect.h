#ifndef GE_DX9EFFECT_H_INCLUDED
#define GE_DX9EFFECT_H_INCLUDED

struct ID3DXEffectPool;

class GE_DLLIMPORT eCDX9Effect :
    public eCAPIEffect
{
    public: virtual bEResult OnResetDevice( void );
    public: virtual bEResult OnLostDevice( void );
    public: virtual bEResult SetTexture( GELPVoid const, eCAPITexture * );
    public: virtual bEResult SetCubeMap( GELPVoid const, eCAPICubeMap * );
    public: virtual bEResult SetVolume( GELPVoid const, eCAPIVolume * );
    public: virtual bEResult SetParameter( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult GetParameter( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult SetBoolArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult GetBoolArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult SetFloatArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult GetFloatArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult SetIntArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult GetIntArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult SetMatrixArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult GetMatrixArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult SetMatrixTransposeArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult GetMatrixTransposeArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult SetVectorArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult GetVectorArray( GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult GetEffectDescription( eCGfxShared::eSGfxEffectDesc & );
    public: virtual bEResult GetParameterDescription( GEUInt, eCGfxShared::eSGfxParameterDesc & );
    public: virtual bEResult GetTechniqueDescription( GEUInt, eCGfxShared::eSGfxTechniqueDesc & );
    public: virtual bEResult IsParameterUsed( GELPVoid const, GELPVoid const, GEBool & );
    public: virtual bEResult SetTechnique( GELPVoid const );
    public: virtual bEResult SetPassNumber( GEUInt );
    public: virtual bEResult BeginTechnique( void );
    public: virtual bEResult EndTechnique( void );
    public: virtual         ~eCDX9Effect( void );

    protected:
        static GEBool ms_bOptimize;

    public:
        eCDX9Effect( eCDX9Effect const & );

    public:
        eCDX9Effect & operator = ( eCDX9Effect const & );

    protected:
        static void ( GE_STDCALL * ms_pRegEffectSwitch )( void );
        static void GE_STDCALL sDisableOptimization( void );
        static void GE_STDCALL sEnableOptimization( void );
        static void GE_STDCALL sSetEffectActCallback( void ( GE_STDCALL* )( void ) );

    protected:
        eCDX9Effect( GELPVoid, GEUInt, IDirect3DDevice9 *, ID3DXEffectPool *, GEBool & );

};

#endif
