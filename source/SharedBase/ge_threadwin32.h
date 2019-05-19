#ifndef GE_THREADWIN32_H_INCLUDED
#define GE_THREADWIN32_H_INCLUDED

enum bEThreadPriority;

class GE_DLLIMPORT bCThreadWin32
{
    public:
        struct bSThreadContext
        {
            public:
                bSThreadContext( void );

            public:
                bSThreadContext & operator = ( bSThreadContext const & );
        };

    public:
         bCThreadWin32( void );
        ~bCThreadWin32( void );

    public:
        bCThreadWin32 & operator = ( bCThreadWin32 const & );


    public:

        GEBool   Create( bSThreadContext const &, GEU32 ( GE_STDCALL* )( GELPVoid ));
        void     Destroy( void );
        GELPVoid GetHandle( void ) const;
        GEBool   IsValid( void ) const;
        void     SetPriority( bEThreadPriority );

};

#endif
