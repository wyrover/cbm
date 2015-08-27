<?php

require("php_utils.php");
require("inflector.php");

//单词变复数
function pluralize_word($word)
{
	$inflector = new Inflector();
	return $inflector->pluralize($word);
}
// var_dump(pluralize_word('cbm_tunnel'));

function build_tbl_relations(&$relations, $tbl_name, $fields)
{
	//去掉cbm前缀,作为文件名
	$fname = table_no_prefix($tbl_name);
	//得到类名
	$clsname = camel_case($fname);

	foreach ($fields as $name => $type) {
		$param_type = $type;
		$parent_tbl_name = table_no_id($name);
		$var_name = $name;
		$field_name = table_no_prefix($parent_tbl_name);
		if($name == 'id') continue;
		//该字段是外键(所有的外键ID都是以_id结尾的)
		if($field_name != $name && $name != 'id') {
			$param_type = camel_case($field_name);
			$var_name = $field_name;

			if(!isset($relations[$parent_tbl_name])) {
				$relations[$parent_tbl_name] = array();
			}
			var_dump($parent_tbl_name."-->".$tbl_name);
			$relations[$parent_tbl_name][] = $tbl_name;
		}
	}
	// var_dump($relations);
}

function build_cbm_relations()
{
	$relations = array();

	$mysqli = mysqli_connect("localhost", "root", "", "cbm");

	/* check connection */
	if (mysqli_connect_errno()) {
	    printf("Connect failed: %s\r\n", mysqli_connect_error());
	    exit();
	}

	//查找所有的表名
	$result = $mysqli->query("show tables");//执行查询语句
	$tables=array();
	while($arr = $result->fetch_assoc()) {
	    $tbl = $arr["Tables_in_cbm"];//遍历查询结果
	    if($tbl == 'cbm_dummy') continue;
	    $tables[] = $tbl;
	}

	//查找表中的所有字段
	foreach($tables as $tbl) {
		$query = "SELECT * from $tbl";
		if ($result = mysqli_query($mysqli, $query)) {

		    /* Get field information for all columns */
		    $finfo = mysqli_fetch_fields($result);
		    $fields = array();
		    foreach ($finfo as $val) {
		        //类型编号映射成c++数据类型
		        // var_dump($tbl.'----'.h_type2txt($val->type));
		        $fields[$val->name] = cpp_type(h_type2txt($val->type));
		    }
		    //构造表关联
		    build_tbl_relations($relations, $tbl, $fields);

		    mysqli_free_result($result);
		}
	}

	/* close connection */
	mysqli_close($mysqli);
	return $relations;
}

//包含所有enttity类的头文件
function begin_entity_head_file($file, $tables)
{
	fwrite($file, "#ifndef CBM_ALL_ENTITIES_H".ENTER);
	fwrite($file, "#define CBM_ALL_ENTITIES_H".ENTER);

	fwrite($file, ENTER."#include ".DBL_QUOT."Record.h".DBL_QUOT.ENTER);
	fwrite($file, ENTER."#include <vector>".ENTER);
	fwrite($file, "#include <boost/shared_ptr.hpp>".ENTER);
	fwrite($file, "using namespace boost;".ENTER);

	//开始定义命名空间
	fwrite($file, ENTER."namespace cbm {".TWO_ENTER);

	//前向声明
    foreach ($tables as $tbl_name) {
		//去掉cbm前缀,作为文件名
		$fname = table_no_prefix($tbl_name);
		//得到类名
		$clsname = camel_case($fname);

		fwrite($file, "class $clsname;".ENTER);
	}

	fwrite($file, ENTER);
	foreach ($tables as $tbl_name) {
		//去掉cbm前缀,作为文件名
		$fname = table_no_prefix($tbl_name);
		//得到类名
		$clsname = camel_case($fname);

		fwrite($file, "typedef boost::shared_ptr<$clsname> $clsname"."Ptr;".ENTER);
	}
	// fwrite($file, ENTER);
	// foreach ($tables as $tbl_name) {
	// 	//去掉cbm前缀,作为文件名
	// 	$fname = table_no_prefix($tbl_name);
	// 	//得到类名
	// 	$clsname = camel_case($fname);
	// 	fwrite($file, "typedef boost::shared_ptr< std::vector<$clsname"."Ptr> > $clsname"."List;".ENTER);
	// }
}

