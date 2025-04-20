#pragma once

#include <Game/ge_gsmapmarker.h>

#include <Engine.h>

struct gSMapGenerate;

class GE_DLLIMPORT gCMap_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCMap_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMap_PS, eCEntityPropertySet)
    GE_PROPERTY(eCLocString, Header, m_strHeader)
    GE_PROPERTY(bCString, Bitmap, m_strBitmap)
    GE_PROPERTY(bCVector, WorldTopLeft, m_vecWorldTopLeft)
    GE_PROPERTY(bCVector, WorldBottomRight, m_vecWorldBottomRight)

  public:
    GEBool CalcUV(bCVector const &, GEFloat &, GEFloat &) const;
    GEBool Contains(bCVector const &) const;
    GEBool Generate(bTObjArray<eCEntityProxy> const &, gSMapGenerate const &);
    bTObjArray<gSMapMarker> &GetMarkers();
    bTObjArray<gSMapMarker> const &GetMarkers() const;

  protected:
    GEBool GenerateMarkers(bTObjArray<eCEntityProxy> const &, gSMapGenerate const &);
    GEBool GenerateTexture(gSMapGenerate const &);
    void Invalidate();

  private:
    eCGfxImageData *CreateTexture(gSMapGenerate const &);
    GEBool FillTextureWithMarkers(eCGfxImageData *, gSMapGenerate const &);
    GEBool SaveTexture(eCGfxImageData *, gSMapGenerate const &);

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(gCMap_PS, 0x40)

GE_ASSERT_PROPERTY(gCMap_PS, m_strHeader, 0x14, 4)
GE_ASSERT_PROPERTY(gCMap_PS, m_strBitmap, 0x18, 4)
GE_ASSERT_PROPERTY(gCMap_PS, m_vecWorldTopLeft, 0x1c, 12)
GE_ASSERT_PROPERTY(gCMap_PS, m_vecWorldBottomRight, 0x28, 12)
