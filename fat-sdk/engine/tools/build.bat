@echo off
echo building tablemaker ...
lcc tablemaker.c
lcclnk tablemaker.obj
del tablemaker.obj
echo building genscalers ...
lcc genscalers.c
lcclnk genscalers.obj
del genscalers.obj
echo building gentransscalers ...
lcc gentransscalers.c
lcclnk gentransscalers.obj
del gentransscalers.obj

echo generating tables.c ...
tablemaker > ..\tables.c

echo generating scalers.c ...
genscalers > ..\scalers.c

echo generating transscalers.c ...
gentransscalers > ..\transscalers.c

@echo on