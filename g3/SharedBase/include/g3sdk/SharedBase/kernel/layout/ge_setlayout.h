#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCSetLayout
{
    // clang-format off
    protected: virtual void Destroy();
    protected: virtual void Create();
    protected: virtual void CopyFrom(bCSetLayout const &);
    public: virtual GEU16 Read(bCIStream &);
    public: virtual void Write(bCOStream &);
    public: virtual ~bCSetLayout();
    // clang-format on

  public:
    bCSetLayout();

  public:
    bCSetLayout const &operator=(bCSetLayout const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void FillLayout();
    GEBool IsValid() const;

  protected:
    bCSetLayout(bCSetLayout const &);

  protected:
    void CopyTo(bCSetLayout &) const;
    void Invalidate();
};
