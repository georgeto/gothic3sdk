#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCCollisionDesc : public bCObjectRefBase
{
  public:
    enum eECollisionDescType
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: virtual eECollisionDescType GetCollisionDescType();
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCCollisionDesc() override;
    // clang-format on

  public:
    eCCollisionDesc(eCCollisionDesc const &);
    eCCollisionDesc();

  protected:
    eCCollisionDesc const &operator=(eCCollisionDesc const &);

  protected:
    void Invalidate();
};
