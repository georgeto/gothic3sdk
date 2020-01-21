#ifndef HOOK_H_INCLUDED
#define HOOK_H_INCLUDED

#include "AsmjitUtil.h"

#include "SharedBase.h"

class mCRestorable
{
    public:
                 mCRestorable( void );
        virtual ~mCRestorable();

    protected:
        void Backup(GELPVoid a_pAddress, GEUInt a_uDataSize);
        void Restore();
        void ApplyAsm(asmjit::X86CodeAsm& a_Assembler, GEUInt a_u32ReplaceSize);

    private:
        struct mSBackupItem
        {
            GELPVoid m_pOriginalAddress;
            GELPVoid m_pOriginalData;
            GEUInt m_uOriginalDataSize;
        };
        bTObjArray<mSBackupItem> m_arrBackupItems;
};

class mCDataPatch :
    public mCRestorable
{
    public:
        template<typename T>
        mCDataPatch(GEU32 a_uDataAddress, T const & a_NewData);
        mCDataPatch(GEU32 a_uDataAddress, GELPCVoid a_pNewData, GEU32 a_uSize);

    private:
        void Patch(GEU32 a_uDataAddress, GELPCVoid a_pNewData, GEU32 a_uSize);
};

#define CODE_PATCH \
  [](asmjit::X86CodeAsm & Asm) \
    { \
        using namespace asmjit; \
        using namespace asmjit::x86;


class mCCodePatch :
    public mCRestorable
{
    public:
        typedef void (*mFCodeSupplier)( asmjit::X86CodeAsm & );

    public:
        mCCodePatch(GEU32 a_uAddress, GEU32 a_uReplaceSize, mFCodeSupplier a_CodeSupplier);

    private:
        void Patch(GEU32 a_uAddress, GEU32 a_uReplaceSize, mFCodeSupplier a_CodeSupplier);
};

class mCSkipCode :
    public mCRestorable
{
    public:
        mCSkipCode(GEU32 a_uAddress, GEU32 a_uSize);
};

class mCRegisterBase
{
    public:
        enum mERegisterType
        {
            mERegisterType_None = 0,
            mERegisterType_Eax  = 1,
            mERegisterType_Ecx  = 2,
            mERegisterType_Edx  = 4,
            mERegisterType_Ebx  = 8,
            mERegisterType_Ebp  = 16,
            mERegisterType_Esi  = 32,
            mERegisterType_Edi  = 64
        };

    public:
        mCRegisterBase( void );

    public:
        template< typename T > T      GetEax();
        template< typename T > T      GetEcx();
        template< typename T > T      GetEdx();
        template< typename T > T      GetEbx();
        template< typename T > T      GetEbp();
        template< typename T > T      GetEsi();
        template< typename T > T      GetEdi();
        template< typename T > T      GetImmEax();
        template< typename T > T      GetImmEcx();
        template< typename T > T      GetImmEdx();
        template< typename T > T      GetImmEbx();
        template< typename T > T      GetImmEbp();
        template< typename T > T      GetImmEsi();
        template< typename T > T      GetImmEdi();
        template< typename T > void   SetEax( T a_Eax );
        template< typename T > void   SetEcx( T a_Ecx );
        template< typename T > void   SetEdx( T a_Edx );
        template< typename T > void   SetEbx( T a_Ebx );
        template< typename T > void   SetEbp( T a_Ebp );
        template< typename T > void   SetEsi( T a_Esi );
        template< typename T > void   SetEdi( T a_Edi );
        template< typename T > void   SetImmEax( T a_Eax );
        template< typename T > void   SetImmEcx( T a_Ecx );
        template< typename T > void   SetImmEdx( T a_Edx );
        template< typename T > void   SetImmEbx( T a_Ebx );
        template< typename T > void   SetImmEbp( T a_Ebp );
        template< typename T > void   SetImmEsi( T a_Esi );
        template< typename T > void   SetImmEdi( T a_Edi );

    protected:
        GEU32    m_u32Eax;
        GEU32    m_u32Ecx;
        GEU32    m_u32Edx;
        GEU32    m_u32Ebx;
        GEU32    m_u32Ebp;
        GEU32    m_u32Esi;
        GEU32    m_u32Edi;
        GEU32    m_u32EbxRestore;
        GEU32    m_u32EbpRestore;
        GEU32    m_u32EsiRestore;
        GEU32    m_u32EdiRestore;

    private:
        mCRegisterBase( mCRegisterBase const & );

    private:
        mCRegisterBase & operator = ( mCRegisterBase const & );
};

inline mCRegisterBase::mERegisterType operator | ( mCRegisterBase::mERegisterType lhs, mCRegisterBase::mERegisterType rhs )
{
    return static_cast< mCRegisterBase::mERegisterType >( static_cast< GEInt >( lhs ) | static_cast< GEInt >( rhs ) );
};

#define HOOK_NAME( NAME ) \
        Hook_ ## NAME

#define HOOK_CLASS_NAME( CLASS, NAME ) \
        Hook_ ## CLASS ## __ ## NAME

#define DEFINE_HOOK_FUNCTION_HEADER( NAME, RETURN_TYPE, SIGNATURE ) \
        mCFunctionHook HOOK_NAME(NAME); \
        RETURN_TYPE GE_STDCALL NAME SIGNATURE { \
            mCFunctionHook & HookInstance = HOOK_NAME(NAME); \
            GE_UNREFERENCED_PARAMETER(HookInstance); \
            typedef RETURN_TYPE (*mFOriginalFunction) SIGNATURE; \

#define HOOK_FUNCTION( NAME, RETURN_TYPE, SIGNATURE, ... ) \
        DEFINE_HOOK_FUNCTION_HEADER(NAME, RETURN_TYPE, SIGNATURE) \
            __VA_ARGS__ \
        }

#define HOOK_CLASS_FUNCTION( THIS_TYPE, NAME, RETURN_TYPE, SIGNATURE, ... ) \
        HOOK_FUNCTION( THIS_TYPE ## __ ## NAME, RETURN_TYPE, SIGNATURE, __VA_ARGS__)

#define HOOK_FUNCTION_THISCALL( THIS_TYPE, NAME, RETURN_TYPE, SIGNATURE, ... ) \
        DEFINE_HOOK_FUNCTION_HEADER( THIS_TYPE ## __ ## NAME , RETURN_TYPE, SIGNATURE ) \
            THIS_TYPE * This = Hook_ ## THIS_TYPE ## __ ## NAME.GetSelf<THIS_TYPE *>(); \
            __VA_ARGS__ \
        }

#define CALL_ORIGINAL_FUNCTION(...) \
            HookInstance.GetOriginalFunction<mFOriginalFunction>()(__VA_ARGS__)

class mCBaseHook :
    public mCRestorable,
    public mCRegisterBase
{
    public:
        enum mEHookType
        {
            mEHookType_OnlyStack,
            mEHookType_ThisCall,
            mEHookType_Mixed
        };

    public:
        class mCHookParams
        {
            protected:
                friend class mCBaseHook;
                GELPVoid       m_pOriginalFunc;
                GELPVoid       m_pNewFunc;
                mEHookType     m_HookType;
                mERegisterType m_RegisterType;
        };

        template< typename P, typename H >
        class mCHookInstanceBuilder
        {
            public:
                inline GEBool Hook() const { return m_pHook->Hook(*static_cast<P const *>(this)); };

            protected:
                friend H;
                H * m_pHook;
        };

    public:
        mCBaseHook( void );

    public:
        template< typename T > static T GetLastSelf();

    public:
        inline                 GEBool IsValid() const { return m_pCode != 0; };
        template< typename T > T      GetOriginalFunction( void ) const;
        template< typename T > T      GetOriginalFunction( T ) const;
        template< typename T > T      GetSelf() const;
        template< typename T > void   SetSelf( T a_Self );

    protected:
        static const GEU32 JMP_SIZE = 5;
        static const GEU32 CALL_SIZE = 5;

    protected:
        GELPVoid DoRegisterMagic( mCHookParams const & a_HookParams );

    protected:
        GELPVoid m_pSelf;
        GELPVoid m_pCode;
        GEU32    m_u32Ret;

    private:
        static GELPVoid m_pLastSelf;

    private:
        mCBaseHook( mCBaseHook const & );

    private:
        mCBaseHook & operator = ( mCBaseHook const & );
};

#define ME_DECLARE_HOOK_BUILDER_BASE( CLASS ) \
    template<typename T>                      \
    class CLASS ## BuilderBase :              \
        public CLASS ## Params

#define ME_DECLARE_HOOK_BUILDER( CLASS )                              \
    class CLASS ## Builder :                                          \
        public CLASS ## BuilderBase<CLASS ## Builder>                 \
    {                                                                 \
    };                                                                \
                                                                      \
    class CLASS ## InstanceBuilder :                                  \
        public CLASS ## BuilderBase<CLASS ## InstanceBuilder>,        \
        public mCHookInstanceBuilder<CLASS ## InstanceBuilder, CLASS> \
    {                                                                 \
    };


class mCFunctionHook :
    public mCBaseHook
{
    public:
        class mCFunctionHookParams :
            public mCHookParams
        {
            protected:
                friend class mCFunctionHook;
                GEBool m_bTransparent = GEFalse;
        };

        ME_DECLARE_HOOK_BUILDER_BASE( mCFunctionHook )
        {
            public:
                // A 'transparent' hook disables itself on entering.
                // Therefore calling the hooked function from inside the hook is possible without using GetOriginalFunction.
                // NOTE: 'transparent' hooks can only be used in combination with the hook types OnlyStack or ThisCall.
                inline T & Transparent() { m_bTransparent = GETrue; return *static_cast<T *>(this); }
        };

        ME_DECLARE_HOOK_BUILDER( mCFunctionHook );

    public:
        mCFunctionHook( void );

    public:
        template< typename O, typename N>
        static mCFunctionHookBuilder PrepareParams( O a_pOriginalFunc, N a_pNewFunc, mEHookType a_HookType = mEHookType_OnlyStack, mERegisterType a_RegisterType = mERegisterType_None );

        template< typename O, typename N >
        mCFunctionHookInstanceBuilder Prepare( O a_pOriginalFunc, N a_pNewFunc, mEHookType a_HookType = mEHookType_OnlyStack, mERegisterType a_RegisterType = mERegisterType_None );

        template< typename O, typename N >
        inline GEBool Hook( O a_pOriginalFunc, N a_pNewFunc, mEHookType a_HookType = mEHookType_OnlyStack, mERegisterType a_RegisterType = mERegisterType_None );

        GEBool Hook( mCFunctionHookParams const & a_HookParams );

    protected:
        GEBool HookInternal(mCFunctionHookParams const & a_HookParams, asmjit::X86CodeAsm& a_pAssembler, GEUInt a_u32RelocateSize);

    private:
        GEBool m_bInside;
        GEU32 m_u32HookRet;

    private:
        mCFunctionHook( mCFunctionHook const & );

    private:
        mCFunctionHook & operator = ( mCFunctionHook const & );
};

class mCVtableHook :
    public mCBaseHook
{
    public:
        class mCVtableHookParams
            : mCHookParams
        {
            protected:
                friend class mCVtableHook;
        };

    public:
        mCVtableHook( void );
        mCVtableHook( mCVtableHookParams const & a_HookParams );

        template< typename O, typename N >
        mCVtableHook( O a_pVtable, GEU32 a_u32Offset, N a_pNewFunc );

    public:
        template< typename O, typename N >
        static mCVtableHookParams PrepareParams( O a_pVtable, GEU32 a_u32Offset, N a_pNewFunc );

        template< typename O, typename N >
        GEBool Hook( O a_pVtable, GEU32 a_u32Offset, N a_pNewFunc );

        GEBool Hook( mCVtableHookParams const & a_HookParams );

    private:
        mCVtableHook( mCVtableHook const & );

    private:
        mCVtableHook & operator = ( mCVtableHook const & );
};

class mCCallHook :
    public mCBaseHook
{
    public:
        class mCCallHookParams :
            public mCHookParams
        {
            public:
                enum mEArgType
                {
                    mEArgType_RegDirect,
                    mEArgType_RegIndirect,
                    mEArgType_Immediate
                };

                struct mSRegRelativeArg
                {
                    mERegisterType m_Register;
                    union {
                        GEU32 m_u32Offset;
                        GEU32 m_u32Immediate;
                    };
                    mEArgType m_enuArgType;
                };

            protected:
                friend class mCCallHook;
                GEU32 m_u32CallAdr;
                bTObjArray<mSRegRelativeArg> m_arrStackArgs;
                GEBool m_bInsertCall = GEFalse;
                GEBool m_bExplicitSize = GEFalse;
                GEUInt m_uCallSize = 0;
                GEUInt m_uMinRelocateSize = 0;
                GEUInt m_uMaxRelocateSize = 0;
                GEBool m_bVariableReturnAddress = GEFalse;
                GEBool m_bRestoreRegister = GEFalse;
                GEBool m_bTestOnReturn = GEFalse;
        };

        ME_DECLARE_HOOK_BUILDER_BASE( mCCallHook )
        {
            public:
                // Registers are passed in left-to-right order
                inline T & AddStackArg( GEU32 a_u32Offset, mERegisterType a_RegisterType = mERegisterType_None, GEBool a_bIndirect = GEFalse )
                {
                    mSRegRelativeArg Arg = { a_RegisterType, a_u32Offset, a_bIndirect ? mEArgType_RegIndirect : mEArgType_RegDirect };
                    m_arrStackArgs.Add( Arg );
                    return *static_cast<T *>(this);
                };

                inline T & AddStackArgEbp( GEU32 a_u32Offset )
                {
                    return AddStackArg( a_u32Offset, mERegisterType_Ebp );
                };

                inline T & AddStackArgReg( mERegisterType a_RegisterType )
                {
                    return AddStackArg( 0, a_RegisterType );
                };

                inline T & AddPtrStackArg( GEU32 a_u32Offset, mERegisterType a_RegisterType = mERegisterType_None )
                {
                    return AddStackArg( a_u32Offset, a_RegisterType, GETrue );
                };

                inline T & AddPtrStackArgEbp( GEU32 a_u32Offset )
                {
                    return AddStackArg( a_u32Offset, mERegisterType_Ebp, GETrue );
                };

                inline T & AddRegArg( mERegisterType a_RegisterType )
                {
                    return AddStackArg( 0, a_RegisterType );
                };

                inline T & AddPtrRegArg( mERegisterType a_RegisterType )
                {
                    return AddPtrStackArg( 0, a_RegisterType );
                };

                template<typename T>
                inline T & AddImmArg( T a_ImmediateValue )
                {
                    GE_ASSERT_SIZEOF( a_ImmediateValue, sizeof( GEU32 ) );
                    mSRegRelativeArg Arg = { a_RegisterType, reinterpret_cast<GEU32>( a_ImmediateValue ), mEArgType_Immediate };
                    m_arrStackArgs.Add( Arg );
                    return *static_cast<T *>(this);
                };

                inline T & AddThisArg()
                {
                    return AddStackArg( 0, mERegisterType_Ecx );
                };

                inline T & InsertCall()
                {
                    m_bInsertCall = GETrue;
                    return *static_cast<T *>(this);
                };

                inline T & ReplaceSize( GEUInt a_uReplaceSize )
                {
                    m_bExplicitSize = GETrue;
                    m_uCallSize = a_uReplaceSize;
                    m_uMinRelocateSize = a_uReplaceSize < CALL_SIZE ? CALL_SIZE - a_uReplaceSize : 0;
                    m_uMaxRelocateSize = 0;
                    return *static_cast<T *>(this);
                };

                inline T & ExplicitSize( GEUInt a_uCallSize, GEUInt a_uRelocateSize )
                {
                    m_bExplicitSize = GETrue;
                    m_uCallSize = a_uCallSize;
                    m_uMinRelocateSize = m_uMaxRelocateSize = a_uRelocateSize;
                    return *static_cast<T *>(this);
                };

                inline T & VariableReturnAddress()
                {
                    m_bVariableReturnAddress = GETrue;
                    return *static_cast<T *>(this);
                };

                inline T & RestoreRegister()
                {
                    m_bRestoreRegister = GETrue;
                    return *static_cast<T *>(this);
                };

                inline T & TestOnReturn()
                {
                    m_bTestOnReturn = GETrue;
                    return *static_cast<T *>(this);
                };

                template< typename O >
                inline T & OriginalFunction( O a_pOriginalFunc )
                {
                    GE_ASSERT_SIZEOF(O, sizeof(GELPVoid))
                    m_pOriginalFunc = *reinterpret_cast< GELPVoid * >(&a_pOriginalFunc);
                    return *static_cast<T *>(this);
                }
        };

        ME_DECLARE_HOOK_BUILDER( mCCallHook );

    public:
        mCCallHook( void );

        template< typename N >
        mCCallHook( GEU32 a_u32CallAdr, N a_pNewFunc, mEHookType a_HookType = mEHookType_OnlyStack, mERegisterType a_RegisterType = mERegisterType_None );

        // Beware of the static initialization order fiasco, which will occur, if this constructor (or the Hook method) is called, before the static initialization of AsmJit.
        mCCallHook( mCCallHookParams const & a_HookParams );

    public:
        inline GEU32  GetReturnAddress() { return m_u32CallReturnAdr; };
        // Relocated instructions are not executed, when the return address was changed.
        inline void   SetReturnAddress( GEU32 a_u32ReturnAddress ) { m_u32CallReturnAdr = a_u32ReturnAddress; };

    public:
        template< typename N >
        static mCCallHookBuilder PrepareParams( GEU32 a_u32CallAdr, N a_pNewFunc, mEHookType a_HookType = mEHookType_OnlyStack, mERegisterType a_RegisterType = mERegisterType_None );

        template< typename N >
        mCCallHookInstanceBuilder Prepare( GEU32 a_u32CallAdr, N a_pNewFunc, mEHookType a_HookType = mEHookType_OnlyStack, mERegisterType a_RegisterType = mERegisterType_None );

        template< typename N >
        GEBool Hook( GEU32 a_u32CallAdr, N a_pNewFunc, mEHookType a_HookType = mEHookType_OnlyStack, mERegisterType a_RegisterType = mERegisterType_None );

        GEBool Hook( mCCallHookParams const & a_HookParams );

    public:
        void Disable();

    private:
        GEBool HookInternal( mCCallHookParams const & a_HookParams );

    private:
        mCCallHook( mCCallHook const & );

    private:
        mCCallHook & operator = ( mCCallHook const & );

    private:
        GEU32 m_u32CallReturnAdr;
};

class mCCaller :
    public mCRegisterBase
{
    public:
        struct mSCallerParams
        {
            GELPVoid       m_u32FunctionAdr;
            mERegisterType m_RegisterType;
        };

    public:
        mCCaller( void );
        mCCaller( mSCallerParams const & a_CallerParams );

    public:
        template< typename N > static mSCallerParams GetCallerParams( N a_u32FunctionAdr, mERegisterType a_RegisterType );

    public:
        template< typename T > T      GetFunction( void );
        template< typename T > T      GetFunction( T );
                               GEBool Init( mSCallerParams const & a_CallerParams );

    protected:
        GELPVoid m_pFunction;
        GEU32    m_u32Ret;

    private:
        mCCaller( mCCaller const & );

    private:
        mCCaller & operator = ( mCCaller const & );
};

template<typename T>
mCDataPatch::mCDataPatch(GEU32 a_uDataAddress, T const & a_NewData)
{
    Patch(a_uDataAddress, &a_NewData, sizeof(a_NewData));
}

template< typename T >
T mCBaseHook::GetOriginalFunction( void ) const
{
    GE_ASSERT_SIZEOF(T, sizeof(GELPVoid));
    return reinterpret_cast< T >(m_pCode);
}


template< typename T >
T mCBaseHook::GetOriginalFunction( T ) const
{
    GE_ASSERT_SIZEOF(T, sizeof(GELPVoid));
    return reinterpret_cast< T >(m_pCode);
}

template< typename T >
T mCBaseHook::GetSelf() const
{
    GE_ASSERT_SIZEOF(T, sizeof(GELPVoid));
    return reinterpret_cast< T >(m_pSelf);
}

template< typename T >
T mCCaller::GetFunction()
{
    GE_ASSERT_SIZEOF(T, sizeof(GELPVoid));
    return reinterpret_cast< T >(m_pFunction);
}

template< typename T >
T mCCaller::GetFunction( T )
{
    GE_ASSERT_SIZEOF(T, sizeof(GELPVoid));
    return reinterpret_cast< T >(m_pFunction);
}

template< typename T >
T mCRegisterBase::GetEax()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return reinterpret_cast< T >(m_u32Eax);
}

template< typename T >
T mCRegisterBase::GetEcx()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return reinterpret_cast< T >(m_u32Ecx);
}

