#pragma once

#include <Engine/entity/proxy/ge_templateentityproxy.h>

#include <SharedBase.h>

class eCShaderEllementProxy;

struct eSShaderMaterialDeclaration
{
    GE_UNIMPL_STRUCT(eSShaderMaterialDeclaration)
};

class eCShaderEllementConstant
{
    GE_UNIMPL_STRUCT(eCShaderEllementConstant)
};

class GE_DLLIMPORT eCShaderEllementBase : public bCObjectRefBase
{
    // clang-format off
    public: virtual bCString const & GetEllementTypeName() const;
    public: virtual void SetSwitch(GEInt);
    public: virtual GEInt GetProxyCount() const;
    public: virtual eCShaderEllementProxy const * GetProxyAt(GEInt) const;
    public: virtual bCString GetProxyNameAt(GEInt) const;
    public: virtual void SetTime(GEFloat);
    public: virtual GEBool IsVertexTexCoordUsed(GEInt, GEBool) const;
    public: virtual GEBool IsVertexDiffuseUsed(GEBool) const;
    public: virtual GEBool IsVertexTangentUsed() const;
    public: virtual void GetUniqueConstantDeclerations(bTObjArray<bCString> &, bTObjMap<bCString, GEInt> &);
    public: virtual void BeforeCompileShader();
    public: virtual GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool);
    public: virtual GEBool Prefetch(GEBool, GEInt);
    public: virtual void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCShaderEllementBase() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCShaderEllementBase, bCObjectRefBase)

  public:
    bCRect &GetEditorLayout();
    eCShaderEllementConstant *GetShaderConstant(GEInt);
    GEInt GetShaderConstantCount() const;
    bCGuid const &GetToken() const;
    GEBool IsTimed() const;

  protected:
    void AddShaderConstant(eCShaderEllementConstant *);
    void DestroyLocal();
    void Invalidate();
    GEBool IsSwitch() const;
    void RemoveShaderConstant(eCShaderEllementConstant *);
    void SetIsSwitch(GEBool);
    void SetIsTimed(GEBool);
    void SetToken(bCGuid const &);

  private:
    GE_UNIMPL_MEMBERS(56)
};

GE_ASSERT_SIZEOF(eCShaderEllementBase, 0x44)
