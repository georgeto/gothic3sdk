#pragma once

#include <Engine/ge_gfxshared.h>
#include <Engine/ge_imageadmin.h>

#include <SharedBase.h>

class eCConfigFile;

class GE_DLLIMPORT eCThemeAdmin
{
  public:
    struct SCursor
    {
        GE_UNIMPL_STRUCT(SCursor)
    };

    struct SElement
    {
        GE_UNIMPL_STRUCT(SElement)
    };

    struct SFont
    {
        GE_UNIMPL_STRUCT(SFont)
    };

    struct SMetrics
    {
        GE_UNIMPL_STRUCT(SMetrics)
    };

    struct STheme
    {
        GE_UNIMPL_STRUCT(STheme)
    };

    struct SThemePaths
    {
        GE_UNIMPL_STRUCT(SThemePaths)
    };

  public:
    static eCThemeAdmin &GE_STDCALL GetInstance();

  public:
    eCThemeAdmin(eCThemeAdmin const &);
    ~eCThemeAdmin();

  public:
    eCThemeAdmin &operator=(eCThemeAdmin const &);

  public:
    GEBool CompileAllThemes();
    GEBool CompileTheme(GEInt);
    GEBool CreateFontA(eCGfxShared::eSFontDesc const &, GEInt &);
    GEBool CreateTheme(bCString const &, GEInt &);
    void Destroy();
    GEBool ExportThemeSettings(GEInt);
    GEBool FindFontIndex(eCGfxShared::eSFontDesc const &, GEInt &) const;
    GEBool FindThemeIndex(bCString const &, GEInt &) const;
    GEInt GetFontCount() const;
    GEBool GetFontInfo(GEInt, eCGfxShared::eSFontDesc &) const;
    SFont const *GetFontNode(GEInt) const;
    bCString GetRootPath() const;
    eCImageAdmin::STexture const *GetTextureNode(GEInt) const;
    STheme *GetTheme(GEInt);
    STheme const *GetTheme(GEInt) const;
    GEInt GetThemeCount() const;
    GEBool GetThemePath(bCString const &, bCString &) const;
    GEBool GetThemePaths(bCString const &, SThemePaths &) const;
    bCString GetThemesPath() const;
    GEBool ImportThemeSettings(GEInt);
    GEBool IsValidFontIndex(GEInt) const;
    GEBool IsValidThemeIndex(GEInt) const;
    GEBool LoadCompiledTheme(GEInt);
    GEBool RemoveFont(GEInt);
    GEBool SetFontInfo(GEInt, eCGfxShared::eSFontDesc const &);

  protected:
    eCThemeAdmin();

  protected:
    void DestroyFonts();
    GEBool ExportCursor(eCConfigFile &, SCursor const &);
    GEBool ExportCursor(bCString const &, SCursor const &);
    GEBool ExportElement(eCConfigFile &, SElement const &);
    GEBool ExportElement(bCString const &, SElement const &);
    GEBool ExportFont(eCConfigFile &, GEInt);
    GEBool ExportMetrics(eCConfigFile &, SMetrics const &);
    GEBool ExportMetrics(bCString const &, SMetrics const &);
    GEBool FillThemeFromImages(STheme &);
    GEBool ImportCursor(eCConfigFile &, SCursor &);
    GEBool ImportCursor(bCString const &, SCursor &);
    GEBool ImportElement(eCConfigFile &, SElement &);
    GEBool ImportElement(bCString const &, SElement &);
    GEBool ImportFont(eCConfigFile &, GEInt &);
    GEBool ImportMetrics(eCConfigFile &, SMetrics &);
    GEBool ImportMetrics(bCString const &, SMetrics &);
    void Invalidate();
    GEBool Read(bCIStream &, SCursor &);
    GEBool Read(bCIStream &, SElement &);
    GEBool Read(bCIStream &, SFont &);
    GEBool Read(bCIStream &, SMetrics &);
    GEBool Read(bCIStream &, STheme &);
    GEBool ReadCompiled(bCString const &, STheme &);
    void ReleaseFonts();
    GEBool Write(bCOStream &, SCursor &);
    GEBool Write(bCOStream &, SElement &);
    GEBool Write(bCOStream &, SFont &);
    GEBool Write(bCOStream &, SMetrics &);
    GEBool Write(bCOStream &, STheme &);
    GEBool WriteCompiled(bCString const &, STheme &);
};
