#include "StdAfx.h"
#include "SComboxHelper.h"

void SComboBoxHelper::Append(SComboBox* combox, const StringArray& names, const IntArray& ids)
{
	SComboBoxHelper::Clear(combox);
	for(int i=0;i<names.size();i++)
	{
		SComboBoxHelper::Insert(combox, names[i], ids[i], i);
	}
}

int SComboBoxHelper::Add(SComboBox* combox, const CString& name, int id)
{
	return SComboBoxHelper::Insert(combox, name, id, combox->GetCount());
}

int SComboBoxHelper::Insert(SComboBox* combox, const CString& name, int id, int i)
{
	int pos = combox->InsertItem(i, name, 0, 0);
	if(pos != -1)
	{
		//附加数据
		ItemData* pData = new ItemData;
		pData->id = id;
		pData->nItem = i;
		combox->SetItemData(i, (LPARAM)pData);
	}
	return pos;
}

void SComboBoxHelper::Clear(SComboBox* combox)
{
	int n = combox->GetCount();
	for(int i=0;i<n;i++)
	{
		ItemData* pData = (ItemData*)combox->GetItemData(i);
		delete pData;
	}
	combox->ResetContent();
}

void SComboBoxHelper::DeleteCurSel(SComboBox* combox)
{
	SComboBoxHelper::DeleteByPos(combox, combox->GetCurSel());
}

int SComboBoxHelper::Find(SComboBox* combox, const CString& name)
{
	return combox->FindString(name);
}

void SComboBoxHelper::DeleteByString(SComboBox* combox, const CString& name)
{
	int nCurSel = combox->FindString(name);
	if(nCurSel == -1) return;
	SComboBoxHelper::DeleteByPos(combox, nCurSel);
}

void SComboBoxHelper::DeleteByPos(SComboBox* combox, int i)
{
	if(i<0 || i>=combox->GetCount()) return;

	ItemData* pData = (ItemData*)combox->GetItemData(i);
	delete pData;
	combox->DeleteString(i);
}

int SComboBoxHelper::GetItemID(SComboBox* combox, int i)
{
	if(i< 0 || i >= combox->GetCount()) return 0;
	ItemData* pData = (ItemData*)combox->GetItemData(i);
	return pData->id;
}

void SComboBoxHelper::SetCurSelByString(SComboBox* combox, const CString& name)
{
	combox->SetCurSel(combox->FindString(name));
}

void SComboBoxHelper::Select(SComboBox* combox, int i)
{
	if(combox->GetCount() == 0)
	{
		combox->SetCurSel(-1);
	}
	else
	{
		if(i < 0) 
		{
			i = -1;
		}
		else if(i >= combox->GetCount())
		{
			i = 0;
		}
		combox->SetCurSel(i);
	}
}

int SComboBoxHelper::GetCurSelItemID(SComboBox* combox)
{
	return SComboBoxHelper::GetItemID(combox, combox->GetCurSel());
}

CString SComboBoxHelper::GetCurSelString(SComboBox* combox)
{
	return (LPCTSTR)combox->GetLBText(combox->GetCurSel());
}

int SComboBoxHelper::GetCurSel(SComboBox* combox)
{
	return combox->GetCurSel();
}


void SListBoxHelper::Append(SListBox* listbox, const StringArray& names, const IntArray& ids)
{
	SListBoxHelper::Clear(listbox);
	for(int i=0;i<names.size();i++)
	{
		SListBoxHelper::Add(listbox, names[i], ids[i]);
	}
}

int SListBoxHelper::Add(SListBox* listbox, const CString& name, int id)
{
	int pos = listbox->AddString(name);
	if(pos != -1)
	{
		//附加数据
		ItemData* pData = new ItemData;
		pData->id = id;
		pData->nItem = pos;
		listbox->SetItemData(pos, (LPARAM)pData);
	}
	return pos;
}

int SListBoxHelper::Insert(SListBox* listbox, const CString& name, int id, int i)
{
	int pos = listbox->InsertString(i, name);
	if(pos != -1)
	{
		//附加数据
		ItemData* pData = new ItemData;
		pData->id = id;
		pData->nItem = pos;
		listbox->SetItemData(pos, (LPARAM)pData);
	}
	return pos;
}

void SListBoxHelper::Clear(SListBox* listbox)
{
	int n = listbox->GetCount();
	for(int i=0;i<n;i++)
	{
		ItemData* pData = (ItemData*)listbox->GetItemData(i);
		delete pData;
	}
	listbox->DeleteAll();
}

void SListBoxHelper::DeleteCurSel(SListBox* listbox)
{
	SListBoxHelper::DeleteByPos(listbox, listbox->GetCurSel());
}

int SListBoxHelper::Find(SListBox* listbox, const CString& name)
{
	int nCurSel = -1;
	for(int i=0;i<listbox->GetCount();i++)
	{
		SStringT str;
		listbox->GetText(i, str);
		if(str.Compare((LPCTSTR)name) == 0)
		{
			nCurSel = i;
			break;
		}
	}
	return nCurSel;
}

void SListBoxHelper::DeleteByString(SListBox* listbox, const CString& name)
{
	SListBoxHelper::DeleteByPos(listbox, SListBoxHelper::Find(listbox, name));
}

void SListBoxHelper::DeleteByPos(SListBox* listbox, int i)
{
	if(i<0 || i>=listbox->GetCount()) return;

	ItemData* pData = (ItemData*)listbox->GetItemData(i);
	delete pData;
	listbox->DeleteString(i);
}

int SListBoxHelper::GetItemID(SListBox* listbox, int i)
{
	if(i< 0 || i >= listbox->GetCount()) return 0;
	ItemData* pData = (ItemData*)listbox->GetItemData(i);
	return pData->id;
}

void SListBoxHelper::SetCurSelByString(SListBox* listbox, const CString& name)
{
	listbox->SetCurSel(SListBoxHelper::Find(listbox, name));
}

void SListBoxHelper::Select(SListBox* listbox, int i)
{
	if(listbox->GetCount() == 0)
	{
		listbox->SetCurSel(-1);
	}
	else
	{
		if(i < 0) 
		{
			i = -1;
		}
		else if(i >= listbox->GetCount())
		{
			i = 0;
		}
		listbox->SetCurSel(i);
	}
}

int SListBoxHelper::GetCurSelItemID(SListBox* listbox)
{
	return SListBoxHelper::GetItemID(listbox, listbox->GetCurSel());
}

CString SListBoxHelper::GetCurSelString(SListBox* listbox)
{
	SStringT str;
	listbox->GetText(listbox->GetCurSel(), str);
	return (LPCTSTR)str;
}

int SListBoxHelper::GetCurSel(SListBox* listbox)
{
	return listbox->GetCurSel();
}