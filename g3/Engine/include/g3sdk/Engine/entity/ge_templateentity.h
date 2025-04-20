#pragma once

#include <Engine/entity/ge_entity.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTemplateEntity : public eCEntity
{
    // clang-format off
    protected: virtual bEResult ReadHeader(bCIStream &, GEU16 &, GEBool);
    protected: virtual bEResult ReadContent(GEU16, bCIStream &);
    protected: virtual bEResult ReadAll(bCIStream &);
    public: virtual bEResult ReadAll();
    protected: virtual bEResult ReadSkipData(bCPOStream &);
    public: GEU16 GetVersion() const override;
    protected: bEResult Write(bCOStream &) override;
    protected: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCTemplateEntity() override;
    protected: void OnReadContent() override;
    public: eCTemplateEntity * DoClone() const override;
    public: void SetName(bCString const &) override;
    public: GEBool IsHelperParent() const override;
    public: GEBool IsResource() const override;
    public: void UpdateParentDependencies() override;
    public: void UpdateChildDependencies() override;
    public: void Kill() override;
    public: eCTemplateEntity const * GetCreator() const override;
    public: GEBool HasCreator() const override;
    public: GEU32 Modified() override;
    public: void OnCacheIn() override;
    public: void OnCacheOut() override;
    // clang-format on

  public:
    static GEU32 GE_STDCALL GetMagicCode1();
    static GEU32 GE_STDCALL GetMagicCode2();

  public:
    void CacheOut(GEBool, GEBool);
    void DeleteContent();
    void DeleteInstances();
    void DeleteTemplate();
    eCEntity *GetInstanceAt(GEInt);
    eCEntity const *GetInstanceAt(GEInt) const;
    GEInt GetInstanceCount() const;
    eCTemplateEntity const *GetRefTemplate() const;
    bCPropertyID const &GetRefTemplateID() const;
    GEBool IsContentLoaded() const;
    GEBool IsDeleted() const;
    GEBool IsReferencedTemplateEntity() const;
    bEResult PatchEntity(eCEntity *, GEBool, GEBool) const;
    GEBool PatchInstances();
    bEResult Save(bCString const &);
    void SetAsHelperParent();
    void SetRefTemplate(eCTemplateEntity const &);

  protected:
    eCTemplateEntity(eCTemplateEntity const &);
    eCTemplateEntity();

  protected:
    eCTemplateEntity const &operator=(eCTemplateEntity const &);

  protected:
    void AddInstanceEntity(eCEntity *);
    void Invalidate();
    void RemoveInstanceEntity(eCEntity *);
    bEResult WriteHeader(bCOStream &);
};
