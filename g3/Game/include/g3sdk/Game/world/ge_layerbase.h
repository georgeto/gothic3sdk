#pragma once

#include <Game/world/ge_sector.h>

#include <Engine.h>

class GE_DLLIMPORT gCLayerBase : public eCProcessibleElement
{
    // clang-format off
    public: virtual bCString GetLayerCategory() const;
    protected: virtual bCPropertyObjectBase * OnCreateContext();
    public: GEBool IsValid() const override;
    public: void Destroy() override;
    public: ~gCLayerBase() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool IsDataAvailable() const override;
    protected: GEBool CanGotoState(eCProcessibleElement::eEState) override;
    protected: eCProcessibleElement::eEResult CreateData() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCLayerBase, eCProcessibleElement)
    GE_PROPERTY(bTPOSmartPtr<gCSector>, SectorPtr, m_pSector)

  public:
    void Enable(GEBool);
    eCContextBase &GetContext();
    eCContextBase const &GetContext() const;
    gCSector &GetSector();
    gCSector const &GetSector() const;
    GEBool HasSector() const;
    GEBool IsEnabled() const;
    GEBool IsLocked() const;
    GEU16 Lock();
    GEFloat QueryProgress();
    GEU16 Unlock();

  protected:
    void Invalidate();
    eCProcessibleElement::eEResult SetContext(bCPropertyObjectBase *);
    eCProcessibleElement::eEResult SetContext(eCContextBase *);
    void SetSector(bCPropertyObjectBase const *);
    void SetSector(gCSector const *);

  private:
    GE_UNIMPL_MEMBERS(32)
};

GE_ASSERT_SIZEOF(gCLayerBase, 0x44)

GE_ASSERT_PROPERTY(gCLayerBase, m_pSector, 0x1c, 8)
