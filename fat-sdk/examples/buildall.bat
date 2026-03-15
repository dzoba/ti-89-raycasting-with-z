@echo off
echo ------------------------------------
echo Generating FAT Demo Loader ...
echo ------------------------------------
tigcc -Os -Wall -W -Wwrite-strings fatload.c
copy fatload.89z ..\..\bin89
copy fatload.9xz ..\..\bin92p
del fatload.89z
del fatload.9xz
echo ------------------------------------
echo Generating Demo 1 ...
echo ------------------------------------
call buildone.bat fatd1

@echo off
echo ------------------------------------
echo Generating Demo 2 ...
echo ------------------------------------
call buildone.bat fatd2

@echo off
echo ------------------------------------
echo Generating Demo 3 ...
echo ------------------------------------
call buildone.bat fatd3

@echo off
echo ------------------------------------
echo Generating Demo 4 ...
echo ------------------------------------
call buildone.bat fatd4

@echo off
echo ------------------------------------
echo Generating Demo 5 ...
echo ------------------------------------
call buildone.bat fatd5

@echo off
echo ------------------------------------
echo Generating Demo 6 ...
echo ------------------------------------
call buildone.bat fatd6

@echo off
echo ------------------------------------
echo Generating Demo 7 ...
echo ------------------------------------
call buildone.bat fatd7

@echo off
echo ------------------------------------
echo Generating Demo 8 ...
echo ------------------------------------
call buildone.bat fatd8

@echo off
echo ------------------------------------
echo Generating Demo 9 ...
echo ------------------------------------
call buildone.bat fatd9

@echo off
echo ------------------------------------
echo Generating Demo 10 ...
echo ------------------------------------
call buildone.bat fatd10
