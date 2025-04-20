#pragma once

#include <Engine/entity/ge_entitypropertyset.h>

#include <SharedBase.h>

class eCCollisionShape;

class GE_DLLIMPORT eCCollisionShapeBase_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual bEResult SetShape(eCCollisionShape *);
    public: virtual bEResult SetShape(bCString const &);
    public: virtual bEResult AddShape(eCCollisionShape *);
    public: virtual bEResult AddShape(bCString const &);
    public: virtual GEU32 GetNumShapes() const;
    public: virtual eCCollisionShape * GetShapeAtIndex(GEU32) const;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCCollisionShapeBase_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCCollisionShapeBase_PS, eCEntityPropertySet)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCCollisionShapeBase_PS, 0x14)
