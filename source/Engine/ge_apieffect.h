#ifndef GE_APIEFFECT_H_INCLUDED
#define GE_APIEFFECT_H_INCLUDED

class GE_DLLIMPORT eCAPIEffect
{
    public: virtual bEResult OnResetDevice( void ) = 0;
    public: virtual bEResult OnLostDevice( void ) = 0;
    public: virtual bEResult SetTexture( GELPVoid const, eCAPITexture * ) = 0;
    public: virtual bEResult SetCubeMap( GELPVoid const, eCAPICubeMap * ) = 0;
    public: virtual bEResult SetVolume( GELPVoid const, eCAPIVolume * ) = 0;
    public: virtual bEResult SetParameter( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult GetParameter( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult SetBoolArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult GetBoolArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult SetFloatArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult GetFloatArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult SetIntArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult GetIntArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult SetMatrixArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult GetMatrixArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult SetMatrixTransposeArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult GetMatrixTransposeArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult SetVectorArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult GetVectorArray( GELPVoid const, GELPVoid const, GEUInt ) = 0;
    public: virtual bEResult GetEffectDescription( struct eCGfxShared::eSGfxEffectDesc & ) = 0;
    public: virtual bEResult GetParameterDescription( GEUInt, struct eCGfxShared::eSGfxParameterDesc & ) = 0;
    public: virtual bEResult GetTechniqueDescription( GEUInt, struct eCGfxShared::eSGfxTechniqueDesc & ) = 0;
    public: virtual bEResult IsParameterUsed( GELPVoid const, GELPVoid const, GEBool & ) = 0;
    public: virtual bEResult SetTechnique( GELPVoid const ) = 0;
    public: virtual bEResult SetPassNumber( GEUInt ) = 0;
    public: virtual bEResult BeginTechnique( void ) = 0;
    public: virtual bEResult EndTechnique( void ) = 0;
    public: virtual         ~eCAPIEffect( void );

    public:
        eCAPIEffect( eCAPIEffect const & );

    public:
        eCAPIEffect & operator = ( eCAPIEffect const & );

    public:
        GEU32 AddRef( void );
        GEU32 Release( void );

    protected:
        eCAPIEffect( void );

    private:
        GEU32 m_u32ReferenceCount;
};

#endif