//包含所有enttity类的头文件
function end_entity_head_file($file, $tables)
{
	fwrite($file, ENTER."} // namespace cbm".ENTER);
	fwrite($file, ENTER."#endif // CBM_ALL_ENTITIES_H".ENTER);
}

//生成实体的头文件
function gen_entity_head_file($file, $tbl_name, $fields, $relations)
{
	//去掉cbm前缀,作为文件名
	$fname = table_no_prefix($tbl_name);

	//得到类名
	$clsname = camel_case($fname);

	fwrite($file, ENTER."class".DLL_EXPORT.$clsname." : public orm::Record".ENTER);
	fwrite($file, "{".ENTER);
	
	//静态成员函数
	fwrite($file, "public:".ENTER);
	fwrite($file, TAB."static CString Table();".ENTER);
	fwrite($file, TAB."static orm::RecordPtr Create();".ENTER);

	//成员函数
	fwrite($file, ENTER."public:".ENTER);
	//构造函数
    fwrite($file, TAB."$clsname();".ENTER);
	//生成成员变量定义
	// fwrite($file, ENTER."public:".ENTER);
	// //(1)1->n映射
 //    if(isset($relations[$tbl_name])) {
	// 	foreach ($relations[$tbl_name] as $name) {
	// 		$field_name = table_no_prefix($name);
	// 		$param_type = camel_case($field_name);
	// 		$var_name = $field_name;
	// 		fwrite($file, TAB."ObjGroup<$param_type> ".pluralize_word($var_name).";".ENTER);
	// 	}	
	// }
	//字段变量
	foreach ($fields as $name => $type) {
		$param_type = $type;
		$var_name = $name;
		$field_name = table_no_prefix(table_no_id($name));
		if($name == 'id') continue;
		//该字段是外键(所有的外键ID都是以_id结尾的)
		if($field_name != $name && $name != 'id') {
			//$param_type = camel_case($field_name)."Ptr";
			$param_type = "orm::RecordPtr";
			$var_name = $field_name;
		}
		fwrite($file, TAB.$param_type." ".$var_name.";".ENTER);
	}
	fwrite($file, ENTER."}; // class $clsname".ENTER);
}

function begin_entity_cpp_file($file, $tables)
{
	if(VC_PRECOM) {
		fwrite($file, "#include ".DBL_QUOT."stdafx.h".DBL_QUOT.ENTER);
	}
	fwrite($file, "#include ".DBL_QUOT."Entity.h".DBL_QUOT.ENTER);
	// fwrite($file, "#include <Util/HelperClass.h>".ENTER);

	//开始定义命名空间
	fwrite($file, ENTER."namespace cbm {".ENTER);
}

function end_entity_cpp_file($file, $tables)
{
	fwrite($file, ENTER."} // namespace cbm".ENTER);
}

