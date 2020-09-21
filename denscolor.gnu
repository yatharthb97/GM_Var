#!/usr/bin/gnuplot -c


#ARG1 - ParentPath+RunName --> generate Output Filename
#ARG2 - Data File
#ARG3 - Range 0_x
#ARG4 - Range 1_x
#ARG5 - Range 0_y
#ARG6 - Range 1_y
#ARG7 - Tics x & y

#Density Color Plot///////////////////////////////////////////////////////////
reset

#Palettes---------------------------------------------

# Colormap similar to Matlab parula, see:
# http://www.mathworks.de/products/matlab/matlab-graphics/#new_look_for_matlab_graphics
#Source: https://github.com/Gnuplotting/gnuplot-palettes/blob/master/parula.pal

# line styles
set style line  1 lt 1 lc rgb '#352a87' # blue
set style line  2 lt 1 lc rgb '#0f5cdd' # blue
set style line  3 lt 1 lc rgb '#1481d6' # blue
set style line  4 lt 1 lc rgb '#06a4ca' # cyan
set style line  5 lt 1 lc rgb '#2eb7a4' # green
set style line  6 lt 1 lc rgb '#87bf77' # green
set style line  7 lt 1 lc rgb '#d1bb59' # orange
set style line  8 lt 1 lc rgb '#fec832' # orange
set style line  9 lt 1 lc rgb '#f9fb0e' # yellow

# New default Matlab line colors, introduced together with parula (2014b)
set style line 11 lt 1 lc rgb '#0072bd' # blue
set style line 12 lt 1 lc rgb '#d95319' # orange
set style line 13 lt 1 lc rgb '#edb120' # yellow
set style line 14 lt 1 lc rgb '#7e2f8e' # purple
set style line 15 lt 1 lc rgb '#77ac30' # green
set style line 16 lt 1 lc rgb '#4dbeee' # light-blue
set style line 17 lt 1 lc rgb '#a2142f' # red

# palette
set palette defined (\
0 '#000000',\
1 '#470646',\
2 '#352a87',\
3 '#0363e1',\
4 '#1485d4',\
5 '#06a7c6',\
6 '#38b99e',\
7 '#92bf73',\
8 '#d9ba56',\
9 '#fcce2e',\
10 '#f9fb0e',\
11 '#8C2D04',\
12 '#a2142f')

#Palettes---------------------------------------------


set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
out = sprintf("%s%s", ARG1, "_varvfracvar2.png")
set output out
set datafile separator ":"


set title "Variance v Fractional Variance"

unset key
set xrange [ARG3:ARG4]
set yrange[ARG5:ARG6]
set xtics ARG3, ((ARG4-ARG3)/ARG7), ARG4
set ytics ARG5, ((ARG6-ARG5)/ARG7), ARG6


set xlabel "Variance"
set ylabel "Fractional Variance"

set grid ytics lt 0 lw 1 lc rgb "#bbbbbb" front
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb" front


plot ARG2 using 1:2:3 notitle with points pt 2 palette
reset
#Density Color Plot/////////////////////////////////////////////////////////////////