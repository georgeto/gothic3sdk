#pragma once

#include <g3sdk/Game.h>

template <typename T>
inline T Min(T a_Value1, T a_Value2);
template <typename T>
inline T Max(T a_Value1, T a_Value2);

template <typename T>
inline void Swap(T &a, T &b);

bCString Trim(bCString const &a_rString, GEBool a_bTrimLeft = GETrue, GEBool a_bTrimRight = GETrue);
bCString GetWord(bCString const &a_rString, GEInt a_iWordNumber, bCString const &a_rDelimiters,
                 GEBool a_bTrimLeft = GETrue, GEBool a_bTrimRight = GETrue);
bCString NextWord(bCString const &a_rString, GEInt a_iStartIndex, bCString const &a_rDelimiters,
                  GEBool a_bTrimLeft = GETrue, GEBool a_bTrimRight = GETrue);
bCString GetWords(bCString const &a_rString, GEInt a_iStart, bCString const &a_rDelimiters, GEInt a_iEnd = -1,
                  GEBool a_bTrimLeft = GETrue, GEBool a_bTrimRight = GETrue);
bCString JoinString(bTObjArray<bCString> const &a_arrStrings, GEInt a_iOffset = 0, bCString const &a_rDelimiter = " ",
                    GEInt a_iEnd = -1);
bTObjArray<bCString> SplitString(bCString const &a_rString, bCString const &a_rDelimiters = " ",
                                 GEBool a_bTrimLeft = GETrue, GEBool a_bTrimRight = GETrue);
GEBool AutoCompleteString(bTObjArray<bCString> const &a_arrStrings, bCString &a_strFragment,
                          GEBool a_bBackward = false);

GEInt IndexOf(const GELPCChar a_arrData[], GEInt a_iDataCount, bCString a_strValue, GEBool a_bIgnoreCase = GEFalse);

GEBool IsNumeric(GEChar a_Char);
GEBool ParseDuration(bCString const &a_strDuration, GEU32 *o_uDuration);

bCString GetSystemTimeString();
bCString FormatDate(bCDateTime const &a_Date, bCString const &a_strFormat);
bCString FormatTime(bCDateTime const &a_Time, bCString const &a_strFormat);

bCString GetGothicPath();
GEBool FromFile(GELPCChar a_strFile, bCMemoryStream &o_MemoryStream);
GEBool ToFile(bCMemoryStream &a_MemoryStream, GELPCChar a_strFile);
GEBool ReadPhysConfigFile(GELPCChar a_strFile, eCConfigFile &o_ConfigFile);
void DestroyPhysConfigFile(eCConfigFile &a_ConfigFile);
bCString GetPhysicalFilePath(bCString const &a_strFilePath);
GEBool IsPhysical(bCString const &a_strFilePath);
bCString VectorToString(bCVector const &a_Vector, GEBool a_bAppendMarvin = false);
bCString VectorToMarvinString(bCVector const &a_Vector);
GEBool MarvinStringToVector(bCString const &a_strInput, bCVector &o_Vector);
bCString BoxToString(bCBox const &a_Box);
bCString MatrixToString(bCMatrix const &a_Matrix);
template <typename T>
bCString EntityProxyToString(T const &a_EntityProxy);
bCString BoolToString(GEBool a_Bool);
GEInt RoundFloat(GEFloat f);

bCUnicodeString FromUTF8(GELPCByte a_pSource, GEInt a_iLength = -1);
GEBool StartsWith(bCString const &a_strValue, GELPCChar a_strPattern);
GEBool StartsWith(bCString const &a_strValue, GEChar a_chPattern);
GEBool EndsWith(bCString const &a_strValue, GELPCChar a_strPattern);
GEBool EndsWith(bCString const &a_strValue, GEChar a_chPattern);
GEBool ContainsOnly(bCString const &a_strValue, GELPCChar a_strChars);
GEBool IsInteger(bCString const &a_strValue);
GEBool IsUnsignedInteger(bCString const &a_strValue);

bCString ToString(gEPoliticalAlignment a_PoliticalAlignment);
bCString ToString(gEQuestStatus a_QuestStatus);

template <typename T>
bCString GetEnumPrefix();

template <typename T>
bCString EnumToString(bTPropertyTypeOnly<bTPropertyContainer<T>> const &a_PropertyType, T a_enuValue,
                      GEBool a_bPrefix = GETrue);

template <typename T>
GEBool StringToEnum(T &a_oEnuValue, bTPropertyTypeOnly<bTPropertyContainer<T>> const &a_PropertyType,
                    bCString a_strValue, GEBool a_bPrefix = GETrue);

