#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCFlexibleVertexFormat
{
  public:
    static GEInt GE_STDCALL GetMaxTextureStages();

  public:
    bCFlexibleVertexFormat(bCFlexibleVertexFormat const &);
    explicit bCFlexibleVertexFormat(GEU32 Format = 0);
    ~bCFlexibleVertexFormat();

  public:
    explicit operator GEU32() const;
    bCFlexibleVertexFormat &operator=(bCFlexibleVertexFormat const &);
    GEBool operator==(bCFlexibleVertexFormat const &) const;
    GEBool operator!=(bCFlexibleVertexFormat const &) const;

  public:
    GEU32 &AccessFormat();
    void CopyFrom(bCFlexibleVertexFormat const &);
    void CopyTo(bCFlexibleVertexFormat &) const;
    void EnableDiffuse(GEBool);
    void EnableNormal(GEBool);
    void EnablePointSize(GEBool);
    void EnableRHW(GEBool);
    void EnableSpecular(GEBool);
    GEU32 GetFormat() const;
    void GetFormat(GEU32 &) const;
    GEInt GetOffsetDiffuse() const;
    GEInt GetOffsetNormal() const;
    GEInt GetOffsetPointSize() const;
    GEInt GetOffsetRHW() const;
    GEInt GetOffsetSpecular() const;
    GEInt GetOffsetTextureCoord(GEInt, GEInt) const;
    GEInt GetOffsetTextureCoords(GEInt) const;
    GEInt GetOffsetTextureCoords() const;
    GEInt GetOffsetWeight(GEInt) const;
    GEInt GetOffsetWeights() const;
    GEInt GetOffsetX() const;
    GEInt GetOffsetXYZ() const;
    GEInt GetOffsetY() const;
    GEInt GetOffsetZ() const;
    GEInt GetTextureCoordCount(GEInt) const;
    GEInt GetTextureStageCount() const;
    GEInt GetVertexByteCount() const;
    GEInt GetWeightCount() const;
    GEBool HasDiffuse() const;
    GEBool HasNormal() const;
    GEBool HasPointSize() const;
    GEBool HasRHW() const;
    GEBool HasSpecular() const;
    GEBool HasWeight(GEInt) const;
    GEBool HasXYZ() const;
    GEBool IsTransformedAndLit() const;
    GEBool IsValid() const;
    GEBool MatchesMask(GEU32) const;
    void ModifyStyle(GEU32, GEU32);
    void SetFormat(GEU32);
    void SetTextureCoordCount(GEInt, GEInt);
    void SetTextureStageCount(GEInt);
    void SetWeightCount(GEInt);
};
