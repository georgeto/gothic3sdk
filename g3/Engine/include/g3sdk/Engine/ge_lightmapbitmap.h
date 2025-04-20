#pragma once

#include <Engine/ge_lightmapbatcher.h>

#include <SharedBase.h>

struct eSLightmapUVGroup;

class GE_DLLIMPORT eCLightmapBitmap
{
    // clang-format off
    public: virtual ~eCLightmapBitmap();
    // clang-format on

  public:
    eCLightmapBitmap(eSLightmapUVGroup const &, GEInt, GEFloat);
    eCLightmapBitmap(eCLightmapBitmap const &);
    eCLightmapBitmap();

  public:
    eCLightmapBitmap &operator=(eCLightmapBitmap const &);

  public:
    GEInt &AccessOffsetX();
    GEInt &AccessOffsetY();
    void Alloc();
    void Create(GEInt, GEInt);
    GEBool CreateYHorizon();
    GEBool CreateYHorizonFromBitmap(GEU32);
    void Destroy();
    void FillBitmapEdges(GEU32);
    void FilterBitmap();
    void Free();
    void FreeEmpty();
    GEU32 *GetBitmap();
    GEU32 const *GetBitmap() const;
    GEU32 GetBitmapSize() const;
    GEInt GetHeight() const;
    GEInt GetOffsetX() const;
    GEInt GetOffsetY() const;
    GEU32 GetSize() const;
    GEInt GetUVGroupIndex() const;
    GEInt GetWidth() const;
    eCLightmapBatcher::eSHorizonRow *GetYHorizon();
    eCLightmapBatcher::eSHorizonRow const *GetYHorizon() const;
    void Read(bCIStream &);
    void Write(bCOStream &);

  protected:
    static GEU16 ms_u16Version;
    static GEU32 ms_u32MagicNumber;
};
