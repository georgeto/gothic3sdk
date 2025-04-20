#pragma once

class IFFGUIWindow;

class GE_DLLIMPORT IFFGUIMsgProc
{
    // clang-format off
    protected: virtual GEInt MsgProc(IFFGUIWindow *, GEUInt, GEUInt, GEUInt);
    // clang-format on
};
