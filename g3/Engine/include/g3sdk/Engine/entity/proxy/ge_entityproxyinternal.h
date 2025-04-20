#pragma once

#include <SharedBase.h>

class eCEntity;

class GE_DLLIMPORT eCEntityProxyInternal
{
  public:
    eCEntityProxyInternal &operator=(eCEntityProxyInternal const &);

  public:
    GEU32 AddReference();
    eCEntity *GetEntity();
    eCEntity const *GetEntity() const;
    GEU32 GetReferenceCount() const;
    GEU32 ReleaseReference();

  protected:
    eCEntityProxyInternal();
    ~eCEntityProxyInternal();

  protected:
    void Invalidate();
    void SetEntity(eCEntity const *);

  private:
    eCEntity *m_Entity;
    GEU32 m_ReferenceCount;
};

GE_ASSERT_SIZEOF(eCEntityProxyInternal, 0x8)
