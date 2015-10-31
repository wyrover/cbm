@echo off

rem thrift -gen php:server Hello.thrift  生成php的服务端需要加server
thrift.exe -r --gen php:server msis.thrift
rem生成php客户端代码
rem thrift.exe -r --gen php msis.thrift
xcopy "gen-php" "..\php\gen-py\"  /c /e /y
