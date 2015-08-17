<?php

require('sql_utils.php');

function soui_control_type($type)
{
  static $ctrl_dicts = array(
    // "window" => "SWindow",
    // "caption" => "SCaption",
    // "group" => "SGroup",
    // "imgbtn" => "SImageButton",
    // "button" => "SButton",
    "text" => "SStatic",
    "edit" => "SEdit",
    "richedit" => "SRichEdit",
    "combobox" => "SComboBox",
    "radio" => "SRadioBox",
    "toggle" => "SToggle",
    "checkbox" => "SCheckBox",
    "img" => "SImageWnd",
    "link" => "SLink",
    "icon" => "SIconWnd",
    "comboboxex" => "SComboBoxEx",
    "header" => "SHeaderCtrl",
    "listbox" => "SListBox",
    "listboxex" => "SListBoxEx",
    "listctrl" => "SListCtrl",
    "slider" => "SSliderBar",
    "splitpane" => "SSplitPane",
    "splitwnd" => "SSplitWnd",
    // "page" => "STabPage",
    "tabctrl" => "STabCtrl",
    "treebox" => "STreeBox",
    "treectrl" => "STreeCtrl",
    "animateimg" => "SAnimateImgWnd"
  );
  if(!isset($ctrl_dicts[$type]) || is_null($type)) 
    return null;
  else
    return $ctrl_dicts[$type];
}

function short_name($type)
{
  static $short_names = array(
    "combobox" => "combox"
  );
  if(!isset($short_names[$type])) {
    return $type;
  }
  else {
    return $short_names[$type];
  }
}

function real_name($name, $type)
{
  //去掉左右两侧的$type表示的字符串
  $name = str_ireplace($type, "", $name);
  //去掉两侧多余的下划线
  $name = trim($name, "_");

  if(preg_match("/^[0-9]+/", $name)) {
    return short_name($type).$name;
  }
  else {
    return $name."_".short_name($type);
  }
}

function declare_vars($file, $vars)
{
  fwrite($file, ENTER."protected:".ENTER);

  foreach ($vars as $name => $type) {
    $ctrl_type = soui_control_type($type);
    if(is_null($ctrl_type)) continue;

    $var_name = camel_case(real_name($name, $type));
    fwrite($file, TAB.$ctrl_type."* m_".$var_name.";".ENTER);
  }
}

function impl_function_onInitDialog($file, $vars)
{
  foreach ($vars as $name => $type) {
    $ctrl_type = soui_control_type($type);
    if(is_null($ctrl_type)) continue;

    $var_name = camel_case(real_name($name, $type));
    fwrite($file, TAB."m_$var_name = FindChildByName2<$ctrl_type>(L".DBL_QUOT.$name.DBL_QUOT.");".ENTER);
  }
}

function msg_map($file, $vars)
{
  foreach ($vars as $name => $type) {
    // $ctrl_type = soui_control_type($type);
    $var_name = camel_case(real_name($name, $type));

    if($type == 'button') {
      $func_name = "On".$var_name."Click";
      fwrite($file, TWO_TAB."EVENT_NAME_COMMAND(".tchar($name).", $func_name)".ENTER);
    }
    else if($type == 'combobox') {
      $func_name = "On".$var_name."SelChanged";
      fwrite($file, TWO_TAB."EVENT_NAME_COMMAND(".tchar($name).", $func_name)".ENTER);
    }
  }
}

function make_function($func_name, $params="", $prefix="", $return_type="void")
{
  if($prefix != "" && !is_null($prefix)) {
    $prefix = $prefix."::";
  }
  return "$return_type"." ".$prefix."".$func_name."(".$params.")";
}

function make_function_no_param($func_name, $prefix="", $return_type="void")
{
  return make_function($func_name, "", $prefix, $return_type);
}

function declare_msg_handler($file, $vars)
{
  foreach ($vars as $name => $type) {
    // $ctrl_type = soui_control_type($type);
    $var_name = camel_case($name."_".short_name($type));

    if($type == 'button') {
      $func_name = "On".$var_name."Click";
      $func = make_function_no_param($func_name);
      fwrite($file, TAB."$func;".ENTER);
    }
    else if($type == 'combobox') {
      $func_name = "On".$var_name."SelChanged";
      $func = make_function($func_name, $params="SOUI::EventArgs *pEvt");
      fwrite($file, TAB."$func;".ENTER);
    }
  }
}

