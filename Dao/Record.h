#pragma once

#include "Db.h"
#include "Row.h"
#include "Query.h"
#include "Utils.h"

namespace orm
{
    //表示数据库表中的一条记录
    //整体可以看作是一个链式树状结构
    class DAO_DLLIMPEXP Record
    {
    public:
        //析构函数
        virtual ~Record();

        //克隆一个新的对象
        bool clone( RecordPtr ptr );

        //执行insert操作
        bool save();
        //根据id执行delete操作
        bool remove();

        //设置主键id(参数fetch表示是否需要通过id从数据库拉取数据)
        bool setID( int id, bool fetch = false );
        bool setID( const CString& id, bool fetch = false );
        //获取主键id
        int getID() const;
        CString getStringID() const;
        //获取数据库表名
        CString getTable() const;

        //判断对象是新建的还是通过select得到的
        //该参数决定对象是通过insert还是update提交到数据库
        void setNewlyRecord( bool isNewly );
        bool isNewlyRecord() const;

        //读/写字段(目前只支持int、double、CString三种类型，不包括外键)
        void set( const CString& name, int v );
        void set( const CString& name, double v );
        void set( const CString& name, CString v );
        bool get( const CString& name, int& v ) const;
        bool get( const CString& name, double& v ) const;
        bool get( const CString& name, CString& v ) const;
        //读取数据并自动转换成string类型(方便使用)
        CString get( const CString& name ) const;

        /** 下面的几个方法仅供内部使用. */
        //从row中读取数据(数据库一个row代表一条记录)
        bool fetchByRow( RowPtr& row );
    protected:
        Record( const CString& table );
        void map_field( const CString& name, int& v );
        void map_field( const CString& name, double& v );
        void map_field( const CString& name, CString& v );
        void map_foreign_key( const CString& name, RecordPtr& ptr, CreateFunc cf );
    private:
        //字段和外键操作
        void attributes( KVMap& fields, bool all = false );
        bool setAttrib( const CString& name, const Attribute& attrib );
        void updateAttrib( const CString& name );
        bool isForeignKey( const CString& name ) const;
        bool isPrimaryKey( const CString& name ) const;
        bool setForeignKey( const CString& name, const CString& id );
        //根据id从数据库表中拉取数据
        //这是一个递归过程,如果发现外键,初始化并读取外键的数据
        bool fetchById( int id );
    private:
        DISALLOW_COPY_AND_ASSIGN( Record );
        class Row* row;
        class ForeignKey* fk;
        bool m_isNewlyRecord;
        CString m_table;
        int m_id;
    };
}

//注册字段(不包括外键)
#define REG_ATTRIB(field_name, var_name) this->map_field(_T(#field_name), var_name)
//注册外键
#define REG_FOREGIN_KEY(field_name, var_name, create_func) this->map_foreign_key(_T(#field_name), var_name, create_func);
