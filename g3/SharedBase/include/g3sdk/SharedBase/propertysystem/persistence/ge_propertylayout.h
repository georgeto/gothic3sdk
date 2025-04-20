#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;
class bCPropertyTypeBase;

class GE_DLLIMPORT bCPropertyLayout
{
    // clang-format off
    protected: virtual void Destroy();
    protected: virtual void Create();
    protected: virtual void CopyFrom(bCPropertyLayout const &);
    public: virtual GEU16 Read(bCIStream &);
    public: virtual void Write(bCOStream &);
    public: virtual ~bCPropertyLayout();
    // clang-format on

  public:
    bCPropertyLayout();

  public:
    bCPropertyLayout const &operator=(bCPropertyLayout const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void AssignPropertyType(bCPropertyTypeBase const *);
    GEBool IsValid() const;

  protected:
    bCPropertyLayout(bCPropertyLayout const &);

  protected:
    void CopyTo(bCPropertyLayout &) const;
    void Invalidate();
};
