#pragma once

#include "Types.h"

namespace orm 
{
	class ARXDAO_DLLIMPEXP Utils
	{
	public:
		static std::string string_tolower(std::string s);
		static std::string string_toupper(std::string s);
		static std::string int_to_string(int v);
		static std::string double_to_string(double v);
		static bool string_to_int(std::string s, int& v);
		static bool string_to_double(std::string s, double& v);
		static std::vector<std::string> string_explode(std::string s, std::string e);
		static std::string string_join( std::vector<std::string> vec, std::string delim );

		static CString cstring_tolower(CString s);
		static CString cstring_toupper(CString s);
		static CString int_to_cstring(int v);
		static CString double_to_cstring(double v);
		static bool cstring_to_int(CString s, int& v);
		static bool cstring_to_double(CString s, double& v);
		static CString cstring_join( std::vector<CString> vec, CString delim );
		static void cstring_explode(const CString& str, const CString& tokens, CStringArray& values);
	};
}
