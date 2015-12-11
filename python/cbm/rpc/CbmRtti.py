info = {

"Account":{
	"id":int,
	"username":str,
	"password":str,
	"comment":str
},
"AdjLayer":{
	"id":int,
	"work_surf_id":int,
	"coal_id":int,
	"name":str,
	"num":int,
	"h":float,
	"hp":float,
	"in_cz":int,
	"comment":str
},
"Coal":{
	"id":int,
	"mine_id":int,
	"name":str,
	"minable":int,
	"thick":float,
	"hw":float,
	"qa":float,
	"qr":float,
	"fore_qr":float,
	"fore_qa":float,
	"rank":int,
	"quality":int,
	"pressure":float,
	"gas_content":float,
	"f_value":float,
	"res_abundance":int,
	"complexity":int,
	"mine_index":float,
	"var_coeff":float,
	"stability":int,
	"dip_angle":float,
	"czh":float,
	"czk":float,
	"czw":float,
	"hw_sum":float,
	"rock":int,
	"hhh":float,
	"layer_gap":float,
	"influence_factor":float,
	"res_a1":float,
	"gas_x1":float,
	"res_a2":float,
	"gas_x2":float,
	"pump_wc":float,
	"pump_k":float,
	"pump_k2":float,
	"pump_k3":float,
	"pump_k4":float,
	"pump_k1":float,
	"pore_datas":str,
	"rho":float,
	"vr":float,
	"gas_w0":float,
	"gas_wc2":float,
	"gas_wc3":float,
	"gas_eta":float,
	"q0":float,
	"eval_method":int,
	"q0_alpha":float,
	"qt_alpha":float,
	"t_alpha":float,
	"q_lambda":float,
	"r_lambda":float,
	"p0_lambda":float,
	"p1_lambda":float,
	"t_lambda":float,
	"a_lambda":float,
	"p1_k":float,
	"p2_k":float,
	"gas_q":float,
	"core_height":float,
	"core_area":float,
	"gas_viscosity":float,
	"decay_alpha":float,
	"permeability_lambda":float,
	"permeability_k":float,
	"eval_difficult":int,
	"comment":str,
	"relative_layer_gap":float,
	"is_protectable":int
},
"Complexity":{
	"id":int,
	"name":str,
	"details":str,
	"comment":str
},
"DesignDrillingSurfTechnology":{
	"id":int,
	"design_technology_id":int,
	"name":str,
	"comment":str,
	"v_offset":float,
	"h_offset":float,
	"dp":float,
	"gp":float,
	"leading_dist":float,
	"gbp":float,
	"l_stripe":float,
	"ls":float,
	"ws":float,
	"hs":float,
	"gs":float,
	"wd":float,
	"hd":float,
	"l1":float,
	"l2":float,
	"w":float,
	"h":float,
	"top_side":float,
	"bottom_side":float,
	"left_side":float,
	"right_side":float,
	"lm":float,
	"close_length":float
},
"DesignEvalUnit":{
	"id":int,
	"design_eval_unit_partition_id":int,
	"name":str,
	"comment":str,
	"num":int,
	"l":float,
	"t":int,
	"gap":float
},
"DesignEvalUnitPartition":{
	"id":int,
	"work_surf_id":int,
	"name":str,
	"comment":str,
	"l2":float,
	"l1":float,
	"w":float,
	"h":float,
	"l":float,
	"r":float,
	"t":float,
	"v":float
},
"DesignGoafTechnology":{
	"id":int,
	"design_technology_id":int,
	"name":str,
	"comment":str,
	"pore_stubble":float,
	"dp":float,
	"gs":float,
	"ls":float,
	"ws":float,
	"hs":float,
	"gp":float,
	"pore_num":int,
	"top_dist":float,
	"h_offset":str,
	"y_offset":str,
	"l1":float,
	"l2":float,
	"w":float,
	"h":float
},
"DesignPore":{
	"id":int,
	"design_eval_unit_id":int,
	"design_site_id":int,
	"name":str,
	"d":float,
	"x1":float,
	"y1":float,
	"z1":float,
	"x2":float,
	"y2":float,
	"z2":float,
	"length":float,
	"angle1":float,
	"angle2":float,
	"comment":str,
	"t":int
},
"DesignSite":{
	"id":int,
	"design_technology_id":int,
	"name":str,
	"w":float,
	"h":float,
	"x":float,
	"y":float,
	"z":float,
	"comment":str
},
"DesignTechnology":{
	"id":int,
	"coal_id":int,
	"name":str,
	"region":int,
	"comment":str
},
"DesignTunnelControlPoint":{
	"id":int,
	"design_eval_unit_partition_id":int,
	"name":str,
	"comment":str,
	"x":float,
	"y":float,
	"z":float
},
"DesignWorkSurfControlPoint":{
	"id":int,
	"design_eval_unit_partition_id":int,
	"name":str,
	"comment":str,
	"x":float,
	"y":float,
	"z":float
},
"DesignWorkSurfTechnology":{
	"id":int,
	"design_technology_id":int,
	"name":str,
	"comment":str,
	"top_side":float,
	"bottom_side":float,
	"right_side":float,
	"l1":float,
	"w":float,
	"h":float,
	"l2":float,
	"left_side":float,
	"v_offset":float,
	"h_offset":float,
	"p_offset":float,
	"wd":float,
	"hd":float,
	"lm":float,
	"ws":float,
	"ls":float,
	"gs":float,
	"hs":float,
	"dp":float,
	"gp":float,
	"single_rock_tunnel":int,
	"d_offset":float,
	"pore_stubble":float,
	"pore_angle":float,
	"pore_type":int,
	"close_length":float
},
"DrillingRadiusParam":{
	"id":int,
	"coal_id":int,
	"name":str,
	"r":float,
	"l":float,
	"k1":float,
	"rho":float,
	"q0":float,
	"a":float,
	"t":float,
	"qm":float,
	"qsum":float,
	"eta":float,
	"r0":float,
	"p0":float,
	"r1":float,
	"p1":float
},
"DrillingSurf":{
	"id":int,
	"work_area_id":int,
	"tunnel_id":int,
	"name":str,
	"qr":float,
	"qa":float,
	"fore_qr":float,
	"fore_qa":float,
	"q4":float,
	"comment":str
},
"HighDrillingPore":{
	"id":int,
	"high_drilling_pore_param_id":int,
	"num":int,
	"length":float,
	"angle":float,
	"pore_type":int,
	"comment":str
},
"HighDrillingPoreParam":{
	"id":int,
	"work_surf_id":int,
	"name":str,
	"lk":float,
	"lc":float,
	"lw":float,
	"n1":int,
	"n2":int,
	"beta":float,
	"ld":float,
	"comment":str
},
"HighDrillingSiteParam":{
	"id":int,
	"work_surf_id":int,
	"name":str,
	"l1":float,
	"l2":float,
	"lg":float,
	"hn":float,
	"theta":float,
	"q":float,
	"rtn":float,
	"hs":float,
	"comment":str
},
"HighDrillingTunnel":{
	"id":int,
	"work_surf_id":int,
	"name":str,
	"k":float,
	"rock":int,
	"hz_min":float,
	"hz_max":float,
	"comment":str
},
"HydrGeo":{
	"id":int,
	"name":str,
	"x1":int,
	"x2":int,
	"x3":int,
	"x4":float,
	"x5":float,
	"x6":float,
	"x7":float,
	"x8":str
},
"Mine":{
	"id":int,
	"tech_mode_id":int,
	"mine_region_id":int,
	"account_id":int,
	"name":str,
	"province":str,
	"city":str,
	"capacity":float,
	"topo_geo":int,
	"hydr_geo":int,
	"ground_condition":int,
	"qr":float,
	"qa":float,
	"fore_qr":float,
	"fore_qa":float,
	"gas_k1":float,
	"gas_k2":float,
	"stereo_schem_diagram":str,
	"rock_gas_k2":float,
	"reserve_w1":float,
	"reserve_w2":float,
	"reserve_w3":float,
	"gas_w0":float,
	"gas_wc2":float,
	"pump_k2":float,
	"pump_k3":float,
	"pump_k4":float,
	"pump_k1":float,
	"pump_k":float,
	"pump_wc":float,
	"reserve_gas":float,
	"comment":str,
	"protect_layer_condition":int
},
"MineBase":{
	"id":int,
	"name":str,
	"comment":str
},
"MineRegion":{
	"id":int,
	"mine_base_id":int,
	"name":str,
	"comment":str
},
"PoreFlow":{
	"id":int,
	"name":str,
	"t":float,
	"a0":float,
	"d":float,
	"d1":float,
	"m":float,
	"k":float,
	"delta_t":float,
	"x":float,
	"p_test":float,
	"p_cur":float,
	"b":float,
	"pt":float,
	"delta_p":float,
	"dh":float,
	"q_hun":float,
	"q_chun":float
},
"PoreSize":{
	"id":int,
	"name":str,
	"q":float,
	"v":float,
	"d":float,
	"p":float,
	"sigma":float,
	"delta":float,
	"comment":str
},
"ResAbundance":{
	"id":int,
	"name":str,
	"min_abundance":float,
	"max_abundance":float
},
"Rock":{
	"id":int,
	"name":str,
	"a":float,
	"b":float,
	"c":float,
	"comment":str
},
"SysInfo":{
	"id":int,
	"account_id":int,
	"last_login_time":str,
	"comment":str
},
"TechMode":{
	"id":int,
	"mine_region_id":int,
	"name":str,
	"mode_type":int,
	"c1":int,
	"c2":int,
	"c3":int,
	"comment":str
},
"Technology":{
	"id":int,
	"mine_region_id":int,
	"name":str,
	"iskey":int,
	"doc":str,
	"video":str,
	"comment":str
},
"TopoGeo":{
	"id":int,
	"name":str,
	"feature":str,
	"comment":str
},
"Tunnel":{
	"id":int,
	"name":str,
	"b":float,
	"h":float,
	"l":float,
	"s":float,
	"d":float,
	"wh":float,
	"v":float,
	"q3":float,
	"q0":float,
	"comment":str,
	"tunnel_type":int,
	"top_side":float,
	"bottom_side":float,
	"left_side":float,
	"right_side":float,
	"x1":float,
	"y1":float,
	"z1":float,
	"x2":float,
	"y2":float,
	"z2":float
},
"WorkArea":{
	"id":int,
	"coal_id":int,
	"name":str,
	"mode":int,
	"a":float,
	"qr":float,
	"qa":float,
	"fore_qr":float,
	"fore_qa":float,
	"comment":str
},
"WorkSurf":{
	"id":int,
	"work_area_id":int,
	"tunnel_id":int,
	"name":str,
	"a":float,
	"qr":float,
	"qa":float,
	"fore_qr":float,
	"fore_qa":float,
	"l1":float,
	"l2":float,
	"layerable":int,
	"k1":float,
	"k2":float,
	"k3":float,
	"kf":float,
	"method":int,
	"last_t":float,
	"qr1":float,
	"qr2":float,
	"comment":str
}
}

