#pragma once

#include <SharedBase.h>

class eCGfxImageData;
class eCImageGroupListener;

struct eSImageGroup
{
    GE_UNIMPL_STRUCT(eSImageGroup)
};

class GE_DLLIMPORT eCImageGroup
{
  public:
    struct SImage
    {
        bCString ImageName;      // VirtualPath
        bCRect ImageTextureSize; // CompiledPath
        bCString ImageTexture;   // CompiledPath
    };

  public:
    struct SPack
    {
        GE_UNIMPL_STRUCT(SPack)
    };

    struct STile
    {
        GE_UNIMPL_STRUCT(STile)
    };

  public:
    eCImageGroup(eCImageGroup const &);
    eCImageGroup();
    ~eCImageGroup();

  public:
    eCImageGroup &operator=(eCImageGroup const &);

  public:
    GEBool Compile();
    GEBool CreateImage(bCString const &, GEInt &);
    GEBool Decompile();
    void Destroy();
    GEBool FindImageIndex(bCString const &, GEInt &) const;
    void GetGroupInfo(eSImageGroup &) const;
    GEInt GetImageCount() const;
    GEBool GetImageInfo(GEInt, SImage &) const;
    bCString const &GetName() const;
    GEBool IsModified() const;
    GEBool IsValidImageIndex(GEInt) const;
    GEBool Load(bCString const &);
    GEBool Read(bCIStream &);
    GEBool RemoveImage(GEInt);
    GEBool Save(bCString const &);
    void SetGroupInfo(eSImageGroup const &);
    GEBool SetImageFile(GEInt, bCString const &);
    GEBool SetImageTexture(GEInt, bCString const &, bCRect const &);
    void SetListener(eCImageGroupListener *);
    void SetModified(GEBool);
    GEBool UpdateFromRootPath();
    GEBool Write(bCOStream &);

  protected:
    static void GE_STDCALL CleanImageName(bCString &);
    static GEBool GE_STDCALL ClearTexture(eCGfxImageData *, GEU32);
    static GEInt GE_CCALL CompareTileHeights(GELPCVoid, GELPCVoid);
    static GEInt GE_CCALL CompareTileVolumes(GELPCVoid, GELPCVoid);
    static GEBool GE_STDCALL CompressTexture(eCGfxImageData *);
    static GEBool GE_STDCALL CopyTextureRect(eCGfxImageData *, STile const &);
    static GEBool GE_STDCALL LoadTexture(STile &);
    static GEBool GE_STDCALL SaveTexture(eCGfxImageData *, bCString const &);

  protected:
    GEBool BuildFileMap();
    GEBool ClearPackTextures();
    GEBool CompressPackTextures();
    GEBool CopyTilesToTextures();
    GEBool CreatePackTextures();
    void DestroyImageTextures();
    void DestroyPackTextures();
    void DestroyTiles();
    void FillImagesFromTiles();
    STile *FindTile(SImage const &);
    GEInt ImportPath(bCString const &);
    void Invalidate();
    GEBool LoadTiles();
    void NotifyCompile(GEInt, GEInt, GEInt, GEInt);
    void OnCompileFailed();
    GEBool PackSubGroup(GEInt, GEInt, GEInt, GEInt &, SPack &);
    GEBool PackTiles();
    GEBool SavePackTextures();
    void SortTiles();

  public:
    bTObjArray<SImage> m_arrImageInfo;
    bCString m_strName;
    bCString field_10;
    bCString field_14;
    bCString field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    bCByteAlphaColor Color;
    int field_40;
    int field_44;
    bool m_bModified;
    GE_PADDING(3)
    bTPtrMap<bCString, GEU32> m_TileMap; // TODO: type
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
};
