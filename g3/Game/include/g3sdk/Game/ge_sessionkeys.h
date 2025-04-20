#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCSession;

class GE_DLLIMPORT gCSessionKeys : public bCObjectRefBase
{
    // clang-format off
    public: virtual void CopyFrom(gCSessionKeys const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCSessionKeys() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCSessionKeys, bCObjectRefBase)

  public:
    explicit gCSessionKeys(gCSession &);

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void AssignKey(gESessionKey, bCUnicodeString &, bTPtrArray<eCPhysicalKey *> &);
    void CreateDefaultKeys();
    void CreateINIKeys();
    eCPhysicalKey *GetAssignedKey(gESessionKey, GEInt);
    eCPhysicalKey *GetPressedKey();
    void Invalidate();

  protected:
    void AssignSingleKey(gESessionKey, bCString, eSSetupEngine::SPhysicalKeys &);

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(gCSessionKeys, 0x10)
