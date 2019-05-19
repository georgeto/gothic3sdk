#ifndef GE_LOCADMIN_H_INCLUDED
#define GE_LOCADMIN_H_INCLUDED

class GE_DLLIMPORT eCLocAdmin
{
    public:
        static eCLocAdmin & GE_STDCALL GetInstance( void );

    public:
        eCLocAdmin( eCLocAdmin const & );

    public:
        eCLocAdmin & operator = ( eCLocAdmin const & );

    public:
        GEBool                                 AddLanguage( bCString const & );
        GEBool                                 AddReference( bCString const & );
        GEBool                                 AddReference( eCLocString * );
        bCString                               AddString( bCString const &, eCLocTable::SEntry const &, bCString const & );
        bCString                               AddString( bCString const &, eCLocTable::SEntry const & );
        GEBool                                 AreIDsEqual( bCString const &, bCString const & ) const;
        GEBool                                 Create( void );
        void                                   Destroy( void );
        GEBool                                 DuplicateID( bCString const &, bCString const & );
        GEBool                                 ExistsID( bCString const & ) const;
        GEBool                                 ExistsLanguage( bCString const & ) const;
        GEBool                                 ExistsString( eCLocTable::SEntry & ) const;
        GEBool                                 ExistsString( eCLocTable::SEntry &, bCString const & ) const;
        bCString                               FindLanguage( GEInt ) const;
        GEInt                                  FindLanguageIndex( bCString const & ) const;
        bCString const &                       GetCurrentAudioLanguage( void ) const;
        bCString const &                       GetCurrentLanguage( void ) const;
        GEUInt const &                         GetCurrentRevision( void ) const;
        eCLocTable::SEntry const               GetEntry( bCString const &, bCString const & ) const;
        eCLocTable::SEntry const               GetEntry( bCString const & ) const;
        bCString                               GetID( eCLocTable::SEntry & ) const;
        bCString                               GetID( eCLocTable::SEntry &, bCString const & ) const;
        GEInt                                  GetIDCount( void ) const;
        GEBool                                 GetIDList( bTObjArray<bCString> & ) const;
        GEInt                                  GetLanguageCount( void ) const;
        eCLocTable const &                     GetLocTable( bCString const & );
        bCString                               GetNewID( bCString const & ) const;
        GEU32                                  GetReferenceCount( bCString const & ) const;
        GEU32                                  GetReferenceCount( void ) const;
        GEUInt                                 GetRevision( bCString const & ) const;
        bCUnicodeString const                  GetStageDirection( bCString const &, bCString const & ) const;
        bCUnicodeString const                  GetStageDirection( bCString const & ) const;
        bCUnicodeString const                  GetString( bCString const &, bCString const & ) const;
        bCUnicodeString const                  GetString( bCString const & ) const;
        bCString                               GetStringTableFile( void ) const;
        bTObjMap<bCString, eCLocTable> const & GetTables( void ) const;
        void                                   Invalidate( void );
        GEBool                                 IsModified( void ) const;
        GEBool                                 IsReadOnly( void ) const;
        GEBool                                 Read( bCString const &, GEBool );
        GEBool                                 Read( void );
        GEBool                                 ReadBinary( bCString const & );
        GEBool                                 ReadCSV( bCString const &, GEBool );
        GEBool                                 RemoveDuplicateID( bCString const & );
        GEBool                                 RemoveDuplicateIDs( void );
        GEBool                                 RemoveID( bCString const & );
        GEBool                                 RemoveLanguage( bCString const & );
        GEBool                                 RemoveReference( bCString const & );
        GEBool                                 RemoveReference( eCLocString * );
        GEU32                                  RemoveUnusedIDs( void );
        GEBool                                 RenameID( bCString const &, bCString const & );
        GEBool                                 ReserveString( bCString const &, eCLocTable::SEntry const &, bCString const & );
        GEBool                                 ReserveString( bCString const &, eCLocTable::SEntry const & );
        void                                   SetCurrentAudioLanguage( bCString const & );
        void                                   SetCurrentLanguage( bCString const & );
        void                                   SetCurrentRevision( GEUInt const & );
        GEBool                                 SetString( bCString const &key, eCLocTable::SEntry const &entry, bCString const &lang );
        GEBool                                 SetString( bCString const &key, eCLocTable::SEntry const &entry );
        GEBool                                 Write( bCString const & ) const;
        GEBool                                 Write( void ) const;
        void                                   WriteBinary( bCString const & );
        GEBool                                 WriteCSV( bCString const & ) const;

    protected:
         eCLocAdmin( void );
        ~eCLocAdmin( void );

    protected:
        GEBool ReadASCII( bCString const &, GEBool );
        GEBool ReadUnicode( bCString const &, GEBool );

};

#endif
