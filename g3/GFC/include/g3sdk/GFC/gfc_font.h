#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT CFFGFCFont
{
    // clang-format off
    public: virtual ~CFFGFCFont();
    // clang-format on

  public:
    CFFGFCFont(CFFGFCFont const &);
    CFFGFCFont();

  public:
    CFFGFCFont &operator=(CFFGFCFont const &);

  public:
    GEBool Create(tagLOGFONTA const &);
    GEBool Create(GELPCChar, GEInt, GEInt, GEBool, GEBool, GEBool);
    GEU32 GetHandle() const;
    void SetHandle(GEU32);
};
