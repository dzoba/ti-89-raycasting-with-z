@echo off
tigcc -O2 -Wall -W -Wwrite-strings %1.c -pack %1pk
copy %1.89y ..\..\bin89\%1pk.89y
copy %1.9xy ..\..\bin92p\%1pk.9xy
del %1.89z
del %1.89y
del %1.9xz
del %1.9xy
@echo on
