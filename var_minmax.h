/* mmm  m    m        m    m   mm   mmmmm	|	Developed by: Yatharth Bhasin
 m"   " ##  ##        "m  m"   ##   #   "#  |	Discipline of Physics
 #   mm # ## #         #  #   #  #  #mmmm"  |	IIT Indore
 #    # # "" #         "mm"   #mm#  #   "m  |	(yatharth1997@gmail.com)
  "mmm" #    #__________##   #    # #    "  |	(git: yatharthb97)
  											|	Licence: *******************
//---------------------------------------------------------------------------------

//Gerrymandering Variance Analysis - GM_VAR v1.0
  Header File defining the variance table
//-----------------------------------------------------------------------------------
//		+++ Notes - InComplete, +++ Status - Not Tested
//-----------------------------------------------------------------------------------
*/
/*Notes

*/

//Preprocessor Commands
#pragma once
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

/**Class for storing Variance Values. For every "No. of Seats Won per Election" - A min, max, mean, sum of all values(stack), (count - frequeny of occurance)
 */
class VarTable
{

	std::vector<double> min;
	std::vector<double> max;
	std::vector<double> mean;
	std::vector<double> stack;
	std::vector<double> count;
	std::vector<int> zero_freq;

public:


	//1
	//Constructor
	//!Class Constructor. Initializes the table.
 	/*
 	\param tab_size size of variance table.
 	*/
	VarTable(int tab_size)
	{
		min.reserve(tab_size);
		max.reserve(tab_size);
		mean.reserve(tab_size);
		stack.reserve(tab_size);
		count.reserve(tab_size);
		zero_freq.reserve(tab_size);

		for(unsigned int i = 0; i < tab_size; i++)
		{
			min.push_back(0);
			max.push_back(0);
			mean.push_back(0);
			stack.push_back(0);
			count.push_back(0);
			zero_freq.push_back(0);
		}
	}//End of Constructor
	//**********************************************************************************

	//!Function that updates the varance table
 	/*
 	\param seats won seats during measurement
 	\return variance variance of the seat distribution obtained
 	*/
	void Push(int seats, double variance)
	{
		
		//Minimum Comparision
		if(variance < 0.00000001 && variance > -0.00000001) //### Machine Epsilon  - 10e-8
		{
			zero_freq.at(seats)++;
		}

		else
		{
			if(min.at(seats) == 0) {min.at(seats) = variance;}
			else min.at(seats) = std::min(min.at(seats), variance);
		}	

		max.at(seats) = std::max(max.at(seats), variance);
		stack.at(seats)+= variance;
		count.at(seats)++;
	}//End of Push()
//**********************************************************************************
	//!Function that prints the variance table
 	/*
 	\param string filename of the file for printing the variance table
 	*/
	void Print(string filename)
	{
		ostringstream buffer;
		for(unsigned int i = 0; i <=25; i++)
		{
					
			buffer << setprecision(10)
			<< i << ":" << min.at(i) << ":" << max.at(i) << ":" << (max.at(i) - min.at(i)) 
			<< ":" << (count.at(i)!=0 ? (stack.at(i)/count.at(i)) : 0) << ":" << count.at(i)
			<< ":" << zero_freq.at(i)
 			<< "\n";
		}

		ofstream file(filename, ios::out);
		file << buffer.str();
		file.close();
	}//End of Print()
//**********************************************************************************



	//Exp1 ? Exp2 : Exp3;
	//count.at(i)!=0 ? (stack.at(i)/count.at(i)) : 0


}; //End of class VarTable
//**********************************************************************************


////////////////////////////////END OF TRANSLATION UNIT/////////////////////////
