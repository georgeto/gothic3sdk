#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCPropertyID;
class bCPropertyObjectBase;
class bCPropertyObjectFactory;
class bCString;

class GE_DLLIMPORT bCAccessorCreator
{
  public:
    bCAccessorCreator(bCAccessorCreator const &);
    bCAccessorCreator(bCPropertyID const &, bCString const *);
    explicit bCAccessorCreator(bCString const &);
    explicit bCAccessorCreator(bCPropertyObjectBase *);
    ~bCAccessorCreator();

  public:
    explicit operator bCPropertyObjectBase *();
    explicit operator bCPropertyObjectBase const *() const;
    bCAccessorCreator const &operator=(bCAccessorCreator const &);
    bCPropertyObjectBase *operator->();
    bCPropertyObjectBase const *operator->() const;

  public:
    bCAccessorCreator Clone() const;
    void CopyFrom(bCAccessorCreator const &);
    void CopyTo(bCAccessorCreator &) const;
    bCPropertyObjectFactory *GetObjectFactory();
    bCPropertyObjectFactory const *GetObjectFactory() const;
    GEBool HasBaseClass() const;
    void Invalidate();
    GEBool IsValid() const;
    bCAccessorCreator QueryBaseClass();
    void SetInstance(bCPropertyObjectBase *);

  protected:
    bCAccessorCreator();

  private:
    GE_UNIMPL_MEMBERS(0x4)
};

GE_ASSERT_SIZEOF(bCAccessorCreator, 0x4)
