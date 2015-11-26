<?xml version="1.0" encoding="UTF-8"?>
<Form xmlVersion="20141222" releaseVersion="8.0.0">
<TableDataMap>
<TableData name="ds2" class="com.fr.data.impl.DBTableData">
<Parameters/>
<Attributes maxMemRowCount="-1"/>
<Connection class="com.fr.data.impl.NameDatabaseConnection">
<DatabaseName>
<![CDATA[FRDemo]]></DatabaseName>
</Connection>
<Query>
<![CDATA[SELECT * FROM `map_柜台信息` ]]></Query>
</TableData>
<TableData name="ds1" class="com.fr.data.impl.DBTableData">
<Parameters/>
<Attributes maxMemRowCount="-1"/>
<Connection class="com.fr.data.impl.NameDatabaseConnection">
<DatabaseName>
<![CDATA[FRDemo]]></DatabaseName>
</Connection>
<Query>
<![CDATA[SELECT * FROM map_柜台信息 where 柜台号='${p}']]></Query>
</TableData>
<TableData name="ds3" class="com.fr.data.impl.DBTableData">
<Parameters/>
<Attributes maxMemRowCount="-1"/>
<Connection class="com.fr.data.impl.NameDatabaseConnection">
<DatabaseName>
<![CDATA[FRDemo]]></DatabaseName>
</Connection>
<Query>
<![CDATA[SELECT * FROM `柜台sale` where 柜台号='${p}']]></Query>
</TableData>
</TableDataMap>
<Layout class="com.fr.form.ui.container.WBorderLayout">
<WidgetName name="form"/>
<WidgetAttr>
<PrivilegeControl/>
</WidgetAttr>
<Margin top="0" left="0" bottom="0" right="0"/>
<Border>
<border style="0" color="-723724" type="0" borderStyle="0"/>
<WidgetTitle>
<O>
<![CDATA[新建标题]]></O>
<FRFont name="SimSun" style="0" size="72"/>
<Position pos="0"/>
</WidgetTitle>
<Alpha alpha="1.0"/>
</Border>
<LCAttr vgap="0" hgap="0" compInterval="0"/>
<Center class="com.fr.form.ui.container.WFitLayout">
<WidgetName name="body"/>
<WidgetAttr>
<PrivilegeControl/>
</WidgetAttr>
<Margin top="1" left="1" bottom="1" right="1"/>
<Border>
<border style="0" color="-723724" type="0" borderStyle="0"/>
<WidgetTitle>
<O>
<![CDATA[新建标题]]></O>
<FRFont name="SimSun" style="0" size="72"/>
<Position pos="0"/>
</WidgetTitle>
<Alpha alpha="1.0"/>
</Border>
<LCAttr vgap="0" hgap="0" compInterval="0"/>
<Widget class="com.fr.form.ui.container.WAbsoluteLayout$BoundsWidget">
<InnerWidget class="com.fr.form.ui.container.WTitleLayout">
<WidgetName name="report0"/>
<WidgetAttr>
<PrivilegeControl/>
</WidgetAttr>
<Margin top="0" left="0" bottom="0" right="0"/>
<Border>
<border style="0" color="-723724" type="0" borderStyle="0"/>
<WidgetTitle>
<O>
<![CDATA[新建标题]]></O>
<FRFont name="SimSun" style="0" size="72"/>
<Position pos="0"/>
</WidgetTitle>
<Alpha alpha="1.0"/>
</Border>
<LCAttr vgap="0" hgap="0" compInterval="0"/>
<Widget class="com.fr.form.ui.container.WAbsoluteLayout$BoundsWidget">
<InnerWidget class="com.fr.form.ui.ElementCaseEditor">
<WidgetName name="report0"/>
<WidgetAttr>
<PrivilegeControl/>
</WidgetAttr>
<Margin top="1" left="1" bottom="1" right="1"/>
<Border>
<border style="0" color="-723724" type="0" borderStyle="0"/>
<WidgetTitle>
<O>
<![CDATA[新建标题]]></O>
<FRFont name="SimSun" style="0" size="72"/>
<Position pos="0"/>
</WidgetTitle>
<Alpha alpha="1.0"/>
</Border>
<FormElementCase>
<ReportPageAttr>
<HR/>
<FR/>
<HC/>
<FC/>
</ReportPageAttr>
<ColumnPrivilegeControl/>
<RowPrivilegeControl/>
<RowHeight defaultValue="723900">
<![CDATA[1943100,723900,723900,723900,723900,723900,723900,723900,723900,723900,723900,723900,723900,723900,723900,723900,723900,723900,4152900,723900]]></RowHeight>
<ColumnWidth defaultValue="2743200">
<![CDATA[9791700,11315700,2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200]]></ColumnWidth>
<CellElementList>
<C c="0" r="0" cs="2" s="0">
<O>
<![CDATA[人民商场服装柜台分布]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="1" cs="2" rs="18" s="1">
<O t="CC">
<LayoutAttr selectedIndex="0"/>
<Chart name="Default">
<Chart class="com.fr.chart.chartattr.Chart" options="{}" customChartID="" wrapperName="FineChart" requiredJS="" chartImagePath="">
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="0" isRoundBorder="false"/>
<newColor borderColor="-6908266"/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<ChartAttr isJSDraw="true" isStyleGlobal="false"/>
<Title>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="0" isRoundBorder="false"/>
<newColor borderColor="-6908266"/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<O>
<![CDATA[]]></O>
<TextAttr>
<Attr alignText="0">
<FRFont name="微软雅黑" style="1" size="128" foreground="-8355712"/>
</Attr>
</TextAttr>
<TitleVisible value="false" position="0"/>
</Title>
<Plot class="com.fr.chart.chartattr.MapPlot">
<MapPlot>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="0" isRoundBorder="false"/>
<newColor/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr isNullValueBreak="true" autoRefreshPerSecond="-1" seriesDragEnable="false" plotStyle="0" combinedSize="50.0"/>
<newHotTooltipStyle>
<AttrContents>
<Attr showLine="false" position="1" isWhiteBackground="true" isShowMutiSeries="false" seriesLabel="${SERIES}${BR}${CATEGORY}${BR}${VALUE}"/>
<Format class="com.fr.base.CoreDecimalFormat">
<![CDATA[#.##]]></Format>
<PercentFormat>
<Format class="com.fr.base.CoreDecimalFormat">
<![CDATA[#0.##%]]></Format>
</PercentFormat>
</AttrContents>
</newHotTooltipStyle>
<ConditionCollection>
<DefaultAttr class="com.fr.chart.chartglyph.ConditionAttr">
<ConditionAttr name=""/>
</DefaultAttr>
</ConditionCollection>
<Legend>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="0" isRoundBorder="false"/>
<newColor borderColor="-6908266"/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr position="4" visible="true"/>
<FRFont name="SimSun" style="0" size="72"/>
</Legend>
<DataSheet>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="1" isRoundBorder="false"/>
<newColor borderColor="-16777216"/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr isVisible="false"/>
</DataSheet>
<NameJavaScriptGroup>
<NameJavaScript name="网络报表2">
<JavaScript class="com.fr.js.ReportletHyperlink">
<JavaScript class="com.fr.js.ReportletHyperlink">
<Parameters>
<Parameter>
<Attributes name="p"/>
<O t="Formula" class="Formula">
<Attributes>
<![CDATA[=AREA_NAME]]></Attributes>
</O>
</Parameter>
</Parameters>
<TargetFrame>
<![CDATA[_self]]></TargetFrame>
<Features width="600" height="400"/>
<ReportletName>
<![CDATA[/demo/map/Form4.frm]]></ReportletName>
</JavaScript>
</JavaScript>
</NameJavaScript>
</NameJavaScriptGroup>
<newPlotFillStyle>
<AttrFillStyle>
<AFStyle colorStyle="0"/>
<FillStyleName fillStyleName=""/>
</AttrFillStyle>
</newPlotFillStyle>
<newattr201212 mapName="商场" isSvgMap="false" mapType="Map_Normal" isHeatMap="true" heatIndex="0"/>
<MapHotAreaColor>
<MC_Attr minValue="0.0" maxValue="0.0" useType="0" areaNumber="5" mainColor="-14374913"/>
<ColorList>
<AreaColor>
<AC_Attr minValue="=0.0" maxValue="=0.0" color="-14374913"/>
</AreaColor>
<AreaColor>
<AC_Attr minValue="=0.0" maxValue="=0.0" color="-11486721"/>
</AreaColor>
<AreaColor>
<AC_Attr minValue="=0.0" maxValue="=0.0" color="-8598785"/>
</AreaColor>
<AreaColor>
<AC_Attr minValue="=0.0" maxValue="=0.0" color="-5776129"/>
</AreaColor>
<AreaColor>
<AC_Attr minValue="=0.0" maxValue="=0.0" color="-2888193"/>
</AreaColor>
</ColorList>
</MapHotAreaColor>
<BubblePlot>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="0" isRoundBorder="false"/>
<newColor/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr isNullValueBreak="true" autoRefreshPerSecond="0" seriesDragEnable="false" plotStyle="0" combinedSize="50.0"/>
<newHotTooltipStyle>
<AttrContents>
<Attr showLine="false" position="1" isWhiteBackground="true" isShowMutiSeries="false" seriesLabel="${VALUE}"/>
<Format class="com.fr.base.CoreDecimalFormat">
<![CDATA[#.##]]></Format>
<PercentFormat>
<Format class="com.fr.base.CoreDecimalFormat">
<![CDATA[#0.##%]]></Format>
</PercentFormat>
</AttrContents>
</newHotTooltipStyle>
<ConditionCollection>
<DefaultAttr class="com.fr.chart.chartglyph.ConditionAttr">
<ConditionAttr name=""/>
</DefaultAttr>
</ConditionCollection>
<Legend>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="0" isRoundBorder="false"/>
<newColor borderColor="-6908266"/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr position="4" visible="true"/>
<FRFont name="SimSun" style="0" size="72"/>
</Legend>
<DataSheet>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="1" isRoundBorder="false"/>
<newColor borderColor="-16777216"/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr isVisible="false"/>
</DataSheet>
<newPlotFillStyle>
<AttrFillStyle>
<AFStyle colorStyle="0"/>
<FillStyleName fillStyleName=""/>
</AttrFillStyle>
</newPlotFillStyle>
<RectanglePlotAttr interactiveAxisTooltip="false"/>
<xAxis>
<ValueAxis class="com.fr.chart.chartattr.ValueAxis">
<ValueAxisAttr201108 alignZeroValue="false"/>
<newAxisAttr isShowAxisLabel="true"/>
<AxisLineStyle AxisStyle="1" MainGridStyle="1"/>
<newLineColor mainGridColor="-4144960" lineColor="-5197648"/>
<AxisPosition value="3"/>
<TickLine201106 type="2" secType="0"/>
<ArrowShow arrowShow="false"/>
<TextAttr>
<Attr alignText="0"/>
</TextAttr>
<AxisLabelCount value="=0"/>
<AxisRange/>
<AxisUnit201106 isCustomMainUnit="false" isCustomSecUnit="false" mainUnit="=0" secUnit="=0"/>
<ZoomAxisAttr isZoom="false"/>
<axisReversed axisReversed="false"/>
</ValueAxis>
</xAxis>
<yAxis>
<ValueAxis class="com.fr.chart.chartattr.ValueAxis">
<ValueAxisAttr201108 alignZeroValue="false"/>
<newAxisAttr isShowAxisLabel="true"/>
<AxisLineStyle AxisStyle="1" MainGridStyle="1"/>
<newLineColor mainGridColor="-4144960" lineColor="-5197648"/>
<AxisPosition value="2"/>
<TickLine201106 type="2" secType="0"/>
<ArrowShow arrowShow="false"/>
<TextAttr>
<Attr alignText="0"/>
</TextAttr>
<AxisLabelCount value="=0"/>
<AxisRange/>
<AxisUnit201106 isCustomMainUnit="false" isCustomSecUnit="false" mainUnit="=0" secUnit="=0"/>
<ZoomAxisAttr isZoom="false"/>
<axisReversed axisReversed="false"/>
</ValueAxis>
</yAxis>
<BubblePlotAttr bubbleSize="50.0" bubbleType="1" isNegative="true"/>
</BubblePlot>
<Plot>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="0" isRoundBorder="false"/>
<newColor/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr isNullValueBreak="true" autoRefreshPerSecond="0" seriesDragEnable="false" plotStyle="0" combinedSize="50.0"/>
<newHotTooltipStyle>
<AttrContents>
<Attr showLine="false" position="1" isWhiteBackground="true" isShowMutiSeries="false" seriesLabel="${VALUE}"/>
<Format class="com.fr.base.CoreDecimalFormat">
<![CDATA[#.##]]></Format>
<PercentFormat>
<Format class="com.fr.base.CoreDecimalFormat">
<![CDATA[#0.##%]]></Format>
</PercentFormat>
</AttrContents>
</newHotTooltipStyle>
<ConditionCollection>
<DefaultAttr class="com.fr.chart.chartglyph.ConditionAttr">
<ConditionAttr name=""/>
</DefaultAttr>
</ConditionCollection>
<Legend>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="0" isRoundBorder="false"/>
<newColor borderColor="-6908266"/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr position="4" visible="true"/>
<FRFont name="SimSun" style="0" size="72"/>
</Legend>
<DataSheet>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="1" isRoundBorder="false"/>
<newColor borderColor="-16777216"/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr isVisible="false"/>
</DataSheet>
<newPlotFillStyle>
<AttrFillStyle>
<AFStyle colorStyle="0"/>
<FillStyleName fillStyleName=""/>
</AttrFillStyle>
</newPlotFillStyle>
<PieAttr subType="1" smallPercent="0.05"/>
</Plot>
<CategoryPlot>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="0" isRoundBorder="false"/>
<newColor/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr isNullValueBreak="true" autoRefreshPerSecond="0" seriesDragEnable="false" plotStyle="0" combinedSize="50.0"/>
<newHotTooltipStyle>
<AttrContents>
<Attr showLine="false" position="1" isWhiteBackground="true" isShowMutiSeries="false" seriesLabel="${VALUE}"/>
<Format class="com.fr.base.CoreDecimalFormat">
<![CDATA[#.##]]></Format>
<PercentFormat>
<Format class="com.fr.base.CoreDecimalFormat">
<![CDATA[#0.##%]]></Format>
</PercentFormat>
</AttrContents>
</newHotTooltipStyle>
<ConditionCollection>
<DefaultAttr class="com.fr.chart.chartglyph.ConditionAttr">
<ConditionAttr name=""/>
</DefaultAttr>
</ConditionCollection>
<Legend>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="0" isRoundBorder="false"/>
<newColor borderColor="-6908266"/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr position="4" visible="true"/>
<FRFont name="SimSun" style="0" size="72"/>
</Legend>
<DataSheet>
<GI>
<AttrBackground>
<Background name="NullBackground"/>
</AttrBackground>
<AttrBorder>
<Attr lineStyle="1" isRoundBorder="false"/>
<newColor borderColor="-16777216"/>
</AttrBorder>
<AttrAlpha>
<Attr alpha="1.0"/>
</AttrAlpha>
</GI>
<Attr isVisible="false"/>
</DataSheet>
<newPlotFillStyle>
<AttrFillStyle>
<AFStyle colorStyle="0"/>
<FillStyleName fillStyleName=""/>
</AttrFillStyle>
</newPlotFillStyle>
<RectanglePlotAttr interactiveAxisTooltip="false"/>
<xAxis>
<CategoryAxis class="com.fr.chart.chartattr.CategoryAxis">
<newAxisAttr isShowAxisLabel="true"/>
<AxisLineStyle AxisStyle="1" MainGridStyle="0"/>
<newLineColor mainGridColor="-4144960" lineColor="-5197648"/>
<AxisPosition value="3"/>
<TickLine201106 type="2" secType="0"/>
<ArrowShow arrowShow="false"/>
<TextAttr>
<Attr alignText="0"/>
</TextAttr>
<AxisLabelCount value="=0"/>
<AxisRange/>
<AxisUnit201106 isCustomMainUnit="false" isCustomSecUnit="false" mainUnit="=0" secUnit="=0"/>
<ZoomAxisAttr isZoom="false"/>
<axisReversed axisReversed="false"/>
</CategoryAxis>
</xAxis>
<yAxis>
<ValueAxis class="com.fr.chart.chartattr.ValueAxis">
<ValueAxisAttr201108 alignZeroValue="false"/>
<newAxisAttr isShowAxisLabel="true"/>
<AxisLineStyle AxisStyle="1" MainGridStyle="1"/>
<newLineColor mainGridColor="-4144960" lineColor="-5197648"/>
<AxisPosition value="2"/>
<TickLine201106 type="2" secType="0"/>
<ArrowShow arrowShow="false"/>
<TextAttr>
<Attr alignText="0"/>
</TextAttr>
<AxisLabelCount value="=0"/>
<AxisRange/>
<AxisUnit201106 isCustomMainUnit="false" isCustomSecUnit="false" mainUnit="=0" secUnit="=0"/>
<ZoomAxisAttr isZoom="false"/>
<axisReversed axisReversed="false"/>
</ValueAxis>
</yAxis>
<secondAxis>
<ValueAxis class="com.fr.chart.chartattr.ValueAxis">
<ValueAxisAttr201108 alignZeroValue="false"/>
<newAxisAttr isShowAxisLabel="true"/>
<AxisLineStyle AxisStyle="1" MainGridStyle="1"/>
<newLineColor mainGridColor="-4144960" lineColor="-5197648"/>
<AxisPosition value="4"/>
<TickLine201106 type="2" secType="0"/>
<ArrowShow arrowShow="false"/>
<TextAttr>
<Attr alignText="0"/>
</TextAttr>
<AxisLabelCount value="=0"/>
<AxisRange/>
<AxisUnit201106 isCustomMainUnit="false" isCustomSecUnit="false" mainUnit="=0" secUnit="=0"/>
<ZoomAxisAttr isZoom="false"/>
<axisReversed axisReversed="false"/>
</ValueAxis>
</secondAxis>
<CateAttr isStacked="false"/>
<BarAttr isHorizontal="false" overlap="-0.25" interval="1.0"/>
<Bar2DAttr isSimulation3D="false"/>
</CategoryPlot>
</MapPlot>
</Plot>
<ChartDefinition>
<MapSingleLayerTableDefinition>
<Top topCate="-1" topValue="-1" isDiscardOtherCate="false" isDiscardOtherSeries="false" isDiscardNullCate="false" isDiscardNullSeries="false"/>
<TableData class="com.fr.data.impl.NameTableData">
<Name>
<![CDATA[ds2]]></Name>
</TableData>
<AreaName areaName="柜台号"/>
<DefinitionList>
<SeriesDefinition>
<SeriesName>
<O>
<![CDATA[面积]]></O>
</SeriesName>
<SeriesValue>
<O>
<![CDATA[柜位面积]]></O>
</SeriesValue>
</SeriesDefinition>
</DefinitionList>
</MapSingleLayerTableDefinition>
</ChartDefinition>
</Chart>
</Chart>
</O>
<PrivilegeControl/>
<Expand/>
</C>
</CellElementList>
<ReportAttrSet>
<ReportSettings headerHeight="0" footerHeight="0">
<PaperSetting/>
</ReportSettings>
</ReportAttrSet>
</FormElementCase>
<StyleList>
<Style imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="96" foreground="-16749643"/>
<Background name="ColorBackground" color="-2953990"/>
<Border>
<Top color="-1446671"/>
<Bottom style="1" color="-1446671"/>
<Left color="-1446671"/>
<Right color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="SimSun" style="1" size="72"/>
<Background name="NullBackground"/>
<Border>
<Top style="1" color="-1446671"/>
<Bottom style="1" color="-1446671"/>
<Left style="1" color="-1446671"/>
<Right style="1" color="-1446671"/>
</Border>
</Style>
</StyleList>
<showToolbar showtoolbar="false"/>
<IM>
<![CDATA[KY)@l<*SuQCk.$YLe&p?;UQjs.O?\&h;'qU-jW@fQ[jTC82JHidP,ceG761@d(G!W^%_9@p\
b>0p=XerB@X?>hC%N>SA_1XcQD#SF6A\HHVqaDGO@!:\T;s(r>tM9BhcgX4*NmFOVE5Eloqh
@Au>:WW\sk9_^E+aq>Q0(8\!%U5-XYo]ApP`HDVI<Ugi<b>qfd)e;4FQE;`R#ol!r.kOk\>M3
6Is_Tc@/gD0R@YKabo^>sB(n<ESW&j3<?1DZHoF[Q`X[@.d@`1)tpN!1fT1'a=OWr)8tH@3U
_MPNQG?:M3D]AAXH<$\,&GTa9VR+'<#\q03H=nO:N[76&&+*Pm`@;I"+Vhh'[)PAgNKa\iLna
j2'(Yg-?BJh=n%]A]A6;T6)cQPUJ7<EaHVI4*_7\K;=,Lb:28:KaJbtG&QX?1Djl`be[IZT-^T
tl9a\(1<LFZ'`I"L7d*MO'ak9+\!oH,fa$pJ1CYTcc"pqb33;iZ7Yl6hAm?XJVS]APT#h(OBE
^c`E0\4`?s!HLA\?qZ@"ld@k6gAeHS\&0$=363C-lCc.>1$'V]AY>OindctIRHf*1&3,=dV(5
lqM./0cG2f4?/p6-=gJi<;8A+q<)1\R_6/j^2FbRZKc55Q:N``30u,iAhCrL[[h=TOJNfWgD
s/qlY6"qR!eL'DFM\qn><#8E79mggi(o"6kk&&Dj/Yh[+d,6#iq<U`TN8,]AF=>pVjniHLW*M
+K&`rT0RV6>oi_C'Fj\IaR=Ctm_P%7+;MtTK)G67+BENWHcY`dH[koP&]AYdneDs1(pciENo$
t:YK`?JZ1/-="bk"L"^EVlU-c&DnnCru6aa6gL]As)JL<eJgCC[P=aN+Zi3hHMmY:]AFSh>',a
EmW"V3?-)s#p,-jdBkNm,cQfr-cWn?Cq6X]AIpqN"2-F*UWJt>*MnCPQ<D]AtmWUU@#76tg\X%
7>[m$jY$l\un@6IkVI%?+\`AD4G*f$guRI8q8u?cU6.,]AKuA#7,,`hiuQcfW-Q_^d;CmoFVf
/u@dSc@[Pdh2b5iDAdI/W6mp\?Ek+jG3+-IGF_HB'<hBsstLn<H![YanmMS9rZbYSFP\B!DA
iYaO"qEfKu%dW_%2hFH'iTtllaUt7,P:X9(s.YqCp^p3;GEsY^A\kJ]AgNcs/KX&o)j3&$9rp
h>H:-.Y<;NEpH`0\O4rRFB!!JL0p9Hfur_#8=BYpfFYkO[n#phBsqLT]ALf]Ac-IV$>iEubJN6
NWc:5&$*UNeL(KMQ<]A!4Nm1>kt1ApZOFJP=XgkFJg1qn*W/\'oEj`j'J3>4B>G6&K_+)KkQ]A
p1O:4nE+X!Z$h7-[N/jf8L#5Oh+4hNIrF4IKZ(XAIBfSH#L:pa/!%rk`ImY6XF$a\+SJ?%_&
)ts2'UF4MM>9(KRbc%d%Cu[dB6=R5&H'3&ooE8[+:_P&Y6SEtS/<:mUY]Al[NH$3_S?O!nMR;
j'gT,DDmV^*>-K$c4<:XYPL\\8M$mc.O2Ror\90'Cac"DrPeGna50sN;R&<]A-rNC32[?'Do+
gpYU)XH`f1b@1V7%Eu9<OSHE;nC>D%_b+R<qY"2ZF/Z0HeRbp$";Wa/-'0fjBem9u:h8q5]A1
h^Wi5B*t/*jp-7Bt+7F`S"anh1%7'q0:Cd9Z4W3Y]AlXdSUB)8-Xq<@epJfOaaJ,7j5reeYi2
Rr_+8,l_\\@G#[s6Q0iJTC(U:L=%SUg$_bLM^]A5ld?a5lTrp#aJ]Ag'USg!jk3td/jE;/SU!j
eUESpl1/`gfgXRUJQ%@dB-0=N\/`F"8/s"=d`6LZLlMN@f*<$CD*o/iZ(aZl9pha.[/4ThTe
k:^dMbogVBs+ApJ@+!u'=lt4</.nc)_"i0n+[;V4]A)Mfj]A6;A'iVt:ps*oT?4='G52SUU:OH
h5TN7m`lW89jj?pROs#l;:cq3OtVhq'p_:5%0:m/$]A3]AbfuQA[_$S`*WY0K+s:D40c)j:oc+
chiQRlT9900H=jtk^WXR[$^1[mhYa.&F2.aYSYEbs:>"D@ni5meCiiphIe2.k78Y#^HN#i(W
nM'"Hc+=f'8"($J"sH^hT`VVq0@/-DTbjXQ9O;Xk98Hr_sFA.R@U,p79T.FVWL=kqf^.UC4q
_HC;"?V,k`/f[@*h?J/.am+kP)"Oa[mL?#b>BgPM%UkO\%6n]AZ+8Oe<=S7\`QCqB5V+4d<Cr
1Ljt(%+8HapNs1(s!.L5K9begTnTNLraa;6;ed0MWK8NRa\%jO%IAB*4u*g\nk4TjbZe#7;g
I+=GHk'j@Z)(2eseTH6Tm5F_.<i6aF\ctX^h*51>S2q+27`;oGJ$Xs3#L@Cs(\*5GnA%pL[-
W5c(ls)I$*>5#apA"]Ai5lTVEUF%'(iM)fEe]A$]Ad*8KZcee$?ZF96l[0?^1IkXkmiltFE>oHQ
/F3+<!mkr+mneq/sPPV:Oh&B^Sbl6;bgR:XiT9[h4u,6S40U*l'2!5Y4juFlqWg/#N<26^bb
_Nc($u<L9g(cioJS`.!Zsedu4T]A`5@W.+IA=8J^\C.pC!ebs2:A-T0i"V@/Z=8o(cbu.TN'\
IJ#4^KA.opTPB<2a'!/A0aQV]A;hWG/lkePF0K.9(keT]A'd?!"5CBEon'@WkZnkAlCO/^Jm,"
NhNp#JrV?Qh"g'Q*ou6-h;U/K&a'ckj(F?8TQ$]A1S!qiXI*a.#C]A"d[Vp,9/;+g)_S<JHXYg
m/0?H$3C8RpbP0Fj-ca,Mkus9.k`Yimg"RX=Va2`U2JLZJ,*3bXoeEl$6s/]Aj]Af!R.Le6/t\
^.H\=t'3%[)_L9^C:##$mjB#nAS?06ZQ61[TR=qi\O21gqi3bf'?FdV7)mH-Yp!0["Alnq?3
*&V(AMpa363HHmH<tE8ED!Rb>ume;u&Nr!cXiigsZTkuc+>G2B'u#H)%Pdd-S4PkK4)@(*"+
\l<@3H).6_<+^9>DL,F7j^c;3X>#5bn\_f!AlR;N'rUqRS_^^Br7SJO,)[i\.0:Wr$1VGGG8
;mK)4"E2"oA3CBLXc_P3/JlgE^9(K:#>7.@LPYDbH^-\3<HLm:@g_VB'ct155.*rW`*LggB"
uJ<B"gG0`T;H+N.62kNU\PHG4*)RMr*0B<V]A]AaV\tFZ:2<IILIijT\&,^[P_)l_PkaM]A8Y.9
Hb@F2qB\Zq@3AU6KQV_ko@[GO_d2HIMk,Z:U8m=C?cT<8H9%D4E]A<&1pq:Uo.'RA$lf`S*Mj
.spcqe%Ea*Rm`9[We(r+F,B]AgYoLVFkV6F4L1KBq(^1F$ZF\Jsh0bEHDt/uTtSSrC2;]A.iWN
51c%f2*U/?$>F.VXC(m#0drr4"#8,LkDCshh`">*:QI;SbTj?9.>JG!'t]Ahg0+ZChdR8DmZB
$(h'g=9A06@YajLL=@^s,RNQ^nIPVa@0kZ7s+Tc*khHjgmL==;`ckHN/_h+4?HC1H&XdWKUD
#EQWko.=@Kmmo2e0C*!>c_>/F5aF=*C)QnHh9&e':Hs9Z`BbG056.0aN<=NjVVm;tX/*q)C.
Ts.TM[.SCYIR`bjDZl&_AGP92N-U=%@(E(e!Sc)RO%gT$fU#@*??PjE$r:'De?_C\R-S[dj@
X"W@3$0</I/EFWY75D,,*&h-\[r]Aj!ho4*tL*4,g]A(-#]Ao]A*4j2\5\m!PNZheVA4iGRj=tMG
4:+&b/hB?-LCrBs/-DKn2>*`XKdfe"XK8>s>RgjBH.IIb;UOl%:CpVl^C+tg6NQ$*S&\$8Q9
7UC_W]As26p'L/Ni!"nK3c.h8N:EU'Rs[K?ZEt6I4DdF<7OY8ah>r)As=N(>lodU%m>2Xli(8
R5L?)WZt-'\J((pl&ZuXr&<6Icb?61`I0[..+DkO="CaXdT?K;3EY;-!d]AjlZ@p%8d?qR3B+
#aQii!nZI2.4doh\$g&e3-?'fQg-clmP4Rpm]ArWWf"ut(,fW#J*%K3AJs-)5=g%kB4t]At%Pj
@P/ga2FIEm(_\!7Z$;KtXp),Gr;0Xj?HX2jA_pQ/A6+2e8p/3JrKf_)tB,SlchR.6aoa+l@A
h%C6o`H%70+G23>NEl*tQ]A#.=L[/]AZB:Ciq!0LT&]ABut.V5IudRA@ZjrH7!"@PbaJfW'Ps9<
a7_H=?B^ZPOQnAGl0[901`O`[Q2IF+@rT=-ELODbSa/ZKdq.S]AYgE'/[)8(2M1/AfH,A*Y4c
Kr^AO5a5KTD'*hh(gA\GH`mpF]AHAVAaL:"hnlhi5\&&/kXADQg>b/,iEfZI7X)R\;PiLCH-k
HnUbUlM<:c$&ZESL&fC)(+$^-kZ$#Ks]A\9:e.>UIIK)s)(23j0!:pIUZ*A"Gi[@B,+'jok/n
H\[_^h87O)UGZ4f_jq3hPBh#pZY'j":-RGYB+jTscic#<;2WdIrL[F*k,iAg?lR^r"U>ke,q
AdKDiIR[jX>UI<254_NN"b%NLm!*g+)c!4mo,K;K/*mdBM8Kt+csp^hqT@(;[2Hng+3d]Ap3p
',B:M!&/_qVVg1.B<ujkBVo6g?k)7Rc#D?<hVEVmbMFm.o$Q`AU%sl%5/&mh2hf$I);@&LST
)\5HHek.U3:6Yp]A-f%K=pf"K8ck(g>[l$WA1Fg7,6iJ`Ako70VN3OLW?SC2MbN%f`+HlEXFq
jjIA(@"$mP$Qr%=Lm34W`l0AjC3;1>g)e<;m2Zu9+l7i,(@D12\r>qj!jS-FIi>bqlBYo]A2r
EC[VFT@_#?::iZ;Z$U=H[=8D/3r[[/&7N)n>rUqDrPP^_S2^(#\[]Ab1(,8fqp%*8,69W9f[3
P(aANds'M(goqlTUstH,`Co!I!c2WU3)`"$Hr&o1Ud7]APe<I&6/P=V3T.$lpic@ea]A<qGR'F
N_Hkop=gDuR,^nYscod@-X.)jNj?4EOUYP@oOZ"rCg@4a@G5\+\ZD5UD:GMJ8mp^glU?r^sS
lO]AgX`IA+"(DhMUTj?OWkG==pAM,h@jW\pR;I:HT[aRN<cm0/XufVLci?i<@=d?f[0mbD(#k
*o"`A(='m[,\;k#XKR%Z8BRtn$R!37BG]AAEF?^2?RO.64E.`UmED:;3*q$g$e9AFD+CHST*h
R(kfNXEF'^KmrYXbHfk%l>X+^bWk]Ae=M6f#]AkVpF?RMq..NPhOc+XiRd"b[@10bl[`h[r]AE.
0J8R(LepHJRgqjP&('3EW"^M.rA%j+7seflc@1nUisn!<Lfkp*Ur_A_H\19L&cU1Ip!mS;KO
N;,EXjuMa7TJr_k/"$S"s-9U9?'bMCg5iC$%hN7)HbB5j"iHAK,TRSj8HP%rLM]A^[oZa6U`0
PQ!)CP.#PJ<0efhSn9K#"b4B/fZo6T.J;9fTj_QSki@Nsu@FgWlA*oPWm%J'DRurK8TcfRO@
JnY2aO-Q4Z"#sMjW]AY*LP9UY8HHgU'9Zk$96I,a'-iGqXDGh6!YpX,/sOMZN<IC=@J7X3Wf`
_fnlIQ"l,uX>?ZsI#mSV/%I9NbTY2[d]ApnZaAjRVWil,CH;oonB+<V=3%'rmH/\c-DZ;mjPu
:R=<2=h5q9+==V]AWR8'."EL=m8N!t1KYfo9<6u5Z=_qLb94SD(VO[.j%6.Ma]ADf[NU/M,_dT
!5=lB@B/FcJG*X66uB^8;AJ>P%ASF=8gX=Va+-UA3;?[6"rTY5aG/V2qe?3Dl7-e:aLTq%k?
4S)3Yn&H6g!".PNP()ibMM1p%ApjVY)L`N\9ZW)n,&sL55!B1."&5=ELJ>bo&_<,2'.YjJMY
%)+ADQ@FAh[4:47<lBO#@d\<n2i]A^[J5j..1>@OiEN)(m3iV?n/c&Oi;m.mnOu\aiZp0lcEN
l%W89&IR%Be(\g_&XH=c"YiC2MJiVCSn611>ki)KAl+'MJDHEPtce#OiP;N^/4K8]AVY>>6(Y
IJ5sr13#"u@!tQBRuFXn_c%_"c/i/>,u@rla)EmkYc5V<7Mnm<IRldLHhcQ'H+mD>3Z$Z2.d
1:]Ak\%.o-ZsdtcX6d(NJ^W*0u.8R]AQ)T"*IhSBO_H8>/hRQ:mj5-$'g_t.9fMp7eMops?U#K
cq6umNcoL";]A@R)GAUVmAQe"#Br6f>(dHkR`$jB9uV.R7U=(C>T8t%33M7jD<q);;Ici]A8tm
AN_koWWdVDHH^pWa_M'MK7lU?btl0Kf/+[8,GSIr4+VH$Q:A.lWKg)K3+;_Cb#geR0E>7HR<
9lcE5c@J3P!ch.PV(rR:KKnO]Ab?YV<\Lk-Uo:*(So)b[L?f>33drlF9lNNjYAA,YNHS;D@X7
$_9$aAPn0)oel'ROT4O[G!i,/P"=O\*$T5$M>,BJg,ZU3Q]Ad"=im#/c98qtF5T!?J[LRc;_:
bB-Z$P9GZX4DT4JU0M?n-irU<3!o6W1[$qA#d2#67TgV>i*T1UnRhVO*G1XY,0oF8X7O;k<i
d^mc#:.Y)a@N3bB[=h;:roTlJUL(:I1;dsk54;pbdA$`io$L:EeE/3[V'Z0XMb)o<Z?=pg")
_2Z-SpF(C3)cc"Q]AlB1WX_V6k%er@oA;:Fk7q7+#E6mt99MOt[s*rk$$sR\5r@mNKuAu.N;Y
25<e.XhZ5:>m$R-66MZ!Y+!d9QLiPlH/0)>Y8]AsSF(g:H3TIMWqhbeiF(+l#ioFZGsD0lS^.
\<.)C_d1B2nsauadVD$ICKQ-6)3lK?_gr>cIi$@%8N>fm)`g8l_'[2hI\RcaMB^\Of.lOgUe
,CPYJjml"h"WZ2ENa&FaCproj47%D+0FKip%&&GDsbphs0M7o&7jX^2EjkYE\-rQ<p`=_$L:
10;!@+An'oG^]A(&'luuN)FA9]AB&:i51^!6SMlUXnEHFL^A,J)kq'-Ha855F<A1:d&9nS[tuF
j3$AZa!F_Vk_ZQCCRIKJn;3@J]A_qq^=c*[-O9-c/-``Tis0`\G]Ai)j+U4G.N7M^lfG#,K_5+
YB]AE6Ic_^_+mQsQBklqI02AecTA)3lf:U&FDR]AY86JlTRsaR4kX0Q`ue:r)U_4IBcr,\"gMD
h.?4rD(s/r7?*Lr$G5.Sm>qlkHB=:k=j9M=,)^kF>2rS>C@%Bt+j94Vlm-E_>nJWZ8'l:oa]A
hkX@2`P1^FAN8VSd&UB'GP[]A0j`m3eZdVWUqEg>3V`!]AVYH;9)>L'jALf<'t,WO10-h`HXE]A
%c`%OgV:#;%5ifa7[X-]AFJ$h.fH.\\]A<,d]A09'@1&;o\'Flm:>-T'@j4Hfi@WYKtsi4\kI$8
,GRVKq@#.0s4S)i<G_)b3OG>kPM'$Qu'2Ijh&O]A+OWn8NcHSd4skko)X;r*7lmU77?g-Z_^e
5:iDMDmriLtu[FM)9b,>0NV&$BP):Vlqn_>b0H>9&_W2XK<-Nsi@V)pt9(Jijh\b@Ts4ljs7
\qo]ACCF_qKLXRL]A5o9s"f)k#L`S[7E-Cn"U>4!m-bZYlFlLT(KqS0Xf]A7t>LX7s6QEU$W%7Z
M.&XuN4^34p)`oKV1R*$[E^$_G?3Y/dh2gcEW^9-pO.=ZMq7h1Y+ib_"_$0UYcej>h^gVOD.
5*(/QE_iu+!<uE%J^3U[`nLHMUfrU%S1-``<`VaQ<7HgeFiSnCF.<Hjf`T?$!'sI-OSpBKZH
#L.RYXZ?r-MlL3^Jkk<'mOCl0\]AC=A*VImCg(e9kK`WCBmBBZj[=f5?0]AQYAE:$VGqP&A9.4
`@<)ks?]A2HHRVZUeKDIZk#mFr'W;+UMckB@H^Ip6912t>(q.mj]AW$LYd:Qd-"@gk)AMOc4H,
NgMH2g/@0,;qQNIY`Xq2bR_<PW^'C#NTt:l!YmV>5f-6U9-+*L'd6Uq4E_2XNi@'/E@dDOmt
Rmq>0UY6mI>)A(6'cPO1hU:nBc,@PEP&n?[.oQr9NrPMn7K>.K1uT\po"\!?qs(LU9(iS;26
FVUoN4e?!^i\#+IUXqS9HO=[A*g<?CcIaj*LW46ZcamfNf$l6JHURoYq<nEVe6rle"]A8*tT$
"K-p`f@IC<q*1.?O@[m;>_$YiNcbL8.X1.iMHuVd,e1A/t1iMb?Me;*Y>ZN(<LLdU\"5^&gX
h?0.I;NS=12TiSqrX;"pPk[p*\P_`:]A)S(k0U.[\"oK2/MjWr?2`gj=;8nNY8b!&(S%G)t<n
92!;K5`WO-p6t%2]As\erKcsrg'ac6K^e<uueh)oY9B1K.735.A9k(:W2VB$ISc3o4-HC'#7)
sK6q=YN\+iEoRBoOrdMRr]AVREJ#'`ko^[l5a'iVp*'lDSs;bS((T;YP6V?WgYVP9JW\3PYgC
&#Mrb79*#3@JV4IhU&e:M5$j6;&fc!F>!`[bq4+0C!u@L?r6nd):goOAl[N"8D2L0a04D5b`
q^b,ea=GTC]AhVQ&gsb&)<8DW(sutfKkUc6:iW:E3aoQjWEVDij<L$om.P*W'+('9E]A?[8QmR
p,2q:B3gW6W^=l\dfPt<X4"0ZAkNebn7/XIQLL2q[Bo=-M@&)FS;Wu$V/Wj"V:D0>O#&moi#
2Jq<\R_O&Nj4ng='@,BWg3GBFKYXHPS_Xusp+oDX,r7tkgc>nmbWTluL+?'/o.AakNFET7=8
N6SP!'ZC62K08?Lpt5Ppk!b+64cG6@-Ln12>17[6Km_8<A[uOo!b`>8MriGJ58b@3R5U;EG@
dbDX+W1Zctq29?`l^KC^)h468ViX"BS;@pI4rV]A63F^/0M"Wr_-LM$tf4FVuiD!_KTK3%meK
(V!'IP&R4fpCF_;[1J0]ApWXbm('aL1<Qd"+?aY:\TjZ:-'8.3ieu,d_J"SI;I^*5BJ'>.\>h
G"(m4PM9:(pX,.0]AfE2@o@9M-q!O%8EnKO9M(8#uV'Tr0h0KVTPX/c5l_+FXNDk,^i:onlrP
7Jbg'[(#Fg:57ar5,p9ZCY`0tY3J$]A`ZLs]Apni^Zpp&j17@%:Q-$d"0RZs[u#-0>bHs#hoer
3crHMO?.d6Fb_=^`Hpi:c)[?IYehp[R:Bn9D0.8""FDDO_)!>guVNKgWsR^TR*AJG?#CkBMs
(deW7aqE8fMa+c&a5@a43%jc#Ni9A.0*!td'l&>V6;e*,F\AomMWC+du1`ghtZGu%`^dPV`/
7FZ77/?!-4cHQW8n!iA1kj*+/2IE,>Zb6SA5;<Ig2_^r&)pml2>?NjI"JuOjgsYpV+bZbh+I
R^Ci&O]Adq,Ql22866]AFOGN]AZC&5OVY7[9(gM%M@Udk8t%d5>-#U3S/E\+O'`m*#$\<GjeCc@
e<QU+pjfN]Am2.H]AaWFLa*t,s.(Ns_[B<FZanr[n0X$%7kDcE_:SJq@t`pCTg)lmQ;p9NgcL5
(G:F$>,X]A^^RCTef&&K<=Me#>mRJKa4Pjc=`9HPODZDF&id*+.enQ(tBX8+0J^)kCnNmN#^,
`\Zh^98@9#9am8b3$Z"Uio`ctU1QqadJsX)(WI=&U=l0TTL**k`$-)GkEK&YNF[-%-lM&(f;
g=i@=H>6p#</qj(8sZDh>M+@P%MriMsGCK/;:M(!\b(6GETAOQ/I2\qpq\H.JeG$W)+mj8eT
-ud!)Bdr(fF:@c)OEr=T=C8f4kA@oXBaXeSUGq/<iNC!H6J#s%!>4A%#je"&R'VugU+g#7Y5
DT,(@bB@]A3(b6c.:H=RNFah%jq\/]AW4k5YN`DgA(]AKN+T,i+j"*`,'ZBVfk&'#W/hOIb1i-<
eot%$`+b6)L"_2c>7$!,HuY3[J'KGfW>2X)\,mRs?Di4D=C%a=PDeVfm_:;&[sMPAh;!K8D7
NG%S#u""teiRftqMr`DsCe/UR*p4>*36n;j)bfWZ+eNq0mW+06;lgDb@'-h`@R+57lLQCX[B
;?:1fh-"uabuX2gCS&qnp@k<cl1oE=HG]ALc*&6dNZ8q9)ks($F\!K2;0uERijn`hXs?WAqAG
2<fI!s1<>HYJi35?-0XI8RY[dC^1/I8lJp\q]AnUkW2`+4Q'3fWjB?X;Q[9LF$>#=COuKkU#"
#Eu2Y!eC/s*'ClnG-C`'I-UUd(!AE%be[58r3W>uB7uD$R8b:,efJ/d/*0f`U5i$kl+5-A1[
u.dH--\r;]A;j$HPTV`YkPG?1.o<Eg/X6D&F6ug^kg=AIR#C#@GCaPY+t34XJdP$%ju7!2Bjl
teO82('7p`F*ta]AI5^\eh[-Us@KZYf<dQTPlhq2ZGI.E5m#uuZg7l*$)ZK=u)B;B(H[,b2:G
G\->V72YDSYWYY([0a)$*ibXe`;*]AF&^06J#$F$Im7q;.cA+<:B^Pd<Opt.]A%AU8&L[HA&(a
4uL@.47$$0)fI\)p:"FIe3qPt9ge*f;AT:@qKk5+T+cjCg<-H"NEIqD;Q"HB$/JrHQMX1R3-
YBNd([d#[d*"b<,+Q_l23g\7rWi_k`BL^GEdu3pegHma:cCCkdr/*Jk3d6.t\ofi"$DdtH>(
fI1>S/M+#W"Pj:ZhJ+Vi8R]A+Q/jX9+1b>:8X<>g%IDk(E%rTNuC/&m,C*SkM.YPQ`U+L'ZN:
EUoH]AY-Xl3H"kOs*UIK7YZiNF3OM5_=mX2[I]AehEh1FGn-rB>EIO%]AoKe8fK[,U_nNL/PY_:
)6ND)&GuEH,k,#OfsYc6DM)Zb,l1th<Koul7(=h5nUQ-nG>E;59O[8Za;CSYZ3`ITC.!YH`Q
@h[R-BS!7J=?8t1h[pi3U83kg5gB2\ISDO;&0CEGnC(aeQr`Q*dJD]AqX#G0UiN.5AIBR5o[a
<JLm1Y.Cob`#JI<&tY_JM<"luNLVQ]A,`*!_V^M#1M2cF[`jH#QO&0:6>ET<P-6QDIm*@Zuo6
mPmObPj(-hNEjV]Ah(72JQ?gKLZZ1Cl>Z!CQucjdD&[*RBNc9rW@)pUkbdf8,;\lq),=C]A&mh
0ou8%h0r,.r:4Q\sGZtCPBiS`(L,X1YPo:a"ggo`t[SRJ=CBDf;YYNbd$e"Ms<6H?d_Q6EI2
_L;TASG?)f4#QD`hp?!'^)_t>jNBE7J[ps]A)8i-hKX8G[;bc>*+od7UBE`cJp<Uj.H`,Pjpa
#`\#'-rV?LVZ_UZNcg8t@"46,rM\lVW313^u*"D9[maKMNLCs8lIl,nKTdmS?'kBD>(eQ92+
oE>$"8H:g`a4c1==RMd+3*NgO:&'dW'6M5EZ\6B?Z/i7^FaOX(cI@piWrKrO`(&Q,$Z/)KT2
J[S1`>.0)Y.AW#3"$7g,,g*NH?li>BG"n9FEoh*F:\t;cVB=4h,r*+#i<g,phf\_]A.7"C<m3
K:\Z!@^_.U,`g?XP+h7=iYcchLf)ZicNWMAh46+FD'b":FET9e&=#'4h$q6#AMJWM.:*'_q#
92\,7?B2'WE'V50K(B"`dqk0.=q-#`BHm6<QE-#e`BgW.1/TBJaeZ!e5$F+e0"+`o2Spn`gF
SKphVg5b'4\$6Js2(Xt*!S1+[2%ieK[_rn6Y5iR`)g.S"T'V?n-q@'Vmp;*1V?\(^]Ab#n#l&
k!*KAjCr8\&J<D]A`nm`UlKZ45=L:$2Xndi!ia]Ak^Ijsq,81RO0aO\N\0PW"=QJU/<0o0Ge4-
)S;YUJ@<4lMqsl=8dK@ANYrR,3$A1RHh?cNn`=Z5=U;LfEYecu$->_cPe0YAK>6,do&Sr(6q
^ZXi/nh8+qYnX:P1]A<*2Wf\'.g5VkDUh%PN9EP!8F.VcStI.K#e^<Qt(37Yi^4AlVa]A]AUkW:
\OYsFWQiH*8/7/"V``$[^b3Ap,7Kg'B&$->%RO*HL-qZH,R=p^q8cL>C5G@4TsZee.bl:VdW
(7.h/oF@LlQj0!(ll]A%WpRp;B/_6S!qC4@WWtDb=m+QqD<j+%JlIH=`qkpY?R^1,%0f/2l*e
M'"68V/->3DE9.YAe050VQbj5mj\!1dMce.r\fcBVC>-`0Mhr3I0[Y%2'noLQ,)q:>!#58QZ
+"Sq),9a@rH&>_gfrd-qF(["?<36O6We5P#1h+SUq95RgC::6c!2scU^;\PfJL8.S,X)]AgD?
oool>+cKApfHidGV8Lm54Y,XE"Q'VR_QGR&(ZB&=JJ[q`qg4]Ah21ln0f(QG[]A92f>I3FOuC#
Y;K^*)Ym-qg'.mr@!P?=)%;,eX,HG4r-Z4OO"RsjW2hKd2sQAZO$#G-p4_Mkouu9R$qF;;`C
4TTmJmRgJ)h5_jO$VN@^J>'lQ?S6gsrai7I$-@4@O]AH5qM[oto9(Z^M(Zf?BfLJ+]A,V"gP$Y
bU21+2#<N33%&!%a"+2q6gS.XdH43#mgop;:nsDA:X3Q)"!RWK'3>?j86&Z>HPmc.&HY(3dG
fe:e33fLlUgsHPbH/6VpQ9/q%RT8FHcm6@(Lb\Pm\a.UI[sE8CqqBHC3.6nn!=MVJd%'Z;>R
V8&`<GOY+'%:1,9(p):Z9Mkg=Orh"NsJrq`S`sga>Wjfcu9S]A2A"G2o^B"Q\K7#NHtO)D9Cq
q)Yi8>0TE4k`>,+`q7A9Ds9l&4"27Sqn`?c;MIo!DS:%pT`fRbi!26k/AX:_]A$%Vl.bB/U!a
"5(J,KjZWuc-Ueu0720b`KkK#)&(tOF]A2!uHrYnn5;isGV\3fE=U(ErsdaT5MV+Xtao@J""%
.i`da&!)FLSKAf;%OmV[8IPC67:)sR<U-<884$Y[oa[%jYS<LT[keCI#slIkSO'pX^r,,o:"
*EH,#/$Cf]AA5R\]AZ37&NVM.ND8+*E9o*@4T,b8RIBff%3t3:0U0#b(KGeCh:701%pnGMeJW:
g.F=#@dJ9FE.6#FZ.g[]AhLrkt*\1pL-l+sf&f#1TH,WDXj>CBdKZ'hAr8]A]ALu[#h@^2[+JMY
d3Qh=He3QH(1#IEHng*l0"9.'?L=ujVQlgliT?P2hbSlMjNQ>LbgXLgS6m,NBEd:X,Xa.ql)
D.ogR3i$7&cn)g/b>`C;huf?PYj2g0?t4a.Z_:J,ZhQp3b49X>LmQqe=I(eTW;%5bJsg0&Yr
W7i!NQKL9k&bD7.RgKGVEC0&Y.^9gJGH#\[/r<\9Q[WRAq"p^$B!?o5\Vi+tX=i\Cp'AiLa+
jHlY:S12VjGjdkM?@j;o*$">50Nq;i(sH/#6ku8@gd;TV_#1o<c3W43fQVNi@XL,4.Ji"*Ll
U6tt]AX]Af/@A[X%BnaCIfqm<G5CTBXfThQ*ZbC1Y)I@`Qb#L`R#I)%Eof<*DKL&!dl$C>../^
WmO%#EQ+-O&[4(,`II$lOj#G1p]AZ'Vo6Me-P;A5)7QU:QNtWRDk+k*>+&gEN@ImJ*G&"Gg]Al
BLVM7ql\N7^Kl6C<4]AdsYT$8BhF\H;dCQDQt&([H]AJWaHeW$riA$8sg#6=;6UAqP(03033@e
Y;r/Zh"3;3gPpg5]AL8X9dDWND$EB"_!#lA9@l22bE%Cnq$+[2`7C,lm_$D3elj<XqLaX]A?qH
h+PX5.t>>#Y[hP\[5L-Z:3>5BLVI8#a[Yqu/USTk,U$G+@(`61?'T(!H+*+MInf6DtE\SBti
o<+t=$!"k'\Xu3ac90!m$4fkZd9?GQ/*:DQ*DkpU9SX6+#4h3Lu3#rSd$dmr64qQU<1VQ"lq
UM(G4s,=0^NOT`12/EMCjArQLQJ%sfP3;Lr0%2M@\W44g5->?3ViM0X>S,8jaeuIR]AiXMHhT
"'l'Z--qAlD*>-?)mB1(NP#N!tn:&ke&R'c:uIpYYqT8a[?>]AnlGh'O2c*K,nWM2`c'P5iC\
h"q"BlF'EdM9H<iZ6:3uI2j&m3J1BWYEFu>l_Q7[)Cf7'#t6(hc2c@E&q(Utf`.WC'(.%q4J
2=Eq#sN[>?&1?F`jsM*GQNj^7JYX<2u7K+=R*,6QDkr095atO9R**frgfhV5`%25'lX:2luf
9$8b&0`tSMI+@$0':jt8Z%70&%ADua'j:me\LZ#BrPgVt*T\R#/<gFMM!#(Nfj[k)o3=0#%>
;r)*r,`/?&;$$Z<aI%+D*'(U?h#dWe#p6E.a^.QHdVVrjPAS$8c6u@9[&"]AchrKRO<_YHR<:
Q<0L$pdmY!gT>qN\.Yfo2LfsG@6"g'@uC.>_Kb3,Q8'Y$Y.qP3dtp"W>_JjA;H!aHHmqK7T1
:QlkshVhcqA_8+;2&/GORWr&Ar5#.L*=26PniIVhb:u!e\NO>]AXuPe$1/6]AH@!<,d<j'h?nN
5UijJdJNQotT@n\--H\1"Y(X=K.V)#9T7\T5>)kiSDi3>DC&ZVMOlKh/<KACj`@/1@24H!)=
k0,cetIHua)/rd"7Ba']AB13m>_^F`[oSOt8nbjM%`:J<<(Pb<M$e=)blXJDdTr1drNk@Rkb'
JB^0p-Hidm?k(\?m;N+e$D*MU=pJk0ZArW>XW'/4+SCD%NT<Em'bkgJ@AmoL$O,e""\f`YC&
Gr0%&FUH_$O]AFn0\+%J>dJ&m<)FDJfp9rFi5SYJHJk(ssrWB(qnkT^\gKX8/`d\2Qp3R[L3P
ll1?1qg`:m#LEUUX>'mJGN"d3/?*uZgARn),^2N#=0U2,`nG_Hjm);U_ToMk,'.'40r%\if9
N/KQLb@i>?Ea-P+p:X>!40MSHP?DP`O``DEcQYZR$>LJpq%_$DVIV<9Pmj/q7Q'_B(Z5O?96
J9ac&T"2MGR>kE,UPa1L"k%:!2^ih6Bo,lC]A>==Fjkm)-&*hq=@mquRb]AQ"YX<<Z'?`V7WaO
S<=I#P_i`0rD&8n`P5m1@8[7Hi18l4jPY)n6sOb"lP\i3F-hHq**q)#!6BBPH</<0>.#GEFH
.kMHNClc$LqkS'UnT2U>&<@>/X-`t4!Ge4ZNR/iHVTJ35J_)al_F0=t67?lr,Mc["d5Y`TqU
9`nB#'iTanWe]AER3=@304iB_("Ygb.m(OO'I=^3s\n`Ni>WFTF:UsU-P3=glN/62pDl`D(\>
(".IU#P?>A\<8Ht<M+:aN(X2L'lMC4G5.MlmF:&^Tep3K#E@Ql6Fi*LUKo;;-<!&f-DFm/(D
C<(0G*K#a1h-X0^nUs4uh'do3Hq'AYP>W'nfI)o;#<?_gLQG34Ec2aDqiq@-fnK1s_O8.7)U
^M\ced!6![,4FJT#Ia%NFirj'X@iMIMZ&8XQV[jjK"jPYD`$XE*`b%SXF_".QNNTn2fKHi:N
:jQ^g1LL5D2[DCN:8d[D/#/+=-R!8oF7UoZN0jAQ#29<jY4X#]A8q_HVc,Iu&."T>c['g6r@;
Bq78fXWl4!4/7+i-o6-M^Y8sRCbOUIW_E-;LGlGKFnO-D;hk"onP#$]ARMXR=cbf7tlsEeA9g
'LPHV2$l"ijsD#HiW'iB":`'G=hhe]Atm+FIE]A[#qI8oG@fFC7muZ?E>#+RkjZu7f6IaD]AH4)
EAQY>-K':,=A,#@;!OgEYk*"q#K!YI(oh2nUc&YK.<ihUXH<)^`$[MDME`3<(2D@'F^,k_JH
F=]A8=PrUX8n\dtdW6L5aA*]AsCq5;I'@.WeYGtf_f8\3B7k4i1Y!1Qn_4.[jqc#EB^gS]Ak:d[
qH==q8R(;+:3SqMG^(LASo@=?[Q6CQbp5+<T3@W<f_]AQ,Q+1Re5q_A(AeOY1BT`_o0S\$$!n
B@lSMkm_JC`.H;kYrL%gUZD3DWJ#kRDqfqKd[$?cX0Kf%+=@K/SjQ7"_I(G:gSS50qfga3b"
3MQ;;,V:bmHSa_V.@N[_^Pf<PrK?"oW\HdVO*`:,Y(H'N8?IBh'0PUU:eE3$j7P=!<St#\.k
.lQ<<_Xnfe^7Ml=rVQ^kZ+=1]A!UA?4.r!@N`;j$J(##d.:Crg2I#bR<fS).i`PTo!eS1ROIT
<SqF+jK"E4uGgC]A]AMu9'j5(bqaG*jXE`*SoQ5bfOmbEjNHM4hQ2EbKF!sJ(cI1o9TaD8tI2V
)s#@)NTf7*Yqjh:RfY:OI]A;CVo@IG*N$>]Ap<RA7tbT3N5qPlVtASZ8!,J1-Z61IqBu[e0CsG
n3"+YG<TS@$Jo$X3!pECT5hE'kp-ZFZim2*RM_as\]AH+*#l3B\M%l[A8X=k&[IJB/";J$\l]A
=(ne$%:D/#JkYkbV9h>[FBddC_sdg5.C[6>O&^1Et:/d#VkR`']An$:2ocs7-?K[=o.,_9D3Z
;Y"*K;jiO150rTlp+tqgEKcQg-WV#%A3^\Y#8$;f6:3VdWrgt-*rC.>$a1SO=*1QTte^tTj-
10=?j6'"55ee[]A9*[q@%U_hrcKJ%3':dlkee.[O&?iG"&/8l3;bUSLopjK6Z8dnAN5c+X,lo
:A8]A<T1Yi2L1-9N@@jB,X+%bn@aD=i-ukP*4[!#[mkJH`7k+sB@G=VT[$olYY<UTW+1ntLHC
Yd/r(]A1hQdbT("]A:dA`XM8$nr#0OUU*/`LIHX1=B4g$YS&;b?DemGhu.\0em);P:a\*6>&Zi
gC6$&on\YfNM_;T!(X`r?/phqRYjF)*Mk$\aNW>g]ACideLb)6FZSkd8(\n7cO+(Zbk^;Wg\H
ZbY:i)V3'kh=(EgYP1uU(/adUdi\5O(8J@_9%t=cG^0!jqigdm_l1o:_Cc!k5H+=A[rn/B&\
^]ATkrt*a&FG:NKA;FQ*Z(&/oEHIH=??t;WKAJ1]A$^]Ahh<0+Zp?oVurC2$'T+D0,c%(O\j3O7
1m\R:Td>TB`"4^R@YDrq+&7\rc939[qbHq>WsM#Td#,EE>\5Ja4LH?r"qr$KH14DSnNY%hE^
"U39DaSleK(T%Ea,c5IF[U#7<%&mjp9KM%9<`7R20@Ck:R9rRMQgA"3h0DZWn[t%>Y"[hMr8
?E]ANkDi+Q9X5GkfN"o[MV]A]A-U3eli4DD.b!n^TehuN<DY;+;&`/88cOc9T7JE_XAa0%%WY<-
lqH\F?,oqC1lCXrRgd+QLn!oh/F8bo*d\@j%:Vu-1`SZc'V)clq</$fbn6mQ,fhDl@LMuDQe
pQ[mCRM/:e/[D;_&@<6ipa=jT1nP^\kCL[S+(tH*'TWN;>C^P&.!G;7Go1$Q+Ms.&3jCdh=1
u\p(db5f[&,\G?0BJ_:a1)g2@H3MJVu!`i<]AGn@c'f^s?6Ykh/E<<f1YS/Yi[toHCUF\Q#P@
XZoY^!-d/b3e&58b!+5LC@+R.F_or98FbJSR+2\O@2gU+GV]Aht<L[MKZJ=7]AHd#s.7lhrHa=
_[HLHcZ]A><R8H2it1KXfO]A'q$]A<q]An]A,VNV,]A$6VdrCe*QlEPR_2mJ,/u=T:2Yi.*,*GVUXK
l<mu55.6"uV8<q]ANlfkuNlLeYP)V1S$ggtLlOdJ*Z>I6_BY/VP0K48?U-ssSFI9p#oL%edfp
[?\J1KOXlk/r.<DgS#nNPEsSZ.+*F:OTM6QE6c4-bDi.CB*/_ko]Ah4bofa=ZA/"\MsTDTS(*
@oN*ga0gLd_`\Fl*:-e2k',Xc@g>+.'qYnW#:qu-:&ks-;\Ls)kkYNi2D(ONN&F8sHIHL``Y
c?!/a1ajNm>"YOCD%T[#l)KhkVJZ$@ROgj/B(;(mLU>cW(MZ,.CG!n$\cZ;38orF8d2Ott0p
fF%87o:3kT#!=\g'eF[QOflnW6%IGSZJ$)bTm_U>PS\lA.0Ji!EYO;"]An(I,A/KS9sZ>9(3D
4=DluK6i'PCM"nDjaI@MKfdW3Fp:WW%?#m[4+GN@0e'.OA`I+"W$ibgA.Y\OLQ4K)^H1/caI
"pTURQSni7O!#DmJQtM=?(q%e9ckM'.&!MToR\@IQ>;(Ta<h7+J*1i54pM'&.u8DA-e)pb/a
9VW*%`Q_^kiFZh6++B&;ch]A7^4'Y4>jW7u"P]AcL7XXZ,#(63Uu[Le'[!%174A>HF&7RW.B&1
%63D%*[Zb&L)4`7RHYN_VFm>JW3e-TP<P?hf-rpnd(oT.]A_=5=nInZ[G2eKNdA-AmjEPC"2.
@$_O([^S6I,oSeR'Xk,keiq\M9CtLFn5,#ri^TDVs)jniNG$`]A,]AtH6nF,O+tc8Q@.ENU6Gm
6f&tY?=kc,;.;kdG_0(2?hFTsl<h4a5.%\>)SfJK$`26hDVaNSdo"ep;LE=KXUIj#-E;AKRE
ZA#pNENR'>[MWb,X\\QT/'C[6&$3lI3]A[H\NMm_KoMpt(]Ar-t)0Q2M$!aE&:SgMGa=Ke`R:#
YPJluP=;H>K-EVn?=:A-nDroE3no;XW1;.mB(VZ*FiPdg`X9&9ZlpM\?oP"I$F-,1t8`D[^U
1Jl>TDCY8_\&"P%>FqbFI%]AU+2KCT^*K70P[VO:%.3gboH&VXTD$Z8$Q)J>KTQ'WRDohiVqD
'L\4J*PZH5/u^n@9_&1r\a?OpleAW3BE621UAbJ'0eGHt6jQ)E4X@O-A@s0`lk;ps$Neemhj
d_5;OXd8@d6jn`^gnT5.T3teY7)+h3kq!?5-@D7-@,tHo`ALN[Y(E2Q7\gPi5;'VQ:E<.jJI
_VkH)CONgI$Ef3(.L-knmE7idEWHTqbKLS[('KKNS#gD(gF1Fqj,WlJj[s0)+2P/Y>Y)#4Jd
R+NBF+o-P[imD]A/)M+]Ab)Ya4ShpA\6'(VcM6gC"C9dq@kDE8EUcA`4t/%@8Ua=WSld/JsV-S
M]A8uHZu_;ng(?TJRs)ai'VDH@*D,pfgCuD4IF)Ap='oX?(<XULV#cU<4!--+]Aqhps:2mVgY^
+iI=OL,Q5-<Gt.Fie>cV<F0;b2'?ZEj1KU&%-t-1,^VoKAW3>>J_4aAqAE$?pEF/r@en.uNX
(U7Nb!'uSM_hBjDnY":E]A!e]Apni9GnT,=_hPY7?!4$WqTEYg6qN2hl>OrI&!DAaWIX)J=^PU
"TN)7o'I'VqlPT68!u%bgt,qr",;.V0>8LRUHW31"D2U2Q:<*^>Y]A12%qJNZQgb0AkeCLEL.
NmDD\hDOf@PF-c<9c6fVJV@]Aqj>fsu3PX\&EbgOItPch:m!0#i7133B$9_FBrtE#FgtQqZG0
L:,aj.IW3B""#[0``diF8!;TFY=ZmH9rHKSF$ochg8^a-ojO'H"dZrg^J(P4Ib9CHRCK3flD
-:69J/K#'ZSsT0>lT:j`@2dEe?7I1:G[N?]ADBsoZ*u`p<:'DU"]AdO#%/%C]A\UP2"bX0[C?T?
QhZHgq6S)c2:?PR^S=3f?1ic;LZ3c#A*i@n[8`pp,RItE@)p<:CD3_^'AQ9Tl3R,Z*FgFqQ,
HmkrT9J)[p3$7PG.4C(ra,E*)Md1$gmLUa2fG$Z)A=a##VJ/Q;?jeQpQHiRWn!(%lU5et/8<
if1Xf<58Nh;RY/41i*)Y">P[r=N5R;>h)n2k_Q#kId<0:`>`2l-,c<rg%`2TnGTrF$mQ$J:E
b]A`u<X;?Y_kMT5YEES1]A*5IZ?eUrZ+%7qga)O;<-k<1,K3@BLsS1OuT@Bhn7-2Y<1Pc%tS6A
0HFE6aXBI0)j+kr!9YN*c&qY@m[H*@3t1S$Q+b:g93?2jCg-1sR9"nt\9^5!B4RZp!jUg@S5
4:N)'&`LrR1'AX`WgN2WD?j+jZ@B1-mk.561>KtZnVQu1#bD'P%-eIA@^Ss!O_/N_hMT-O3C
TVWQGjF1k>iCmUU+Rjacf^<^OMXDtBtBj2;f\n*3/[sF:-NtBXZ)eXljmkDbfugfrGW,<r;:
LJnpuqFau#(!AljTn&j?)a@p$FIcH!F-#htbf!3ce!c;2]AFO0rruGUf%2^@,@G$AHR)Kj^uP
NGiifJ'->jTI-;ZmO#40Z,T1AmVb6K:\@IZ:Y70CT+9Q*N>dm6[W^s[;Ru\@7-PeNc>Nt+W6
KJVd):Fn]ABbi^?IcB8;4KbTq9cm*j2A7tnme#M.f40n2<p7p.TJE50gBGFZ-h^Nl85`m5m(@
H<,C&'9gZN\J$dqgiW3npWaipn4]A/nZ*]AQasG6/@C@R:0>3+^Z%Veoeo=pKH)7eFfiM_XK*,
gGtW>\Ic!9:FA!n(V$afs^cSlXldcdquhKU/#70_QI;an0$d%`;J&ieDXNr/3ejO]A#V`H6UT
]ALM.sUX-r)[;ESLmdSQVkUL&4@WTRfq[ABsa@6Lu[4"tX7nRUf`kG-#nJr1T7OdSdFUZ]AhIi
&X7BMB;.6#+bbt)N)Y/)H6_O>&nJKj*#Pic)IER9e!ZY%RN1:&/?%#i!%8lTHe/eXmAZ-0cA
mQkKAElD^g4R&<q.J9E"5CTBU&rL#^r`"@e4.YN7IGPOlG<*?[[n3@jl2W/mp[kI^B<_.3W!
6k>>0I-NV>P@2Z<,-9WT&\K["gE38@p0ur\tcKN5NSP!h#UQK:3B2)EQ]AH($tn)LSs6Q_;?3
EW+am5GJrok'5*<VRZ^?B48"*&[]AdSI*4G['tSB1Y`kt8D5)[XW]AnlADV;cd<W$_(2+W;9/W
D>D=_'^Jnq_iicJ;m@>+G55[$IOK:eJ9Ic/fS$(5?#o5,?P/>A7!pi+SUGIO"IY*jjS[+P1f
P"<%'(P0Fk]A%lS&QGo$[AQ(s5%#$T/AZ0iKaQhpW,%F6tZ,C6Y_Dn>`Q5$[@X$F/Y-?gKsFl
n5`s37.!D(:241V-W-P@d$h1Nn;e0@%HEN5ja^WYADm8\)M69[Sa5cRmHo:VuOH6`]Aq[9,AY
9)pZOjMN+iGQ*@VT=jjXdYY&7O9`nNs"#3^V%hC<9Ipli,T_tXC,F\BdbSW;A*o'A%\D*`pW
k/!f-SEJ_6`-V99%7@F[?f1_$YsbuqbQD>>uJEJW>VmfRWFTrJCJAhX&lZL@MP=%P^0sfKIm
!\J`GOV"o_B8X*4fP+8R?RnB_O!O%(;)j$7:::>8LmO;^j.H24\)]ACeM;![mF$q6$lRVnJ;.
oiq-YR9mOreTgHMhBM:1]AnT3>oljsTR4X,&A/Griaj7bfd>)"M<T"Qe`p3eM'paOmp-T74Uf
je<NBVon.8LR^8N9=HSVuL$$jGa#%SII2!t*YKhJ%$rkF.71,4A$$oi6[(CO^*U'>oO(M*3t
MpFGn$p37eV.pB:06FIare=.[8<sf8Ff.L5rmfXJ=FIQI4PP5`YeJ-3qo%V^AE9tuo"IuZ]A)
[rp<8P(Uo'6;EEkCjF>\#ft)WQ4<SO7k0I6Q(QJq;6^`^QjK2kO%u0^l[M7qa]AC0O;IV<%^L
uhC2Ed%^%hsMom3_*;>>\FJW$OISY6ib6#s=DTk/PZ=WZh17fn(_Su]AoDK,m\qc\^$.QS2a9
994&T(ODW1=hrc*p.L#\H']A"E5"&5>b7D(Q=k^+dYVC$FaX@#VY#"t,L-/Oq-YPAuB>Q$IXp
[`FWMt5h2pt.&JnW@fCpb%T_U@#:[A7^/abkG&Km<jhJZs&1IgCJW>X.5!@$2Q-Q-Z6BU$3#
o'ei^2:9U7eesQDm8G_Dln8@:KY]AKtp8$0q=f"`Wd?-K*ZbUt_)NdI+omQ7&MKe,"cEVYD9\
DSk6>1,d\5mQV>@18NN$70[*j+D*aZL;cth^.Gk=0#ADPcDFsjQsPJ4FD)S,IMqg!+<_s*:G
?*h<oC-'#\b?"IKd5f9dN(Sc-+i8311T55s%$g1"756O,fG=@MpbOXNHCR.\03McSHT23WIE
)GLfT&9'a]Ao$d1IbOp"0f9]A-V@X_jeGfB(:kW]AQBn>r+#>&/nRG;1bB,]ABhj6m83B=5M5hZR
Za8";J)^b_4H'X+^ki7:haCO=*-p@je(4NP@6P449DLU[R'52tmu+%,:a+A`9EUTEqnC]ASSu
Zq]A*qkQPSJj=2E1k'uoY8iIa]AQZ*o\d4'%fr@'`H'ac"AHU!6\N?[d%!DoPrRCNSbPV5iHkp
O.1B/8$Rn3cVSuUD*DR>IrFThbn''5ma\&=&l+get*Iq(9Kc<gl!F,ZE&-?MKGR>MSeJ([mX
'`@2F->n3F0dHgs)RY(jE>$IlD0fa/2GSJl>orq4t(:A^VLL3lo3pqmeARL3-'i_,]Af-TPpD
GmRS5KK-MqQm(b2"`)ZQON#W'qqt<`<cHYj>',A`4.>D(Cubg^U,PrNE;qbe9RK4Mbjh@sc5
l\2Z=DaNiQ6l>qZ"OQ>PLY;IIH(&,)@?nh,5HQ4\.(o8]AMCjSMSaq8iIsM.FR#S6[*a`F>MF
.ceS'drgqa@"4#d#XF75F[FRP)IJ"ThqES<*ZQZTiNUB,o5`nr+(583FI9u)Y/Z*#W4]AG;H+
85&l2bSs7R!Q7>W#utSU?%L1@s?o<'=<a%QMH'd:d"]Aj<OINmikJ4Qhr!*S[RD7GKNkH3%;K
"1kO*P10@dO7h57<F=3"@UG7229VVeLX&_RoN>^]AuB/&#e.=tK_Uf-R<ZW#Y!RT:*drZGKhm
42t1jCXY^pSM[-1/9D8$k!WO6n9eINV'B1E\qPC4qS8nQXak^Whn;HhmiF[HW6tk,Dm,f#7J
ud72gdbt8(Ed>o%KYm'qg/qG?+qm",\Z=oZMkXk`1`"$8pGnX*PPqbN3SnONR?2:."8"M8Ta
,ZF@.@^2I!3_.SZR]APR7\7POP$1!HGW-sc%B#9lQWPuOgG9iKd6q0EnCVc,OP4jS<b3`Y:ce
ARL<YL'^j%d6XF/@U<=i;CSc7i4qomJ7+CJAB,k.a&"TRG-p'2!KGDiq4Fc50cO^SF^RCr=A
TDbO)>bMdl^)lWdc/Ba\SAI"^<-#k5?8%A/_cYC0G^[h8AC8Rsn&.\Rn9`^)nqT.RTj,P8os
]AAXmU%h;a'ren8lgGn\3ehcbPfKhpo_[e+eIidR7RYEjb!'nA"975agH0Z&u\G3V+VcaD'fC
eC686/dJGhAm2Bn-nf0&*e6(5A7t:IiRcn"KNQGiu2ji=?rpO`t=<n&XU3EP)Oc.-J`BT@W.
@2&%U+5%-0b/5N&e"OQ2f%l$qWL-F&!&/FM`fSSG9*Z[YJc:kf;H*2D`C^/10s5[=)K9'Ec7
`LJ"hR6N*CYMqjM$n_O5"<K8B[/ChQ9B$J0!=lc\t[c48'.8Dn_L`*Z$jG_=\L*i*T#'ZaJ#
c;E0'+0UWFuEID2kOb#T/cM!Q6VhL,$hDs)]AsSkDI`@I>6"W3SKr!/:@)A+3"\4\d]A@mS!9a
J'ME0F+MEG7eRqeqbg451LC/2?:)<Qn#A13`U<V[Ai#ImS.Sr_f,e-uQZaZIa(nsRkEJZtn!
8aGf&(Yk:_-FOf>("86d1cq[qqd$$n='1Dq%p9&+`j8m5tlu\d;\5/$[@gK)!-ZEujRdU(Z%
NS@'H%1t_-,I%uGjhVSWAeS_bb2!FGfbH=I3.$#>\]ATUMQG%p7VJC[P6eR23(@&_RMGNVT2D
MN&>$maXO3ef3DJOq5q_gO/0,'8*%MtQinS+TWP@^PHfX+^)Jd<%CX3V/kt9hrc5^9am'R$k
EAkPBog@Cri/:MW2f)fq5H>Fg-6Qoaq;Y$PG;[P7/00M?-\Z>D@#Z2SXN72jDds8-kn*"0R-
-',a%Qs:.K:)7CKAu!AtqPPg>k"B:=c*2nV3ZGXF7U-E(BCcV>k[E[C7)YFOoo()o\Ybed#U
P\p^V;t:,,id_mj',\T&U0`)SNLRiXfs;HZ`u9o9t5VDQ3GE-Xg9Yf`[4N4XaZ1`oec1E+$[
KalG#?pVclZ[eJ4VIW\0*Ur05*f=*6$j"umKcOf7(_;!`7LT)cW`r]A%HZ*b\I<*otu6siVk2
a+%1?*Z-8;*?P'>dQscr".us!h6lb(T2g'YH)R`2KZYThsg2?RuKC"!R[Ma+;'=&bhiqcpRh
mV)0>P/E_KY\q$/t3JD[#KJ]AmC'U5bAA3ksBP,951!O4KalVSeE7Ru;Z5X#DhLS?)/Zr^O0s
]AKq2RS'Q\b0$7h2F?!tP:J"_.:Ms*s-"n!Yf5r;KGgCCM>s2GpLOH=_rQ=B(Wm]AY,d9@C()6
f.X*)BZB+[0Je?MQ;Lgt^)rY_7K>h&p/L96Ei_OM1Me5`!E@$U'-_n8&-q5QamDrQ.e3R\'j
".LR+t4]AE8Hm/hn\"dOZ`L.Zs$r7+/^XbLi9o0-i.:tip)7d!i$Mh-L07fY*ZQeMm+N]A(slZ
p7.JCY@M,YI:s&Sua6mU*)]A?HPD_*?tCMnjTA`QgOsiSmV+%^^-bQ@PdT++6\T@tDP&BP@mT
E-D0rk2H@?\2k%Nn6(%(cl\"f9j`IGMmC##`d/fJe-4*"?a#fG<*Mt43@PT,P[BF_iUqbkR2
V\(ZK=(jZRCUS)CiR2[hlH:K-ggri"?,Mqro<,<R.b^3Q"+Wq:")3PkYI"&/J/HNhejA(*On
C+m9`kfA,k@.kW:bL!]A7W,PI/Zf&%[FFGKTPi$GAGCH/>)FQ[ta8)hk;5?[HT30pI,S#a72u
C[A19laW#;o"Z3UM/tZf87GE=\(CKD-:5&$cK`Xp-@E#t(76(H7C80C[a)%ZOrnR[NOm.2=c
D6H-DA1!-i[Ptub;-d)&6;d6`'u"Cn.q_Ifilh4`ETisbH&rKm]A_()g@2Zm/C#AW:hnA]A0Bt
cc&qqrr2q:nL'V)+!2#3jl3Uf_=YAN(?mQXEIo3["DiXN6qJNn_!raQ3O_JT'_>\Q7'Y;Fn/
-[0BCmfM.6i-OYTU)T]AVSuT,!M0G]AcKbU(oDWR>d)LQ6j'US=J)f+f?Y4`Ze)QuKdYk[JZ<.
1C),L]AGrZX&?&A_';9VRQl.*A5Nf$!o\qRc$i`ri,)[dtT?Yo-2$]AQhNd/SoQmsXcr(E#f5T
DM;`oLdUQ21i;CuN12S<IdX_I?k+_LD(]AqV:lV!leT$(7e`)q2.cF:&g?mUJ-Yr=MnF8"h[c
oEJq+]A09Vn9*LJ?p48br+^S"Ker>k<XW.\Eok4YrWQt7AX*[!Ko-I,/oT:]AM_ikHg--S7IR$
&3JEZM=$<O%L>`Y[Kq*O-QOqp%eG]AHPk'0:7>8+gV(<Y8F#G\k)f8X3L3:*kfR)r+Bk]A68,i
!XeG5l34H.=R)L_em%`JUt=W,/X(K$We/CTVVt8%.if385N;qSL.`3d]Aq0_r$>^7-U[a46(M
EPGlp-`*TCP&d9<WT<\&+E=\tZa/8Z/lA!h@qA]AOks%PN_cC0`Y*m:ag,=RhPH]A]A?;s@/?R!
KfmL"8nXa0e=4"S9(XG(@@kFu"B\`M`bt=;gp_3?Jngm%i>B6Y.R*pVjB6,'_JBSBY?]AE=j"
dpBE;?:JmDe[?*/Q0F1C's&\$A7":-#oNB`f=_#ZZQBakUB!*?)BAq56MkG@8&/M-H-=(^*i
fB.KcknWAY]A&ptO(j!C8E>cZAF1(+0Z(PgU0t;hsc6,1=Ts;DZ0N,a5@d[j@s'$),;t2<#$i
AG34F2[)I/!,#GP"%mfZG/NL*[I1gOYQ,?$UmbP##_2[-"_W,+bg!#*%AW(%Ub-#2\5_mFb2
0aNQN[%ARKoQ_>MQJl%1'[B]AB9)b7%6gQiZ`VpZQ)N]A]AL]AoP^K9E&Tka756,XXTeh,as?"-=
h.BRiU)QXQ0$Mk:pnt-1JN@li?g$Tq3EthKK)0kB#`CHYI<N$u/I2.2JA_@1e=-lL:ah1&45
'X]A\=a!0X]AiRoa%9<fpb!q:6Y9jM3T5E2X4kBOIO1To(GAmGsHDW:5outfi,Ml6Q1Bf0X.cb
Pc^hWIE^$2$2U5jUQ^ZpoN]Aat5_N/)0LaeQmc-hAd)/#$1`&E4U+V-Ujf@!*;Iim.TZ)N2@N
WQ/tCngD&9fS5a)Fj!:!,2q!E#+:p82&-nS9B+sG\DE<s\#'K9e(O[F(iaHcq!0Y@@.lP)fH
1S`cJik'-HEo?s.3O`_el>sXZ^Uh&YPYnR\Rc4\rhEa%Q2/';=FEF0RN"H/[4/PNT6BU*I"k
LC(`=ORD5IWRIS)6<b[d<1h5#_<@W0a-G:hc^%Q1.!do#c-!X`<`^>pu>cFFdFUQ%oSsoK(J
nE'NH+(+=7@=uTU/knp+)TB:S&f=^;8*t$l.26.dcr$Ed1,?/:]A3"a_:S;EqaV60IEflucRe
sX<!(drMT7ijnUeO#=mMW(MesC?bSZ&V`t'7BlYHnZ:#BUj>_FkAVm!%<S;kc#Es!,+krHg7
SQ.m-WPj8j),5UT,MT@jE6N`S@Qme6;@d9n)!BG0fu08$\LE<b#NW86K\p]A)ooFP'51@5:'7
oLl`I8d">!L8VBl8;%oH#`E.^p,Cbb"oNHI;XORIKa,&"5TW8^i"Bh<rmC0JADdQPb]AX[ReO
331tU;)2.slZ\h=<.:50O@,X`OMM0>fnf@0-<Eq31++lRFG:t;O>BKu%gV]AB?TA;-%1i(d>[
k8dj'oK!Q%#Wh`!`HC1kZ?D6^0.FR^S?Mm\"l`#5C^sLXBE_;h#>F_b=)ZUnFnFTZ9tn"j2A
oj>Xl*X7?M[0X!&B$AlWp>bb*<CMPM37%'P0f!oU5!%W]A3m/;j,L3-4]AURR.gW^s+L6HUH-"
K$UZ.I!X0f9j.8ur!SMYIpD_$aN9TfDr[Y,1r!<oEZ:bJZR)jAn!kR]A49]Ap'm'VSsh!%@5Ye
&_h=X6HSg!2Xpj_5PmYB_$213H"W#;bKG/!N\NDhI%A^8&^)osW[Y.pfj1,E*,D!m^f7p4]As
t+>,Ph[:oRoij`>bM>Ad%B6e9oekKtU_Z0FMh8/4o6;g<b(6nB'BO+lC.Q!q2X<4@3Z8_^j9
'f'-I0m:k^-%tP>tuNPf4l&'1^?k$(5H3`mEsVi/foDT%it703S*8=+.j>u:cYhuArW5fB>W
SmCrStp\1-#o_7u\)jdGQaAAF'&GuF]A3,,enm?B6'&Rq&'#^0^PMc5g5\57p;Co"/4BcL>+o
1RV\nFK!JL`iqV@"cAN-9,Lc^=GdPJ!KC5\.c7C6'/o0T!,!YN8^S(Y?PW+]Ah'l/S:&%;?K3
X-jSLop;g6-Wods_<*s%q*/lq,bV>9ADLiQQb[l3HoC,<D##n^cuof@K*-MoT;ZWdGfA)If$
/IPQ/`4*E<!+^t=q#'J>nJDtSu6AK'eYhmhF_R`HcaIoo+pnspeNll/&nsnb.bs)ZrBS+2=0
,*!-j)XU\]AG:A,h,#&tE]AJ)-Vfq?P6W3g3,[GjkB"$XMTI5X2d0BO7'[B2jPNCo(1>mpHW2s
.cDo&Mr+(Qk(g%f"-)PP=7Bfi.4HT4!+agqO<N+I-X?o.K&0@A3S-T8Q(o7q0A*L'5]A0Vo91
V=2SWIZj7#qOWNoH$Cb&o]AGZ)gV55-YpEHI%L4m-7T*NET:Gj%Z=P`I_X>)NBd5$BcSn;M\F
#[qI:bRhKf)+<+H+nXq;\iVOVigEo<'P5Js=uQKo4_LQsGY-mCO4;G9Tbj]AlFllFkB<8_PPq
>^JLsG<V-`do;ngo5I9TD;5(s+1i.2W\p9q/Q,j/ML9EJ`CK`)r!<nc]ANkC6&5#m%84Fnb\U
.+3EN-5GhmC*eq[m&FD^`75=j`ALm:pOD)%sQMtcRQT"1.WLF9:T:BeZAA.#]A7mq.r#E9AMI
gj`+?3C7Fu?)]Af92kE\1s"Y4LBeH-mh'S\,8UUbj'[*>_iiqq./U0haWV]A06G6PHH#tqH['>
2]AI.WD<#7.[o'KfhAj=>[9,]AarTDJb]A5"cn!kV]AhaS0MMWR4O?<i9:hp"JDoI[,V"d^^&f/#
MpCV9@KeG^?0HG?-j?kU^"up+@!]A.FEBRe"ERb'\E3h[cW##J_;Z,>!C?IHqgbW#NUuplZa;
jAeQ?ja65SQAI6X0@N`=bg<XD2<">0-P(M]Aj3THDG;.'is-0'7B%&6@W)tGt\Sj[:l8!(5HH
pF_TT9JS_c=WU6"7"*:d[tk:AuVOL[YlDho+VSU'Q_GC$al^=;.biH'YHr^*Z>CB`l9;QA,B
R3Z>uI@EWAG*E>gt\*D?KQVa-!!ace_]Ams;LnI9,7Uo5,1T>FE)@J/U"s`Hc.JGECOYBV*/F
6BPDLDVmRDXQaVQ7AI+"+6+!"k>[s,[IF-RE`VAf`g/JH-LfV!*QS0G_."(O@X9I775K0cXu
pO6e]A\Z$V-%Z$Eo5mXa0U>8d0D("S<mU;k\tlpd7_dR$lW-8+1oL!lNB;;F@(#JKG-@@+)DH
:$"gqPeJ>,:(X-,S%VGl9b'r$fHB:^F]Ajr=!"$W+B("F>6)kcS[$THr?g*=RpT3b_*Ei0i$O
3NWAI'#I7>S4C'CeHM)Li>BeX*To':Gk872&4'8?+uBDX_"3,m28]AfIOTQ82\aFK/-<'D\iN
TNa`D<8U:%5<kASl-1Pt0CVNZP5;YTbIeo=jpcIOD_E#*dCgNRWXYB9BTF.O)@YE:odruAV%
Qt%5#=%6]A7-VN#D/$^5@QSA3W*R9Bii-&838<MjGn90MkCpNbC(7Xe[J!njGO:R#@c4<71Fk
_bVKIo'WmP)1'/eS@aqo0k[bVD,*ST7G2YaloT+_of_184D64QDsm(q2+&-H>hcklgI7r3,A
.OK5%%,&2lkQ8nU/'Dl8fmRjqD^k(pGg0rpWk*tOFp4m2OLI90+@;$DC48.N3&c;$Bq(dkU]A
X9iaW']A6m01k"nCu-$1OMYDg@^3qc]AAMWhCu8L./\G6E\XYO\DnW0Qm_C;5A\326h`!k)*a&
t0>?]A^[TSIMm?Of#5dU^P_XDj%LV#SZ1iN4k=m?(5d#ZgqNed';d:VrMe5P4$i^0=l,8ENjY
J:0[mI>S00#)]A3?9iO&tjIG*?4flWA-@c?7.FIT&>gdS>2$H8$[o^BGbjkTTMrrWkWnrZ3;j
+YIU)B!GhVa!l82QZs`1sX-4ceAR2g+f1'V>+KV;tTla!%3oYJUiYS%6p#Yl=RUMGlJ41M7f
1mS,(B/rs+.Et(-bN.OD#11D54J<+c7iNhP(4#2q`IAiN@@hNEP'c^da$W9P>0fo#@U3"ud8
]AV$a*l(@I4N+$V-([5&?6VJ%[qE@5o?=gX@R)h"qImcTg)E?'((@,dD`9q5"S!HTV>)O`+&e
f8?V-N1N88lH"sp$-(VYZb`Bn3PH;:F`m:A!cNijE274\$7"H=4NNRS-_IW>B%rO=46mI.Y&
nI!_5eVgkM?<a3Z^*G&=nYWY$dW_I_ktL^n,Da"Qpf_$eXf"frA(B>:r^c<bTZ>u$\"ohaPB
Mt_qS?b+j;*PG!dZ8rN+W=2;$n8H`\hqQLhM7=%pMk5>RFKm&/,XWedp1<&'h&9%M1IKh$G,
f._j]A_1`4c:1:QC/=67fZVQX]ARr8$1`2O1R;GuBE==F7Ad\9K/C[W3B<V.1Hn9eBFI5;tLDJ
ibs[f5A_bZZ[?_?"6jSSn'oRmcDdr;<LC>ll-IcBZSa&5@NBf!F8,L0NP[4=?/REbCfu7*eN
k+d@;u9h%T#/-"mXMl;0sZ#Y'mjr/.XTh<_`Z!8ie**3=f/<?'AQgRP(NV\o`@9?I_TOj[Yj
s)Q1;pi6omZ$VTr>>C_O_"JEj@c!Sn)\KXE@(5dcX2Fig2k'7=nLJ=6f8hjfYk9"t4r$L(]AR
T00-:?<Y84>YJ6Q=lTJ[ec^@[1uW:ta.TP2;bE$,%n>ao&-5.YNStRCTYbAcZEp<Xm7Q0iYP
'&Y-OdjZ"-uap3U1>Z"?L/q'[1'qE29%GH&Y+"(HR+b.n=[dl2_?=51U"cH&/J$`.s9c879c
qqh`Ce$%+YWW*^+)pP&B`e+6S4_/s6FQ_$AoMcG.oClqC^VaFS(11V4OC\n]A$ghI8U^APFqi
d\bdqA?h"ZPP^Qc)LCg&7JId]A<1DTcrAb.5Y!dR%p"#t2'-r?7]Ap*aln4m<hdq9[,W,l5usM
hRtsI[2Odm@H+9%RmS2?^3W*.g::"IIMm)AQ(lHi.D=V"&'bG$//%ONH(<-l3Rc8"+]AD`Hdb
!T)\)72<RU`ZJ]A#R1=eLat8f0"'pomEV9=)$in?ske8-QCmN2s2bPX4,6?*Tp#B-TN_B2T,\
5%\P&P[0A,Wm"GV2^j/\G,P<CXf+_.-9mp4Cf+sf2V,=ScZub5W<?>QbnZs',4SGdo;=()Uh
bEIF_pYX4#_3GRni2;^PFD*^ha-iH^0Wd<.&skZo]AU]ADhenA:A-0Gc[WMXdJ!oI4'S84TrlN
61Nd=rp\L]A3ed`m-[@t./lLKqE3B?qgpY_W35"hd:MmqmNQaN/e^[Pi'2(6-84GVFpOnKE1`
:>NeX88oHRm*WprqYMdmAd+GC_LsHJns[_HK@soT\;0;-m_)ZWj.t$RllI@LR=:pB"#J_Eq4
S+a%fP]A8_'eK$fY.$8Gf-tlnCd^g0n[o\&mYE8=6d2ZR48>Bh&<6HB2k+B$?-pU\KD6D0Z5P
^,(EOMp[Lh.>=5g&7-"-rX).H&XQ>f;'uQX2o7r+'iRg-"o0Y21BD*T5&*c"M(XjJ2C0HOpE
A$._P9/i%0KVgHEWI2.PO**]AhO8l@F9sm+9hQ^@Ee6IgVcLP&8M7d1jBd8d]AS9T2>V:7.Ve&
;o.4b(!]AO]AQX![ln6S.hpp8!S_biY8?fE[Lm"_Xt&kj5%H1e4iMX[LCMj[]A/N,\Q=hn[VJ2(
_W,LU&nTq4N/N!Z:ZI7Lfb"qg'>rJF9[UjS"cRL1BgD*WWfA:48@aATI>:Z7PTqslpF3EF(@
>r*%B4\F*ksrZU^aW<K@5X95ndr-0SJ5^G;nQF/XH2*#$@A`n?mUMP\C-"#)'l)MS=ll:LFi
mG##S4lX;hce#o/NSDXc=O]AiecH!,#$glbmD.cdrO\c36STI&N=>W`S9Dd[DSa\K%KXm;$TB
G_Pph+Ks\AO`rOVYMSMTT$@OS]AbpnG;?&9pfW&cn[71o@-]A>Q0j8*inO[HC-rRUJ)3S^-&%r
s/q>)!(47K<f+pYGG';4`-!-UM@=taEOE6>Tg4=QF\ScKmJAtCJs-W\m:ZsmsUE8\,b-U[jm
MB>@\JKX0*![FiFChkHhrB%)[_0To+HAmfO1>1pYrI#`BUR-jfeP^]A;F#4Lfc^POOK"u!;@'
H&K`^*a;FgOHW<T0pLGVG(*`skPg`rkNLX!A:>jC%,pE@QCA0u2eq%7.j6#X\):ll-!dB\V1
!!/t14SrULX<GC,j($PO++.I=u='!\VMShkFn8R4:j&/pP*UaD;62S@!401`J+KsGq=mOX9i
/WkAfR*&]Akm&X5i^f#\D7fc`<A"164I*L?&mJ6"Majm()ADQpqh>T.!B0]AL:B@rc>/id!V_(
8#S8Z9"7.J2RFh(F,P6O@c[=Ingp6/UaK1?H@6P_<B\F;cNf'hc<..@HRZA79"TaRA]A@H;e\
On48QMO7AVfW?sie7j25`7\Ge*"[.BesZ:[c;8+:lr"2/`Q_lQBi'[Y0dX8WrAZk(bIF[21[
5&BZ_cB-OY>-"-jRrmlL*oALhFLOmSbQ\;39PtZ!?7HnZ.!EZjACgPJZ9.Bsh"Zm2$:K?TUi
#;PPmNEQe+ir<\<(N5_#dL)C/uPAl\(8=gneLN]A'&Z6l$_<?/.lOdHj:Dd2OKe";eFU>_$1n
(c@U]AmePTih]AW^p/q7d6.<&_?ak>)o<U-mnkZ,g9;5B!ZU#u(8>e6[;f`u8AT`,i[ILL:!H,
dM(aSb1p$Qo;;%pIBE1JcQlhS<iTLeep*D*%-K\p+FqDp"uZfi>ZL)qH[$8s(O#i%`\G`*-G
Oi)B!N,55eB.VV/k.dE8o,Ze6HL*=fBb$Ubp#iP_U=VMfh804i>iC+RIS*7[8E0#Z]A+p6pB%
Nu^4uZ,;)7S&-eC.Kd]Ado`^&4#gf>Wf=>5u!*f36I'kB0d>rJ7KdTrbG(W>LT_I_H6p:@Tai
2a?I>;(Y&H(7TLr^s+7ESo]APnKq^)0AgUR]AD:AbR+P(kA%BJa^k^$)3EGklhf>91E.*82!Qa
QOek&XeW\/QsTHN7a![!PI7Unl<l*kfj;!g0R3q->(pQ4@m:D-bk$Fc(tB9mFqDQ._3)W5A&
!8%ZlgZ'4/RQ-hTE^0rX'-Ltmu`AfBs;k>&)M4R!ccL>s^oG:$!"jI?ai'#Luu.CiL<1#m,4
nkR8Dj\+\FYi4X9BfE/TMQ,2`piiBnf&n*Ye-jn]AGNQ_)e+*%h[f[q$^ElCDb$,@"RuR1!]A9
gp_jV@2rGYMMI\'#4mUF_,aFWd4#lkGiuNeS)??712/5&UZ!Y12m^Y2Brd:n9@T(gI55AR&I
DJ@_qY7UQ7Q'(E:/;7+"$Rm2Z?Dj?>214Sc*Gt`$UprFj&4'7`9_]A8m<4Q@MU9]AqKSd`UB1I
1C2SK6teF^L3PTNHrb:7F(NCq0/K!5:$+Z6WYO*SD:ccYXMg/edLDUeRDU'7./jArIBX(=Ep
BuqbAc%F>2i-gHF6#3ZP4mMi0%hs7JrQN2?M`.J_D^aGNX%o#`f1/76sj@F<Vt!&G_,ZY+Y-
-PW$=@ljJ\gAml9-4\qmbKeq.hna%WZc^-g20B-9--""n(9.,8rhInujeN7g;OO\=41d+e7f
(l0eA3-16aHqP-uc=2#Y@-RC*YraQ]AOV[7PA)f>^gYW+W:O8^67U#%!GZ>3%[PS202A,`;[>
Ah[$jmCn.#^bu1W,^Eb\4mmNgl@GcZH_k/54>p)8\Z1^[#%&5cZnsq1;##(0L%IS3+a00tVY
7Z=-i5nj1Mu-_aDNqPVZ^B@jL+n%bMN"cRm98DA`ZjW!$@6tdF(7(_D.3^^`7GYgSuV_#jfM
:[e%oC#WpVmY]Aj%=)*'Eo(>a\;%oHfo=S;%V=@&GGGcQDB-Si6V,%bi"K$TC2[m+=cC]A?+R=
[*A[kU5j8qk6sD%9!u<*^V7+B>CG,WTPlMgZ@B@m\3Nt,pOo&S>qRLhq,B7"F;!c&4ZMY]A:P
j5*kUH1Tq2qbJU]Ani[Q-;EeE(h#<.a8hp`cTfr$@rF9?jOeNAj0f)2XeN!03smt29]A*.X;2Q
dXaD&iDHi:R0e'Oi[d+)[`Z?4KhF$e-LD"q>hel(u@f$/6]A,WJu7r:A"4!N;(D)dIS'psbbc
f(g7k(qR5=W;8D0*tc,bK]AjKcS@[o<4&0?@kl]A5g)&gM)<fAH/2(/:\F8j2q"*3I6l]AJ]A%j?
utF'L0jq6m$S>V]A6WI@daLIZ844dp#ifd"V-c7W>qm@<L17n>.=E'#9o47f'("TT=jZQ&!-<
nh<$[&Q>C5B0.l`']AjH[Q#;B@&>[oeFkjWQ3*dC5RH,,H55?0tUMf#]A$1uS'<;#bDr7UTQJn
?YO\"I/*cjVhOqWoa!Q2dn3Lr0L/GG8;3CQ+87U4aiT#^,>W1?4Ce_7=6IG_gC=?0OOLd]A:b
-Q=639BZ0&b<+UP9i8KFI^YW$,5.tAJ?PjS0CJsi'ZF6EtEE<0HL&S'ZPRnXjFStZHZ"X/)\
j3(+_U3:Ad`#3f*(=epm=S\:RG10f=`@>Fl%2:.W:3Zm:Kb(m`:<c/YSWnWa1H^p*JG8liq4
p!FdpH-GTIJR]AFAZSj7R#Bdd+<soRGoZgpCX!F%QeU*["%1&CjFof?^nC;;j+ss7h*H1!\=@
'dml2NmN%Al;SYqQLnaTg7#UpV.mj34JJIQ7jZg10/@D,KckiCas/+%Ed8Rcb\><0gEVqE"<
Ml33+?6s1sC-i:%$)F'P"V2jjsZ+i^kC.9P/uHPbm2pO8rC@6EiD0Ga"5;d.gIZ=b,C=*q9#
6D/Wb#nsXSH3A2ai`+*7`el>T!2HUjo.mU\"`!;*o"n\9+&ToLiid!-n-;Yt;i>Nk>HSYsU=
t3jB+*TJ3nha9W/D&'[S>8V.@SIrUd/M0=Q!ZhHq]A!fDYn'0=[a#U*]A;!/d!9*2_8eS7MMpc
4d7npAbWsN@j?F[0&jgKqFT!F""A8m6sVO'tdo),U]APn/?\(.WR5Mf,=<Jj2-AT,(Bf$lN'i
e@Hi`fp`+JBdqoh,0DIS'j;p6?R^9/#<d)17#;8iWTO3!J$n_/b<@@=Fkr7&B23bi@F;[\@J
[dBhu+5dSiAn6qC2H7]A@ln,):l"H]AAMp#N8NJH&Z[A5LuhZ]ALC)!XK.T6S_j5CX8h&21/PjI
XLuO7U^4A)G4L?F]AJ"H2f@o1OYaD@.OCeHU@0$]Ae$S4htRbt708i@mWSb:l?FqEc6/XGLK#X
Rp39=_G!(9@K31`0Ak2<``jZ7n6[276a[-5(#%ag4k"?Snkd?*P&G@hu6!T%F</O+h[U]Ab:6
VuPG:3!G4r(_2)hl0=X87?E&I#3disOg1!MOGS,Lp%\$Q<q.rTcXFG2lKIYnXAXU@@I[Zsu\
j>E9RFS,1g*&/`H"TNAQek`A5-:$P0'LjX;:;J$*LgT[IqgZ6ifje6qCpDU9JSOhrq-KC.cA
,kU.:GKHVK^n5caLM.U64Fu2=BIO3U-K-n:.r8`G(\h:IQWENppiLH((ZiRo[0PK.$Z,ahCO
:[1K7W.!G/oL1]As2-uead>([_%GHaBYBAkTP,a)7E67o$urppC"6EJVHgr\2fnh)IoT15)!K
6V;c?7ED-BQUhibY&_#cj(D'G>I32f82r'4Fo/[\66JICkN?aVK[_>-@,MOQfqI'=236Uruf
8UD0Z?L?q!F*mKHG:*0BDi$Aj5P`J-(#;n0=&2L-Ebo@i:TTnNg&*JQ/?Hr1sj_K/^,0Netg
fSo3Da@nR_%443a=1rju&b@/9HP%sI_*#:u]ARQE3mB'@mcNK;88$+IE2DbA6)&Q,ETr!o4iF
?(omW>H(cErnnCpe%lIeYVO!31!jgceBN0j41=Qi3\qM!6I*^5?froW:3Bm/jMI%^?n>_,>/
rAPJe(6-eXR4'c/I_T,5rK4o=N!H+N>Vb?"t\:,NtRB<CcF9Ce(&U\U?1gQRDed?/1Bl:A)8
^$XdZ.Rf@GroB_=0%UF2k9QQh_9&H1FC_f;nj9dTr<Uj(%>e''XW))H]Aoha?fs3R'o=0[!R?
jfU)=ch/Z,GY\rt3SDOe=O[3:O(L,htNAHH3>9)eXEhNs/=*Eitu8]Ap\em7\IM`)l.#RG^O(
)TUGs05Y'HT>>(q,-AhQ!]A:+^hI]Ajn*..GJLn@>0Fn0p'MFKAqg`3]A6^j*gih0N0.&[jD*V%
_,gb;@!S\,GIV2TmfOO.'k>B!5KRM;9n(a<:;CXqE9nghQjip>dOmKC@DuaQkcl@AAN;>9Gi
hdZ',6`B-d-W86ib>QUuJ&bm6`0C;4HDX1gMrZ4(X^jDsAs$l"V(WuHGYb4C4"d3Nq^."[32
$D\o1#?$ueHhlJ[.T9T.eRPc:"?6?^"#&EL$@."4lhlAV>mXpA'.RVPqU=u)oS(?UVlF.K$#
Je>`GWCc@"8*^k:As*hoU%/.D9<i9@JrV9r]AA+4B'oUt,AJ(/<_>0[<dS?91&5I`:/kF!_t*
ikt.[0U98F%$m05afYsAs74Q//0Z>SaR)rt>8.o"Xr"hLqF]AY^#5VMp3%Y7-L>mPel/sW,(@
moIjiPF'Jbh\T2O;Nc(6jK-NhJ=s@QP5JY=q?O4FdcZX%<@WDE+cYWMj.spK68X<rENC1DMO
ZG&?<D3V\=_#Y)mQ-V0\42dF1/&G<",8"4FV!(G2RF(qYNeC\7-/:RVaRtQQQe[5Ok^-]ABE!
g_7nSM_18=$h5L:)BILLDVYaC\,l?CRa/Z:^W:HRDf,[GAWjW"_&n_&#Q5@]AGu8&3&H-PW2o
,fNNu=0n$.sM?&D?G*2SX#Qe7ltft5!!m`LT!Iu`"=J#??e@19c[cL)3j;7-tR@GX-AJ^;cp
Ta+JT8Sr9:XJ>Y=4"nK>/=J3LH0CP]AmQ!-%)Zj^dn*.;ipVX@Q"9CO_CE'qH1rN[FYX?>n5R
QqTYG$Y*K:(&$?W9PE6uG&'1F2.ubg%o/g?t+N)_Qa.Y0![uhSUhTb)412?LB@;\J4>DdOSG
sUI?$gQ8%V_>n=5&CcFR)'p?5!k:d,kQ%^/pKEX)U)eCNqji/pTSEV/WSr3d#a+'oQPlGRFj
'kf$T5f9!ZUr2O#g5:OmK$N[Y4l&l1;Fd-_ZgX7%X7oOgLH`#hjt]A.Z_OVLCaoLKe-<Hhh^^
&hP,[._DDHC$WRBoL4bfft/[LaHULOAFH6sACg]Ak_@Zh<8^p+l-JRuX(&VbB8@DPFktL0qC/
J^%ba7SW"?q^kN'S;UBu5LCP9:%"C7a"GeM0DXXO%r%&s,?jcm]AOGsq5C1r!#mW;Jg&cHkd:
Uk=5=%j0k9NUe,.fp.o`.jW8D-bti:]AS7Vo4hL%<2r\$TFO[R-oY,e8F>,N/kAG/^jkjY"Th
+,n+Bgfuo-W''C^pJ'$HG?OJ@\Wq]A&gBer5k'TjX6?l1NGrrb6G;1sF\HTGDEQBANs#YtFBI
E4%'02aNsO:=t1Y>(o&kZH0gQCna0\\-fqBWb!/nhM2[B#)ao:$.h>/gPE^jSD?+PVp3:ouQ
KS`N_V]A<fMR>ni*<*7#p$s*5/g\^LRPTUQ8scCS\B%M,XH(2GeXh+S0(eTl.*;P?`kI*U)$h
iDQ3B;grL0@S'[3[_H%oiec_nX+@1E3hY5S'CNQ5JGKWU]A=#t`N^trmSPQM,:4IVYc:W)_+&
TbB45#Z5/tMt(:FL,RnYA9B\9r;EP0@LUB<QX_W[AV_<$pU*M@>fqD4'C38rVI/M3XV\ec66
1?h)YtjO#ls7TdeQfkbm=<Lm=rXLjEJ%N.Y6>Os<CjftfAj9_\CotTGANn_*)>dqC.Ht%3`4
cTQNs"29#44QSt9#/[bm0@9Q85)'k:od);T<36We%E2PS<4T3hn&;uY#19/02L#28XQBTNOQ
\T)IiNdY!S76TYT6>"YBAD@I7fp,1CbDc7;?EV9loOW^eMjEoR\EdlrY;`Eh/5*R:=;?F$M1
8]Ak\/FmliYB4@(8n;u[o6W#tgF-tXkF1CH]A]AGR'I<MEY-6tPFCG`AWu3qP^CLWf(7RD7bT#c
)(<^K+$O5Y[,b2&'jK06eVC'D_Y-ceB4cTIra0'=+LT;,RE^pTu>NV5'8s.eL1HI">VqG\Ea
_I.)ApWM<<8LXZjLqq_1_qGdDIH[0L:Q0r`]AqjZ@6hX--`pK5Uc[5G2-C%7>YnDJ\gd',/bi
e>7G,f\kT`QQ']A!niX7bBZis&#QeR$u0p"D2LVOX#)4Z^k-jLM$EVD!l5-fKcK;7+cU8K$SB
ooHK.dq^)STK7FX`k09Via-[lfgVW#nIWBoWk(dS%"8K+CSEQbqAa:34S\o-_8o3\I_:HibR
:T,A,`clQf1Hhk$J`144LXU1`=bp_7DuVhiII*:t\2M2?iIIr()!Y/i#eLp;b!lL@'\FFm3#
qQ)"M83Y%4SZ\\NtRsQ-+[*,)/k1m2j?DE1h.I.D*U2_e9(8n`>p]AjuNs*!3LN\@QKsmO!$V
JH>^i!e^2W`Y&02)?:=;[$BEQU_/p'a&F/[hSt(Z%X0@pa`)j_p%\`6D#!7cOlH/M1$YK&=-
%;Ct$uu+h78X7fr6V!_InjanPPVJe^rmtXjAFo6U#bZuIqAZ2#Cs7"g9W>p_[b.Ug>o(d#FM
?>#EKrCIqSRmnQX70^66q\D)%=F]Ao!a%m"=D2e_nJE;je4,g70/r=D?,F'0m^sa0MkIW2e@A
_/tJ7IZeEEdXX7*q1">Q+I.-fS]A2:kll0sldje1n"61fkf_I*:8UdBjJJLAd_S=5i#'2o(%K
'+\Nn4ZSSN!ZnT_:3!?ut)ePFK#QE5!t"7KXKtP&A+L:=61@1%(p)=QO^4#t$!-K1!o%D\.G
NIpE\KMu'q$&%''#a[&B$BXHPZC`T?rH`XY0Q2NI6_cg5!HP&#H6^_SMDdc7]Ar>'cDSMhMl=
LN?LWT[iKHi*#9\GYMaghkqM(a2%)HT21TgDT5u,6u,3!I3V`[hp<FT.U[uPu?B0cU]APm!ln
s[A.MI`WE-Z01LCH.Ol7AP37j_p1D@$(BCp'TrlXVkiR<]AuGpH"5hmXDN1HY\M]Ab2sBX_'li
[>s.r0VbmT=YPduY]AJ>H4a6J/d]AL"_mKQrL>l`ajp$D(fd6/a;06>Xd)s.*7`[:eCTR<L(#K
jY=K:d\Br'i,TDRR'!c=(ue,;?B**LlB0[Shf!nJFot)`231q[hSc(oHi:`%Sj7?:@c3g4!t
O#Gn:.8IEsJT"O/N=/,85V9Q&^jOLm1r<hep)$o>6Re*k:!h@7F[]A@/%D"dR8Z#T%!HA5:_a
':tX$Z2g-XBu`f7!d<^b7&_A(HiV]A[L9'?P,LnSA*!Oj#&_(LHZ_ZdNHn0<s8+Qdbq0:NP$<
o6_l<!>U43)W+>RVgoj3Bg:Jj<knt%r46`[p']Am#1%fguePhA%-:&4h%?.g[,P3=S:JO<u$X
o@a.EmY@`[_-C<+SbM%R*=6BiBQGqtpsqCX:`HMt.a>ZV;s%NlM$eM38dAWjD1%MRdQnV1$f
Fk2>]A/31&=cL8,m]A5CVL"67RYW\$>3_s:(;6ImZXHbY?CDf,T0#5@.Y"N.baD!>#c\iR9isr
BMLoiEVIr"U"afpjk!t;LbBn0=d-&]A3*_5B#?=X"!$`@^#1K_$GeBsq*6!nZ<-@E)*llS<6!
4=(h:FR\XK*u2u1j\V6`uA_O,1B(nbGK2S.Ll9'8rQa=NE\ubQ%M=B'Xi:B?9A&Ohd^o8H%U
A9>H)E&_^1$[jdY9L'U7I22Gm>U!=_(qEr6E+?MO(@"*T#k[L#a3=fU2JiGuLlS/k5#H(,<C
@0@V7WGB\ceic/0lM+O8*hc1#O_&J.0KlPp($jn1%As%'o(@U6fN)>hRr7*:5OG=JeFCm@KI
7.D87cDIO1r2N,HYpsDKUN^^]AA`YWQhsZbB"RT4J>G5g8F(0I5cDDHV0u6PP_8:SN<ZcmoQW
-mE5,O19QWc1MIs(F;L,MQZ_uck+2f>h8>dphA<5)4(N&]ASDr?+D]AN:!6VK^$HT)+7ruK;(p
USTBO%J\E(_-KDHML$os2mU2=TNW%e,hf7hjKN;9=3=n5(%%mpU8Iq$91#kDmg=:s8=ofXY=
.Z]AOSjSE,et`HYk;Vdcq!CqkC52)Z:-0>kdoEjV%>Ma;/>TZcP#U9/X1F[k<`-8)PI_/!jOj
g&;JeGM(<E[pH_bpk,u`FRM=3!q'b\&MMm5&JT[42T6F7gegA4/"dlaB'5?1OeSj:TNJSnh(
s^RNV@,DkNj)qi%(lRi>5?O<Fe-5[E'Q'=KN-m-o-?hXoA4eO2'\ZVW?UuThOc:$5JV&H&#W
r%\miq+3bfZJ/a4U%<Z%R^ijJ%mWa+sE([g,]A-4__I`0K1Y`7%-3Ob8<Yo\WpRa$7D0@(&q4
$H>>j]A&(`rMa[,OSr=J,'%lG-aC<RY:D#KQ^j07C%TI`dn@N@hg%JI8&eKVaWY";n]A(]AD,=G
b.b)o**=;V4<.X1G"(1jp>^JU9lX"IUY5r;HY7Ur^78>G:ZGU&&18_nO-3JNqs+EsNl%B#e`
J/e#k^$tsJOa4puc%tGH.04>V_=J_E6YAFEb_H]A<#t[LF(Aq@=B3C@3Jrm,CV!#<sne:Jt6W
u_1A2TX+)6o9IV;Lj8?*(JN<j.JJ"DmLd`[#IO1F"^U3,3Rb:`o`Oc1,D`GC.5["ohWX#?In
b;Yq9C`F8Y9SfP<e'*1Ck<H3h21=/U%(noqDZu]AYR_Yd-!;+Kjgg2CEZ,)G[LiD#9;@RofGf
@WgjjBs[F@VqcLYgq?TR@,fDl>#Ys<$<G2(H\E.Y,B8!Hum=B0TAc(qKrrN^A@,>4VT*l>7Q
$A:*Ir)A)YoDl#cprRU>43"phY("rN2P#0EQX`e+mO'J"5\'XlCeq[kRaXnjPl%;YR90,+5g
;[``#WuaoOC;@^5\a]A!UpZ:^qZ"V'qDsO3J#T.V,RA($@%B6."V$%CpetVM7MUCr.lM*fD4m
rHa<da[nKT*u\E\CQ'C8PDMf&gU>qOt"Ig$r$TgYmo?>5Ztm(,-.A=9/s*/`-?=4W5)Ol2MY
F/M>e"?XSj<JIGtDY&#A8=&G`Q,K.D[(s;NgJrKp;%\<3;NY]A>?cfK//#bl`QMe`'S?XBOh<
#]A</GCGisPID'o#<.:khsW3+2DuZ)*$"'2WHQ#cr_;0^XcZoK3RV:=C*6ln'FLqIopD6g_Tr
h>.qAqcBFlf[?k3U"XJY7GoO?7dm9!:Z.=CW0]AU5TfI6W^O&B'KTbI1qZQ7Yp\Z^/H1(cD<)
L"Lt[8Ee.UHp!]At0i97YD/@A5[1FE,h_an+A@sGofB;7+`9YAOND*e1%`bZdciZHCeCm(>?Y
^CO;t/o1.u%W/.>p?PbAnKgU>dkF'?IrAC9ku"mOqH*:CAjVqMKbm:tT=dmP):]AAlaC@64[?
dQDsb4X8C:(I*fn&k^D*m^Um(L]A`g2O_)E#,B=_/7K6,]ATn9ZF@VXsLf%5`aadVMSHI^%XE9
h/*j%GG`>eY(\C-:iggC#mL_pn>6qgXPV)8574\*06C4b``V-S57P;+5]A?$E!h<'hjW:Ggfg
oT[W9)h#'3/QIpUc^^+Chb;"F<pL?hI>%$7s-`Rbj'j70_QTZPfr*WP.qVt>f'f6B(8qY--^
R]AA4TUOSX3<Ve?o`QBZ(XiIK2@>j^Yr70%h9(i/6:IoE/S;/qH@seSGKEFZB\08Drrd>X1Fj
;C,/&D]A,P3=Z`P>4(74/t3V,q`pea7lhYO4*eAD[Tq5A+3TL`F.[4N6H5o<0,5R@YXAh98U"
1P=pt:5,BDt48uYd#7nL<5M9fh>SHEFIjN2(i\s,i3</g_OSMIO69TcYMk(d.(iaV!rp\>eB
T_A'R)iV3V>nuu:mE]A)/EH@)qn_E<.0f:?e@pMf9@f^qAh;dY%*_KF4E$ZIHY\IY'OpS4jmX
-_Z-='*0@O<SVoi1d1mD2<j.ce.F/\*WMH]AFA8P-"5URjQb'g-(^@"/b\9&;?f,=W=8I"at\
*.8T:8&4@b9$0Eq@\qJ7;<E(eks,R&SQ#JZkAZ]A%X*Hs3qE%tNrTd<C9A>R?>W!7EW`K-\g*
#5(rlY&CNL`ffi_>+<`7Qc`j9ePtm9:eP;NnE14<(n:p\s@!&%GYMIt:WN<nLW8:je(plU,*
GNPn-^=g6JgjH(_LnWFf4ha3boR!&\_H\M.A*Q;"L7:TIH^p=^kYLTY,hUg3H+nF+Mf(KkFG
oR5rWBDUTp)-;"`uQBFN/H"/ml>#2hPDM+n-:b72_6g.I4,A=Mg>D^gtMm=S=FW*$Pbrlg&"
u6TQ$^\7ZGX`R=j$W3l_fe8L7UPDl/>3PhVhTNaem78UKtB@=p@"MK"$BU+KdHk47#<s"8M=
YTq]APTNmlX6ho_sFHJ.cO9?M-\T'W\+WL3kf%Qtrd'`X/iP7_W3IDhSajm4G%YI&uEMX%CA7
%P7JaTG3`.bb:_Lsfb23-naJk>`gMrM(*V$(%_C,Vdlb9iK9C++]ASGLB80[.7`?CH,j4hiT6
rQQ9.S4R6"*7N"<enl)41_:hG.I43ISjr-);iDtC(guWEX;,?.9jKA6$ZY,B^VIN;2nH(Ni7
$STO;X8XsX5)"<SZ-bFAniY=igC+CDkiN",b`C--BfjCZjVX96X7)^WsA.kh;d5QX(c#K7^u
fI[m;Jsi(d^6+KhraYaINF-kiT5f=KVk[K?IZAnh)A(ceRH3dr$Fi"\qY>X<-YSNYCN9uXqd
l]A1^gnHDt`"fD*4e*WJkHM.Y.2K(_?Z.;qm_q_=r6Kt"j\61<)H*V>,S(.c=6L2iQRJOQ\qA
3.8\Q_T5poqBIdiV8HN[hteTGM,$l!DarZP*^hrT9M1G-qRk/7]A.VJJ0oL[)[&d:\)HU6$VX
m<UY.oEMB(;aAXU?Y4tn/b#c'-[8!;)%.OpMk:VK"k#Ig6N<%`MJ<G6blAoD/">1%tACUl:$
KM/^MourVc]AjoPUG^td3+^tc.^mC-q;^\7(Z<%3@LG)=RiLkT[CSl[/.n2?]AOCc#[eC6JM:M
8Z/+lV>M8jWQj":7/-9q5_0hD4-A6i]AElB#J0fBpan?!K(Df;7V']AbWhWGVQ47*._,u;pe8\
lGl#jSZ6hoi`.[sjk$7^QksYUHl`nl*,m(XmJ5;UPa8SiR(uhqO%Iig()cYhoj]AX72JE<"qk
[RgCVX+:gB&4,qd2i*!*:2"p^3,V;JgduAhDmS/qk,-<O56Vp@PG*anGVPL*r5]Ar-Tt52gGW
Q@&Wc91qf?[9\-/V*0VloW+`1G&EQiV4^8g:Oh3?<A0EmL[ff><[bIYt(^MCP%aqNkQ]At`FN
m]A6`^+4P(!(o&(-@F/n.6*to9c(Tpp<HLT,N:,nCtNg/DEnuUMI3DNn\jTtE#kfDOo$G!"YQ
qHB#&aokjMtB%27&0;ma:i@=sXL@]A?/#O'=?p:tgI&>mSa32c^6f.meu*QQrN>dK5!)DJQHe
'jk!SQLeF2:7]A%R;GiT5Uqs6Zml4:re&X5qp1Imjb+5a1"[8rYkX1uC7P&%#LC^9gJ1mG\*P
5?Xe50l$M3+"S_c9C42abiEdHAW)jiE,Y2>UZt9pHu:^4Aa.@j\u,?7MB#fX4hr+.mD*$cD-
VN:.>'B(ACkj?Toa9T""6K#.j3+)o)gk=`+]APXhsfS7:Qi2q39*'W\X+^arX2nb>\:A=K*h2
Fkg/,6*?6%*I;76QQE#>aM&@O>$Q84`=Hr\_R?n([_q4=l,G3mSb'FMC4\V[(HkEfe;XBjlN
]A#3u:?.j695_:,F5_Y2WmQns,\,HA'=JJ\qC$qeZ$Og(<eNhD9>A%BNrjHQ2&,j1cC0C#NNJ
'.,/r36ZaWhi9?]A7QMa>?Dim5`090m8m5I<&!mn=qOK#;M2<jaeYU=1U(-8KBb=mJP&3!SHR
[Vc=M(*e,5Y^47oG,jp*j8*msFBnfLgTFGmKZ,KUpj=Y=REfm!V;C0X_@D=`lHK%sUVVbQeW
",A(.jVXPbXl9eY<E.YZLMAR`5)u<hcM?9-TSiFLP*4\^O.7Vu[NhF.[D54eV$T<"naVVs$W
/*ZlPLMIZNhIp#.43@X+m^<:3:EOB0-:KML]A7A]A/ts<M#9>3^%[A?n@c-k%W6(<#YD8FC_Xl
Hj9D\fd?oRIr]A-DSq$"`4o6:9#Ae`S+S+isGM6Qc_LeJZms3";!!`3%AQYGBQqIJksH2`88;
Z?+Wj>bqog#3C'-MAe)HBok\bRHD#]A6YS2!e:079[_+:9XYT/NRN,OOEP5W^?($Y$4eNQ=Ys
%OB-pWM?G>S\Nhc5cD.+3l?*2UfJlV?!\*D8Bad?#$Xf2ES@m?VtH:.`BKP&]AanP"r6Es*jn
G-@c?A93)(k2p,+ICE?:5TG$idcE.?CeD[EE/3m(Xl2jBIM;Xdl@o1X"WXN0(3^$1<MTJWWF
6q6ar6Rmf8fTlQ*esd9<6ACGFDf!bjQK+=3=;boB(K"%n#Lr'X+W&-D0C=tjP7__"5H]A2cf!
-F^&a4*]AhAE7,`]A68mqWBDYZpW"SSc3ACa>Y=IU,k&3'sdDVWXY4-_:huIp'PE]ALZOs+I'q7
F)H@'#L+CRd)N^D.&2maR5[aL[n2Mr,&C%ED`U\Fc=S!l0B<5H;;jk.O1+IP[!+k:A3\S;lh
=qhI/'X>#*>#OodQ1qFI^S#",FSg9H=3uh,Wo4]AFXl=?QnkY%bLEnNJBo_&lGA:7.8M@6%nH
rGL;9(b7$ZJM%\Y./P:*s,oB$_F<S^:D01D-1?pragme1hT3pQ\H-SU#YJ'46XhE>C@`NkoL
5tZVJ^EeQo]AB)$#sYI0XHNn<dBm5#-`1[ZAU\.;@OR7Um/[*5X>E=6)KCg6aRt+#-#qP?l^<
ON6%CI&:VWe/9BDS!R`dV:iI"W#WOIb1DZ08UKBr:U^NI9YaSKbi&&(d_[4l^$82+^DYNFtS
2fqu*<@0hd9j-#47R"^!,t5?iIWN_2EG[&j^&tnj%3<7T+nT4UNf5&+('cL'U..l!oI&P\#t
O?rLi]AS*"1s_am=e;Z:7kD.>o7W!SmW[Lj%L\1N#=be'6)gNciMi-KQt/H-_@D!l+;5kDi5f
ZSS.:ip38fO/>te]A\7^*0JP*^bddC6g+=Eg^d%,!g19ECf6RmbaqJ\hZ`1X*J:s,9s!m\4+?
gTBi1@2ENm3C61M8A&*nmk!ZARQ5^T`:UmL;>.\-Us:[AkA?,S5@%_)U@d6>/=8@qX4&Yhro
7S,jG2,AES'Oc-?pAZ*)5NECX,C\!HE<P\N&9CHn+]Ar^3;oHUd*j8,aCN3Hg-Datu:,'WSH[
pa[\UOoR*fb0+B&`75KYj<N@h]A0AfI7_F`6%%%(t$D.T>p$'a9JNTsA<t;+:#G*=rXR@1l$U
Fs`>t]A:_V"kTa]AN),<gETY5R5hi^qQKZ[*Z\N_<PJcMFREa<E_iaQ64[4/BI[uBBe;pP$9mp
.!TjRKZi^JJ!2lhR/[U;e!RLaZ_K^nEmI_?4D0?*2_Z\e1aZk[pRtPJhChC`JKge"HU97,MX
)cWdJe\-.4$AYq1*0O$Y)go+N&VZSV.Z\0.AOR)kU%3,jW-EqQ_D,o>jhLdAA=]A`[ojkIqH>
ZR&SZ\#H<(YFUcVN7@h-,%<6.=uS^h40J\j(i9$)"S[-p)S3%nohUe`]AHhn)s@;t7E9;7C`[
qQ-MQ6Org,n'KL/T$^C/-@4boH+s'?H]A*5cPJ*\WrLr$lPH47"So,T,FnOIW7T"BFSBfO&$C
M>\^8fK?)cV'#)0=@=UpLP%-%-g20p/F4qjHE+Qp9!?lI\&P@IYG$o,+p!=(;3o7t;CLJ%\t
JU_Gip&mnDRW>9#LNi+SWMt=VO.<?i\n($34QJr_&8V:U_+S_iU3gMmUEd*h'r9,kAEsUX%n
h"Krb(teE0^s4fkYAn2?Pg*-XaZH,N8T7W$)k`jOD0Kl6]ARgK(*hbjdq_1r3d<:nc*YB'17-
aQ#(LMtOeqT]AhRW"IGEpAqG5,Mi-[LpMFo`2/!YjCj7]AeSTKYPY>N4s.Trm?1<\<"*epI$,-
<MFs-r_?1cE/L#C/TFr^]A5C@.,5*i2mDP4\M4J![lED3Xg?H4DZ=P&[j'BV*VsVfF`3",n7D
tX$`p0g1*6;0XfU#ROkPAMGG!<10dJ'=V/($,:)u3/go7oJQAJgeA</nGe(,(WG"^?-iA>^#
poG(/f%q!oGVVPWXn^b^bP&tqb<9!gB;R(sgmaE`2jS;_?8I\CXllP_o%8[]A1f@/=4O7H:+m
)09g_r@3A7?EB_f":LdC\n%hj-/78&aG.Q06?nJ5<.?:5t?6"VpJ&"Kpl*B9u08XBb:^&no4
G#6T+V@V=5dU5[Et!r@u7eb@YItE0&??c7+sRS+c`Xpf%<9liB6j/H:ll8Kq04h.Ct]AeKB*_
?5R/t+$'cc-RtE!*1r3BZFf3^+1s>g[?RI7b\L0"ee9-W15eG`S7-1Ih>.dm?_T/3f<"h!OC
IuCAYDV=+Bp>48XVkBK+('[h>[6VAqaR%D!L.n]AnmM)2mDFAcDR`F=0U37TF$l"BU,6d0YEU
d:7=/[eFPH53OY6B>f'RNY'>"NbG[&&V[N44cPdjl$)^Ncgr06S$1^0/H0)l6E:(S]A2C#D#6
o=3.VS-bZ-KE,\;s`3,C(:u2o9a(1LTN']A*D$fc4dCV#DM4Z&SN#K^A`K=epb3sLo\!`Y=5P
dIb$jI$b"eke!$RU\Pc`0k%CaQbUWDc0!@VMu&ASZDe7CT-lnV\U)mR5K1;Kn0rQ85]A"erm,
XpAAPlnH%./#(!c:n@5%Nfpq-RK<lA-&r24EQFH&kejSM;oNW=^&"g2.@>?oe+eFRc&MFk3I
"oW0SU728/ZANm,,e7Ju(dF?t!%c86@'%re0!5OG7Z_Kj^n>aL[T."RW5Y&7.S<F(A7[n'8(
n[1T>9:Pk1=6i6(2T*=]AM,r-X+838bk7JFI\b!CJ<)mW%m2[SkG9kDNP-2A$&)#o;SHtG%3>
5_QdR_F.ao2)[E/^*&Wa5,dL6_inN,,9rrhn-D?ffK=2UIs,0&GFadCg$Ta:!O*dgWDbA5bg
lPp3**0;IMc&OEmW#S\Mh;Jt<7'V($`nrK/_EQEQ,g[W&]A[Q@leQn(o[b[k$1EBAGqRoBG`H
lRfTp&-Af]APr/+&7^4_UT'3rso@D@[mRT!(^W?U?bO9"j=ZlSUiIh"D_Jg[%F%I/QMrDQi(M
iAujJd<U_1!a\M\$=HA+q)bY1S<a+9VYd+IjcuWqS&j]AKT-PDWCY/s(DjrbC?^5JXj"98;?a
3RtGki%C8rOl1SF,*\'BE;Y:&@hjSHep0s#&:5[!!o^r,>,"#JRR<?VjD1Y%%%e\g[ou(Td7
*+CNS$fsk3pmEP%SSWEr<9!7F0U^<W;\-L*nIW,5Im@spR'/\[^sZFa1V%qYV0%+hNlRP@oK
uJ8O_G[k7@^"[r%d\6^(;90gc8Z4m&E_O$sd".C%Q,Jn23G9hXQi!m'jO`kR89P_cn-fV*fo
F>`ab]AOZ(u*rSHjb<"gDi?ectS`Hub0KN53jm$!./nHn_=U-s7/K3b*rUmX7rMH#i_<-pgX%
ZTM;Y/;9fDqmHdHY<)b""Mf9M;mfj#94.Te#$*A4=0BT7N%X?VH1[dmEK11,SP+o\,=[,.@Z
+]AEbpK.N#tobu*&[kfh`g:(Z:6nH[Tr\D]A*JqlL2oXTA67@)F,!kHr0CXl4'A%t;)rTAnFU_
noZf=Q[9&;tP`q#$4(Tb7BJJ%HN+q<h=>L`f1,s/Jl9pb-c-nhE>>gq03N?=F8GG3/pHFJ$[
:nYr)=(^&R=%Ra=\Bg#n1)gHED;Ap9Ea8:o`_'4SaaZj_]A&:0aZ5j?q\)fE[3-]A("CWb:]A<R
=kF-461pnCC"rIj3_>/u4^#__o90BeMTRWSZHc'ua^,D;+\l;rl8h($2f]As25K;;V;T#s@fu
dT*9d]A5ckeIjH\=&N1aXt+hc+UV5)X-eCW+$`[-/GI&j\(H*d5s(f6\k81Pua19$NPBFNFql
&#h_qR?tZFe)Wl5KaARjn9W6r"C@kVs"Y$V%FuK\)2O?#[Q>+3CllOH0c['F]A5C_5F3hpm3.
UNuc+A1>rB5i+sMgM?VHHhoS(.\UM6''@t087]ArVPM2*W+X*qW=A/B_eXr0_Cs?j/DWF!\Z=
4Zqt#I;#P9M$4W!%'O4Fe&^f>P/040s5m*d,_E3&&3W%A!a(/CjNqU&[[%6Hh$NiV2BBH!N$
D9TcKokbsP;%C^2r9E[-ZYG+T.$Ou:I`m.,_Te>"&'?4o9LYf-$@Tn>3`Z<]A*9eJH,5I64*j
>!%VFK=og+8FHq@#HVSWX]A?#_*\G#^#ld?sm4Xj%a("R=Tf]A+Z6M#ar<lW@I/'nO=:CHF7+#
t)Vt=,d%Eu<W@T@%3E<MtOcAf3:QF#@%r>!`=?WXIO94"#^kBGgbo)6R`P(CbG>n<F--=5>`
pL@nS,YUOQ$H9be>1N,A(04DmaCl#nOWuYqKm_qdKWKm&nLl]Am;o%THI57Ek(WuY@[ipo>*g
uj/+/8bUeb!$mgQFQY5R:$h#\62GQV&mF(=8b+,a8NV!s#9N0H`bk3&@,%Cf]A#Dp<-P3Bt1=
[/*a+UPRW?aV.q;q%S7YHZC'""$18A#o^-cGnI+E8;tngR^\"o8]A;sY4-[gJmT?QkC.Q"cTo
CD1Kgt6Z`eocIat'_?o8cAe4?m-)I!T1!W^'m14noi;drtj<g`9'19[A7i5"F9]A]A@C?C'@3d
LLu^g)0=7*lk)N";UTi92<GbeZXHCmWTV2*l2Pa+mMc*38KFm:R4ZCqGOBC=V/%BN@dd=3'*
P\kf9(hB047Iu#K>@p_SEmU\!=%A^jZq;6[WC@^ZE2Oedm9<\H3Y,Z)c<k*:[TAuA?MXlki`
\]A=RRHEFMF*VYqX608uZBd\5^)n"jLT6P+=F9h)!02khf"Y)oTN)?oTnaf>3=@nqfH3nO*%W
bZm3X.&W)%Y?bA%D1`'dlh?).gNgI&UWH[c>QJ+qcQ4qsp&W'L1SVpk0ls+T@HYBbE"-'VAB
`_N>CY?,U:"nQ0=Su(,8HU<;Xqf>6E,-QPB=Aq5o,%TT4p17XdUKZAAGC5Ss?0[V123PRZ+(
lD%P>VS2i]A;>BmJ:!Dr6,KBMoBbg3PA=!o2cL!Z6DN]AVF6kVQ+'e[?WmMHq9lG&IDMHL&mKA
W7]AuN,FYP!SelCYt*A:_nfQRB"<4-2loi8:AeZt]A.*Es<$dn7HOogI`9Z9@A>,+o>3`ad0dB
]A`pJfc/8tUJOP7`mjD+r(6H1uog?[NN5^)J^HMV8b6/i7J2"AtTq%.eB2F4*@"hshW9@m@K*
)m`\I5To#ek%!@,CbRXP&8U;*fFeS-'ehS*EO<"1lXCP+2c_0AiIS[Cbt?q"7bQ=+M_VSH_o
nith3m&#(6ok-qI*/YMonAdlM[hgQmZ2jd<^9ON-R_a<86X&lYc8-7`Tc0;M_FoJI[hMe+n'
&R@OT,e!g`]As7$l+s*MFEV[qc`c[X:E?Vs=36IV_C3h2WH;B\u)FVgAu;O?L,^btBs^7,ot8
4qIk9h_0nnnJIIk?m[$7m.)LKbj,4OiE^UISTdsLUNV6GRhX_5",i0Ti\+4j5I7<iRWXlr4P
9gEpgdG3E=MuUL+0Uc&@%J]AQo74B!R;*kh)cII+[(HkkJ%++]AU`S.Ii_@A5-\9)m;1,qI_,!
.6A18k6RX:*6:&s]A6d$f<fr5R3#cl4mcGs3PoT6XE--ksnB1@C:MnBJja7,'3.\=5gZlArr[
8N9(NKhBhK,=SJuh*k20a?;+0*kii/D0^^aN=!a4KEBe*Ga=I3&8g[X^_hk=(r;iu[Y]AME`0
A%578RZ$QUJ5Nr5MHKL8<gg;]A'2&?C[d:GLV:=XXFQA@YG:&O.'hk0(.,*sC.N8dHb&'h2_h
DO_tCoCtVem9$>OD5k&oTO+th?r`YWRTEZ@6nXNZmE?k3-8dK)Z6l6X%IM_!U0ZqD\1#AB?d
6Ce"s8SX4mhRp:5ru@+%^jB0ORVEMX,L=eH/gfO&I]Ao=\k+Q:!3b'4O(,V)bnD4Tl[B;C1uc
,4KbBBmqt]AiE`o=?cQM6$:Z3U_oS(c7XN\\.MP?pqU"L"Dtf0Mhjp:=X]AW8PD.pbf`gBLN\b
glO(QQ*g?9)[IEd]A>92Drlk3/XAe(V%4T-UFq]An'go)b:lo'X/4OVYL<>,>?Q+0.:kKXjmn6
P:Xu=\(o>IfOJe[]A&+rGFd?-oDg4TnCp!7LKCIK!knLdu)7qD-K`M7;&d@+"+UgoH95W#Uur
hOGXpSo(ec\rD;NUFQGZNCW*%`tdIb*\H-I9I*saeIt!p'B7]A1k1;;on"C<*7f&*nQJ1+UN]A
6@6<l1HCu!lr!1R]ADBe:<_o*g4IP+&"2l<*<iDnmK"[#-#fb63VjaGFN@CLu+A"-]AT"bWm\R
0</bLhX73V`BLl,W;n]A^LacMc76Te:=4+Lq2`?8M9m)TuYs[NX\BE:XAfI.H4s#\IW2D(oJ=
l:LA!G.cRl.PEFIl9hMkItHqk9Nt;9G,8UtXIKW`Q%ZZTIngL+[=;0/f(YgPMoUM6d>HpB0#
CrLq#DWA11KD0W1XUQ]AA'%ZpAmjmgp5DnZqOg"TR=*:@/seDO*.eXJncX^="tDBV60Xp@.RM
VVDZat7SGm7iX:&l`-r2g7*H@ku?lq+ZSAc87L9q`HddW)^P-<#53j'l4@DgFc91]AGt_TKp5
!o!%Jol+Z+85#a?1QSHMN\WcuNA8uRJu.=8l,fOK`PWq3+t6mk(`PUaLiJYO.\U1_^8\X[&e
m=@pfRCp>-:11e!Ubl$0=7sT(>'r++L$a_R8BF^acf]AZ'lRHJqBOpj0fI]Ae(Ou^sRHmn=GH]A
[@%!?0ce,d@'2Tb/b&Yeapg4n%fb:Z*--Q;g+R-/a\NbOT(Jig#6WYrZUsPCqQFX'*5H^9?8
3lP]AIVmqg_\r;G)I\G@A<d3D6q1[Te=Fom#Z6bYVG=b;PYaOXkOW7Z\Nidt^_i<er8!iKL_b
CgP$(oj6n;s\jlIgTH[gG@%bMP@M-eOAC6$VbE(5`LhhDLZ.*I]A@/[n_al(GKMu_;koQN[7W
=hiG]Au`hB$nuGAT7K3/WbI]AQ8aYRkEO`b7>oE)udSB5n.EA"hk,T#!]Ap"fZ"5i_tQ^uU:$dR
B^F'R&a)jA4U]AmGPl^=2aGF^O0hD4dj32Y&EdFeqpQ79&LUEW3,0ellZkPC9HP2q<f;MoTX6
Y0MbK)d&)OCtOnD:P**j!*irF@S)[F+7B.E"?Cctf6E^:`3VZdR'?Ta2rT/:"9-9cnB0=[5W
!9:Jl<FjrMpr2.\i'jLq6GL[XL*,S%)5n9ug[9Vpl;EoTa4VML]AN!uKt\R?MYQdgGF'pXXgl
Na+=DC]ANZ7:c85(!OuF[9@iYa6&7"2X1$D2Ao;:1)i?1M<o8%6k),mobp5S9d1`6>RU!Y4[L
"\h<2:>PEKdC%E8,V:"t4m-[*5b:,K:Sg`ZEL[i-l<M5sOCFQJ)4X7U4^Z#NXSb/.<e(N7V'
mi]A/\HG,$)[&6nVQ3*NjdK&E)=7'pO`E'OP<\r`he2\s?gY4R)e_bb[MI-_RqH61-A3#*MS%
ii6]ALIT)DdC@'#Gcg;G%9HKZ@=&ZE/;%*EZn**rAp/4/jLb'K-irm7o*=,e\l:?HU3ts3.L:
QfVLksnO2ap#L')@[WZl>,h=kKqS%T/.P@Np`MFLf8AkQL$niYV4qKKis1?o6<;,qGP?oBb'
'$-A2Q3Xoodk.aQ#LV\n?/SKF0Oc1`GBu:[VICu^VK]Ae16UU0#8YiCYjnC2FsU59Gt(/]A2WP
.*Dp/HX7o1r$SOg,d[P1lM6k>AT6iIC0>j4NcOq>@MAY5F;Vek\i3<Sq,YgLSQGW%4hoTSJ,
S@GQ7`[iT3[VF;g51M]A14M=7@mL`fh;\kpR_#eTp+61>siG\h?q$n;;gNVPf\_Z(j)mVJrQ"
I_3aK*-@FX>eMG?1L:Qis=8d+"Z:+6UFb2u91sS&$7`Hb<lR!Z@YqlVcp9'D0_T$3a5.^)V2
q+?5;]Af<'eC:#Y8.*aFm<=<Kj'?sd"_oFHUB.sGi%D!EGI7D1Ec=mWS!G1g,sJ:,KaYFK+:n
>ttEF2j)Zdi#DX<5H'a#s6)sdg?s!.f%_=Z&fdZ$2jP)js:?WJje^&5l0'h$rOarH^!H!RMT
3F_0r2tRXL;.:1WJ;@Q0nPM6e#ndNuFAJT:C>5rsVnD&d]AsR`&D<-df@`dQcP[VsD\CCSR-(
:8!o5^Zf-F\]AI\*[S2=<e-/d9ejX=3g.OB'Ah0:7m8E&*j#loSfhKH\q1p1%om1YlH$J<\Hg
;Ech`bs('%@uL>Vc^-_#B:g(s&D;o>nWoH*MqH)5T4bh;M9gEGNo3E>&8)[Ul)/n2X(7jm8K
:eh8`(8R2PGj)l/9I3jKZDl\3l?@C!HS2?B0YF"N'ATH5+EQsnkY8=hMhnC^+hlFD8_YP,fe
DCKHFs.d`:=TrJE/8#d#4n0C1&)E7VF.YQ%sMD"ln(V;2aVtMn./8dMp(]AL;l4<G<#]AQ<p/u
U/82s'nL`u$7I'D#Yo)!qKi_JG&?a#\Xl^9o[D,d-QBG/[2mqC=+8/*2f\=@&$L3j;#8M9V8
Mr5C=`Lt[K$,&su5XlB8Eta"D%/trGCP\9`#D!bt3SMf64Q=\d_G;C?#Q>:RCpn;W9I%9*fn
r/ur=Q/"s&<LT3QEAa4X:H=dP:<Z59Z).Im/Y'Q7)CWOK^CR^H.@GU&-H_7guc'fQd#6fhsn
.6['GJMoj#cJ0sf^?F^f1FB%4E2LN2ZhrW@)s1GF!s2m:Q(`Ro;^$W0KCNI3mOh3,P'"!-L)
&LLMJA8P0+FaDK)'<"FqLpGK+cC\g=<W_:.4@`HLK8'S8FVcXXI=4q`o$HCctWEQ>[jk"<S)
cOFggA</p4#ii@5*4Ta8#?`;lhohumlm"?"WIRO2B7>]AdEQWotIm8dj3H0c:KtT;ZH<'V20.
g-Me0s'10;Y:%*oOc*VXiYe'`'5qQJ'$/p6"sYNSI\,<!;[CH_^TuFS_ab:S=%<Sk#;:maPL
D:Ne"@MF?.:mOR(n^;.'NI:VVc<kGa]A,+-l(91GN*3-gtu)MoW:["jr:-/L6'>Ooa]AftRs4^
Gi+,cE_A/9409bbKVUTHH;XdA;pc:,4K`(("/8Tto:55HmN2+'m#?lpGIWINta@5;2jDtRB^
/tl;!*H^8'6%W0l!ImN)IXnTS;dEE2%/de(eN<'gXhh^3$)uogE!i&+kGM=_p:(K?_T/)Ih4
C6((bd?>%MG^k1#VHgYcm61&MVl#-WA"B`#Lq*Cr#Is&!F9#,(MOfsN=-#r@McIr+5uE]A:17
q3+R;=A/tR5t$m4Sm_O1qbej-i4X"i&/"Y42(0a5H9P&Jo39u#Tk'1Fl_6cYF#Cf,8`(c4;+
WhLrP(cq[!H3\@p6W2Q=0e:\Q1\I"ZO7^_;U_=s)PsUfb/Tg#ho"d+8o*)lQ#egA-.(NWG,_
20Mo[3rX__J4UYG(>]A:E(,5rS)s4BQ)Q=_)OdbRYK!%48_s,s_l*Vl6cr'nM9U(.FP6luQhm
fih6GlFnO+fGN3YE+)2[j>'5A=d]A_d)"j+W&'<@gJWUJ7O8LRn:)kVKGOXeR&h'D0HG7L"W7
T!E[^>T6W0]AhUfs\oFXIO;+jT@7KY@=+'&qC"DD/cUm,--#R4;h=Yp;K]A(-Ktk/^r4-$2L3A
oc>7Q5@bJn`iRYZ8MOF]A:a[Xd[4SKVmrs,k8hMu0]A)5[5Ho-qX/"DBs;Ps+!mqr^`O5'QHHj
m-.V0r_)+W0A=mmcKZOkn221B3V,4)e&Y_7KN9aE"sRg=h%+8IY24Xgs`=o5?M`-*0<Q)Yk]A
Dl\YYti2tm%kPnfma/f:cs5295\3?_b^\.=#IsmI:HmAG5U;+$u1n6!^MdIV6ro6DoPEGc'&
4a&05_?('^\R%L&^@jnMuN]Ap`:"`9RD;gS#iT$b2rO_RV/B[j'bok235()@QN,8-?U!q1&YH
/C8@?^Z;856khn>-!ZsncKK`d/1CT6Wl^^+dIMPibI;A6;>60qL9BD5hV\&QYQ">'Z>pBA8>
.P&X7Y-mUJn+sJ[pICnUa"m5a@7jDu6ED70h=/-BhPOJXrtYC,haIXpaO_,nZh338,3cYZH,
%k&7G1k$ml7p/@Vu.9l96&)3i)ml@t'@#K0$b)p4WVG5<IGDM5ou3ABeMerQgdcBs#h?[33%
pM+)A=s+dn1D=TqhLqj!^qu=U7OT0@us67RGL;:[Vj[i[ZbW`jm?C7%+%Uj06RhP]A_p6QCkS
h+6<H0YhT@sjJl9C$\(kP+q0OfMg-a'K&T[fu;76IS`39/_#e1Rb(!)gkGJ=]AKsO?#EAR[I'
_okDp"ccRlO^XS-`,dpG+NVXaFS\:EERrM+g[UJZ&2oB;:f?1oRBKJ\7um73)dD+r"hpArQ=
@$Sp+ML_U0;O;s&pM98cQ]A8,iEk:tf(*7@cEHV,MMcrb!^L[7qs3D"04lA@B+uIMS?us%=JC
O2:2bRj/$s*9X`i:Qk):G6eJYKl7L-kHcq$+I**'T5=i$8!CIpcon!(6BRk^5`Chb0=2Z`c!
SC";C.p=IT#pC9u4"ERtl$$RK;+%LCS$Zs?C47`kE$isEqI]A(A;^7Z2d"0/Yq#S[t5*PC7qo
<WIM4st\rY5RVa'un(^$UBu*]Afo+BP_Tf'Q'dXI;%;:@_iOS!#%0G4j2oRI`.O<R'+=BU>-`
a/_jsj^#Vd/[_N?OeMdZ<V-$L&A1Q]AB(nm3hfNJ\O-\Cs5"lVP2`n&q.$=)aF4iQ?pFRu<Rk
n_=VjlA!5WNnhKOm_)+]A6B3LVGN(]AMM_C)T#:_PG)qak,lk]AsB;;nBR@+1Wi7Z$SU:uN(7iS
%AlYW]A4.l@[3q"(R.H-jtsIe$_IB*%*GAs4`XI2;s+S@+ML$4RKr>T@&RU'Iu9K<%&S#$V#i
XDAkN"&cVTL4@"?P933BqC"/1&c5pQULnQW3Y&EXK\Q[3"_54kBntX#Dk?.4=q+fKlDY04Ir
7R[5M!;_F``;D<e!m$,_Dp*U<OhN.Xgo.;WnGok[Hi!3E3"FAWM-Vh]A3VokAsM=6[plk'*LZ
@pS;KVmiIV@?/@C:hZ>;"El:PWYF&%n9GK1^mG1PGjDuRa#qY,RAIJpWNha*0;a>XS"l+;HU
kHS?!_*DXLo,Ne4,31->pe(W5BX*7))'33'K(?r'A89]A[jkO/,4,(2BPJJ[40)*ZCTE?eM[X
!VPUZ5AZ+1$!OHe6u_-'2s.TTk`^k)&)_%mI7G$_pLi#b'3[O6b(a74FNkXu5!_`^qr#_03+
3P2EVGMFAN0nYE\ZZj%B(L2[?WgD.^m=YbM<>o[_jIIrP:Z=mSX09tCMG>b@"_)P>%!a1;:&
B)WLq_9I3/f"Qq7H)CV3tR`Y0=N0E<]AmHkE+eu/Sh9:?V_Hk;3,;%P;dSY)8)&9;95$f[Ba]A
*TatoZHh5Dhj[SAB)*!F7c5^78:NM$$E/=+/V0!gJ&2ub!b[$MbL3sSYl^&l-dpHah)7T1tY
Rnc$Y$&_lt$J0sFN)9'hCK.s_q7L)OEXd5dHZTB)CJ2!lj$cuY2gK)97)!FM"MPEZSPRf7hN
>&AbX8:r/_-+9K!Yn6Q3[B2cu:9L+L?PDIWu43bd`#]AMBEEPLA%mB"&"@J_'-SQ7<gm*(lAr
Q';)Wp<VbG@35_O8\SJ+(I8\e^TG<"LYB9SL"/pTP]AHMT))=5M->s[X$)S^,ZEs=W3RlJ!i!
"TB@r^#[s=M`e?*>?XPS4q4]AeZD+gaH/,=]A:d\Gf!U:+kIT5kNd'?c'ldJ1kK7=s-5>%]AR/V
GFm+PC$@3XSBI+htrA$p"n*8/FsWmt=N<0oECX$_*>eCd)1)jlDG2WPeW:F"($1O?X#?&2HY
UBZJ99(V/7P>iRQlog>Bq$\kBPK`"ioA)8SneYY;\K4t"S5:`%4%s1`=1VL`NaXXu2-ce<:#
aond-H._/?6d`iu"fp6"APY7N)p/@'K(bD@hK*ms]ABKqTiJ0R6BZQ2,6ehL;EdAM7qgtkPi]A
sq0;qN&@iUhZt="VhsJIglNLm0Z_'VGX+Hno?Dk4+*T%9s$dN.9RZ4%u]A.RjMLuY^:mTEur%
6B:jPV!r(Mu$kf&%,5Y/,6ic8tfPUYoUdfDB'ljYc2oCZVGouj*OumCc9G`0D#'?QES]AOp_E
2-7RlRs]A%+q#<>B7@q'QLlRO?P,n/rHoR4N)b.mRp]Are):bRRT[B!e2YOdDtY#RmqSPYe^j8
W#/?9h:t"d_g;PK7^22E%Q#rSM^rMN3L_.O0#tX%A[k[<o55A2[b1E>H'/C3_W65?KP"\>EP
bZq")@H2)<c*OhnAjQRl#9!C$2";NsVD1GH_fi1>:H;hT5[H;6G'Z+kY!eYf5a]AH3YEV^r%R
bnPIq'cW'P%`\h0#-aL0!__V_abnlI=&)k!)"iti^IoahSNN!h*+"nu9%'V6l^nSD_aHIGIk
)82E>fTfIZJ_:uC&BCfA/,@3@u:Vk+CSb88sgCa-!%e<B4*Q/\DRf^V[ok==D8[j9Nqm1F(-
'(7&nlEonR8sXO`SXlP/$u!F:_h?bKt'5aq`rF1cEdm,_53gk15XG8i%@Q_KD&.sG6A]A-m57
`LFctd$K^@P?fX:3NL-+(p-A\$Vekt,>d8S)ah(SQoeQOXkqgCH9Y\n\/<8o5J-1GNX)ilgt
D0P6EPs5*=,iT0IXfP$lYO=(.?#QGSW4?3%CF#VEkO+$po6sN+VU0&nqk?5_Pgb9AaP$&)l`
9Fu:H44-#MP(<Kc2RgLPorD.l)7Wl3U,5,(2=P1!Zc#d]A)a2hpSFGEbqkec9K1s\n`!=p(+d
fKs?Wuq6b]A9[-K6N'h6.TJA>m#QLV!Xf3U0P95Gp!L=(NMQmr?NOe.n.a2gS6Eh%!]A8oH11Y
lL(pLcX;\SqV9PC9K;>on+m[X'DlY^e@di1k%mc$)gbT599#`_"u!B[S7/Wng2;OORPF73*0
h\QL23hqfJ(n`6_$bSO0_V;=O8KSt2SSbT`0JMpKm+eQ,B%s@\^PTc/0$e^dTYq?Y#f!UT_8
j8*\8q@HEZsZ&b_JOZ<@c@U>RBjp^FN2u#27q.mPQ%,?1rnQ@tCY^6'02pR[5#WVBft)`]A(D
t3]AG.ULWGN*:YI4&BHI8Qmo0PIY9p>s@4PJ#*d>SYB#UmOE4A%$H&rs84eHN6E?VPnlYB(K@
sXuHjoAig[ghe]A(E<:F<ST.]Ad3f>gCBnF^LXC\<R"/cO8I:mSd$M:s&!!P`*mEGD>2iQV'uO
F/V=Be.%'T2,>tTnOV5#;g\NFuF=F+7LN#oUI`qB%`_CU@u/^1HZ?Mm:k<FHXt-YA@>\8*!+
M;GN`,Bl3e5L*Df,3r(JUX&9EfG>h63'^c\!M?6(h-7l/EcaTFTr#f"rdrj?F$e%P<f<dbSQ
?2H>km-I5=\1EQ@[k#mB$gNhTm-0fh/&:_M3Y>/V40h(I`ODGY0pRcNl/pDbgIA0mPijSd3F
_o9cP'+#9W*,ItreH@a%8/n<qF;3'^i)'*J3/K2&f%%na1i`b\]A'X!$oWbRUjB:c*H"mm`<_
"(aqcb\=`#LC`-g#h;.N7At)c)a>s?V;si_MWCjmt[(Y%AgtroZiUW9]A[5)/!QBiIXjOD!=c
8&\bCQDp!;;BBtk/_eaJe=Fdr3Bb_Z?kGtIT@<L^'8UI<U4%f()aLM_pMlYQ>.AqZe`r$iYB
)X%sQ(N:S,b.#M(%bOAsPnn/0CV`mY&>$^""X0@V2@%*kU^305&@(Y.Q<`rUYo-nNc0l!V+g
ESt?@"h[+oFp5IXCu#AVXa(@O683V,mSDmTd[bDklc`$.D@fcP>P/#&;@63Fj1g^J.kZr,"k
%`:S&RT-:Q"[fb5bX1(m-St@Jkb;jMeHp2d+1ga(^\QIjc3M'"&k4p._gi2`5#/`#_<Cch*%
5gp$'Q3'n#G,J9R#57.F610MgIe:O\L5s(VuA1>j8K1J@*Goc[\'-;i'Jf)hPI@;[.Y=^EHP
eMUu(#qK-.DjL/Y/':[>pR=XW]APgd3^f1-j+X8rK-8"hPq,4Z.O="kpkXrSkWZ6`>`]A4Neus
NFo>cQ_RGBMmg/goFVAc/1d3V:ZYg21L@oT?`0)iaHqAR6n$nf]Aa,BmDr_%i%X%)djP^jq10
I%gA8Q>$V;CC&9!;Qh#htK7WuuB6_GcR-aH[m%KBa#_WV`4*"oiTs(H"fo5abA0'T"#hp,Yq
"q?9FRCVraQk4*.\Qtn$<_S]A:%ki74'G-a5GBm+XgBh/1(i60m*7(?:D6$>O]Ak8i-TVQF'c3
#Q@oGhoCG.nCZM]A5d8Mh6N-ukDF&MJ?8@,h19%^OQ8T0jCjY.h\L[6;4:N*^tC<e>@o_`oJ4
Qd]A(XV@dfRoE@in&=?)70P!L=:8$M3S%rI,j.$2,9BdXuSLD:(Gu,;uOiV6UaaGN,NcAofug
IGMM]A\hqr"4/L6KPr@WDU0F,W6T`)JVDqgMYk/Fa@%Z^CL9/Z^,P,AQL3DmHFT&+<CT*K>[k
#-1ChqLd5>bIEk+RCh1EWO8.=H8-G!#3Kf%M'Wec":a0]Aq.S/HV2CBFUsleS^2s)\fg_Vg5]A
g!k%lKf0R=_TacTD[/\$-/8-aumk'A?-^`8",a\oRVt6$!hE'$.,>ur=^L;QHfuUT]AA5$!?q
'$4"Pn%A@157Ah2\NPX+Rn4)0A6`$&XlT1=>Y(CY5<6U(KM1nY'$M%"HPP-EIeSLK&9?jWk>
.O@l/Ia1n!MKkWF]Ao:[+2pE\_CfRPsSDSdp:[hVZsB$)2UfYn!7b4KDP]A"uL>KO&/FW#8D-e
N<bd/6[L6gjaXLVG]An:o4=q=Gnf=Fp\n,Rr(Y"M(c_C@d+G+0cH(k.a(NAD]AC?OPj#bT?J)t
?<0oW'EgBpa;#!8)emWZQ8EG.Yi]Af%lHa8.:-"YqH=N"6"juD4E!]A$/j:VN^h.7Oq/$5G5U/
ODCoSuW;s06<-1@IHjV"5*f:[-np(po%k?T^`=Q&SoB>^%/YtN@f[e,#I@QD1CTh&hdTW(Oe
/b_CqVbb7KMbl5CRRtg4kKlqQsMn18m%QPqbufBM98#+q2+mE]A='\>cL<T%CE'$FmGTYMH".
gUc+=u3k@A:oO"cI4hAtJ/!=I"M3;*R\Gi'MM!XtIP*IKPm+D"qOAK7;>b5t6DCYM%Y[6>/Q
,tuOP]AXrk+Z)!e)<n_$&/''%cjDrd0(7L.J!@-:_B(^0\X&[]A-%b2RJ#Pb/bH]A_:Q@mj&LWn
@Q"2B`cHpAcaU9K;+kjc%\DHbJ7'O)/DO/#e]AZoE3+DQV@]AKJD-Oa&KD^u"#hYO5mbhnrG`\
2:aB:PhVrb72GZP97"RLNO926?I7iVFE)K;?Ht7toJo3m<n:X'%"SEB(HuJOm]AmWI-39+e>f
Ykjb7gG.:Xe[Fo-WY*MNMI'c&fZf;fS#BBT1(dGoZdt3UebB-\35L]A?,ff.fOe"H-K;aG4Gg
4cSiH!L;pl)S+fpNDr@>m>.*=!&^gY"F=%6:)fr^MlpF8'h=t1/',uPNE^CRJo@<(-FHqT;2
O)5^t%1VKnlUG%,-M45B^2\@\di'CMb^3<uf8\FOUO0_)[6A67+B']Ade:D8LZN%h(05:'Ij/
n,34]AX<?=dfR'[:a^*&*"0CVQ[PCBOBNl+<R/"5gnm;iOMCB_!SFu_>n^]A\eC)8%so;W`n0'
P(eu"CQUqSC6,!f$Y8q)+U-NpAl'ZXAdO%0&8@VNW+`_X2S/*ZsKL,;E^_id3UMZIi;TdM3F
5\NQb?Q_R6n5L8qP=P.-Q]AC75O?fd!Hm1>#$n@pVm7JMEt#E3aSHkqQ2K2)_d+@6[RjniL!"
=Ll3M<T3_<Wj31WWsf)*nLTVMn9_3Hc.)V1!&>nl2@8!,]AiV2d"U7Lcm&gue(@lr/+7P>=2:
JLAc6Po:;@Ro@M&f5"-&S[i=?!eu?OAn.n)e\6?hN&OI5a?Iu7hB&eb4=V_1E?17!pFO;KO*
3er5*CpQ*ap\l5-4?%fD'CT?>A,JNhY'\'%t?FS:qH(T<=l;\M:e&8?TDETC2YXNRR)92($R
Vb..ajjORfel,\H(cc43<?J>Yn;+5E"7PhJT[YI7#a0KBJ&@a'i9pa,T,CldM6LS)Xb[DACG
D[$0gsR3QMuCO#X,O]A4p=@.Lf'^KFSog*k4Y=o>]A2SF_PqM<eG[?RuA]A@D[_RMB(j>,mdplo
aJb=Pq\@WBHphNQols4HQ2K9,<mAF6A\pPU*H,37gFLN/fk!k7,XQFEGVXO(eSm9MK1Pc4n2
F_)L,pjSm0puA9Oh$L-4UNtI.4:N(T8O;H=8'7gl#]Ad0^dO1Tac=FXsr+[&B!l)-26L_[D%(
!IYA,0-,2/c]A-C!aqhrM_]Ais.-(Wqu(N5BbM8`.`u-sIVjNBYso4nKnVMtrr?s="_UEMEZ_@
a[JlH>RB1phN"8A26B&q(JrqC;<5./5"?kCR;hdBu+.dGaXhnT_S6^jF.+ml'n@Kcrd1'?_P
3Vl"J$LpIETG\B.UnW<1\H'Q?J)2!@nOI#\E,^oQ1L`=nNF4GWD9i;?</iVO]A3]A:qqFJ=JSV
-%a^(10i*a1#s3Ub8s/NU38Bfo2IJ>.f]A>Jc,P<nHaAs,dlD\S?]Aq#!4kaHs3B!COjL\>08u
Ym,#A>=33eW_g8r48>=+q-Jt2W.rlMDp86'l-qS<>AXSRqlCUe`91khPiVBUm^aHo$;,@-"8
kSNpMOL@9b=PH3\3aOp<;V$6]AiB)k\'.ucEFn\N'[WeQttW)4c%u::epM<>kF5RaGBQ9s#`T
^NdL^c]A^tmpKH]ARRd;JpW"FlNrmhtEYTMbKf@K/B<oV`7Ab^=FO1Tq%WfeO<1r@aRPjo4Gb0
+`VTV)KEBA,EBg[$#[qcPu)_V[D^M/*/<Krso~
]]></IM>
</InnerWidget>
<BoundsAttr x="0" y="0" width="480" height="540"/>
</Widget>
<body class="com.fr.form.ui.ElementCaseEditor">
<WidgetName name="report0"/>
<WidgetAttr>
<PrivilegeControl/>
</WidgetAttr>
<Margin top="1" left="1" bottom="1" right="1"/>
<Border>
<border style="0" color="-723724" type="0" borderStyle="0"/>
<WidgetTitle>
<O>
<![CDATA[新建标题]]></O>
<FRFont name="SimSun" style="0" size="72"/>
<Position pos="0"/>
</WidgetTitle>
<Alpha alpha="1.0"/>
</Border>
<FormElementCase>
<ReportPageAttr>
<HR/>
<FR/>
<HC/>
<FC/>
</ReportPageAttr>
<ColumnPrivilegeControl/>
<RowPrivilegeControl/>
<RowHeight defaultValue="723900">
<![CDATA[723900,723900,723900,723900,723900,723900,723900,723900,723900,723900,723900]]></RowHeight>
<ColumnWidth defaultValue="2743200">
<![CDATA[2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200]]></ColumnWidth>
<CellElementList>
<C c="0" r="0">
<PrivilegeControl/>
</C>
<C c="1" r="1" cs="7" rs="42">
<O>
<![CDATA[<iframe src=\"http://bbs.finereport.com\" width=\"100%\" height=\"100%\"></iframe>]]></O>
<PrivilegeControl/>
<CellGUIAttr showAsHTML="true"/>
<CellPageAttr/>
</C>
</CellElementList>
<ReportAttrSet>
<ReportSettings headerHeight="0" footerHeight="0">
<PaperSetting/>
</ReportSettings>
</ReportAttrSet>
</FormElementCase>
<StyleList/>
<showToolbar showtoolbar="false"/>
</body>
</InnerWidget>
<BoundsAttr x="0" y="0" width="480" height="540"/>
</Widget>
<Widget class="com.fr.form.ui.container.WAbsoluteLayout$BoundsWidget">
<InnerWidget class="com.fr.form.ui.container.WTitleLayout">
<WidgetName name="report2"/>
<WidgetAttr>
<PrivilegeControl/>
</WidgetAttr>
<Margin top="0" left="0" bottom="0" right="0"/>
<Border>
<border style="0" color="-723724" type="0" borderStyle="0"/>
<WidgetTitle>
<O>
<![CDATA[新建标题]]></O>
<FRFont name="SimSun" style="0" size="72"/>
<Position pos="0"/>
</WidgetTitle>
<Alpha alpha="1.0"/>
</Border>
<LCAttr vgap="0" hgap="0" compInterval="0"/>
<Widget class="com.fr.form.ui.container.WAbsoluteLayout$BoundsWidget">
<InnerWidget class="com.fr.form.ui.ElementCaseEditor">
<WidgetName name="report2"/>
<WidgetAttr>
<PrivilegeControl/>
</WidgetAttr>
<Margin top="1" left="1" bottom="1" right="1"/>
<Border>
<border style="0" color="-723724" type="0" borderStyle="0"/>
<WidgetTitle>
<O>
<![CDATA[新建标题]]></O>
<FRFont name="SimSun" style="0" size="72"/>
<Position pos="0"/>
</WidgetTitle>
<Alpha alpha="1.0"/>
</Border>
<FormElementCase>
<ReportPageAttr>
<HR/>
<FR/>
<HC/>
<FC/>
</ReportPageAttr>
<ColumnPrivilegeControl/>
<RowPrivilegeControl/>
<RowHeight defaultValue="723900">
<![CDATA[1943100,723900,723900,76200,1943100,723900,723900,76200,1943100,723900,723900]]></RowHeight>
<ColumnWidth defaultValue="2743200">
<![CDATA[2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200]]></ColumnWidth>
<CellElementList>
<C c="0" r="0" cs="6" s="0">
<O>
<![CDATA[楼层信息]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="1" s="1">
<O>
<![CDATA[楼层建筑面积]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="1" cs="2" s="2">
<O>
<![CDATA[1802㎡]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="3" r="1" s="1">
<O>
<![CDATA[楼层柜台面积]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="4" r="1" cs="2" s="3">
<O>
<![CDATA[1054㎡]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="2" s="1">
<O>
<![CDATA[楼层经营面积]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="2" cs="2" s="4">
<O>
<![CDATA[1594㎡]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="3" r="2" s="1">
<O>
<![CDATA[楼层品牌总数]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="4" r="2" cs="2" s="5">
<O t="I">
<![CDATA[16]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="4" cs="6" s="0">
<O>
<![CDATA[楼层服装所属业种情况]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="5" s="1">
<O>
<![CDATA[编码]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="5" s="1">
<O>
<![CDATA[名称]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="2" r="5" cs="3" s="1">
<O>
<![CDATA[品牌]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="5" r="5" s="1">
<O>
<![CDATA[面积]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="6" s="1">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="业种编号"/>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Parameters/>
</O>
<PrivilegeControl/>
<Expand dir="0"/>
</C>
<C c="1" r="6" s="6">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="所属业种"/>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Parameters/>
</O>
<PrivilegeControl/>
<Expand dir="0"/>
</C>
<C c="2" r="6" cs="3" s="6">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Parameters/>
</O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="5" r="6" s="6">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="柜位面积"/>
<Condition class="com.fr.data.condition.ListCondition"/>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.SummaryGrouper">
<FN>
<![CDATA[com.fr.data.util.function.SumFunction]]></FN>
</RG>
<Result>
<![CDATA[$$$+"㎡"]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="8" cs="6" s="0">
<O>
<![CDATA[各经营方式查看]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="9" s="1">
<O>
<![CDATA[经销]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="9" cs="5" s="7">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Condition class="com.fr.data.condition.CommonCondition">
<CNUMBER>
<![CDATA[0]]></CNUMBER>
<CNAME>
<![CDATA[经营方式]]></CNAME>
<Compare op="0">
<O>
<![CDATA[经销]]></O>
</Compare>
</Condition>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Result>
<![CDATA[$$$]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<HighlightList>
<Highlight class="com.fr.report.cell.cellattr.highlight.DefaultHighlight">
<Name>
<![CDATA[条件属性1]]></Name>
<Condition class="com.fr.data.condition.FormulaCondition">
<Formula>
<![CDATA[len($$$) = 0]]></Formula>
</Condition>
<HighlightAction class="com.fr.report.cell.cellattr.highlight.ValueHighlightAction">
<O>
<![CDATA[--]]></O>
</HighlightAction>
</Highlight>
</HighlightList>
<Expand/>
</C>
<C c="0" r="10" s="1">
<O>
<![CDATA[联销]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="10" cs="5" s="7">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Condition class="com.fr.data.condition.CommonCondition">
<CNUMBER>
<![CDATA[0]]></CNUMBER>
<CNAME>
<![CDATA[经营方式]]></CNAME>
<Compare op="0">
<O>
<![CDATA[联销]]></O>
</Compare>
</Condition>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Result>
<![CDATA[$$$]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="11" s="1">
<O>
<![CDATA[代销]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="11" cs="5" s="7">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Condition class="com.fr.data.condition.CommonCondition">
<CNUMBER>
<![CDATA[0]]></CNUMBER>
<CNAME>
<![CDATA[经营方式]]></CNAME>
<Compare op="0">
<O>
<![CDATA[代销]]></O>
</Compare>
</Condition>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Result>
<![CDATA[$$$]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<HighlightList>
<Highlight class="com.fr.report.cell.cellattr.highlight.DefaultHighlight">
<Name>
<![CDATA[条件属性1]]></Name>
<Condition class="com.fr.data.condition.FormulaCondition">
<Formula>
<![CDATA[len($$$) = 0]]></Formula>
</Condition>
<HighlightAction class="com.fr.report.cell.cellattr.highlight.ValueHighlightAction">
<O>
<![CDATA[--]]></O>
</HighlightAction>
</Highlight>
</HighlightList>
<Expand/>
</C>
<C c="0" r="12" s="1">
<O>
<![CDATA[代售]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="12" cs="5" s="7">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Condition class="com.fr.data.condition.CommonCondition">
<CNUMBER>
<![CDATA[0]]></CNUMBER>
<CNAME>
<![CDATA[经营方式]]></CNAME>
<Compare op="0">
<O>
<![CDATA[代售]]></O>
</Compare>
</Condition>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Result>
<![CDATA[$$$]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<HighlightList>
<Highlight class="com.fr.report.cell.cellattr.highlight.DefaultHighlight">
<Name>
<![CDATA[条件属性1]]></Name>
<Condition class="com.fr.data.condition.FormulaCondition">
<Formula>
<![CDATA[len($$$) = 0]]></Formula>
</Condition>
<HighlightAction class="com.fr.report.cell.cellattr.highlight.ValueHighlightAction">
<O>
<![CDATA[--]]></O>
</HighlightAction>
</Highlight>
</HighlightList>
<Expand/>
</C>
<C c="0" r="13" s="1">
<O>
<![CDATA[租赁]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="13" cs="5" s="7">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Condition class="com.fr.data.condition.CommonCondition">
<CNUMBER>
<![CDATA[0]]></CNUMBER>
<CNAME>
<![CDATA[经营方式]]></CNAME>
<Compare op="0">
<O>
<![CDATA[租赁]]></O>
</Compare>
</Condition>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Result>
<![CDATA[$$$]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<HighlightList>
<Highlight class="com.fr.report.cell.cellattr.highlight.DefaultHighlight">
<Name>
<![CDATA[条件属性1]]></Name>
<Condition class="com.fr.data.condition.FormulaCondition">
<Formula>
<![CDATA[len($$$) = 0]]></Formula>
</Condition>
<HighlightAction class="com.fr.report.cell.cellattr.highlight.ValueHighlightAction">
<O>
<![CDATA[--]]></O>
</HighlightAction>
</Highlight>
</HighlightList>
<Expand/>
</C>
</CellElementList>
<ReportAttrSet>
<ReportSettings headerHeight="0" footerHeight="0">
<PaperSetting/>
</ReportSettings>
</ReportAttrSet>
</FormElementCase>
<StyleList>
<Style imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="96" foreground="-16749643"/>
<Background name="ColorBackground" color="-2953990"/>
<Border>
<Top color="-1446671"/>
<Bottom style="1" color="-1446671"/>
<Left color="-1446671"/>
<Right color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="ColorBackground" color="-854279"/>
<Border>
<Top style="1" color="-1446671"/>
<Bottom style="1" color="-1446671"/>
<Left style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Top style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Top style="1" color="-1446671"/>
<Right style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Top style="1" color="-1446671"/>
<Bottom style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Top style="1" color="-1446671"/>
<Bottom style="1" color="-1446671"/>
<Right style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Top style="1" color="-1446671"/>
<Bottom style="1" color="-1446671"/>
<Left style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Bottom style="1" color="-1446671"/>
<Right style="1" color="-1446671"/>
</Border>
</Style>
</StyleList>
<showToolbar showtoolbar="false"/>
<IM>
<![CDATA[c$FY7;chSb6`F*9ecDbEctW^r_#YDT(tr`4:/FG[L,e-WJ-7(f"fbU#:f%0)#fMUX$7%*U!$
OWn5_LC_L1imZ"N[]Au&Ap*;2%76h&N[Rs?,,k,j3tD<leHiAIJ.s[Z_)Y`0)akBH01'>1F>h
b1ipj$)g>#F1j.uW8X%-BV]A\bNdukJ?RUigUbJs#EK^kji*<D]Aa;_GGdm%.@kHrbp7aWG+jV
p8Q!moem3n:L2P<8(m^e>[V?pO2?#J]Aj@j&eA:*^340%Yl'm7h)dlL1-9^JE&!!]AoLk/]ANdf
P[EF,8!L$Xu,^Bi`b31K50+1#)LR?=miOb9Y(%k6f\I3WNNNd5ujq0;,Z(8R9&Lp3?CMCY\d
O4==IXKiSgoe9_&;>!G*NA%]AomoCWG3lD;\=i\Q$P'>?a=e:LnQZ2$'&^p@=J<TW@.l9`Hfg
9YnYs6s9K%Cs]A%\71CT-B*5IHt0L:dK6!A3,3CrUkk>?IHs#n2FJt#:cu0p]A<2DMA.K"?7OY
c1<N8-Y)`DhM\=`Uar3Ea6CDI1?XLdD-ZYs!%Tp&O0+WL@FoWMu/2mdN[B._h?r7)i1U%Y%!
BjJ5DZ%dg"Tck3Jc*"G6VU$V3%j:Kk@5H.U^l%n'J(pqTGL57,_5YKhF6#/5g3qpBuk)mQ"R
TMZC4>\Pn0ID9)2n9e(RU.=1KFq^:KQp)h&OVfJ0RaJEH^&SeF,m7g%Kr]A$fn).m/`qd%;+.
-FbZpls)c*G]A_4q31Hpk[ec85]AY4u')4S(@2.bB?Mn=sa\dRDd(_^jtk0C]A\+iTm&SW@l6I9
m(qgo0Y"=LhrKd>_%X9GNAT4e!ImS/XT,\2YM14HI.I41ec[3V'*LM\nH<g6ulmU]AUPUTP"j
C2->.H<NrX(#U$]Aqr'c%Xn9:ppY'B>IocF)r)X2P3+s,!rO+9k\=Ll13AlGRC5U'aZbaVE!]A
MY0i1.H(.4Jt&6+WV&Wf2?A3T!OD_Gfn6iPU7X5,N<Hp1'pAd@t!r+.r#M>ON$1oROPpV_#Z
Cl&MPHdI<XKV'ScM`,8<_U0\bHG\X?"!kB"Wn3+'fd*OPek"1k;a;Bd(R4^QdblTP-43'N#8
KRB6YOkc&nb3oXMN<)IN4TNC@]ACrP/GAJ;Z8bEQ>!.42q=4`:";3VDklQ3,9.InWA>qjm%`X
).f>AEDYkpp#Si#W8NH":%<@t*ehZ6J;4.s<%BP[9u(ZnL5upbT[M18'$22imFGl0K:JVTUX
U(TfN;:'tNh=6&@_$FKei(B[5dBni`IM'/L\X;c-co(h&oRh5LM()m+:s,WpAlZsap0iu!-6
rd=EBJjo34rSFE#)ugIN=T&-=n<HfcI.\QE_]A"<Unk)&Qf2BEfsBY(oNb\Q;sfB;eECHIKGe
q)hD>jfV"'<+_fIuGi\-Ao$UajJ.=2X6\?G$Li<NKA&aQ"R5gn"\Jd;nl%J1b-j2u,8l,-VK
Q0iDI)"g.IoKIV@.,&+RR5L-`P]A:EuWnN&Y/MNCV[@8a?ZmpI<h9p)H73f6q^oSETll8`'oE
0RY8faWd.&#.erta)f/uUZ(KTaBmQ#)=5QVoOtk"o\<4Ieg9]AE[4fcG\h*X=gIL`%6&YEe?,
Gf0^FOp,e.=Pp\nilQB_[G>Tekk&o-^_'#q&Qe1NUGrqmo)oN7WjYf2kWu7^0(i+nY.dQ&L_
+Ls[.Q]AJP2_0OK=hW1a`3``_D@$ni''&))@HGFSc.Jh58Ok8X_%`reB=DYnqlO^qTSCH9mjS
aiTlj\&#-aFa*Z^;)@>%[%"M)?732IY]ALlkG^#j5?;K>*$^mgM=D"8ai?>/,^BTe6L_\8.2$
YX?f%%'=W_2XIA%r$^&+j6<OumYJT\KRdSRS%B(WQNOX\SOp)U\iBWcRBG,EYq@PAG#hHoWu
!ghL[s]A,B&!q'''H!B_tHZ2ld4pZTA5\,#XtQ!&$9ElRSf!U#gBO-K_)Y%c<hf5SJH3Q'Be#
E<ssbtp`RH%=`7$a]AL>PHXM/)*-."E$Nu[)95KJ@-o%QZm3C^q9CG.sK7Aa[]AVUo*=C*jWPh
"Q(<>[jNI=:>MGRm<rY+q:#anj$*l_5/p-VP@uKpI.Q=EnKI?/;Ti(GBM2-**upOc\B$\i#0
<dYE3OVUtV^.`e_RoQUL1E,)c6n_?JHE>DAM60gj:>K.is;QHe,'bs(+7W?-_1_/Z5TS)TMW
HZZpE\,j:6AZ4Y=5d]ANPOZ#*K<'?Lt0J/)Pj/-/IK5FjPDIiI'PBXQ?&^ZU_!U5Ui1/.N>3h
A2a$&US1;kQ%?jrqi^Kpq[59>J6hq>9ie$]A1]A#htMu*<I&ub413L&(oK?@Ho%h$,gG@>*J,F
K7\2K>p>2,f_d?89V\tsH4e77!'o,:RN2_pa<^i,bAPae-ReIGT^_M/,R)>LrcrhD<li(`g/
%Da<[TC+U^M/Q=Bg.:@h?i5g0X\nV%h74$NeF3#a`++hpq[0EGOI"R'P"Ao/YPVo;q0OfD7h
8?OOR*r<97GWE-#+`EBPjY5@O#II/'eiZ!L.*lOU=9[ine:KP=t_H6Brm-I;U@D-o$YZg#np
\$QblA]AUS(FJA9%]AjMTiS('QN3'lc)fjQ3>QU2GB-5lBfrKlsS^4X-?WlP"l6t,X>br5u$@Y
]At,L;rKjKWe2l(8i1i4[lf8`mRkbkirT-R@98dT_op5I(Y+$H0Z/`gSj2KKf'a]AZ*bf(b.mp
Y$rhKuW-@HM(Kqp1"3:QHQX=qk3n?Y5n6C-9#I>u8_@Ur.De)Qmhu=&O-s)t2&s"<Z5La'si
91\7.c$]AF;^/A#'Eb6"O/&Yir,O!aC?/54S.<hYMDf8Ue9&iU,qu=ZVE(NUai2!t4fU40AGE
h9lGO'^6Qc)uJMZL%ki-6l8M0AJ8@b)A\?iD]Abr@L;Xi`O2>P"eJl]AFUcH/.Gn36b?g20.'$
[7st=Ib=8&$NJjQi6#aOA\j]AXno'UGP;N/oKo.l$*7+Tj]ATb$V?pg2;6gRj9YEmSr<'??h`B
?SQ8c*qAJ^MYsEhS_$hJM%"6)4o;-rNZ-"Ke9Y3:M$i9&qN:"(_fV[q*SmK/:TZJXjJ(O9q=
HUHg^e.HJ7BD@ZS_e.$P*h6bf[fj>24+]A6Zs)EV_G-Uc9l3UlPuN;^<VX(-Z,F^jm6,2*]A&Y
s&aiHLTU=<60jjqijq'2P?'J0^M+Cq[DeX0mb"J2-!-=Tmmn*]AIhB`^DcBlm(^=W8SsWn"sq
)Zk6b)^YNiKbq$%<WbL9t50/Bli*1GiBH*fG=%oMfm)rZ?b*p"4XG5<mA&\LPS;k&02#;AV\
1Qc"l*-,qcI%u0O00h]A99.H3cfGi5u8Hm*19_.u<W-%6d-?5pf1XjZ31CO"RB#N+F`U=g7*u
GoA-V\Zd7\eShFF!pOhbmZ6Z`&ub#/7g99Vr06Y1\Tj]Af3@pRU1d4Can8Qe\cms66L(S^AQ3
OKuGN!_gOp\qU@c)m'$.Rq4C,4,`Z0>\a\;^7BK)Wdi7MFP6H*uI#!pFMd+^!E25d#hI':jC
m#")O8eufgP-@#.[7J-g4+7C8'&e>ZJZT2ZIJ'L(>P3I;nP(Idn>iP5J88a6L8l$lM-)bfd!
ROJV[jY6(:9gRhmnc,[UY)=XG,kj^(Lo/YghI$if()FC(IJ[R$Nj>M?NI)c+ipoS9IJKDgKR
#c?)ab:`_V4N5W.G8Yu/,]A'brZqo&SFZ*+iF`0\XIWVnY<Wbf!0HWnl9.:D/f2ci.W[_Cu0&
'Ei&A>3Rb>4kJYPbB.hA30Z)-d]Am25c\P%=n?p8cu-=2rt3CDr=AcJ?sUs"Z#QBe+^gsn`p_
:[7"U;7Tf\pXY,ZQ<jqJl]AAgZ!95CK(%)EFd<f#o4W'o<lJ?era_#.L8NQX7Zh<6-^a22[[_
#-q(rO$<9NW)C=qAd#q)e8Wj1jV"Ci^KN`bMmEj6";g3Ni=(N=2c^s<OB"YQE_e1)$6EH=F/
0_e;Hktd[%$T-PT[(O@<.RH2Rq;%hGdn,pP<#'okMg`<ej-(F9PZ>l!p"_8l%bhFU+Hqfqlk
RsN88m682Z<@)RlZU5Jqlg%q7QcsLr!Q-tn'DiZVI(,EZ=hb(0Ud6p+*Q8^a1,FoE-`MOUI[
Z,Rf3s@VLn*Bq^H!#>G7?3CNo5TWhTi!(K:4F24K4:R\S-qpp;gXB,hs5j+hTM'gfs[l:;>(
YkKFG'U`sh-4">trjo"7FQ'Wc*Oc"c@8:RrS'12,;f@Dh#)j?r6>A(0J!teADQE8AVT]AMp%:
^!3Z:N:LOjZRc:Wq5<"i&6+::/1_H^g,$5`FY?qYoAcBl\Mj/95GiafC:N2n6d8N:QaSA;Be
k#(>mhm!6M7qN&2[lam4_#lki?6#5)36`Hrq?kr#B,q0JH*5.-KtDgnO95d19fBP)kQ\TdGp
l\:2AUVp.Q5XndH4hNG4\X5Lo(,g/h>oN-DWg^7>%U':,$ALNKa$X03"Zp=!JUk[lj)3YYF$
8.LPo<RJN4^`nU[F<&E\a;bX!lpF&9)qO'o[P/ABDJ/g/M\?XhLRoSbr#eA&E%IBqtkW'$RA
6%40kt+ja6NZ%s/QTKl8&Y,iJM$&sc.b80jjaLg_.SkDT#En9(-On[rZhUu1#I=bk^qJfpaJ
tBU86IR&'Z[(*;9L%2YB+7^=2paY;LeW/(qC,31kdq[rDFR%#!I#Xg6aqcjb_XmEmddZ4aJP
kC"2L#hCufo?:aF(t.)1hnhnLI435$;p.kIDn"'($i1E!K(Q*\OfW&Wjn()UN5mu(n2I@G(`
b(jg=)%YX"?,q*3@+3DTgIH[JN9hIqE`jY,fN.[*8:aojk>?L^T9blO@eL43WrgdN%++2Cj^
Ci'DWeC&@e!osF47)-O1D0*#gSfCKkkNXLcXtn]A`9sM)EuF+&V=Z%l#s[_/.8$+dc#k)O83;
M::[o(5k@f_\$n[=Q'jTim2::=YeVIZ!+FA@quAo.YILng^3"r)<kGdb+T(EPijm+V0uIPf/
g0oNi"T#f6HkH?n_>d,?SSP)+\&!XOgN2"?L#Yh^jQqe%N'QtP[8-p)N^(c6I!"\,$8V"_E8
OFb/*Q@npU*h`n(C/V^'_.99Ds<[kC:aNk%5nj3nPdQ!#Zl&t\iTb1]A2g:fT<^M#@1r:55rE
H/&&gja.Q^*7-'2m,iLRhR5U^^&u<b?:^FYILbof8r^tahnD]A)CYWu2:;l8SaMk8YHe;t<%c
=]A(a0DpGorH<;KhHktKkH.b[O]A("]AR<b$^5W@[/n4Fa!,?UKn<$(d^HL_]A>>hoVi=7-P[Bbr
jPot*cnNH5in8CRQY)M/t^@F!FW=u=+OXF/6+>o?lVt[`EIc!S-=jG?M:)MOmf/L1letBI%F
jnOKACCn&:RE-nP\*k'424DUN"E[2Etp7\YoB$g6q.Y3P_sQ;*bD(#;`='Iid\0^m`R$5\*_
NnY?5-pe*FoDbDYCS0-+V2#\?KUdi[eE\R.4uJ2AS9!EH?AnJ3\//?*U\')nmH9,MoPpeYgH
FIotk<doAfWF+X@A_BB86Moarj]ALD6$X&GUfU&f#X<XhT^hm6&=/VIW:((gqIB`M.)#@)K4[
kV=f7=u.R:'Rn,*I;jo9r>m%CM8d.((c1nZ*TcqVrb0QTBh=H(L..9]AEm3]AFALb:\58]A=IRt
Hs6'Na<A.)*R=dOh=aVkHoeaVLG*urhhgecX%a2j!eLVca]A\L2W.%;hqs4ZLiW@$sD<nnW!W
IuO[9-Wpq5]AfPPZDK0]A%h<u3Z4e5l&qBG*HY^d,mK_6bU9#\RCaW+Y*ED>sKM/&-nJ>DEDLQ
6G?]APi27#sLa3=HbL?DA,Y42l`*P>F.q-sO!qh;H%kM=u-"qqnrPOW@pB@W5g8cVhO)hG5_9
Vn/(>Y-3KHmjMu1`WDoLn=(n__,ohB1`)*lOkP;"`fG"!Im2'S`0>QM18IeP=ar+g[,Slo)t
7#c?fKeJJVCt:IUsn^`&2FlW4((.m;P!,M:'QtK_]AIQgkI367[^n=dL5<S[5?TK_5^:9XD_f
3[([1jI$i&f7Y:0cDpRZ*F?WuEZ([26PHP@%7V%I+lb?)6D<.&g29iJ5O["6Z]Ae_$amZU#eB
k41"5`^7'4+F^,mTFS7FXEU(qJlDtL%V(QhKQ)0a=$M`Uj7BGp*@_66s8ik%2PJJ\WQ"8qt@
g(7`XQ?F2K<TT+h]AngjH:;Z_![Pk-RP'j&Ws]A\InV@JQksb;n^5mY-hHFXZZE2p4HD&Ss<U=
'a(q=A[Ahhe!cCi'hlf8ahM_"R^8bZ"u,1W-(qZ+5Pd0ZXUB3#LHSZ:CKOjmVt1jiO3t3tB9
H"?NAB8N]A_#ZSk:qa`E8kHZneZU^%O;LZJeoV"-RTZ#<9hHs?fAu[L_%Y=;L^ZreTH7eNIt=
o<\W^8"SMKH_;f?QNQ%<fs!P#HDJ[b$cJn"gEA)L8AVq[$q7odkV[PTe*+bCT<FY%Uiipi)&
BTm+//FG\$O&Nm*Sqa;ZT+=7Q83!&P>R.=)MId18Rm0RGot'KY@q*^4*anb86mTS4-4W&V05
5aY8ZO_%dr1gU"5MdZJW`b4F>F5D:X8ET_hH5EI[3!S>u50=P0LR'cJnF:>V\U;BaYcK[Ps@
iVqVo&10"bA!"mORW7nEJF61@rF!Gtd$I]Aoe8>ZZ2m.&$8`/76Z7&IP;9`\5Y&A0-c.lQ\ZI
-$g3+&a,`*H?BQ]AM9`8V^EDQ-mPpo<PXqkmMdOCEi"i:u</R#$N?E6p<2X(;55=0Z-]A)_mmF
IS\+s%:Xt*8_gCE_QQYsLO69CGN;q5lSrhlkB4uH:Ss*CFcKZrph@dq4EOE05Ffb7(_`U9qR
a@_e7\T%V[DO!p;0KCbaCAk*qih2.=+k3^pl;3mfPNm\I7K.C"CMl'F3!PMU-<4B\N;8boPt
2FpEWg7>MuYDBf4MeJ=!mXZ3JlJfkdB6\rh?nM1B3M40L*?!0HQZWUYf(ZJ/otA4"(qhZc?3
"jW9`<j5:XNVSdbKi[VR^V8kXgRT`uepkH]AN#i3Uis_H"`:RUn=+`>r""/cg&@WhBn53><B&
^Vcr<dP_*iHX'pF_l280H[*edRMLCai)B<@g",le2P>+[URV:DW(bp]Asm($I"NNDgL)^:>GV
8;VN[P/T_g'Tg]A<&[$.JR?8rM1/P]AS-GZDX/8\;?h$=-$IVG/DfQaFlQLCJ\4[TY(tjUd!Q)
G*+\2[eGQ8-e]AX8,p30C33acN93Db+@r8e/\U2mTM0Asd4qggnH.?1A2cse4$'EWggqOiirO
l+%n'[p;F0]A+STqA]AH9bURll^-'9HiLeM*"iu^7g-!h+,HDdZp9u[>5W<^t?PuZlB<E@#t8<
a_Y!%'Z`t_@<e@FJ+*Xu>Rh/I<OmCAk2PHs'q4a^%Uj6__%H+O=DTu1ZrO02lnL<=G-\L.HQ
R69[8LWtW9&>Zm7!s'bFSk6T0?cm3Yd3?/\/oS]AHh\<hM+7@^H]AG5<cBN`MkXITC9R6DJK"p
\!WbW)#@J7ejF*6TrlCGth":Yd23=9Z]AN3m7MnrU"B\!!shdDSKk=<<W)r'tu5)X:HEWhMA1
I8fFnAh<!NgRW!eAc<2HHuqAW\Zm:*Dd]A$>6A=kkesf%l_s.(d>7N^!&LaF=_uOIqX4>3dH7
SB!%WCmb\^7jaF?+Pos!dgFe%To-V4l;?hBQP7tB1-%__YP"WHbRP%:'5D7/k1.9rZpEtHW)
k9TLoIl,"#a4\_O#dUs%:G#TAU9jOSX:T_Jf>2L;nM)qF>OsUTf!Vep!>$U7Ic)R_n'#1o(K
5YgH>--n;`Dmf-$"RS^(>C*&=B.Ncpj[KLo'("Uh'=fW;79=Wa:dUI:f1+)eHa?T`jM>]A[I?
`J36qQ@r3Or'rJae&peBk+0kMJ8n\<i$LLQ#1lnM!?7iB0eJ=*8E]A<$5?rpLBcKq4j!k)ghq
]AH9G%;7&L@$WYJ3pkak.&*dpbFLmiY78cQ)Mm&C<HrdYD(4Y>`<qU6G9RZ'=MhLB/PWEZEPk
p5faN+Akd/A,C)([..dW`d-I'!bfn#sHLRPP6cVC%OCdRJ@M-lPSGs-q2P9,"95?pG)a[c>9
FVFUZh=IF`"26Y]AOVFe?qMW0NI:71+e?k6qR&Ln^T4Rcl4QNirWfT"nmgIr_X4"%al_LNYVa
5`H_%S7pQBP_iZ5p;_%pY1Jj,rD&"^aJ+\Lqq<loIo_>tlFQ>@L(;l\T%b\pYuq(OAW@+k\;
=:.R=%hF$FESKi+$?Augg)1Ifq"'GYMRMus=`t5;D*+g_hkD#35'*l2D=shKdhd&f3O/.:dR
XGr2$I9h%>7*KXnT^^l"tcMV&D1`k'De-"5sFHWj@ebr_8?Z)QRot+]A5N+ZEs!`$N?gpdL?3
WC<Ad=!1W"0u'A0ELe'6mTk3H7+"F(+YdtP<.bgTBnl4Ie:P%0:^?X&-/=!-h?s!UoSD5'<$
Jl8qkVB)dfU"KeNZ//`3'(d<gkp(Rg(?$<;3l^*t-,r(?[0:cDLGHhc<qs?(RV!a]AoU*;:cm
;plAl^AQ/N'M]A%o8lZSV:m\!cjDA]A_Hte4R*Sn]AoW19*u#FtRPu@7(AONmD#\oSl2kQcHEc,
hiTV2o*u;f[++%f?Xe57d`Z3le_Dg@$dj"H%47s+`NA:M5"lc')W("_-pC>'@D"i(KD7:@uR
B)YM5)uYgq0>23o8.3(SdD;7aGS3V;1I2-^`i#NiXKY]AVl*/^8!X\Er]ATr!Fi)4de2sqnPJZ
q@[I>c4D,8*6_2.;pnmD<A1gS2ZX<?[r[9hI`ZID,r0.0oW_!;o!7I"g)*)b^X-%.59GEX8!
dib]A58.]AWbA_5Ki'f!Ef=J'b[SD9'-i++EjcKn!*D3_]A"g/hkjEUTcH8???Q4-!Bq?Jr4u&$
F/:d>>KR+6JH`XOlg1H589SjjToc&G&r7eC(e,;Dj*cH;C'i1nb4H<i4;lc2-$'#i>/[k_^3
\b[,;VH5U5M>l(-IMF@2YNDYjEIogfo>+9260o%XN4P0rRG_]A<(NLXgZ_:!HUO:M)j?t!\?/
QKTeMq_MtPWMZ#7p3VWO0\R<P>Z!Z@#*a9q'MUOK:[&:_1u`r>fTbWGJ3<3V.oT0^\$9Ln(K
^jKS(9iR5jhSroon00\c/.KGTMc$Y5,IQ-_=Zf"hR(!-QJ6b+Y]A69:8S1^?Y2Fc1_h#IMYR=
3i%[b"DGK]A<7"e-^Jj8;XNI?/$nM?1;W@II\[Uj-lR7<eHTe%jTG<_bC&>B]A(G]Aag+5&_hKH
S8W08d"5@HQmH%F5\pp*97"N((i/]A]AO3'RSqPeE(0ZsaW/Db5upu[Xo07=8.\+RHh4_A:V+i
IBD!sa[,:f7h8$B1@4r(9`Pc4WZo]A1Hnj-AUa&L7%)i-;7'hB-_JuH:tVRZir.lCB,5"bXY9
!V^tgEE9eZ^%P.qGSV>?dl7ep7(?Hq7`]A,Z)&W9(]A^>j6e,-%-X]AE+<s,7%<n30;'6.[g!4n
5#*DVup_l6JEG'`75R>hT(P0T;&G%u9QK_Kl(*q&RF/il!+(]A?j)#HXK!BG1Ek4]A[Bf2NcIj
e;Qf.=ZBQ"LCmWB;`D^I'W%uhGpX@G)>/0`CobP2jB^SK,5QNQ1Tg1n@XuO.NmII_L2Pc9d+
_?=)`1%j.mI-d1X`D0*6aKM"u.".'?4n#D,nGb!N?H;WZ7ejg2%sgB<Cc0)uG<gp_3^17tGp
FMjt&B'?3PV,0C*\1U>`T]AaTYnht'HWIP<C]AC;S*OREqZBORa.@SNssaIbZ1!lj4/+b_OeNe
A)a!p&B:WQ9'OuHdYb.q3.'W0Y&/Klo;/8YI!LY/.dUY#9dP;9t+"V?N$W&EjG7?DSf.'&5@
JJ)<>pr>r,pZ^Gc)=g>FDfL<qS1HCFSQ?j.VQ1Of(]AXr0GNa2a9Jeq=p@:SY2e!@t:Yp(BA!
[Wi33.)c*p`!1]A%Asb?hY_ccHfVV5)C?<B1\"5him0>/lT,QocD^7D^8qZ'#.GE=tTM31RM6
JN*-jI5S&TL*=Y<dW&p?b249)d>$)s5iVS,k!j8pTR!Jl:rgBR1-^qBq;e`_6]Ac*"o2eIN$@
.:q]A-U27;SS86NNRZ`:9>_@djh\^p5EXS3OPk[:75?)TAqZp/>R8`[tTC@0QTLF5JkeR'5lr
tpb&8.&9dNs?@pgugKGm%HL[@=4sd;(Hq0[c]A\G33+Ru!*d_OmQK_Ugt4DkD-J9jk9is=qG]A
sn<:R]AtnIE%$@^CZIg\N"Ed1W8ggkaBZnjj4QB$/o9]A2;idkR_V'f7n/Q,00,>/h0I96Q%nZ
poX4B8;W$'FMV?TnW]A\2U&7\#OLrJBHisL)nV%:Z^C\>rh)YRCJOGATjA3\XPdYJ1nL'J^2O
IhNEHD/s[CTJUkGp6>Q+7`?Q,VGLn1a]AtAl-T*U]A;>uPJ9$Tq<6^]AN_S7Q'r*GuD9jRQs0hj
`\rlphTsOb0~
]]></IM>
</InnerWidget>
<BoundsAttr x="480" y="0" width="480" height="540"/>
</Widget>
<body class="com.fr.form.ui.ElementCaseEditor">
<WidgetName name="report2"/>
<WidgetAttr>
<PrivilegeControl/>
</WidgetAttr>
<Margin top="1" left="1" bottom="1" right="1"/>
<Border>
<border style="0" color="-723724" type="0" borderStyle="0"/>
<WidgetTitle>
<O>
<![CDATA[新建标题]]></O>
<FRFont name="SimSun" style="0" size="72"/>
<Position pos="0"/>
</WidgetTitle>
<Alpha alpha="1.0"/>
</Border>
<FormElementCase>
<ReportPageAttr>
<HR/>
<FR/>
<HC/>
<FC/>
</ReportPageAttr>
<ColumnPrivilegeControl/>
<RowPrivilegeControl/>
<RowHeight defaultValue="723900">
<![CDATA[723900,723900,723900,723900,723900,723900,723900,723900,723900,723900,723900]]></RowHeight>
<ColumnWidth defaultValue="2743200">
<![CDATA[2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200,2743200]]></ColumnWidth>
<CellElementList>
<C c="0" r="0" cs="6" s="0">
<O>
<![CDATA[楼层信息]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="1" s="1">
<O>
<![CDATA[楼层建筑面积]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="1" cs="2" s="2">
<O>
<![CDATA[1802㎡]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="3" r="1" s="1">
<O>
<![CDATA[楼层柜台面积]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="4" r="1" cs="2" s="3">
<O>
<![CDATA[1054㎡]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="2" s="1">
<O>
<![CDATA[楼层经营面积]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="2" cs="2" s="4">
<O>
<![CDATA[1594㎡]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="3" r="2" s="1">
<O>
<![CDATA[楼层品牌总数]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="4" r="2" cs="2" s="5">
<O t="I">
<![CDATA[16]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="4" cs="6" s="0">
<O>
<![CDATA[楼层服装所属业种情况]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="5" s="1">
<O>
<![CDATA[编码]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="5" s="1">
<O>
<![CDATA[名称]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="2" r="5" cs="3" s="1">
<O>
<![CDATA[品牌]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="5" r="5" s="1">
<O>
<![CDATA[面积]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="6" s="1">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="业种编号"/>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Parameters/>
</O>
<PrivilegeControl/>
<Expand dir="0"/>
</C>
<C c="1" r="6" s="6">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="所属业种"/>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Parameters/>
</O>
<PrivilegeControl/>
<Expand dir="0"/>
</C>
<C c="2" r="6" cs="3" s="6">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Parameters/>
</O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="5" r="6" s="6">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="柜位面积"/>
<Condition class="com.fr.data.condition.ListCondition"/>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.SummaryGrouper">
<FN>
<![CDATA[com.fr.data.util.function.SumFunction]]></FN>
</RG>
<Result>
<![CDATA[$$$+"㎡"]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="8" cs="6" s="0">
<O>
<![CDATA[各经营方式查看]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="9" s="1">
<O>
<![CDATA[经销]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="9" cs="5" s="7">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Condition class="com.fr.data.condition.CommonCondition">
<CNUMBER>
<![CDATA[0]]></CNUMBER>
<CNAME>
<![CDATA[经营方式]]></CNAME>
<Compare op="0">
<O>
<![CDATA[经销]]></O>
</Compare>
</Condition>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Result>
<![CDATA[$$$]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<HighlightList>
<Highlight class="com.fr.report.cell.cellattr.highlight.DefaultHighlight">
<Name>
<![CDATA[条件属性1]]></Name>
<Condition class="com.fr.data.condition.FormulaCondition">
<Formula>
<![CDATA[len($$$) = 0]]></Formula>
</Condition>
<HighlightAction class="com.fr.report.cell.cellattr.highlight.ValueHighlightAction">
<O>
<![CDATA[--]]></O>
</HighlightAction>
</Highlight>
</HighlightList>
<Expand/>
</C>
<C c="0" r="10" s="1">
<O>
<![CDATA[联销]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="10" cs="5" s="7">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Condition class="com.fr.data.condition.CommonCondition">
<CNUMBER>
<![CDATA[0]]></CNUMBER>
<CNAME>
<![CDATA[经营方式]]></CNAME>
<Compare op="0">
<O>
<![CDATA[联销]]></O>
</Compare>
</Condition>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Result>
<![CDATA[$$$]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="0" r="11" s="1">
<O>
<![CDATA[代销]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="11" cs="5" s="7">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Condition class="com.fr.data.condition.CommonCondition">
<CNUMBER>
<![CDATA[0]]></CNUMBER>
<CNAME>
<![CDATA[经营方式]]></CNAME>
<Compare op="0">
<O>
<![CDATA[代销]]></O>
</Compare>
</Condition>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Result>
<![CDATA[$$$]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<HighlightList>
<Highlight class="com.fr.report.cell.cellattr.highlight.DefaultHighlight">
<Name>
<![CDATA[条件属性1]]></Name>
<Condition class="com.fr.data.condition.FormulaCondition">
<Formula>
<![CDATA[len($$$) = 0]]></Formula>
</Condition>
<HighlightAction class="com.fr.report.cell.cellattr.highlight.ValueHighlightAction">
<O>
<![CDATA[--]]></O>
</HighlightAction>
</Highlight>
</HighlightList>
<Expand/>
</C>
<C c="0" r="12" s="1">
<O>
<![CDATA[代售]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="12" cs="5" s="7">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Condition class="com.fr.data.condition.CommonCondition">
<CNUMBER>
<![CDATA[0]]></CNUMBER>
<CNAME>
<![CDATA[经营方式]]></CNAME>
<Compare op="0">
<O>
<![CDATA[代售]]></O>
</Compare>
</Condition>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Result>
<![CDATA[$$$]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<HighlightList>
<Highlight class="com.fr.report.cell.cellattr.highlight.DefaultHighlight">
<Name>
<![CDATA[条件属性1]]></Name>
<Condition class="com.fr.data.condition.FormulaCondition">
<Formula>
<![CDATA[len($$$) = 0]]></Formula>
</Condition>
<HighlightAction class="com.fr.report.cell.cellattr.highlight.ValueHighlightAction">
<O>
<![CDATA[--]]></O>
</HighlightAction>
</Highlight>
</HighlightList>
<Expand/>
</C>
<C c="0" r="13" s="1">
<O>
<![CDATA[租赁]]></O>
<PrivilegeControl/>
<Expand/>
</C>
<C c="1" r="13" cs="5" s="7">
<O t="DSColumn">
<Attributes dsName="ds2" columnName="品牌名称"/>
<Condition class="com.fr.data.condition.CommonCondition">
<CNUMBER>
<![CDATA[0]]></CNUMBER>
<CNAME>
<![CDATA[经营方式]]></CNAME>
<Compare op="0">
<O>
<![CDATA[租赁]]></O>
</Compare>
</Condition>
<Complex/>
<RG class="com.fr.report.cell.cellattr.core.group.FunctionGrouper"/>
<Result>
<![CDATA[$$$]]></Result>
<Parameters/>
</O>
<PrivilegeControl/>
<HighlightList>
<Highlight class="com.fr.report.cell.cellattr.highlight.DefaultHighlight">
<Name>
<![CDATA[条件属性1]]></Name>
<Condition class="com.fr.data.condition.FormulaCondition">
<Formula>
<![CDATA[len($$$) = 0]]></Formula>
</Condition>
<HighlightAction class="com.fr.report.cell.cellattr.highlight.ValueHighlightAction">
<O>
<![CDATA[--]]></O>
</HighlightAction>
</Highlight>
</HighlightList>
<Expand/>
</C>
</CellElementList>
<ReportAttrSet>
<ReportSettings headerHeight="0" footerHeight="0">
<PaperSetting/>
</ReportSettings>
</ReportAttrSet>
</FormElementCase>
<StyleList>
<Style imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="96" foreground="-16749643"/>
<Background name="ColorBackground" color="-2953990"/>
<Border>
<Top color="-1446671"/>
<Bottom style="1" color="-1446671"/>
<Left color="-1446671"/>
<Right color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="ColorBackground" color="-854279"/>
<Border>
<Top style="1" color="-1446671"/>
<Bottom style="1" color="-1446671"/>
<Left style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Top style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Top style="1" color="-1446671"/>
<Right style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Top style="1" color="-1446671"/>
<Bottom style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Top style="1" color="-1446671"/>
<Bottom style="1" color="-1446671"/>
<Right style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Top style="1" color="-1446671"/>
<Bottom style="1" color="-1446671"/>
<Left style="1" color="-1446671"/>
</Border>
</Style>
<Style horizontal_alignment="0" imageLayout="1">
<FRFont name="Microsoft YaHei" style="0" size="72" foreground="-13421773"/>
<Background name="NullBackground"/>
<Border>
<Bottom style="1" color="-1446671"/>
<Right style="1" color="-1446671"/>
</Border>
</Style>
</StyleList>
<showToolbar showtoolbar="false"/>
<IM>
<![CDATA[c$B[q;ch_V<H/!BWrc$]Ad0`d)W//Zk%[Bp\*'p!eJkuab#"-<KTEQ&FLDHnG,\#:b!C9*Z&3
,I_&:raB&OI,M*$ljBNY%4EpLJl_J%PR5p&0*:bK=:*T<j;s^VfY,n(p(:F,.qDbpAfWVG*E
DqYc`9;l37C2.aoHJlu%"-O04m`D`XA/6oZ#gj?\&`6Cq0YQ"3$Hd(<u2<jFbX/lD0]A_sh%l
KT6LXVdY7Y%aKqqLFpI7P3+pI++JVGfAXJ)N:afO-Xb",n5+u>4JD_U9:5A[W*kkJF>c'fO0
R)Lm1)?L8@[C\4,08g,%4M/U_5SS7i\!s$f#JKf1>?Z@D:(St=BYLJh'ggRg6`Y-67@&_LPU
oiLpEp88'#nE@+RMRY\Mm<:#tQN)#0mcWalUXg/ij8[J=q"T.n?C/)NQbB-G0_K4M:M!Uc2^
R^4Vt9[]AiP<=N/q1@#)_/Tb_<A8d>J*+$4P8h"5Oc$f!Nir6V'b`ZZGYSK>in,!L4eBeLHkV
H6"AjsItp]A@nLN=rGgN\?qPr$9!fDZJ,5k'5FPoBg48RaY(p_S0Y@Sn!+*8a4/88nDnb5B0&
5W4a3/`T(DkjmB#ohKNga;IV!@[BA<Yp%]AD5OPQ7OI4[,$'NP)PL(TM*t\L@RG"@(;#;N_2-
k#!(qn(Z6D?_Rn)=b^O^%IPgl4GA.Hjd$B[QMX<8=del_\!1]A&R0IMRlhE3kg'?%W/t9i"Lj
5;:]AnPMmG3U@@jd+OYiWe5Y[b@@<S,'rH:>+16uCVGAs^L5At8kUWhH?n&F0[(LdPn]A@N*Ud
L'?i2Y67h'#%5di$FB']A*Ph4;.>RB.`g14rFiX3\G=/VDD7/Th:`@(2TG9RVTA%FG88$[a9!
RY`U("1t+:@g#_$q%\Jr$S7QMPKF2Zq"I)pTWFD!!I=V<GgBDl,`]AEg4rMb&KEa^Rk!3M/d'
:KKUpsLnF`lhfMjHp>M\9O>(aYn6NQ9IGs/B^LIpWaM3.$1n1Tm`eY?j%<=Ah<0;&d6PpCh$
X/ZTM(;_W<u#U0iQ=/OD,^`!MJQC'+[=QoC9SO[q/$<"C,+#J9$\.:E[Dc05&`c9fr5Neg\P
WLt!rM_ik>##2r"kXOZ;A1n]A"dbYm4>RC?t/>JpCjHUQ]A:9JjI??rOL4ZBe$/@dDoNOrctaa
"6NcRgr,"5NgK4O]Am$os=9p2stS&Gg0.1W=O9`QZA"a4@3dq1^$Wq&(Gm6*nE\i99L/e^C`3
2A7`OqB#DUeT!Ko./h`ik*USB1OLpb1D'^7C36s@/QJU9s(nEjtW*sBE)]AAOk0%\K$+!*9X+
/-`I\b.MPb()2G>#MaT&W6i6od8LbXiUo*6p4\e"?g_bZVC7,]AEY`ni_F!TdUN)N,i8a$btN
9R1L_HoV_e#!>JeF\".pCbZKI:ciFB.Ei4D>oB4IM`_K`4#@#(t9b9+SKRlRAFTYFR7]A;:Q4
)2l$tEN\!n=Omor3nutub%2'Qn'XhtD!J:qr<#_-[+&\qY]A_bRnGj0h-lA,cU,P*`D85qC.n
,*D%^f(c6k$G>FR3O5Utl@(+/H/-RQV/IMU'#8k*4Y'^->8;L?-^+ET%Xf`+jU9DV;TEkk':
JJ5mKNCNk\YpKCJ.=^#-3Ac65o<b\Q,\/]AAage+]A?o`[MsX!nDm%/q:_\lM2ENHUqY5/27cR
?:KNfc`L^E_s\\"@!;gEZ&L:arj7MI2UY?*H-uHeS$N,d$GMTqbUP--GI_GB>J1_rQ%@Cn/G
d,80<X"DoaDHGdOiT_+H)[GomT[VZgV+)F2,t\-<Sk#7ilS,1D+aUO1$HY#fu%f>WGt(VbeG
9mGL&WsR(VeO_@Q!bFn.bHn[YC6*U(r/5$0(>Bg2%!`3i0;8gCH"FJ<h4j[HDI=*7EE$ZIoZ
/PM9pqi"::<]AMWB-07``%&31N"4.:I5R4N/+?j^o)n<0guu]AF!0oW6PF2'LIgo/'4O9h?8l,
f[(LoXEnF2TTGR350t31QC#[I)$9^$?bhg=W?kZtOPn)#16b9nl^h`@\Bh4@Wj^LBIY[('W]A
.;O5J9Q9_3nY^P+FT^Bf3KAUd#,W6diA-Xn="T=(JsOBnfd&6GdOCiVr6e8bu"3,!X2chZiQ
%LPp71SQl>Nllp*k%edVn6=29C%4b&hDg_ta6+0I-J1b1mhAC$SefP16,cfaXN@og93hKjpc
^ZKY<Fd?tt]AJEe.";0SHAphFPLO(+t'ZUL>R%]ALfZ_eO/09U#rcm1TT-h-+K)g(H-nO`&R_t
DP+#4.qVmJPbp=7Ba(EV+7,&S*;'G^#305]A?P\LK[8%G0:9SKFTBM%L:Fb`,$.TI7'Lae7Ej
5U=gbSnR8Y9As5.-Sg(MH^+F6caAOi;NkDW?Sul8<RO[hEk\jnuK5/k=4#ZjFJoc(BX)4R'[
QS"l@4[^[p^1`HQDAYTU"/e[GnEk=0^+X7V!*+\Vi6ZB5[oIKC1u)T[<Di2K$OL-+FSISY/n
sH=P"rL76J"$WZL\$:I;X2(Gmq1r\p/Y6D+#Vc?[[>pj?JOW:AY`VZ(o?Va9Li/)MPeY)hJR
F0k%ffW=Tc6agfIH;Hs"4h>hO[`hfj`gJZn409j.#KZ1iM3ngAD[9'LV2]AG3/bBPhb50^4q$
1QiYfB2F;#4bO0p(2/dPoTM?B1++<f'7$/@_j(0smnr+TTjEp(j%iRkE=Gn5H\l-e3D<BPI5
tqO7q.h+-$:@:.%Xh1M-jiS[g5"bjaNH.NMTPKsH"T*r[h_0dI>//SdZRq?`;E2U-mBnb36<
mtqBYO^:cQcM(3r]A0a^nT@MhN"`JB\$:(uHkjQg*1lpFbL=)O:dT@W-i,bD0M&)S/qKVKU<L
FsPOkc^1*>YnY/_B5N&@a)n[%^Z9i^E'r\SErmBn7E*KOn^aVbUMV<4SSUX#ouVYMiuWDLet
\'7lsE`(U;OBZjBrWU?CL+gT]ArN(j!;toI3KFW,+7<0lScDU#@s-7=6/;:aSGr14[eT)Z+)B
pCr_^C+IU5;!!()1G<aL79AqhA@E$q![[8pgQOJI**CC<QGcbgfbX9u/201ir@>Z6iM8TR,*
uAXi>mK)o%#hkP!Y7O9T#$0XV8/6rq3Jf"4+11i-0KSJ+&WBAIQ=3?\`dYprGl_s\d%eP*37
E;iO)(V'LHcE@;P-GiU::9mD`]A5h64he2%7VEP,9QCpU4?"<>,Kb*J51QNl.Coo&PV:4cjUX
c/H^7LPipN0:pnD`kU0lD1(%NE1</h-:Pok#SZ?l?Vb$8JW/;-B75n*)NLV$V\[T=`_iA/T+
hS4T'/cL>-qE_M><a.3*<,eWR,(Or`GQ'>nI9=Crj`\]A0H&q6RVsuXbY!t6jN?^mG0+]AEK]A)
,f%@pI&VP)'4fM)-Bj$f+@H&"P0mn-6lflGXdlOMM`i?mtKH?048[EJ7VQTE?-N>hq9W$R;I
&pV."#,`6f8Dt$EM>%Z;eE<kX?_$^5HM4sl?,ojuOFT=;j4Zs*0@JqPLd#mS"_3O9TbK]Aam*
mM:oI3Q[ZWoa5\X4"?hAE5?5K#Q#m+:Udr`(A;.U36B3H5QMr3$dWi6JcQ<dWJJ'A;4.,7`;
e@H6"3D%s,q/h#;:>WkRh!%K;)^r>+6_hD*fF)]A'n8!&]A\[(]Aq8/0`:ehkGlQ!7<bo#]A,'Dt
I+^Mf3XAYtptTu^L-+dQML20gK#"(T3Q'7DN$aNpW1UeF[EoBS/iBNCOI[ps&:_\LKn/Q1G;
c<W2m1)i3i>7o9\T42Vi/(WhNNL$0#cIg!u[f(V[?mfP>T=JpQn*HSC"M3.<^&>8:ZLm9^r]A
rFq;:0/BBoZ1@Nt_<obSRa0ims:ih-Y74P&g8/[!e<oD]ALQQ6K-oP=]A&gmekiNDo&/XL-#fQ
4tp>G55N-_=@NCH(-4*1m[d\U=4OeGqi9THi3*s_*2Bff'r&?T;R^bM0j7EYcu@'DKa_rasC
.).js(NTgCcMD$'\0ZD9hd89B>=-ce&,RqWkQHN]Ai8Q*;JQe4;C-mLRo5I^QHpW270JH,(F.
&++^DTqj$ld6)CZp?bDSR!@MfB\/JsHSemR/PpJ".1pZ[+)M+cI#?XTSQ&_S'gaE=\X82)Ja
"0+f0+<OmnGBIc1fa_KgWJ&Jr\(8:E6iN)-:3*6l$5r?9j?a=#/ea3?#POHc+W3Yc*q\`M1g
;F,Ni=e3B^qp+:=`*@L$ODuYr7YD0EZma_3i=`e_k]Ab'?XX:a_b<1)B\IgnPt(Nu^1mMgL`%
og0pY2t!4>?l'`as3CSKE`WV8C!(HImJ^72ai\>#rBKIbbg;&Oa\8*0[_cd`-H+Q8gc9Fbf=
$GPob=dd$ao)PCHjD<,cSV2/ghZmL[G)V&eHoN*G[ZT^Z8lrk@@W%*rcN:XbCK?9AtO$"WNX
f-)1\E+Z:[%3dE#>#AP'5Y`dB)3!R1NUVi-UL3T1dG&F'pcUqhpls6[TNjV`m#`QI-HsdqMp
4^JQKMi\0UrT-L?bGE3A^R-2Prp5D\o&J7,t;kUkpRIj`ImS3WW8.<YUm"XCu-*>/aWE2^6m
7Q#!PW)"*!1a2e'4',uqOd"27r11bZ2/;iY_s4"='C.t"K4)$A>@$WpijNJ"S:b2b^_*`>X.
oY=:a^@.*>]A@c$=92Fh5irTtcLSL@KfkEd+qe5?lPoZrEn8TgEQ#XHFg!*B0t=pHfE,77EX^
_>=(KFf4d7qPdAT16_gSckOLNp%U)^`TeonN-/:o%NN^l)O$#[&/Y8FOA(I,DJP!\B&_idcG
_`iPg37/1Ph:cKu\;f0:a[I]AR/M(RDcR:a2`pF_EP09UP!&->1bQ5MGd5CN9Z/BGE7:OH[?>
FFa2RMk*a.96$!9G%BQ&QJqOL/`e;).#$MB`Z"GO>4"(A5\Upg#-?CY"dZD!HCSEYP_u5UH=
:><"/lM`["bAeT5.I!:cMItn?(l9`Y[U8u76Ate5Kkn9c^X?Cb)DZjWIOG",!T$@h`N\rD1%
g"2sWBaWBPC6%E\5-4@qB4M0T7o44LN#1+8d[KF@U.]A;JVn_+eu1_`hYpeKR;qMG:XT"V,Qb
e/.QqA@LR_-&#B7sRV68thrsL[@44g4$jJ<e3$(fmV>,ghL?X^1[%Ee/[d^-pSXF=Ame+.ia
2[JklqO/[S%Re#OK8F[Kq53i[KDT#L'nVdY&!LGNZ1"A:KT@pPHZPo%0(#D<9Ael.W`/5CIX
R[gquH>--G:2*B)^$>o'NU3H!]A(Fq/_n97LTU9qM_0q08T;-h_]AWrefZ#)qhnM"eFE"5L9c9
g=j#-QK*:XiEY*_g9Yh^q-q17PRH!foHStFQ<V!Oo2F[Jd`LckAZ_l>P5+$(XJ21c0JhZc5T
grq[Xb+BrI+IEJaCtP_UK8!,fp$i$/)@h;I'7hclQ7W`pE*YqHqu6/Z:d!dk+2#Lam?A/l>D
Z=#?U2rE>_E'a$rjj&G5(LG%mK.O2WYn:SZeKc^Cb:Mr#Vn=iI?ME>lAX2r*g[HZ8*&l!=tq
Ff?*+Xd!nm"&M?gfAj4h3PMH,>\E`Vd;G?S/?)/31<TlWAi2l6lhfZanpZ4m"7LmhFOFC!/a
>cI-U=,D8FF>\?<D,a_$G9,05?Fc2-5I=oLrgpTe1if4F\ZRXKX9<B@ugo5hJ=?^B"L$aRiO
;J/bTE8mK3,BC4['35/*pX9a_Z=o>8O>Go+T;V#D*'0-0\>Tr,f&O]AHnEm8mn6G3ro*.9Q]Ai
/^Ajs6n(h1mAouW)H(]AG)3E,XE79u+EgH@*H]A'%]AVOho`U9P5;rumNVg1$HraFVkM9)_`NC(
o*s'J\m-.c1mLaA;lO7-_&Xu<3n1+i?<C?8inAK6%Q<<d@iNVZnUO4"9p![f?0:Yn1]A1TE6J
A:a#n#`iDjH"J*h=cY[a)_\?g"3,08K&h`lc(>e%bLMoFW5I!(jWE;rhd,nl"[4*]AWtm_I_B
'1L_9Yt"5.,_p,@UI'\Zo"nE-L/fdT!""-DY0u*jVJmpT_hdLPhH/"@-/"n*^3ZlRcXl_>Bl
QahD8XVW^[Gr$P5#JJ!l4aiu:[$\8SSoflb?aZAFmfLl2iB19VqcnVXe>ZKTb*;DN<MfA1>b
p2-@=`_f6p?$;A>M.e#"F2r\]AZL:'W,NZFoB:M'^o!(Y&tjM,lhQ*o8)tIS+n(3J9$UT#+Vn
2r&T%#VL5C-+MJnA'/e(qV$X73Hp'pJ*=)tbC'9NF^(Z]A]Aa&NMVFYBL649ts=#m'1FpNJ@d;
6ccn(HgZpHrhZ:J'-q/Dr)<3OT(<,Spm*j!dG5dfa9hIqH;r,6-g2BQ9XDjEkD`emlY7HkGC
"BF4M*rE9;%DraR?7eJ6R@U4k:-G;XLi5/-;kM5c$%bc3X^sj`!2QhtVMH(EWBuCZ#6.Hu:j
c<-?@X#VIV\$X9"L:a@J3q<I%RTSlrlm%Vsa*!md;d-r"03-P=X=;jC*Hh+Xi'#s*O3ceEBa
LHS51UBdi<5/N+FNFAS]A`Ce`K_G?!GaQBY#ClioY\W1d`J1JaTAjcA8sQQ9%r<SFEU_0kZfO
e'g-Zb$nq[,$it#R*;<W-Bb&\Tp+2Kf81J(toV?YUmR)R#)g>Qq>cGMR-mB9&7=&`;J=Z3H#
/Y+Nfr2uKp0GeM9;r1&b?fFlb>AFh"p-/To$@n+a\b@?4357VGor1QM]AZZJ@L<Qh,4#VcZeF
!Ad(g4kRB@FQ9#P*H_NLM`gcOcp.^SKq:4>@o\Cjb,?,LPKfC[$In+4&0Om&[0D>.j6SfF;`
1PU<Gk!j`s6RR^GT@#<eC9jD5(050O>?)+GbU1%?=^"@AUg;#52,*\T4s,0&.Ol$)p**K)8J
`89*P3M++DmmBU:q[D-WU8?b(\#R#FKU`7%qV>7og*-*h*J^WlOqLpYAWlB,O974EIn1m1H`
j;)h`N8?qccV"l^(\kM;?[=AgdKofEqWiG7I7*V\b)]AM^N[UHPcPWq=Ld#)^>ol&!=*SO_[n
%RqY&e7i(a%/`c]A\UtHb`ljHSV=d"ir8E`*<2DWISn<loNO<pDf"p.BCl-5oEbUWX8>Lod&5
Y+CQOX3\4'*hk4UYBa>B"[:b@PqkZ;4Q!/"kbX'`:RHeGRo&RmiU$MMSa!J?%8lm[;'BD52K
WP0,Y'3b('H)odD&Z\[67?([ied<8!CVqonE8QES>+e,E/iHS<me22E+7]A#9jGgoS//5IPW1
d!]AXb8K8\<#DW3W<*[A#QqIp^1Ai7kO2!)]AW.+N$Z/8FkbNei]AceJBe]A"5Ck?I@1>\!)cZ"g
0d%qZXm8b_$oSRIaQ?Pt_(q4ninmAZ_'eAIu&2/M$HE&QjMfORNG93Ias6\1".QD7fBf]A#@A
"ca3*&Enb-%QCO.o/oN&X!4kKK@/$l;sWu^H@lePQ0_RZ(2Uj*1_gH^ppNE'-8d.!D9kNpB!
e=\h81;BMIt2,I0rp.A'(WN1j,A<)G=2lGK35R[ma?P5,3Bk!HKL[I%Pjlrp5U'"hMSHfl_1
*2b$5krTn-Yb^#NN*P&s(TI<T!QFoUH$u,E)O?%5V`du0P)LQ(R7:F)qhRn]Ao+q7\HSDN3!)
A/>I:5(Y<s$IUg$q3jAMfR`W?nB(`<QN&qUMgX^K7]A[M"?]APVU_Kkp.GNfe1S2-7Zudbp\W!
#:%Z)D.P%qfbKtF0gf(DA,b..(fi*3KHAbJTfr:$'0o+bhgA0L5UWnRdOL'%aHdb,EtqA2dp
du7&%0o<G/n2hh]A$`9O[I!XWrH&b#'5]AQ-T6+AHN*:Q^Na+^B`EF7l_C3cPNd]A23$A&EQMnV
9]A9'G:o,]AIIX"-]AfOM]A(Gf;LXohF9Q`9[&ZU;%ouCOXY%<%KM[T6?;EnNrUSMTP&'mdir%4)
i91AuUYHqgm4pq"d7rIK93oKQnlIgIhn9C8u_XVD74<5C*a2*PRV8PBuW#dZR9(6&P4_b#bJ
WfPS0t98Y1`g/p0t/t<O.e'R[jVM-fU/B'o0Zm4b[N=YHTM65C$@Kqj*"UlH]A)k#cWqFl',[
3YB9cBNA1D2F%+0M"K=,PAn,o'C2O'@Nm]AUOmlp`L?_q]A#lnq+CAm+VBlQW,#c\&[kW6EA&?
&!g;r1QZC0!)#P2Q<hhM'@DGanrQ(@Gh.Iu=V7/?>=JSV]Ah#+BF'F)Yd$6HC`OcViLW%n5+t
*Jq<(6C<U(Z)>6R`0Q9FTb=%?_pgU','\&KL2?=k<JgOe3@%"l5%V#*Wp^+.W6(DT*GhhaiK
3#>tueq3goAEVCuWKldmK&GelK#R8?YI<5T;rlWa&,R196XLR!>i3&U&Ka8Snl!u!H-)gbHr
G0B7#i?$o`S&92ZOnega8;nY+Lq`m`ELMtc7rALV4XJpP->2HAlU6=j9u[P9YH!n=#Ee`,;D
jgRd//8Qp0K]ARbgi!pFH7Zn4]AJr'-.SWrN_?(`?dR-f_"#YQAma$$$=E<i`T1+gDsP.*e-Jc
T:YW9MVARk.*HXg)aOS3]A#&U:gou/;"/T%4Mh1`&hJN/=F*$\e4%JeV5(.eR*QV109#%^rjq
.M3f7SlB)KLHH[]A?VS]AIFLNq0?L(W>bf1cXJ(%*eDBs&>VHd&_o)!E[-B=%Q1\,"\/@.^@ob
#r#0Y3.UCc@r]A=+La[N$X]AN0;"rY"RD^]A:)9pSXHa%VZ(g:QP/(H+7bbLJCk*0T24ia\IYnO
2>\?rN",$[T;PXRX5@4qZ/,?k26]A=\NOirgV^ql$"(>C<>0$W,HTE)goQe:`7br#E3-ESI3H
fBA%U!h8B^E*C)B^t=D<;b;?K'==;9gK.&L4tKq+X5L<<@9)N<3dafeh;aZXVX\X"NV%/6iF
GZ_EO*LW%f#[`JM$-T[J,dJ$T-IQPoa@C_jOMDHE6Mfo%MQlN&33Qd.Su=a9BqO%Tb^@p<aH
)b\rau<DrSrGJC7oo)BqrqBSTXN^a_BQh!\#*]AD,`eK!H#JMD_t-E#+X*rhWEA+(=%]Ak".oe
^QX0Vqbj0LRU4XbR3^TTVZrgVh#;">'K@YOuXM;dIru.-Vprmd/FP?_ciAB3;+(]AtRm2"[6F
mLF^B%<9V2=:/@66C/;knQ4*+EAp4EVDWb":ks>fC-F*j5(4/Na9ikjHO6E[m!$*\\l$HjVZ
TO,bu)("R#oukQL1Ae^lsZEj+")#@,A^hu$C+<Zf*bHF$FXi[UIAa[cKK.D.`9'Z#1N\'[f_
D1[qQM`VQoDk'QY@r&0IW_:1&S3\=A#CtZF`pt\:,s>c`M?Kh[8""hTZuUYB`eFU^DsPm]A00
T/7e)\>Qr6PQXHP*%YU`u#]A_XGW.!E0WpV7Yl$XtKBc5S'3*><6<@^\pYlCXsS[T62Rq7d_@
D<,"06/7fS6?ib-)M-_2)]A,\OaCt=e<-$YU)5rS,#Rp!X4ru(1*JWf8BZY2,+S072!*_TZG\
cT=n8,soY]A%&Ji>=iPsr@`.PJ(U?B]A_p0R&ne!>Z@j=P$Se/6V;5kVHY`7fV&T\U+rGMH[3C
(Amj_P`P8%lM5d^HX?.nQX!_pi-1@$K:K</jERN0$<:I!kOeKKMqBt!jAd#;eN3VC2K5lg1o
ZD]A3Mj8sVg:4!YN?I!I(Pis9g<t?_3olq/d<DTRkY#b1"?IWa/8N323XbL'b7i%kIjmMrOnr
O;GX-W8c_p%]AM=n5,(&4$o)_>;:7_#^p=9stGKcCu"[j8b>1/cR#AP%D\;XfWU87oC'gb+>A
o[:(kE7N!dm1Dj(8-=LV#&qqB<:XQ2`?%28gDr\a/2]AS^#F8HS6dN@eqSt\.)?+Ef&VY)gVC
rA%O8?NR#AF)En_t?'AhLp]AKbPYonPB6_;+*ba:E$#F(Z;7\(4W'$HWpE>O5RFP-?.BbQ\s"
?RpO\:eD):]AHWFR8L6*&D'iCGIV+_S(PM[U:i1\+7(6\<5.$aGm7@j4+c-I`^pJD3+A3EdM^
R]AEkpZ"fT&")B%NYhH"=@[rIsP1O:CX+]Abr=gEXr<.2W)PW,X7$>&:(qOId]AB<*pF)eE"YXc
j)l)lYlB;YW<?Mi!FC5p=1['9>i]AS(oJ*j[S]Ae7;F8@fKY$HY,fZJFUVL:45k?N4d:k"Wid6
8'O>W3Tc-@IbMUT-"sQ3*_T@)37f@h8Nl]A6t3'(MH7.;b2d4f;j2PrLmg0uBr$B:)"a!BP6k
LaUscOm.qdNRnJ@u2?AQ)Hj5#A$Hk;HiO[Jg\!<:kePmK`%mTs6+V0V\Q*o7e2(4</!JPT?0
#lFZ$i;X'l2G;&cLO1IV]Afc^:pVR09t:0[a%$mrOpLJ'5X<L@DqgB+Y@\S>\pB<0"c.b4:3+
eUZWfm.Tf*A@0ck;$^Su21*Sr&'uj*/1,lLs"0IRRfDiNWdn!pBk"RfqZd:3!Yd>oBR!Ab&=
9B]A9"i&='3=8's,L2*/opB_m#7Wbd`&9)6#SddHenTM[>:b_>R%,L!5-mZjrUgV+'3N]A<KMK
e3YGGf86#PciLDQJH"r^e;>)Mn%I+MWrqDfV-RDLN\_X;UEOq*pbB)$k^X6Y.K4KO*]AEN6Ri
ZN`.W5",.1'dg"0jdK$0k!_^dV(JX<rRMl(D%^k:HR&m@MRs@U1R`j)A[b9)VhXM;C%"aC:K
E@!HN>aVptj)o3V\ub5[(o6=,r,<%@-gEZ9\$-^a1unjf#/YdYM^mtJ&2:utbU'CXg<&1;m=
,6]AmL5qSrH?m]A2c;.$S!%_[jW-PS;qfRJae?2rZ(bG42hQ`/s3N!Rcl0>gX@BjGk:2L'sM7F
Wm'faaA#U7R_r^pBQ:OiU*jU/a84%MF+8LNK7Yqgge<\VP:;k'qO=J)jl0Pn5sIbZuO,Pt""
$A*4E.jmK.O4*LT<9%4mEmhs':(eD>/`1)47SD;(81oW>.)VR1L6Zh@@=>jmTJ:F#VY%eM6,
Dc+jm\_1`2ZCZ3bhbcY1+]A8#cp-.NG&3jh3gfDd!!~
]]></IM>
</body>
</InnerWidget>
<BoundsAttr x="480" y="0" width="480" height="540"/>
</Widget>
<Sorted sorted="false"/>
<WidgetZoomAttr compState="0"/>
<Size width="960" height="540"/>
<MobileWidgetList/>
</Center>
</Layout>
<DesignerVersion DesignerVersion="IAA"/>
<PreviewType PreviewType="0"/>
</Form>