template< typename T >
T mCRegisterBase::GetEdx()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return reinterpret_cast< T >(m_u32Edx);
}

template< typename T >
T mCRegisterBase::GetEbx()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return reinterpret_cast< T >(m_u32Ebx);
}

template< typename T >
T mCRegisterBase::GetEbp()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return reinterpret_cast< T >(m_u32Ebp);
}

template< typename T >
T mCRegisterBase::GetEsi()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return reinterpret_cast< T >(m_u32Esi);
}

template< typename T >
T mCRegisterBase::GetEdi()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return reinterpret_cast< T >(m_u32Edi);
}

template< typename T >
T mCRegisterBase::GetImmEax()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return static_cast< T >(m_u32Eax);
}

template< typename T >
T mCRegisterBase::GetImmEcx()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return static_cast< T >(m_u32Ecx);
}

template< typename T >
T mCRegisterBase::GetImmEdx()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return static_cast< T >(m_u32Edx);
}

template< typename T >
T mCRegisterBase::GetImmEbx()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return static_cast< T >(m_u32Ebx);
}

template< typename T >
T mCRegisterBase::GetImmEbp()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return static_cast< T >(m_u32Ebp);
}

template< typename T >
T mCRegisterBase::GetImmEsi()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return static_cast< T >(m_u32Esi);
}

