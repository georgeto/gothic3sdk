#include <stdio.h>
#include "Util.h"
#include "Logging.h"
#include "Debug.h"

bCString Trim(bCString const & a_rString, GEBool a_bTrimLeft, GEBool a_bTrimRight)
{
    bCString strResult = a_rString;
    strResult.Trim(a_bTrimLeft, a_bTrimRight);
    return strResult;
}

bCString GetWord(bCString const & a_rString, GEInt a_iWordNumber, bCString const & a_rDelimiters, GEBool a_bTrimLeft, GEBool a_bTrimRight)
{
    bCString strDest;
    a_rString.GetWord(a_iWordNumber, a_rDelimiters, strDest, a_bTrimLeft, a_bTrimRight);
    return strDest;
}

bCString NextWord(bCString const & a_rString, GEInt a_iStartIndex, bCString const & a_rDelimiters, GEBool a_bTrimLeft, GEBool a_bTrimRight)
{
    GEInt iEndIndex = a_rString.FindOneOf(a_rDelimiters, a_iStartIndex);
    if (iEndIndex == -1)
        iEndIndex = a_rString.GetLength();
    return Trim(a_rString.Mid(a_iStartIndex, iEndIndex - a_iStartIndex), a_bTrimLeft, a_bTrimRight);
}

bCString GetWords(bCString const & a_rString, GEInt a_iStart, bCString const & a_rDelimiters, GEInt a_iEnd, GEBool a_bTrimLeft, GEBool a_bTrimRight)
{
    G3SCRIPT_ASSERT(a_iStart > 0);
    G3SCRIPT_ASSERT(a_iEnd == -1 || a_iStart < a_iEnd);

    GEInt iStartIndex = -1, iEndIndex = -1;
    GEInt iIndex = 0, iWord = 0;
    while ((iIndex = a_rString.FindOneOf(a_rDelimiters, iIndex)) != -1)
    {
        if (a_iStart == iWord)
            iStartIndex = iIndex;
        else if (a_iEnd == iWord)
            iEndIndex = iIndex;
        iWord++;
    }

    if(iStartIndex == -1)
        return "";

    if(iStartIndex == 0)
        iStartIndex++;

    if(a_iEnd == -1 || iEndIndex == -1)
        iEndIndex = a_rString.GetLength();

    return Trim(a_rString.Mid(iStartIndex, iEndIndex - iStartIndex), a_bTrimLeft, a_bTrimRight);
}

bTObjArray< bCString > SplitString(bCString const & a_rString, bCString const & a_rDelimiters, GEBool a_bTrimLeft, GEBool a_bTrimRight)
{
    GEInt iWordCount = a_rString.CountWords(a_rDelimiters);
    bTObjArray< bCString > arrSplitted(iWordCount);
    for( GEInt i = 0; i < iWordCount; i++ )
    {
       bCString strWord;
       a_rString.GetWord(i, a_rDelimiters, strWord, a_bTrimLeft, a_bTrimRight);
       arrSplitted.Add(strWord);
    }
    return arrSplitted;
}

bCString JoinString( bTObjArray< bCString > const & a_arrStrings, GEInt a_iOffset, bCString const & a_rDelimiter, GEInt a_iEnd )
{
    GEInt iStringCount = a_arrStrings.GetCount();
    if( iStringCount == 0 || a_iOffset >= iStringCount)
        return "";

    a_iEnd = a_iEnd == -1 || a_iEnd > iStringCount ? iStringCount : a_iEnd;

    bCString Result = a_arrStrings[a_iOffset];
    for( GEInt i = a_iOffset + 1; i < a_iEnd; i++ )
        Result += a_rDelimiter + a_arrStrings[i];

    return Result;
}


