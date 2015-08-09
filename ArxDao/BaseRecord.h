#pragma once

#include <stactive_record.h>
using namespace stactiverecord;

template <class Klass>
class BaseRecord : public Record<Klass>
{
public:
	BaseRecord() : Record<Klass>()
	{
		subUpdate();
	}
	BaseRecord(int id) : Record<Klass>(id)
	{
		Klass::subUpdate();
	}
	void save()
	{
		Klass:subSave();
		Record<Klass>::save();
	}
	void update()
	{
		Record<Klass>::update();
		Klass::subUpdate();
	}
protected:
	void subSave() {}
	void subUpdate() {}
};