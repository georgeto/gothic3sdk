#ifndef GE_COMMANDLINE_H_INCLUDED
#define GE_COMMANDLINE_H_INCLUDED

class GE_DLLIMPORT bCCommandLine
{
    private:
        bTStringObjMap< bCString > m_mapOptions;    // 0000
        bTObjArray< bCString >     m_arrArguments;  // 0010

    public:
         bCCommandLine( bCCommandLine const & );
         bCCommandLine( bCString const & );
         bCCommandLine( void );
        ~bCCommandLine( void );

    public:
        bCCommandLine & operator =  ( bCCommandLine const & );
        bCOStream &     operator >> ( bCOStream & );
        bCIStream &     operator << ( bCIStream & );

    public:
        void                             CopyFrom( bCCommandLine const & );
        void                             CopyTo( bCCommandLine & ) const;
        GEBool                           Create( bCString const & );
        void                             Destroy( void );
        bTObjArray<bCString> const &     GetArguments( void ) const;
        void                             GetArguments( bTObjArray<bCString> & ) const;
        bTStringObjMap<bCString> const & GetOptions( void ) const;
        void                             GetOptions( bTStringObjMap<bCString> & ) const;
        GEBool                           Read( bCIStream & );
        void                             Write( bCOStream & );

    protected:
        static GEBool GE_STDCALL SkipOption( bCString &, bCString &, bCString & );
        static GEBool GE_STDCALL SkipOptionDelimiter( bCString & );
        static GEBool GE_STDCALL SkipValue( bCString &, bCString & );
        static GEBool GE_STDCALL SkipValue( bCString &, bCString &, GELPCChar );
        static GEBool GE_STDCALL SkipValueDelimiter( bCString & );
        static GEInt GE_STDCALL  SkipWordDelimiters( bCString & );

    protected:
        bTObjArray<bCString> &     AccessArguments( void );
        bTStringObjMap<bCString> & AccessOptions( void );
        GEInt                      InsertArgument( bCString const & );
        GEBool                     InsertOption( bCString const &, bCString const & );
        GEBool                     InsertOption( bCString const & );
        void                       Invalidate( void );
        GEBool                     ParseArgument( bCString & );
        GEBool                     ParseOption( bCString & );
        void                       SetArguments( bTObjArray<bCString> const & );
        void                       SetOptions( bTStringObjMap<bCString> const & );

};

#endif