GEBool AutoCompleteString(bTObjArray< bCString > const & a_arrStrings, bCString & a_strFragment, GEBool a_bBackward )
{
    if( a_arrStrings.GetCount() == 0 )
        return GEFalse;

    if( a_strFragment.IsEmpty() )
        return a_strFragment = a_arrStrings[0], GETrue;

    GEInt iStringIndex = -1;
    for( GEInt i = 0; i < a_arrStrings.GetCount(); i++ ) // find match
        if ( a_arrStrings[i].CompareNoCaseFast( a_strFragment ) )
        {
            iStringIndex = i;
            break;
        }

    if( iStringIndex != -1 ) // cycle strings
    {
        GEInt iNextIndex = iStringIndex + ( a_bBackward ? -1 : 1 ) ;

        if( iNextIndex < 0 )
            iNextIndex = 0;

        if( iNextIndex >= a_arrStrings.GetCount() )
            iNextIndex = a_arrStrings.GetCount() - 1;

        return a_strFragment = a_arrStrings[iNextIndex], GETrue;
    }


    for( GEInt i = 0; i < a_arrStrings.GetCount(); i++ )
    {
        if ( a_arrStrings[i].FindNoCase( a_strFragment, 0 ) == 0 ) // starts with
            return a_strFragment = a_arrStrings[i], GETrue;
    }

    for( GEInt i = 0; i < a_arrStrings.GetCount(); i++ )
    {
        if ( a_arrStrings[i].FindNoCase( a_strFragment, 0 ) != -1 ) // contains
            return a_strFragment = a_arrStrings[i], GETrue;
    }

    return GEFalse;
}

GEBool ParseDuration(bCString const & a_strDuration, GEU32 * o_uDuration)
{
    static bCString s_strNumeric("0123456789");

    bCString strDuration = a_strDuration;
    strDuration.ToLower();
    strDuration.Replace(" ", "");
    strDuration.Replace("\t", "");

    GEU32 uDuration = 0;
    GEInt iStartToken = 0;
    for(GEInt i = 0; i < strDuration.GetLength(); i++)
    {
        GEChar Token = strDuration[i];
        if(s_strNumeric.Contains(Token))
            continue;

        GEU32 uMultiplier;
        if(Token == 'y')
        {
            uMultiplier = 3600 * 24 * 365;
        }
        else if(Token == 'd')
        {
            uMultiplier = 3600 * 24;
        }
        else if(Token == 'h')
        {
            uMultiplier = 3600;
        }
        else if(Token == 'm')
        {
            uMultiplier = 60;
        }
        else if(Token == 's')
        {
            uMultiplier = 1;
        }
        else
            return GEFalse;

        uDuration += strDuration.Mid(iStartToken, i).GetInteger() * uMultiplier;
        iStartToken = i + 1;
    }

    if(iStartToken != strDuration.GetLength())
        return GEFalse;

    if(o_uDuration)
        *o_uDuration = uDuration;
    return GETrue;
}

bCString GetGothicPath()
{
    eCVirtualFileSystem & VirtualFileSystem = eCVirtualFileSystem::GetInstance();
    return VirtualFileSystem.GetRootPath();
}

GEBool FromFile( GELPCChar a_strFile, bCMemoryStream & o_MemoryStream )
{
    FILE * pFile;
    if( fopen_s( &pFile, a_strFile, "rb" ) )
        return GEFalse;

    fseek(pFile, 0, SEEK_END);
    GEI32 iSize = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);
    o_MemoryStream.SetCount(iSize);

    o_MemoryStream.Seek(0, bEStreamSeekMode_Begin);
    fread(o_MemoryStream.AccessBuffer(0), static_cast<size_t>(o_MemoryStream.GetSize()), 1, pFile);
    fclose(pFile);

    return GETrue;
}

GEBool ToFile( bCMemoryStream & a_MemoryStream, GELPCChar a_strFile )
{
    FILE * pFile;
    if( fopen_s( &pFile, a_strFile, "wb" ) )
        return GEFalse;
    GEI64 iOldPosition = a_MemoryStream.GetPosition();
    a_MemoryStream.Seek( 0, bEStreamSeekMode_Begin );
    fwrite( a_MemoryStream.GetBuffer(0), sizeof(GEByte), static_cast< GEUInt >( a_MemoryStream.GetSize() ), pFile );
    fclose( pFile );
    a_MemoryStream.Seek( iOldPosition, bEStreamSeekMode_Begin );
    return GETrue;
}

namespace
{
    class eCConfigFilePhysFile
        : public eCConfigFile
    {
        public:
            GEBool ReadFile( bCIStream & a_IStream )
            {
                eCConfigFile::ReadFile(a_IStream);
            }
    };
}

GEBool ReadPhysConfigFile( GELPCChar a_strFile, eCConfigFile & o_ConfigFile )
{
    bCMemoryStream ConfigFileData;
    if(!FromFile(a_strFile, ConfigFileData))
        return false;

    return static_cast<eCConfigFilePhysFile &>(o_ConfigFile).ReadFile(ConfigFileData);
}

void DestroyPhysConfigFile( eCConfigFile & a_ConfigFile )
{
    // Prevent write-back to disk, which will fail as the config was loaded from a memory stream.
    a_ConfigFile.Invalidate();
}

