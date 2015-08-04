# soui的xml设计器

首先上2个图，如果大家觉得还可以，继续看下去，觉得是垃圾的话那就关闭这个页面吧。**本工具的定位在于前期快速拖拉出一个大致能看的过去[soui][1]界面初稿（没错，就是初稿），把逻辑功能先实现了再说，后期再微调皮肤和样式，bingo~**
### mockups手绘的界面（这个几分钟就能拖拉出来）
<img src="http://i1.tietuku.com/6cf40e3989540ff5.png">
### 生成soui的xml文件效果
<img src="http://i1.tietuku.com/d68f2646293eedc2.png">

# 一 开场吐槽
[soui][1]是一个非常不错的DUI库，感谢作者的辛苦劳动。但是但是懒惰的程序员们习惯了拖拉界面的日子，让我们完全手写xml文件实在是太痛苦了些，奈何soui还没有一个成品的设计器（半成品的都木有），看着MFC、Qt、Android、Windows Form、WebUI这些开发工具，随便拖拉几下就可以快速做出一个大致的界面来，实在是口水不止~~~那该怎么办呢？我总结了大概这么几种方法：

1. 独立开发一个soui设计器（没这能力、也没这时间，看看duilib的那个设计器就知道了，没事就给你弄个崩溃，喊冤都没地方哭去~）
2. 改换门庭，转投它家（开玩笑，千挑万选才相中soui，嘿嘿） 
3. **借用其他工具或语言的设计器，通过某种技术手段生成soui的xml文件（这个思路我认为还是比较可行的，开源时代最反对“重复造轮子”嘛）**

注：soui的一些demo例子，非常的炫（传送门：http://www.cnblogs.com/setoutsoft/p/4155997.html）

# 二 SOUI的xml文件说明
如果去掉xml文件中关于样式和皮肤的部分，所有的窗口和控件都可以看作一个是方框，好看的界面都是在方框上贴图贴出来的效果。设计器（或者说soui的xml文件）最关心的是窗口或控件的**位置、大小以及其他的一些基本属性**。像***皮肤、样式、字体***等都可以后期再进行微调和美化！！！
# 三、设计器选择
考察过的设计器大致有这么几个：VC对话框设计器、Qt设计器、Android的UI设计器、WebUI设计器、UI原型设计软件
## 3.1 VC的对话框设计器
生成的是一个rc文件，文件内容和格式看着挺简单，实际解析起来挺费劲，微软也不给开放一个接口或者库啥的。
## 3.2 Qt设计器
Qt官网下载地址：http://www.qt.io/download-open-source/#section-2
Qt设计器设计的界面保存为*.ui格式，ui文件实质就是一个xml格式文件，如下所示是一个ui文件的片段。理论上而言，只要有一个好的xml解析库，转换成soui的xml文件应该是可行的，但是本人对xml格式无爱，感觉xml太罗嗦太繁琐了，也不够时髦（我更喜欢用json，嘿嘿）。另外你得安装一套Qt开发环境，才能用这个Designer工具。
**注：这种转换就可以用那些文本处理能力更强的语言来做，比如php、python等**
<img src="http://i1.tietuku.com/5f0fa9c91fb04e06.png">

## 3.3 Android的UI设计器
曾经有段时间也对Android开发有过兴趣，Android SDK自带的设计器确实强大，做一个简单界面分分秒秒的事，做复杂界面也不难。但是但是，做Android开发有3大难关要过：

1. Android SDK安装困难，要翻越伟大的GFW（貌似现在国内有Android SDK镜像了）；
2. 机器配置要求高，要不你连eclipse都运行不起来；
3. 还得安装一个Android模拟器（真机android开发？我只能祝你好运了）

## 3.4 WebUI设计器
现在的web技术太强大了，每每看到那些简洁、素雅、酷炫的网页都口水不止，有时候就想html标签不就是soui里的控件吗，css不就是soui的控件属性和样式，把这些解析出来难度不大吧。查阅资料后才知道初生牛犊不怕虎是神马意思。主要技术难点：

1. html+css解析google、微软、苹果等这些牛叉公司也不敢说一点问题都没有，兼容性问题分分钟钟搞死你；
2. web页面有2种设计方式，一种是纯前端设计，即利用html+css+javascript实现（这种方法要求前端技术非常熟悉才行）；另一种就是利用ps等平面设计软件进行设计，然后切图再配合div+css做出web页面（工科男一个，实在是没有学ps的天份），so放弃~~

