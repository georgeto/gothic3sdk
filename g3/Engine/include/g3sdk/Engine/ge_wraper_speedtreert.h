#pragma once

#include <Engine/ge_ambientocclusionpreprocessor.h>

#include <SharedBase.h>

class eCCollisionDesc;
class eCCollisionShape;
struct eSRayIntersectionDesc;

class CSpeedTreeRT
{
  public:
    GE_UNIMPL_STRUCT(CSpeedTreeRT)

    struct SGeometry
    {
        GE_UNIMPL_STRUCT(SGeometry)
    };

    struct STextures
    {
        GE_UNIMPL_STRUCT(STextures)
    };
};

class GE_DLLIMPORT eCWraper_SpeedTreeRT : public bCObjectRefBase
{
    // clang-format off
    public: virtual GEBool IntersectsRay(eSRayIntersectionDesc &, eCCollisionDesc **) const;
    public: virtual GEBool IntersectsVolume(bCVolume &, bTValArray<bCTriangle> *, GEBool) const;
    public: virtual void GetBoundary(bCBox &);
    public: GEU16 GetVersion() const override;
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: GEU32 AddReference() override;
    public: GEU32 ReleaseReference() override;
    public: ~eCWraper_SpeedTreeRT() override;
    // clang-format on

  public:
    eCWraper_SpeedTreeRT(eCWraper_SpeedTreeRT const &);
    eCWraper_SpeedTreeRT();

  public:
    eCWraper_SpeedTreeRT &operator=(eCWraper_SpeedTreeRT const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyTo(eCWraper_SpeedTreeRT &) const;
    eCAmbientOcclusionPreprocessor::eCAOMeshBase *CreateAOMesh();
    eCCollisionShape *CreateCollisionShape(GEInt);
    void GetBillboardGeometry(CSpeedTreeRT::SGeometry &);
    GEInt GetCollisionShapeCount() const;
    CSpeedTreeRT::SGeometry const &GetCurrentLoDGeometry() const;
    bCString const &GetFilePath() const;
    void GetTextures(CSpeedTreeRT::STextures &);
    void SetLoD(GEFloat);
    void UpdateLoD(bCVector const &);

  protected:
    void Invalidate();
};
