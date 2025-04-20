#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCStatisticCtrl : public eCWnd
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCStatisticCtrl() override;
    protected: void OnSize(GEU32, GEInt, GEInt) override;
    protected: void Process() override;
    protected: void OnParentNotify(GEU32, GEU32, GEU32, GEI32 *) override;
    protected: void OnSysColorChange() override;
    protected: void OnRender() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    public: GEInt OnKeyDown(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &) override;
    public: void OnLButtonDown(GEU32, bCPoint) override;
    // clang-format on

  public:
    eCStatisticCtrl(eCStatisticCtrl const &);
    eCStatisticCtrl();

  public:
    eCStatisticCtrl &operator=(eCStatisticCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCStatisticCtrl const &);
    void CopyTo(eCStatisticCtrl &) const;
    bCObjectBase *GetAutoProfileObject() const;
    GEInt GetChannelCount() const;
    GEU32 GetCurrentChannel();
    GEFloat GetLastSample(GEU32) const;
    void NextSample(GEFloat, GEInt, bCByteAlphaColor const *);
    void PauseSampling();
    void SetAutoProfileObject(bCObjectBase *);
    void SetColorBoundaries(GEFloat, GEFloat, GEFloat);
    void SetCurrentChannel(GEU32);
    void SetDynamicRangeEnabled(GEBool);
    void SetRenderLines(GEBool);
    void SetRenderPivots(GEBool);
    void SetRenderYRangeText(GEBool);
    void SetTimeToObserve(GEFloat);
    void SetTitleText(bCString const &);
    void SetYRange(GEFloat, GEFloat);
    void StartSampling();
    void StopSampling();
    void UpdateSample(GEU32, GEFloat, GEInt, bCByteAlphaColor const *);

  protected:
    void Invalidate();

  private:
    void CreateSample(GEU32, GEU32, GEFloat, GEInt, bCByteAlphaColor const *);
    bCByteAlphaColor GetColorOfYValue(GEFloat) const;
    void ParameterChanged();
    void UpdateDynamicRange();
};
