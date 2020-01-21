#ifndef GE_DX9HLSLSHADER_H_INCLUDED
#define GE_DX9HLSLSHADER_H_INCLUDED

struct ID3DXBuffer;

class GE_DLLIMPORT eCDX9HLSLShader :
    public eCAPIHLSLShader
{
    public: virtual bEResult Compile( eCGfxShared::eSGfxHLSLShaderSrc const & );
    public: virtual GELPVoid CreateConstantTable( void );
    public: virtual void     DestroyConstantTable( GELPVoid );
    public: virtual bEResult GetFunctionData( GELPVoid *, GEU32 & ) const;
    public: virtual bEResult GetShaderType( eCGfxShared::eEGfxHLSLShaderType & ) const;
    public: virtual bEResult GetShaderVersion( GELPVoid, GEU32 & ) const;
    public: virtual bEResult GetConstantCount( GELPVoid, GEUInt & );
    public: virtual bEResult GetConstantDescription( GELPVoid, GELPVoid const, GEUInt, eCGfxShared::eSGfxHLSLConstantDesc &, GEBool ) const;
    public: virtual bEResult SetConstant( GELPVoid, GELPVoid const, GELPVoid const, GEUInt );
    public: virtual bEResult SetConstantMatrix( GELPVoid, GELPVoid const, bCMatrix const * );
    public: virtual bEResult SetConstantTransposedMatrix( GELPVoid, GELPVoid const, bCMatrix const * );
    public: virtual bEResult SetConstantBoolArray( GELPVoid, GELPVoid const, GEInt const *, GEUInt );
    public: virtual bEResult SetConstantFloatArray( GELPVoid, GELPVoid const, GEFloat const *, GEUInt );
    public: virtual bEResult SetConstantIntArray( GELPVoid, GELPVoid const, GEInt const *, GEUInt );
    public: virtual bEResult SetConstantMatrixArray( GELPVoid, GELPVoid const, bCMatrix const *, GEUInt );
    public: virtual bEResult SetConstantMatrixPtrArray( GELPVoid, GELPVoid const, bCMatrix const * *, GEUInt );
    public: virtual bEResult SetConstantMatrixTransposeArray( GELPVoid, GELPVoid const, bCMatrix const *, GEUInt );
    public: virtual bEResult SetConstantVectorArray( GELPVoid, GELPVoid const, bCVector4 const *, GEUInt );
    public: virtual bEResult GetSamplerIndex( GELPVoid, GELPVoid const, GEUInt & );
    public: virtual bEResult Execute( void );
    public: virtual bEResult DestroyShader( void );
    public: virtual bEResult Read( bCIStream & );
    public: virtual bEResult Write( bCOStream & );
    public: virtual         ~eCDX9HLSLShader( void );

    protected:
        static GEBool s_bFogEnabled;

    public:
        eCDX9HLSLShader( eCDX9HLSLShader const & );

    public:
        eCDX9HLSLShader & operator = ( eCDX9HLSLShader const & );

    protected:
        eCDX9HLSLShader( IDirect3DDevice9 * );

    protected:
        bEResult Create( ID3DXBuffer *, eCGfxShared::eEGfxHLSLShaderType );
        void     Destroy( void );
        GEBool   IsValid( void ) const;

};

#endif
