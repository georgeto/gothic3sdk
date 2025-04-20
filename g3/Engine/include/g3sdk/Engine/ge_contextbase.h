#pragma once

#include <SharedBase.h>

class eCNode;

class GE_DLLIMPORT eCContextBase : public bCObjectRefBase
{
    // clang-format off
    public: virtual GEBool IsDataAvailable() const;
    public: virtual void SetGraph(eCNode *);
    public: virtual GEBool IsProcessing() const;
    public: virtual GEFloat QueryProgress() const;
    public: virtual eCNode * CreateSpecificEntity();
    protected: virtual void UpdateBoundingBox();
    public: virtual void OnUpdateInternals();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCContextBase() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCContextBase, bCObjectRefBase)
    GE_PROPERTY(bCGuid, ID, m_guidID)
    GE_PROPERTY(bCBox, ContextBox, m_boxContext)

  public:
    void DisableUpdateInternalsOnWrite();
    void Enable(GEBool);
    bCString const &GetFilePath() const;
    eCNode *GetGraph();
    eCNode const *GetGraph() const;
    GEU32 GetNodeCount() const;
    GEFloat GetObjectCullFactor() const;
    GEFloat GetVisualLoDFactor() const;
    GEBool HasGraph() const;
    GEBool IsEnabled() const;
    GEBool IsLocked() const;
    GEU16 Lock();
    void SetFetchingMode(GEBool);
    void SetFilePath(bCString const &);
    void SetModified();
    void SetObjectCullFactor(GEFloat);
    void SetVisualLoDFactor(GEFloat);
    GEU16 Unlock();

  protected:
    void CollectNodes(eCNode *, bTValArray<eCNode *> &) const;
    void Invalidate();
    bEResult ReadDependency(bCIStream &, bTValArray<eCNode *> &);
    bEResult WriteDependency(bCOStream &, bTValArray<eCNode *> const &);

  private:
    GE_UNIMPL_MEMBERS(32)
};

GE_ASSERT_SIZEOF(eCContextBase, 0x58)

GE_ASSERT_PROPERTY(eCContextBase, m_guidID, 0xc, 20)
GE_ASSERT_PROPERTY(eCContextBase, m_boxContext, 0x20, 24)
