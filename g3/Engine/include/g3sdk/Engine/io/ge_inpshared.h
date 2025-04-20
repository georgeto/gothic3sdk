#pragma once

#include <SharedBase.h>

class eCInpShared
{
  public:
    enum eECoopLevel;
    enum eEKeyboardStateOffset
    {
        eEKeyboardStateOffset_ESC = 1,
        eEKeyboardStateOffset_1 = 2,
        eEKeyboardStateOffset_2 = 3,
        eEKeyboardStateOffset_3 = 4,
        eEKeyboardStateOffset_4 = 5,
        eEKeyboardStateOffset_5 = 6,
        eEKeyboardStateOffset_6 = 7,
        eEKeyboardStateOffset_7 = 8,
        eEKeyboardStateOffset_8 = 9,
        eEKeyboardStateOffset_9 = 10,
        eEKeyboardStateOffset_0 = 11,
        eEKeyboardStateOffset_MINUS = 12,
        eEKeyboardStateOffset_EQUALS = 13,
        eEKeyboardStateOffset_BACKSPACE = 14,
        eEKeyboardStateOffset_TAB = 15,
        eEKeyboardStateOffset_Q = 16,
        eEKeyboardStateOffset_W = 17,
        eEKeyboardStateOffset_E = 18,
        eEKeyboardStateOffset_R = 19,
        eEKeyboardStateOffset_T = 20,
        eEKeyboardStateOffset_Y = 21,
        eEKeyboardStateOffset_U = 22,
        eEKeyboardStateOffset_I = 23,
        eEKeyboardStateOffset_O = 24,
        eEKeyboardStateOffset_P = 25,
        eEKeyboardStateOffset_LEFT_BRACKET = 26,
        eEKeyboardStateOffset_RIGHT_BRACKET = 27,
        eEKeyboardStateOffset_RETURN = 28,
        eEKeyboardStateOffset_LEFT_CTRL = 29,
        eEKeyboardStateOffset_A = 30,
        eEKeyboardStateOffset_S = 31,
        eEKeyboardStateOffset_D = 32,
        eEKeyboardStateOffset_F = 33,
        eEKeyboardStateOffset_G = 34,
        eEKeyboardStateOffset_H = 35,
        eEKeyboardStateOffset_J = 36,
        eEKeyboardStateOffset_K = 37,
        eEKeyboardStateOffset_L = 38,
        eEKeyboardStateOffset_SEMICOLON = 39,
        eEKeyboardStateOffset_APOSTROPHE = 40,
        eEKeyboardStateOffset_GRAVE = 41,
        eEKeyboardStateOffset_LEFT_SHIFT = 42,
        eEKeyboardStateOffset_BACKSLASH = 43,
        eEKeyboardStateOffset_Z = 44,
        eEKeyboardStateOffset_X = 45,
        eEKeyboardStateOffset_C = 46,
        eEKeyboardStateOffset_V = 47,
        eEKeyboardStateOffset_B = 48,
        eEKeyboardStateOffset_N = 49,
        eEKeyboardStateOffset_M = 50,
        eEKeyboardStateOffset_COMMA = 51,
        eEKeyboardStateOffset_PERIOD = 52,
        eEKeyboardStateOffset_MINUS2 = 53,
        eEKeyboardStateOffset_RIGHT_SHIFT = 54,
        eEKeyboardStateOffset_NUM_MUL = 55,
        eEKeyboardStateOffset_LEFT_ALT = 56,
        eEKeyboardStateOffset_SPACE = 57,
        eEKeyboardStateOffset_CAPS_LOCK = 58,
        eEKeyboardStateOffset_F1 = 59,
        eEKeyboardStateOffset_F2 = 60,
        eEKeyboardStateOffset_F3 = 61,
        eEKeyboardStateOffset_F4 = 62,
        eEKeyboardStateOffset_F5 = 63,
        eEKeyboardStateOffset_F6 = 64,
        eEKeyboardStateOffset_F7 = 65,
        eEKeyboardStateOffset_F8 = 66,
        eEKeyboardStateOffset_F9 = 67,
        eEKeyboardStateOffset_F10 = 68,
        eEKeyboardStateOffset_NUMLOCK = 69,
        eEKeyboardStateOffset_SCROLL = 70,
        eEKeyboardStateOffset_NUM_7 = 71,
        eEKeyboardStateOffset_NUM_8 = 72,
        eEKeyboardStateOffset_NUM_9 = 73,
        eEKeyboardStateOffset_NUM_SUB = 74,
        eEKeyboardStateOffset_NUM_4 = 75,
        eEKeyboardStateOffset_NUM_5 = 76,
        eEKeyboardStateOffset_NUM_6 = 77,
        eEKeyboardStateOffset_NUM_1 = 79,
        eEKeyboardStateOffset_NUM_2 = 80,
        eEKeyboardStateOffset_NUM_3 = 81,
        eEKeyboardStateOffset_NUM_0 = 82,
        eEKeyboardStateOffset_NUM_DEL = 83,
        eEKeyboardStateOffset_PIPE = 86,
        eEKeyboardStateOffset_F11 = 87,
        eEKeyboardStateOffset_F12 = 88,
        eEKeyboardStateOffset_F13 = 100,
        eEKeyboardStateOffset_F14 = 101,
        eEKeyboardStateOffset_F15 = 102,
        eEKeyboardStateOffset_NUM_ENTER = 156,
        eEKeyboardStateOffset_RIGHT_CTRL = 157,
        eEKeyboardStateOffset_NUM_DIV = 181,
        eEKeyboardStateOffset_RIGHT_ALT = 184,
        eEKeyboardStateOffset_PAUSE = 197,
        eEKeyboardStateOffset_HOME = 199,
        eEKeyboardStateOffset_CURSOR_UP = 200,
        eEKeyboardStateOffset_PAGE_UP = 201,
        eEKeyboardStateOffset_CURSOR_LEFT = 203,
        eEKeyboardStateOffset_CURSOR_RIGHT = 205,
        eEKeyboardStateOffset_END = 207,
        eEKeyboardStateOffset_CURSOR_DOWN = 208,
        eEKeyboardStateOffset_PAGE_DOWN = 209,
        eEKeyboardStateOffset_INSERT = 210,
        eEKeyboardStateOffset_DELETE = 211,
        eEKeyboardStateOffset_LEFT_OS_KEY = 219,
        eEKeyboardStateOffset_RIGHT_OS_KEY = 220
    };
    enum eEMouseOffset
    {
        eEMouseOffset_PositionX = 0,
        eEMouseOffset_PositionY = 1,
        eEMouseOffset_PositionZ = 2,
        eEMouseOffset_Button0 = 3,
        eEMouseOffset_Button1 = 4,
        eEMouseOffset_Button2 = 5,
        eEMouseOffset_Button3 = 6,
        eEMouseOffset_PositionXPositive = 7,
        eEMouseOffset_PositionXNegative = 8,
        eEMouseOffset_PositionYPositive = 9,
        eEMouseOffset_PositionYNegative = 10,
        eEMouseOffset_PositionZPositive = 11,
        eEMouseOffset_PositionZNegative = 12
    };
    enum eEAPIType
    {
        // TODO: Enumerator values
    };
    enum eEAxisMode
    {
        // TODO: Enumerator values
    };
    struct eSInpBufferedData;
    struct eSInputMessage
    {
      public:
        enum eEInputDevice
        {
            eEInputDevice_Keyboard = 0,
            eEInputDevice_Mouse = 1
        };