bCString GetPhysicalFilePath( bCString const & a_strFilePath )
{
    eCArchiveFile File = eCArchiveManager::GetInstance().GetFile( a_strFilePath );
    bCString strPhysicalPath;
    if ( !File.IsValid() || !File.GetPhysicalPath(strPhysicalPath) )
        return "";

    return strPhysicalPath;
}

GEBool IsPhysical( bCString const & a_strFilePath )
{
    eCArchiveFile File = eCArchiveManager::GetInstance().GetFile( a_strFilePath );
    if ( !File.IsValid() )
        return GEFalse;
    bCString strPhysicalPath;
    return File.GetPhysicalPath(strPhysicalPath);
}

bCString VectorToString( bCVector const & a_Vector, GEBool a_bAppendMarvin )
{
    if(!a_bAppendMarvin)
        return bCString::GetFormattedString("X: %f, Y: %f, Z: %f", a_Vector.GetX(), a_Vector.GetY(), a_Vector.GetZ());
    else
        return bCString::GetFormattedString("X: %f, Y: %f, Z: %f (%d/%d/%d//)", a_Vector.GetX(), a_Vector.GetY(), a_Vector.GetZ(), RoundFloat(a_Vector.GetX()), RoundFloat(a_Vector.GetY()), RoundFloat(a_Vector.GetZ()));
}

bCString VectorToMarvinString(bCVector const & a_Vector)
{
    return bCString::GetFormattedString("%d/%d/%d//", RoundFloat(a_Vector.GetX()), RoundFloat(a_Vector.GetY()), RoundFloat(a_Vector.GetZ()));
}

GEBool MarvinStringToVector(bCString const & a_strInput, bCVector & o_Vector)
{
    bCString strInput = a_strInput;
    if(strInput.Contains("//"))
        strInput = strInput.Left(strInput.Find("//"));

    bTObjArray<bCString> arrSplitted = SplitString(strInput, "/");
    if(arrSplitted.GetCount() != 3)
        return GEFalse;

    o_Vector = bCVector(arrSplitted[0].GetFloat(), arrSplitted[1].GetFloat(), arrSplitted[2].GetFloat());
    return GETrue;
}

bCString BoxToString( bCBox const & a_Box )
{
    return bCString::GetFormattedString("[min: (%f, %f, %f), max: (%f, %f, %f)]", a_Box.GetMin().GetX(), a_Box.GetMin().GetY(), a_Box.GetMin().GetZ(), a_Box.GetMax().GetX(), a_Box.GetMax().GetY(), a_Box.GetMax().GetZ());
}

bCString MatrixToString( bCMatrix const & a_Matrix )
{
    return bCString::GetFormattedString("[(%f, %f, %f, %f),\n (%f, %f, %f, %f),\n (%f, %f, %f, %f),\n (%f, %f, %f, %f)]",
        a_Matrix.GetXAxis4().GetX(), a_Matrix.GetXAxis4().GetY(), a_Matrix.GetXAxis4().GetZ(), a_Matrix.GetXAxis4().GetW(),
        a_Matrix.GetYAxis4().GetX(), a_Matrix.GetYAxis4().GetY(), a_Matrix.GetYAxis4().GetZ(), a_Matrix.GetYAxis4().GetW(),
        a_Matrix.GetZAxis4().GetX(), a_Matrix.GetZAxis4().GetY(), a_Matrix.GetZAxis4().GetZ(), a_Matrix.GetZAxis4().GetW(),
        a_Matrix.GetTranslation4().GetX(), a_Matrix.GetTranslation4().GetY(), a_Matrix.GetTranslation4().GetZ(), a_Matrix.GetTranslation4().GetW());
}

bCString BoolToString(GEBool a_Bool) {
    return a_Bool ? "true" : "false";
}

GEInt RoundFloat(GEFloat f)
{
    return (GEInt) (f >= 0.0f ? f + 0.49999997f : f - 0.49999997f);
}

bCUnicodeString FromUTF8(GELPCByte a_pSource, GEInt a_iLength )
{
    int wchars_num = MultiByteToWideChar( CP_UTF8, 0, reinterpret_cast<LPCSTR>(a_pSource), a_iLength, NULL, 0 );
    wchar_t* wstr = new wchar_t[wchars_num + 1];
    wstr[wchars_num] = 0;
    MultiByteToWideChar( CP_UTF8, 0, reinterpret_cast<LPCSTR>(a_pSource), a_iLength, wstr, wchars_num );
    bCUnicodeString Result( wstr, wchars_num );
    delete[] wstr;
    return Result;
}

