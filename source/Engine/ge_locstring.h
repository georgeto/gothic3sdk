#ifndef GE_LOCSTRING_H_INCLUDED
#define GE_LOCSTRING_H_INCLUDED

class GE_DLLIMPORT eCLocString
{
    private:
        bCString id;

    public:
         eCLocString( eCLocString const & );
         eCLocString( bCString const & );
         eCLocString( eCLocString const * );
         eCLocString( void );
        ~eCLocString( void );

    public:
        eCLocString & operator =                     ( eCLocString const & );
        bCOStream &   operator >>                    ( bCOStream & ) const;
        bCIStream &   operator <<                    ( bCIStream & );
                      operator bCUnicodeString const ( void ) const;

    public:
        bCString const &      GetID( void ) const;
        bCUnicodeString const GetStageDirection( bCString const & ) const;
        bCUnicodeString const GetStageDirection( void ) const;
        bCUnicodeString const GetString( bCString const & ) const;
        bCUnicodeString const GetString( void ) const;
        void                  Read( bCIStream & );
        void                  SetID( bCString const & );
        void                  Write( bCOStream & ) const;

};

GE_ASSERT_SIZEOF( eCLocString, 0x04 )

#endif
