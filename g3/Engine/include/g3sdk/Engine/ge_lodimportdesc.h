#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCLoDImportDesc : public bCObjectRefBase
{
  public:
    struct eSImportMaterial
    {
        GE_UNIMPL_STRUCT(eSImportMaterial)
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCLoDImportDesc() override;
    // clang-format on

  public:
    eCLoDImportDesc(eCLoDImportDesc const &);
    eCLoDImportDesc();

  public:
    bTValArray<GEU32> const &GetDiffuseColorArray() const;
    bTValArray<GEU32> const &GetIndexArray() const;
    eSImportMaterial GetMaterialAtIndex(GEInt) const;
    bCString const &GetMeshBaseName() const;
    bTValArray<bCVector> const &GetNormalArray() const;
    bTValArray<bCVector> const &GetPositionArray() const;
    bTValArray<GEU32> const &GetSpecularColorArray() const;
    bTValArray<GEU32> const &GetSubMaterialIndexArray() const;
    bTValArray<bCVector2> const *GetTexCoordDataArray(GEInt) const;
    GEBool IsMaterialValidAtIndex(GEInt) const;
    GEBool IsTexCoordDataArrayValid(GEInt) const;
    void SetDiffuseColorArray(bTValArray<GEU32> *);
    void SetIndexArray(bTValArray<GEU32> *);
    void SetMaterialArray(bTObjArray<eSImportMaterial> *);
    void SetMeshBaseName(bCString const &);
    void SetNormalArray(bTValArray<bCVector> *);
    void SetPositionArray(bTValArray<bCVector> *);
    void SetSpecularColorArray(bTValArray<GEU32> *);
    void SetSubMaterialIndexArray(bTValArray<GEU32> *);
    void SetTexCoordDataArray(GEInt, bTValArray<bCVector2> *);

  protected:
    eCLoDImportDesc const &operator=(eCLoDImportDesc const &);

  protected:
    void Invalidate();
};