## 3.5 UI原型设计软件
在正规的软件开发公司，软件设计的前期要快速开发出一套原型，供开发人员和客户之间协商沟通和讨论。那么原型到底长什么样呢？用什么画？白纸、笔和大脑？
然而用户的需求是苛刻的，用户的需求很多时候是互相矛盾不合理的，用户有时候都不知道他们到底想要什么，于是乎一大批UI原型设计软件纷纷出世，替代传统的白纸+手工绘制方法。目前原型设计软件按照用途主要分为3类：Web UI原型设计、手机APP原型设计、软件UI原型设计。这些软件大多都可以导出成png、pdf、html等格式，供开发人员和用户交流讨论。
这些软件的最终目的不是为了画出一个漂亮的UI，而是通过类似***涂鸦、素描、手绘风格***的简单线条和方框快速勾勒出一个原型出来，与用户进行交流和反复修改。考察过的UI原型设计软件有3个：

1. **AxureRP**（主流原型设计软件，据说很多大公司在使用，可以免费试用30天）
<img src="http://i1.tietuku.com/46bc6171cc1fb8a6.png">
可以生成html网页，html源码相对来说不太复杂，但解析也不太容易。
<img src="http://i1.tietuku.com/2d7837083292c767.png">
<img src="http://i1.tietuku.com/f261340b119aee85.png">
2. **Balsamiq Mockups**（基于Adobe Air + Flex技术开发，手绘风格的界面比较不错，也是收费的，可以免费试用30天）；
<img src="http://i1.tietuku.com/6a99f77c8f0272e8.png">
mockups有个我非常喜欢的功能，它可以将原型界面的信息导出成**json**格式，然后我们就可以利用json数据解析得到soui的xml文件
3. **Pencil Project**（开源的UI原型设计软件，可惜从2013年开始就不更新了，功能也基本够用，但和主流的UI原型设计软件差距较大）
<img src="http://i1.tietuku.com/6a0a31d81dc8c8f1.png">
也是可以导出一个html格式的布局文件，理论上解析该文件也可以得到soui的xml文件，但难度不小，该软件自带的控件种类较少，界面效果也太丑，嘿嘿。
<img src="http://i1.tietuku.com/2a6795a9aee1a5ef.png">
<img src="http://i1.tietuku.com/cfff1650d2d1ea88.png">

# 四 利用mockups生成soui的xml文件
## 4.1 思路
**废话就不多说了，我的主要思路是：用mockups手绘界面，然后导出json格式的数据，通过本文的soui.php脚本，将json数据解析成soui需要的xml文件。**
有这么几点要说明：

1. mockups是收费软件，但可以免费试用30天，功能没有阉割；
2. 解析json的方法很多，有很多的库，很多的编程语言可选，我选择的是PHP（语法简单，看懂代码应该没有问题，半天时间就可以上手写代码了，边写边查资料毫无压力）；
3. 生成的xml文件没有考虑皮肤和样式，所以不要太苛求了，咱只想快点拖拉一个界面出来~~~

## 4.2 开发环境搭建及软件安装

1. 安装Balsamiq Mockups 3
mockups官网：https://balsamiq.com/  （英文页面）
**注：也可以在线使用，点击官网的“Start Web App Trial”注册账号就可以用了（没在线用过，估计也是30天时间限制）**
2. 搭建PHP开发环境，为了省事推荐直接安装wampserver
wampserver官网：http://www.wampserver.com/en/  （英文页面）
**注：wampserver包括php、apache、mysql、phpmyadmin等，需要用的时候启动服务器即可，不用的时候关闭服务，关闭服务器，资源占用不是太离谱。另外具体怎么用，怎么运行php代码就不多说了，找度娘去~**
3. 一个好的文本编辑器
不要告诉我你的电脑上只有一个记事本，没有高亮，没有简单的语法提示，你让码农怎么活（no zuo no die）。文本编辑器有很多：sublime text2、notepad++、ultraedit、editplus、vim、Emacs等，个人推荐sublime text。
4. VC + soui
这个就不需要多说了吧
soui1：https://github.com/setoutsoft/soui  (稳定版本)
soui2：http://code.taobao.org/svn/soui2/trunk     (尝新版本)
soui文档教程：http://www.cnblogs.com/setoutsoft/