function impl_msg_handler($file, $vars, $Class)
{
  fwrite($file, ENTER);
  foreach ($vars as $name => $type) {
    // $ctrl_type = soui_control_type($type);
    $var_name = camel_case($name."_".short_name($type));

    if($type == 'button') {
      $func_name = "On".$var_name."Click";
      $func = make_function_no_param($func_name, $Class);
      fwrite($file, "$func".ENTER);
      fwrite($file, "{".ENTER);
      fwrite($file, "}".TWO_ENTER);
    }
    else if($type == 'combobox') {
      $func_name = "On".$var_name."SelChanged";
      $func = make_function($func_name, "SOUI::EventArgs *pEvt", $Class);
      fwrite($file, "$func".ENTER);
      fwrite($file, "{".ENTER);
      fwrite($file, TAB.'EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;'.ENTER);
      fwrite($file, TAB."if(pEvtOfCB == 0) return;".TWO_ENTER);
      fwrite($file, TAB."int nCurSel = pEvtOfCB->nCurSel;".ENTER);
      fwrite($file, TAB."// do something".ENTER);
      fwrite($file, "}".TWO_ENTER);
    }
  }
}

function dlg_head_file($file, $dlg, $vars)
{
  $ChildDlg = camel_case($dlg)."Dialog";
  $ParentDlg='AcadSouiDialog';

  fwrite($file, "#pragma once".ENTER);
  fwrite($file, "#include ".DBL_QUOT."$ParentDlg.h".DBL_QUOT.TWO_ENTER);
  fwrite($file, "class $ChildDlg : public $ParentDlg".ENTER);
  fwrite($file, "{".ENTER);
  fwrite($file, ENTER.TAB."/** 构造和析构函数 */".ENTER);
  fwrite($file, "public:".ENTER);
  fwrite($file, TAB."RegDlg(BOOL bModal = FALSE);".ENTER);
  fwrite($file, TAB."~RegDlg(void);".ENTER);

  fwrite($file, ENTER.TAB."/** 控件消息处理 */".ENTER);
  fwrite($file, "protected:".ENTER);
  declare_msg_handler($file, $vars);

  fwrite($file, ENTER.TAB."/** 菜单消息 */".ENTER);
  fwrite($file, "protected:".ENTER);
  fwrite($file, TAB."//处理菜单消息(菜单在一个单独的xml文件中描述，每个菜单项都有一个id号)".ENTER);
  fwrite($file, TAB."void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);".ENTER);


  fwrite($file, ENTER.TAB."/** 窗口消息 */".ENTER);
  fwrite($file, "protected:".ENTER);
  fwrite($file, TAB."//对话框初始化过程".ENTER);
  fwrite($file, TAB."LRESULT OnInitDialog(HWND hWnd, LPARAM lParam);".ENTER);

  fwrite($file, ENTER.TAB."//控件消息映射表".ENTER);
  fwrite($file, TAB."EVENT_MAP_BEGIN()".ENTER);
  //控件消息映射声明
  msg_map($file, $vars);
  fwrite($file, TWO_TAB."CHAIN_EVENT_MAP($ParentDlg)".ENTER);
  fwrite($file, TAB."EVENT_MAP_END()".ENTER);

  fwrite($file, TAB.ENTER."//HOST消息(WINDOWS消息)映射表".ENTER);
  fwrite($file, TAB."BEGIN_MSG_MAP_EX($ChildDlg)".ENTER);
  fwrite($file, TWO_TAB."MSG_WM_INITDIALOG(OnInitDialog)".ENTER);  
  fwrite($file, TWO_TAB."MSG_WM_COMMAND(OnCommand)".ENTER);
  fwrite($file, TWO_TAB."CHAIN_MSG_MAP($ParentDlg)".ENTER);
  fwrite($file, TWO_TAB."REFLECT_NOTIFICATIONS_EX()".ENTER);
  fwrite($file, TAB."END_MSG_MAP()".ENTER);

  //变量声明
  declare_vars($file, $vars);

  fwrite($file, "};".ENTER);

}

