#pragma once

#include <Engine/ge_refptrarray.h>
#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCResourceImageList_PS : public eCResourceBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceImageList_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    public: GEBool IsDataAvailable() const override;
    protected: void CalculateSize() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceImageList_PS, eCResourceBase_PS)
    GE_PROPERTY(bTRefPtrArray<eCResourceDataEntity *>, Images, m_arrImages)

  public:
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    GEBool AddImageFile(bCString const &);
    GEInt ContainsResourceFile(bCString const &) const;
    GEBool RemoveImageFile(bCPropertyID const &);
    GEBool RemoveImageFile(bCString const &);

  protected:
    void DeleteResources();
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCResourceImageList_PS, 0x38)

GE_ASSERT_PROPERTY(eCResourceImageList_PS, m_arrImages, 0x2c, 12)