## 4.3、用mockups绘制界面
怎么画图我想不需要手把手教了吧，虽然没有中文界面，但我认为上手应该没有问题，在众多ui原型设计软件中，mockups能够存活下来并独树一帜，容易上手就是它的一个特色。
这里要说的是，mockups提供了非常多的ui元素，但soui的控件（包括大神们贡献的控件）也只是其中的一小部分而已，我也没能力全部支持，要是soui发展壮大，大神们将mockups的所有ui元素都扩展实现，那就爽歪歪了。
目前支持的mockups控件，以及与soui控件的映射关系如下：

```
function mockups_type_to_soui_type($type)
{
  static $soui_type_dicts = array(
    'TextInput' => 'edit',
    'Label' => 'text',
    'Button' => 'button',
    'ComboBox'=> 'combobox',
    'CheckBox' => 'check',
    'RadioButton' => 'radio',
    'Image' => "img",
    'Canvas' => 'window',
    'Link' => 'link',
    'TextArea' => 'richedit',
    'Paragraph' => 'richedit',
    'List' => 'listbox',
    'HSlider' => 'sliderbar',
    'VSlider' => 'sliderbar',
    'ProgressBar' => 'progress',
    'HRule' => 'hr',
    'VRule' => 'hr',
    'DataGrid' => 'listctrl',
    'TabBar' => 'tabctrl',
    'VerticalTabBar' => 'tabctrl',
    'Tree' => 'treectrl'
  );
  if(isset($soui_type_dicts[$type])) {
    return $soui_type_dicts[$type];
  }
  else {
    return 'unknown'; // 未知控件或暂不支持的控件
  }
}
```

还有很多的控件目前没有支持，希望各路大神发挥开源精神，做2件事之一即可：

