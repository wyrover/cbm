@echo off

rem 生成php的服务端需要加server
call gen_code.bat php:server

rem 生成php客户端代码
rem call gen_code.bat php

rem 复制php代码
xcopy "gen-php" "..\php\gen-php\"  /c /e /y

rem 暂停
pause