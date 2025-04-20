#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCColorScheme
{
  public:
    enum eEColorIndex
    {
        // TODO: Enumerator values
    };

    enum eEColorScheme
    {
        // TODO: Enumerator values
    };

  public:
    eCColorScheme(eCColorScheme const &);
    eCColorScheme();
    ~eCColorScheme();

  public:
    eCColorScheme &operator=(eCColorScheme const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCColorScheme const &);
    void CopyTo(eCColorScheme &) const;
    GEBool Create(eEColorScheme);
    bCByteAlphaColor const &GetColor(eEColorIndex) const;
    eEColorScheme GetColorScheme() const;
    void GetColorScheme(eEColorScheme &) const;
    GEBool Read(bCIStream &);
    void SetColorScheme(eEColorScheme);
    void Write(bCOStream &) const;

  protected:
    eEColorScheme &AccessColorScheme();
    bTObjArray<bCByteAlphaColor> &AccessColors();
    void Destroy();
    bTObjArray<bCByteAlphaColor> const &GetColors() const;
    void GetColors(bTObjArray<bCByteAlphaColor> &) const;
    void Invalidate();
    void SetColors(bTObjArray<bCByteAlphaColor> const &);
};
