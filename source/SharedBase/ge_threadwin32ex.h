#ifndef GE_THREADWIN32EX_H_INCLUDED
#define GE_THREADWIN32EX_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )// class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT bCThreadWin32Ex :
    public bCThreadWin32
{

    //FIXME: In VTable1 aber nicht in Exports enthalten: 0x0006B288 - public: virtual void __purecall_1()
    public: virtual void __purecall_1();


    protected:
        static GEBool ms_bEnableThreads;

    public:
        static void GE_STDCALL EnableThreads( GEBool );

    public:
         bCThreadWin32Ex( bCThreadWin32Ex const & );
         bCThreadWin32Ex( void );
        ~bCThreadWin32Ex( void );

    public:
        bCThreadWin32Ex & operator = ( bCThreadWin32Ex const & );

    public:
        GEBool EndThread( void );
        void   SleepThread( GEU32 );
        GEBool StartThread( void );
        void   WaitIfThreadFinished( void );

    protected:
        static GEU32 GE_STDCALL ThreadFunc( GELPVoid );

};

#pragma warning( pop )

#endif
