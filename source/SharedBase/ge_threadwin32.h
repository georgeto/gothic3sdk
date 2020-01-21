#ifndef GE_THREADWIN32_H_INCLUDED
#define GE_THREADWIN32_H_INCLUDED

class GE_DLLIMPORT bCThreadWin32
{
    public:
        enum bEThreadPriority
        {
            bEThreadPriority_LOWEST        = 0xFFFFFFFE,
            bEThreadPriority_BELOW_NORMAL  = 0xFFFFFFFF,
            bEThreadPriority_NORMAL        = 0x00000000,
            bEThreadPriority_HIGHEST       = 0x00000002,
            bEThreadPriority_ABOVE_NORMAL  = 0x00000001,
            bEThreadPriority_ERROR_RETURN  = 0x7FFFFFFF,
            bEThreadPriority_TIME_CRITICAL = 0x0000000F,
            bEThreadPriority_IDLE          = 0xFFFFFFF1,
        };

        struct bSThreadContext
        {
            public:
                bSThreadContext( void );

            public:
                bSThreadContext & operator = ( bSThreadContext const & );

            public:
                GEInt    iThreadIdentifier;
                GELPVoid pUserData;
        };

    public:
         bCThreadWin32( void );
        ~bCThreadWin32( void );

    public:
        bCThreadWin32 & operator = ( bCThreadWin32 const & );

    public:
        GEBool   Create( bSThreadContext const &, GEU32 ( GE_STDCALL* )( GELPVoid ) );
        void     Destroy( void );
        GELPVoid GetHandle( void ) const;
        GEBool   IsValid( void ) const;
        void     SetPriority( bEThreadPriority );

    private:
        HANDLE          m_Handle;
        bSThreadContext m_Context;
};

GE_ASSERT_SIZEOF( bCThreadWin32, 0x0C )

#endif
