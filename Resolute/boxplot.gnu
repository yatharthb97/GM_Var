#!/usr/bin/gnuplot -c


reset
set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
set output ARG1
set datafile separator ":"
set xtics 0,1,20
set ytics 0,20,200
t = sprintf("%s%s%s", "Minority Seats Won - Variance", "\n", "(All Data Points)")
set title t
unset key
set xlabel "Minority Seats"
set ylabel "Variance"
plot ARG2 using 3:2 pt 1
reset