cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat x64
cl /c /DEBUG ext\*.c -I"..\..\language\include" -I"ext\"
link /DEBUG *.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_sockets.dll 
del *.obj
endlocal