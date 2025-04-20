#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCVisualAnimationLipSync
{
  public:
    struct eSPhone
    {
        GE_UNIMPL_STRUCT(eSPhone)
    };

    enum eEPhoneType
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: virtual GEU16 GetVersion() const;
    public: virtual bEResult Read(bCIStream &);
    public: virtual bEResult Write(bCOStream &);
    public: virtual void Destroy();
    public: virtual bEResult Create();
    public: virtual ~eCVisualAnimationLipSync();
    // clang-format on

  public:
    static eEPhoneType GE_STDCALL FindePhoneByLabelString(bCString const &);

  public:
    eCVisualAnimationLipSync(eCVisualAnimationLipSync const &);
    eCVisualAnimationLipSync();

  public:
    bTValArray<eSPhone> &GetPhones();
    bTValArray<eSPhone> const &GetPhones() const;

  protected:
    eCVisualAnimationLipSync const &operator=(eCVisualAnimationLipSync const &);

  protected:
    void CopyFrom(eCVisualAnimationLipSync const &);
    void Invalidate();
};
