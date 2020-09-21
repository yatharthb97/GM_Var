#!/usr/bin/gnuplot -c


reset
set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
set output ARG1
set datafile separator ":"

t = sprintf("%s%s%s", "Minority Seats Won - Histogram", "\n", "(All Data Points)")
set title t
unset key
set style fill solid 0.5 # fill style
set xlabel "Minority Seats"
set ylabel "Frequency"

set xrange [0:25]
set xtics 1

set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"

binwidth=1
bin(x,width)=width*floor(x/width)
set boxwidth binwidth
plot ARG2 using (bin($3,binwidth)):(1.0) smooth freq with boxes lc rgb"gray0" notitle

reset


