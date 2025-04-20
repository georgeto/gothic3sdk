#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCDummyCollectorBase
{
    // clang-format off
    public: virtual bEResult Collect(bCBox const &) = 0;
    public: virtual bEResult Collect(eCEntity &) = 0;
    public: virtual bEResult Apply() = 0;
    public: virtual bEResult Apply(bCBox const &) = 0;
    public: virtual bEResult Apply(eCEntity &) = 0;
    public: virtual bEResult UpdateCollection() = 0;
    public: virtual bEResult UpdateCollection(eCEntity &) = 0;
    public: virtual bEResult ClearCollection() = 0;
    public: virtual bEResult RemoveFromCollection(eCEntity &) = 0;
    public: virtual GEU32 GetReferencedEntitiesCount() const = 0;
    public: virtual eCEntity * GetReferencedEntityAt(GEU32) const = 0;
    public: virtual GEBool IsInUpdateCollection() const = 0;
    public: virtual ~gCDummyCollectorBase();
    // clang-format on

  public:
    gCDummyCollectorBase(gCDummyCollectorBase const &);

  public:
    gCDummyCollectorBase &operator=(gCDummyCollectorBase const &);

  protected:
    explicit gCDummyCollectorBase(eCEntity &);

  private:
    eCEntity *m_pRootEntity;
};
