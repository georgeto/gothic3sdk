#ifndef GE_GFXSHARED_H_INCLUDED
#define GE_GFXSHARED_H_INCLUDED

typedef enum _D3DFORMAT D3DFORMAT;
typedef enum _D3DPOOL D3DPOOL;
typedef enum _D3DPRIMITIVETYPE D3DPRIMITIVETYPE;

typedef LPCSTR D3DXHANDLE;
typedef enum _D3DXREGISTER_SET D3DXREGISTER_SET;
typedef enum _D3DXPARAMETER_CLASS D3DXPARAMETER_CLASS;
typedef enum _D3DXPARAMETER_TYPE D3DXPARAMETER_TYPE;

class GE_DLLIMPORT eCGfxShared
{
    public:
        struct eSGfxContextDesc;

        struct eSGfxLayersDesc
        {
            UINT Width;
            UINT Height;
            UINT Depth; // if(Depth > 1) -> D3DRTYPE_VOLUMETEXTURE
            GEBool IsCubeTexture; // D3DRTYPE_CUBETEXTURE
            UINT Levels;
            DWORD Usage; // D3DUSAGE
            D3DFORMAT Format;
            D3DPOOL Pool;
        };
        GE_ASSERT_SIZEOF( eSGfxLayersDesc, 0x20 )

        struct eSFontDesc
        {
            GEInt  Height;
            GEUInt  Width;
            GEUInt  Weight;
            GEUInt  MipLevels;
            GEBool Italic;
            GE_PADDING( 3 )
            GEU32 CharSet;
            GEU32           OutPrecision;
            GEU32           Quality;
            GEU32           PitchAndFamily;
            bCUnicodeString FaceName;
        };
        GE_ASSERT_SIZEOF( eSFontDesc, 0x28 )

        struct eSGfxEffectDesc
        {

        };

        struct eSGfxParameterDesc
        {

        };

        struct eSGfxTechniqueDesc
        {

        };

        enum eEGfxHLSLShaderProfile
        {
            eEGfxHLSLShaderProfile_PS_1_1 = 0,
            eEGfxHLSLShaderProfile_PS_1_2 = 1,
            eEGfxHLSLShaderProfile_PS_1_3 = 2,
            eEGfxHLSLShaderProfile_PS_1_4 = 3,
            eEGfxHLSLShaderProfile_PS_2_0 = 4,
            eEGfxHLSLShaderProfile_PS_2_a = 5,
            eEGfxHLSLShaderProfile_PS_2_b = 6,
            eEGfxHLSLShaderProfile_PS_3_0 = 7,
            eEGfxHLSLShaderProfile_VS_1_1 = 8,
            eEGfxHLSLShaderProfile_VS_2_0 = 9,
            eEGfxHLSLShaderProfile_VS_2_a = 10,
            eEGfxHLSLShaderProfile_VS_3_0 = 11
        };

        struct eSGfxMacro
        {
            GELPCChar Name;
            GELPCChar Definition;
        };

        struct eSGfxHLSLShaderSrc
        {
            bCString FilePath;
            // An optional NULL terminated array of eEGfxHLSLShaderMacro structures. This value may be NULL.
            eSGfxMacro const * pDefines; // D3DXMACRO
            bCString FunctionName;
            eEGfxHLSLShaderProfile ShaderProfile;
            GEU32 CompileFlags; // D3DXSHADER
        };


        struct eSGfxHLSLConstantDesc
        {
            LPCSTR Name;
            D3DXHANDLE Handle;
            D3DXREGISTER_SET RegisterSet;
            D3DXPARAMETER_CLASS Class;
            D3DXPARAMETER_TYPE Type;
            UINT Rows;
            UINT Columns;
            UINT Elements;
            UINT StructMembers;
            UINT Bytes;
            UINT RegisterIndex;
            UINT RegisterCount;
        };

        struct eSGfxEffectSource
        {
            bCString SrcData;
            GEU32 SrcDataLen;
            GEU32 CompileFlags;
            eSGfxMacro const * pDefines;
        };

