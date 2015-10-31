@echo off

thrift.exe -r --gen %1 entity.thrift
thrift.exe -r --gen %1 cbm.thrift
thrift.exe -r --gen %1 ctrl.thrift