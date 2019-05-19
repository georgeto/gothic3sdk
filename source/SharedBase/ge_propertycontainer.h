#ifndef GE_PROPERTYCONTAINER_H_INCLUDED
#define GE_PROPERTYCONTAINER_H_INCLUDED

#pragma warning ( push )
#pragma warning ( disable : 4266 )// 'GEBool bCObjectBase::Write(bCOStream &) const' : no override available for virtual member function from base 'bCObjectBase'; function is hidden

// NOTE: Invalidate is virtual but the template is not exported.
// Therefore we do not have access to the Default Value defined
// elsewhere in the Genome libraries or the Game application...
// That is the reason why no default constructor is defined and
// our definition of Invalidate sets the Value to -1 (it should
// be an invalid value for most of the enumerations). The other
// virtual methods (Read and Write) emulate the Genome methods.
template< typename T >
class bTPropertyContainer :
    public bCObjectBase
{
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual bEResult Create( void );
    public: virtual bEResult CopyFrom( bCObjectBase const & );
    public: virtual         ~bTPropertyContainer( void );

    public:
        static T s_DefaultValue;

    protected:
        GE_DECLARE_PROPERTY( T, m_Value, Value )

    public:
        bTPropertyContainer( void );
        bTPropertyContainer( T const & );
        bTPropertyContainer( bTPropertyContainer< T > const & );

    public:
               operator T &       ( void );
               operator T const & ( void ) const;
        GEBool operator ==        ( bTPropertyContainer< T > const & ) const;
        GEBool operator ==        ( T const & ) const;
        GEBool operator !=        ( bTPropertyContainer< T > const & ) const;
        GEBool operator !=        ( T const & ) const;
        bTPropertyContainer< T > & operator = ( bTPropertyContainer< T > const & );
};

#include "ge_propertycontainer.inl"

#pragma warning ( pop )

GE_ASSERT_SIZEOF( bTPropertyContainer<GEU32>, 0x08 )

template<typename T>
static inline GEU32 g_GetHashValue( bTPropertyContainer<T> const & _e )
{
    return _e.m_Value;
}

#endif
