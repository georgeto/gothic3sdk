@echo off
set _SCRIPT_PATH=%~dp0
pushd ..\source
for /R %%i in (*.vcproj) do (
	"%_SCRIPT_PATH%bin\VcprojFormatter.exe" -DECIMAL_POINT:. -ENCODING:UTF-8 -NEWLINE:CRLF "%%i"
)
popd