        struct eSGfxEffectFileSource
        {
            bCString FilePath;
            GEU32 CompileFlags;
            eSGfxMacro const * pDefines;
        };

        enum eEGfxHLSLShaderType
        {
            eEGfxHLSLShaderShader_VS     = 0,
            eEGfxHLSLShaderShader_PS     = 1,
            eEGfxHLSLShaderShader_PS_1_1 = 0x101,
            eEGfxHLSLShaderShader_PS_1_2 = 0x201,
            eEGfxHLSLShaderShader_PS_1_3 = 0x301,
            eEGfxHLSLShaderShader_PS_1_4 = 0x401,
            eEGfxHLSLShaderShader_PS_2_0 = 0x501,
            eEGfxHLSLShaderShader_PS_2_a = 0x601,
            eEGfxHLSLShaderShader_PS_2_b = 0x701,
            eEGfxHLSLShaderShader_PS_3_0 = 0x801,
            eEGfxHLSLShaderShader_VS_1_1 = 0x100,
            eEGfxHLSLShaderShader_VS_2_0 = 0x200,
            eEGfxHLSLShaderShader_VS_2_a = 0x300,
            eEGfxHLSLShaderShader_VS_3_0 = 0x400
        };

        enum eECubeMapFace // D3DCUBEMAP_FACES
        {
            eECubeMapFace_POSITIVE_X = 0,
            eECubeMapFace_NEGATIVE_X = 1,
            eECubeMapFace_POSITIVE_Y = 2,
            eECubeMapFace_NEGATIVE_Y = 3,
            eECubeMapFace_POSITIVE_Z = 4,
            eECubeMapFace_NEGATIVE_Z = 5,
        };
        enum eECopyFilter // D3DX_FILTER
        {
            eECopyFilter_NONE             = (1 << 0),
            eECopyFilter_POINT            = (2 << 0),
            eECopyFilter_LINEAR           = (3 << 0),
            eECopyFilter_TRIANGLE         = (4 << 0),
            eECopyFilter_BOX              = (5 << 0),
            eECopyFilter_MIRROR_U         = (1 << 16),
            eECopyFilter_MIRROR_V         = (2 << 16),
            eECopyFilter_MIRROR_W         = (4 << 16),
            eECopyFilter_MIRROR           = (7 << 16),
            eECopyFilter_DITHER           = (1 << 19),
            eECopyFilter_DITHER_DIFFUSION = (2 << 19),
            eECopyFilter_SRGB_IN          = (1 << 21),
            eECopyFilter_SRGB_OUT         = (2 << 21),
            eECopyFilter_SRGB             = (3 << 21)
        };

        struct eSGfxIndexBufDesc
        {
            DWORD Length;
            DWORD Usage;
            D3DFORMAT Format;
            D3DPOOL Pool;
        };
        GE_ASSERT_SIZEOF(eSGfxIndexBufDesc, 0x10)

        struct eSGfxVertexBufDesc
        {
            UINT Size;
            DWORD Usage;
            DWORD FVF;
            D3DPOOL Pool;
            UINT VertexSize; // Used if FVF == 0
        };
        GE_ASSERT_SIZEOF(eSGfxVertexBufDesc, 0x14)

        struct eSGfxDrawCallDesc
        {
            GEBool bIndexed;
            D3DPRIMITIVETYPE Type;
            DWORD PrimitiveCount;
            DWORD StartVertex; // Only valid if bIndexed = false
            DWORD MinVertexIndex;
            DWORD NumVertices;
            DWORD StartIndex;
            DWORD BaseVertexIndex;
        };
        GE_ASSERT_SIZEOF(eSGfxDrawCallDesc, 0x20)

        // Not used by eCDX9 implementation
        struct eSSpriteDesc
        {
        };