template< typename T >
T mCRegisterBase::GetImmEdi()
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    return static_cast< T >(m_u32Edi);
}

template< typename T >
void mCBaseHook::SetSelf(T a_Self)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_pSelf = reinterpret_cast< GELPVoid >(a_Self);
}

template< typename T >
void mCRegisterBase::SetEax(T a_Eax)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Eax = reinterpret_cast< GEU32 >(a_Eax);
}

template< typename T >
void mCRegisterBase::SetEcx(T a_Ecx)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Ecx = reinterpret_cast< GEU32 >(a_Ecx);
}

template< typename T >
void mCRegisterBase::SetEdx(T a_Edx)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Edx = reinterpret_cast< GEU32 >(a_Edx);
}

template< typename T >
void mCRegisterBase::SetEbx(T a_Ebx)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Ebx = reinterpret_cast< GEU32 >(a_Ebx);
}

template< typename T >
void mCRegisterBase::SetEbp(T a_Ebp)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Ebp = reinterpret_cast< GEU32 >(a_Ebp);
}

template< typename T >
void mCRegisterBase::SetEsi(T a_Esi)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Esi = reinterpret_cast< GEU32 >(a_Esi);
}

template< typename T >
void mCRegisterBase::SetEdi(T a_Edi)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Edi = reinterpret_cast< GEU32 >(a_Edi);
}

