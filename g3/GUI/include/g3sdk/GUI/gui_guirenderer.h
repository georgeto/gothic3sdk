#pragma once

#include <SharedBase.h>

class IFFGUITheme;

struct SFFGUIFont
{
    bCString FaceName;
    GEU32 Height;
    GEU32 Width;
    GEU32 Weight;
    GEByte CharSet;
    GEByte OutPrecision;
    GEByte Quality;
    GEByte PitchAndFamily;
    GEByte Italic;
    GE_PADDING(3)
};

struct SFFGUIBitmap
{
    GE_UNIMPL_STRUCT(SFFGUIBitmap)
};

class IFFGUIRenderer
{
    // clang-format off
    public: virtual GEU32 CreateFontA(GELPCChar, GEInt, GEInt, GEBool, GEBool, GEBool);
    public: virtual GEU32 CreateFontA(tagLOGFONTA const &);
    public: virtual GEU32 CreateFontA(SFFGUIFont const &);
    public: virtual GEU32 CreateTexture(bCByteAlphaColor);
    public: virtual GEU32 CreateTexture(GELPCChar);
    public: virtual GELPVoid GetFontDC(GEU32);
    public: virtual GEInt GetFontHeight(GEU32);
    public: virtual GEBool GetFontDesc(GEU32, SFFGUIFont &);
    public: virtual GEInt CalcTextRect(GEU32, GELPCChar, GEInt, bCRect *, GEU32);
    public: virtual GEInt CalcTextRect(GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32);
    public: virtual GEBool BeginFrame();
    public: virtual GEBool EndFrame();
    public: virtual GEBool DrawRect(bCRect const *, GEU32);
    public: virtual GEBool DrawSprite(GEU32, bCRect const *, bCVector const *, bCVector const *, bCMatrix const *, bCMatrix const *, GEU32);
    public: virtual GEBool DrawTextA(GEU32, GELPCChar, GEInt, bCRect *, GEU32, GEU32);
    public: virtual GEBool DrawTextA(GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32, GEU32);
    public: virtual GEBool SetClipRect(bCRect const *);
    public: virtual GEBool LoadBitmapA(bCString const &, SFFGUIBitmap &);
    public: virtual GEBool LoadTheme(IFFGUITheme *);
    public: virtual GEBool SaveTheme(IFFGUITheme *);
    public: virtual GEBool VideoPause(GEU32, GEBool);
    public: virtual GEBool VideoStart(GEU32);
    public: virtual GEBool VideoStop(GEU32);
    public: virtual GEBool VideoSetPosition(GEU32, GEInt);
    public: virtual GEInt VideoGetPosition(GEU32);
    public: virtual GEBool VideoMoveForward(GEU32, GEInt);
    public: virtual GEBool VideoMoveBackward(GEU32, GEInt);
    public: virtual GEBool VideoEnableLooping(GEU32, GEBool);
    public: virtual GEBool VideoIsLoopingEnabled(GEU32);
    public: virtual GEBool VideoIsPaused(GEU32);
    public: virtual GEBool VideoIsRunning(GEU32);
    // clang-format on
};
