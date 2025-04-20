#pragma once

#include <Engine/entity/proxy/ge_entityproxy.h>

#include <SharedBase.h>

enum eEEffectorType
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCEffector : public bCObjectRefBase
{
    // clang-format off
    public: virtual eEEffectorType GetType() const;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCEffector() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCEffector, bCObjectRefBase)
    GE_PROPERTY(eCEntityProxy, Entity1, m_Entity1)
    GE_PROPERTY(eCEntityProxy, Entity2, m_Entity2)
    GE_PROPERTY(bCVector, Pos1, m_vecPos1)
    GE_PROPERTY(bCVector, Pos2, m_vecPos2)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCEffector, 0x5c)

GE_ASSERT_PROPERTY(eCEffector, m_Entity1, 0xc, 28)
GE_ASSERT_PROPERTY(eCEffector, m_Entity2, 0x28, 28)
GE_ASSERT_PROPERTY(eCEffector, m_vecPos1, 0x44, 12)
GE_ASSERT_PROPERTY(eCEffector, m_vecPos2, 0x50, 12)
