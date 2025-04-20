#pragma once

#include <Game/ge_effectcommand.h>

#include <Engine.h>

struct gSEffectCommand_PlaySound
{
    GE_UNIMPL_STRUCT(gSEffectCommand_PlaySound)
};

class GE_DLLIMPORT gCEffectCommandPlaySound : public gCEffectCommand
{
  public:
    struct SItem
    {
        GE_UNIMPL_STRUCT(SItem)
    };

    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~gCEffectCommandPlaySound() override;
    public: gEEffectCommand GetCommandType() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void Execute(eCEntity *, eCEntity *, bCMatrix const *, bTObjMap<GEInt, eCEntityProxy> &, bTObjArray<eCEntityProxy> &, GEBool) const override;
    public: gCEffectCommand * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffectCommandPlaySound, gCEffectCommand)
    GE_PROPERTY(GEFloat, Volume, m_fVolume)
    GE_PROPERTY(GEFloat, MinDistance, m_fMinDistance)
    GE_PROPERTY(GEFloat, MaxDistance, m_fMaxDistance)

  public:
    void GetDescriptor(gSEffectCommand_PlaySound &) const;
    bTObjArray<SItem> &GetItems();
    bTObjArray<SItem> const &GetItems() const;
    GEInt SelectSample() const;
    void SetDescriptor(gSEffectCommand_PlaySound const &);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(gCEffectCommandPlaySound, 0x28)

GE_ASSERT_PROPERTY(gCEffectCommandPlaySound, m_fVolume, 0x10, 4)
GE_ASSERT_PROPERTY(gCEffectCommandPlaySound, m_fMinDistance, 0x14, 4)
GE_ASSERT_PROPERTY(gCEffectCommandPlaySound, m_fMaxDistance, 0x18, 4)
