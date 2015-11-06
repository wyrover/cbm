@echo off

rem 生成py代码
call gen_code.bat py

rd /s /q "..\python\flask\gen-py\"
rd /s /q "..\python\flask\thrift\"
md "..\python\flask\gen-py\"
md "..\python\flask\thrift\"

rem 复制thrift的py模块
xcopy "..\ThirdParty\thrift\py\thrift"  "..\python\flask\thrift\"  /c /e /y
rem 复制通过IDL生成的py代码
xcopy "gen-py" "..\python\flask\gen-py\"  /c /e /y

rem 利用sqlacodegen工具，从msyql数据库中读取表信息，自动生成满足sqlalchemy格式的py代码
sqlacodegen mysql+pymysql://root:@localhost/cbm --outfile sql.py

rem 复制sql.py
copy /y sql.py "..\python\flask\"
copy /y SQLServerHelper.py "..\python\flask\"
copy /y SQLClientHelper.py "..\python\flask\"

rem 暂停
pause