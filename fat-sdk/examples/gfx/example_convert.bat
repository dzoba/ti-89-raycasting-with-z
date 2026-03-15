..\..\..\bin\fixtex64 d3_textures.bin d3tmp.bin 1 2
ttbin2hex -b4 -c 8 -lb 256 d3tmp.bin d3_textures.txt
del d3tmp.bin
