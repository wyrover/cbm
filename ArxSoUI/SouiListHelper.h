#pragma once

struct ItemData
{
    int id;
    int nItem;
};

class SComboBoxHelper
{
public:
    static void Append( SComboBox* combox, const StringArray& names, const IntArray& ids );
    static int Add( SComboBox* combox, const CString& name, int id );
    static int Insert( SComboBox* combox, const CString& name, int id, int i );
    static void Clear( SComboBox* combox );
    static int Find( SComboBox* combox, const CString& name );
    static void Select( SComboBox* combox, int i );
    static void DeleteByString( SComboBox* combox, const CString& name );
    static void DeleteByPos( SComboBox* combox, int i );
    static int GetItemID( SComboBox* combox, int i );

    static void SetCurSelByString( SComboBox* combox, const CString& name );
    static void DeleteCurSel( SComboBox* combox );
    static int GetCurSelItemID( SComboBox* combox );
    static CString GetCurSelString( SComboBox* combox );
    static int GetCurSel( SComboBox* combox );
};

class SListBoxHelper
{
public:
    static void Append( SListBox* listbox, const StringArray& names, const IntArray& ids );
    static int Find( SListBox* listbox, const CString& name );
    static int Add( SListBox* listbox, const CString& name, int id );
    static int Insert( SListBox* listbox, const CString& name, int id, int i );
    static void Clear( SListBox* listbox );
    static void Select( SListBox* listbox, int i );
    static void DeleteByString( SListBox* listbox, const CString& name );
    static void DeleteByPos( SListBox* listbox, int i );
    static int GetItemID( SListBox* listbox, int i );

    static void SetCurSelByString( SListBox* listbox, const CString& name );
    static void DeleteCurSel( SListBox* listbox );
    static int GetCurSelItemID( SListBox* listbox );
    static CString GetCurSelString( SListBox* listbox );
    static int GetCurSel( SListBox* listbox );
};


class SListCtrlHelper
{
public:
    static int Add( SListCtrl* listctrl, int id );
    static int Insert( SListCtrl* listctrl, int id, int i );
    static void SetStringItem( SListCtrl* listctrl, int i, int j, const CString& value );
    static void SetIntItem( SListCtrl* listctrl, int i, int j, int value );
    static void SetDoubleItem( SListCtrl* listctrl, int i, int j, double value, int precision = 3 );
    static bool GetStringItem( SListCtrl* listctrl, int i, int j, CString& value );
    static bool GetIntItem( SListCtrl* listctrl, int i, int j, int& value );
    static bool GetDoubleItem( SListCtrl* listctrl, int i, int j, double& value );
    static void Delete( SListCtrl* listctrl, int i );
    static int GetItemID( SListCtrl* listctrl, int i );
    static void Clear( SListCtrl* listctrl );

    static void DeleteCurSel( SListCtrl* listctrl );
    static int GetCurSelItemID( SListCtrl* listctrl );
};