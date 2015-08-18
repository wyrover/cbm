#pragma once

#include "Types.h"

namespace orm 
{
	class ARXDAO_DLLIMPEXP Utils
	{
	public:
		static std::string string_tolower(const std::string& s);
		static std::string string_toupper(const std::string& s);
		static std::string int_to_string(int v);
		static std::string double_to_string(double v);
		static bool string_to_int(const std::string& s, int& v);
		static bool string_to_double(const std::string& s, double& v);
		static std::vector<std::string> string_explode(const std::string& s, const std::string& e);
		static std::string string_join(std::vector<std::string> vec, const std::string& delim);

		static CString cstring_tolower(const CString& s);
		static CString cstring_toupper(const CString& s);
		static CString int_to_cstring(int v);
		static CString double_to_cstring(double v);
		static bool cstring_to_int(const CString& s, int& v);
		static bool cstring_to_double(const CString& s, double& v);
		static CString cstring_join(std::vector<CString> vec, const CString& delim);
		static void cstring_explode(const CString& str, const CString& tokens, CStringArray& values);
	};
}
