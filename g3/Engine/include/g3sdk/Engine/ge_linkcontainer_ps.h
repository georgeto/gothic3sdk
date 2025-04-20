#pragma once

#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_refptrarray.h>

#include <SharedBase.h>

class eCEffector;
class eCJoint;

class GE_DLLIMPORT eCLinkContainer_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCLinkContainer_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsProcessable() const override;
    public: GEBool IsPhysicRelevant() const override;
    public: GEBool IsEditorRelevant() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnProcess() override;
    protected: void OnPostRead() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCLinkContainer_PS, eCEntityPropertySet)

  public:
    void AddJoint(eCJoint &);
    bTRefPtrArray<eCEffector *> &GetEffectors();
    bTRefPtrArray<eCEffector *> const &GetEffectors() const;
    bTRefPtrArray<eCJoint *> &GetJoints();
    bTRefPtrArray<eCJoint *> const &GetJoints() const;
    GEU32 GetNumEffectors() const;
    GEU32 GetNumJoints() const;
    void RemoveJoint(eCJoint &);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(28)
};

GE_ASSERT_SIZEOF(eCLinkContainer_PS, 0x30)
