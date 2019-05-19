#ifndef GE_ACCESSORENUM_H_INCLUDED
#define GE_ACCESSORENUM_H_INCLUDED

class GE_DLLIMPORT bCAccessorEnum
{

    public:
        bCAccessorEnum( bCAccessorProperty & );

    public:
        GEInt            GetEnumTypeInt( GEInt ) const;
        bCString const & GetEnumTypeString( GEInt ) const;
        GEInt            GetTypeCount( void ) const;
        GEInt            GetValue( void ) const;
        GEBool           IsValid( void ) const;
        void             SetValue( GEInt );

};

#endif
