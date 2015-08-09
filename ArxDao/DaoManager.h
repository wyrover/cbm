#ifndef DAO_H
#define DAO_H

#include "dlimexp.h"

#include <boost/shared_ptr.hpp>
using boost::shared_ptr;

class DaoManager;
typedef boost::shared_ptr<DaoManager> DaoManagerPrt;

class ARXDAO_DLLIMPEXP DaoManager
{
public:
    static DaoManagerPrt Instance();

public:
	~DaoManager();
	bool config(const CString& host, const CString& user, const CString& password, const CString& database);

private:
	static DaoManagerPrt instance;
	DaoManager();
};

#endif // DAO_H
