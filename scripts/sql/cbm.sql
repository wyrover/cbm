-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: 2015-11-12 13:16:22
-- 服务器版本： 5.6.17
-- PHP Version: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `cbm`
--

-- --------------------------------------------------------

--
-- 表的结构 `account`
--

CREATE TABLE IF NOT EXISTS `account` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;

--
-- 转存表中的数据 `account`
--

INSERT INTO `account` (`id`, `username`, `password`, `comment`) VALUES
(1, 'admin', '123', '超级管理员账户'),
(2, 'dlj', '123', NULL),
(3, 'test', '123', NULL);

-- --------------------------------------------------------

--
-- 表的结构 `adj_layer`
--

CREATE TABLE IF NOT EXISTS `adj_layer` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `work_surf_id` int(11) DEFAULT NULL,
  `coal_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `num` int(11) DEFAULT NULL,
  `h` decimal(8,2) DEFAULT NULL,
  `hp` decimal(8,2) DEFAULT NULL,
  `in_cz` int(11) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_16` (`work_surf_id`),
  KEY `fk_relationship_32` (`coal_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='回采工作面就是开采层' AUTO_INCREMENT=7 ;

--
-- 转存表中的数据 `adj_layer`
--

INSERT INTO `adj_layer` (`id`, `work_surf_id`, `coal_id`, `name`, `num`, `h`, `hp`, `in_cz`, `comment`) VALUES
(1, NULL, NULL, 'L1', NULL, NULL, NULL, NULL, NULL),
(2, NULL, NULL, 'L2', NULL, NULL, NULL, NULL, NULL),
(3, NULL, NULL, 'L3', NULL, NULL, NULL, NULL, NULL),
(4, NULL, NULL, 'ddd', NULL, NULL, NULL, NULL, NULL),
(5, NULL, NULL, 'ggg', NULL, NULL, NULL, NULL, NULL),
(6, NULL, NULL, 'hhhh', NULL, NULL, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- 表的结构 `coal`
--

CREATE TABLE IF NOT EXISTS `coal` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `mine_id` int(11) DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `minable` int(11) DEFAULT '1',
  `thick` decimal(8,2) DEFAULT NULL,
  `hw` decimal(8,2) DEFAULT NULL,
  `qa` decimal(8,2) DEFAULT NULL,
  `qr` decimal(8,2) DEFAULT NULL,
  `fore_qr` decimal(8,2) DEFAULT NULL,
  `fore_qa` decimal(8,2) DEFAULT NULL,
  `rank` int(11) DEFAULT NULL,
  `quality` int(11) DEFAULT NULL,
  `pressure` decimal(10,2) DEFAULT NULL,
  `gas_content` decimal(8,2) DEFAULT NULL,
  `gas_penetration` decimal(8,2) DEFAULT NULL,
  `f_value` decimal(8,2) DEFAULT NULL,
  `res_abundance` int(11) DEFAULT NULL,
  `complexity` int(11) DEFAULT NULL,
  `mine_index` decimal(8,2) DEFAULT NULL,
  `var_coeff` decimal(8,2) DEFAULT NULL,
  `stability` int(11) DEFAULT NULL,
  `dip_angle` decimal(8,2) DEFAULT NULL,
  `czh` decimal(8,2) DEFAULT NULL,
  `czk` decimal(8,2) DEFAULT NULL,
  `czw` decimal(8,2) DEFAULT NULL,
  `hw_sum` decimal(8,2) DEFAULT NULL,
  `rock` int(11) DEFAULT NULL,
  `hhh` decimal(8,2) DEFAULT NULL,
  `layer_gap` decimal(8,2) DEFAULT NULL,
  `influence_factor` decimal(8,2) DEFAULT NULL,
  `res_a1` decimal(8,2) DEFAULT NULL,
  `gas_x1` decimal(8,2) DEFAULT NULL,
  `res_a2` decimal(8,2) DEFAULT NULL,
  `gas_x2` decimal(8,2) DEFAULT NULL,
  `pump_wc` decimal(8,2) DEFAULT NULL,
  `pump_k` decimal(8,2) DEFAULT NULL,
  `pump_k2` decimal(8,2) DEFAULT NULL,
  `pump_k3` decimal(8,2) DEFAULT NULL,
  `pump_k4` decimal(8,2) DEFAULT NULL,
  `pump_k1` decimal(8,2) DEFAULT NULL,
  `pore_datas` varchar(500) DEFAULT NULL,
  `rho` decimal(8,2) DEFAULT NULL,
  `vr` decimal(8,2) DEFAULT NULL,
  `gas_w0` decimal(8,2) DEFAULT NULL,
  `gas_wc2` decimal(8,2) DEFAULT NULL,
  `gas_wc3` decimal(8,2) DEFAULT NULL,
  `gas_eta` decimal(8,2) DEFAULT NULL,
  `q0` decimal(8,2) DEFAULT NULL,
  `eval_method` int(11) DEFAULT NULL,
  `q0_alpha` decimal(8,2) DEFAULT NULL,
  `qt_alpha` decimal(8,2) DEFAULT NULL,
  `t_alpha` decimal(8,2) DEFAULT NULL,
  `q_lambda` decimal(8,2) DEFAULT NULL,
  `r_lambda` decimal(8,2) DEFAULT NULL,
  `p0_lambda` decimal(10,2) DEFAULT NULL,
  `p1_lambda` decimal(10,2) DEFAULT NULL,
  `t_lambda` decimal(8,2) DEFAULT NULL,
  `a_lambda` decimal(8,2) DEFAULT NULL,
  `p1_k` decimal(10,2) DEFAULT NULL,
  `p2_k` decimal(10,2) DEFAULT NULL,
  `gas_q` decimal(8,2) DEFAULT NULL,
  `core_height` decimal(8,2) DEFAULT NULL,
  `core_area` decimal(8,2) DEFAULT NULL,
  `gas_viscosity` decimal(8,2) DEFAULT NULL,
  `decay_alpha` decimal(8,2) DEFAULT NULL,
  `permeability_lambda` decimal(8,2) DEFAULT NULL,
  `permeability_k` decimal(8,2) DEFAULT NULL,
  `eval_difficult` int(11) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_1` (`mine_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='煤层基本信息参数表' AUTO_INCREMENT=11 ;

--
-- 转存表中的数据 `coal`
--

INSERT INTO `coal` (`id`, `mine_id`, `name`, `minable`, `thick`, `hw`, `qa`, `qr`, `fore_qr`, `fore_qa`, `rank`, `quality`, `pressure`, `gas_content`, `gas_penetration`, `f_value`, `res_abundance`, `complexity`, `mine_index`, `var_coeff`, `stability`, `dip_angle`, `czh`, `czk`, `czw`, `hw_sum`, `rock`, `hhh`, `layer_gap`, `influence_factor`, `res_a1`, `gas_x1`, `res_a2`, `gas_x2`, `pump_wc`, `pump_k`, `pump_k2`, `pump_k3`, `pump_k4`, `pump_k1`, `pore_datas`, `rho`, `vr`, `gas_w0`, `gas_wc2`, `gas_wc3`, `gas_eta`, `q0`, `eval_method`, `q0_alpha`, `qt_alpha`, `t_alpha`, `q_lambda`, `r_lambda`, `p0_lambda`, `p1_lambda`, `t_lambda`, `a_lambda`, `p1_k`, `p2_k`, `gas_q`, `core_height`, `core_area`, `gas_viscosity`, `decay_alpha`, `permeability_lambda`, `permeability_k`, `eval_difficult`, `comment`) VALUES
(1, 1, '示范矿区煤层-晋城', 1, '6.80', NULL, NULL, NULL, NULL, NULL, 3, NULL, '107.65', '45.00', '0.24', '0.23', 2, 3, '1.34', '0.56', NULL, '6.00', '13.00', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(2, 2, '示范矿区煤层-两淮', 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(3, 3, '示范矿区煤层-松藻', 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5, 4, '2#', 1, '5.60', '6.00', NULL, NULL, NULL, NULL, 3, NULL, '198.56', '20.00', '0.22', '0.12', 2, 3, '5.80', '0.46', 2, '8.00', '20.50', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '44.00', '55.00', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '1.00', '567.00', '14.18', NULL, NULL),
(6, 4, '1#', 1, '6.00', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '8.00', NULL, NULL, NULL, NULL, NULL, NULL, '30.00', NULL, '555.00', '555.00', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(7, 4, '7#', 1, '4.00', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '8.00', NULL, NULL, NULL, NULL, NULL, NULL, '20.00', NULL, '444.00', '444.00', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(8, 5, '1#', 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(9, 5, '2#', 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10, 5, '7#', 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- 表的结构 `complexity`
--

CREATE TABLE IF NOT EXISTS `complexity` (
  `id` int(11) NOT NULL,
  `name` varchar(255) DEFAULT NULL,
  `details` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `complexity`
--

INSERT INTO `complexity` (`id`, `name`, `details`, `comment`) VALUES
(1, '简单构造', '煤地层沿走向、倾向的产状变化不大，断层稀少，没有或很少受岩浆岩的影响，不影响采区的合理划分和采煤工作面的连续推进。主要包括：①产状接近水平，很少有缓波状起伏；②缓倾斜的简单单斜、向斜或背斜；③为数不多和方向单一的宽缓褶皱。', NULL),
(2, '中等构造', '含煤地层沿走向、倾向的产状有一定变化，断层较发育，局部受岩浆岩的影响，对采区的合理划分和采煤工作面的连续推进有一定影响。主要包括：①产状平缓，沿走向和倾向均发育宽缓褶皱，或伴有一定数量的断层；②简单单斜、向斜或背斜，伴有较多断层，或局部有小规模的褶曲及倒转。', NULL),
(3, '复杂构造', '含煤地层沿走向、倾向的产状变化很大，断层发育，有时受岩浆岩的严重影响，影响采区的合理划分，只能划分出部分正规采区。主要包括：①受几组断层严重破坏的断块构造；②在单斜、向斜或背斜的基础上，次一级褶曲和断层均很发育；③紧密褶皱，伴有一定数量的断层。', NULL),
(4, '极复杂构造', '含煤地层的产状变化极大，断层极发育，有时受岩浆岩的严重破坏，很难划分出正规采区。主要包括：①紧密褶皱、断层密集；②形态复杂的褶皱，断层发育；③断层发育，受岩浆岩的严重破坏。', NULL);

-- --------------------------------------------------------

--
-- 表的结构 `design_drilling_surf_technology`
--

CREATE TABLE IF NOT EXISTS `design_drilling_surf_technology` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `design_technology_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  `v_offset` decimal(8,2) DEFAULT NULL,
  `h_offset` decimal(8,2) DEFAULT NULL,
  `dp` decimal(8,2) DEFAULT NULL,
  `gp` decimal(8,2) DEFAULT NULL,
  `leading_dist` decimal(8,2) DEFAULT NULL,
  `gbp` decimal(8,2) DEFAULT NULL,
  `l_stripe` decimal(8,2) DEFAULT NULL,
  `ls` decimal(8,2) DEFAULT NULL,
  `ws` decimal(8,2) DEFAULT NULL,
  `hs` decimal(8,2) DEFAULT NULL,
  `gs` decimal(8,2) DEFAULT NULL,
  `wd` decimal(8,2) DEFAULT NULL,
  `hd` decimal(8,2) DEFAULT NULL,
  `l1` decimal(8,2) DEFAULT NULL,
  `l2` decimal(8,2) DEFAULT NULL,
  `w` decimal(8,2) DEFAULT NULL,
  `h` decimal(8,2) DEFAULT NULL,
  `top_side` decimal(8,2) DEFAULT NULL,
  `bottom_side` decimal(8,2) DEFAULT NULL,
  `left_side` decimal(8,2) DEFAULT NULL,
  `right_side` decimal(8,2) DEFAULT NULL,
  `lm` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_31` (`design_technology_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=2 ;

--
-- 转存表中的数据 `design_drilling_surf_technology`
--

INSERT INTO `design_drilling_surf_technology` (`id`, `design_technology_id`, `name`, `comment`, `v_offset`, `h_offset`, `dp`, `gp`, `leading_dist`, `gbp`, `l_stripe`, `ls`, `ws`, `hs`, `gs`, `wd`, `hd`, `l1`, `l2`, `w`, `h`, `top_side`, `bottom_side`, `left_side`, `right_side`, `lm`) VALUES
(1, 1, '测试1', NULL, '30.00', '60.00', '120.00', '6.00', '15.00', '5.00', '100.00', '4.00', '5.00', '4.00', '20.00', '4.00', '5.00', '1800.00', '200.00', '4.00', '5.00', '20.00', '10.00', '15.00', '15.00', '600.00');

-- --------------------------------------------------------

--
-- 表的结构 `design_eval_unit`
--

CREATE TABLE IF NOT EXISTS `design_eval_unit` (
  `id` int(11) NOT NULL,
  `design_eval_unit_partition_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  `num` int(11) DEFAULT NULL,
  `l` decimal(8,2) DEFAULT NULL,
  `t` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_42` (`design_eval_unit_partition_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 表的结构 `design_eval_unit_partition`
--

CREATE TABLE IF NOT EXISTS `design_eval_unit_partition` (
  `id` int(11) NOT NULL,
  `name` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  `l2` decimal(8,2) DEFAULT NULL,
  `l1` decimal(8,2) DEFAULT NULL,
  `w` decimal(8,2) DEFAULT NULL,
  `h` decimal(8,2) DEFAULT NULL,
  `l` decimal(8,2) DEFAULT NULL,
  `r` decimal(8,2) DEFAULT NULL,
  `t` decimal(8,2) DEFAULT NULL,
  `v` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 表的结构 `design_goaf_technology`
--

CREATE TABLE IF NOT EXISTS `design_goaf_technology` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `design_technology_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_39` (`design_technology_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `design_pore`
--

CREATE TABLE IF NOT EXISTS `design_pore` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `design_eval_unit_id` int(11) DEFAULT NULL,
  `design_site_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `d` decimal(8,2) DEFAULT NULL,
  `x1` decimal(8,2) DEFAULT NULL,
  `y1` decimal(8,2) DEFAULT NULL,
  `z1` decimal(8,2) DEFAULT NULL,
  `x2` decimal(8,2) DEFAULT NULL,
  `y2` decimal(8,2) DEFAULT NULL,
  `z2` decimal(8,2) DEFAULT NULL,
  `length` decimal(8,2) DEFAULT NULL,
  `angle1` decimal(8,2) DEFAULT NULL,
  `angle2` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  `t` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_38` (`design_site_id`),
  KEY `fk_relationship_43` (`design_eval_unit_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `design_site`
--

CREATE TABLE IF NOT EXISTS `design_site` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `design_technology_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `w` decimal(8,2) DEFAULT NULL,
  `h` decimal(8,2) DEFAULT NULL,
  `x` decimal(8,2) DEFAULT NULL,
  `y` decimal(8,2) DEFAULT NULL,
  `z` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_36` (`design_technology_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `design_technology`
--

CREATE TABLE IF NOT EXISTS `design_technology` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `coal_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `region` int(11) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_35` (`coal_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=3 ;

--
-- 转存表中的数据 `design_technology`
--

INSERT INTO `design_technology` (`id`, `coal_id`, `name`, `region`, `comment`) VALUES
(1, 5, NULL, 1, NULL),
(2, 5, NULL, 2, NULL);

-- --------------------------------------------------------

--
-- 表的结构 `design_tunnel_control_point`
--

CREATE TABLE IF NOT EXISTS `design_tunnel_control_point` (
  `id` int(11) NOT NULL,
  `design_eval_unit_partition_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  `x` decimal(8,2) DEFAULT NULL,
  `y` decimal(8,2) DEFAULT NULL,
  `z` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_40` (`design_eval_unit_partition_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 表的结构 `design_work_surf_control_point`
--

CREATE TABLE IF NOT EXISTS `design_work_surf_control_point` (
  `id` int(11) NOT NULL,
  `design_eval_unit_partition_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  `x` decimal(8,2) DEFAULT NULL,
  `y` decimal(8,2) DEFAULT NULL,
  `z` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_41` (`design_eval_unit_partition_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 表的结构 `design_work_surf_technology`
--

CREATE TABLE IF NOT EXISTS `design_work_surf_technology` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `design_technology_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  `top_side` decimal(8,2) DEFAULT NULL,
  `bottom_side` decimal(8,2) DEFAULT NULL,
  `right_side` decimal(8,2) DEFAULT NULL,
  `l1` decimal(8,2) DEFAULT NULL,
  `w` decimal(8,2) DEFAULT NULL,
  `h` decimal(8,2) DEFAULT NULL,
  `l2` decimal(8,2) DEFAULT NULL,
  `left_side` decimal(8,2) DEFAULT NULL,
  `v_offset` decimal(8,2) DEFAULT NULL,
  `h_offset` decimal(8,2) DEFAULT NULL,
  `p_offset` decimal(8,2) DEFAULT NULL,
  `wd` decimal(8,2) DEFAULT NULL,
  `hd` decimal(8,2) DEFAULT NULL,
  `lm` decimal(8,2) DEFAULT NULL,
  `ws` decimal(8,2) DEFAULT NULL,
  `ls` decimal(8,2) DEFAULT NULL,
  `gs` decimal(8,2) DEFAULT NULL,
  `hs` decimal(8,2) DEFAULT NULL,
  `dp` decimal(8,2) DEFAULT NULL,
  `gp` decimal(8,2) DEFAULT NULL,
  `single_rock_tunnel` int(11) DEFAULT NULL,
  `d_offset` decimal(8,2) DEFAULT NULL,
  `pore_stubble` decimal(8,2) DEFAULT NULL,
  `pore_angle` decimal(8,2) DEFAULT NULL,
  `pore_type` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_37` (`design_technology_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=3 ;

--
-- 转存表中的数据 `design_work_surf_technology`
--

INSERT INTO `design_work_surf_technology` (`id`, `design_technology_id`, `name`, `comment`, `top_side`, `bottom_side`, `right_side`, `l1`, `w`, `h`, `l2`, `left_side`, `v_offset`, `h_offset`, `p_offset`, `wd`, `hd`, `lm`, `ws`, `ls`, `gs`, `hs`, `dp`, `gp`, `single_rock_tunnel`, `d_offset`, `pore_stubble`, `pore_angle`, `pore_type`) VALUES
(1, 2, '测试2', NULL, '20.00', '10.00', '15.00', '800.00', '4.00', '5.00', '200.00', '15.00', '50.00', '15.00', '20.00', '4.00', '5.00', NULL, '5.00', '4.00', '20.00', '4.00', '120.00', '3.00', 1, '30.00', '10.00', '80.00', 1),
(2, 2, 'n1202', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- 表的结构 `drilling_radius_param`
--

CREATE TABLE IF NOT EXISTS `drilling_radius_param` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `coal_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `r` decimal(8,2) DEFAULT NULL,
  `l` decimal(8,2) DEFAULT NULL,
  `k1` decimal(8,2) DEFAULT NULL,
  `rho` decimal(8,2) DEFAULT NULL,
  `q0` decimal(8,2) DEFAULT NULL,
  `a` decimal(8,2) DEFAULT NULL,
  `t` decimal(8,2) DEFAULT NULL,
  `qm` decimal(8,2) DEFAULT NULL,
  `qsum` decimal(8,2) DEFAULT NULL,
  `eta` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_12` (`coal_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `drilling_surf`
--

CREATE TABLE IF NOT EXISTS `drilling_surf` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `work_area_id` int(11) DEFAULT NULL,
  `tunnel_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `qr` decimal(8,2) DEFAULT NULL,
  `qa` decimal(8,2) DEFAULT NULL,
  `fore_qr` decimal(8,2) DEFAULT NULL,
  `fore_qa` decimal(8,2) DEFAULT NULL,
  `q4` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_22` (`tunnel_id`),
  KEY `fk_relationship_27` (`work_area_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=5 ;

--
-- 转存表中的数据 `drilling_surf`
--

INSERT INTO `drilling_surf` (`id`, `work_area_id`, `tunnel_id`, `name`, `qr`, `qa`, `fore_qr`, `fore_qa`, `q4`, `comment`) VALUES
(1, 5, NULL, 'D121', NULL, '11.50', NULL, NULL, NULL, NULL),
(2, 5, NULL, 'D125', NULL, '7.90', NULL, NULL, NULL, NULL),
(4, 6, NULL, 'jjjj', NULL, NULL, NULL, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- 表的结构 `eval_unit`
--

CREATE TABLE IF NOT EXISTS `eval_unit` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `work_surf_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `l` decimal(8,2) DEFAULT NULL,
  `t` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_13` (`work_surf_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `high_drilling_pore`
--

CREATE TABLE IF NOT EXISTS `high_drilling_pore` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `high_drilling_pore_param_id` int(11) DEFAULT NULL,
  `num` int(11) DEFAULT NULL,
  `length` decimal(8,2) DEFAULT NULL,
  `angle` decimal(8,2) DEFAULT NULL,
  `pore_type` int(11) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_34` (`high_drilling_pore_param_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `high_drilling_pore_param`
--

CREATE TABLE IF NOT EXISTS `high_drilling_pore_param` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `work_surf_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `lk` decimal(8,2) DEFAULT NULL,
  `lc` decimal(8,2) DEFAULT NULL,
  `lw` decimal(8,2) DEFAULT NULL,
  `n1` int(11) DEFAULT NULL,
  `n2` int(11) DEFAULT NULL,
  `beta` decimal(8,2) DEFAULT NULL,
  `ld` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_33` (`work_surf_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=2 ;

--
-- 转存表中的数据 `high_drilling_pore_param`
--

INSERT INTO `high_drilling_pore_param` (`id`, `work_surf_id`, `name`, `lk`, `lc`, `lw`, `n1`, `n2`, `beta`, `ld`, `comment`) VALUES
(1, 1, NULL, '77.01', '30.00', '186.00', 16, 24, NULL, '130.00', NULL);

-- --------------------------------------------------------

--
-- 表的结构 `high_drilling_site_param`
--

CREATE TABLE IF NOT EXISTS `high_drilling_site_param` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `work_surf_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `l1` decimal(8,2) DEFAULT NULL,
  `l2` decimal(8,2) DEFAULT NULL,
  `lg` decimal(8,2) DEFAULT NULL,
  `hn` decimal(8,2) DEFAULT NULL,
  `theta` decimal(8,2) DEFAULT NULL,
  `q` decimal(8,2) DEFAULT NULL,
  `rtn` decimal(8,2) DEFAULT NULL,
  `hs` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_11` (`work_surf_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=2 ;

--
-- 转存表中的数据 `high_drilling_site_param`
--

INSERT INTO `high_drilling_site_param` (`id`, `work_surf_id`, `name`, `l1`, `l2`, `lg`, `hn`, `theta`, `q`, `rtn`, `hs`, `comment`) VALUES
(1, 1, NULL, NULL, NULL, NULL, '3.00', '10.00', '145.60', '8.34', '20.00', NULL);

-- --------------------------------------------------------

--
-- 表的结构 `high_drilling_tunnel`
--

CREATE TABLE IF NOT EXISTS `high_drilling_tunnel` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `work_surf_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `k` decimal(8,2) DEFAULT NULL,
  `rock` int(11) DEFAULT NULL,
  `hz_min` decimal(8,2) DEFAULT NULL,
  `hz_max` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_5` (`work_surf_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `hydr_geo`
--

CREATE TABLE IF NOT EXISTS `hydr_geo` (
  `id` int(11) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `x1` int(11) DEFAULT NULL,
  `x2` int(11) DEFAULT NULL,
  `x3` int(11) DEFAULT NULL,
  `x4` decimal(8,2) DEFAULT NULL,
  `x5` decimal(8,2) DEFAULT NULL,
  `x6` decimal(8,2) DEFAULT NULL,
  `x7` decimal(8,2) DEFAULT NULL,
  `x8` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 表的结构 `mine`
--

CREATE TABLE IF NOT EXISTS `mine` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tech_mode_id` int(11) DEFAULT NULL,
  `mine_region_id` int(11) DEFAULT NULL,
  `account_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `province` varchar(20) DEFAULT NULL,
  `city` varchar(20) DEFAULT NULL,
  `capacity` decimal(8,2) DEFAULT NULL,
  `topo_geo` int(11) DEFAULT NULL,
  `hydr_geo` int(11) DEFAULT NULL,
  `ground_condition` int(11) DEFAULT NULL,
  `qr` decimal(8,2) DEFAULT NULL,
  `qa` decimal(8,2) DEFAULT NULL,
  `fore_qr` decimal(8,2) DEFAULT NULL,
  `fore_qa` decimal(8,2) DEFAULT NULL,
  `gas_k1` decimal(8,2) DEFAULT NULL,
  `gas_k2` decimal(8,2) DEFAULT NULL,
  `stereo_schem_diagram` varchar(255) DEFAULT NULL,
  `rock_gas_k2` decimal(8,2) DEFAULT NULL,
  `reserve_w1` decimal(8,2) DEFAULT NULL,
  `reserve_w2` decimal(8,2) DEFAULT NULL,
  `reserve_w3` decimal(8,2) DEFAULT NULL,
  `gas_w0` decimal(8,2) DEFAULT NULL,
  `gas_wc2` decimal(8,2) DEFAULT NULL,
  `pump_k2` decimal(8,2) DEFAULT NULL,
  `pump_k3` decimal(8,2) DEFAULT NULL,
  `pump_k4` decimal(8,2) DEFAULT NULL,
  `pump_k1` decimal(8,2) DEFAULT NULL,
  `pump_k` decimal(8,2) DEFAULT NULL,
  `pump_wc` decimal(8,2) DEFAULT NULL,
  `reserve_gas` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_19` (`mine_region_id`),
  KEY `fk_relationship_28` (`account_id`),
  KEY `fk_relationship_30` (`tech_mode_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='账户管理数据表（包括矿井的基本信息）' AUTO_INCREMENT=6 ;

--
-- 转存表中的数据 `mine`
--

INSERT INTO `mine` (`id`, `tech_mode_id`, `mine_region_id`, `account_id`, `name`, `province`, `city`, `capacity`, `topo_geo`, `hydr_geo`, `ground_condition`, `qr`, `qa`, `fore_qr`, `fore_qa`, `gas_k1`, `gas_k2`, `stereo_schem_diagram`, `rock_gas_k2`, `reserve_w1`, `reserve_w2`, `reserve_w3`, `gas_w0`, `gas_wc2`, `pump_k2`, `pump_k3`, `pump_k4`, `pump_k1`, `pump_k`, `pump_wc`, `reserve_gas`, `comment`) VALUES
(1, NULL, 31, 1, '示范矿区矿井-晋城', '山西', '晋城', NULL, 3, 3, 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(2, NULL, 51, 1, '示范矿区矿井-两淮', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(3, NULL, 76, 1, '示范矿区矿井-松藻', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(4, NULL, 44, 2, '小青', '辽宁', '铁法', '12.00', 3, 3, 1, NULL, NULL, NULL, NULL, '1.25', '1.16', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5, NULL, 32, 3, 'dddd', 'ddd', 'ddd', '120.00', 2, 3, 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- 表的结构 `mine_base`
--

CREATE TABLE IF NOT EXISTS `mine_base` (
  `id` int(11) NOT NULL,
  `name` varchar(50) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='这个只是一个帮助下拉列表，类似于省市县这种3联动菜单，见文档的P8 3.1';

--
-- 转存表中的数据 `mine_base`
--

INSERT INTO `mine_base` (`id`, `name`, `comment`) VALUES
(1, '神东基地', NULL),
(2, '陕北基地', NULL),
(3, '黄陇基地', NULL),
(4, '晋北基地', NULL),
(5, '晋中基地', NULL),
(6, '晋东基地', NULL),
(7, '蒙东(东北)基地', NULL),
(8, '两淮基地', NULL),
(9, '鲁西基地', NULL),
(10, '河南基地', NULL),
(11, '冀中基地', NULL),
(12, '云贵基地', NULL),
(13, '宁东基地', NULL),
(14, '新疆基地', NULL);

-- --------------------------------------------------------

--
-- 表的结构 `mine_region`
--

CREATE TABLE IF NOT EXISTS `mine_region` (
  `id` int(11) NOT NULL,
  `mine_base_id` int(11) DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_23` (`mine_base_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `mine_region`
--

INSERT INTO `mine_region` (`id`, `mine_base_id`, `name`, `comment`) VALUES
(1, 1, '神东', NULL),
(2, 1, '万利', NULL),
(3, 1, '准格尔', NULL),
(4, 1, '包头', NULL),
(5, 1, '乌海', NULL),
(6, 1, '府谷', NULL),
(7, 2, '榆神', NULL),
(8, 2, '榆横', NULL),
(9, 3, '彬长(含永陇)', NULL),
(10, 3, '黄陵', NULL),
(11, 3, '旬耀', NULL),
(12, 3, '铜川', NULL),
(13, 3, '蒲白', NULL),
(14, 3, '澄合', NULL),
(15, 3, '韩城', NULL),
(16, 3, '华亭', NULL),
(17, 4, '大同', NULL),
(18, 4, '平朔', NULL),
(19, 4, '朔南', NULL),
(20, 4, '轩岗', NULL),
(21, 4, '河保偏', NULL),
(22, 4, '岚县', NULL),
(23, 5, '西山', NULL),
(24, 5, '东山', NULL),
(25, 5, '汾西', NULL),
(26, 5, '霍州', NULL),
(27, 5, '离柳', NULL),
(28, 5, '乡宁', NULL),
(29, 5, '霍东', NULL),
(30, 5, '石隰', NULL),
(31, 6, '晋城', NULL),
(32, 6, '潞安', NULL),
(33, 6, '阳泉', NULL),
(34, 6, '武夏', NULL),
(35, 7, '扎赉诺尔', NULL),
(36, 7, '宝日希勒', NULL),
(37, 7, '伊敏', NULL),
(38, 7, '大雁', NULL),
(39, 7, '霍林河', NULL),
(40, 7, '平庄', NULL),
(41, 7, '白音华', NULL),
(42, 7, '胜利', NULL),
(43, 7, '阜新', NULL),
(44, 7, '铁法', NULL),
(45, 7, '沈阳', NULL),
(46, 7, '抚顺', NULL),
(47, 7, '鸡西', NULL),
(48, 7, '七台河', NULL),
(49, 7, '双鸭山', NULL),
(50, 7, '鹤岗', NULL),
(51, 8, '两淮', NULL),
(52, 9, '兖州', NULL),
(53, 9, '济宁', NULL),
(54, 9, '新汶', NULL),
(55, 9, '枣滕', NULL),
(56, 9, '龙口', NULL),
(57, 9, '淄博', NULL),
(58, 9, '肥城', NULL),
(59, 9, '巨野', NULL),
(60, 9, '黄河北', NULL),
(61, 10, '鹤壁', NULL),
(62, 10, '焦作', NULL),
(63, 10, '义马', NULL),
(64, 10, '郑州', NULL),
(65, 10, '平顶山', NULL),
(66, 10, '永夏', NULL),
(67, 11, '峰峰', NULL),
(68, 11, '邯郸', NULL),
(69, 11, '邢台', NULL),
(70, 11, '井陉', NULL),
(71, 11, '开滦', NULL),
(72, 11, '蔚县', NULL),
(73, 11, '宣化下花园', NULL),
(74, 11, '张家口北部', NULL),
(75, 11, '平原大型煤田', NULL),
(76, 12, '松藻', NULL),
(77, 12, '盘县', NULL),
(78, 12, '普兴', NULL),
(79, 12, '水城', NULL),
(80, 12, '六枝', NULL),
(81, 12, '织纳', NULL),
(82, 12, '黔北', NULL),
(83, 12, '老厂', NULL),
(84, 12, '小龙潭', NULL),
(85, 12, '昭通', NULL),
(86, 12, '镇雄', NULL),
(87, 12, '恩洪', NULL),
(88, 12, '筠连', NULL),
(89, 12, '古叙', NULL),
(90, 13, '石嘴山', NULL),
(91, 13, '石炭笋', NULL),
(92, 13, '灵武', NULL),
(93, 13, '鸳鸯湖', NULL),
(94, 13, '横城', NULL),
(95, 13, '韦州', NULL),
(96, 13, '马家滩', NULL),
(97, 14, '吐哈', NULL),
(98, 14, '准噶尔', NULL),
(99, 14, '伊犁', NULL),
(100, 14, '库拜', NULL);

-- --------------------------------------------------------

--
-- 表的结构 `pore_flow`
--

CREATE TABLE IF NOT EXISTS `pore_flow` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `t` decimal(8,2) DEFAULT NULL,
  `a0` decimal(8,2) DEFAULT NULL,
  `d` decimal(8,2) DEFAULT NULL,
  `d1` decimal(8,2) DEFAULT NULL,
  `m` decimal(8,2) DEFAULT NULL,
  `k` decimal(8,2) DEFAULT NULL,
  `delta_t` decimal(8,2) DEFAULT NULL,
  `x` decimal(8,2) DEFAULT NULL,
  `p_test` decimal(8,2) DEFAULT NULL,
  `p_cur` decimal(8,2) DEFAULT NULL,
  `b` decimal(8,2) DEFAULT NULL,
  `pt` decimal(8,2) DEFAULT NULL,
  `delta_p` decimal(8,2) DEFAULT NULL,
  `dh` decimal(8,2) DEFAULT NULL,
  `q_hun` decimal(8,2) DEFAULT NULL,
  `q_chun` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `pore_size`
--

CREATE TABLE IF NOT EXISTS `pore_size` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `q` decimal(8,2) DEFAULT NULL,
  `v` decimal(8,2) DEFAULT NULL,
  `d` decimal(8,2) DEFAULT NULL,
  `p` decimal(8,2) DEFAULT NULL,
  `sigma` decimal(8,2) DEFAULT NULL,
  `delta` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `res_abundance`
--

CREATE TABLE IF NOT EXISTS `res_abundance` (
  `id` int(11) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `min_abundance` decimal(8,2) DEFAULT NULL,
  `max_abundance` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `res_abundance`
--

INSERT INTO `res_abundance` (`id`, `name`, `min_abundance`, `max_abundance`) VALUES
(1, '高', '3.00', '3.00'),
(2, '中', '0.50', '0.50'),
(3, '低', '-1.00', '-1.00');

-- --------------------------------------------------------

--
-- 表的结构 `rock`
--

CREATE TABLE IF NOT EXISTS `rock` (
  `id` int(11) NOT NULL,
  `name` varchar(50) DEFAULT NULL,
  `a` decimal(3,1) DEFAULT NULL,
  `b` decimal(3,1) DEFAULT NULL,
  `c` decimal(3,1) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `rock`
--

INSERT INTO `rock` (`id`, `name`, `a`, `b`, `c`, `comment`) VALUES
(1, '坚硬岩石', '1.2', '2.0', '2.0', NULL),
(2, '中硬岩石', '1.6', '3.6', '3.6', NULL),
(3, '软弱岩石', '3.1', '5.0', '5.0', NULL),
(4, '极软弱岩石', '5.0', '8.0', '8.0', NULL);

-- --------------------------------------------------------

--
-- 表的结构 `sys_info`
--

CREATE TABLE IF NOT EXISTS `sys_info` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `account_id` int(11) DEFAULT NULL,
  `last_login_time` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_29` (`account_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='记录当前的一些信息，比如当前用户' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `technology`
--

CREATE TABLE IF NOT EXISTS `technology` (
  `id` int(11) NOT NULL,
  `mine_region_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `iskey` int(11) DEFAULT NULL,
  `doc` varchar(255) DEFAULT NULL,
  `video` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_24` (`mine_region_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `technology`
--

INSERT INTO `technology` (`id`, `mine_region_id`, `name`, `iskey`, `doc`, `video`, `comment`) VALUES
(1, 31, '定向长钻孔条带预抽技术', 0, NULL, NULL, NULL),
(2, 31, '定向顺层羽状分支孔抽采技术', 0, NULL, NULL, NULL),
(3, 31, '近距离顶板梳状钻孔抽采技术', 0, NULL, NULL, NULL),
(4, 31, '远距离顶板梳状钻孔抽采技术', 0, NULL, NULL, NULL),
(5, 31, '近距离底板梳状钻孔抽采技术', 0, NULL, NULL, NULL),
(6, 31, '区域递进式模块化抽采', 0, NULL, NULL, NULL),
(7, 31, '采空区煤层气抽采技术', 0, NULL, NULL, NULL),
(8, 31, '中硬煤层顺煤层井下长钻孔钻进工艺', 1, NULL, NULL, NULL),
(9, 31, '软硬复合破碎煤层顺煤层抽采技术工艺', 1, NULL, NULL, NULL),
(10, 76, '专用瓦斯抽采巷穿层钻孔预抽煤层气技术', 0, NULL, NULL, NULL),
(11, 76, '本煤层顺层钻孔抽采煤层气技术', 0, NULL, NULL, NULL),
(12, 76, '专用瓦斯抽采巷穿层抽采卸压煤层气技术', 0, NULL, NULL, NULL),
(13, 76, '石门揭煤穿层钻孔压裂高效抽采技术', 0, NULL, NULL, NULL),
(14, 76, '采空区煤层气抽采技术', 0, NULL, NULL, NULL),
(15, 76, '高压水力压裂增透抽采技术', 1, NULL, NULL, NULL),
(16, 76, '松软突出煤层顺层孔连续套管护孔技术', 1, NULL, NULL, NULL),
(17, 51, '底板岩巷穿层条带预抽', 0, NULL, NULL, NULL),
(18, 51, '本煤层顺层钻孔抽采', 0, NULL, NULL, NULL),
(19, 51, '底板岩巷大面积抽采卸压瓦斯', 0, NULL, NULL, NULL),
(20, 51, '顶板高抽巷抽采卸压瓦斯技术', 0, NULL, NULL, NULL),
(21, 51, '顶板走向高位钻孔抽采煤层气技术', 0, NULL, NULL, NULL),
(22, 51, '石门揭煤钻扩增透高效抽采技术', 0, NULL, NULL, NULL),
(23, 51, '“一面三巷、一巷多用、联合治理、连续开采”的煤层气立体抽采模式', 0, NULL, NULL, NULL),
(24, 51, '采空区煤层气抽采技术', 0, NULL, NULL, NULL),
(25, 51, '沿空留巷快速充填及防断孔技术', 1, NULL, NULL, NULL),
(26, 51, '松软煤层钻进技术', 1, NULL, NULL, NULL),
(27, 51, '高压水射流割缝增透抽采技术', 1, NULL, NULL, NULL),
(28, 51, '全程护孔下筛管护孔技术', 1, NULL, NULL, NULL),
(29, 51, '掏穴钻孔增透技术', 1, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- 表的结构 `tech_mode`
--

CREATE TABLE IF NOT EXISTS `tech_mode` (
  `id` int(11) NOT NULL,
  `mine_region_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `mode_type` int(11) DEFAULT NULL,
  `c1` int(11) DEFAULT NULL,
  `c2` int(11) DEFAULT NULL,
  `c3` int(11) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_25` (`mine_region_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `tech_mode`
--

INSERT INTO `tech_mode` (`id`, `mine_region_id`, `name`, `mode_type`, `c1`, `c2`, `c3`, `comment`) VALUES
(1, 31, '中高渗单一煤层条件井下规模化抽采技术模式', NULL, 0, 0, 0, NULL),
(2, 31, '中高渗煤层群条件井下规模化抽采技术模式', NULL, 0, 1, 0, NULL),
(3, 76, '低渗近距离煤层群上保护层开采条件井下规模化抽采技术模式', NULL, 1, 1, 1, NULL),
(4, 51, '低渗中远距离煤层群下保护层开采条件井下规模化抽采技术模式', NULL, 1, 1, 0, NULL),
(5, 51, '低渗单一煤层条件井下规模化抽采技术模式', NULL, 1, 0, 0, NULL);

-- --------------------------------------------------------

--
-- 表的结构 `topo_geo`
--

CREATE TABLE IF NOT EXISTS `topo_geo` (
  `id` int(11) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `feature` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `topo_geo`
--

INSERT INTO `topo_geo` (`id`, `name`, `feature`, `comment`) VALUES
(1, '简单', '高丘陵（相对高差100-200m），低丘陵（相对高差<1km），坡面坡度一般<15°', NULL),
(2, '中等', '中山（海拔高度1km-3.5km），低山（海拔高度<1km），山地起伏高度一般200-500m，坡面坡度一般>15°-25°', NULL),
(3, '复杂', '极高山（海拔高度>5km），高山（海拔高度3.5km-5km），山地起伏高度一般>500m，坡面坡度一般>25°', NULL);

-- --------------------------------------------------------

--
-- 表的结构 `tunnel`
--

CREATE TABLE IF NOT EXISTS `tunnel` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `b` decimal(8,2) DEFAULT NULL,
  `h` decimal(8,2) DEFAULT NULL,
  `l` decimal(8,2) DEFAULT NULL,
  `s` decimal(8,2) DEFAULT NULL,
  `d` decimal(8,2) DEFAULT NULL,
  `wh` decimal(8,2) DEFAULT NULL,
  `v` decimal(8,2) DEFAULT NULL,
  `q3` decimal(8,2) DEFAULT NULL,
  `q0` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  `tunnel_type` int(11) DEFAULT NULL,
  `top_side` decimal(8,2) DEFAULT NULL,
  `bottom_side` decimal(8,2) DEFAULT NULL,
  `left_side` decimal(8,2) DEFAULT NULL,
  `right_side` decimal(8,2) DEFAULT NULL,
  `x1` decimal(8,2) DEFAULT NULL,
  `y1` decimal(8,2) DEFAULT NULL,
  `z1` decimal(8,2) DEFAULT NULL,
  `x2` decimal(8,2) DEFAULT NULL,
  `y2` decimal(8,2) DEFAULT NULL,
  `z2` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='所有的巷道列表' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `work_area`
--

CREATE TABLE IF NOT EXISTS `work_area` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `coal_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `mode` int(11) DEFAULT '1',
  `a` decimal(8,2) DEFAULT NULL,
  `qr` decimal(8,2) DEFAULT NULL,
  `qa` decimal(8,2) DEFAULT NULL,
  `fore_qr` decimal(8,2) DEFAULT NULL,
  `fore_qa` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_9` (`coal_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=8 ;

--
-- 转存表中的数据 `work_area`
--

INSERT INTO `work_area` (`id`, `coal_id`, `name`, `mode`, `a`, `qr`, `qa`, `fore_qr`, `fore_qa`, `comment`) VALUES
(5, 6, '南二采区', 1, '1000.00', NULL, NULL, NULL, NULL, NULL),
(6, 6, '北一采区', 1, NULL, NULL, NULL, NULL, NULL, NULL),
(7, 6, 'xxx', 1, NULL, NULL, NULL, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- 表的结构 `work_surf`
--

CREATE TABLE IF NOT EXISTS `work_surf` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `work_area_id` int(11) DEFAULT NULL,
  `tunnel_id` int(11) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `a` decimal(8,2) DEFAULT NULL,
  `qr` decimal(8,2) DEFAULT NULL,
  `qa` decimal(8,2) DEFAULT NULL,
  `fore_qr` decimal(8,2) DEFAULT NULL,
  `fore_qa` decimal(8,2) DEFAULT NULL,
  `l1` decimal(8,2) DEFAULT NULL,
  `l2` decimal(8,2) DEFAULT NULL,
  `layerable` int(11) DEFAULT NULL,
  `k1` decimal(8,2) DEFAULT NULL,
  `k2` decimal(8,2) DEFAULT NULL,
  `k3` decimal(8,2) DEFAULT NULL,
  `kf` decimal(8,2) DEFAULT NULL,
  `method` int(11) DEFAULT NULL,
  `last_t` decimal(8,2) DEFAULT NULL,
  `qr1` decimal(8,2) DEFAULT NULL,
  `qr2` decimal(8,2) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_relationship_21` (`tunnel_id`),
  KEY `fk_relationship_26` (`work_area_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;

--
-- 转存表中的数据 `work_surf`
--

INSERT INTO `work_surf` (`id`, `work_area_id`, `tunnel_id`, `name`, `a`, `qr`, `qa`, `fore_qr`, `fore_qa`, `l1`, `l2`, `layerable`, `k1`, `k2`, `k3`, `kf`, `method`, `last_t`, `qr1`, `qr2`, `comment`) VALUES
(1, 5, NULL, 'S356', '1000.00', '10.00', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(2, 5, NULL, 'S789', '1000.00', '10.00', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(3, 5, NULL, 'S891', '1000.00', '10.00', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

--
-- 限制导出的表
--

--
-- 限制表 `adj_layer`
--
ALTER TABLE `adj_layer`
  ADD CONSTRAINT `fk_relationship_32` FOREIGN KEY (`coal_id`) REFERENCES `coal` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `fk_relationship_16` FOREIGN KEY (`work_surf_id`) REFERENCES `work_surf` (`id`) ON DELETE CASCADE;

--
-- 限制表 `coal`
--
ALTER TABLE `coal`
  ADD CONSTRAINT `fk_relationship_1` FOREIGN KEY (`mine_id`) REFERENCES `mine` (`id`) ON DELETE CASCADE;

--
-- 限制表 `design_drilling_surf_technology`
--
ALTER TABLE `design_drilling_surf_technology`
  ADD CONSTRAINT `fk_relationship_31` FOREIGN KEY (`design_technology_id`) REFERENCES `design_technology` (`id`) ON DELETE CASCADE;

--
-- 限制表 `design_eval_unit`
--
ALTER TABLE `design_eval_unit`
  ADD CONSTRAINT `fk_relationship_42` FOREIGN KEY (`design_eval_unit_partition_id`) REFERENCES `design_eval_unit_partition` (`id`) ON DELETE CASCADE;

--
-- 限制表 `design_goaf_technology`
--
ALTER TABLE `design_goaf_technology`
  ADD CONSTRAINT `fk_relationship_39` FOREIGN KEY (`design_technology_id`) REFERENCES `design_technology` (`id`) ON DELETE CASCADE;

--
-- 限制表 `design_pore`
--
ALTER TABLE `design_pore`
  ADD CONSTRAINT `fk_relationship_43` FOREIGN KEY (`design_eval_unit_id`) REFERENCES `design_eval_unit` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `fk_relationship_38` FOREIGN KEY (`design_site_id`) REFERENCES `design_site` (`id`) ON DELETE CASCADE;

--
-- 限制表 `design_site`
--
ALTER TABLE `design_site`
  ADD CONSTRAINT `fk_relationship_36` FOREIGN KEY (`design_technology_id`) REFERENCES `design_technology` (`id`) ON DELETE CASCADE;

--
-- 限制表 `design_technology`
--
ALTER TABLE `design_technology`
  ADD CONSTRAINT `fk_relationship_35` FOREIGN KEY (`coal_id`) REFERENCES `coal` (`id`) ON DELETE CASCADE;

--
-- 限制表 `design_tunnel_control_point`
--
ALTER TABLE `design_tunnel_control_point`
  ADD CONSTRAINT `fk_relationship_40` FOREIGN KEY (`design_eval_unit_partition_id`) REFERENCES `design_eval_unit_partition` (`id`) ON DELETE CASCADE;

--
-- 限制表 `design_work_surf_control_point`
--
ALTER TABLE `design_work_surf_control_point`
  ADD CONSTRAINT `fk_relationship_41` FOREIGN KEY (`design_eval_unit_partition_id`) REFERENCES `design_eval_unit_partition` (`id`) ON DELETE CASCADE;

--
-- 限制表 `design_work_surf_technology`
--
ALTER TABLE `design_work_surf_technology`
  ADD CONSTRAINT `fk_relationship_37` FOREIGN KEY (`design_technology_id`) REFERENCES `design_technology` (`id`) ON DELETE CASCADE;

--
-- 限制表 `drilling_radius_param`
--
ALTER TABLE `drilling_radius_param`
  ADD CONSTRAINT `fk_relationship_12` FOREIGN KEY (`coal_id`) REFERENCES `coal` (`id`) ON DELETE CASCADE;

--
-- 限制表 `drilling_surf`
--
ALTER TABLE `drilling_surf`
  ADD CONSTRAINT `fk_relationship_27` FOREIGN KEY (`work_area_id`) REFERENCES `work_area` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `fk_relationship_22` FOREIGN KEY (`tunnel_id`) REFERENCES `tunnel` (`id`) ON DELETE CASCADE;

--
-- 限制表 `eval_unit`
--
ALTER TABLE `eval_unit`
  ADD CONSTRAINT `fk_relationship_13` FOREIGN KEY (`work_surf_id`) REFERENCES `work_surf` (`id`) ON DELETE CASCADE;

--
-- 限制表 `high_drilling_pore`
--
ALTER TABLE `high_drilling_pore`
  ADD CONSTRAINT `fk_relationship_34` FOREIGN KEY (`high_drilling_pore_param_id`) REFERENCES `high_drilling_pore_param` (`id`) ON DELETE CASCADE;

--
-- 限制表 `high_drilling_pore_param`
--
ALTER TABLE `high_drilling_pore_param`
  ADD CONSTRAINT `fk_relationship_33` FOREIGN KEY (`work_surf_id`) REFERENCES `work_surf` (`id`) ON DELETE CASCADE;

--
-- 限制表 `high_drilling_site_param`
--
ALTER TABLE `high_drilling_site_param`
  ADD CONSTRAINT `fk_relationship_11` FOREIGN KEY (`work_surf_id`) REFERENCES `work_surf` (`id`) ON DELETE CASCADE;

--
-- 限制表 `high_drilling_tunnel`
--
ALTER TABLE `high_drilling_tunnel`
  ADD CONSTRAINT `fk_relationship_5` FOREIGN KEY (`work_surf_id`) REFERENCES `work_surf` (`id`) ON DELETE CASCADE;

--
-- 限制表 `mine`
--
ALTER TABLE `mine`
  ADD CONSTRAINT `fk_relationship_30` FOREIGN KEY (`tech_mode_id`) REFERENCES `tech_mode` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `fk_relationship_19` FOREIGN KEY (`mine_region_id`) REFERENCES `mine_region` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `fk_relationship_28` FOREIGN KEY (`account_id`) REFERENCES `account` (`id`) ON DELETE CASCADE;

--
-- 限制表 `mine_region`
--
ALTER TABLE `mine_region`
  ADD CONSTRAINT `fk_relationship_23` FOREIGN KEY (`mine_base_id`) REFERENCES `mine_base` (`id`) ON DELETE CASCADE;

--
-- 限制表 `sys_info`
--
ALTER TABLE `sys_info`
  ADD CONSTRAINT `fk_relationship_29` FOREIGN KEY (`account_id`) REFERENCES `account` (`id`) ON DELETE CASCADE;

--
-- 限制表 `technology`
--
ALTER TABLE `technology`
  ADD CONSTRAINT `fk_relationship_24` FOREIGN KEY (`mine_region_id`) REFERENCES `mine_region` (`id`) ON DELETE CASCADE;

--
-- 限制表 `tech_mode`
--
ALTER TABLE `tech_mode`
  ADD CONSTRAINT `fk_relationship_25` FOREIGN KEY (`mine_region_id`) REFERENCES `mine_region` (`id`) ON DELETE CASCADE;

--
-- 限制表 `work_area`
--
ALTER TABLE `work_area`
  ADD CONSTRAINT `fk_relationship_9` FOREIGN KEY (`coal_id`) REFERENCES `coal` (`id`) ON DELETE CASCADE;

--
-- 限制表 `work_surf`
--
ALTER TABLE `work_surf`
  ADD CONSTRAINT `fk_relationship_26` FOREIGN KEY (`work_area_id`) REFERENCES `work_area` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `fk_relationship_21` FOREIGN KEY (`tunnel_id`) REFERENCES `tunnel` (`id`) ON DELETE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
