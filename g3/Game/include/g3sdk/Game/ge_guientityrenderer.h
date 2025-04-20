#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCGUIEntityRenderer
{
  public:
    enum EAttitude
    {
        // TODO: Enumerator values
    };

    enum EMode
    {
        // TODO: Enumerator values
    };

    struct SFocusName
    {
        eCEntity *pEntity;
        GEFloat fAlpha;
    };

    // clang-format off
    public: virtual ~gCGUIEntityRenderer();
    // clang-format on

  public:
    gCGUIEntityRenderer(gCGUIEntityRenderer const &);
    explicit gCGUIEntityRenderer(eCGUIAdmin *);

  public:
    gCGUIEntityRenderer &operator=(gCGUIEntityRenderer const &);

  public:
    GEBool AddFocusName(eCEntity const *, GEFloat);
    GEBool BeginFrame(GEBool);
    GEBool Create();
    void Destroy();
    GEBool DrawFocusNames();
    GEBool EndFrame(GEBool);
    EMode GetMode() const;
    void SetMode(EMode);

  protected:
    GEBool CalcTextRect(eCEntity const *, bCUnicodeString const &, bCRect &, GEFloat &);
    GEBool DrawFocusName(eCEntity const *, GEFloat);
    EAttitude GetAttitude(eCEntity const *) const;
    void Invalidate();
    GEBool IsDead(eCEntity const *) const;
    GEBool IsFocus(eCEntity const *) const;

  public:
    eCGUIRenderer m_Renderer;
    bTObjArray<SFocusName> m_arrFocusNames;
    GEU32 m_FontIndex;
    EMode m_RenderMode;
};

GE_ASSERT_SIZEOF(gCGUIEntityRenderer, 0x78)
