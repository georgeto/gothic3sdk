#pragma once

#include <Engine/ge_visualmeshbase_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCVisualMeshDynamic_PS : public eCVisualMeshBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCVisualMeshDynamic_PS() override;
    protected: bEResult PostInitializeProperties() override;
    protected: void OnPostRead() override;
    public: GEBool ConvertFrom(eCVisualMeshBase_PS const &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCVisualMeshDynamic_PS, eCVisualMeshBase_PS)
    GE_PROPERTY(bCMeshResourceString, ResourceFilePath, m_strResourceFilePath) // Read only

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(eCVisualMeshDynamic_PS, 0x58)

GE_ASSERT_PROPERTY(eCVisualMeshDynamic_PS, m_strResourceFilePath, 0x50, 4)
