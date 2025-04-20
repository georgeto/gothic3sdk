#pragma once

#include <SharedBase.h>

class eCPropertyProxy;

class GE_DLLIMPORT eCPropertyProxyCollection : public bCObjectRefBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCPropertyProxyCollection() override;
    // clang-format on

  public:
    eCPropertyProxyCollection(eCPropertyProxyCollection const &);
    eCPropertyProxyCollection();

  public:
    eCPropertyProxyCollection const &operator=(eCPropertyProxyCollection const &);

  public:
    GEBool AddProxy(bCString const &);
    void ClearCollection();
    void Execute();
    eCPropertyProxy const &GetPropertyProxyAt(GEInt) const;
    GEInt GetPropertyProxyCount() const;
    GEBool RemoveProxy(bCString const &);

  protected:
    void Invalidate();
};