//生成实体的源文件
function gen_entity_source_file($file, $tbl_name, $fields, $relations)
{
	//去掉cbm前缀,作为文件名
	$fname = table_no_prefix($tbl_name);
	//得到类名
	$clsname = camel_case($fname);

	fwrite($file, ENTER."CString $clsname::Table()".ENTER);
	fwrite($file, "{".ENTER);
	fwrite($file, TAB."return ".tchar($tbl_name).";".ENTER);
	fwrite($file, "}".ENTER);

	fwrite($file, ENTER."orm::RecordPtr $clsname::Create()".ENTER);
	fwrite($file, "{".ENTER);
	fwrite($file, TAB."return orm::RecordPtr(new $clsname());".ENTER);
	fwrite($file, "}".ENTER);

	//构造函数
    fwrite($file, ENTER."$clsname::$clsname() : orm::Record($clsname::Table())".ENTER);
    fwrite($file, "{".ENTER);

	//初始化成员变量
    foreach ($fields as $name => $type) {
		$param_type = $type;
		$var_name = $name;
		$field_name = table_no_prefix(table_no_id($name));
		if($name == 'id') continue;
		//该字段是外键(所有的外键ID都是以_id结尾的)
		if($field_name != $name && $name != 'id') {
			$param_type = camel_case($field_name);
			$var_name = $field_name;
		}
		else {
			$default_value = type_default($type);
    		fwrite($file, TAB.$name." = ".$default_value.";".ENTER);
    	}
	}

	//注册属性,并关联成员变量
	foreach ($fields as $name => $type) {
		$param_type = $type;
		$var_name = $name;
		$field_name = table_no_prefix(table_no_id($name));
		if($name == 'id') continue;
		//该字段是外键(所有的外键ID都是以_id结尾的)
		if($field_name != $name && $name != 'id') {
			$param_type = camel_case($field_name);
			$var_name = $field_name;
		}
		else {
			fwrite($file, TAB."REG_ATTRIB($name, $var_name);".ENTER);
		}
	}

    //注册属性,并关联成员变量
	foreach ($fields as $name => $type) {
		$param_type = $type;
		$var_name = $name;
		$field_name = table_no_prefix(table_no_id($name));
		if($name == 'id') continue;
		//该字段是外键(所有的外键ID都是以_id结尾的)
		if($field_name != $name && $name != 'id') {
			$param_type = camel_case($field_name);
			$var_name = $field_name;
			fwrite($file, TAB."REG_FOREGIN_KEY($name, $var_name, &$param_type::Create);".ENTER);
		}
	}
	
    fwrite($file, "}".ENTER);

}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

function gen_dao_cpp_codes($relations)
{
	$mysqli = mysqli_connect("localhost", "root", "", "cbm");

	/* check connection */
	if (mysqli_connect_errno()) {
	    printf("Connect failed: %s\r\n", mysqli_connect_error());
	    exit();
	}

	//查找所有的表名
	$result = $mysqli->query("show tables");//执行查询语句
	$tables=array();
	while($arr = $result->fetch_assoc()) {
	    $tbl = $arr["Tables_in_cbm"];//遍历查询结果
	    if($tbl == 'cbm_dummy') continue;

	    $tables[] = $tbl;
	    		
	}

	//创建目录
	// rmdirs("entity");
	// rmdirs("model");
	// mkdirs("entity");
	// mkdirs("model");

	$entity_head_file = fopen('Entity.h', 'w');
	$entity_cpp_file = fopen('Entity.cpp', 'w');

	begin_entity_head_file($entity_head_file, $tables);
	begin_entity_cpp_file($entity_cpp_file, $tables);

	//查找表中的所有字段
	foreach($tables as $tbl) {
		echo $tbl."<br><pre>";
		$query = "SELECT * from $tbl";
		if ($result = mysqli_query($mysqli, $query)) {

		    /* Get field information for all columns */
		    $finfo = mysqli_fetch_fields($result);
		    $fields = array();
		    foreach ($finfo as $val) {
		        printf("\tName:     %s", $val->name);
		        // printf("Table:    %s<br>", $val->table);
		        // printf("max. Len: %d<br>", $val->max_length);
		        // printf("Flags:    %d<br>", $val->flags);
		        printf("\tType:     %s<br>", h_type2txt($val->type));
		        //类型编号映射成c++数据类型
		        $fields[$val->name] = cpp_type(h_type2txt($val->type));
		    }
		    mysqli_free_result($result);
		    echo "</pre>";
		    
			gen_entity_head_file($entity_head_file, $tbl, $fields, $relations);
			gen_entity_source_file($entity_cpp_file, $tbl, $fields, $relations);
		}
	}

	end_entity_head_file($entity_head_file, $tables);
	end_entity_cpp_file($entity_cpp_file, $tables);

	fclose($entity_head_file);
	fclose($entity_cpp_file);

	/* close connection */
	mysqli_close($mysqli);
}

