#pragma once

#include <Game/world/ge_layerbase.h>

#include <Engine.h>

class gCDatabase;

class GE_DLLIMPORT gCTemplateLayer : public gCLayerBase
{
    // clang-format off
    public: virtual eCProcessibleElement::eEResult Create(gCDatabase &, bCString const &);
    public: GEBool IsValid() const override;
    public: bEResult Create() override;
    public: ~gCTemplateLayer() override;
    public: bCString GetFileExt() const override;
    public: bCString GetFileType() const override;
    public: bCString GetDataFileExt() const override;
    public: bCString GetDataFileType() const override;
    public: GEU16 GetFileVersion() const override;
    protected: eCProcessibleElement::eEResult DoLoadData(bCIStream &) override;
    protected: eCProcessibleElement::eEResult DoSaveData(bCOStream &, bCString const &) override;
    protected: void OnModify() override;
    protected: void OnActivate() override;
    protected: eCProcessibleElement::eEResult ReleaseData() override;
    protected: bCPropertyObjectBase * OnCreateContext() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCTemplateLayer, gCLayerBase)

  public:
    static void GE_STDCALL GetFileExt(bCString &);

  public:
    GEBool ExistsFile(eCTemplateEntity const &) const;
    gCDatabase &GetDatabase();
    gCDatabase const &GetDatabase() const;
    void GetFileNames(bTObjArray<bCString> &) const;
    eCTemplateEntity *GetTemplateEntity(bCString const &);
    bCString GetTemplateEntityFileName(eCTemplateEntity const &) const;
    GEBool HasDatabase() const;
    eCTemplateEntity *InsertNewTemplateEntity(eCTemplateEntity const &, GEBool);
    eCTemplateEntity *InsertNewTemplateEntity(eCDynamicEntity const &, GEBool, GEBool);
    eCTemplateEntity *InsertNewTemplateEntity(eCEntity const &, GEBool, GEBool);
    eCTemplateEntity *InsertNewTemplateEntity(eCSpatialEntity const &, GEBool, GEBool);
    eCTemplateEntity *InsertNewTemplateEntity();
    GEBool IsReadOnly(eCTemplateEntity const &) const;
    GEBool IsReadOnly() const;
    GEBool ReadAll();
    GEBool ReadHeaders(bCIStream &);
    GEBool SaveHeaders(bCOStream &);
    void SetDatabase(gCDatabase const *);

  private:
    gCSector &GetSector();
    gCSector const &GetSector() const;
    eCTemplateEntity *GetTemplateEntity(eCTemplateEntity &, bCString const &);
    GEBool HasSector() const;
    void SetSector(bCPropertyObjectBase const *);
    void SetSector(gCSector const *);

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(gCTemplateLayer, 0x48)