template< typename T >
void mCRegisterBase::SetImmEax(T a_Eax)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Eax = static_cast< GEU32 >(a_Eax);
}

template< typename T >
void mCRegisterBase::SetImmEcx(T a_Ecx)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Ecx = static_cast< GEU32 >(a_Ecx);
}

template< typename T >
void mCRegisterBase::SetImmEdx(T a_Edx)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Edx = static_cast< GEU32 >(a_Edx);
}

template< typename T >
void mCRegisterBase::SetImmEbx(T a_Ebx)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Ebx = static_cast< GEU32 >(a_Ebx);
}

template< typename T >
void mCRegisterBase::SetImmEbp(T a_Ebp)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Ebp = static_cast< GEU32 >(a_Ebp);
}

template< typename T >
void mCRegisterBase::SetImmEsi(T a_Esi)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Esi = static_cast< GEU32 >(a_Esi);
}

template< typename T >
void mCRegisterBase::SetImmEdi(T a_Edi)
{
    GE_ASSERT_SIZEOF(T, sizeof(GEU32));
    m_u32Edi = static_cast< GEU32 >(a_Edi);
}

template< typename O, typename N>
mCFunctionHook::mCFunctionHookBuilder mCFunctionHook::PrepareParams( O a_pOriginalFunc, N a_pNewFunc, mEHookType a_HookType, mERegisterType a_RegisterType )
{
    GE_ASSERT_SIZEOF(O, sizeof(GELPVoid))
    GE_ASSERT_SIZEOF(N, sizeof(GELPVoid))
    mCFunctionHookBuilder Params;
    Params.m_pOriginalFunc = *reinterpret_cast< GELPVoid * >(&a_pOriginalFunc);
    Params.m_pNewFunc = *reinterpret_cast< GELPVoid * >(&a_pNewFunc);
    Params.m_HookType = a_HookType;
    Params.m_RegisterType = a_RegisterType;
    return Params;
}

