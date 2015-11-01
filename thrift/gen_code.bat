@echo off

thrift.exe --gen %1 cbm.thrift
thrift.exe --gen %1 ctrl.thrift