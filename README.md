# GM_Var
A Statistical Study of Ghettoisation and Gerrymandering.

Layout of the code:
0. Start
1. Create Filesystem and assign paths
2. According to the set parameters - decide on the total minority population
3. Create different constituencies with the given con_max distribution
4. Assign Minority population to different constituencies. - Initial Settlement
5. Mix the minority poulations - Migration
6. Conduct Elections * No. of Measurenments
7. Generate configuration files
8. Plot data via launching gnuplot scripts
9. Repeat for iteration(2 &#8594; 8) if iterations > 1
10. End

Important Points:
+ A unique name has to be parsed in the ARGS. Or the files append to the Parent Path given to the program.
+ The program creates a directory with the provided Run Name
+ Multiple iterations can be performed by changing the parameters - in the iteration block. (Director Name Run_Name_i &#8594; i is the i<sup>th</sup> iteration)
+ Used Ranlux48 base generator as PRNG.
+ For Seeding Random Number Generator - System Entropy is used.
+ Make file - "make" -  to compile; "make clean" - to clean files

Different Plots Generated (Typical Run):

![No of Seats Won by Minority - Histogram](https://github.com/yatharthb97/GM_Var/blob/c++/READ_ME%20Samples/freqhist.png?raw=true)
![Successful Swaps for Every Constituency](https://github.com/yatharthb97/GM_Var/blob/c++/READ_ME%20Samples/swap_plot.png?raw=true)
![Scatter Plot - Variance v Fractional Variance](https://github.com/yatharthb97/GM_Var/blob/c++/READ_ME%20Samples/point5_10%5E7me_4_0_varvfracvar.png?raw=true)


![Min_Max_Mean_Diff - Fractional Variance v No of Seats Won](https://github.com/yatharthb97/GM_Var/blob/c++/READ_ME%20Samples/Frac_var.png?raw=true)
![Min_Max_Mean_Diff - Variance v No of Seats Won](https://github.com/yatharthb97/GM_Var/blob/c++/READ_ME%20Samples/Frac_var.png?raw=true)


![Seats Won_Lost Avg per Constituency](https://github.com/yatharthb97/GM_Var/blob/c++/READ_ME%20Samples/wonlost.png?raw=true)
![Seat Population Distribution - Averaged](https://github.com/yatharthb97/GM_Var/blob/c++/READ_ME%20Samples/minmaj.png?raw=true)


![Number of times Zero Variance was recorded for Fractional Variance Plots](https://github.com/yatharthb97/GM_Var/blob/c++/READ_ME%20Samples/zerofracvarhist.png?raw=true)
![Number of times Zero Variance was recorded for Variance Plots](https://github.com/yatharthb97/GM_Var/blob/c++/READ_ME%20Samples/zerovarhist.png?raw=true)

--------------------------------------------------------------------
***
