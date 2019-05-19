#ifndef GE_UNICODECONFIGFILE_SECTIONOBJECT_H_INCLUDED
#define GE_UNICODECONFIGFILE_SECTIONOBJECT_H_INCLUDED

class GE_DLLIMPORT eCUnicodeConfigFile_SectionObject
{

    public:
         eCUnicodeConfigFile_SectionObject( eCUnicodeConfigFile_SectionObject & );
         eCUnicodeConfigFile_SectionObject( void );
        ~eCUnicodeConfigFile_SectionObject( void );

    public:
        eCUnicodeConfigFile_SectionObject const & operator =  ( eCUnicodeConfigFile_SectionObject const & );
        bCUnicodeString &                         operator [] ( bCUnicodeString const & );
        bCUnicodeString const &                   operator [] ( bCUnicodeString const & ) const;

    public:
        void                                  Clear( void );
        void                                  CopyFrom( eCUnicodeConfigFile_SectionObject const & );
        void                                  Create( void );
        void                                  Destroy( void );
        GEInt                                 GetKeyCount( void ) const;
        eCUnicodeConfigFile_KeyObject const * GetKeyObject( GEInt ) const;
        bCUnicodeString const &               GetSectionName( void ) const;
        bCUnicodeString const &               GetValue( bCUnicodeString const & ) const;
        GEBool                                GetValue( bCUnicodeString const &, bCUnicodeString & ) const;
        void                                  Invalidate( void );
        GEBool                                IsValidKey( GEInt ) const;
        GEBool                                RemoveKey( bCUnicodeString const & );
        GEBool                                RemoveValue( bCUnicodeString const & );
        void                                  Write( bCOStream & );

    protected:
        GEInt                           GetKeyIndex( bCUnicodeString const & ) const;
        eCUnicodeConfigFile_KeyObject & InsertNewEmptyKey( void );
        GEBool                          IsValidKey( bCUnicodeString const & ) const;
        GEBool                          SetKey( bCUnicodeString const &, bCUnicodeString const & );
        GEBool                          SetKey( bCUnicodeString const & );
        void                            SetSectionName( bCUnicodeString const & );
        void                            SetWhitespaces( GEU16 );

};

#endif
