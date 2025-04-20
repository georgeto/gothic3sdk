#pragma once

#include <GUI.h>

class eCGUIDatabase;
class eCGUIRenderer;
class eCGUIStreamer;

class GE_DLLIMPORT eCGUIAdmin : public IFFGUIRenderer
{
    // clang-format off
    public: virtual ~eCGUIAdmin();
    public: GEU32 CreateFontA(GELPCChar, GEInt, GEInt, GEBool, GEBool, GEBool) override;
    public: GEU32 CreateFontA(tagLOGFONTA const &) override;
    public: GEU32 CreateFontA(SFFGUIFont const &) override;
    public: GEU32 CreateTexture(bCByteAlphaColor) override;
    public: GEU32 CreateTexture(GELPCChar) override;
    public: GELPVoid GetFontDC(GEU32) override;
    public: GEInt GetFontHeight(GEU32) override;
    public: GEBool GetFontDesc(GEU32, SFFGUIFont &) override;
    public: GEInt CalcTextRect(GEU32, GELPCChar, GEInt, bCRect *, GEU32) override;
    public: GEInt CalcTextRect(GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32) override;
    public: GEBool BeginFrame() override;
    public: GEBool EndFrame() override;
    public: GEBool DrawRect(bCRect const *, GEU32) override;
    public: GEBool DrawSprite(GEU32, bCRect const *, bCVector const *, bCVector const *, bCMatrix const *, bCMatrix const *, GEU32) override;
    public: GEBool DrawTextA(GEU32, GELPCChar, GEInt, bCRect *, GEU32, GEU32) override;
    public: GEBool DrawTextA(GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32, GEU32) override;
    public: GEBool SetClipRect(bCRect const *) override;
    public: GEBool LoadBitmapA(bCString const &, SFFGUIBitmap &) override;
    public: GEBool LoadTheme(IFFGUITheme *) override;
    public: GEBool SaveTheme(IFFGUITheme *) override;
    public: GEBool VideoPause(GEU32, GEBool) override;
    public: GEBool VideoStart(GEU32) override;
    public: GEBool VideoStop(GEU32) override;
    public: GEBool VideoSetPosition(GEU32, GEInt) override;
    public: GEInt VideoGetPosition(GEU32) override;
    public: GEBool VideoMoveForward(GEU32, GEInt) override;
    public: GEBool VideoMoveBackward(GEU32, GEInt) override;
    public: GEBool VideoEnableLooping(GEU32, GEBool) override;
    public: GEBool VideoIsLoopingEnabled(GEU32) override;
    public: GEBool VideoIsPaused(GEU32) override;
    public: GEBool VideoIsRunning(GEU32) override;
    // clang-format on

  public:
    eCGUIAdmin(eCGUIAdmin const &);
    eCGUIAdmin();

  public:
    eCGUIAdmin &operator=(eCGUIAdmin const &);

  public:
    GEBool Create();
    void Destroy();
    eCGUIDatabase &GetDatabase();
    eCGUIDatabase const &GetDatabase() const;
    eCGUIRenderer &GetRenderer();
    eCGUIRenderer const &GetRenderer() const;
    eCGUIStreamer &GetStreamer();
    eCGUIStreamer const &GetStreamer() const;

  protected:
    void Invalidate();
};
