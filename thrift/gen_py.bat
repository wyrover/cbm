@echo off

thrift.exe -r --gen py msis.thrift
xcopy "..\ThirdParty\thrift\py\thrift"  "..\python\flask\thrift\"  /c /e /y
xcopy "gen-py" "..\python\flask\gen-py\"  /c /e /y
