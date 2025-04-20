#pragma once

#include <Engine/entity/proxy/ge_templateentityproxy.h>
#include <Engine/ge_emotion_fx.h>
#include <Engine/ge_wrapper_emfx2motion.h>

#include <SharedBase.h>

class eCArchiveFile;
class eCCollisionDesc;
class eCGfxIndexData;
class eCGfxVertexData;
class eCResourceShaderMaterial_PS;
struct eSRayIntersectionDesc;

namespace MCore
{
template <typename T>
struct Array
{
    GEInt mLength;
    GEInt mMaxLength;
    T *mData;
};
} // namespace MCore

namespace EMotionFX
{
class Node
{
  public:
    GE_UNIMPL_MEMBERS(0x178)
    GEInt mBoneRelatedID;
    GE_UNIMPL_MEMBERS(0xC)
    GEInt mID;
    GE_UNIMPL_MEMBERS(0x4)
};
GE_ASSERT_SIZEOF(Node, 0x190)

class Actor : public Node
{
  public:
    GE_UNIMPL_MEMBERS(0x24)
    MCore::Array<Node> mNodes;
    GE_UNIMPL_MEMBERS(0x64)
};
GE_ASSERT_SIZEOF(Actor, 0x224)

class eCNovodexPhysicsController;
}; // namespace EMotionFX

class GE_DLLIMPORT eCWrapper_emfx2Actor : public bCObjectRefBase
{
  public:
    struct eSHardBuffer
    {
        GE_UNIMPL_STRUCT(eSHardBuffer)
    };

    struct eSSoftPrimitive
    {
        GE_UNIMPL_STRUCT(eSSoftPrimitive)
    };

    enum eEMotionType
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: GEBool IsValid() const override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCWrapper_emfx2Actor() override;
    // clang-format on

  public:
    static void GE_STDCALL CleanUpHierachy(EMotionFX::Actor *);
    static void GE_STDCALL CleanUpHierachy(EMotionFX::Actor *, EMotionFX::Node *, bTValArray<GEInt> &);

  public:
    eCWrapper_emfx2Actor(eCWrapper_emfx2Actor const &);
    explicit eCWrapper_emfx2Actor(EMotionFX::Actor const *);
    eCWrapper_emfx2Actor();

  public:
    GEU16 AddLoDLevel(eCWrapper_emfx2Actor *);
    void CalculateAmbientOcclusion(bTObjArray<bTValArray<GEU32>> &, GEFloat);
    void CalculateDynamicMeshTotals(GEU16, GEInt &, GEInt &);
    void CalculateStaticMeshTotals(GEU16, GEInt &, GEInt &);
    eCWrapper_emfx2Actor *CreateInstance() const;
    GEBool FillHardBuffersAndPrimitves(GEU16, bTObjArray<eSHardBuffer> &, eCGfxVertexData *&, eCGfxIndexData *&);
    void FillSoftBuffers(GEU16, eCGfxVertexData *&, eCGfxVertexData *&, eCGfxIndexData *&, eCGfxIndexData *&);
    void FillSoftPrimitiveArray(GEU16, bTValArray<eSSoftPrimitive> &, bTValArray<eSSoftPrimitive> &);
    bCString const &GetActorName() const;
    bCString GetActorNodeName() const;
    eCWrapper_emfx2Motion::eEMotionBlendMode GetBlendMode(eEMotionType) const;
    bCBox GetBoundary();
    void GetBoundary(bCBox &);
    GEU16 GetCurrentLoDLevel() const;
    void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &);
    GEFloat GetExtroBlending(eEMotionType) const;
    EMotionFX::Actor *GetInstance();
    EMotionFX::Actor const *GetInstance() const;
    GEFloat GetIntroBlending(eEMotionType) const;
    GEU16 GetLoDCount() const;
    eCResourceShaderMaterial_PS *GetMaterialByID(GEU32) const;
    GEDouble GetMaxTime(eEMotionType) const;
    bCString GetName(EMotionFX::Node *);
    EMotionFX::Node *GetNodeByName(bCString const &);
    GEFloat GetPlaySpeed(eEMotionType) const;
    GEDouble GetPlayTime(eEMotionType) const;
    eCWrapper_emfx2Motion::eEMotionPlayMode GetPrimary1PlayMode() const;
    GEFloat GetTargetWeight(eEMotionType) const;
    bCMatrix GetWorldMatrix(EMotionFX::Node *);
    GEBool HasMesh() const;
    GEBool HasMotionInstance(eEMotionType) const;
    bEResult ImportEMFX2Actor(bCString const &);
    GEBool IntersectsRay(eSRayIntersectionDesc &, eCCollisionDesc **, GEU16) const;
    GEBool IsActorPlaying(eEMotionType) const;
    GEBool IsInstance() const;
    GEBool IsMotionRunning(eEMotionType) const;
    void PauseMotion(GEBool, eEMotionType);
    void PlayMotion(eEMotionType, eCWrapper_emfx2Motion &, eCWrapper_emfx2Motion::eSMotionDesc *);
    void Process(bCMatrix const &, GEBool, GEBool, GEFloat);
    void ProcessGeometry();
    bEResult SaveActor(eCArchiveFile &, eCArchiveFile &);
    void SetActorName(bCString const &);
    void SetBlendMode(eEMotionType, eCWrapper_emfx2Motion::eEMotionBlendMode);
    void SetCurrentLoDLevel(GEU16);
    void SetIntroExtroBlending(eEMotionType, bCString &);
    void SetIntroExtroBlending(eEMotionType, GEFloat, GEFloat);
    void SetPlaySpeed(eEMotionType, GEFloat);
    void SetPlayTime(eEMotionType, GEFloat);
    void SetTargetWeight(eEMotionType, GEFloat);
    void StopAtLoopEnd(eEMotionType);
    void StopMotion(eEMotionType, GEFloat);
    void SwitchFadeOut(eEMotionType, GEBool, GEFloat);
    void UpdateDynamicSoftBuffer(GEU16, eCGfxVertexData *);

  protected:
    eCWrapper_emfx2Actor const &operator=(eCWrapper_emfx2Actor const &);

  protected:
    void CreateAndSaveMaterialTechnique(eCArchiveFile &);
    void Invalidate();
    bCString ResolveFileName(bCString) const;
    void RunStopPrevention(GEFloat);
    void SetActor(EMotionFX::Actor *);

  public:
    EMotionFX::Actor *m_pInstance;
    GE_UNIMPL_MEMBERS(32)
    bCBox m_Boundary;
    GE_UNIMPL_MEMBERS(32)
    bCString m_strActorName;
    GE_UNIMPL_MEMBERS(4)
    GEFloat m_fExtroBlending;
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(eCWrapper_emfx2Actor, 0x80)
