#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;
class bCPropertyObjectTypeBase;

class GE_DLLIMPORT bCClassLayout
{
    // clang-format off
    protected: virtual void Destroy();
    protected: virtual void Create();
    protected: virtual void CopyFrom(bCClassLayout const &);
    public: virtual GEU16 Read(bCIStream &);
    public: virtual void Write(bCOStream &);
    public: virtual ~bCClassLayout();
    // clang-format on

  public:
    bCClassLayout();

  public:
    bCClassLayout const &operator=(bCClassLayout const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void AssignPropertyObjectType(bCPropertyObjectTypeBase const *);
    GEBool IsValid() const;

  protected:
    bCClassLayout(bCClassLayout const &);

  protected:
    void CopyTo(bCClassLayout &) const;
    void FillLayout();
    void Invalidate();
};