template< typename O, typename N>
mCFunctionHook::mCFunctionHookInstanceBuilder mCFunctionHook::Prepare( O a_pOriginalFunc, N a_pNewFunc, mEHookType a_HookType, mERegisterType a_RegisterType )
{
    mCFunctionHookInstanceBuilder Params;
    *static_cast<mCFunctionHookParams *>(&Params) = PrepareParams(a_pOriginalFunc, a_pNewFunc, a_HookType, a_RegisterType);
    Params.m_pHook = this;
    return Params;
}

template< typename O, typename N >
GEBool mCFunctionHook::Hook( O a_pOriginalFunc, N a_pNewFunc, mEHookType a_HookType, mERegisterType a_RegisterType )
{
    return Prepare(a_pOriginalFunc, a_pNewFunc, a_HookType, a_RegisterType).Hook();
}

template< typename O, typename N >
mCVtableHook::mCVtableHookParams mCVtableHook::PrepareParams( O a_pVtable, GEU32 a_u32Offset, N a_pNewFunc )
{
    GE_ASSERT_SIZEOF(O, sizeof(GELPVoid))
    GE_ASSERT_SIZEOF(N, sizeof(GELPVoid))
    mCVtableHook::mCVtableHookParams Params;
    Params.m_pOriginalFunc = *reinterpret_cast< GELPChar * >(&a_pVtable) + a_u32Offset;
    Params.m_pNewFunc = *reinterpret_cast< GELPVoid * >(&a_pNewFunc);
    Params.m_HookType = mEHookType_ThisCall;
    Params.m_RegisterType = mERegisterType_None;
    return Params;
}

