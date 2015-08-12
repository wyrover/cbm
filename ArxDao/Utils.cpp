#include "stdafx.h"
#include "Utils.h"
#include <cstring>

namespace orm
{
	std::string Utils::int_to_string(int v) 
	{
		char ss[100];
		sprintf(ss, "%d", v);
		return std::string(ss);
	}
	std::string Utils::double_to_string(double v) 
	{
		char ss[100];
		sprintf(ss, "%lf", v);
		return std::string(ss);
	}
	bool Utils::string_to_int(std::string s, int& v) 
	{
		return sscanf(s.c_str(), "%d", &v) > -1;
	}
	bool Utils::string_to_double(std::string s, double& v) 
	{
		return sscanf(s.c_str(), "%lf", &v) > -1;
	}
	std::string Utils::string_tolower(std::string s)
	{
		std::transform(s.begin(), s.end(), s.begin(), tolower);
		return s;
	}
	std::string Utils::string_toupper(std::string s)
	{
		std::transform(s.begin(), s.end(), s.begin(), toupper);
		return s;
	}
	CString Utils::int_to_cstring(int v) 
	{
		CString str;
		str.Format(_T("%d"), v);
		return str;
	}
	CString Utils::double_to_cstring(double v) 
	{
		CString str;
		str.Format(_T("%lf"), v);
		return str;
	}
	/** Split a CString s into parts by value e */
	std::vector<std::string> Utils::string_explode(std::string s, std::string e) 
	{
		std::vector<std::string> ret;
		int iPos = s.find(e, 0);
		int iPit = e.length();
		while(iPos>-1) {
			if(iPos!=0)
				ret.push_back(s.substr(0,iPos));
			s.erase(0,iPos+iPit);
			iPos = s.find(e, 0);
		}
		if(s!="") {
			ret.push_back(s);
		}
		return ret;
	}
	std::string Utils::string_join( std::vector<std::string> vec, std::string delim )
	{
		if( vec.empty() ) return "";

		std::string result;
		for( std::vector<std::string>::iterator it = vec.begin(); it != vec.end() - 1; ++it )
		{
			result += ( *it ) + delim;
		}
		return result +	( *vec.rbegin() );
	}

	CString Utils::cstring_tolower(CString s)
	{
		s.MakeLower();
		return s;
	}
	CString Utils::cstring_toupper(CString s)
	{
		s.MakeUpper();
		return s;
	}
	bool Utils::cstring_to_int(CString s, int& v) 
	{
		v = _ttoi(s);
		return true;
	}
	bool Utils::cstring_to_double(CString s, double& v) 
	{
		v = _tstof(s);
		return true;
	}
	CString Utils::cstring_join( std::vector<CString> vec, CString delim )
	{
		if( vec.empty() ) return _T("");

		CString result;
		for( std::vector<CString>::iterator it = vec.begin(); it != vec.end() - 1; ++it )
		{
			result += ( *it ) + delim;
		}
		return result +	( *vec.rbegin() );
	}
	void Utils::cstring_explode(const CString& str, const CString& tokens, CStringArray& values)
	{
		int nTokenPos = 0;
		CString strToken = str.Tokenize(tokens, nTokenPos);
		while (!strToken.IsEmpty())
		{
			values.Add(strToken);
			strToken = str.Tokenize(tokens, nTokenPos);
		}
	}

}