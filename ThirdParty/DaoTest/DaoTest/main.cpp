#include <iostream>
#include <string>
#include "EncodeHelper.h"
#include "entity/entities.h"
#include "model/models.h"
#include <Windows.h>
using namespace cbm;

void TestDao()
{
	Mine mine;
	mine.setUsername("dlj");
	mine.setPassword("123");
	//mine.setMineName("test½úÃº¼¯ÍÅ");
	mine.setMineName(EncodeHelper::UnicodeToANSI(L"ÄãºÃ°¡"));

	MineDao dao;
	dao.insert(mine);
}

int main()
{
	Dao::Configure("localhost", "root", "", "cbm");

	TestDao();
	return 0;
}