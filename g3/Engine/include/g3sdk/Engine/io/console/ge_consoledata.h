#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCConsoleData
{
    // clang-format off
    public: virtual ~eCConsoleData();
    // clang-format on

  public:
    eCConsoleData(eCConsoleData const &);
    eCConsoleData();

  public:
    eCConsoleData &operator=(eCConsoleData const &);

  public:
    void Help(eCConsoleData *, GEInt);
};
