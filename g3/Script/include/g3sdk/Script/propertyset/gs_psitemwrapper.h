#pragma once

#include <Engine.h>

#define DECLARE_ITEM_PROPERTY(T, N)                                                                                    \
    class Property##N                                                                                                  \
    {                                                                                                                  \
      protected:                                                                                                       \
        GELPByte m_pEngineEntity;                                                                                      \
                                                                                                                       \
      private:                                                                                                         \
        Property##N();                                                                                                 \
        Property##N(Property##N const &);                                                                              \
        Property##N &operator=(Property##N const &);                                                                   \
                                                                                                                       \
      public:                                                                                                          \
        operator T() const;                                                                                            \
        /*Property##N & operator =       ( T const & );*/                                                              \
      protected:                                                                                                       \
        friend class PSItemWrapper;                                                                                    \
        using PropertySetProperty = Property##N;                                                                       \
    };                                                                                                                 \
    GE_NO_DLLIMPORT                                                                                                    \
    inline T _GetProperty##N() const                                                                                   \
    {                                                                                                                  \
        return GetProperty<Property##N>();                                                                             \
    }                                                                                                                  \
    __declspec(property(get = _GetProperty##N)) T N;

class bCString;

class PSItemWrapper
{
  public:
    template <typename PSP>
    inline PSP const &GetProperty() const;

  protected:
    GELPByte m_pEngineEntity;

  protected:
    using PropertySet = PSItemWrapper;

  public:
    PSItemWrapper(PSItemWrapper const &) = delete;
    PSItemWrapper() = delete;

  public:
    PSItemWrapper &operator=(PSItemWrapper const &) = delete;

  public:
    DECLARE_ITEM_PROPERTY(bCString, ReqAttrib1Tag)
    DECLARE_ITEM_PROPERTY(GEInt, ReqAttrib1Value)
    DECLARE_ITEM_PROPERTY(bCString, ReqAttrib2Tag)
    DECLARE_ITEM_PROPERTY(GEInt, ReqAttrib2Value)
    DECLARE_ITEM_PROPERTY(bCString, ReqAttrib3Tag)
    DECLARE_ITEM_PROPERTY(GEInt, ReqAttrib3Value)
    DECLARE_ITEM_PROPERTY(bCString, ReqAttrib4Tag)
    DECLARE_ITEM_PROPERTY(GEInt, ReqAttrib4Value)
};

template <typename PSP>
PSP const &PSItemWrapper::GetProperty() const
{
    return *reinterpret_cast<typename PSP::PropertySetProperty const *>(this);
}
