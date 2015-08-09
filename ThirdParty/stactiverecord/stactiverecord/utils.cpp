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

#include "stactive_record.h"

namespace stactiverecord
{

    /** Determind if classname is valid - throws exception if not */
    void check_classname( tstring classname )
    {
        char chars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                       };
        bool found;
        for( tstring::size_type i = 0; i < classname.size(); i++ )
        {
            found = false;
            for( int z = 0; z < 52; z++ )
                if( classname[i] == chars[z] || classname[i] == '_' )
                    found = true;
            if( !found ) throw Sar_InvalidClassnameException( SAR_TEXT("\"") + classname + SAR_TEXT("\" is an invalid classname.") );
        }
    };

    /** convert column type to string */
    void coltype_to_name( coltype ct, tstring& name )
    {
        tstring scoltype[] = { SAR_TEXT("NONE"), SAR_TEXT("INTEGER"), SAR_TEXT("DECIMAL"), SAR_TEXT("STRING"), SAR_TEXT("RECORD") };
        name = scoltype[ct];
    };

    /** convert integer to string */
    void int_to_string( int i, tstring& s )
    {
        char c_int[100];
        sprintf( c_int, "%d", i );
		s = SAR_S2T( std::string(c_int) );
    };

	void double_to_string(double f, tstring& s)
	{
		char c_double[100];
		sprintf( c_double, "%lf", f );
		s = SAR_S2T( std::string(c_double) );
	}

    /** Better be sure s is really a string - used for postgres int column
        retrieval
    **/
    int string_to_int( tstring s )
    {
        int i;
        sscanf( SAR_T2S(s).c_str(), "%d", &i );
        return i;
    }

	double string_to_double(tstring s)
	{
		double f;
		sscanf( SAR_T2S(s).c_str(), "%lf", &f );
		return f;
	}

    /** print debugging information if DEBUG is defined */
    void debug( tstring s )
    {
#ifdef DEBUG
        tstring time_s = SAR_TEXT("");
        time_t rawtime = time( NULL );
        tm* tm_t = localtime( &rawtime );
        char rv[40];
        if( strftime( rv, sizeof( rv ) - 1, "%a %b %d %H:%M:%S %Y", tm_t ) )
			time_s = SAR_TEXT("[") + SAR_S2T(std::string( rv )) + SAR_TEXT("] ");
		s = time_s + SAR_TEXT("[") + SAR_S2T(std::string( PACKAGE_NAME )) + SAR_TEXT("] ") + s + SAR_TEXT("\n");
        // escape %'s
        tstring cleaned_s = SAR_TEXT("");
        std::vector<tstring> parts = explode( s, SAR_TEXT("%") );
        for( unsigned int i = 0; i < parts.size() - 1; i++ )
            cleaned_s += parts[i] + SAR_TEXT("%%");
        cleaned_s += parts[parts.size() - 1];
        fprintf( stderr, SAR_T2S(cleaned_s).c_str() );
        fflush( stderr );
#endif
    };

    /** Split a string s into parts by value e */
    std::vector<tstring> explode( tstring s, tstring e )
    {
        std::vector<tstring> ret;
        int iPos = (int)s.find( e, 0 );
        int iPit = (int)e.length();
        while( iPos > -1 )
        {
            if( iPos != 0 )
                ret.push_back( s.substr( 0, iPos ) );
            s.erase( 0, iPos + iPit );
            iPos = (int)s.find( e, 0 );
        }
        if( s != SAR_TEXT("") )
            ret.push_back( s );
        return ret;
    };

    void join( std::vector<tstring> v, tstring joiner, tstring& result )
    {
        result = SAR_TEXT("");
        for ( unsigned int i = 0; i < v.size(); i++ )
            result += ( i == ( v.size() - 1 ) ) ? v[i] : v[i] + joiner;
    };

};
