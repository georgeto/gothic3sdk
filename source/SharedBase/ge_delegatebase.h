#ifndef GE_DELEGATEBASE_H_INCLUDED
#define GE_DELEGATEBASE_H_INCLUDED

class bCDelegateBase
{
    public:
        virtual bCObjectRefBase * GetThisPointer() = 0;
        virtual bCDelegateBase *  Clone()          = 0;

    public:
        bCDelegateBase()
            : m_u16ReferenceCounter(0)
        {}

    protected:
        GEU16 m_u16ReferenceCounter;
};
GE_ASSERT_SIZEOF( bCDelegateBase, 0x08 )


template< typename CLASS, typename ARG >
class bTDelegate
    : public bCDelegateBase
{
    public:
        virtual bCObjectRefBase * GetThisPointer();
        virtual bCDelegateBase *  Clone();

    public:
        typedef void ( GE_STDCALL CLASS::*bFDelegateFunction )( bCObjectRefBase * a_pInvoker, ARG * a_pEvent );
        bTDelegate( bFDelegateFunction a_pDelegateFunction, CLASS * a_pClassThisPointer );

    private:
        bFDelegateFunction m_pDelegateFunction;
        CLASS *            m_pClassThisPointer;
};

#include "ge_delegatebase.inl"

namespace
{
    typedef bTDelegate<bCObjectRefBase, bCEvent> bTDelegate_DUMMY;
    GE_ASSERT_SIZEOF( bTDelegate_DUMMY, 0x10 )
}

#endif
