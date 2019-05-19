#ifndef GI_RESOURCECOMPILER_H_INCLUDED
#define GI_RESOURCECOMPILER_H_INCLUDED

class GE_DLLIMPORT iCResourceCompiler :
    public bCObjectRefBase
{
    public:
        enum eEResourceCompilerType
        {
            eEResourceCompilerType_Image              = 0,
            eEResourceCompilerType_Animation          = 1,
            eEResourceCompilerType_MeshesAndMaterials = 2,
            eEResourceCompilerType_Meshes             = 3,
            eEResourceCompilerType_Materials          = 4,
            eEResourceCompilerType_LipSync            = 5
        };

    protected: virtual void     ConvertMeshes( bTObjArray<bCString> const &, GEBool, GEBool );
    public:    virtual GEU16    GetVersion( void ) const;
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );
    public:    virtual bEResult CopyFrom( bCObjectBase const & );
    public:    virtual         ~iCResourceCompiler( void );

    public:
        iCResourceCompiler( void );

    public:
        iCResourceCompiler & operator = ( iCResourceCompiler const & );

    public:
        void     CompileResources( bCString const &, eEResourceCompilerType );
        void     ConvertResources( bCString const &, eEResourceCompilerType );
        void     DeleteResources( bCString const &, eEResourceCompilerType );
        void     GetProprietaryFileExtensionList( eEResourceCompilerType, bTObjArray<bCString> & );
        bCString GetResourceNameString( eEResourceCompilerType );
        GEBool   ParseCommandLine( bCCommandLine const & );

    protected:
        iCResourceCompiler( iCResourceCompiler const & );

    protected:
        void CheckRedundantNativeImages( bCString const & );
        void CollectFiles( bCString const &, bTObjArray<bCString> const &, bTObjArray<bCString> & );
        void CompileLipSync( bTObjArray<bCString> & );
        void ConvertResources( bTObjArray<bCString> const & );
        void DeleteFiles( bTObjArray<bCString> const & );
        void Invalidate( void );

};

#endif
