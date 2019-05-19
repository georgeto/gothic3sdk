#ifndef GI_TEXTUREBAKER_H_INCLUDED
#define GI_TEXTUREBAKER_H_INCLUDED

class eCGfxVertexDecl;
class eCResourceMeshComplex_PS;
class eCMeshElement;

class GE_DLLIMPORT iCTextureBaker
{
    protected:
        struct iSBakeTexture;

    public: virtual ~iCTextureBaker( void );

    protected:
        static GEInt             ms_iPixelBatchCount;
        static GEInt             ms_iSampleCount;
        static eCGfxVertexDecl * ms_pVertexDecl;

    public:
        iCTextureBaker( iCTextureBaker const & );
        iCTextureBaker( void );

    public:
        iCTextureBaker & operator = ( iCTextureBaker const & );

    public:
        GEBool Process( void );

    protected:
        static GEDouble ( *ms_arrSamples )[2];

    protected:
        void     CollectBakeTextures( eCEntity * );
        void     CollectBakeTextures( eCResourceMeshComplex_PS *, bCMatrix const & );
        GEBool   CollectBakeTextures( eCMeshElement *, bCMatrix const & );
        bEResult Create( void );
        void     Destroy( void );
        void     FillTextureEdges( void );
        void     FindBestHighPolyFace( eCEntity * );
        GEBool   FindBestHighPolyFace( bCVector const &, bCVector const & );
        void     Invalidate( void );
        GEBool   ProcessBakeTexture( iSBakeTexture const & );
        GEBool   RenderBakeTexture( iSBakeTexture const & );

};

#endif