function truncateDatas($file)
{
	fwrite($file, "truncate table cbm_tech_mode;".ENTER);
	fwrite($file, "truncate table cbm_technology;".ENTER);
	fwrite($file, "truncate table cbm_region;".ENTER);
	fwrite($file, "truncate table cbm_base;".ENTER);
	fwrite($file, "truncate table cbm_topo_geo;".ENTER);
	fwrite($file, "truncate table cbm_res_abundance;".ENTER);
}
function genMineBaseSqlFile($file, $txtfile)
{
	fwrite($file, ENTER);
	foreach(file($txtfile) as $line => $content) {
	    //拆分字符串(制表符分隔)
	    $data = explode("\t", trim($content));
		//基地编号
	    $id = intVal($data[0]);
	    //基地名称
	    $name = $data[1];
	    
	    fwrite($file, "insert into cbm_base(id, name) values($id, '$name');".ENTER);
	}
}

function genMineRegionSqlFile($file, $txtfile)
{
	fwrite($file, ENTER);
	foreach(file($txtfile) as $line => $content) {
	    //拆分字符串(制表符分隔)
	    $data = explode("\t", trim($content));
		//矿区编号
	    $id = intVal($data[0]);
	    //矿区名称
	    $name = $data[1];
	    //基地编号
	    $base_id = intval($data[2]);
	    
	    fwrite($file, "insert into cbm_region(id, name, cbm_base_id) values($id, '$name', $base_id);".ENTER);
	}
}

function genTechModeSqlFile($file, $txtfile)
{
	fwrite($file, ENTER);
	foreach(file($txtfile) as $line => $content) {
	    //拆分字符串(制表符分隔)
	    $data = explode("\t", trim($content));
	    var_dump($data);
		//技术模式编号
	    $id = intVal($data[0]);
	    //技术模式名称
	    $name = $data[1];
	    //矿区编号
	    $region_id = intval($data[2]);
	    $c1 = intval($data[3]);
	    $c2 = intval($data[4]);
	    $c3 = intval($data[5]);
	    
	    fwrite($file, "insert into cbm_tech_mode(id, name, cbm_region_id, c1, c2, c3) values($id, '$name', $region_id, $c1, $c2, $c3);".ENTER);
	}
}

function genTechnologySqlFile($file, $txtfile)
{
	fwrite($file, ENTER);
	foreach(file($txtfile) as $line => $content) {
	    //拆分字符串(制表符分隔)
	    $data = explode("\t", trim($content));
		//技术编号
	    $id = intVal($data[0]);
	    //技术名称
	    $name = $data[1];
	    //矿区编号
	    $region_id = intval($data[2]);
	    //是否关键技术
	    $isKey = intval($data[3]);
	    
	    fwrite($file, "insert into cbm_technology(id, name, isKey, cbm_region_id) values($id, '$name', $isKey, $region_id);".ENTER);
	}
}

function genComplexitySqlFile($file, $txtfile)
{
	fwrite($file, ENTER);
	foreach(file($txtfile) as $line => $content) {
	    //拆分字符串(制表符分隔)
	    $data = explode("\t", trim($content));
		//编号
	    $id = intVal($data[0]);
	    //名称
	    $name = $data[1];
	    //详细说明
	    $details = $data[2];
	    
	    fwrite($file, "insert into cbm_complexity(id, name, details) values($id, '$name', '$details');".ENTER);
	}
}

function genTopoGeoSqlFile($file, $txtfile)
{
	fwrite($file, ENTER);
	foreach(file($txtfile) as $line => $content) {
	    //拆分字符串(制表符分隔)
	    $data = explode("\t", trim($content));
		//编号
	    $id = intVal($data[0]);
	    //分类
	    $name = $data[2];
	    //特点
	    $feature = $data[1];
	    
	    fwrite($file, "insert into cbm_topo_geo(id, name, feature) values($id, '$name', '$feature');".ENTER);
	}
}

