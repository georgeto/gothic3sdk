#ifndef GE_THREADPOOL_H_INCLUDED
#define GE_THREADPOOL_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4266 )// 'GEBool bCObjectBase::Write(bCOStream &) const' : no override available for virtual member function from base 'bCObjectBase'; function is hidden

class GE_DLLIMPORT eCThreadPool :
    public bCObjectBase
{
    public:
        class eCThreadPoolWorkerItem;

    public: virtual GEU16    GetVersion( void ) const;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual         ~eCThreadPool( void );

    protected:
        static GEBool ms_bEnableThreads;
        static GEU32  ms_u32NumOfJobsInQueue;
        static GEU32  ms_u32NumOfThreadsProcessing;

    public:
        static void GE_STDCALL   EnableAllThreads( GEBool );
        static GEU32 GE_STDCALL  GetGlobalNumberOfJobsInQueue( void );
        static GEU32 GE_STDCALL  GetGlobalNumberOfThreadsWorking( void );
        static GEBool GE_STDCALL IsThreadingEnabled( void );
        static GEU32 GE_STDCALL  g_ThreadFunc( GELPVoid );

    public:
        eCThreadPool( eCThreadPool const & );
        eCThreadPool( void );

    public:
        using bCObjectBase::CopyFrom;
        void                     CopyFrom( eCThreadPool const & );
        GEBool                   Create( GEU32 );
        GEU32                    GetNumOfJobsInQueueObject( void ) const;
        GEU32                    GetNumberOfThreadsWorking( void ) const;
        GEBool                   InsertWorkItem( eCThreadPoolWorkerItem * );
        eCThreadPoolWorkerItem * RemoveWorkItem( void );
        void                     SetPriority( bCThreadWin32::bEThreadPriority );
        GEBool                   WaitForEmptyThreadQueue( void );
        GEBool                   WaitForIdleThreads( void );

    protected:
        eCThreadPool const & operator = ( eCThreadPool const & );

    protected:
        void Invalidate( void );
};

#pragma warning( pop )

#endif
