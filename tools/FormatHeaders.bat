@echo off
set _SCRIPT_PATH=%~dp0
pushd %1
for /R %%i in (*.h) do (
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "unsigned char const *" "GELPCByte"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "unsigned char *" "GELPByte"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "unsigned char const*" "GELPCByte"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "unsigned char*" "GELPByte"

	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "wchar_t const *" "GELPCUnicodeChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "wchar_t *" "GELPUnicodeChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "wchar_t const*" "GELPCUnicodeChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "wchar_t*" "GELPUnicodeChar"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "wchar_t" "GEUnicodeChar"

	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "char const *" "GELPCChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "char *" "GELPChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "char const*" "GELPCChar"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "char*" "GELPChar"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "unsigned char" "GEU8"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "signed char" "GEI8"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "char" "GEChar"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "unsigned short" "GEU16"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "short" "GEI16"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "unsigned long" "GEU32"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "long" "GEI32"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "unsigned int" "GEUInt"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "int" "GEInt"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "unsigned __int64" "GEU64"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "__int64" "GEI64"

	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "bool" "GEBool"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "float" "GEFloat"
	"%_SCRIPT_PATH%bin\fart.exe" -w "%%i" "double" "GEDouble"

	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "void const *" "GELPCVoid"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "void *" "GELPVoid"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "void const*" "GELPCVoid"
	"%_SCRIPT_PATH%bin\fart.exe" "%%i" "void*" "GELPVoid"

	"%_SCRIPT_PATH%bin\Uncrustify.exe" -c "%_SCRIPT_PATH%uncrustify.cfg" --no-backup "%%i"
)
popd