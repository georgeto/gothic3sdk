#pragma once

#include <Engine/ge_iterator.h>

#include <SharedBase.h>

class eCCollisionDesc;
class eCEntity;

class GE_DLLIMPORT eCIteratorReport
{
    // clang-format off
    public: virtual void Destroy();
    public: virtual bEResult Create();
    public: virtual bEResult CopyFrom(eCIteratorReport const &);
    public: virtual ~eCIteratorReport();
    // clang-format on

  public:
    eCIteratorReport(eCIteratorReport const &);
    eCIteratorReport();

  public:
    eCEntity *GetCollisionEntity();
    eCEntity const *GetCollisionEntity() const;
    eCCollisionDesc *GetCollisionPSReport();
    eCCollisionDesc const *GetCollisionPSReport() const;
    bCObjectRefBase const *GetCollisionPropertySet() const;
    eIterator::eEHitSubType GetHitSubType() const;

  protected:
    eCIteratorReport const &operator=(eCIteratorReport const &);

  protected:
    void Invalidate();
    void SetCollisionEntity(eCEntity *);
    void SetCollisionPSReport(eCCollisionDesc *);
    void SetCollisionPropertySet(bCObjectRefBase *);
};