        struct eSGfxViewport
        {
              GEU32 X;
              GEU32 Y;
              GEU32 Width;
              GEU32 Height;
              GEFloat MinZ;
              GEFloat MaxZ;
        };
        enum eEViewportClear
        {
            eEViewportClear_TARGET  = 1,
            eEViewportClear_ZBUFFER = 2,
            eEViewportClear_STENCIL = 4
        };

        struct eSGfxGammaRamp // D3DGAMMARAMP
        {
            GEU16 Red  [256];
            GEU16 Green[256];
            GEU16 Blue [256];
        };

        enum eERenderMode // D3DFILLMODE
        {
            eEMasterRenderMode_NoMaster  = 0,

            eERenderMode_POINT               = 1,
            eERenderMode_WIREFRAME           = 2,
            eERenderMode_SOLID               = 3,
        };
        typedef eERenderMode eEMasterRenderMode;

        enum eEShadeMode // D3DSHADEMODE
        {
            eEMasterShadeMode_NoMaster  = 0,

            eEShadeMode_FLAT         = 1,
            eEShadeMode_GOURAUD      = 2,
            eEShadeMode_PHONG        = 3,
        };
        typedef eEShadeMode eEMasterShadeMode;

        enum eECullingMode // D3DCULL
        {
            eEMasterCullingMode_NoMaster  = 0,

            eECullingMode_NONE         = 1,
            eECullingMode_CW           = 2,
            eECullingMode_CCW          = 3,
        };
        typedef eECullingMode eEMasterCullingMode;

        enum eECmpFunc // D3DCMPFUNC
        {
            eEMasterCmpFunc_NoMaster = 0,

            eECmpFunc_NEVER        = 1,
            eECmpFunc_LESS         = 2,
            eECmpFunc_EQUAL        = 3,
            eECmpFunc_LESSEQUAL    = 4,
            eECmpFunc_GREATER      = 5,
            eECmpFunc_NOTEQUAL     = 6,
            eECmpFunc_GREATEREQUAL = 7,
            eECmpFunc_ALWAYS       = 8,
        };
        typedef eECmpFunc eEMasterCmpFunc;

        enum eEWrite
        {
            eEMasterWrite_NoMaster   = 0,

            eEWrite_Disabled   = 1,
            eEWrite_Enabled  = 2,
        };
        typedef eEWrite eEMasterWrite;

        enum eEStencil
        {
            eEMasterStencil_NoMaster   = 0,

            eEStencil_Disabled    = 1,
            eEStencil_Enabled  = 2,
        };
        typedef eEStencil eEMasterStencil;

        enum eEStencilOp // D3DSTENCILOP
        {
            eEStencilOp_KEEP         = 1,
            eEStencilOp_ZERO         = 2,
            eEStencilOp_REPLACE      = 3,
            eEStencilOp_INCRSAT      = 4,
            eEStencilOp_DECRSAT      = 5,
            eEStencilOp_INVERT       = 6,
            eEStencilOp_INCR         = 7,
            eEStencilOp_DECR         = 8,
        };

        struct eSGfxStencilData
        {
            DWORD Fail;
            DWORD ZFail;
            DWORD Pass;
            eECmpFunc Func;
            GEU32 Ref;
            GEU32 Mask;
            GEU32 WriteMask;
        };

        enum eEPrimitiveType // D3DPRIMITIVETYPE
        {
            eEPrimitiveType_POINTLIST     = 1,
            eEPrimitiveType_LINELIST      = 2,
            eEPrimitiveType_LINESTRIP     = 3,
            eEPrimitiveType_TRIANGLELIST  = 4,
            eEPrimitiveType_TRIANGLESTRIP = 5,
            eEPrimitiveType_TRIANGLEFAN   = 6,
        };

        enum eEBlending // D3DBLEND
        {
            eEMasterBlending_NoMaster  = 0,

