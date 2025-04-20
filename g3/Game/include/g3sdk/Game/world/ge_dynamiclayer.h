#pragma once

#include <Game/GameEnum.h>
#include <Game/world/ge_layerbase.h>

#include <Engine.h>

class GE_DLLIMPORT gCDynamicLayer : public gCLayerBase
{
    // clang-format off
    public: virtual eCProcessibleElement::eEResult Create(gCSector &, bCString const &, gEEntityType);
    protected: GEU16 GetVersion() const override;
    public: bEResult Create() override;
    public: ~gCDynamicLayer() override;
    public: bCString GetFileExt() const override;
    public: bCString GetFileType() const override;
    public: bCString GetDataFileExt() const override;
    public: bCString GetDataFileType() const override;
    public: GEU16 GetFileVersion() const override;
    protected: eCProcessibleElement::eEResult DoLoadData(bCIStream &) override;
    protected: eCProcessibleElement::eEResult DoSaveData(bCOStream &, bCString const &) override;
    protected: void OnModify() override;
    protected: void OnActivate() override;
    protected: void UpdateState() override;
    protected: eCProcessibleElement::eEResult ReleaseData() override;
    protected: bCPropertyObjectBase * OnCreateContext() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCDynamicLayer, gCLayerBase)
    GE_ENUMPROP(gEEntityType, EntityType, m_enuEntityType)

  public:
    static void GE_STDCALL GetDataFileExt(bCString &);
    static void GE_STDCALL GetFileExt(bCString &);

  public:
    eCDynamicEntity *CreateDynamicEntity(bTObjArray<bCString> const &);
    eCDynamicEntity *CreateDynamicEntity(bCString const &);
    eCDynamicEntity *CreateDynamicEntity();
    eCEntityDynamicContext const &GetEntityContext() const;
    GEBool IsSysLayer() const;
    GEBool IsSysTempLayer() const;

  protected:
    static bCString const ms_strDynamicEntityLayer;
    static bCString const ms_strDynamicEntityTempLayer;

  protected:
    static GEU32 GE_STDCALL GetMagicCode1();
    static GEU32 GE_STDCALL GetMagicCode2();
    static eCEntity *GE_STDCALL g_funcCreateCustomEntity();

  protected:
    eCEntityDynamicContext &GetEntityContext();
};

GE_ASSERT_SIZEOF(gCDynamicLayer, 0x4c)

GE_ASSERT_PROPERTY(gCDynamicLayer, m_enuEntityType, 0x44, 8)
