#include "GameUtil.h"

#include "Memory.h"
#include "Hook.h"

void AddLineToTextBox( bCUnicodeString const & a_strLeftText, bCUnicodeString const & a_strRightText, GELPVoid a_pTextBox )
{
    typedef void ( GE_STDCALL * mFAddLineToTextBox )( bCUnicodeString const & a_strLeftText, bCUnicodeString const & a_strRightText );
    static mCCaller Call_AddLineToTextBox( mCCaller::GetCallerParams( RVA_Game( 0xA5030 ), mCRegisterBase::mERegisterType_Eax ) );

    Call_AddLineToTextBox.SetEax( a_pTextBox );
    Call_AddLineToTextBox.GetFunction<mFAddLineToTextBox>()( a_strLeftText, a_strRightText );
}