            eEBlending_ZERO            = 1,
            eEBlending_ONE             = 2,
            eEBlending_SRCCOLOR        = 3,
            eEBlending_INVSRCCOLOR     = 4,
            eEBlending_SRCALPHA        = 5,
            eEBlending_INVSRCALPHA     = 6,
            eEBlending_DESTALPHA       = 7,
            eEBlending_INVDESTALPHA    = 8,
            eEBlending_DESTCOLOR       = 9,
            eEBlending_INVDESTCOLOR    = 10,
            eEBlending_SRCALPHASAT     = 11,
            eEBlending_BOTHSRCALPHA    = 12,
            eEBlending_BOTHINVSRCALPHA = 13,
            eEBlending_BLENDFACTOR     = 14,
            eEBlending_INVBLENDFACTOR  = 15,
            eEBlending_SRCCOLOR2       = 16,
            eEBlending_INVSRCCOLOR2    = 17,
        };
        typedef eEBlending eEMasterBlending;

        enum eEAlphaTest
        {
            eEMasterAlphaTest_NoMaster   = 0,

            eEAlphaTest_Disabled       = 1,
            eEAlphaTest_Enabled        = 2,
        };
        typedef eEAlphaTest eEMasterAlphaTest;

        struct eSGfxAlphaTestData
        {
            GEU32 AlphaRef;
            eECmpFunc AlphaFunc;
        };

        enum eEMaterialColorSrc // D3DMATERIALCOLORSOURCE
        {
            eEMaterialColorSrc_MATERIAL     = 0,
            eEMaterialColorSrc_COLOR1       = 1,
            eEMaterialColorSrc_COLOR2       = 2,
        };

        struct eSGfxDclElement // D3DVERTEXELEMENT9
        {
            WORD Stream;
            WORD Offset;
            BYTE Type;
            BYTE Method;
            BYTE Usage;
            BYTE UsageIndex;
        };

        enum eETexAddress // D3DTEXTUREADDRESS
        {
            eETexAddress_WRAP            = 1,
            eETexAddress_MIRROR          = 2,
            eETexAddress_CLAMP           = 3,
            eETexAddress_BORDER          = 4,
            eETexAddress_MIRRORONCE      = 5,
        };

        enum eETexFilter // D3DTEXTUREFILTER
        {
            eETexFilter_NONE             = 0,
            eETexFilter_POINT            = 1,
            eETexFilter_LINEAR           = 2,
            eETexFilter_ANISOTROPIC      = 3,
            eETexFilter_PYRAMIDALQUAD    = 6,
            eETexFilter_GAUSSIANQUAD     = 7,
            eETexFilter_CONVOLUTIONMONO  = 8,
        };

        enum eETexCoordCalc // D3DTSS_TCI
        {
            eETexCoordCalc_PASSTHRU                    = 0x00000000,
            eETexCoordCalc_CAMERASPACENORMAL           = 0x00010000,
            eETexCoordCalc_CAMERASPACEPOSITION         = 0x00020000,
            eETexCoordCalc_CAMERASPACEREFLECTIONVECTOR = 0x00030000,
            eETexCoordCalc_SPHEREMAP                   = 0x00040000,
        };

        enum eESamplerState // D3DSAMPLERSTATETYPE
        {
            eESamplerState_ADDRESSU       = 1,
            eESamplerState_ADDRESSV       = 2,
            eESamplerState_ADDRESSW       = 3,
            eESamplerState_BORDERCOLOR    = 4,
            eESamplerState_MAGFILTER      = 5,
            eESamplerState_MINFILTER      = 6,
            eESamplerState_MIPFILTER      = 7,
            eESamplerState_MIPMAPLODBIAS  = 8,
            eESamplerState_MAXMIPLEVEL    = 9,
            eESamplerState_MAXANISOTROPY  = 10,
            eESamplerState_SRGBTEXTURE    = 11,
            eESamplerState_ELEMENTINDEX   = 12,
            eESamplerState_DMAPOFFSET     = 13,
        };

