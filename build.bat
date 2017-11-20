@echo off

set CompilerFlags=-nologo /fp:fast /GR /EHa /WX -FC -Z7
set LinkerFlags=/link user32.lib gdi32.lib

IF NOT EXIST build mkdir build
pushd build

cl %CompilerFlags% ..\main.cpp %LinkerFlags%

popd