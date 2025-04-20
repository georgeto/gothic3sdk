#pragma once

#include <Engine/entity/ge_templateentity.h>
#include <Engine/ge_contextbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCEntityTemplateContext : public eCContextBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    protected: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCEntityTemplateContext() override;
    public: GEBool IsDataAvailable() const override;
    public: eCTemplateEntity * CreateSpecificEntity() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCEntityTemplateContext, eCContextBase)

  public:
    bCString GetFileExt() const;
    GEBool ReadHeaders(bCIStream &);
    GEBool SaveAllTemplateEntities();
    GEBool SaveHeaders(bCOStream &);
    GEBool SaveTemplateEntity(bCString const &, eCTemplateEntity *);

  protected:
    void Invalidate();
    bEResult ReadOldV2(bCIStream &);
};

GE_ASSERT_SIZEOF(eCEntityTemplateContext, 0x58)
