#pragma once

#define __GE_PASTE_TOKENS(A, B) A##B
#define _GE_PASTE_TOKENS(A, B) __GE_PASTE_TOKENS(A, B)
#define GE_PASTE_TOKENS(A, B) _GE_PASTE_TOKENS(A, B)

#define GE_PADDING(X) [[maybe_unused]] char GE_PASTE_TOKENS(__padding, __LINE__)[X];

#define GE_FORCE_DWORD 0x7FFFFFFFL

#define GE_UNREFERENCED_PARAMETER(P) (P)
#define GE_NORETURN __declspec(noreturn)
#define GE_FORCE_INLINE __forceinline

#define GE_CCALL __cdecl
#define GE_STDCALL __stdcall
#define GE_FASTCALL __fastcall

#define GE_DLLIMPORT __declspec(dllimport)
#define GE_DLLIMPORT_EXTC extern "C" GE_DLLIMPORT
#define GE_DLLIMPORT_DATA extern "C++" GE_DLLIMPORT
#define GE_NO_DLLIMPORT template <typename NO_DLLIMPORT = void>
#define GE_THREAD_LOCAL __declspec(thread)

namespace Genome
{
template <bool match>
struct SIZEOF_ASSERTION;
template <>
struct SIZEOF_ASSERTION<true>
{
    enum
    {
        value = 1
    };
};

template <bool match, typename T, int expected, int actual, int diff>
struct SIZEOF_ASSERTION_EQUALS;
template <typename T, int expected, int actual, int diff>
struct SIZEOF_ASSERTION_EQUALS<true, T, expected, actual, diff>
{
    enum
    {
        value = 1
    };
};

template <int x>
struct sizeof_test
{};

template <typename T>
struct remove_reference
{
    using type = T;
};
template <typename T>
struct remove_reference<T &>
{
    using type = T;
};
template <typename T>
struct remove_reference<T &&>
{
    using type = T;
};
template <typename T>
using remove_reference_t = typename remove_reference<T>::type;

} // namespace Genome

#define GE_STATIC_ASSERT(EXPR)                                                                                         \
    using GE_PASTE_TOKENS(Genome_sizeof_, __COUNTER__) =                                                               \
        ::Genome::sizeof_test<sizeof(::Genome::SIZEOF_ASSERTION<!!(EXPR)>)>;

#define GE_STATIC_ASSERT_EQUALS(TYPE, ACTUAL, EXPECTED)                                                                \
    using GE_PASTE_TOKENS(Genome_sizeof_, __COUNTER__) =                                                               \
        ::Genome::sizeof_test<sizeof(::Genome::SIZEOF_ASSERTION_EQUALS < ACTUAL == (EXPECTED), TYPE, EXPECTED, ACTUAL, \
                                     ((int)(EXPECTED) - (int)ACTUAL) >)>;
#define GE_ASSERT_SIZEOF(TYPE, SIZE) GE_STATIC_ASSERT_EQUALS(TYPE, sizeof(TYPE), SIZE);

#define GE_STATIC_BLOCK _GE_STATIC_BLOCK(GE_PASTE_TOKENS(_static_block_, __COUNTER__))
#define _GE_STATIC_BLOCK(prefix) __GE_STATIC_BLOCK(GE_PASTE_TOKENS(prefix, _fn), GE_PASTE_TOKENS(prefix, _var))
#define __GE_STATIC_BLOCK(FUNC_NAME, VAR_NAME)                                                                         \
    static void FUNC_NAME();                                                                                           \
    static int VAR_NAME = (FUNC_NAME(), 0);                                                                            \
    static void FUNC_NAME()

#define GE_UNIMPL_STRUCT(TYPE)                                                                                         \
    TYPE() = delete;                                                                                                   \
    TYPE(const TYPE &) = delete;                                                                                       \
    TYPE &operator=(const TYPE &) = delete;

#define GE_UNIMPL_MEMBERS(SIZE) GE_PADDING(SIZE)

template <typename T, typename F>
T force_cast(F From)
{
    GE_ASSERT_SIZEOF(T, sizeof(F));
    return *reinterpret_cast<T *>(&From);
}

template <typename T, typename F>
T offset_cast(F From, unsigned long Offset)
{
    GE_ASSERT_SIZEOF(T, sizeof(F));
    return reinterpret_cast<T>(reinterpret_cast<unsigned long>(From) + Offset);
}