template <typename T>
T StringToEnum(bTPropertyTypeOnly<bTPropertyContainer<T>> const &a_PropertyType, bCString a_strValue,
               T a_enuDefaultValue, GEBool a_bPrefix = GETrue);

bTObjArray<bCString> GetEnumStringValues(bCPropertyTypeBase const &a_PropertyType, GEBool a_bPrefix = GETrue);

enum InfoCondResult
{
    InfoCondResult_Invalid,
    InfoCondResult_NotFulfilled,
    InfoCondResult_Fulfilled,
};
InfoCondResult CheckInfoCondition(bCString const &a_strRelation, GEInt a_iRequired, GEInt a_iValue);

gCLayerBase *GetLayer(bCString const &a_strName);
eCGeometrySpatialContext *GetGeometrySpatialContext(bCString const &a_strName);
gCEnclave_PS *GetEnclave(bCString const &a_strName);
// Returns: PC_Hero
eCDynamicEntity *GetHero();
// Returns: Entity currently controlled by the player (e.g. PC_Hero, Transformed monster)
eCDynamicEntity *GetPlayer();
GEBool IsPlayer(eCEntity const *a_pEntity);
gCClock_PS *GetClock();
gCSessionEditor *GetSessionEditor();

// Returns: Maxmium value of the attribute, without temporary bonuses/maluses and drain (HP, MP, SP)
GEInt GetBaseMaximum(gCAttribute const &a_pAttribute);

GELPByte GetGamePage(gCGUIManager *a_pGUIManager, gEGamePage a_Page);

void UnregisterModule(eCEngineComponentBase const *a_pModule);

template <typename T, typename C>
GE_FORCE_INLINE GEBool FindInventoryStacksIC(gCInventory_PS const &a_Inventory, T a_Item, C a_fCallback,
                                             gEInventoryFindQuality a_FindQuality = gEInventoryFindQuality_Ignore,
                                             GEU32 a_u32Quality = 0)
{
    GEInt iPrevIndex = -1;
    while ((iPrevIndex = a_Inventory.FindStackIndex(a_Item, a_FindQuality, a_u32Quality, iPrevIndex)) != -1)
    {
        if (a_fCallback(iPrevIndex))
            return GETrue;
    }
    return GEFalse;
}

template <typename T, typename C>
GE_FORCE_INLINE void FindInventoryStacksI(gCInventory_PS const &a_Inventory, T a_Item, C a_fCallback,
                                          gEInventoryFindQuality a_FindQuality = gEInventoryFindQuality_Ignore,
                                          GEU32 a_u32Quality = 0)
{
    FindInventoryStacksIC(
        a_Inventory, a_Item,
        [&](GEInt iItemIndex) {
            a_fCallback(iItemIndex);
            return GEFalse;
        },
        a_FindQuality, a_u32Quality);
}

template <typename T, typename C>
GE_FORCE_INLINE GEBool FindInventoryStacksSC(gCInventory_PS const &a_Inventory, T a_Item, C a_fCallback,
                                             gEInventoryFindQuality a_FindQuality = gEInventoryFindQuality_Ignore,
                                             GEU32 a_u32Quality = 0)
{
    return FindInventoryStacksIC(
        a_Inventory, a_Item, [&](GEInt iItemIndex) { return a_fCallback(*a_Inventory.GetStack(iItemIndex)); },
        a_FindQuality, a_u32Quality);
}

template <typename T, typename C>
GE_FORCE_INLINE void FindInventoryStacksS(gCInventory_PS const &a_Inventory, T a_Item, C a_fCallback,
                                          gEInventoryFindQuality a_FindQuality = gEInventoryFindQuality_Ignore,
                                          GEU32 a_u32Quality = 0)
{
    FindInventoryStacksI(
        a_Inventory, a_Item, [&](GEInt iItemIndex) { a_fCallback(*a_Inventory.GetStack(iItemIndex)); }, a_FindQuality,
        a_u32Quality);
}

template <typename T, typename C>
GE_FORCE_INLINE GEBool FindInventoryStacksISC(gCInventory_PS const &a_Inventory, T a_Item, C a_fCallback,
                                              gEInventoryFindQuality a_FindQuality = gEInventoryFindQuality_Ignore,
                                              GEU32 a_u32Quality = 0)
{
    return FindInventoryStacksIC(
        a_Inventory, a_Item,
        [&](GEInt iItemIndex) { return a_fCallback(iItemIndex, *a_Inventory.GetStack(iItemIndex)); }, a_FindQuality,
        a_u32Quality);
}