        enum eEModifier
        {
            eEModifier_LeftAlt_State = 0x100,
            eEModifier_LeftCtrl_State = 0x200,
            eEModifier_LeftShift_State = 0x400,
            eEModifier_RightAlt_State = 0x800,
            eEModifier_RightCtrl_State = 0x1000,
            eEModifier_RightShift_State = 0x2000,
            eEModifier_Current_State = 0x4000,
            eEModifier_Last_State = 0x8000,
        };

      public:
        union ModifierOrX {
            eEModifier m_Modifier;
            GEInt m_iXDelta;
        };

        union CharOrIndex {
            GEChar m_cCharacter;
            GEU8 m_u8ButtonIndex;
        };

        union Offset {
            eEKeyboardStateOffset m_KeyboardStateOffset;
            eEMouseOffset m_MouseOffset;
        };

      public:
        eEInputDevice m_InputDevice;
        Offset m_Offset;
        CharOrIndex m_CharOrIndex;
        GE_PADDING(3)
        ModifierOrX m_ModifierOrX;
        GEInt m_iYDelta;
        GEInt m_iZDelta;
        GEBool m_bMouseButtonState;
        GEBool m_bMouseButtonLastState;
        GE_PADDING(2)
        GEU32 m_u32TimeStamp;

      public:
        inline eEKeyboardStateOffset GetKeyboardStateOffset() const
        {
            return static_cast<eEKeyboardStateOffset>(m_Offset.m_KeyboardStateOffset & 0xFF);
        };
        inline eEMouseOffset GetMouseOffset() const
        {
            return m_Offset.m_MouseOffset;
        };
        inline GEBool GetState() const
        {
            return (m_ModifierOrX.m_Modifier & eEModifier_Current_State) != 0;
        };
        inline GEBool GetLastState() const
        {
            return (m_ModifierOrX.m_Modifier & eEModifier_Last_State) != 0;
        };
        inline GEBool GetLeftAltState() const
        {
            return (m_ModifierOrX.m_Modifier & eEModifier_LeftAlt_State) != 0;
        };
        inline GEBool GetLeftCtrlState() const
        {
            return (m_ModifierOrX.m_Modifier & eEModifier_LeftCtrl_State) != 0;
        };
        inline GEBool GetLeftShiftState() const
        {
            return (m_ModifierOrX.m_Modifier & eEModifier_LeftShift_State) != 0;
        };
        inline GEBool GetRightAltState() const
        {
            return (m_ModifierOrX.m_Modifier & eEModifier_RightAlt_State) != 0;
        };
        inline GEBool GetRightCtrlState() const
        {
            return (m_ModifierOrX.m_Modifier & eEModifier_RightCtrl_State) != 0;
        };
        inline GEBool GetRightShiftState() const
        {
            return (m_ModifierOrX.m_Modifier & eEModifier_RightShift_State) != 0;
        };
    };
    GE_ASSERT_SIZEOF(eSInputMessage, 0x20)

    struct eSGameKeyMessage
    {
        GE_UNIMPL_STRUCT(eSGameKeyMessage)
    };

    struct eSInpBufferedData
    {
        GE_UNIMPL_STRUCT(eSInpBufferedData)
    };

    struct eSInpContextDesc
    {
        GE_UNIMPL_STRUCT(eSInpContextDesc)
    };

    struct eSInpGamepadDesc
    {
        GE_UNIMPL_STRUCT(eSInpGamepadDesc)
    };

    struct eSInpGamepadState
    {
        GE_UNIMPL_STRUCT(eSInpGamepadState)
    };

    struct eSInpKeyboardState
    {
        GE_UNIMPL_STRUCT(eSInpKeyboardState)
    };

    struct eSInpMouseState
    {
        GE_UNIMPL_STRUCT(eSInpMouseState)
    };
};
