#!/usr/bin/gnuplot -c

#1
#FracVar Plots//////////////////////////////////////////////////////////////////////
reset
set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
out = sprintf("%s%s", ARG1, "_varvfracvar.png")
set output out
set datafile separator ":"


set title "Variance v Fractional Variance"

unset key
set autoscale x
set autoscale y

set xlabel "Variance"
set ylabel "Fractional Variance"

set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"

#set style fill transparent solid 0.04 noborder
#set style circle radius 0.01
plot ARG2 u 1:2 with points lc rgb "red"
reset
#FracVar Plots//////////////////////////////////////////////////////////////////////
