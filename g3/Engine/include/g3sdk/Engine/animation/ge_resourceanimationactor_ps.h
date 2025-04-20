#pragma once

#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCWrapper_emfx2Actor;

class GE_DLLIMPORT eCResourceAnimationActor_PS : public eCResourceBase_PS
{
  protected:
    struct eSLookAtConstraintData
    {
        bCString m_strName;
        GEFloat m_fInterpolationSpeed;
        bCVector m_MinConstraints;
        bCVector m_MaxConstraints;
    };
    GE_ASSERT_SIZEOF(eSLookAtConstraintData, 0x20)

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceAnimationActor_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    protected: void CalculateSize() override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnUpdateInternals() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceAnimationActor_PS, eCResourceBase_PS)

  public:
    static void GE_STDCALL GetNativeFileExt(bCString &);
    static void GE_STDCALL GetProprietaryFileExt(bCString &);
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    eCWrapper_emfx2Actor const &GetEMFX2Actor() const;
    bTObjArray<eSLookAtConstraintData> const &GetLookAtConstraints() const;

  protected:
    void DeleteResources();
    void ImportLookAtConstraints();
    void Invalidate();

  public:
    eCWrapper_emfx2Actor *m_EMFX2Actor;
    bCDateTime m_NativeFileTime;
    GEUInt m_NativeFileSize;
    bTObjArray<eSLookAtConstraintData> m_arrLookAtConstraints;
    bCBox m_Boundary;
};

GE_ASSERT_SIZEOF(eCResourceAnimationActor_PS, 0x60)
