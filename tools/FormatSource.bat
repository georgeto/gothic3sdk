@echo off
set _SCRIPT_PATH=%~dp0
set _FILE=%~f1
"%_SCRIPT_PATH%bin\fart.exe" -C "%_FILE%" "\n" "\r\n"
"%_SCRIPT_PATH%bin\fart.exe" -C "%_FILE%" "\r\r\n" "\r\n"

if not "%~2" == "false" (
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "unsigned char const *" "GELPCByte"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "unsigned char *" "GELPByte"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "unsigned char const*" "GELPCByte"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "unsigned char*" "GELPByte"

	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "wchar_t const *" "GELPCUnicodeChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "wchar_t *" "GELPUnicodeChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "wchar_t const*" "GELPCUnicodeChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "wchar_t*" "GELPUnicodeChar"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "wchar_t" "GEUnicodeChar"

	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "char const *" "GELPCChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "char *" "GELPChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "char const*" "GELPCChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "char*" "GELPChar"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "unsigned char" "GEU8"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "signed char" "GEI8"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "char" "GEChar"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "unsigned short" "GEU16"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "short" "GEI16"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "unsigned long" "GEU32"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "long" "GEI32"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "unsigned int" "GEUInt"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "int" "GEInt"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "unsigned __int64" "GEU64"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "__int64" "GEI64"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "bool" "GEBool"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "float" "GEFloat"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%_FILE%" "double" "GEDouble"

	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "void const *" "GELPCVoid"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "void *" "GELPVoid"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "void const*" "GELPCVoid"
	"%_SCRIPT_PATH%bin\fart.exe" "%_FILE%" "void*" "GELPVoid"
)

"%_SCRIPT_PATH%bin\Uncrustify.exe" -l CPP -c "%_SCRIPT_PATH%uncrustify_source.cfg" --no-backup "%_FILE%"
