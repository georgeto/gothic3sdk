#pragma once

#include <Engine/entity/proxy/ge_templateentityproxy.h>

#include <SharedBase.h>

class eCEntity;

class GE_DLLIMPORT eCEffectSystemBase
{
    // clang-format off
    public: virtual GELPVoid StartEffect(bCString const &, eCEntity *, eCEntity *, bCMatrix const *, GEBool) = 0;
    public: virtual GEBool StopEffect(GELPVoid, GEBool) = 0;
    public: virtual GEBool ProcessEffect(GELPVoid, GEFloat) = 0;
    public: virtual GEBool EnableEffectProcessing(GELPVoid, GEBool) = 0;
    public: virtual void GetEffectDependencies(bCString const &, bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) = 0;
    public: virtual ~eCEffectSystemBase();
    // clang-format on

  public:
    eCEffectSystemBase(eCEffectSystemBase const &);
    eCEffectSystemBase();

  public:
    eCEffectSystemBase &operator=(eCEffectSystemBase const &);
};