function dlg_cpp_file($file, $dlg, $vars)
{
  $ChildDlg = camel_case($dlg)."Dialog";
  $ParentDlg='AcadSouiDialog';

  fwrite($file, "#include ".DBL_QUOT."stdafx.h".DBL_QUOT.ENTER);
  fwrite($file, "#include ".DBL_QUOT."$ChildDlg.h".DBL_QUOT.ENTER);

  fwrite($file, ENTER."#include <ArxHelper/HelperClass.h>".ENTER);
  fwrite($file, "#include <ArxDao/DaoHelper.h>".ENTER);
  fwrite($file, "#include <ArxDao/Entity.h>".ENTER);
  fwrite($file, "using namespace orm;".ENTER);
  fwrite($file, "using namespace cbm;".ENTER);

  //构造函数
  fwrite($file, ENTER."$ChildDlg::$ChildDlg(BOOL bModal) : $ParentDlg(".tchar("layout:$dlg")."), bModal)".ENTER);
  fwrite($file, "{".ENTER);
  fwrite($file, "}".ENTER);
  //析构函数
  fwrite($file, ENTER."$ChildDlg::~$ChildDlg()".ENTER);
  fwrite($file, "{".ENTER);
  fwrite($file, "}".ENTER);

  //OnCommand函数
  fwrite($file, ENTER."void $ChildDlg::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )".ENTER);
  fwrite($file, "{".ENTER);
  fwrite($file, TAB."if(uNotifyCode==0)".ENTER);
  fwrite($file, TAB."{".ENTER);
  fwrite($file, TWO_TAB."//if(nID==6)".ENTER);
  fwrite($file, TWO_TAB."//{".ENTER);
  fwrite($file, TWO_TAB."//}".ENTER);
  fwrite($file, TAB."}".ENTER);
  fwrite($file, "}".ENTER);

  //OnInitDialog函数
  fwrite($file, ENTER."LRESULT $ChildDlg::OnInitDialog( HWND hWnd, LPARAM lParam )".ENTER);
  fwrite($file, "{".ENTER);
  //变量定义
  impl_function_onInitDialog($file, $vars);
  fwrite($file, ENTER.TAB."SetMsgHandled(FALSE);".ENTER);
  fwrite($file, TAB."return 0;".ENTER);
  fwrite($file, "}".ENTER);


  impl_msg_handler($file, $vars, $ChildDlg);
}

function dlg_file($dir, $dlg, $vars)
{
  $ChildDlg = camel_case($dlg)."Dialog";

  //生成头文件
  $file = fopen($dir."/"."$ChildDlg.h", "w");
  dlg_head_file($file, $dlg, $vars);
  fclose($file);

  //生成源文件
  $file = fopen($dir."/"."$ChildDlg.cpp", "w");
  dlg_cpp_file($file, $dlg, $vars);
  fclose($file);
}

function walk_xml_tree($root, &$vars) 
{
   foreach ($root->childNodes as $node) {
    $name = $node->getAttribute('name');
    $type = $node->nodeName;
    if($type == 'text') continue;
    echo "$name --> $type"."<br/>";
    $vars[$name] = $type;
    if($type == 'window' || $type == 'group') {
      walk_xml_tree($node, $vars);
    }
   }
}

function xml_to_vars($xmlfile)
{
  //记录所有的变量
  $vars = array();

  //创建一个XML文档并设置XML版本和编码
  $doc = new DomDocument();
  $doc->preserveWhiteSpace = false;
  $doc->load($xmlfile);
  // $doc->formatOutput = true;
  //xml输出的时候要加上编码,否则输出的中文变成一堆奇怪的符号
  $doc->encoding = 'UTF-8';

  $root = $doc->getElementsByTagName('root')->item(0);
  walk_xml_tree($root, $vars);
   return $vars;
}

function xml_to_dialog($xmlDir, $cppDir)
{
  // rmdirs($cppDir);
  // mkdirs($cppDir);

  //获取本文件目录的文件夹地址
  $filesnames = scanfiles($xmlDir);
  //获取也就是扫描文件夹内的文件及文件夹名存入数组 $filesnames
  foreach ($filesnames as $name) {
    if($name == '.' || $name == '..') continue;

    //得到没有扩展名的文件名
    $fname = pathinfo($name)['filename'];
    $ext = pathinfo($name)['extension'];
    if($ext != 'xml') continue;
    if($fname == 'init') continue;

    //拼接xml文件名
    $xmlfile = $xmlDir.'/'.$fname.'.xml';
    echo $xmlfile."<br/>";

    //解析得到所有的变量
    $vars = xml_to_vars($xmlfile);
    //生成c++代码
    dlg_file($cppDir, $fname, $vars);
  }
}

xml_to_dialog('xml', 'cpp');

recurse_copy('cpp', 'C:\Develop\GitProject\cbm\ArxSoUI');

?>