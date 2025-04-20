#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;

enum bEInterpolator
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT bCInterpolatorBase
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
    // clang-format on

  public:
    bCInterpolatorBase();
    ~bCInterpolatorBase();

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    GEInt GetFrameBegin() const;
    void GetFrameBegin(GEInt &) const;
    GEInt GetFrameCount() const;
    void GetFrameCount(GEInt &) const;
    GEInt GetFrameEnd() const;
    void GetFrameEnd(GEInt &) const;
    bEInterpolator GetType() const;
    void GetType(bEInterpolator &) const;
    void SetFrameBegin(GEInt);
    void SetFrameEnd(GEInt);

  protected:
    bCInterpolatorBase(bCInterpolatorBase const &);

  protected:
    bCInterpolatorBase const &operator=(bCInterpolatorBase const &);

  protected:
    GEInt &AccessFrameBegin();
    GEInt &AccessFrameEnd();
    bEInterpolator &AccessType();
    void SetType(bEInterpolator);
};
