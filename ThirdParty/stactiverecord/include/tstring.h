#pragma once

#include "tchar.h"
#include <string>

namespace stactiverecord
{

typedef std::basic_string<tchar> tstring;


namespace helpers
{
	std::string tostring(const std::wstring&);
	std::wstring towstring(const std::string&);
} // namespace helpers

#ifdef UNICODE

#define SAR_C2T(STRING) stactiverecord::helpers::towstring(STRING)
#define SAR_S2T(STRING) stactiverecord::helpers::towstring(STRING)
#define SAR_T2S(STRING) stactiverecord::helpers::tostring(STRING)

#else // UNICODE

#define SAR_C2T(STRING) tstring(STRING)
#define SAR_S2T(STRING) STRING
#define SAR_T2S(STRING) STRING

#endif // UNICODE

} // namespace stactiverecord

