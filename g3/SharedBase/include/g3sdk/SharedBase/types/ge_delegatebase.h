#pragma once

#include <SharedBase/kernel/event/ge_event.h>
#include <SharedBase/kernel/object/ge_objectrefbase.h>

class bCDelegateBase
{
  public:
    virtual bCObjectRefBase *GetThisPointer() = 0;
    virtual bCDelegateBase *Clone() = 0;

  public:
    bCDelegateBase() : m_u16ReferenceCounter(0)
    {}

  protected:
    GEU16 m_u16ReferenceCounter;
};
GE_ASSERT_SIZEOF(bCDelegateBase, 0x08)

template <typename CLASS, typename ARG>
class bTDelegate : public bCDelegateBase
{
  public:
    bCObjectRefBase *GetThisPointer() override;
    bCDelegateBase *Clone() override;

  public:
    using bFDelegateFunction = void (GE_STDCALL CLASS::*)(bCObjectRefBase *a_pInvoker, ARG *a_pEvent);
    bTDelegate(bFDelegateFunction a_pDelegateFunction, CLASS *a_pClassThisPointer);

  private:
    bFDelegateFunction m_pDelegateFunction;
    CLASS *m_pClassThisPointer;
};

#include "ge_delegatebase.inl"

namespace
{
using bTDelegate_DUMMY = bTDelegate<bCObjectRefBase, bCEvent>;
GE_ASSERT_SIZEOF(bTDelegate_DUMMY, 0x10)
} // namespace
