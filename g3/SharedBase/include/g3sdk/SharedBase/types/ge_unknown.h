#pragma once

#include <SharedBase/kernel/memory/ge_memoryadmin.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>
#include <SharedBase/types/ge_windows.h>

struct FFGUID : GUID
{
    GE_UNIMPL_STRUCT(FFGUID)
};

class IFFUnknown
{
    // clang-format off
    public: virtual GEU32 AddRef( )                               = 0;
    public: virtual GEU32 Release( )                              = 0;
    public: virtual GEU32 QueryInterface( FFGUID const &, GELPVoid * ) = 0;
    // clang-format on
};

class __declspec(dllexport) CFFUnknown : public virtual IFFUnknown
{
    // clang-format off
    public: virtual void Nop() {};
    public: virtual ~CFFUnknown() {};
    // clang-format on

  public:
    GEU32 AddRef() override
    {
        return ++m_uRefCount;
    }

    GEU32 Release() override
    {
        GEU32 NewRefCount = --m_uRefCount;
        if (NewRefCount == 0)
        {
            auto This = this;
            GE_DELETE(This);
        }
        return NewRefCount;
    }

    GEU32 QueryInterface(FFGUID const &, GELPVoid *) override
    {
        // Not supported...
        return static_cast<GEU32>(E_NOINTERFACE);
    }

  private:
    // TODO: Make access thread safe?
    // Must start at 1, otherwise Gothic 3 calls Release too often!
    GEU32 m_uRefCount = 1;
};
