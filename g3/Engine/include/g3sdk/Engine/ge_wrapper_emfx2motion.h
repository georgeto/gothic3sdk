#pragma once

#include <Engine/ge_emotion_fx.h>

#include <SharedBase.h>

class eCArchiveFile;
class eCVisualAnimationLipSync;

class GE_DLLIMPORT eCWrapper_emfx2Motion : public bCObjectBase
{
  public:
    enum eEMotionBlendMode
    {
        // TODO: Enumerator values
    };

    enum eEMotionPlayMode
    {
        // TODO: Enumerator values
    };

    struct eSMotionDesc
    {
        GE_UNIMPL_STRUCT(eSMotionDesc)
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCWrapper_emfx2Motion() override;
    // clang-format on

  public:
    eCWrapper_emfx2Motion(eCWrapper_emfx2Motion const &);
    eCWrapper_emfx2Motion();

  public:
    void CleanUpMotions();
    GEBool CreateLipSyncMotion(eCWrapper_emfx2Motion &, eCVisualAnimationLipSync *);
    bEResult ImportEMFX2Motion(bCString const &);
    GEBool IsMotionUsed() const;
    bEResult LoadMotion(eCArchiveFile &);
    bEResult LoadMotion(bCString const &);
    bEResult Read(bCIStream &, GEU32);

  protected:
    eCWrapper_emfx2Motion const &operator=(eCWrapper_emfx2Motion const &);

  protected:
    void Invalidate();
    void SetMotion(EMotionFX::Motion *);
};
