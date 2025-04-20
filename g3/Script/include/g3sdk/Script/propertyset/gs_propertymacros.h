#pragma once

#include <Engine.h>

class Entity;

//
// Entity PropertySet (PS*)
//

class GE_DLLIMPORT EntityPropertySet
{
  public:
    template <typename PSP>
    inline PSP &AccessProperty();
    template <typename PSP>
    inline PSP const &GetProperty() const;

  public:
    eCEntityPropertySet *m_pEngineEntityPropertySet;

  public:
    EntityPropertySet() = delete;
    EntityPropertySet(EntityPropertySet const &) = delete;
    EntityPropertySet &operator=(EntityPropertySet const &) = delete;
};

#define GS_PROPERTY_SET(T, C)                                                                                          \
  public:                                                                                                              \
    using INSTANCE_CLASS = C;                                                                                          \
                                                                                                                       \
  public:                                                                                                              \
    explicit T(eCEntity *);                                                                                            \
    explicit T(C *);                                                                                                   \
    ~T();                                                                                                              \
                                                                                                                       \
  public:                                                                                                              \
    C const *operator->() const;                                                                                       \
    T &operator=(T const &);                                                                                           \
                                                                                                                       \
  public:                                                                                                              \
    GEBool IsValid() const;                                                                                            \
                                                                                                                       \
  protected:                                                                                                           \
    friend class Entity;                                                                                               \
    using PropertySet = T;                                                                                             \
    using EnginePropertySet = C;                                                                                       \
                                                                                                                       \
  protected:                                                                                                           \
    explicit operator C *();                                                                                           \
    explicit operator C const *() const;                                                                               \
    C *operator->();                                                                                                   \
                                                                                                                       \
  protected:                                                                                                           \
    GEBool AttachTo(eCEntity *);                                                                                       \
    GEBool AttachTo(eCEntityPropertySet *);                                                                            \
    GEBool CopyFrom(T const &);                                                                                        \
                                                                                                                       \
  public:                                                                                                              \
    T(T const &) = delete;                                                                                             \
    T() = delete;

//
// Entity PropertySet Property (PS*::Property*)
//

class GE_DLLIMPORT EntityPropertySetProperty
{
  protected:
    eCEntity *m_pEngineEntity;

  private:
    EntityPropertySetProperty() = delete;
    EntityPropertySetProperty(EntityPropertySetProperty const &) = delete;
    EntityPropertySetProperty &operator=(EntityPropertySetProperty const &) = delete;
};

#define GS_PROPERTY(T, N)                                                                                              \
  public:                                                                                                              \
    class GE_DLLIMPORT Property##N : public EntityPropertySetProperty                                                  \
    {                                                                                                                  \
      public:                                                                                                          \
        operator T() const;                                                                                            \
        Property##N &operator=(T const &);                                                                             \
                                                                                                                       \
      protected:                                                                                                       \
        friend class Entity;                                                                                           \
        friend class EntityPropertySet;                                                                                \
        using PropertySetProperty = Property##N;                                                                       \
                                                                                                                       \
      public:                                                                                                          \
        Property##N() = delete;                                                                                        \
        Property##N(Property##N const &) = delete;                                                                     \
                                                                                                                       \
      public:                                                                                                          \
        Property##N &operator=(Property##N const &) = delete;                                                          \
    };                                                                                                                 \
    _GS_PROPERTY_WRAPPER(T, N)

#ifndef __INTELLISENSE__
#define _GS_PROPERTY_WRAPPER(T, N)                                                                                     \
    GE_NO_DLLIMPORT                                                                                                    \
    inline void _PutProperty##N(T const &a_Value)                                                                      \
    {                                                                                                                  \
        AccessProperty<Property##N>() = a_Value;                                                                       \
    }                                                                                                                  \
    GE_NO_DLLIMPORT                                                                                                    \
    inline T _GetProperty##N() const                                                                                   \
    {                                                                                                                  \
        return GetProperty<Property##N>();                                                                             \
    }                                                                                                                  \
    __declspec(property(get = _GetProperty##N, put = _PutProperty##N)) T N;
#else
#define _GS_PROPERTY_WRAPPER(T, N) __declspec(property(get = _GetProperty##N, put = _PutProperty##N)) T N;
#endif

#define GS_PROPERTY_COPY_ONLY(N)                                                                                       \
    class GE_DLLIMPORT Property##N : public EntityPropertySetProperty                                                  \
    {                                                                                                                  \
      protected:                                                                                                       \
        friend class Entity;                                                                                           \
        friend class EntityPropertySet;                                                                                \
        using PropertySetProperty = Property##N;                                                                       \
                                                                                                                       \
      public:                                                                                                          \
        Property##N() = delete;                                                                                        \
        Property##N(Property##N const &) = delete;                                                                     \
                                                                                                                       \
      public:                                                                                                          \
        /* hide copy assignment operator */                                                                            \
        Property##N &operator=(Property##N const &) = delete;                                                          \
    };

#include "gs_propertymacros.inl"
