@echo off
REM tex1.bin contains 6 tiles
..\..\bin\fixtex64 tex1.bin tex1tmp.bin 3 2
..\..\bin\tex2hdr -quiet -prefix TEX1_ tex1tmp.bin - > textures.h
del tex1tmp.bin
REM tex2.bin contains 6 tiles
..\..\bin\fixtex64 tex2.bin tex2tmp.bin 3 2
..\..\bin\tex2hdr -quiet -prefix TEX2_ tex2tmp.bin - >> textures.h
del tex2tmp.bin
REM tex3.bin contains 4 tiles
..\..\bin\fixtex64 tex3.bin tex3tmp.bin 2 2
..\..\bin\tex2hdr -quiet -prefix TEX3_ tex3tmp.bin - >> textures.h
del tex3tmp.bin
REM tex4.bin contains 4 tiles
..\..\bin\fixtex64 tex4.bin tex4tmp.bin 2 2
..\..\bin\tex2hdr -quiet -prefix TEX4_ tex4tmp.bin - >> textures.h
del tex4tmp.bin
