#pragma once

#include <Engine/ge_gfxshared.h>
#include <Engine/ge_guisubadmin.h>
#include <Engine/ge_imageadmin.h>
#include <Engine/ge_themeadmin.h>

#include <GUI.h>

class GE_DLLIMPORT eCGUIDatabase : public eCGUISubAdmin
{
    // clang-format off
    public: ~eCGUIDatabase() override;
    // clang-format on

  public:
    eCGUIDatabase(eCGUIDatabase const &);
    explicit eCGUIDatabase(eCGUIAdmin *);

  public:
    eCGUIDatabase &operator=(eCGUIDatabase const &);

  public:
    GEBool Create();
    GEU32 CreateFontA(SFFGUIFont const &);
    GEU32 CreateFontA(eCGfxShared::eSFontDesc const &);
    GEU32 CreateFontA(tagLOGFONTA const &);
    GEU32 CreateFontA(GELPCChar, GEInt, GEInt, GEBool, GEBool, GEBool);
    GEU32 CreateTexture(GEInt, GEInt, GELPCChar);
    GEU32 CreateTexture(GELPCChar);
    GEU32 CreateTexture(bCByteAlphaColor);
    void Destroy();
    GELPVoid GetFontDC(GEU32);
    GEBool GetFontDesc(GEU32, SFFGUIFont &) const;
    GEBool GetFontDesc(GEU32, tagLOGFONTA &) const;
    GEInt GetFontHeight(GEU32);
    eCThemeAdmin::SFont const *GetFontNode(GEU32) const;
    eCImageAdmin::STexture const *GetTextureNode(GEU32) const;
    GEBool VideoEnableLooping(GEU32, GEBool);
    GEInt VideoGetPosition(GEU32);
    GEBool VideoIsLoopingEnabled(GEU32);
    GEBool VideoIsPaused(GEU32);
    GEBool VideoIsRunning(GEU32);
    GEBool VideoMoveBackward(GEU32, GEInt);
    GEBool VideoMoveForward(GEU32, GEInt);
    GEBool VideoPause(GEU32, GEBool);
    GEBool VideoSetPosition(GEU32, GEInt);
    GEBool VideoStart(GEU32);
    GEBool VideoStop(GEU32);

  protected:
    void Invalidate();
};
