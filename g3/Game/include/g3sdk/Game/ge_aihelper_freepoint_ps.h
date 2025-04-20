#pragma once

#include <Game/ge_aihelper_label_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT gCAIHelper_FreePoint_PS : public gCAIHelper_Label_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCAIHelper_FreePoint_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    protected: void OnUpdateInternals() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnProcess() override;
    public: void OnPreProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCAIHelper_FreePoint_PS, gCAIHelper_Label_PS)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCAIHelper_FreePoint_PS, 0x14)
