#pragma once

#include <Engine/ge_texcoordsrcbase.h>

#include <SharedBase.h>

class eCTexCoordSrcProxy;

class GE_DLLIMPORT eCTexCoordSrcScroller : public eCTexCoordSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCTexCoordSrcScroller() override;
    protected: bEResult PostInitializeProperties() override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: void SetTime(GEFloat) override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool GetVSImplementation(bCString &, GEInt, GEBool) override;
    public: GEBool GetPSImplementation(bCString &, GEInt, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCTexCoordSrcScroller, eCTexCoordSrcBase)
    GE_PROPERTY(bCVector2, ScrollOffset, m_vecOffset)
    GE_PROPERTY(bCVector2, Direction, m_vecDirection)
    GE_PROPERTY(GEFloat, Rate, m_fRate)

  public:
    bCVector2 &AccessOffset();
    bCVector2 const &GetOffset() const;
    eCTexCoordSrcProxy &GetTexCoordSrc();
    void SetOffset(bCVector2 const &);

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(72)
};

GE_ASSERT_SIZEOF(eCTexCoordSrcScroller, 0xa0)

GE_ASSERT_PROPERTY(eCTexCoordSrcScroller, m_vecOffset, 0x44, 8)
GE_ASSERT_PROPERTY(eCTexCoordSrcScroller, m_vecDirection, 0x4c, 8)
GE_ASSERT_PROPERTY(eCTexCoordSrcScroller, m_fRate, 0x54, 4)
