#ifndef GE_ENUMWRAPPER_H_INCLUDED
#define GE_ENUMWRAPPER_H_INCLUDED

class bCEnumWrapper
{
    public: virtual bCString const & GetValueString() const = 0;
    public: virtual GEU32            GetValue() const       = 0;
    public: virtual                 ~bCEnumWrapper( void )  = 0;
};

template <typename ENUMCLASS>
class bTEnumWrapper : public bCEnumWrapper
{
    public: virtual bCString const & GetValueString() const;
    public: virtual GEU32            GetValue() const;
    public: virtual                 ~bTEnumWrapper( void );

    private:
        static bTObjMap<bCString, ENUMCLASS> & GetMapStringToValue();
        static bTObjMap<ENUMCLASS, bCString> & GetMapValueToString();

    public:
        bTEnumWrapper( bCString const & a_strValue, GEU32 a_u32Value );

    private:
                                     bTEnumWrapper();  // not defined
        bTEnumWrapper< ENUMCLASS > & operator = ( bTEnumWrapper< ENUMCLASS > const & );  // not defined

    private:
        ENUMCLASS m_EnumValue;
};

#include "ge_enumwrapper.inl"

namespace
{
    typedef bTEnumWrapper<bTPropertyContainer<GEU32>> bTEnumWrapper_DUMMY;
    GE_ASSERT_SIZEOF( bTEnumWrapper_DUMMY, 12 );
}

#endif
