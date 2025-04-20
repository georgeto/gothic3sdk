#pragma once

#include <SharedBase.h>

class eCGfxImageData;
class eCImageGroupListener;
class eCVideoPlayer;
struct eSImageGroup;

struct eSImage
{
    GE_UNIMPL_STRUCT(eSImage)
};

class GE_DLLIMPORT eCImageAdmin
{
  public:
    struct STexture
    {
        GE_UNIMPL_STRUCT(STexture)
    };

  public:
    static eCImageAdmin &GE_STDCALL GetInstance();

  public:
    eCImageAdmin(eCImageAdmin const &);
    ~eCImageAdmin();

  public:
    eCImageAdmin &operator=(eCImageAdmin const &);

  public:
    GEBool CompileAllGroups();
    GEBool CompileGroup(GEInt);
    GEBool CreateGroup(eSImageGroup const &, GEInt &);
    GEBool CreateImage(bCString const &, GEInt, GEInt &);
    GEBool CreateTempTexture(bCString const &, GEInt &);
    GEBool CreateTexture(bCPoint const &, bCString const &, GEInt &);
    GEBool CreateTexture(bCString const &, GEInt &);
    void Destroy();
    GEBool FindGroupIndex(bCString const &, GEInt &) const;
    GEBool FindImageIndex(bCString const &, GEInt &, GEInt &) const;
    GEBool FindTextureIndex(bCString const &, GEInt &) const;
    GEInt GetGroupCount() const;
    GEBool GetGroupInfo(GEInt, eSImageGroup &) const;
    GEInt GetImageCount(GEInt) const;
    GEBool GetImageInfo(GEInt, GEInt, eSImage &) const;
    GEInt GetTempTextureCount() const;
    STexture *GetTexture(GEInt);
    STexture const *GetTexture(GEInt) const;
    GEInt GetTextureCount() const;
    GEBool ImportImage(GEInt, GEInt, bCString const &, bCRect const &, GEInt &);
    GEBool ImportTempTexture(bCString const &, eCGfxImageData *, GEInt &);
    GEBool IsValidGroupIndex(GEInt) const;
    GEBool IsValidImageIndex(GEInt, GEInt) const;
    GEBool IsValidTextureIndex(GEInt) const;
    GEBool Load(bCString const &);
    GEBool LoadGroup(GEInt, bCString const &);
    GEBool LoadGroupList(bCString const &, bTValArray<GEInt> &, GEBool, GEBool);
    GEBool RebuildGroupImages(GEInt);
    GEBool RemoveGroup(GEInt);
    GEBool RemoveImage(GEInt, GEInt);
    GEBool RemoveTexture(GEInt);
    GEBool Save(bCString const &);
    GEBool SaveGroup(GEInt, bCString const &);
    GEBool SaveGroupList(bTValArray<GEInt> const &, bCString const &);
    GEBool SetGroupInfo(GEInt, eSImageGroup const &);
    GEBool SetGroupListener(GEInt, eCImageGroupListener *);
    GEBool SetImageFile(GEInt, GEInt, bCString const &);
    GEBool VideoEnableLooping(GEInt, GEBool);
    GEInt VideoGetPosition(GEInt);
    GEBool VideoIsLoopingEnabled(GEInt);
    GEBool VideoIsPaused(GEInt);
    GEBool VideoIsRunning(GEInt);
    GEBool VideoMoveBackward(GEInt, GEInt);
    GEBool VideoMoveForward(GEInt, GEInt);
    GEBool VideoPause(GEInt, GEBool);
    GEBool VideoSetPosition(GEInt, GEInt);
    GEBool VideoStart(GEInt);
    GEBool VideoStop(GEInt);

  protected:
    static GEBool GE_STDCALL ImportTexture(STexture &, eCGfxImageData *);
    static GEBool GE_STDCALL LoadTexture(STexture &);

  protected:
    eCImageAdmin();

  protected:
    void DestroyTextures();
    eCVideoPlayer *GetVideoPlayer(GEInt);
    void Invalidate();
    GEBool LoadTextures();
    GEBool Read(bCIStream &);
    GEBool Write(bCOStream &);
};