GEBool StartsWith(bCString const & a_strValue, GELPCChar a_strPattern)
{
    return a_strValue.Find(a_strPattern) == 0;
}

GEBool StartsWith(bCString const & a_strValue, GEChar a_chPattern)
{
    return a_strValue.GetLength() > 0 && a_strValue.GetAt(0) == a_chPattern;
}

GEBool EndsWith(bCString const & a_strValue, GELPCChar a_strPattern)
{
    return a_strValue.ReverseFind(a_strPattern) == a_strValue.GetLength() - 1;
}

GEBool EndsWith(bCString const & a_strValue, GEChar a_chPattern)
{
    return a_strValue.GetLength() > 0 && a_strValue.GetAt(a_strValue.GetLength() - 1) == a_chPattern;
}

GEInt IndexOf(const GELPCChar a_arrData[], GEInt a_iDataCount, bCString a_strValue, GEBool a_bIgnoreCase)
{
    for(GEInt i = 0; i < a_iDataCount; i++)
    {
        if((!a_bIgnoreCase && a_arrData[i] == a_strValue) || (a_bIgnoreCase && a_strValue.CompareNoCaseFast(a_arrData[i]) ))
            return i;
    }

    return -1;
}

bCString GetSystemTimeString()
{
    bCDateTime SystemTime;
    SystemTime.Update();
    bCString strSystemTime;
    SystemTime.GetTimeString(strSystemTime);
    return strSystemTime;
}

bCString FormatDate(bCDateTime const & a_Date, bCString const & a_strFormat)
{
    FILETIME LocalFileTime;
    SYSTEMTIME SystemTime;
    FileTimeToLocalFileTime(reinterpret_cast<FILETIME const *>(&a_Date), &LocalFileTime);
    FileTimeToSystemTime(&LocalFileTime, &SystemTime);

    TCHAR Result[256];
    GetDateFormat(LOCALE_USER_DEFAULT, 0, &SystemTime, a_strFormat.GetText(), Result, 256);
    return bCString(Result);
}

bCString FormatTime(bCDateTime const & a_Time, bCString const & a_strFormat)
{
    FILETIME LocalFileTime;
    SYSTEMTIME SystemTime;
    FileTimeToLocalFileTime(reinterpret_cast<FILETIME const *>(&a_Time), &LocalFileTime);
    FileTimeToSystemTime(&LocalFileTime, &SystemTime);

    TCHAR Result[256];
    GetTimeFormat(LOCALE_USER_DEFAULT, 0, &SystemTime, a_strFormat.GetText(), Result, 256);
    return bCString(Result);
}

GELPByte GetGamePage(gCGUIManager * a_pGUIManager, gEGamePage a_Page)
{
    GELPByte pPageContainer = *reinterpret_cast<GELPByte *>(reinterpret_cast<GELPByte>(a_pGUIManager) + 4);
    if(pPageContainer)
        return *reinterpret_cast<GELPByte *>(pPageContainer + 0x38 + a_Page * 0x04);
    return 0;
}

gCLayerBase * GetLayer( bCString const & a_strName )
{
    gCWorld * pWorld = gCWorld::GetCurrentWorld();
    for ( GEInt i = 0; i < pWorld->GetSectorCount(); i++ )
    {
        gCSector * pSector = pWorld->GetSectorAt( i );
        for ( GEInt i = 0; i < pSector->GetDynamicLayerCount(); i++ )
            if ( a_strName.CompareFast( pSector->GetDynamicLayerAt(i)->GetFileBaseName() ) )
                return pSector->GetDynamicLayerAt(i);

        for ( GEInt i = 0; i < pSector->GetGeometryLayerCount(); i++ )
            if ( a_strName.CompareFast( pSector->GetGeometryLayerAt(i)->GetFileBaseName() ) )
                return pSector->GetGeometryLayerAt(i);
    }
    return 0;
}

eCGeometrySpatialContext * GetGeometrySpatialContext( bCString const & a_strName )
{
    eCSceneAdmin * pSceneAdmin = FindModule<eCSceneAdmin>();
    for ( GEInt i = 0; i < pSceneAdmin->GetSpatialContextCount(); i++ ) {
        if ( a_strName.CompareFast( pSceneAdmin->GetSpatialContext(i)->GetFileBaseName() ) )
            return pSceneAdmin->GetSpatialContext(i);
    }

    return 0;
}

