#include "GameUtil.h"

#include <g3sdk/util/Hook.h>
#include <g3sdk/util/Memory.h>

void AddLineToTextBox(bCUnicodeString const &a_strLeftText, bCUnicodeString const &a_strRightText, GELPVoid a_pTextBox)
{
    using mFAddLineToTextBox =
        void(GE_STDCALL *)(bCUnicodeString const &a_strLeftText, bCUnicodeString const &a_strRightText);
    static mCCaller Call_AddLineToTextBox(mCCaller::GetCallerParams(RVA_Game(0xA5030), mERegisterType_Eax));

    Call_AddLineToTextBox.SetEax(a_pTextBox);
    Call_AddLineToTextBox.GetFunction<mFAddLineToTextBox>()(a_strLeftText, a_strRightText);
}
