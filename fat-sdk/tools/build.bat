@echo off
echo building fixtex64 ...
lcc fixtex64.c
lcclnk fixtex64.obj
del fixtex64.obj
copy fixtex64.exe ..\..\bin
del fixtex64.exe

echo building tex2hdr ...
lcc tex2hdr.c
lcclnk tex2hdr.obj
del tex2hdr.obj
copy tex2hdr.exe ..\..\bin
del tex2hdr.exe

echo building texmaker ...
lcc texmaker.c
lcclnk texmaker.obj
del texmaker.obj
copy texmaker.exe ..\..\bin
del texmaker.exe

echo building bindiff ...
lcc bindiff.c
lcclnk bindiff.obj
del bindiff.obj
copy bindiff.exe ..\..\bin
del bindiff.exe

@echo on
