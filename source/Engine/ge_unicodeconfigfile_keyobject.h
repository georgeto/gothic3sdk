#ifndef GE_UNICODECONFIGFILE_KEYOBJECT_H_INCLUDED
#define GE_UNICODECONFIGFILE_KEYOBJECT_H_INCLUDED

class GE_DLLIMPORT eCUnicodeConfigFile_KeyObject
{

    public:
         eCUnicodeConfigFile_KeyObject( eCUnicodeConfigFile_KeyObject & );
         eCUnicodeConfigFile_KeyObject( bCUnicodeString const & );
         eCUnicodeConfigFile_KeyObject( void );
        ~eCUnicodeConfigFile_KeyObject( void );

    public:
        eCUnicodeConfigFile_KeyObject const & operator = ( eCUnicodeConfigFile_KeyObject const & );

    public:
                                eCUnicodeConfigFile_KeyObject( bCUnicodeString const &, bCUnicodeString const &, bCUnicodeString const & );
                                eCUnicodeConfigFile_KeyObject( bCUnicodeString const &, bCUnicodeString const & );
        void                    Clear( void );
        void                    CopyFrom( eCUnicodeConfigFile_KeyObject const & );
        void                    Create( void );
        void                    Destroy( void );
        bCUnicodeString const & GetComment( void ) const;
        bCUnicodeString const & GetKey( void ) const;
        bCUnicodeString &       GetValue( void );
        bCUnicodeString const & GetValue( void ) const;
        GEBool                  HasKeyOnly( void ) const;
        void                    Invalidate( void );
        GEBool                  IsComment( void ) const;
        GEBool                  IsEmpty( void ) const;
        void                    SetComment( bCUnicodeString const & );
        void                    SetKey( bCUnicodeString const & );
        void                    SetValue( bCUnicodeString const & );
        void                    Write( bCOStream & );

};

#endif
