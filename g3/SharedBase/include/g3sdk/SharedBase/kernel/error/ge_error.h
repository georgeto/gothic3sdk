#pragma once

#include <SharedBase/kernel/error/ge_erroradmin.h>

#define GE_FATAL_ERROR(MODULE) bCErrorAdmin::GetInstance().CallFatalError(MODULE, __FILE__, __LINE__);
#define GE_FATAL_ERROR_EX(MODULE, DETAIL)                                                                              \
    bCErrorAdmin::GetInstance().CallFatalError(MODULE, DETAIL, __FILE__, __LINE__);
#define GE_FAULT_ERROR(MODULE) bCErrorAdmin::GetInstance().CallFaultError(MODULE, __FILE__, __LINE__);
#define GE_FAULT_ERROR_EX(MODULE, DETAIL)                                                                              \
    bCErrorAdmin::GetInstance().CallFaultError(MODULE, DETAIL, __FILE__, __LINE__);
