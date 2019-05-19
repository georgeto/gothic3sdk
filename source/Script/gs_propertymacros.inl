template< typename PSP >
PSP & EntityPropertySet::AccessProperty( void )
{
    return *reinterpret_cast< typename PSP::PropertySetProperty * >( this );
}

template< typename PSP >
PSP const & EntityPropertySet::GetProperty( void ) const
{
    return *reinterpret_cast< typename PSP::PropertySetProperty const * >( this );
}