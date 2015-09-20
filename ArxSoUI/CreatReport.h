#pragma  once

#define ISNULL _T("**")

//初始化全局变量(new构造对象，并初始化com)
extern bool initword();
//卸载全局变量(释放内存，释放com)
extern void uninitword();
//生成报告
extern bool CreatReport(const CString& savePath,const AcDbObjectId& drill_site);
//打开word文档
extern void OpenWordDocument( const CString& filePath );
