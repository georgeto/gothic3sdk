#pragma once

#include <Engine.h>

enum gEEffectCommand
{
    // TODO: Enumerator values
};

struct gSEffectCommand
{
    GE_UNIMPL_STRUCT(gSEffectCommand)
};

class GE_DLLIMPORT gCEffectCommand : public bCObjectRefBase
{
    // clang-format off
    public: virtual gEEffectCommand GetCommandType() const;
    public: virtual void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &);
    public: virtual void Execute(eCEntity *, eCEntity *, bCMatrix const *, bTObjMap<GEInt, eCEntityProxy> &, bTObjArray<eCEntityProxy> &, GEBool) const;
    public: virtual gCEffectCommand * Clone() const;
    public: void Destroy() override;
    public: ~gCEffectCommand() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffectCommand, bCObjectRefBase)
    GE_PROPERTY(GEFloat, TimeOffset, m_fTimeOffset)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCEffectCommand, 0x10)

GE_ASSERT_PROPERTY(gCEffectCommand, m_fTimeOffset, 0xc, 4)
