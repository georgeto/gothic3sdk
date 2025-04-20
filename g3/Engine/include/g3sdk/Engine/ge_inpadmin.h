#pragma once

#include <Engine/ge_enginecomponentbase.h>
#include <Engine/io/ge_inpshared.h>

#include <SharedBase.h>

class eCInpContextAdmin;

class GE_DLLIMPORT eCInpAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCInpAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult Shutdown() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCInpAdmin, eCEngineComponentBase)

  public:
    bEResult Create(eCInpShared::eEAPIType);
    bEResult EnumContext(GEU32, eCInpShared::eSInpContextDesc &) const;
    eCInpShared::eEAPIType GetAPIType() const;
    eCInpContextAdmin &GetAccessToContext();
    bEResult GetContextCount(GEU32 &) const;
    void Invalidate();

  protected:
    void InitializeAdmin(eCInpShared::eEAPIType);

  private:
    GE_UNIMPL_MEMBERS(32)
};

GE_ASSERT_SIZEOF(eCInpAdmin, 0x34)
