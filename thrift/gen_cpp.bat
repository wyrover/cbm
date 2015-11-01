@echo off

rem 生成c++代码
call gen_code.bat cpp

rd /s /q "..\RpcDao\gen-cpp\"
md "..\RpcDao\gen-cpp\"

rem 复制通过IDL生成的cpp代码
xcopy "gen-cpp" "..\RpcDao\gen-cpp\"  /c /e /y

rem 暂停
pause