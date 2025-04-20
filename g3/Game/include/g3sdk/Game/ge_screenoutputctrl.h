#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCInfoScriptLine_PS;
class gCQuest_PS;

class GE_DLLIMPORT gCScreenOutputCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCScreenOutputCtrl() override;
    public: void OnSize(GEU32, GEInt, GEInt) override;
    public: void Process() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCScreenOutputCtrl, eCWnd)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(gCScreenOutputCtrl const &);
    void CopyTo(gCScreenOutputCtrl &) const;
    void OutDebug(bCPoint &, bCString &, bCByteAlphaColor const &, GEFloat);
    void OutDebugEnd(bCString &);
    void PrintGameMessage(bCUnicodeString const &, gEGameMessageType);
    void PrintScreen(bCUnicodeString const &, bCByteAlphaColor const &, GEFloat);
    void PrintScreenEnd();
    void PrintScreen_InfoScript_Say(gCInfoScriptLine_PS &, GEFloat);
    void PrintScreen_Quest_Failed(gCQuest_PS const &, GEFloat);
    void PrintScreen_Quest_Success(gCQuest_PS const &, GEFloat);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(44)
};

GE_ASSERT_SIZEOF(gCScreenOutputCtrl, 0x11c)
