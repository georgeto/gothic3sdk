#ifndef GE_MESSAGEADMIN_H_INCLUDED
#define GE_MESSAGEADMIN_H_INCLUDED

enum bEMessageCallbackPriority
{
    bEMessageCallbackPriority_Critical,
    bEMessageCallbackPriority_Normal,
    bEMessageCallbackPriority_Low,
    bEMessageCallbackPriority_Count
};

enum bEMessageFilterTypes
{
    bEMessageFilter_OK,
    bEMessageFilter_Info,
    bEMessageFilter_Warn,
    bEMessageFilter_Fault,
    bEMessageFilter_Fatal
};

enum bEMessageTypes
{
    bEMessageType_OK = 1,
    bEMessageType_Info,
    bEMessageType_Warn,
    bEMessageType_Fault,
    bEMessageType_Fatal
};

typedef GEBool (GE_STDCALL * GEFMessageCallback)( bEMessageTypes, GELPCChar, GELPCChar, GEU32, GELPCChar, GEInt, GEInt );

class GE_DLLIMPORT bCMessageAdmin
{
    public:
        static bCMessageAdmin & GE_STDCALL GetInstance( void );

    public:
         bCMessageAdmin( void );
        ~bCMessageAdmin( void );

    public:
        bCMessageAdmin & operator = ( bCMessageAdmin const & );

    public:
        void                 EnableLogFile( GEBool );
        bEMessageFilterTypes GetFilterType( void ) const;
        GEBool               OnMessage( bEMessageTypes, GELPCChar, GELPCChar, GELPCChar, GEInt, GEInt );
        GEBool               RegisterCallback( GEFMessageCallback, bEMessageCallbackPriority, GEU32 );
        void                 SetFilterType( bEMessageFilterTypes );
        GELPCChar            StripFilename( GELPCChar );
        GEBool               UnregisterCallback( GEFMessageCallback );

    protected:
        GEBool ExecuteCallbackType( bEMessageCallbackPriority, bEMessageTypes, GELPCChar, GELPCChar, GELPCChar, GEInt, GEInt );
        GEInt  LookupCallback( GEFMessageCallback ) const;

    private:
        void Create( void );
        void Destroy( void );
        void Invalidate( void );

};

#endif
