@echo off
..\..\..\bin\texmaker -i ..\indices.h textures.txt fatdtx
copy fatdtx.89y ..\..\..\bin89
copy fatdtx.9xy ..\..\..\bin92p
del fatdtx.89y
del fatdtx.9xy
