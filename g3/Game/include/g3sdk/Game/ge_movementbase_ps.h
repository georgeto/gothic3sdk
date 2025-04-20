#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCMovementBase_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual void MoveLocal(GEFloat, GEFloat, GEFloat);
    public: virtual void MoveLocal(bCVector const &);
    public: virtual void MoveWorld(GEFloat, GEFloat, GEFloat);
    public: virtual void MoveWorld(bCVector const &);
    public: virtual void RotateWorld(bCQuaternion const &);
    public: virtual void RotateWorld(GEFloat, GEFloat, GEFloat, GEFloat);
    public: virtual void RotateWorld(bCVector const &, GEFloat);
    public: virtual void RotateWorldX(GEFloat);
    public: virtual void RotateWorldY(GEFloat);
    public: virtual void RotateWorldZ(GEFloat);
    public: virtual void RotateLocal(GEFloat, GEFloat, GEFloat, GEFloat);
    public: virtual void RotateLocal(bCVector const &, GEFloat);
    public: virtual void RotateLocalX(GEFloat);
    public: virtual void RotateLocalY(GEFloat);
    public: virtual void RotateLocalZ(GEFloat);
    public: virtual bCVector const & GetAtVectorWorld() const;
    public: virtual bCVector const & GetUpVectorWorld() const;
    public: virtual bCVector const & GetRightVectorWorld() const;
    public: virtual void ResetRotationsWorld();
    public: virtual void ResetXZRotationsWorld();
    public: virtual void ResetRotationsLocal();
    public: virtual void ResetXZRotationsLocal();
    public: virtual void SetHeadingAtWorld(bCVector const &);
    public: virtual void SetHeadingWorld(bCVector const &);
    public: virtual void SetHeadingWorld(eCEntity *);
    public: virtual void SetHeadingYWorld(bCVector const &);
    public: virtual void SetHeadingYWorld(eCEntity *);
    public: virtual void SetHeadingAtLocal(bCVector const &);
    public: virtual void SetHeadingLocal(bCVector const &);
    public: virtual void SetHeadingYLocal(bCVector const &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCMovementBase_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    public: GEInt OnAction(eCInpShared::eSGameKeyMessage const &) override;
    public: GEInt OnMouse(eCInpShared::eSInputMessage const &) override;
    protected: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMovementBase_PS, eCEntityPropertySet)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCMovementBase_PS, 0x14)
