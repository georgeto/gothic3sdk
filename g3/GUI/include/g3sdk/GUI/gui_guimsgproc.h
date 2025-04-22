#pragma once

class IFFGUIWindow;

class IFFGUIMsgProc
{
    // clang-format off
    protected: virtual GEInt MsgProc(IFFGUIWindow *, GEUInt, GEUInt, GEUInt);
    // clang-format on
};
