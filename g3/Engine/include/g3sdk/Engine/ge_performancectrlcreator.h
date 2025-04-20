#pragma once

#include <SharedBase.h>

class eCStatisticCtrl;

class GE_DLLIMPORT eCPerformanceCtrlCreator
{
  public:
    explicit eCPerformanceCtrlCreator(bCString const &);
    ~eCPerformanceCtrlCreator();

  public:
    eCPerformanceCtrlCreator &operator=(eCPerformanceCtrlCreator const &);
    eCStatisticCtrl *operator->();
    eCStatisticCtrl const *operator->() const;

  protected:
    eCPerformanceCtrlCreator();
};
