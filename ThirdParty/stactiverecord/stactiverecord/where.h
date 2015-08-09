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

    class Where
    {
    public:
        int ivalue, ivaluetwo;
		double fvalue, fvaluetwo;
        tstring svalue;
        std::vector<int> ivalues;
        wheretype type;
        coltype ct;
        bool isnot;
        Where( int _ivalue, wheretype _wt, bool _isnot = false ) :
            ivalue( _ivalue ), type( _wt ), ct( INTEGER ), isnot( _isnot ) {};
		Where( double _fvalue, wheretype _wt, bool _isnot = false ) :
			fvalue( _fvalue ), type( _wt ), ct( DECIMAL ), isnot( _isnot ) {};
        Where( DateTime _dtvalue, wheretype _wt, bool _isnot = false ) :
            ivalue( _dtvalue.to_int() ), type( _wt ), ct( DATETIME ), isnot( _isnot ) {};
        Where( std::vector<int> _ivalues, wheretype _wt, bool _isnot = false ) :
            ivalues( _ivalues ), type( _wt ), ct( INTEGER ), isnot( _isnot ) {};
        Where( int _ivalue, int _valuetwo, wheretype _wt, bool _isnot = false ) :
            ivalue( _ivalue ), ivaluetwo( _valuetwo ), type( _wt ), ct( INTEGER ), isnot( _isnot ) {};
		Where( double _fvalue, double _fvaluetwo, wheretype _wt, bool _isnot = false ) :
			fvalue( _fvalue ), fvaluetwo( _fvaluetwo ), type( _wt ), ct( DECIMAL ), isnot( _isnot ) {};
		Where( DateTime _dtvalue, DateTime _dtvaluetwo, wheretype _wt, bool _isnot = false ) :
            ivalue( _dtvalue.to_int() ), ivaluetwo( _dtvaluetwo.to_int() ), type( _wt ), ct( DATETIME ), isnot( _isnot ) {};
        Where( tstring _svalue, wheretype _wt, bool _isnot = false ) :
            svalue( _svalue ), type( _wt ), ct( STRING ), isnot( _isnot ) {};
        // in the case of a record search - i.e., Q(hasobject(someobject))
        Where( tstring _svalue, int _ivalue, wheretype _wt, bool _isnot = false ) :
            svalue( _svalue ), ivalue( _ivalue ), type( _wt ), ct( RECORD ), isnot( _isnot ) {};
        // for isnull and nisnull
        Where( wheretype _wt, bool _isnot = false ) : type( _wt ), ct( ALL ), isnot( _isnot ) {};
    };

    Where* startswith( tstring value );
    Where* endswith( tstring value );
    Where* contains( tstring value );
    Where* lessthan( int value );
    Where* greaterthan( int value );
    Where* between( int value, int valuetwo );
	Where* lessthan( double value );
	Where* greaterthan( double value );
	Where* between( double value, double valuetwo );
    Where* lessthan( DateTime value );
    Where* greaterthan( DateTime value );
    Where* between( DateTime value, DateTime valuetwo );
    Where* equals( DateTime value );
    Where* equals( int value );
	Where* equals( double value );
    Where* equals( tstring value );
    Where* equals( bool value );
    Where* equals( const tchar* value );
    Where* in( std::vector<int> values );
    Where* isnull();
    template <class T> Where* hasobject( Record<T>& r )
    {
        return new Where( r.classname, r.id, OBJECTRELATION );
    };


    // negated values
    Where* nstartswith( tstring value );
    Where* nendswith( tstring value );
    Where* ncontains( tstring value );
    Where* nlessthan( int value );
    Where* ngreaterthan( int value );
    Where* nbetween( int value, int valuetwo );
    Where* nequals( int value );
	Where* ngreaterthan( double value );
	Where* nbetween( double value, double valuetwo );
	Where* nequals( double value );
    Where* nlessthan( DateTime value );
    Where* ngreaterthan( DateTime value );
    Where* nbetween( DateTime value, DateTime valuetwo );
    Where* nequals( DateTime value );
    Where* nequals( tstring value );
    Where* nequals( bool value );
    Where* nequals( const tchar* value );
    Where* nin( std::vector<int> values );
    Where* nisnull();
};
