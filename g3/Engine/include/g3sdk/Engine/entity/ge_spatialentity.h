#pragma once

#include <Engine/entity/ge_entity.h>

#include <SharedBase.h>

class eCResourceBase_PS;

class GE_DLLIMPORT eCSpatialEntity : public eCEntity
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCSpatialEntity() override;
    public: void SetContext(eCContextBase *) override;
    protected: eCSpatialEntity * DoClone() const override;
    public: GEBool IsKilled() const override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void UpdateLocalBoundary() override;
    public: void SetCreator(eCTemplateEntity *) override;
    public: eCTemplateEntity const * GetCreator() const override;
    public: GEBool HasCreator() const override;
    public: void OnCacheIn() override;
    public: void OnCacheOut() override;
    public: void Render(GEI16) override;
    public: void RenderAlpha(GEI16) override;
    // clang-format on

  public:
    eCResourceBase_PS *GetMeshResource();
    bCBox const &GetVisualWorldNodeBoundary() const;
    bCOrientedBox const &GetVisualWorldNodeOOBoundary() const;
    GEBool IsHybrid() const;
    GEBool SetResourceFile(bCString const &);
    GEBool UpdateContents();

  protected:
    eCSpatialEntity(eCSpatialEntity const &);
    eCSpatialEntity();

  protected:
    eCSpatialEntity const &operator=(eCSpatialEntity const &);

  protected:
    void Invalidate();
};
