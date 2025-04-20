#pragma once

#include <SharedBase/kernel/object/ge_objectrefbase.h>

class bCObsoleteClass : public bCObjectRefBase
{
  protected:
    ~bCObsoleteClass() override;

  public:
    bCObsoleteClass &operator=(bCObsoleteClass const &a_Object) = default;
};
