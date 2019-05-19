#ifndef GE_UNICODECONFIGFILE_H_INCLUDED
#define GE_UNICODECONFIGFILE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )// class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT eCUnicodeConfigFile
{
    protected: virtual GEBool ReadFile( bCIStream & );

    public:
        struct eSConfigValue
        {
            bCUnicodeString * m_pstrKey;
            bCUnicodeString * m_pstrValue;
        };
        GE_ASSERT_SIZEOF( eSConfigValue, 0x0008 )

    public:
         eCUnicodeConfigFile( eCUnicodeConfigFile const & );
         eCUnicodeConfigFile( bCString const & );
         eCUnicodeConfigFile( void );
        ~eCUnicodeConfigFile( void );

    public:
        bCOStream &             operator >> ( bCOStream & );
        bCIStream &             operator << ( bCIStream & );
        bCUnicodeString &       operator () ( bCUnicodeString const &, bCUnicodeString const & );
        bCUnicodeString const & operator () ( bCUnicodeString const &, bCUnicodeString const & ) const;

    public:
        void                                                  AddComment( bCUnicodeString const & );
        void                                                  AddEmptyLine( void );
        void                                                  Clear( void );
        GEBool                                                Contains( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEBool                                                Contains( bCUnicodeString const & ) const;
        void                                                  CopyFrom( eCUnicodeConfigFile const & );
        void                                                  Create( void );
        void                                                  Destroy( void );
        GEBool                                                GetBool( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEBool                                                GetBool( bCUnicodeString const &, bCUnicodeString const &, GEBool ) const;
        bCString const &                                      GetFilePath( void ) const;
        GEFloat                                               GetFloat( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEFloat                                               GetFloat( bCUnicodeString const &, bCUnicodeString const &, GEFloat ) const;
        GEI16                                                 GetI16( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEI16                                                 GetI16( bCUnicodeString const &, bCUnicodeString const &, GEI16 ) const;
        GEI32                                                 GetI32( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEI32                                                 GetI32( bCUnicodeString const &, bCUnicodeString const &, GEI32 ) const;
        GEI8                                                  GetI8( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEI8                                                  GetI8( bCUnicodeString const &, bCUnicodeString const &, GEI8 ) const;
        GEInt                                                 GetInt( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEInt                                                 GetInt( bCUnicodeString const &, bCUnicodeString const &, GEInt ) const;
        bTObjArray<eCUnicodeConfigFile_SectionObject> &       GetSectionArray( void );
        bTObjArray<eCUnicodeConfigFile_SectionObject> const & GetSectionArray( void ) const;
        GEBool                                                GetSectionBlock( bCUnicodeString, bTObjArray<eSConfigValue> & ) const;
        GEBool                                                GetSections( bTObjArray<bCUnicodeString> & ) const;
        bCUnicodeString &                                     GetString( bCUnicodeString const &, bCUnicodeString const &, bCUnicodeString const & ) const;
        bCUnicodeString &                                     GetString( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEU16                                                 GetU16( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEU16                                                 GetU16( bCUnicodeString const &, bCUnicodeString const &, GEU16 ) const;
        GEU32                                                 GetU32( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEU32                                                 GetU32( bCUnicodeString const &, bCUnicodeString const &, GEU32 ) const;
        GEU8                                                  GetU8( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEU8                                                  GetU8( bCUnicodeString const &, bCUnicodeString const &, GEU8 ) const;
        bCUnicodeString &                                     GetValue( bCUnicodeString const &, bCUnicodeString const & );
        bCUnicodeString const &                               GetValue( bCUnicodeString const &, bCUnicodeString const & ) const;
        GEBool                                                GetValue( bCUnicodeString const &, bCUnicodeString const &, GEI8 & ) const;
        GEBool                                                GetValue( bCUnicodeString const &, bCUnicodeString const &, GEU8 & ) const;
        GEBool                                                GetValue( bCUnicodeString const &, bCUnicodeString const &, GEI16 & ) const;
        GEBool                                                GetValue( bCUnicodeString const &, bCUnicodeString const &, GEU16 & ) const;
        GEBool                                                GetValue( bCUnicodeString const &, bCUnicodeString const &, GEInt & ) const;
        GEBool                                                GetValue( bCUnicodeString const &, bCUnicodeString const &, GEI32 & ) const;
        GEBool                                                GetValue( bCUnicodeString const &, bCUnicodeString const &, GEU32 & ) const;
        GEBool                                                GetValue( bCUnicodeString const &, bCUnicodeString const &, GEFloat & ) const;
        GEBool                                                GetValue( bCUnicodeString const &, bCUnicodeString const &, GEDouble & ) const;
        GEBool                                                GetValue( bCUnicodeString const &, bCUnicodeString const &, bCUnicodeString & ) const;
        GEBool                                                GetValue( bCUnicodeString const &, bCUnicodeString const &, GEBool & ) const;
        void                                                  Invalidate( void );
        GEBool                                                IsOpen( void ) const;
        GEBool                                                ReadFile( bCString const & );
        GEBool                                                RemoveKey( bCUnicodeString const &, bCUnicodeString const & );
        GEBool                                                RemoveSection( bCUnicodeString const & );
        GEBool                                                RemoveValue( bCUnicodeString const &, bCUnicodeString const & );
        GEBool                                                SetSection( bCUnicodeString const &, bCUnicodeString const & );
        GEBool                                                SetSection( bCUnicodeString const & );
        GEBool                                                SetValue( bCUnicodeString const &, bCUnicodeString const &, bCUnicodeString const & );
        GEBool                                                SetValue( bCUnicodeString const &, bCUnicodeString const &, GEI8 );
        GEBool                                                SetValue( bCUnicodeString const &, bCUnicodeString const &, GEU8 );
        GEBool                                                SetValue( bCUnicodeString const &, bCUnicodeString const &, GEI16 );
        GEBool                                                SetValue( bCUnicodeString const &, bCUnicodeString const &, GEU16 );
        GEBool                                                SetValue( bCUnicodeString const &, bCUnicodeString const &, GEInt );
        GEBool                                                SetValue( bCUnicodeString const &, bCUnicodeString const &, GEI32 );
        GEBool                                                SetValue( bCUnicodeString const &, bCUnicodeString const &, GEU32 );
        GEBool                                                SetValue( bCUnicodeString const &, bCUnicodeString const &, GEFloat );
        GEBool                                                SetValue( bCUnicodeString const &, bCUnicodeString const &, GEDouble );
        GEBool                                                SetValue( bCUnicodeString const &, bCUnicodeString const &, GEBool );
        GEBool                                                Sort( void );
        GEBool                                                Update( void );
        GEBool                                                WriteFile( bCString const & );
        GEBool                                                WriteFile( void );

    protected:
        eCUnicodeConfigFile const & operator = ( eCUnicodeConfigFile const & );

    protected:
        eCUnicodeConfigFile_SectionObject * AccessSection( bCUnicodeString const & );
};

#pragma warning( pop )

#endif
