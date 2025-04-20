#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCVertexStructArrayBase
{
    // clang-format off
    protected: virtual void __purecall_0() = 0;
    protected: virtual void __purecall_1() = 0;
    protected: virtual void __purecall_2() = 0;
    protected: virtual void __purecall_3() = 0;
    protected: virtual void __purecall_4() = 0;
    protected: virtual void __purecall_5() = 0;
    protected: virtual void __purecall_6() = 0;
    protected: virtual void __purecall_7() = 0;
    protected: virtual void __purecall_8() = 0;
    protected: virtual void __purecall_9() = 0;
    protected: virtual void __purecall_10() = 0;
    protected: virtual void __purecall_11() = 0;
    protected: virtual void __purecall_12() = 0;
    protected: virtual void __purecall_13() = 0;
    protected: virtual void __purecall_14() = 0;
    public: virtual ~eCVertexStructArrayBase();
    // clang-format on

  public:
    eCVertexStructArrayBase(eCVertexStructArrayBase const &);
    eCVertexStructArrayBase();

  public:
    eCVertexStructArrayBase &operator=(eCVertexStructArrayBase const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);
};

bCIStream &GE_STDCALL operator>>(bCIStream &, eCVertexStructArrayBase &);
bCOStream &GE_STDCALL operator<<(bCOStream &, eCVertexStructArrayBase &);
