#ifndef GE_ERRORADMIN_H_INCLUDED
#define GE_ERRORADMIN_H_INCLUDED

enum bEErrorPositionHandling
{
    bEErrorCallbackType_Pre,
    bEErrorCallbackType_Post,
    bEErrorCallbackType_Count,
    bEErrorCallbackType_ForceDWORD = GE_FORCE_DWORD
};

enum bEErrorType
{
    bEErrorType_Exception,
    bEErrorType_Fatal,
    bEErrorType_Fault,
    bEErrorType_ForceDWORD = GE_FORCE_DWORD
};

struct bSException_Pointers : public EXCEPTION_POINTERS
{
};

class GE_DLLIMPORT bCErrorAdmin
{
    public:
        static bCErrorAdmin & GE_STDCALL GetInstance( void );

    public:
        ~bCErrorAdmin( void );

    public:
        void             AddHistoryEntry( GELPCChar );
        GEInt            CallExceptionError( bSException_Pointers * );
        GE_NORETURN void CallFatalError( GELPCChar a_strModule, GELPCChar a_strDescription, GELPCChar a_strFileName, GEInt a_iLine );
        GE_NORETURN void CallFatalError( GELPCChar a_strModule, GELPCChar a_strFileName, GEInt a_iLine );
        void             CallFaultError( GELPCChar a_strModule, GELPCChar a_strDescription, GELPCChar a_strFileName, GEInt a_iLine );
        void             CallFaultError( GELPCChar a_strModule, GELPCChar a_strFileName, GEInt a_iLine );
        void             Create( void );
        void             DebugBreak( void );
        void             EnableWriteMiniDump( GEBool );
        GEBool           GenerateDump( bSException_Pointers * );
        GEBool           IsDebuggerPresent( void ) const;
        GEBool           IsInPanicState( void ) const;
        GEBool           IsLocked( void ) const;
        void             LockSystem( void );
        GEBool           RegisterCallback( GEBool ( GE_STDCALL* )( bEErrorType, GEU32 ), bEErrorPositionHandling, GEU32 );
        void GE_CCALL    TraceF( GELPChar, ... );
        void             UnlockSystem( void );
        GEBool           UnregisterCallback( GEBool ( GE_STDCALL* )( bEErrorType, GEU32 ) );

    protected:
        bCErrorAdmin( bCErrorAdmin const & );
        bCErrorAdmin( void );

    protected:
        bCErrorAdmin const & operator = ( bCErrorAdmin const & );

    protected:
        void  Destroy( void );
        void  ExecuteErrorCallbacks( bEErrorPositionHandling, bEErrorType );
        void  Invalidate( void );
        GEInt LookupCallback( bEErrorPositionHandling, GEBool ( GE_STDCALL* )( bEErrorType, GEU32 ) ) const;
        void  PrintHistoryEntries( void );
        void  PrintMemoryDumpStats( void );
        void  PrintMessage( bCGothic3EngineDialogs::bEGE3DialogsLogMessageType, GELPCChar, GEBool );
        void  PrintStackFrame( bSException_Pointers * );
};

GELPCChar GE_STDCALL GetFirstStackTraceString( GEU32, _EXCEPTION_POINTERS * );
GEInt     GE_STDCALL GetFirstStackTraceStringVB( GEU32, _EXCEPTION_POINTERS *, GELPChar, GEUInt );

GELPCChar GE_STDCALL GetNextStackTraceString( GEU32, _EXCEPTION_POINTERS * );
GEInt     GE_STDCALL GetNextStackTraceStringVB( GEU32, _EXCEPTION_POINTERS *, GELPChar, GEUInt );

GELPCChar GE_STDCALL GetRegisterString( _EXCEPTION_POINTERS * );
GEInt     GE_STDCALL GetRegisterStringVB( _EXCEPTION_POINTERS *, GELPChar, GEUInt );

#endif