gCEnclave_PS * GetEnclave( bCString const & a_strName )
{
    bTValArray<gCEnclave_PS *> const & arrEnclave = gCEnclaveAdmin::GetInstance().GetEnclaves();
    for( GEInt i = 0; i < arrEnclave.GetCount(); i++ )
    {
        gCEnclave_PS * pEnclavePS = arrEnclave[i];
        eCEntity const * pEnclave = pEnclavePS ? pEnclavePS->GetEntity() : 0;
        if(pEnclave && pEnclave->GetName() == a_strName)
            return pEnclavePS;
    }
    return 0;
}

bCString ToString(gEPoliticalAlignment a_PoliticalAlignment)
{
    switch(a_PoliticalAlignment)
    {
        case gEPoliticalAlignment_None:
            return "None";
        case gEPoliticalAlignment_Orc:
            return "Orc";
        case gEPoliticalAlignment_Nrd:
            return "Nrd";
        case gEPoliticalAlignment_Reb:
            return "Reb";
        case gEPoliticalAlignment_Mid:
            return "Mid";
        case gEPoliticalAlignment_Ass:
            return "Ass";
        case gEPoliticalAlignment_Nom:
            return "Nom";
        case gEPoliticalAlignment_Out:
            return "Out";
        case gEPoliticalAlignment_Slave:
            return "Slave";
        case gEPoliticalAlignment_Pirate:
            return "Pir";
        case gEPoliticalAlignment_Citizen:
            return "Citizen";
        case gEPoliticalAlignment_Mid_Torn:
            return "Mid_Torn";
        case gEPoliticalAlignment_Partisan:
            return "Partisan";
        case gEPoliticalAlignment_Bakaresh:
            return "Bakaresh";
        case gEPoliticalAlignment_Gonzalez:
            return "Gonzalez";
        default:
            return "<Unknown>";
    }

}

bCString ToString(gEQuestStatus a_QuestStatus)
{
    switch(a_QuestStatus)
    {
        case gEQuestStatus_Open:
            return "Open";
        case gEQuestStatus_Running:
            return "Running";
        case gEQuestStatus_Success:
            return "Success";
        case gEQuestStatus_Failed:
            return "Failed";
        case gEQuestStatus_Obsolete:
            return "Obsolete";
        case gEQuestStatus_Cancelled:
            return "Cancelled";
        case gEQuestStatus_Lost:
            return "Lost";
        case gEQuestStatus_Won:
            return "Won";
        default:
            return "<Unknown>";
    }
}

eCDynamicEntity * GetHero(void)
{
    return gCSession::GetInstance().GetHero();
}

eCDynamicEntity * GetPlayer(void)
{
    return gCSession::GetInstance().GetPlayer();
}


GEBool IsPlayer(eCEntity const * a_pEntity) {
    return a_pEntity == GetPlayer();
}

gCClock_PS * GetClock(void) {
    gCWorld * pWorld = gCWorld::GetCurrentWorld();
    return pWorld ? GetPropertySet<gCClock_PS>(pWorld->GetWorldEntity(), eEPropertySetType_Clock) : 0;
}

GEInt GetBaseMaximum(gCAttribute const & a_pAttribute)
{
    if(gCStat const * pStat = dynamic_cast<gCStat const *>(&a_pAttribute))
    {
        return pStat->GetBaseMaximum();
    }
    else
    {
        return a_pAttribute.GetBaseValue();
    }
}

void UnregisterModule(eCEngineComponentBase const * a_pModule)
{
    bTPtrArray<eCEngineComponentBase *> & arrModules = *reinterpret_cast<bTPtrArray<eCEngineComponentBase *> *>(reinterpret_cast<GELPChar>(&eCModuleAdmin::GetInstance()) + 0x34);
    for(GEInt i = 0; i < arrModules.GetCount(); i++)
    {
        if(arrModules[i] == a_pModule)
        {
            arrModules.RemoveAt(i);
            return;
        }
    }
}

bTObjArray<bCString> GetEnumStringValues( bCPropertyTypeBase const & a_PropertyType )
{
    bTObjArray<bCString> arrStringValues;
    if(a_PropertyType.HasEnumValues())
    {
        for(GEInt i = 0; i < a_PropertyType.GetEnumValueCount(); i++)
        {
            bCEnumWrapper const * pEnumValue = a_PropertyType.GetEnumValue(i);
            arrStringValues.Add(pEnumValue->GetValueString());
        }
    }

    return arrStringValues;
}