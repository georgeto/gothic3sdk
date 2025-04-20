#pragma once

#include <Engine/io/ge_inpshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCInputReceiver : public bCObjectRefBase
{
  public:
    enum eEInputPriority
    {
        eEInputPriority_Normal,
        eEInputPriority_High,
        eEInputPriority_ForceDWORD = GE_FORCE_DWORD
    };

    // clang-format off
    public: virtual eEInputPriority GetInputPriority() const;
    public: virtual GEInt OnAction(eCInpShared::eSGameKeyMessage const &);
    public: virtual GEInt OnKeyboard(eCInpShared::eSInputMessage const &);
    public: virtual GEInt OnMouse(eCInpShared::eSInputMessage const &);
    public: GEU16 GetVersion() const override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCInputReceiver() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCInputReceiver, bCObjectRefBase)

  public:
    void EnableInput(GEBool);
    GEBool IsInputEnabled() const;

  protected:
    void Invalidate();

  private:
    GEBool m_bInputEnabled;
    GE_PADDING(3)
};

GE_ASSERT_SIZEOF(eCInputReceiver, 0x10)
