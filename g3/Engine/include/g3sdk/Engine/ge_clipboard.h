#pragma once

#include <SharedBase.h>

class eCWnd;

class GE_DLLIMPORT eCClipboard
{
  public:
    static eCClipboard &GE_STDCALL AccessClipboard();
    static eCClipboard const &GE_STDCALL GetClipboard();

  public:
    ~eCClipboard();

  public:
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  public:
    void Close();
    GEBool Empty();
    GEInt GetData(GEInt, GELPVoid, GEInt) const;
    GEInt GetDataByteCount(GEInt) const;
    GEInt GetFormatIndex(bCString const &) const;
    eCWnd const *GetOpener() const;
    void GetOpener(eCWnd *&) const;
    eCWnd const *GetOwner() const;
    void GetOwner(eCWnd *&) const;
    GEBool IsOpen() const;
    GEBool Open(eCWnd *);
    GEBool Read(bCIStream &);
    GEBool SetData(GEInt, GELPCVoid, GEInt);
    void Write(bCOStream &) const;

  protected:
    eCClipboard(eCClipboard const &);
    eCClipboard();

  protected:
    eCClipboard &operator=(eCClipboard const &);

  protected:
    bTPtrArray<GELPByte> &AccessBuffers();
    bTValArray<GEInt> &AccessByteCounts();
    bTObjArray<bCString> &AccessFormats();
    eCWnd *&AccessOpener();
    eCWnd *&AccessOwner();
    void ClearBuffer(GEInt);
    void CopyFrom(eCClipboard const &);
    void CopyTo(eCClipboard &) const;
    void Create();
    void CreateBuffers();
    void Destroy();
    void DestroyBuffers();
    bTPtrArray<GELPByte> const &GetBuffers() const;
    void GetBuffers(bTPtrArray<GELPByte> &) const;
    bTValArray<GEInt> const &GetByteCounts() const;
    void GetByteCounts(bTValArray<GEInt> &) const;
    bTObjArray<bCString> const &GetFormats() const;
    void GetFormats(bTObjArray<bCString> &) const;
    void Invalidate();
    void SetBuffers(bTPtrArray<GELPByte> const &);
    void SetByteCounts(bTValArray<GEInt> const &);
    void SetFormats(bTObjArray<bCString> const &);
    void SetOpener(eCWnd *);
    void SetOwner(eCWnd *);
};
