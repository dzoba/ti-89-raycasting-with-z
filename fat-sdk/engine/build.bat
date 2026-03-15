@echo off
echo Generating FATLIB.DLL ...
tigcc -Wall -W -Wwrite-strings -O3 fat.c
ttstrip fat.89z fat.bin
ttbin2oth -89 dll fat.bin fatlib
ttbin2oth -92 dll fat.bin fatlib
del fat.bin
del fat.89z
del fat.9xz
copy fatlib.89y ..\..\bin89
copy fatlib.9xy ..\..\bin92p
del fatlib.89y
del fatlib.9xy
echo Generating FATLIB_C.DLL (console version) ...
tigcc -Wall -W -Wwrite-strings -DFAT_WITHCONSOLE -O3 fat.c
ttstrip fat.89z fat.bin
ttbin2oth -89 dll fat.bin fatlib_c
ttbin2oth -92 dll fat.bin fatlib_c
del fat.bin
del fat.89z
del fat.9xz
copy fatlib_c.89y ..\..\bin89
copy fatlib_c.9xy ..\..\bin92p
del fatlib_c.89y
del fatlib_c.9xy

@echo on
