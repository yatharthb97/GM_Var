#!/usr/bin/gnuplot -c


#1
#FracVar Plots//////////////////////////////////////////////////////////////////////
reset
set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
out = sprintf("%s%s", ARG1, "_fracvarplots.png")
set output out
set datafile separator ":"


set title "Fractional Variance Plots"


set xrange [0:25]
set xtics 1

set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"

set xlabel "Minority Seats Won"
set ylabel "Fractional Variance"

plot ARG2 using 1:2 with linespoints lt rgb "red" lw 3 title "Minimum",\
     ARG2 using 1:3 with linespoints lt rgb "blue" lw 3  title "Maximum",\
     ARG2 using 1:4 with linespoints lt rgb "green" lw 3  title "Difference",\
     ARG2 using 1:5 with linespoints lt rgb "black" lw 3  title "Mean"
reset
#FracVar Plots//////////////////////////////////////////////////////////////////////



#2
#Var Plots//////////////////////////////////////////////////////////////////////////
reset
set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
out = sprintf("%s%s", ARG1, "_varplots.png")
set output out
set datafile separator ":"


set title "Variance Plots"


set xrange [0:25]
set xtics 1

set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"

set xlabel "Minority Seats Won"
set ylabel "Variance"

plot ARG3 using 1:2 with linespoints lt rgb "red" lw 3 title "Minimum",\
     ARG3 using 1:3 with linespoints lt rgb "blue" lw 3  title "Maximum",\
     ARG3 using 1:4 with linespoints lt rgb "green" lw 3  title "Difference",\
     ARG3 using 1:5 with linespoints lt rgb "black" lw 3  title "Mean"
reset
#Var Plots//////////////////////////////////////////////////////////////////////////




#3
#Frequency Plot - Histogram/////////////////////////////////////////////////////////
reset

set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
out = sprintf("%s%s", ARG1, "_freqhist.png")
set output out
set datafile separator ":"

t = sprintf("%s%s%s", "Minority Seats Won - Histogram", "\n", "(All Data Points)")
set title t
unset key

set xrange [-1:26]
set xtics 1
set xlabel "Minority Seats"
set ylabel "Frequency"

set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"

set boxwidth 0.9
set style fill solid
plot ARG2 using 1:6 with boxes lc rgb"gray0", "" u 1:6:6 with labels offset char 0,1 font 'Verdana,6'
reset
#Frequency Plot - Histogram/////////////////////////////////////////////////////////



#4
#Frac Variance - Histogram/////////////////////////////////////////////////////////
reset

set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
out = sprintf("%s%s", ARG1, "_zerofracvarhist.png")
set output out
set datafile separator ":"

t = sprintf("%s%s%s", "Zero Frac Variance Count - Histogram", "\n", "Fractional Variance")
set title t
unset key

set xrange [-1:26]
set xtics 1
set xlabel "Minority Seats Won"
set ylabel "Frequency"

set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"

set boxwidth 0.9
set style fill solid
plot ARG2 using 1:7 with boxes lc rgb"grey20", "" u 1:7:7 with labels offset char 0,1 font 'Verdana,6'
reset
#Frac Variance - Histogram/////////////////////////////////////////////////////////


#5
#Frac Variance - Histogram/////////////////////////////////////////////////////////
reset

set term pngcairo size 1920, 1080 enhanced font 'Verdana,20'
out = sprintf("%s%s", ARG1, "_zerovarhist.png")
set output out
set datafile separator ":"

t = sprintf("%s%s%s", "Zero Variance Count - Histogram", "\n", "Variance")
set title t
unset key

set xrange [-1:26]
set xtics 1
set xlabel "Minority Seats Won"
set ylabel "Frequency"

set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"

set boxwidth 0.9
set style fill solid
plot ARG3 using 1:7 with boxes lc rgb"navy", "" u 1:7:7 with labels offset char 0,1 font 'Verdana,6'
reset
#Variance - Histogram/////////////////////////////////////////////////////////