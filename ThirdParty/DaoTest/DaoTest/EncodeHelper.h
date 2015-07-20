#pragma once

//#include "dlimexp.h"

#include <string>

/** 
* ×Ö·û´®±àÂë×ª»».
*/
class /*ARXHELPER_DLLIMPEXP*/ EncodeHelper
{
public:
	static std::string UnicodeToANSI(const std::wstring& str);
	static std::wstring ANSIToUnicode(const std::string& str);
	static std::string ANSIToUtf8(const std::string& str);
	static std::string Utf8ToANSI(const std::string& str);
	static std::string UnicodeToUtf8(const std::wstring& str);
	static std::wstring Utf8ToUnicode(const std::string& str);
};
