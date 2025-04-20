#pragma once

#include <Engine.h>

class gCNPC_PS;

class GE_DLLIMPORT gCSVMManager
{
  public:
    struct SBlock
    {
        GE_UNIMPL_STRUCT(SBlock)
    };

    struct SVoice
    {
        GE_UNIMPL_STRUCT(SVoice)
    };

  public:
    static GEBool GE_STDCALL ContainsBlock(SVoice const &, bCString const &);
    static GEBool GE_STDCALL ContainsSVM(SBlock const &, bCString const &);
    static bCString GE_STDCALL FormatSampleName(bCString const &, bCString const &, GEBool);
    static bCString GE_STDCALL FormatSampleName(bCString const &, GEBool);
    static bCString GE_STDCALL FormatSampleName(gCNPC_PS const *, bCString const &, GEBool);
    static gCSVMManager &GE_STDCALL GetInstance();
    static eCLocTable::SEntry GE_STDCALL GetLocEntry(bCString const &, bCString const &);
    static eCLocString GE_STDCALL GetLocString(bCString const &, bCString const &);
    static bCString GE_STDCALL GetStringID(bCString const &a_strVoice, bCString const &a_strSVM);
    static GEBool GE_STDCALL SetLocEntry(bCString const &, bCString const &, eCLocTable::SEntry const &);

  public:
    gCSVMManager(gCSVMManager const &);

  public:
    gCSVMManager &operator=(gCSVMManager const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    GEBool AddBlock(bCString const &, bCString const &);
    GEBool AddSVM(bCString const &, bCString const &);
    GEBool CloneVoice(bCString const &, bCString const &);
    GEBool ContainsSVM(SVoice const &, bCString const &);
    SBlock const *CreateBlock(bCString const &);
    SVoice const *CreateVoice(bCString const &);
    GEBool DeleteBlock(bCString const &);
    GEBool DeleteVoice(bCString const &);
    GEBool ExistsSVM(bCString const &) const;
    SBlock const *GetBlock(bCString const &) const;
    bCString GetBlockId(bCString const &);
    bTObjMap<bCString, SBlock> const &GetBlockList();
    bCString GetFileName() const;
    bCUnicodeString GetStageDirection(bCString const &);
    SVoice const *GetVoice(bCString const &) const;
    bTObjMap<bCString, SVoice> const &GetVoiceList();
    GEBool IsReadOnly() const;
    void Read(bCIStream &);
    GEBool Read();
    GEBool RemoveBlock(bCString const &, bCString const &);
    GEBool RemoveSVM(bCString const &);
    GEBool RenameBlock(bCString const &, bCString const &);
    GEBool RenameSVM(bCString const &, bCString const &);
    GEBool RenameVoice(bCString const &, bCString const &);
    GEBool SetStageDirection(bCString const &, bCUnicodeString const &);
    GEBool SetText(bCString const &, bCString const &, bCUnicodeString const &);
    void Write(bCOStream &);
    GEBool Write();

  private:
    gCSVMManager();
    ~gCSVMManager();

  private:
    GEBool Create();
    GEBool DeleteStringsFromLocTable(bCString const &, SBlock const &);
    void Destroy();
    void Invalidate();
};

bCIStream &GE_STDCALL operator>>(bCIStream &, gCSVMManager &);
bCOStream &GE_STDCALL operator<<(bCOStream &, gCSVMManager &);
bCIStream &GE_STDCALL operator>>(bCIStream &, gCSVMManager::SBlock &);
bCOStream &GE_STDCALL operator<<(bCOStream &, gCSVMManager::SBlock &);
bCOStream &GE_STDCALL operator<<(bCOStream &, gCSVMManager::SVoice &);
bCIStream &GE_STDCALL operator>>(bCIStream &, gCSVMManager::SVoice &);
