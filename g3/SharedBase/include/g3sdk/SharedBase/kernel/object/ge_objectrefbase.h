#pragma once

#include <SharedBase/kernel/object/ge_objectbase.h>

class bCMemoryStream;
class bCPropertyObjectBase;
class bCString;

class GE_DLLIMPORT bCObjectRefBase : public bCObjectBase
{
    // clang-format off
    /**
     *  If true, Add/ReleaseVirtualReference are called as virtual methods,
     *  otherwise the bCObjectRefBase implementation of the method is called directly.
     *  VirtualReference is enabled by default, only eCEntityPropertySet and eCResourceBase_PS have it disabled.
     */
    public: virtual GEBool IsVirtualReferencingEnabled() const;
    public: virtual bEResult PostInitializeProperties();
    private: virtual GEU32 NotifyPropertyValueChangedEnter(GELPCChar);
    private: virtual GEU32 NotifyPropertyValueChangedExit(GELPCChar);
    public: virtual GEBool OnNotifyPropertyValueChangedEnterEx(GELPCChar, GEBool);
    public: virtual GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool);
    public: virtual void NotifyPropertyDeprecated(bCString const &, bCString const &, bCMemoryStream &, GEU16);
    public: virtual GEBool NotifyPropertyValueChangedEnterEx(GELPCChar, GEBool);
    public: virtual GEBool NotifyPropertyValueChangedExitEx(GELPCChar, GEBool);
    public: GEU16 GetVersion() const override;
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    /**
     * If this object has a property object set, it will call
     * m_pPropertyObject->Add/ReleaseReference instead of modifying its own reference counter.
     */
    public: GEU32 AddReference() override;
    public: GEU32 ReleaseReference() override;
    protected: ~bCObjectRefBase() override;
    // clang-format on

  public:
    bCObjectRefBase(bCObjectRefBase const &);
    bCObjectRefBase();

  public:
    bCObjectRefBase &operator=(bCObjectRefBase const &);

  public:
    template <typename T>
    friend class bTPOPureSmartPtr;
    bCPropertyObjectBase *GetPropertyObject();
    bCPropertyObjectBase const *GetPropertyObject() const;
    GEU32 GetReferenceCount() const;

  protected:
    GEU32 AddVirtualReference();
    void Invalidate();
    GEU32 ReleaseVirtualReference();
    void SetPropertyObject(bCPropertyObjectBase const *);

  private:
    // 0000 // bCObjectRefBase::`vftable'
    /* 0004 */ bCPropertyObjectBase *m_pPropertyObject;
    /* 0008 */ GEU32 m_u32ReferenceCount;
};

GE_ASSERT_SIZEOF(bCObjectRefBase, 0xc)
