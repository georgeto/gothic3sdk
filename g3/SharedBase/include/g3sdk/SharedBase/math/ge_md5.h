#pragma once

#include <SharedBase/propertysystem/base/ge_propertyid.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCMd5
{
  public:
    bCMd5();
    ~bCMd5();

  public:
    void Append(GELPCVoid, GEU32);
    GEBool Create();
    void Destroy();
    void Finish(bCPropertyID::bSCore &);
    void Finish();
    void GetDigest16(bCPropertyID::bSCore &) const;
    void GetDigest32(bCPropertyID::bSCore &) const;
    void GetDigest8(bCPropertyID::bSCore &) const;

  protected:
    void Invalidate();

  private:
    void Process(GELPCByte const);
};
