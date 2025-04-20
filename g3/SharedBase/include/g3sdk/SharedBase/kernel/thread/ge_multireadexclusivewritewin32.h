#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCMultiReadExclusiveWriteWin32
{
  public:
    bCMultiReadExclusiveWriteWin32();
    ~bCMultiReadExclusiveWriteWin32();

  public:
    bCMultiReadExclusiveWriteWin32 &operator=(bCMultiReadExclusiveWriteWin32 const &);

  public:
    void BeginRead();
    void BeginWrite();
    void EndRead();
    void EndWrite();
    GEU32 GetLockCount() const;

  protected:
    GEBool WriterIsOnlyReader() const;
};
