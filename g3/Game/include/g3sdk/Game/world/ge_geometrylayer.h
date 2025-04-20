#pragma once

#include <Game/GameEnum.h>
#include <Game/world/ge_layerbase.h>

#include <Engine.h>

class GE_DLLIMPORT gCGeometryLayer : public gCLayerBase
{
    // clang-format off
    public: virtual eCProcessibleElement::eEResult Create(gCSector &, gEGeometryType, bCString const &);
    public: bEResult Create() override;
    public: ~gCGeometryLayer() override;
    public: GEBool IsDataAvailable() const override;
    public: bCString GetFileExt() const override;
    public: bCString GetFileType() const override;
    public: bCString GetDataFileExt() const override;
    public: bCString GetDataFileType() const override;
    public: GEU16 GetFileVersion() const override;
    protected: eCProcessibleElement::eEResult DoLoadData(bCIStream &) override;
    protected: eCProcessibleElement::eEResult DoSaveData(bCOStream &, bCString const &) override;
    protected: void OnModify() override;
    public: void UpdateState() override;
    public: eCProcessibleElement::eEResult Activate() override;
    protected: eCProcessibleElement::eEResult ReleaseData() override;
    public: bCString GetLayerCategory() const override;
    protected: bCPropertyObjectBase * OnCreateContext() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCGeometryLayer, gCLayerBase)
    GE_ENUMPROP(gEGeometryType, GeometryType, m_enuGeometryType)
    GE_PROPERTY(bCString, OriginImportName, m_strOriginImportName)

  public:
    static void GE_STDCALL GetFileExt(bCString &);

  public:
    eCSpatialEntity *CreateSpatialEntity(eCSpatialEntity *);
    void UnloadCaches();
};

GE_ASSERT_SIZEOF(gCGeometryLayer, 0x50)

GE_ASSERT_PROPERTY(gCGeometryLayer, m_enuGeometryType, 0x44, 8)
GE_ASSERT_PROPERTY(gCGeometryLayer, m_strOriginImportName, 0x4c, 4)
