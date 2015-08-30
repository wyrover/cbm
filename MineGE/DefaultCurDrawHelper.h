#pragma once

class MineGEDraw;

extern void InitAllDefaultCurDraws();
extern bool GetDefaultCurDraw(const CString& type, CString& draw);
extern bool SetDefaultCurDraw(const CString& type, const CString& draw);
extern MineGEDraw* GetDefaultCurDrawPtr(const CString& type);