        enum eETexArgument // D3DTA
        {
            eETexArgument_SELECTMASK     = 0x0000000f,
            eETexArgument_DIFFUSE        = 0x00000000,
            eETexArgument_CURRENT        = 0x00000001,
            eETexArgument_TEXTURE        = 0x00000002,
            eETexArgument_TFACTOR        = 0x00000003,
            eETexArgument_SPECULAR       = 0x00000004,
            eETexArgument_TEMP           = 0x00000005,
            eETexArgument_CONSTANT       = 0x00000006,
            eETexArgument_COMPLEMENT     = 0x00000010,
            eETexArgument_ALPHAREPLICATE = 0x00000020,
        };

        enum eETexOperation // D3DTEXTUREOP
        {
            eETexOperation_DISABLE                    = 1,
            eETexOperation_SELECTARG1                 = 2,
            eETexOperation_SELECTARG2                 = 3,
            eETexOperation_MODULATE                   = 4,
            eETexOperation_MODULATE2X                 = 5,
            eETexOperation_MODULATE4X                 = 6,
            eETexOperation_ADD                        = 7,
            eETexOperation_ADDSIGNED                  = 8,
            eETexOperation_ADDSIGNED2X                = 9,
            eETexOperation_SUBTRACT                   = 10,
            eETexOperation_ADDSMOOTH                  = 11,
            eETexOperation_BLENDDIFFUSEALPHA          = 12,
            eETexOperation_BLENDTEXTUREALPHA          = 13,
            eETexOperation_BLENDFACTORALPHA           = 14,
            eETexOperation_BLENDTEXTUREALPHAPM        = 15,
            eETexOperation_BLENDCURRENTALPHA          = 16,
            eETexOperation_PREMODULATE                = 17,
            eETexOperation_MODULATEALPHA_ADDCOLOR     = 18,
            eETexOperation_MODULATECOLOR_ADDALPHA     = 19,
            eETexOperation_MODULATEINVALPHA_ADDCOLOR  = 20,
            eETexOperation_MODULATEINVCOLOR_ADDALPHA  = 21,
            eETexOperation_BUMPENVMAP                 = 22,
            eETexOperation_BUMPENVMAPLUMINANCE        = 23,
            eETexOperation_DOTPRODUCT3                = 24,
            eETexOperation_MULTIPLYADD                = 25,
            eETexOperation_LERP                       = 26,
        };

        enum eEDepthFormat; // D3DFORMAT

        struct eSGfxLightData
        {

        };

        struct eSGfxFogData
        {

        };

        enum eEMasterFogging
        {
            eEMasterFogging_NoMaster = 0,
            eEMasterFogging_Disable = 1,
        };

        struct eSGfxPlaneData
        {

        };

        struct eSGfxAssistantMethods
        {

        };

        struct eSGfxAttributeWeigths
        {

        };

        struct eSGfxBoxData
        {

        };

        struct eSGfxCylinderData
        {

        };

        struct eSGfxPolygonData
        {

        };

        struct eSGfxSphereData
        {

        };

        struct eSGfxTextData
        {

        };

        struct eSGfxTorusData
        {

        };

        enum eESpriteRenderOpt
        {

        };

        enum eENormalMapGen
        {

        };

        enum eEChannel
        {

        };

        enum eEAPIType
        {
            eEAPIType_Invalid = 0,
            eEAPIType_Dummy   = 1,
            eEAPIType_DX9     = 3,
        };
        struct eSGfxModeDesc
        {
            GEU32 Width;
            GEU32 Height;
            UINT  RefreshRate;
            // D3DFORMAT
            GEU32 Format;
        };
        struct eSGfxAdapterDesc
        {
            GEChar Driver[512];
            GEChar Description[512];
            GEU32  DriverVersion_LowPart;
            GEU32  DriverVersion_HighPart;
            GEU32  VendorId;
            GEU32  DeviceId;
            GEU32  SubSysId;
            GEU32  Revision;
            GEU8   Caps[296];
        };

        struct eSTLTexVertex;
        struct eSTLTexDiffuseVertex;
        struct eSTLColVertex;
        struct eSTexVertex;
};

#endif
