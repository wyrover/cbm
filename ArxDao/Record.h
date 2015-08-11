#pragma once

#include "Db.h"
#include "Row.h"
#include "Query.h"
#include "Utils.h"

namespace orm 
{
	class ARXDAO_DLLIMPEXP Record
	{
	public:
		//执行insert操作
		bool save();
		//根据id执行delete操作
		bool remove();
		//根据id从数据库表中拉取数据
		bool fetch();

		//获取数据库表名
		CString getTable() const;
		//获取id
		int getID() const;
		
		//读/写字段(目前只支持int、double、CString三种类型)
		void set(const CString& name, int v);
		void set(const CString& name, double v);
		void set(const CString& name, CString v);
		bool get(const CString& name, int& v) const;
		bool get(const CString& name, double& v) const;
		bool get(const CString& name, CString& v) const;

		//从row中读取数据(数据库一个row代表一条记录,内部使用)
		bool fetchByRow(RowPtr& row);
		//判断对象是新建的还是通过select得到的(内部使用)
		void setNewlyRecord(bool isNewly);
		bool isNewlyRecord() const;
		//字段和外键操作(内部使用)
		void attributes(KVMap& fields, bool all=false);
		bool setAttrib(const CString& name, const Attribute& attrib);
		bool setForeignKey(const CString& name, const CString& id);
		bool isForeignKey(const CString& name) const;
		virtual ~Record();
	protected:
		Record(const CString& table);
		void map_field(const CString& name, int& v);
		void map_field(const CString& name, double& v);
		void map_field(const CString& name, CString& v);
		void map_foreign_key(const CString& name, RecordPtr& ptr, CreateFunc cf);
		class Row* row;
		class ForeignKey* fk;
		bool m_isNewlyRecord;
		CString m_table;
	private:
		DISALLOW_COPY_AND_ASSIGN(Record);
	};
}

//注册字段(不包括外键)
#define REG_ATTRIB(field_name, var_name) this->map_field(_T(#field_name), var_name)
//注册外键
#define REG_FOREGIN_KEY(field_name, var_name, create_func) this->map_foreign_key(_T(#field_name), var_name, create_func);
