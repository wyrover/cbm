/*
Copyright (C) 2007 Butterfat, LLC (http://butterfat.net)

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

Created by bmuller <bmuller@butterfat.net>
*/

#pragma once

namespace stactiverecord
{

    struct mapStrCmp
    {
        bool operator()( tstring s1, tstring s2 ) const
        {
            return s1 == s2;
        }
    };

	struct mapDecimalCmp
	{
		bool operator()( double f1, double f2 ) const
		{
			return fabs((f1-f2)*1e4)<1e-4;
		}
	};

    // In utils.cpp
    void int_to_string( int i, tstring& s );
	void double_to_string(double f, tstring& s);
    void debug( tstring s );
    void check_classname( tstring classname );
    std::vector<tstring> explode( tstring s, tstring e );
    void coltype_to_name( coltype ct, tstring& name );
    void join( std::vector<tstring> v, tstring joiner, tstring& result );
    int string_to_int( tstring s );
	double string_to_double(tstring s);
};

