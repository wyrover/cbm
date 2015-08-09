#pragma once

#include "tstring.h"
#include <algorithm>
#include <limits>

namespace stactiverecord {
    
namespace helpers {

        /**
         * Returns <code>s</code> in upper case.
         */
        stactiverecord::tstring toUpper(const stactiverecord::tstring& s);
        tchar toUpper(tchar);


        /**
         * Returns <code>s</code> in lower case.
         */
        stactiverecord::tstring toLower(const stactiverecord::tstring& s);
        tchar toLower(tchar);


        /**
         * Tokenize <code>s</code> using <code>c</code> as the delimiter and
         * put the resulting tokens in <code>_result</code>.  If
         * <code>collapseTokens</code> is false, multiple adjacent delimiters
         * will result in zero length tokens.
         *
         * <b>Example:</b>
         * <pre>
         *   string s = // Set string with '.' as delimiters
         *   list<stactiverecord::tstring> tokens;
         *   tokenize(s, '.', back_insert_iterator<list<string> >(tokens));
         * </pre>
         */
        template <class StringType, class OutputIter>
        inline void tokenize(const StringType& s, typename StringType::value_type c,
            OutputIter result, bool collapseTokens = true)
        {
            typedef typename StringType::size_type size_type;
            size_type const slen = s.length();
            size_type first = 0;
            size_type i = 0;
            for (i=0; i < slen; ++i)
            {
                if (s[i] == c)
                {
                    *result = StringType (s, first, i - first);
                    ++result;
                    if (collapseTokens)
                        while (i+1 < slen && s[i+1] == c)
                            ++i;
                    first = i + 1;
                }
            }
            if (first != i)
                *result = StringType (s, first, i - first);
        }


        template <typename intType, typename stringType, bool isSigned>
        struct ConvertIntegerToStringHelper;


        template <typename intType, typename charType>
        struct ConvertIntegerToStringHelper<intType, charType, true>
        {
            static inline
            void step1 (charType * & it, intType & value)
            {
                // The sign of the result of the modulo operator is
                // implementation defined. That's why we work with
                // positive counterpart instead.  Also, in twos
                // complement arithmetic the smallest negative number
                // does not have positive counterpart; the range is
                // asymetric.  That's why we handle the case of value
                // == min() specially here.
                if (value != (std::numeric_limits<intType>::min) ())
                {
                    intType const r = value / 10;
                    intType const a = (-r) * 10;
                    intType const mod = -(a + value);
                    value = -r;

                    *(it - 1)
                        = static_cast<charType>(SAR_TEXT('0') + mod);
                    --it;
                }
                else
                    value = -value;
            }

            static inline
            bool is_negative (intType val)
            {
                return val < 0;
            }
        };


        template <typename intType, typename charType>
        struct ConvertIntegerToStringHelper<intType, charType, false>
        {
            static inline
            void step1 (charType * &, intType &)
            {
                // This will never be called for unsigned types.
            }

            static inline
            bool is_negative (intType)
            {
                return false;
            }
        };


        template <class stringType, class intType>
        inline void convertIntegerToString (stringType & str, intType value)
        {
            typedef std::numeric_limits<intType> intTypeLimits;
            typedef typename stringType::value_type charType;
            typedef ConvertIntegerToStringHelper<intType, charType,
                intTypeLimits::is_signed> HelperType;
            
            charType buffer[intTypeLimits::digits10 + 2];
            // We define buffer_size from buffer using sizeof operator
            // to apease HP aCC compiler.
            const std::size_t buffer_size
                = sizeof (buffer) / sizeof (charType);

            charType * it = &buffer[buffer_size];
            charType const * const buf_end = &buffer[buffer_size];

            if (value != 0)
            {
                --it;
                *it = SAR_TEXT('0');
            }
            else
            {
                bool const negative = HelperType::is_negative (value);
                if (negative)
                    HelperType::step1 (it, value);

                for (; value != 0; --it)
                {
                    intType mod = value % 10;
                    value = value / 10;
                    *(it - 1) = static_cast<charType>(SAR_TEXT('0')
                        + mod);
                }

                if (negative)
                {
                    --it;
                    *it = SAR_TEXT('-');
                }
            }

            str.assign (static_cast<charType const *>(it), buf_end);
        }


        template<class intType>
        inline tstring convertIntegerToString (intType value)
        {
            tstring result;
            convertIntegerToString (result, value);
            return result;
        }


        template<class intType>
        inline tstring convertIntegerToNarrowString (intType value)
        {
            tstring result;
            convertIntegerToString (result, value);
            return result;
        }


        //! Join a list of items into a string.
        template <typename Iterator>
        inline void join (tstring & result, Iterator start, Iterator last, tstring const & sep)
        {
            if (start != last)
                result = *start++;

            for (; start != last; ++start)
            {
                result += sep;
                result += *start;
            }
        }


    } // namespace helpers

} // namespace stactiverecord
