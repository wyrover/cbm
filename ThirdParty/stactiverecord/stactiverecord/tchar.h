#pragma once

#if defined (_WIN32)
#include <cstddef>
#endif

#if defined (UNICODE)
//#	define SAR_UNICODE
#endif

#ifdef SAR_UNICODE
#  define SAR_TEXT2(STRING) L##STRING
#else
#  define SAR_TEXT2(STRING) STRING
#endif // UNICODE

#define SAR_TEXT(STRING) SAR_TEXT2(STRING)


namespace stactiverecord
{

#if defined (SAR_UNICODE)
typedef wchar_t tchar;

#else
typedef char tchar;

#endif

} // namespace stactiverecord

