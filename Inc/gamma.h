/*
 * Enlighted-Otter  -  Stm32f334 based mobile worklight.
 * Copyright (C) 2018 Jan Henrik Hemsing
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 #pragma once

float gammaTable[] = { // generated gamma correction table from Tools/gamma.py gamma value used: 1.6 resolution: 1.00000 
	0.50,	0.52,	0.57,	0.64,	0.72,	0.82,	0.92,	1.04,	1.17,	1.31,	1.46,	1.61,	1.78,	1.96,	2.14,	2.33,
	2.53,	2.74,	2.95,	3.17,	3.40,	3.63,	3.88,	4.13,	4.38,	4.64,	4.91,	5.19,	5.47,	5.75,	6.05,	6.35,
	6.65,	6.96,	7.28,	7.60,	7.93,	8.26,	8.60,	8.94,	9.29,	9.64,	10.00,	10.37,	10.74,	11.11,	11.49,	11.88,
	12.27,	12.66,	13.06,	13.46,	13.87,	14.29,	14.71,	15.13,	15.56,	15.99,	16.43,	16.87,	17.31,	17.76,	18.22,	18.68,
	19.14,	19.61,	20.08,	20.56,	21.04,	21.53,	22.02,	22.51,	23.01,	23.51,	24.02,	24.53,	25.04,	25.56,	26.08,	26.61,
	27.14,	27.68,	28.22,	28.76,	29.30,	29.86,	30.41,	30.97,	31.53,	32.10,	32.67,	33.24,	33.82,	34.40,	34.98,	35.57,
	36.17,	36.76,	37.36,	37.97,	38.57,	39.18,	39.80,	40.42,	41.04,	41.66,	42.29,	42.93,	43.56,	44.20,	44.85,	45.49,
	46.14,	46.80,	47.45,	48.11,	48.78,	49.45,	50.12,	50.79,	51.47,	52.15,	52.84,	53.52,	54.21,	54.91,	55.61,	56.31,
	57.01,	57.72,	58.43,	59.15,	59.87,	60.59,	61.31,	62.04,	62.77,	63.50,	64.24,	64.98,	65.73,	66.47,	67.22,	67.98,
	68.73,	69.49,	70.26,	71.02,	71.79,	72.56,	73.34,	74.12,	74.90,	75.68,	76.47,	77.26,	78.06,	78.85,	79.65,	80.46,
	81.26,	82.07,	82.88,	83.70,	84.52,	85.34,	86.16,	86.99,	87.82,	88.65,	89.49,	90.33,	91.17,	92.01,	92.86,	93.71,
	94.57,	95.42,	96.28,	97.15,	98.01,	98.88,	99.75,	100.62,	101.50,	102.38,	103.26,	104.15,	105.04,	105.93,	106.82,	107.72,
	108.62,	109.52,	110.43,	111.33,	112.24,	113.16,	114.07,	114.99,	115.92,	116.84,	117.77,	118.70,	119.63,	120.57,	121.51,	122.45,
	123.39,	124.34,	125.29,	126.24,	127.19,	128.15,	129.11,	130.07,	131.04,	132.01,	132.98,	133.95,	134.93,	135.91,	136.89,	137.87,
	138.86,	139.85,	140.84,	141.84,	142.84,	143.84,	144.84,	145.84,	146.85,	147.86,	148.88,	149.89,	150.91,	151.93,	152.95,	153.98,
	155.01,	156.04,	157.08,	158.11,	159.15,	160.19,	161.24,	162.28,	163.33,	164.38,	165.44,	166.50,	167.55,	168.62,	169.68,	170.75,
	171.82,	172.89,	173.96,	175.04,	176.12,	177.20,	178.29,	179.37,	180.46,	181.56,	182.65,	183.75,	184.85,	185.95,	187.05,	188.16,
	189.27,	190.38,	191.49,	192.61,	193.73,	194.85,	195.97,	197.10,	198.23,	199.36,	200.49,	201.63,	202.77,	203.91,	205.05,	206.20,
	207.35,	208.50,	209.65,	210.80,	211.96,	213.12,	214.28,	215.45,	216.61,	217.78,	218.96,	220.13,	221.31,	222.49,	223.67,	224.85,
	226.04,	227.22,	228.41,	229.61,	230.80,	232.00,	233.20,	234.40,	235.61,	236.81,	238.02,	239.23,	240.45,	241.66,	242.88,	244.10,
	245.33,	246.55,	247.78,	249.01,	250.24,	251.48,	252.71,	253.95,	255.19,	256.44,	257.68,	258.93,	260.18,	261.43,	262.69,	263.94,
	265.20,	266.47,	267.73,	269.00,	270.26,	271.53,	272.81,	274.08,	275.36,	276.64,	277.92,	279.21,	280.49,	281.78,	283.07,	284.36,
	285.66,	286.96,	288.26,	289.56,	290.86,	292.17,	293.48,	294.79,	296.10,	297.41,	298.73,	300.05,	301.37,	302.69,	304.02,	305.35,
	306.68,	308.01,	309.35,	310.68,	312.02,	313.36,	314.70,	316.05,	317.40,	318.75,	320.10,	321.45,	322.81,	324.17,	325.53,	326.89,
	328.25,	329.62,	330.99,	332.36,	333.73,	335.11,	336.49,	337.87,	339.25,	340.63,	342.02,	343.40,	344.79,	346.19,	347.58,	348.98,
	350.38,	351.78,	353.18,	354.58,	355.99,	357.40,	358.81,	360.22,	361.64,	363.06,	364.48,	365.90,	367.32,	368.75,	370.17,	371.60,
	373.04,	374.47,	375.90,	377.34,	378.78,	380.23,	381.67,	383.12,	384.56,	386.01,	387.47,	388.92,	390.38,	391.84,	393.30,	394.76,
	396.22,	397.69,	399.16,	400.63,	402.10,	403.58,	405.05,	406.53,	408.01,	409.50,	410.98,	412.47,	413.96,	415.45,	416.94,	418.44,
	419.93,	421.43,	422.93,	424.44,	425.94,	427.45,	428.96,	430.47,	431.98,	433.50,	435.01,	436.53,	438.05,	439.58,	441.10,	442.63,
	444.16,	445.69,	447.22,	448.75,	450.29,	451.83,	453.37,	454.91,	456.46,	458.00,	459.55,	461.10,	462.66,	464.21,	465.77,	467.33,
	468.89,	470.45,	472.01,	473.58,	475.15,	476.72,	478.29,	479.86,	481.44,	483.02,	484.60,	486.18,	487.76,	489.35,	490.93,	492.52,
	494.12,	495.71,	497.30,	498.90 };