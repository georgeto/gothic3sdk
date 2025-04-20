#pragma once

#include <Engine/ge_guisubadmin.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCGUIRenderer : public eCGUISubAdmin
{
    // clang-format off
    public: virtual GEBool DrawRect(bCRect const *, GEU32);
    public: virtual GEBool DrawSprite(GEU32, bCRect const *, bCVector const *, bCVector const *, bCMatrix const *, GEU32);
    public: virtual GEInt CalcTextRect(GEU32, GELPCChar, GEInt, bCRect *, GEU32);
    public: virtual GEInt CalcTextRect(GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32);
    public: virtual GEBool DrawTextA(GEU32, GELPCChar, GEInt, bCRect *, GEU32, GEU32);
    public: virtual GEBool DrawTextA(GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32, GEU32);
    public: virtual GEBool BeginFrame(GEBool);
    public: virtual GEBool EndFrame(GEBool);
    public: virtual GEBool SetClipRect(bCRect const *);
    public: virtual GEBool SetTransform(bCMatrix const *);
    public: virtual GEBool GetDrawScale(bCVector &) const;
    public: virtual GEBool SetDrawScale(bCVector const &);
    public: ~eCGUIRenderer() override;
    // clang-format on

  public:
    eCGUIRenderer(eCGUIRenderer const &);
    explicit eCGUIRenderer(eCGUIAdmin *);

  public:
    eCGUIRenderer &operator=(eCGUIRenderer const &);

  public:
    GEBool Create(GEU32);
    void Destroy();

  protected:
    void ApplyStates();
    void Invalidate();
    void PopStates();
    void PushStates();

  private:
    GE_UNIMPL_MEMBERS(0x5c)
};

GE_ASSERT_SIZEOF(eCGUIRenderer, 0x60)
