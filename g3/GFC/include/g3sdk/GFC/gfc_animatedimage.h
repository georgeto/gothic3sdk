#pragma once

#include <GFC/gfc_wnd.h>

#include <GUI.h>

class GE_DLLIMPORT CFFGFCAnimatedImage : public virtual CFFGFCWnd
{
    // clang-format off
    public: void OnPaint() override;
    public: ~CFFGFCAnimatedImage() override;
    // clang-format on

  public:
    CFFGFCAnimatedImage(CFFGFCAnimatedImage const &);
    CFFGFCAnimatedImage();

  public:
    CFFGFCAnimatedImage &operator=(CFFGFCAnimatedImage const &);

  public:
    void AddImage(bCUnicodeString);
    void AddImageByName(bCUnicodeString);
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    void CreateImageList(bTValArray<bCUnicodeString>);
    GEInt GetAniSpeed();
    IFFGUIBitmap *GetBitmap() const;
    IFFGUIBitmap *GetImage();
    GEInt GetTimer();
    void GotoImage(GEInt);
    GEBool IsAutoplay();
    GEBool IsRepeat();
    void Pause();
    void Play();
    void ResetTimer();
    void SetAniSpeed(GEInt);
    GEBool SetAutoplay(GEBool);
    IFFGUIBitmap *SetBitmap(IFFGUIBitmap *);
    GEBool SetRepeat(GEBool);
    void ShowPicture();
    void UpdateTimer();
};
