#!/usr/bin/gnuplot -c


#1
#Per Seat Avg Won/Lost - Histogram ///////////////////////////////////////
reset

set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
out = sprintf("%s%s", ARG1, "_wonlost.png")
set output out
set datafile separator ":"

t = sprintf("%s%s%s", "Average Won/Lost - Per Seat (%)", "\n", "By Minority Population")
set title t
#unset key

set xrange [-1:26]
set xtics 1
set xlabel "Constituency"
set ylabel "Lost/Won"

set key horiz
set key tmargin
set key box
set key font ",20"

set grid ytics lt 1 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 1 lw 1 lc rgb "#bbbbbb"

set boxwidth 0.9
set style fill solid
plot ARG2 using 1:($3 + $4):xticlabels(2) with boxes lc rgb"red" title "Lost", "" u 1:($3 + $4):4 with labels offset char 0,-1 font 'Verdana,12' textcolor rgb"black" notitle, ARG2 using 1:3:xticlabels(2) with boxes lc rgb"navy" title "Won", "" u 1:3:3 with labels offset char 0, 0 font 'Verdana,12' textcolor rgb"white" notitle
reset
#Per Seat Avg Won/Lost - Histogram ///////////////////////////////////////



#2
#Per Seat Avg Min/Maj Pop - Histogram ///////////////////////////////////////
reset

set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
out = sprintf("%s%s", ARG1, "_minmaj.png")
set output out
set datafile separator ":"

t = sprintf("%s%s%s", "Average Majority and Minority Population", "\n", "Per Seat (%)")
set title t
#unset key

set xrange [-1:26]
set xtics 1
set xlabel "Constituency"
set ylabel "Minority/Majority Fraction"

set key horiz
set key tmargin
set key box
set key font ",20"

set grid ytics lt 1 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 1 lw 1 lc rgb "#bbbbbb"

set boxwidth 0.9
set style fill solid
plot ARG2 using 1:($5 + $6):xticlabels(2) with boxes lc rgb"red" title "Minority", "" u 1:($5 + $6):5 with labels offset char 0,-1 font 'Verdana,12' textcolor rgb"black" notitle, ARG2 using 1:6:xticlabels(2) with boxes lc rgb"navy" title "Majority", "" u 1:6:6 with labels offset char 0, 0 font 'Verdana,12' textcolor rgb"white" notitle
reset
#Per Seat Avg Won/Lost - Histogram ///////////////////////////////////////