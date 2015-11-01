#pragma once

#include "Types.h"
#include "Utils.h"

namespace orm
{
    //模板类,表示一个任意类型的值(目前只支持int、double、string三种类型)
    template<typename T, typename Ptr = std::equal_to<T> >
    class Value
    {
    public:
        Value( T* ptr = 0 ) : v_ptr( ptr ), v_pod( T() ) {}
        Value( const Value<T, Ptr>& b )
        {
            v_ptr = b.v_ptr;
            v_pod = b.v_pod;
        }
        T new_value() const
        {
            return ( v_ptr != 0 ) ? ( *v_ptr ) : v_pod;
        }
        T old_value() const
        {
            return v_pod;
        }
        void update()
        {
            if( v_ptr != 0 ) v_pod = *v_ptr;
        }
        bool hasChanged() const
        {
            return ( v_ptr == 0 ) ? false : !( *this == v_pod );
        }
        Value<T, Ptr>& operator=( const T& v )
        {
            if( v_ptr != 0 )
            {
                *v_ptr = v;
            }
            else
            {
                v_pod = v;
            }
            return *this;
        }
        //Value<T, Ptr>& operator=(const Value<T, Ptr>& b) { v_ptr = b.v_ptr; v_pod = b.v_pod; return *this; }
        bool operator==( const T& v ) const
        {
            return Ptr()( *v_ptr, v );
        }
    private:
        T* v_ptr;
        T v_pod;
    };

    struct DAO_API DecimalCmp
    {
        bool operator()( double f1, double f2 )
        {
            return fabs( f1 - f2 ) * 1e4 < 1e-4;
        }
    };

    typedef Value<int> IntValue;
    typedef Value<double, DecimalCmp> DoubleValue;
    typedef Value<CString> StringValue;

    //代表一个属性(也可以叫做字段)
    //同样地，这个属性只支持3种基本类型(int、double、string)
    class DAO_API Attribute
    {
    public:
        Attribute() : att_type( 0 ) {}
        Attribute( int* v ) : ivalue( v ), att_type( 1 ) {}
        Attribute( double* v ) : fvalue( v ), att_type( 2 ) {}
        Attribute( CString* v ) : svalue( v ), att_type( 3 ) {}
        Attribute& operator=( const int& v )
        {
            set( v );
            return *this;
        }
        Attribute& operator=( const double& v )
        {
            set( v );
            return *this;
        }
        Attribute& operator=( const CString& v )
        {
            set( v );
            return *this;
        }
        void set( const int& v );
        void set( const double& v );
        void set( const CString& v );
        bool get( int& v ) const;
        bool get( double& v ) const;
        bool get( CString& v ) const;
        int getType() const;
        void setType( int att_type );
        void update();
        CString toString() const;
        bool hasChanged() const;

    private:
        int att_type;
        IntValue ivalue;
        DoubleValue fvalue;
        StringValue svalue;
    };

    class DAO_API Row
    {
    public:
        Row();
        ~Row();
        void set( const CString& name, int v );
        void set( const CString& name, double v );
        void set( const CString& name, CString v );
        bool get( const CString& name, int& v ) const;
        bool get( const CString& name, double& v ) const;
        bool get( const CString& name, CString& v ) const;
        CString toString( const CString& name ) const;
        Attribute& operator[]( const CString& name );
        void attributes( KVMap& fields, bool all = false );

    private:
        //禁用拷贝构造函数和赋值运算符重载
        DISALLOW_COPY_AND_ASSIGN( Row );
        struct RowPrivate* d;
    };
}
