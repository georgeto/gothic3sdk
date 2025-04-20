#pragma once

#include <Engine/ge_canvas.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCMaterialCanvas : public eCCanvas
{
    // clang-format off
    protected: virtual void DrawVertices();
    protected: virtual void UpdateVertices();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    protected: void Destroy() override;
    protected: bEResult Create() override;
    public: ~eCMaterialCanvas() override;
    public: void Process() override;
    public: void Render() override;
    // clang-format on

  public:
    eCMaterialCanvas(eCMaterialCanvas const &);
    eCMaterialCanvas();

  public:
    eCMaterialCanvas &operator=(eCMaterialCanvas const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCMaterialCanvas const &);
    void CopyTo(eCMaterialCanvas &) const;
    GEU8 GetAlpha() const;
    GEU32 GetDiffuseColor() const;
    void SetAlpha(GEU8);
    void SetDiffuseColor(bCByteAlphaColor const &);
    void SetDiffuseColor(GEU32);
    void SetTexture(bCString const &);

  protected:
    void Invalidate();
};
