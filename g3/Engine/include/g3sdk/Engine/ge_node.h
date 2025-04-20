#pragma once

#include <SharedBase.h>

class eCContextBase;

class GE_DLLIMPORT eCNode : public bCObjectRefBase
{
    // clang-format off
    public: virtual eCNode * GetParent();
    public: virtual eCNode const * GetParent() const;
    public: virtual eCNode const * GetRoot() const;
    public: virtual eCNode const * GetChildAt(GEInt) const;
    public: virtual eCNode * GetChildAt(GEInt);
    protected: virtual void SetContext(eCContextBase *);
    public: virtual void OnReadContent();
    public: virtual GEInt AttachChild(eCNode *);
    public: virtual GEBool DetachChildByIndex(GEInt);
    public: virtual void RemoveAllChildren();
    protected: virtual eCNode * DoClone() const;
    public: virtual void ChildrenAvailable(GEBool);
    public: GEU16 GetVersion() const override;
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCNode() override;
    // clang-format on

  public:
    eCNode(eCNode const &);
    eCNode();

  public:
    eCNode const &operator=(eCNode const &);

  public:
    eCNode *Clone() const;
    eCNode *CloneSubgraph() const;
    void CollectChildrenRecursive(bTPtrArray<eCNode *> &) const;
    GEBool ContainsParent(eCNode const *) const;
    GEBool DetachChild(eCNode *);
    GEInt GetChildIndex(eCNode const *) const;
    GEInt GetChildrenCount() const;
    eCContextBase *GetCurrentContext();
    eCContextBase const *GetCurrentContext() const;
    bCPropertyID &GetID();
    bCPropertyID const &GetID() const;
    GEInt GetLevel() const;
    GEBool HasParent() const;
    GEBool IsInContext() const;
    GEBool IsRoot() const;
    GEBool IsValidChildIndex(GEInt) const;
    void RemoveFromParent();

  protected:
    void Invalidate();
    void MoveToNode(eCNode *);
    void SetID(bCPropertyID);

  public:
    eCNode *m_pParent;
    bTSmallArray<eCNode *> m_arrChilds;
    bCPropertyID m_ID;
    eCContextBase *m_pCurrentContext;
};

GE_ASSERT_SIZEOF(eCNode, 0x30)
