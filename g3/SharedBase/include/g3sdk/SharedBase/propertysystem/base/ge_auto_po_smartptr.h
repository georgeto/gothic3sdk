#pragma once

#include "ge_po_puresmartptr.h"

#include <SharedBase/io/streams/ge_istream.h>
#include <SharedBase/io/streams/ge_ostream.h>

template <typename CLASS>
class bTAutoPOSmartPtr
{
  public:
    void CopyFrom(bTAutoPOSmartPtr<CLASS> const &a_Source);
    void Create();
    void Destroy();
    void SetPropertyObject(bTPOPureSmartPtr<CLASS> *a_Source);

  public:
    bTAutoPOSmartPtr();
    explicit bTAutoPOSmartPtr(CLASS &a_Object);
    ~bTAutoPOSmartPtr();

  public:
    bTAutoPOSmartPtr<CLASS> &operator=(bTAutoPOSmartPtr<CLASS> const &);
    explicit operator CLASS *();
    explicit operator CLASS const *() const;
    CLASS *operator->();
    CLASS const *operator->() const;
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  private:
    bTPOPureSmartPtr<CLASS> *m_pPropertyObject;
};

#include "ge_auto_po_smartptr.inl"

GE_ASSERT_SIZEOF(bTAutoPOSmartPtr<bCObjectRefBase>, 0x04)
