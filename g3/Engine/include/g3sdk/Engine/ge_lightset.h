#pragma once

#include <Engine/ge_shadermaterialadmin.h>

#include <SharedBase.h>

class eCDynamicLight_PS;
class eCIlluminated_PS;

struct eSShaderMaterialLightList
{
    GE_UNIMPL_STRUCT(eSShaderMaterialLightList)
};

class GE_DLLIMPORT eCLightSet : public bCObjectRefBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: GEU32 AddReference() override;
    protected: GEU32 ReleaseReference() override;
    public: ~eCLightSet() override;
    // clang-format on

  public:
    static GEU32 GE_STDCALL BuildCheckSum(bTValArray<eCDynamicLight_PS *> const &);

  public:
    eCLightSet &operator=(eCLightSet const &);

  public:
    GEU32 GetCheckSum() const;
    bTValArray<eCDynamicLight_PS *> const &GetEffectedDynamicLights() const;
    bTValArray<eCIlluminated_PS *> const &GetEffectedObjects() const;
    eSShaderMaterialLightList const &GetShaderMaterialLightList() const;
    bTSphericalHarmonics2<bCVector4> const &GetSphericalHarmonics() const;
    GEBool IsEffectedByDynamicLight(eCDynamicLight_PS *) const;
    void SetEffectedDynamicLights(bTValArray<eCDynamicLight_PS *> const &);
    GEBool UpdateIllumination();

  protected:
    eCLightSet(eCLightSet const &);
    eCLightSet();

  protected:
    void AddEffectedDynamicLight(eCDynamicLight_PS *);
    GEBool AddEffectedObject(eCIlluminated_PS *);
    void ClearEffectedDynamicLights();
    void Invalidate();
    GEBool RemoveAllEffectedObjects();
    void RemoveEffectedDynamicLight(eCDynamicLight_PS *);
    GEBool RemoveEffectedObject(eCIlluminated_PS *);
};
