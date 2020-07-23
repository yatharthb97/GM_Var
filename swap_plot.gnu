#!/usr/bin/gnuplot -c

#3
#Frequency Plot - Histogram/////////////////////////////////////////////////////////

reset

set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
out = sprintf("%s%s", ARG1, "_swap_plot.png")
set output out
set datafile separator ":"

t = sprintf("%s%s%s", "Swap Frequency Plot", "\n", "(Sum Over All Measurements)")
set title t
unset key

set xrange [-1:25]
set xtics 1
set xlabel "Constituency Size"
set ylabel "Swap Frequency"

set grid ytics lt 1 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 1 lw 1 lc rgb "#bbbbbb"

set boxwidth 0.9
set style fill solid
plot ARG2 using 1:2:xticlabels(3) with boxes lc rgb "gray0", "" u 1:2:2 with labels offset char 0,1 font 'Verdana,6'
reset
#Frequency Plot - Histogram/////////////////////////////////////////////////////////