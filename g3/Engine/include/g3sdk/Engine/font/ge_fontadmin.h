#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCFontResource;
class eCGfxFont;

class GE_DLLIMPORT eCFontAdmin : public bCObjectRefBase
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    protected: void Destroy() override;
    protected: bEResult Create() override;
    public: ~eCFontAdmin() override;
    // clang-format on

  public:
    static eCFontAdmin &GE_STDCALL GetInstance();

  public:
    eCFontAdmin(eCFontAdmin const &);
    eCFontAdmin();

  public:
    eCFontAdmin &operator=(eCFontAdmin const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCFontAdmin const &);
    void CopyTo(eCFontAdmin &) const;
    eCFontResource *CreateFontResource(bCString const &);
    eCGfxFont *CreateSubsystemFont(eCGfxShared::eSFontDesc);
    void ReleaseSubsystemFont(eCGfxFont *);

  protected:
    void Invalidate();
};