1. 扩展soui，实现mockups中的ui元素
2. 修改本文的php代码，支持还没有实现的soui控件，比如标题栏caption、分组group，window，分割窗口(splitwnd、splitpane）、日历calenda等

## 4.4 mockups导出json数据
### 4.4.1 如何导出？
按快捷键ctrl+e即可，mockups会提示你已经保存到系统剪贴板里
（1）鼠标选择一个ui元素，按ctrl+e，提示你已经保存到系统的剪贴板，粘贴到一二
（2）鼠标框选多个ui元素，按ctrl+e
（3）按ctrl+a全选，再按ctrl+e
<img src="http://i1.tietuku.com/1122002753882949.png">
### 4.4.2 如何保存？
粘贴到文件里保存即可，但该文件必须是**utf8**格式（不能是ANSI格式，不能是GBK、GB2312，也不能是unicode，也不能是utf8-bom格式）
注1：千万不要用记事本自带的另存为utf8格式，它最终保存的实质是***utf8-bom***，坑死你不偿命!!!
注2：推荐用sublime text、notepad++编辑，它们都内置编码转换功能或者有插件可以将文件进行编码转换，非常方便
注3：sublime text新建文件默认是utf8格式，如果在windows下使用，建议安装package control、ConvertToUTF8、GBK Encoding这3个插件扩展，要不然gbk格式中文文件打开会乱码
### 4.4.3 有没有查看json数据更直观的方法？
当然有，网上有很多的json在线编辑器，都非常的不错，这里给一个我自己在用的：http://www.qqe2.com/ （非广告，选择自己喜欢的就行）
注1：json数据可以显示成一行，也可以显示成树状结构（前提是没有错误）
注2：保存到文件的json数据最好是一行，树状结构虽然美观，但php解析起来有时候会有点问题
**==>json数据在一行**
<img src="http://i3.tietuku.com/3c20d994e87fa59e.png">
**==>json数据树状结构**
<img src="http://i3.tietuku.com/cf2872f2a16e60e4.png">
### 4.4.4 mockups导出的json数据格式说明
mockups最具特色的2个功能：
1. 手绘风格，使用简单（这个是官方也是网上很多做ui设计的人们口口相传的，咱也认同）；
2. 可以导出json数据（官方貌似没有特意宣传这个特色，但我非常的喜欢，真心不错）

从开发的角度来说，市面上的其它UI原型设计软件大多都只提供**html**格式的导出功能。为什么呢？因为按照它们的定位，UI原型还只是一个**草稿**，不是正式的产品界面。说白了就是，这个东西画出来就是给你们看的（程序员和用户），把它当成图片看看就拉倒，具体程序上怎么绘制UI用这个**草稿**作为参考就行了。
但是html的解析太复杂，里面涉及到css、javascript等等，难度不是一般的大。相反，mockups导出的json包含了我所关注的UI元素基本信息(简洁就是美嘛)：
1. 控件的位置（x、y）和大小（宽度、高度）
2. 控件的类型
3. 控件的文本内容
4. 控件的基本属性（颜色、字体、对齐方式等）

例如，这是一个mockups绘制的简单按钮导出来的json数据
<img src="http://i1.tietuku.com/076111b8e0d72448.png">
**注1：mockups可以导出你选择的ui元素，也可以导出全部**
**注2：一眼看过去会感觉乱，但习惯json的语法之后，你会被它的简洁语法和强大表示能力折服的**

```
{
  "mockup": {
    "controls": {
      "control": [
        {
          "ID": "0",
          "h": "70",
          "measuredH": "27",
          "measuredW": "58",
          "properties": {
            "size": "18",
            "text": "你好"
          },
          "typeID": "Button",
          "w": "158",
          "x": "182",
          "y": "122",
          "zOrder": "0"
        }
      ]
    },
    "measuredH": "192",
    "measuredW": "340",
    "mockupH": "70",
    "mockupW": "158",
    "version": "1.0"
  }
}
```

## 4.5 运行php代码生成soui的xml文件
### 4.5.1 启动wampserver，启动服务
**服务有哪些？**
php解释器、apache服务器、mysql服务器等
**wampserver语言设置？**
右键单击任务栏图标-->language-->chinese即可
**如何启动或关闭服务？**
左键单击任务栏图标-->启动或关闭所有服务
<img src="http://i1.tietuku.com/24c98847fafb2df8.png">
### 4.5.2 根据需要修改php代码
用文本编辑器打开soui.php,修改最后一行代码，指定json文件名和要生成的xml文件名

```
//读取mockups导出的json数据,生成soui需要的xml文件
mockups_to_soui_xml('login.json', 'login.xml');
```

注1：这个php文件是**utf8**编码的，所以如果浏览器运行有乱码，请设置浏览器的编码为UTF8
注2：我为了省事，把php代码直接放在wampserver的www目录下
注3：同样的，json文件也放在www目录下，各位按照自己的意愿修改路径即可
注4：php代码写的比较乱，我也是现学现卖的，有php大神愿意给重构下更好，热烈欢迎（改完后记得给同志们回馈下啊）
<img src="http://i1.tietuku.com/24c98847fafb2df8.png">
### 4.5.3 打开浏览器运行php代码
浏览器地址栏输入：[localhost/soui.php][2]，然后回车。运行完毕之后，会在www目录下生成我们需要的xml文件
**注：这个xml文件没有使用soui的样式class、没有皮肤skin，控件都是绝对定位(pos、width、height）**

下面是生成的xml片段，比较ugly

```
<?xml version="1.0" encoding="UTF-8"?>
<SOUI width="905" height="589" translucent="0" alpha="255" resizable="0">
  <root cache="1" skin="_skin.sys.wnd.bkgnd">
    <text pos="60,40" width="49" height="21" enable="1" font="face:宋体" ncSkin="_skin.sys.border" name="Label7" margin-x="1" margin-y="1">用户名</text>
    <edit pos="118,37" width="204" height="27" enable="1" font="face:宋体" ncSkin="_skin.sys.border" name="edit_user" test="中文测试" margin-x="1" margin-y="1"/>
    <text pos="60,82" width="49" height="21" enable="1" font="face:宋体" ncSkin="_skin.sys.border" name="Label10" margin-x="1" margin-y="1">密码</text>
    <edit pos="118,82" width="204" height="27" enable="1" font="face:宋体" ncSkin="_skin.sys.border" name="TextInput11" margin-x="1" margin-y="1"/>
    <button pos="40,127" width="124" height="55" enable="1" font="face:宋体" ncSkin="_skin.sys.border" name="Button12" margin-x="1" margin-y="1">'有引号的汉字'</button>
    <button pos="180,133" width="115" height="30" enable="1" font="face:宋体" ncSkin="_skin.sys.border" name="Button13" margin-x="1" margin-y="1">注册</button>
  </root>
</SOUI>

```

## 4.6 测试xml文件
大家自行发挥吧，把xml文件注册到soui的uires.idx即可

# 五 自定义属性
## 5.1 问题
可能有的童鞋就说了，mockups控件自带的信息太少了。嗯，这是事实，我不否认，那么还有缺少哪些信息呢？

1. mockups的控件只有id号，没有name
**注：soui推荐使用name，而不是id，id容易冲突，查找效率也不高**
2. 组合框(combobox)无法指定下拉内容
<img src="http://i3.tietuku.com/e64af9633dce4e96.png">
<img src="http://i3.tietuku.com/b21bcf62a3b3ed2c.png">
3. mockups的树型控件(Tree)无法指定子节点数据
mockups的Tree内置数据对soui来说无甚大用，难以解析
<img src="http://i3.tietuku.com/838c1b9df719e8f7.png">
4. 其它更多
想到了再加，嘿嘿~~

## 5.2 解决办法
解决办法有么有，当然有！！！mockups提供了叫做**“custom properties”**功能，可以通过字符串的形式给控件指定额外的属性（真是业界良心啊!!!）

mockups中右键点击ui元素，弹出菜单，选择“custom properties”
<img src="http://i3.tietuku.com/d554638169fa5a92.png">
然后会弹出一个对话框，指定自定义属性，可以是任意数据，内部是以字符串的形式保存，这就给了我们无限扩展的能力。
<img src="http://i3.tietuku.com/c10094f79df64653.png">
*注：**custom control ID**这一项无所谓，随便填个名字即可，我的php代码忽略该ID，重点关注的是**custom control data**的内容*

那么，**custom control data**的该填什么内容呢？这里我仍然使用强大的json，传递一个json字符串进去（json就相当于一个大词典，可以放任何数据）
***注：不会json？看着头晕？那你也太out了，赶紧充电去吧~***

# 六 其它问题
有的童鞋可能就说了，你只考虑简单的**非容器类控件**，那容器类控件（比如treectrl、window、splitpanel等）呢？

### 1. soui容器类控件目前实现了3个
（1）tabctrl是用mockups的TabBar转换得到的，生成的xml文件&lt;tabctrl&gt;标签也包含了&lt;page&gt;子标签，但里面没有具体内容；&lt;page&gt;的标题通过英文逗号分隔
```
杀毒, 体检, 更新, Four
```
（2）listctrl是用mockups的DataGrid转换得到的，listctrl的标题栏通过DataGrid文本值的第一行解析得到（这个文本值字符串用英文的逗号分隔）
**注：soui的listctrl不支持在xml里定义数据，所以第2行之后的数据都会被忽略**
```
名称,学号,性别,成绩
张三,01,男,80.7
李四,02,男,88.7
```
（3）listbox是用mockups的List转换得到的，listbox里的item通过List的文本值转换得到（文本值字符串用换行分隔）
```
Item One
Item Two
Item Three
```
### 2. &lt;window&gt;、&lt;group&gt;、&lt;splitpanel&gt;这类容器控件怎么处理？
其实变通的方法很简单：
```
新建一个mockups项目，然后把生成的xml文件简单编辑处理下，用soui的<include>标签括起来不就完事了嘛~~~

```

后续如果可能的话，我的php代码能够直接支持子窗口那就更美好了，当然了，大神们要给力啊~~~

# 七 下一步的改进方向
首先，希望各路大神都能参与进来，携手把soui做好做精，*不能仅仅停留在自己用用就行了的阶段*~

 1. 完善更多的mockups控件向soui控件的转化
 2. 支持在mockups中指定更多的数据（比如样式、皮肤等）
 3. 重构php代码，希望代码能更规范、更模块化，这样大神们参与进来更方便
 4. 生成的xml文件不适合人类阅读和修改，下一步想将一些通用的属性提取成soui的样式class和皮肤skin

最后欢迎拍砖，轻点哈，写代码写文档不容易啊（前期考察UI设计器时间N天，构思和写php代码2天，markdown写文档1天）~~


  [1]: http://www.cnblogs.com/setoutsoft/
  [2]: http://localhost/soui.php