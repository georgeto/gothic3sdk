#pragma once

#include <SharedBase/math/3d/ge_vector.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCFlexibleVertexFormat;
class bCVector2;
class bCVector4;

class GE_DLLIMPORT bCFlexibleVertexPtr
{
  public:
    bCFlexibleVertexPtr(bCFlexibleVertexPtr const &);
    bCFlexibleVertexPtr();
    ~bCFlexibleVertexPtr();

  public:
    bCFlexibleVertexPtr &operator=(bCFlexibleVertexPtr const &);
    GEBool operator==(bCFlexibleVertexPtr const &) const;
    GEBool operator!=(bCFlexibleVertexPtr const &) const;
    bCFlexibleVertexPtr operator++(GEInt);
    bCFlexibleVertexPtr &operator++();
    bCFlexibleVertexPtr operator--(GEInt);
    bCFlexibleVertexPtr &operator--();
    bCFlexibleVertexPtr operator-(GEInt);
    bCFlexibleVertexPtr operator+(GEInt);
    bCFlexibleVertexPtr &operator+=(GEInt);
    bCFlexibleVertexPtr &operator-=(GEInt);

  public:
    GELPByte &AccessBuffer();
    GEU32 &AccessDiffuse();
    bCFlexibleVertexFormat &AccessFormat();
    bCVector &AccessNormal();
    GEFloat &AccessPointSize();
    bCVector &AccessPosition();
    GEFloat &AccessRHW();
    GEU32 &AccessSpecular();
    bCVector2 &AccessTextureCoords2(GEInt);
    bCVector &AccessTextureCoords3(GEInt);
    bCVector4 &AccessTextureCoords4(GEInt);
    GEFloat &AccessWeight(GEInt);
    GEFloat &AccessX();
    GEFloat &AccessY();
    GEFloat &AccessZ();
    void Advance(GEInt);
    void AttachTo(bCFlexibleVertexFormat const &, GELPByte);
    void CopyFrom(bCFlexibleVertexPtr const &);
    void CopyTo(bCFlexibleVertexPtr &) const;
    GELPByte GetBuffer();
    GELPCByte GetBuffer() const;
    void GetBuffer(GELPByte &) const;
    GEU32 GetDiffuse() const;
    bCFlexibleVertexFormat const &GetFormat() const;
    void GetFormat(bCFlexibleVertexFormat &) const;
    bCVector GetNormal() const;
    void GetNormal(bCVector &) const;
    GEFloat GetPointSize() const;
    bCVector GetPosition() const;
    void GetPosition(bCVector2 &) const;
    void GetPosition(bCVector &) const;
    GEFloat GetRHW() const;
    GEU32 GetSpecular() const;
    void GetTextureCoords(GEInt, bCVector2 &) const;
    void GetTextureCoords(GEInt, bCVector4 &) const;
    void GetTextureCoords(GEInt, bCVector &) const;
    GEFloat GetWeight(GEInt) const;
    GEFloat GetX() const;
    GEFloat GetY() const;
    GEFloat GetZ() const;
    void Invalidate();
    GEBool IsBufferValid() const;
    GEBool IsFormatValid() const;
    GEBool IsValid() const;
    void Rewind(GEInt);
    void SetAllTextureCoords(bCVector2 const &);
    void SetAllTextureCoords(bCVector4 const &);
    void SetAllTextureCoords(bCVector const &);
    void SetAllWeights(GEFloat);
    void SetBuffer(GELPByte);
    void SetDiffuse(GEU32);
    void SetFormat(bCFlexibleVertexFormat const &);
    void SetFormat(GEU32);
    void SetNormal(bCVector const &);
    void SetPointSize(GEFloat);
    void SetPosition(bCVector const &);
    void SetRHW(GEFloat);
    void SetSpecular(GEU32);
    void SetTextureCoords(GEInt, bCVector2 const &);
    void SetTextureCoords(GEInt, bCVector4 const &);
    void SetTextureCoords(GEInt, bCVector const &);
    void SetWeight(GEInt, GEFloat);
    void SetX(GEFloat);
    void SetY(GEFloat);
    void SetZ(GEFloat);
};
