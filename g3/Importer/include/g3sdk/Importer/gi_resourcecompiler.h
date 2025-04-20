#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT iCResourceCompiler : public bCObjectRefBase
{
  public:
    enum eEResourceCompilerType
    {
        eEResourceCompilerType_Image = 0,
        eEResourceCompilerType_Animation = 1,
        eEResourceCompilerType_MeshesAndMaterials = 2,
        eEResourceCompilerType_Meshes = 3,
        eEResourceCompilerType_Materials = 4,
        eEResourceCompilerType_LipSync = 5
    };

    // clang-format off
    protected: virtual void ConvertMeshes(bTObjArray<bCString> const &, GEBool, GEBool);
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~iCResourceCompiler() override;
    // clang-format on

  public:
    iCResourceCompiler();

  public:
    iCResourceCompiler &operator=(iCResourceCompiler const &);

  public:
    void CompileResources(bCString const &, eEResourceCompilerType);
    void ConvertResources(bCString const &, eEResourceCompilerType);
    void DeleteResources(bCString const &, eEResourceCompilerType);
    void GetProprietaryFileExtensionList(eEResourceCompilerType, bTObjArray<bCString> &);
    bCString GetResourceNameString(eEResourceCompilerType);
    GEBool ParseCommandLine(bCCommandLine const &);

  protected:
    iCResourceCompiler(iCResourceCompiler const &);

  protected:
    void CheckRedundantNativeImages(bCString const &);
    void CollectFiles(bCString const &, bTObjArray<bCString> const &, bTObjArray<bCString> &);
    void CompileLipSync(bTObjArray<bCString> &);
    void ConvertResources(bTObjArray<bCString> const &);
    void DeleteFiles(bTObjArray<bCString> const &);
    void Invalidate();
};