template <typename T, typename C>
GE_FORCE_INLINE void FindInventoryStacksIS(gCInventory_PS const &a_Inventory, T a_Item, C a_fCallback,
                                           gEInventoryFindQuality a_FindQuality = gEInventoryFindQuality_Ignore,
                                           GEU32 a_u32Quality = 0)
{
    FindInventoryStacksI(
        a_Inventory, a_Item, [&](GEInt iItemIndex) { a_fCallback(iItemIndex, *a_Inventory.GetStack(iItemIndex)); },
        a_FindQuality, a_u32Quality);
}

template <typename T>
GEInt GetItemAmount(gCInventory_PS const &a_Inventory, T a_Item)
{
    GEInt iAmount = 0;
    FindInventoryStacksS(a_Inventory, a_Item,
                         [&](gCInventoryStack const &ItemStack) { iAmount += ItemStack.GetAmount(); });
    return iAmount;
}

template <typename T>
GEBool IsEquipped(gCInventory_PS const &a_Inventory, T a_Item)
{
    return FindInventoryStacksSC(a_Inventory, a_Item,
                                 [](gCInventoryStack const &ItemStack) { return ItemStack.GetSlot() != gESlot_None; });
}

template <typename T>
GEBool HasItems(gCInventory_PS const &a_Inventory, T a_Item, gEStackType a_StackType)
{
    return FindInventoryStacksSC(a_Inventory, a_Item,
                                 [&](gCInventoryStack const &ItemStack) { return ItemStack.GetType() == a_StackType; });
}

template <typename T>
T *GetPropertySet(eCEntity *a_pEntity, eEPropertySetType a_Type)
{
    return a_pEntity ? dynamic_cast<T *>(a_pEntity->GetPropertySet(a_Type)) : 0;
}

template <typename T>
T const *GetPropertySet(eCEntity const *a_pEntity, eEPropertySetType a_Type)
{
    return a_pEntity ? dynamic_cast<T const *>(a_pEntity->GetPropertySet(a_Type)) : 0;
}

template <typename T>
T *FindModule()
{
    // Ensure FindModule is only used for engine modules
    static_cast<eCEngineComponentBase *>(static_cast<T *>(nullptr));

    static T *s_pModule = dynamic_cast<T *>(eCModuleAdmin::GetInstance().FindModule(bTClassName<T>::GetUnmangled()));
    return s_pModule;
}

template <typename T>
bCString JoinString(bTArrayBase<T> const &a_arrObjects, bCString (*a_fConverter)(T const &), GEInt a_iOffset = 0,
                    bCString const &a_rDelimiter = " ", GEInt a_iEnd = -1)
{
    GEInt iCount = a_arrObjects.GetCount();
    if (iCount == 0 || a_iOffset >= iCount)
        return "";

    a_iEnd = a_iEnd == -1 || a_iEnd > iCount ? iCount : a_iEnd;

    bCString Result = a_fConverter(a_arrObjects[a_iOffset]);
    for (GEInt i = a_iOffset + 1; i < a_iEnd; i++)
        Result += a_rDelimiter + a_fConverter(a_arrObjects[i]);

    return Result;
}

template <typename T>
bCString JoinStringImm(bTArrayBase<T> const &a_arrObjects, bCString (*a_fConverter)(T), GEInt a_iOffset = 0,
                       bCString const &a_rDelimiter = " ", GEInt a_iEnd = -1)
{
    GEInt iCount = a_arrObjects.GetCount();
    if (iCount == 0 || a_iOffset >= iCount)
        return "";

    a_iEnd = a_iEnd == -1 || a_iEnd > iCount ? iCount : a_iEnd;

    bCString Result = a_fConverter(a_arrObjects[a_iOffset]);
    for (GEInt i = a_iOffset + 1; i < a_iEnd; i++)
        Result += a_rDelimiter + a_fConverter(a_arrObjects[i]);

    return Result;
}

template <typename T, typename F = T>
bCString JoinString(bTArrayBase<T> const &a_arrObjects, char const *a_FormatString, GEInt a_iOffset = 0,
                    bCString const &a_rDelimiter = " ", GEInt a_iEnd = -1)
{
    GEInt iCount = a_arrObjects.GetCount();
    if (iCount == 0 || a_iOffset >= iCount)
        return "";

    a_iEnd = a_iEnd == -1 || a_iEnd > iCount ? iCount : a_iEnd;

    bCString Result = bCString::GetFormattedString(a_FormatString, static_cast<F const &>(a_arrObjects[a_iOffset]));
    for (GEInt i = a_iOffset + 1; i < a_iEnd; i++)
        Result += a_rDelimiter + bCString::GetFormattedString(a_FormatString, static_cast<F const &>(a_arrObjects[i]));

    return Result;
}

