#include "Common.h"

namespace
{
    class mCGothicLogger
    {
        public:
            void Register();

        public:
            ~mCGothicLogger();

        protected:
            static GEBool GE_STDCALL g_MessageCallback(bEMessageTypes a_enumType, GELPCChar a_pcMessage, GELPCChar a_pcReserved, GEU32 a_u32Parameter, GELPCChar a_pcFile, GEInt a_iLine, GEInt a_iPriority);

        protected:
            GEBool OnMessageCallback(bEMessageTypes a_enumType, GELPCChar a_pcMessage, GELPCChar a_pcReserved, GELPCChar a_pcFile, GEInt a_iLine, GEInt a_iPriority);
    };

    void mCGothicLogger::Register()
    {
        bCMessageAdmin::GetInstance().RegisterCallback(
            mCGothicLogger::g_MessageCallback, bEMessageCallbackPriority_Normal,
            reinterpret_cast<GEU32>(this));
    }

    GEBool GE_STDCALL mCGothicLogger::g_MessageCallback(bEMessageTypes a_enumType, GELPCChar a_pcMessage, GELPCChar a_pcReserved, GEU32 a_u32Parameter, GELPCChar a_pcFile, GEInt a_iLine, GEInt a_iPriority)
    {
        mCGothicLogger * pGothicLogger = reinterpret_cast<mCGothicLogger *>(a_u32Parameter);
        if (pGothicLogger)
            return pGothicLogger->OnMessageCallback(a_enumType, a_pcMessage, a_pcReserved, a_pcFile, a_iLine, a_iPriority);
        return GEFalse;
    }

    GEBool mCGothicLogger::OnMessageCallback(bEMessageTypes a_enumType, GELPCChar a_pcMessage, GELPCChar a_pcReserved, GELPCChar a_pcFile, GEInt a_iLine, GEInt a_iPriority)
    {
        bCString strMessage = bCString::GetFormattedString("{%d,%d} ", a_enumType, a_iPriority);
        if (a_pcReserved)
            strMessage += bCString::GetFormattedString("[%s] ", a_pcReserved);
        strMessage += a_pcMessage;
        if (a_pcFile)
            strMessage += bCString::GetFormattedString(" (%s,%d)", a_pcFile, a_iLine);
        strMessage += "\n";

        mCFileLogger::GetInstance("g3debug").LogString(strMessage);

        return GEFalse;
    }

    mCGothicLogger::~mCGothicLogger()
    {
        bCMessageAdmin::GetInstance().UnregisterCallback(&g_MessageCallback);
    }
}

ME_MODULE(MessageLogger)
{
    if (GetModSettings().Logging_Gothic)
    {
        static mCGothicLogger s_MessageLogger;
        s_MessageLogger.Register();
    }
}