fkey = {

"Account":{
	"id":1,
	"username":0,
	"password":0,
	"comment":0
},
"AdjLayer":{
	"id":1,
	"work_surf_id":2,
	"coal_id":2,
	"name":0,
	"num":0,
	"h":0,
	"hp":0,
	"in_cz":0,
	"comment":0
},
"Coal":{
	"id":1,
	"mine_id":2,
	"name":0,
	"minable":0,
	"thick":0,
	"hw":0,
	"qa":0,
	"qr":0,
	"fore_qr":0,
	"fore_qa":0,
	"rank":0,
	"quality":0,
	"pressure":0,
	"gas_content":0,
	"f_value":0,
	"res_abundance":0,
	"complexity":0,
	"mine_index":0,
	"var_coeff":0,
	"stability":0,
	"dip_angle":0,
	"czh":0,
	"czk":0,
	"czw":0,
	"hw_sum":0,
	"rock":0,
	"hhh":0,
	"layer_gap":0,
	"influence_factor":0,
	"res_a1":0,
	"gas_x1":0,
	"res_a2":0,
	"gas_x2":0,
	"pump_wc":0,
	"pump_k":0,
	"pump_k2":0,
	"pump_k3":0,
	"pump_k4":0,
	"pump_k1":0,
	"pore_datas":0,
	"rho":0,
	"vr":0,
	"gas_w0":0,
	"gas_wc2":0,
	"gas_wc3":0,
	"gas_eta":0,
	"q0":0,
	"eval_method":0,
	"q0_alpha":0,
	"qt_alpha":0,
	"t_alpha":0,
	"q_lambda":0,
	"r_lambda":0,
	"p0_lambda":0,
	"p1_lambda":0,
	"t_lambda":0,
	"a_lambda":0,
	"p1_k":0,
	"p2_k":0,
	"gas_q":0,
	"core_height":0,
	"core_area":0,
	"gas_viscosity":0,
	"decay_alpha":0,
	"permeability_lambda":0,
	"permeability_k":0,
	"eval_difficult":0,
	"comment":0,
	"relative_layer_gap":0,
	"is_protectable":0
},
"Complexity":{
	"id":1,
	"name":0,
	"details":0,
	"comment":0
},
"DesignDrillingSurfTechnology":{
	"id":1,
	"design_technology_id":2,
	"name":0,
	"comment":0,
	"v_offset":0,
	"h_offset":0,
	"dp":0,
	"gp":0,
	"leading_dist":0,
	"gbp":0,
	"l_stripe":0,
	"ls":0,
	"ws":0,
	"hs":0,
	"gs":0,
	"wd":0,
	"hd":0,
	"l1":0,
	"l2":0,
	"w":0,
	"h":0,
	"top_side":0,
	"bottom_side":0,
	"left_side":0,
	"right_side":0,
	"lm":0,
	"close_length":0
},
"DesignEvalUnit":{
	"id":1,
	"design_eval_unit_partition_id":2,
	"name":0,
	"comment":0,
	"num":0,
	"l":0,
	"t":0,
	"gap":0
},
"DesignEvalUnitPartition":{
	"id":1,
	"work_surf_id":2,
	"name":0,
	"comment":0,
	"l2":0,
	"l1":0,
	"w":0,
	"h":0,
	"l":0,
	"r":0,
	"t":0,
	"v":0
},
"DesignGoafTechnology":{
	"id":1,
	"design_technology_id":2,
	"name":0,
	"comment":0,
	"pore_stubble":0,
	"dp":0,
	"gs":0,
	"ls":0,
	"ws":0,
	"hs":0,
	"gp":0,
	"pore_num":0,
	"top_dist":0,
	"h_offset":0,
	"y_offset":0,
	"l1":0,
	"l2":0,
	"w":0,
	"h":0
},
"DesignPore":{
	"id":1,
	"design_eval_unit_id":2,
	"design_site_id":2,
	"name":0,
	"d":0,
	"x1":0,
	"y1":0,
	"z1":0,
	"x2":0,
	"y2":0,
	"z2":0,
	"length":0,
	"angle1":0,
	"angle2":0,
	"comment":0,
	"t":0
},
"DesignSite":{
	"id":1,
	"design_technology_id":2,
	"name":0,
	"w":0,
	"h":0,
	"x":0,
	"y":0,
	"z":0,
	"comment":0
},
"DesignTechnology":{
	"id":1,
	"coal_id":2,
	"name":0,
	"region":0,
	"comment":0
},
"DesignTunnelControlPoint":{
	"id":1,
	"design_eval_unit_partition_id":2,
	"name":0,
	"comment":0,
	"x":0,
	"y":0,
	"z":0
},
"DesignWorkSurfControlPoint":{
	"id":1,
	"design_eval_unit_partition_id":2,
	"name":0,
	"comment":0,
	"x":0,
	"y":0,
	"z":0
},
"DesignWorkSurfTechnology":{
	"id":1,
	"design_technology_id":2,
	"name":0,
	"comment":0,
	"top_side":0,
	"bottom_side":0,
	"right_side":0,
	"l1":0,
	"w":0,
	"h":0,
	"l2":0,
	"left_side":0,
	"v_offset":0,
	"h_offset":0,
	"p_offset":0,
	"wd":0,
	"hd":0,
	"lm":0,
	"ws":0,
	"ls":0,
	"gs":0,
	"hs":0,
	"dp":0,
	"gp":0,
	"single_rock_tunnel":0,
	"d_offset":0,
	"pore_stubble":0,
	"pore_angle":0,
	"pore_type":0,
	"close_length":0
},
"DrillingRadiusParam":{
	"id":1,
	"coal_id":2,
	"name":0,
	"r":0,
	"l":0,
	"k1":0,
	"rho":0,
	"q0":0,
	"a":0,
	"t":0,
	"qm":0,
	"qsum":0,
	"eta":0,
	"r0":0,
	"p0":0,
	"r1":0,
	"p1":0
},
"DrillingSurf":{
	"id":1,
	"work_area_id":2,
	"tunnel_id":2,
	"name":0,
	"qr":0,
	"qa":0,
	"fore_qr":0,
	"fore_qa":0,
	"q4":0,
	"comment":0
},
"HighDrillingPore":{
	"id":1,
	"high_drilling_pore_param_id":2,
	"num":0,
	"length":0,
	"angle":0,
	"pore_type":0,
	"comment":0
},
"HighDrillingPoreParam":{
	"id":1,
	"work_surf_id":2,
	"name":0,
	"lk":0,
	"lc":0,
	"lw":0,
	"n1":0,
	"n2":0,
	"beta":0,
	"ld":0,
	"comment":0
},
"HighDrillingSiteParam":{
	"id":1,
	"work_surf_id":2,
	"name":0,
	"l1":0,
	"l2":0,
	"lg":0,
	"hn":0,
	"theta":0,
	"q":0,
	"rtn":0,
	"hs":0,
	"comment":0
},
"HighDrillingTunnel":{
	"id":1,
	"work_surf_id":2,
	"name":0,
	"k":0,
	"rock":0,
	"hz_min":0,
	"hz_max":0,
	"comment":0
},
"HydrGeo":{
	"id":1,
	"name":0,
	"x1":0,
	"x2":0,
	"x3":0,
	"x4":0,
	"x5":0,
	"x6":0,
	"x7":0,
	"x8":0
},
"Mine":{
	"id":1,
	"tech_mode_id":2,
	"mine_region_id":2,
	"account_id":2,
	"name":0,
	"province":0,
	"city":0,
	"capacity":0,
	"topo_geo":0,
	"hydr_geo":0,
	"ground_condition":0,
	"qr":0,
	"qa":0,
	"fore_qr":0,
	"fore_qa":0,
	"gas_k1":0,
	"gas_k2":0,
	"stereo_schem_diagram":0,
	"rock_gas_k2":0,
	"reserve_w1":0,
	"reserve_w2":0,
	"reserve_w3":0,
	"gas_w0":0,
	"gas_wc2":0,
	"pump_k2":0,
	"pump_k3":0,
	"pump_k4":0,
	"pump_k1":0,
	"pump_k":0,
	"pump_wc":0,
	"reserve_gas":0,
	"comment":0,
	"protect_layer_condition":0
},
"MineBase":{
	"id":1,
	"name":0,
	"comment":0
},
"MineRegion":{
	"id":1,
	"mine_base_id":2,
	"name":0,
	"comment":0
},
"PoreFlow":{
	"id":1,
	"name":0,
	"t":0,
	"a0":0,
	"d":0,
	"d1":0,
	"m":0,
	"k":0,
	"delta_t":0,
	"x":0,
	"p_test":0,
	"p_cur":0,
	"b":0,
	"pt":0,
	"delta_p":0,
	"dh":0,
	"q_hun":0,
	"q_chun":0
},
"PoreSize":{
	"id":1,
	"name":0,
	"q":0,
	"v":0,
	"d":0,
	"p":0,
	"sigma":0,
	"delta":0,
	"comment":0
},
"ResAbundance":{
	"id":1,
	"name":0,
	"min_abundance":0,
	"max_abundance":0
},
"Rock":{
	"id":1,
	"name":0,
	"a":0,
	"b":0,
	"c":0,
	"comment":0
},
"SysInfo":{
	"id":1,
	"account_id":2,
	"last_login_time":0,
	"comment":0
},
"TechMode":{
	"id":1,
	"mine_region_id":2,
	"name":0,
	"mode_type":0,
	"c1":0,
	"c2":0,
	"c3":0,
	"comment":0
},
"Technology":{
	"id":1,
	"mine_region_id":2,
	"name":0,
	"iskey":0,
	"doc":0,
	"video":0,
	"comment":0
},
"TopoGeo":{
	"id":1,
	"name":0,
	"feature":0,
	"comment":0
},
"Tunnel":{
	"id":1,
	"name":0,
	"b":0,
	"h":0,
	"l":0,
	"s":0,
	"d":0,
	"wh":0,
	"v":0,
	"q3":0,
	"q0":0,
	"comment":0,
	"tunnel_type":0,
	"top_side":0,
	"bottom_side":0,
	"left_side":0,
	"right_side":0,
	"x1":0,
	"y1":0,
	"z1":0,
	"x2":0,
	"y2":0,
	"z2":0
},
"WorkArea":{
	"id":1,
	"coal_id":2,
	"name":0,
	"mode":0,
	"a":0,
	"qr":0,
	"qa":0,
	"fore_qr":0,
	"fore_qa":0,
	"comment":0
},
"WorkSurf":{
	"id":1,
	"work_area_id":2,
	"tunnel_id":2,
	"name":0,
	"a":0,
	"qr":0,
	"qa":0,
	"fore_qr":0,
	"fore_qa":0,
	"l1":0,
	"l2":0,
	"layerable":0,
	"k1":0,
	"k2":0,
	"k3":0,
	"kf":0,
	"method":0,
	"last_t":0,
	"qr1":0,
	"qr2":0,
	"comment":0
}
}
