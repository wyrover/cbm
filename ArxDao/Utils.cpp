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
	bool Utils::string_to_int(const std::string& s, int& v) 
	{
		return sscanf(s.c_str(), "%d", &v) > -1;
	}
	bool Utils::string_to_double(const std::string& s, double& v) 
	{
		return sscanf(s.c_str(), "%lf", &v) > -1;
	}
	std::string Utils::string_tolower(const std::string& s)
	{
		std::string ss(s);
		std::transform(ss.begin(), ss.end(), ss.begin(), tolower);
		return ss;
	}
	std::string Utils::string_toupper(const std::string& s)
	{
		std::string ss(s);
		std::transform(ss.begin(), ss.end(), ss.begin(), toupper);
		return ss;
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
	/** Split a const CString& s into parts by value e */
	std::vector<std::string> Utils::string_explode(const std::string& s, const std::string& e) 
	{
		std::string ss(s);
		std::vector<std::string> ret;
		int iPos = ss.find(e, 0);
		int iPit = e.length();
		while(iPos>-1) {
			if(iPos!=0)
				ret.push_back(ss.substr(0,iPos));
			ss.erase(0,iPos+iPit);
			iPos = ss.find(e, 0);
		}
		if(ss!="") {
			ret.push_back(ss);
		}
		return ret;
	}
	std::string Utils::string_join(const std::vector<std::string>& vec, const std::string& delim )
	{
		if( vec.empty() ) return "";

		std::string result;
		for( std::vector<std::string>::const_iterator it = vec.begin(); it != vec.end() - 1; ++it )
		{
			result += ( *it ) + delim;
		}
		return result +	( *vec.rbegin() );
	}

	CString Utils::cstring_tolower(const CString& s)
	{
		CString ss(s);
		ss.MakeLower();
		return ss;
	}
	CString Utils::cstring_toupper(const CString& s)
	{
		CString ss(s);
		ss.MakeUpper();
		return ss;
	}
	bool Utils::cstring_to_int(const CString& s, int& v) 
	{
		v = _ttoi(s);
		return true;
	}
	bool Utils::cstring_to_double(const CString& s, double& v) 
	{
		v = _tstof(s);
		return true;
	}
	CString Utils::cstring_join( std::vector<CString> vec, const CString& delim )
	{
		if( vec.empty() ) return _T("");

		CString result;
		for( std::vector<CString>::iterator it = vec.begin(); it != vec.end() - 1; ++it )
		{
			result += ( *it ) + delim;
		}
		return result +	( *vec.rbegin() );
	}
	void Utils::cstring_explode(const CString& str, const CString& tokens, std::vector<CString>& values)
	{
		int nTokenPos = 0;
		CString strToken = str.Tokenize(tokens, nTokenPos);
		strToken.Trim(); // È¥µô×óÓÒ¿Õ°×
		while (!strToken.IsEmpty())
		{
			values.push_back(strToken);
			strToken = str.Tokenize(tokens, nTokenPos);
		}
	}

}