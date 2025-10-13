#pragma once

#include <SharedBase/kernel/object/ge_objectrefbase.h>

class GE_DLLIMPORT bCEvent : public bCObjectRefBase
{
    // clang-format off
    public: virtual GEBool IsDeleteable();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~bCEvent() override;
    // clang-format on

  public:
    bCEvent(bCEvent const &);
    bCEvent();

  public:
    bCEvent &operator=(bCEvent const &);

  public:
    GE_NO_DLLIMPORT
    inline GEU32 GetWindowId() const
    {
        return m_u32WindowId;
    }

  protected:
    void Invalidate();

  private:
    GEU32 __UNK_000C;
    GEBool __UNK_0010;
    // Id of the window that caused the window (if any): eCGUIManager::GetInstance()->AccessWindowByID(m_u32WindowId)
    GEU32 m_u32WindowId;
};

GE_ASSERT_SIZEOF(bCEvent, 0x18)