template <typename A, typename T>
A SplitString(bCString const &a_rString, bCString const &a_rDelimiters, T (*a_fConverter)(bCString const &),
              GEBool a_bTrimLeft = GETrue, GEBool a_bTrimRight = GETrue)
{
    GEInt iWordCount = a_rString.CountWords(a_rDelimiters);
    A arrSplitted(iWordCount);
    for (GEInt i = 0; i < iWordCount; i++)
    {
        bCString strWord;
        a_rString.GetWord(i, a_rDelimiters, strWord, a_bTrimLeft, a_bTrimRight);
        arrSplitted.Add(a_fConverter(strWord));
    }
    return arrSplitted;
}

template <typename T>
bCString EntityProxyToString(T const &a_EntityProxy)
{
    if (a_EntityProxy.GetEntity())
        return a_EntityProxy.GetEntity()->GetName() + " | " + a_EntityProxy.GetEntityID().GetText();
    return a_EntityProxy.GetEntityID().GetText();
}

template <typename T>
bTObjArray<T> CopyRange(bTObjArray<T> &a_arrElements, GEInt a_iStart, GEInt a_iEnd = -1)
{
    GEInt iElementCount = a_arrElements.GetCount();
    if (iElementCount == 0)
        return bTObjArray<T>();

    a_iEnd = a_iEnd != -1 ? a_iEnd : iElementCount;

    bTObjArray<T> arrResult(a_iEnd - a_iStart);
    for (GEInt i = a_iStart; i < a_iEnd; i++)
        arrResult.Add(a_arrElements[i]);

    return arrResult;
}

template <typename T>
void CallConstructor(GELPCChar a_strModule, T *m_pUnitialized)
{
    GELPVoid pConstructor = GetConstructor<T>(a_strModule);
    force_cast<void(GE_FASTCALL *)(T *)>(pConstructor)(m_pUnitialized);
}

template <typename T>
void CallVbTableConstructor(GELPCChar a_strModule, T *m_pUnitialized)
{
    GELPVoid pConstructor = GetConstructor<T>(a_strModule);
    force_cast<void(GE_FASTCALL *)(T *, GEInt, GEInt)>(pConstructor)(m_pUnitialized, /* dummy value to fill eax*/ 0, 1);
}

template <typename T>
GELPVoid GetConstructor(GELPCChar a_strModule)
{
    return GetProcAddress(a_strModule, "??0" + bTClassName<T>::GetUnmangled() + "@@QAE@XZ");
}

template <typename T>
GELPVoid GetDestructor(GELPCChar a_strModule)
{
    return GetProcAddress(a_strModule, "??1" + bTClassName<T>::GetUnmangled() + "@@QAE@XZ");
}

template <typename T>
GELPVoid GetVirtualDestructor(GELPCChar a_strModule)
{
    return GetProcAddress(a_strModule, "??1" + bTClassName<T>::GetUnmangled() + "@@UAE@XZ");
}

template <typename T>
inline T Read(bCIStream &a_InputStream)
{
    T Temp;
    Temp << a_InputStream;
    return Temp;
}

template <typename K, typename T>
void WriteMap(bCOStream &a_OutputStream, bTValMap<K, T> &a_Map)
{
    a_OutputStream << a_Map.GetCount();
    GE_MAP_FOR_EACH (Key, Value, a_Map)
    {
        Key >> a_OutputStream;
        Value >> a_OutputStream;
    }
}

template <typename K, typename T>
bCOStream &operator>>(bTValMap<K, T> &a_Map, bCOStream &a_OutputStream)
{
    WriteMap(a_OutputStream, a_Map);
    return a_OutputStream;
}

template <typename K, typename T>
void ReadMap(bCIStream &a_InputStream, bTValMap<K, T> &a_Map)
{
    a_Map.Clear();
    GEInt Count;
    a_InputStream >> Count;
    while (Count > 0)
    {
        K Key;
        T Value;
        Key << a_InputStream;
        Value << a_InputStream;
        a_Map.SetAt(Key, Value);

        Count--;
    }
}

template <typename K, typename T>
bCIStream &operator<<(bTValMap<K, T> &a_Map, bCIStream &a_InputStream)
{
    ReadMap(a_InputStream, a_Map);
    return a_InputStream;
}

struct CpuFeature
{
  private:
    enum Reg
    {
        Eax = 0,
        Ebx = 1,
        Ecx = 2,
        Edx = 3
    };

  public:
    struct Identifier
    {
        GEUInt FunctionId;
        GEUInt SubfunctionId;
        Reg RegId;
        GEUInt Bit;

        operator GEBool() const;
    };

    static constexpr Identifier Lzcnt{0x80000001, 0, Ecx, 5};
    static constexpr Identifier Avx{1, 0, Ecx, 28};
    static constexpr Identifier Avx2{7, 0, Ebx, 5};
};

#include "Util.inl"