function genResAbundanceSqlFile($file, $txtfile)
{
	fwrite($file, ENTER);
	foreach(file($txtfile) as $line => $content) {
	    //拆分字符串(制表符分隔)
	    $data = explode("\t", trim($content));
		//编号
	    $id = intVal($data[0]);
	    //分类
	    $name = $data[1];
	    //丰度上下限
	    $min_a = floatval($data[2]);
	    $max_a = floatval($data[2]);
	    
	    fwrite($file, "insert into cbm_res_abundance(id, name, min_abundance, max_abundance) values($id, '$name', $min_a, $max_a);".ENTER);
	}
}

function genAccountSqlFile($file, $txtfile)
{
	fwrite($file, ENTER);
	foreach(file($txtfile) as $line => $content) {
	    //拆分字符串(制表符分隔)
	    $data = explode("\t", trim($content));
		//编号
	    $id = intVal($data[0]);
	    //用户名
	    $user = $data[1];
	    //密码
	    $pwd = $data[2];
	    
	    fwrite($file, "insert into cbm_account(username, password) values('$user', '$pwd');".ENTER);
	}
}

function genMineSqlFile($file, $txtfile)
{
	fwrite($file, ENTER);
	foreach(file($txtfile) as $line => $content) {
	    //拆分字符串(制表符分隔)
	    $data = explode("\t", trim($content));
		//编号
	    $id = intVal($data[0]);
	    //用户名
	    $name = $data[1];
	    //矿区
	    $region_id = $data[2];
	    //账户
	    $account_id = $data[3];
	    
	    fwrite($file, "insert into cbm_mine(name, cbm_region_id, cbm_account_id) values('$name', $region_id, $account_id);".ENTER);
	}
}

function genRockSqlFile($file, $txtfile)
{
	fwrite($file, ENTER);
	foreach(file($txtfile) as $line => $content) {
	    //拆分字符串(制表符分隔)
	    $data = explode("\t", trim($content));
		//编号
	    $id = intVal($data[0]);
	    //名称
	    $name = $data[1];
	    //a
	    $a = floatval($data[2]);
	    //b
	    $b = floatval($data[3]);
	    //c
	    $c = floatval($data[3]);
	    
	    fwrite($file, "insert into cbm_rock(id, name, a, b, c) values($id, '$name', $a, $b, $c);".ENTER);
	}
}

//建立表关系映射
$relations = build_cbm_relations();

//项目路径(读取root.txt文件得到)
$projDir = file_get_contents('root.txt');

//生成c++代码
gen_dao_cpp_codes($relations);
//将c++代码复制到cbm项目
copy('Entity.h', $projDir.'ArxDao\Entity.h');
copy('Entity.cpp', $projDir.'ArxDao\Entity.cpp');

//将建表的sql文件一次性追加到新sql文件中
// file_put_contents('cbm.sql', file_get_contents('cbm-mysql.sql'));
//生成sql插入语句
$file = fopen("cbm-data.sql", "w");
//生成煤炭基地的sql数据文件
// truncateDatas($file);
// genAccountSqlFile($file, 'account.txt');
genMineBaseSqlFile($file, 'base.txt');
genMineRegionSqlFile($file, 'region.txt');
// genMineSqlFile($file, 'mine.txt');
genTechModeSqlFile($file, 'tech_mode.txt');
genTechnologySqlFile($file, 'technology.txt');
genTopoGeoSqlFile($file, 'topo_geo.txt');
genComplexitySqlFile($file, 'complexity.txt');
genResAbundanceSqlFile($file, 'res_abundance.txt');
genRockSqlFile($file, 'rock.txt');
fclose($file);

//将sql文件复制到cbm项目
copy('cbm-mysql.sql', $projDir.'php\cbm\cbm-mysql.sql');
copy('cbm-data.sql', $projDir.'php\cbm\cbm-data.sql');

//将php代码复制到cbm项目
// copy('root.txt', $projDir.'php\cbm\root.txt');
copy('index.php', $projDir.'php\cbm\index.php');
copy('inflector.php', $projDir.'php\cbm\inflector.php');
copy('php_utils.php', $projDir.'php\cbm\php_utils.php');

?>
