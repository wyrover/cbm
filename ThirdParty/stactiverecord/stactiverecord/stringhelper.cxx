#include "stringhelper.h"

#include <iterator>
#include <algorithm>
#include <cstring>
#include <cwchar>
#include <cwctype>
#include <cctype>
#include <cassert>
#include <vector>


namespace stactiverecord
{

namespace internal
{

stactiverecord::tstring const empty_str;

} // namespace internal

} // namespace stactiverecord

namespace stactiverecord
{

namespace helpers
{


void clear_mbstate (std::mbstate_t & mbs)
{
    // Initialize/clear mbstate_t type.
    // XXX: This is just a hack that works. The shape of mbstate_t varies
    // from single unsigned to char[128]. Without some sort of initialization
    // the codecvt::in/out methods randomly fail because the initial state is
    // random/invalid.
    std::memset (&mbs, 0, sizeof (std::mbstate_t));
}

static void towstring_internal (std::wstring & outstr, const char * src, std::size_t size, std::locale const & loc)
{
	if (size == 0)
	{
		outstr.clear ();
		return;
	}

	typedef std::codecvt<wchar_t, char, std::mbstate_t> CodeCvt;
	const CodeCvt & cdcvt = std::use_facet<CodeCvt>(loc);
	std::mbstate_t state;
	clear_mbstate (state);

	char const * from_first = src;
	std::size_t const from_size = size;
	char const * const from_last = from_first + from_size;
	char const * from_next = from_first;

	std::vector<wchar_t> dest (from_size);

	wchar_t * to_first = &dest.front ();
	std::size_t to_size = dest.size ();
	wchar_t * to_last = to_first + to_size;
	wchar_t * to_next = to_first;

	CodeCvt::result result;
	std::size_t converted = 0;
	while (true)
	{
		result = cdcvt.in (
			state, from_first, from_last,
			from_next, to_first, to_last,
			to_next);
		// XXX: Even if only half of the input has been converted the
		// in() method returns CodeCvt::ok. I think it should return
		// CodeCvt::partial.
		if ((result == CodeCvt::partial || result == CodeCvt::ok)
			&& from_next != from_last)
		{
			to_size = dest.size () * 2;
			dest.resize (to_size);
			converted = to_next - to_first;
			to_first = &dest.front ();
			to_last = to_first + to_size;
			to_next = to_first + converted;
			continue;
		}
		else if (result == CodeCvt::ok && from_next == from_last)
			break;
		else if (result == CodeCvt::error
			&& to_next != to_last && from_next != from_last)
		{
			clear_mbstate (state);
			++from_next;
			from_first = from_next;
			*to_next = L'?';
			++to_next;
			to_first = to_next;
		}
		else
			break;
	}
	converted = to_next - &dest[0];

	outstr.assign (dest.begin (), dest.begin () + converted);
}

std::wstring towstring(const std::string& src)
{
	std::wstring ret;
	towstring_internal (ret, src.c_str (), src.size (), std::locale ());
	return ret;
}


//std::wstring towstring(char const * src)
//{
//	std::wstring ret;
//	towstring_internal (ret, src, std::strlen (src), std::locale ());
//	return ret;
//}

static void tostring_internal (std::string & outstr, const wchar_t * src, std::size_t size, std::locale const & loc)
{
	if (size == 0)
	{
		outstr.clear ();
		return;
	}

	typedef std::codecvt<wchar_t, char, std::mbstate_t> CodeCvt;
	const CodeCvt & cdcvt = std::use_facet<CodeCvt>(loc);
	std::mbstate_t state;
	clear_mbstate (state);

	wchar_t const * from_first = src;
	std::size_t const from_size = size;
	wchar_t const * const from_last = from_first + from_size;
	wchar_t const * from_next = from_first;

	std::vector<char> dest (from_size);

	char * to_first = &dest.front ();
	std::size_t to_size = dest.size ();
	char * to_last = to_first + to_size;
	char * to_next = to_first;

	CodeCvt::result result;
	std::size_t converted = 0;
	while (from_next != from_last)
	{
		result = cdcvt.out (
			state, from_first, from_last,
			from_next, to_first, to_last,
			to_next);
		// XXX: Even if only half of the input has been converted the
		// in() method returns CodeCvt::ok with VC8. I think it should
		// return CodeCvt::partial.
		if ((result == CodeCvt::partial || result == CodeCvt::ok)
			&& from_next != from_last)
		{
			to_size = dest.size () * 2;
			dest.resize (to_size);
			converted = to_next - to_first;
			to_first = &dest.front ();
			to_last = to_first + to_size;
			to_next = to_first + converted;
		}
		else if (result == CodeCvt::ok && from_next == from_last)
			break;
		else if (result == CodeCvt::error
			&& to_next != to_last && from_next != from_last)
		{
			clear_mbstate (state);
			++from_next;
			from_first = from_next;
			*to_next = '?';
			++to_next;
			to_first = to_next;
		}
		else
			break;
	}
	converted = to_next - &dest[0];

	outstr.assign (dest.begin (), dest.begin () + converted);
}

std::string tostring(const std::wstring& src)
{
	std::string ret;
	tostring_internal (ret, src.c_str (), src.size (), std::locale ());
	return ret;
}

//std::string tostring(wchar_t const * src)
//{
//	std::string ret;
//	tostring_internal (ret, src, std::wcslen (src), std::locale ());
//	return ret;
//}

namespace
{


struct toupper_func
{
    tchar operator () (tchar ch) const
    {
        return std::char_traits<tchar>::to_char_type (
#ifdef UNICODE
            std::towupper
#else
            std::toupper
#endif
            (std::char_traits<tchar>::to_int_type (ch)));
    }
};


struct tolower_func
{
    tchar operator () (tchar ch) const
    {
        return std::char_traits<tchar>::to_char_type (
#ifdef UNICODE
            std::towlower
#else
            std::tolower
#endif
            (std::char_traits<tchar>::to_int_type (ch)));
    }
};


} // namespace


tchar toUpper (tchar ch)
{
    return toupper_func () (ch);
}


tstring toUpper(const tstring& s)
{
    tstring ret;
    std::transform(s.begin(), s.end(), std::back_inserter (ret),
        toupper_func ());
    return ret;
}


tchar toLower (tchar ch)
{
    return tolower_func () (ch);
}


tstring toLower(const tstring& s)
{
    tstring ret;
    std::transform(s.begin(), s.end(), std::back_inserter (ret),
        tolower_func ());
    return ret;
}


} // namespace helpers

} // namespace stactiverecord
