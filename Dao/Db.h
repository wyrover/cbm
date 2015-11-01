#pragma once

#include "Row.h"

namespace orm
{
    //单件模式
    class DAO_API Db
    {
    public:
        //静态方法--获取实例指针
        static DbPrt Instance();

    public:
        virtual ~Db() {}
        virtual bool config( const CString& user, const CString& password, const CString& database, const CString& host = _T( "localhost" ), const CString& port = _T( "3306" ) ) = 0;
        virtual bool execute( const CString& sql ) = 0;
        virtual bool query( const CString& sql, RowSet& rs ) = 0;
        virtual int lastInsertId( const CString& table ) = 0;

    public:
        //主键ID使用表前缀(默认不使用)
        //如果使用表前缀,则主键id的字段名为: 表前缀+下划线+id,例如"cbm_mine_id"
        //如果不使用表前缀，则主键id的字段名为:id，例如"id"
        void enableTablePrefix( bool use = false )
        {
            m_useTablePrefix = use;
        }

        //获取固定的主键ID名
        CString getPrimaryKeyName( const CString& table ) const
        {
            if( m_useTablePrefix )
            {
                //全部变成小写
                return Utils::cstring_tolower( table + _T( "_" ) + KEY_ID );
            }
            else
            {
                return KEY_ID;
            }
        }
        CString getForeignKeyName( const CString& table ) const
        {
            //全部变成小写
            return Utils::cstring_tolower( table + _T( "_" ) + KEY_ID );
        }
    protected:
        static DbPrt instance;
        Db() : m_useTablePrefix( false ) {}
    private:
        DISALLOW_COPY_AND_ASSIGN( Db );
        bool m_useTablePrefix;
    };

    //全局函数
    extern DAO_API DbPrt get_db();
}
