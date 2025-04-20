#pragma once

#include <Engine/entity/proxy/ge_entityproxy.h>
#include <Engine/ge_jointdesc.h>

#include <SharedBase.h>

class NxJoint;
class NxJointDesc;
class eCEntity;

enum eEJointState
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCJoint : public bCObjectRefBase
{
    // clang-format off
    public: virtual eEJointType GetType() const;
    public: virtual eEJointState GetState() const;
    public: virtual void GetEntities(eCEntity *&, eCEntity *&);
    public: virtual void SetWorldAnchor(bCVector &);
    public: virtual bCVector GetWorldAnchor();
    public: virtual void SetWorldAxis(bCVector &);
    public: virtual bCVector GetWorldAxis();
    public: virtual void SetBreakable(GEFloat, GEFloat);
    public: virtual void GetBreakable(GEFloat &, GEFloat &);
    public: virtual void SetLimitPoint(bCVector const &, GEBool);
    public: virtual GEBool GetLimitPoint(bCVector &);
    public: virtual GEBool AddLimitPlane(bCVector const &, bCVector const &);
    public: virtual void PurgeLimitPlanes();
    public: virtual void ResetLimitPlaneIterator();
    public: virtual GEBool HasMoreLimitPlanes();
    public: virtual GEBool GetNextLimitPlane(bCVector &, GEFloat &);
    public: virtual void SetDescriptor(eCJointDesc &, GEBool);
    protected: virtual NxJointDesc & GetDescriptorInternal();
    protected: virtual NxJoint * GetJointInternal();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCJoint() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCJoint, bCObjectRefBase)
    GE_PROPERTY(eCEntityProxy, Entity1, m_Entity1)
    GE_PROPERTY(eCEntityProxy, Entity2, m_Entity2)

  public:
    void SetIsCachedIn(GEBool);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(eCJoint, 0x48)

GE_ASSERT_PROPERTY(eCJoint, m_Entity1, 0xc, 28)
GE_ASSERT_PROPERTY(eCJoint, m_Entity2, 0x28, 28)
