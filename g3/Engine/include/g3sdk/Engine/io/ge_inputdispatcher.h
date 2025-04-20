#pragma once

#include <Engine/io/ge_inputreceiver.h>

#include <SharedBase.h>

class eCEngineComponentBase;

class GE_DLLIMPORT eCInputDispatcher : public eCInputReceiver
{
    // clang-format off
    public: virtual bCGuid const & GetID() const;
    protected: virtual GEBool RegisterModule(eCEngineComponentBase &);
    protected: virtual GEBool UnregisterModule(eCEngineComponentBase &);
    public: virtual void SetSession(eCInputReceiver *);
    public: virtual void SetActionMapper(eCInputReceiver *);
    public: virtual void EnableDebugMode(GEBool);
    public: virtual void Dispatch();
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCInputDispatcher() override;
    // clang-format on

  public:
    eCInputDispatcher(eCInputDispatcher const &);
    eCInputDispatcher();

  protected:
    eCInputDispatcher const &operator=(eCInputDispatcher const &);

  protected:
    void Invalidate();
};
