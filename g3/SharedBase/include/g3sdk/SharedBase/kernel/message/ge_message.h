#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

GE_DLLIMPORT_EXTC GEInt const g_iDefaultMessagePriority;

#ifdef _DEBUG
#define GE_MESSAGE_OK_EX(METHOD, TEXT)                                                                                 \
    bCMessageAdmin::GetInstance().OnMessage(bEMessageType_OK, TEXT, METHOD, __FILE__, __LINE__,                        \
                                            g_iDefaultMessagePriority);
#define GE_MESSAGE_OK(TEXT) GE_MESSAGE_OK_EX(0, TEXT)
#define GE_MESSAGE_INFO_EX(LEVEL, METHOD, TEXT)                                                                        \
    bCMessageAdmin::GetInstance().OnMessage(bEMessageType_Info, TEXT, METHOD, __FILE__, __LINE__, LEVEL);
#define GE_MESSAGE_INFO(LEVEL, TEXT) GE_MESSAGE_OK_EX(LEVEL, 0, TEXT)
#define GE_MESSAGE_WARN_EX(METHOD, TEXT)                                                                               \
    bCMessageAdmin::GetInstance().OnMessage(bEMessageType_Warn, TEXT, METHOD, __FILE__, __LINE__,                      \
                                            g_iDefaultMessagePriority);
#define GE_MESSAGE_WARN(TEXT) GE_MESSAGE_WARN_EX(0, TEXT)
#else
#define GE_MESSAGE_OK_EX(METHOD, TEXT)                                                                                 \
    bCMessageAdmin::GetInstance().OnMessage(bEMessageType_OK, TEXT, METHOD, 0, -1, g_iDefaultMessagePriority);
#define GE_MESSAGE_OK(TEXT) GE_MESSAGE_OK_EX(0, TEXT)
#define GE_MESSAGE_INFO_EX(LEVEL, METHOD, TEXT)                                                                        \
    bCMessageAdmin::GetInstance().OnMessage(bEMessageType_Info, TEXT, METHOD, 0, 0, LEVEL);
#define GE_MESSAGE_INFO(LEVEL, TEXT) GE_MESSAGE_OK_EX(LEVEL, 0, TEXT)
#define GE_MESSAGE_WARN_EX(METHOD, TEXT)                                                                               \
    bCMessageAdmin::GetInstance().OnMessage(bEMessageType_Warn, TEXT, METHOD, 0, -1, g_iDefaultMessagePriority);
#define GE_MESSAGE_WARN(TEXT) GE_MESSAGE_WARN_EX(0, TEXT)
#endif

GE_DLLIMPORT_EXTC GEInt GE_CCALL GE_MESSAGEF_INFO(GEInt, GELPChar, ...) GE_PRINTF_FORMAT(2, 3);
GE_DLLIMPORT_EXTC GEInt GE_CCALL GE_MESSAGEF_D_INFO(GEInt, GELPChar, ...) GE_PRINTF_FORMAT(2, 3);
GE_DLLIMPORT_EXTC GEInt GE_CCALL GE_MESSAGEF_OK(GELPChar, ...) GE_PRINTF_FORMAT(1, 2);
GE_DLLIMPORT_EXTC GEInt GE_CCALL GE_MESSAGEF_D_OK(GELPChar, ...) GE_PRINTF_FORMAT(1, 2);
GE_DLLIMPORT_EXTC GEInt GE_CCALL GE_MESSAGEF_WARN(GELPChar, ...) GE_PRINTF_FORMAT(1, 2);
GE_DLLIMPORT_EXTC GEInt GE_CCALL GE_MESSAGEF_D_WARN(GELPChar, ...) GE_PRINTF_FORMAT(1, 2);
GE_DLLIMPORT_EXTC GEInt GE_CCALL GE_MESSAGEF_LOGFILE(GELPChar, ...) GE_PRINTF_FORMAT(1, 2);

#define GE_OBSOLETE_METHOD_EX(METHOD, DETAIL) GE_MESSAGEF_WARN("The obsolete method %s was called! %s", METHOD, DETAIL);
#define GE_OBSOLETE_METHOD(DETAIL) GE_OBSOLETE_METHOD_EX(__FUNCTION__, DETAIL)

#define GE_IMPROPER_USAGE_EX(METHOD, DETAIL)                                                                           \
    GE_MESSAGEF_WARN("The method %s detected an improper usage! \nHint:%s ", METHOD, DETAIL);
#define GE_IMPROPER_USAGE(DETAIL) GE_IMPROPER_USAGE_EX(__FUNCTION__, DETAIL)