template< typename O, typename N >
GEBool mCVtableHook::Hook( O a_pVtable, GEU32 a_u32Offset, N a_pNewFunc )
{
    return Hook(PrepareParams(a_pVtable, a_u32Offset, a_pNewFunc));
}

template< typename N >
mCCallHook::mCCallHook( GEU32 a_u32CallAdr, N a_pNewFunc, mEHookType a_HookType, mERegisterType a_RegisterType )
    : mCCallHook()
{
    Hook(a_u32CallAdr, a_pNewFunc, a_HookType, a_RegisterType);
}

template< typename N >
mCCallHook::mCCallHookBuilder mCCallHook::PrepareParams( GEU32 a_u32CallAdr, N a_pNewFunc, mEHookType a_HookType, mERegisterType a_RegisterType )
{
    GE_ASSERT_SIZEOF(N, sizeof(GELPVoid))
    mCCallHook::mCCallHookBuilder Params;
    Params.m_u32CallAdr = a_u32CallAdr;
    Params.m_pOriginalFunc = 0;
    Params.m_pNewFunc = *reinterpret_cast< GELPVoid * >(&a_pNewFunc);
    Params.m_HookType = a_HookType;
    Params.m_RegisterType = a_RegisterType;
    return Params;
}

template< typename N >
mCCallHook::mCCallHookInstanceBuilder mCCallHook::Prepare( GEU32 a_u32CallAdr, N a_pNewFunc, mEHookType a_HookType, mERegisterType a_RegisterType )
{
    mCCallHookInstanceBuilder Params;
    *static_cast<mCCallHookParams *>(&Params) = PrepareParams(a_u32CallAdr, a_pNewFunc, a_HookType, a_RegisterType);
    Params.m_pHook = this;
    return Params;
}

template< typename N >
GEBool mCCallHook::Hook( GEU32 a_u32CallAdr, N a_pNewFunc, mEHookType a_HookType, mERegisterType a_RegisterType )
{
    return Prepare(a_u32CallAdr, a_pNewFunc, a_HookType, a_RegisterType).Hook();
}

template< typename T >
T mCBaseHook::GetLastSelf()
{
    GE_ASSERT_SIZEOF(T, sizeof(GELPVoid))
    return reinterpret_cast<T>(m_pLastSelf);
}


template< typename N >
mCCaller::mSCallerParams mCCaller::GetCallerParams(N a_u32FunctionAdr, mERegisterType a_RegisterType)
{
    GE_ASSERT_SIZEOF(N, sizeof(GELPVoid))
    mCCaller::mSCallerParams Params;
    Params.m_u32FunctionAdr = *reinterpret_cast< GELPVoid * >(&a_u32FunctionAdr);
    Params.m_RegisterType = a_RegisterType;
    return Params;
}


#endif