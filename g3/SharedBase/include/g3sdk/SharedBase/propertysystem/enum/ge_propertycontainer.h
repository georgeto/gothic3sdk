#pragma once

#include <SharedBase/kernel/object/ge_objectbase.h>
#include <SharedBase/propertysystem/ge_propertymacros.h>

// NOTE: Invalidate is virtual but the template is not exported.
// Therefore we do not have access to the Default Value defined
// elsewhere in the Genome libraries or the Game application...
// That is the reason why no default constructor is defined and
// our definition of Invalidate sets the Value to -1 (it should
// be an invalid value for most of the enumerations). The other
// virtual methods (Read and Write) emulate the Genome methods.
template <typename T>
class bTPropertyContainer : public bCObjectBase
{
    // clang-format off
    public: bEResult Write( bCOStream & ) override;
    public: bEResult Read( bCIStream & ) override;
    public: bEResult Create( ) override;
    public: bEResult CopyFrom( bCObjectBase const & ) override;
    public: ~bTPropertyContainer( ) override;
    // clang-format on

  public:
    static T s_DefaultValue;

  protected:
    GE_DECLARE_PROPERTY(T, m_Value, Value)

  public:
    bTPropertyContainer();
    explicit bTPropertyContainer(T const &);
    bTPropertyContainer(bTPropertyContainer<T> const &);

  public:
    operator T &();
    operator T const &() const;
    GEBool operator==(bTPropertyContainer<T> const &) const;
    GEBool operator==(T const &) const;
    GEBool operator!=(bTPropertyContainer<T> const &) const;
    GEBool operator!=(T const &) const;
    bTPropertyContainer<T> &operator=(bTPropertyContainer<T> const &);
};

#include "ge_propertycontainer.inl"

GE_ASSERT_SIZEOF(bTPropertyContainer<GEU32>, 0x08)

template <typename T>
inline GEU32 GE_STDCALL g_GetHashValue(bTPropertyContainer<T> const &_e)
{
    return _e.m_Value;
}
