#pragma once
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include "macros.h"
#include "utilities.h"

//Redundant as the Range is pre-determined. Sorting operations can be easily avoided

void DensityColorPlot(const double xdat[], const double ydat[],
					  int siz, int Bin, double Delta, const std::string &parent_path,
					  const std::string &run_name)
{

	double struct_x_0 = 0;
	double struct_x_1 = 0;
	double struct_y_0 = 0;
	double struct_y_1 = 0;


	size_t arrsiz = sizeof(double)*siz;

	//Assign Struct -> Replace operations by memcopy
	//memcpy (struct_x, xdat, arrsiz);
	//memcpy (struct_y, ydat, arrsiz);
	
	//Sorting Done
	//std::sort(struct_x, struct_x+siz);
	//std::sort(struct_y, struct_y+siz);

	struct_x_0 = *std::min_element(xdat, xdat+siz);
	struct_x_1 = *std::max_element(xdat, xdat+siz);

	struct_y_0 = *std::min_element(ydat, ydat+siz);
	struct_y_1 = *std::max_element(ydat, ydat+siz);

	//cout << "struct_x_0: " << struct_x_0 << "  struct_x[end]: " << struct_x_1 << endl;
	//cout << "struct_y_0: " << struct_y_0 << "  struct_y[end]: " << struct_y_1 << endl;
	

	//underflow Safety
	if(std::isnan(struct_x_0))
		struct_x_0 = 0;
	if(std::isnan(struct_y_0))
		struct_y_1 = 0;


	double range_x = std::fabs(struct_x_1 - struct_x_0);
	double range_y = std::fabs(struct_y_1 - struct_y_0);


	double bin_size_x = range_x/Bin;
	double bin_size_y = range_y/Bin;


	double cut_x = bin_size_x/Delta;
	double cut_y = bin_size_y/Delta;
	//cout << cut_x << endl << cut_y << endl;


	int occupancy[siz] = {0};

	//Two Loops
	for(int i = 0; i<siz; i++)
	{

		for(int j=0; j<i; j++)
		{
			if(std::fabs(xdat[i]-xdat[j]) <=cut_x 
			 && std::fabs(ydat[i]-ydat[j]) <=cut_y)
					{occupancy[i]++;}
		}

		for(int j=i+1; j<siz; j++)
		{
			if(std::fabs(xdat[i]-xdat[j]) <=cut_x 
			 && std::fabs(ydat[i]-ydat[j]) <=cut_y)
					{occupancy[i]++;}
		}
	} //End of Two Loops


	std::string datapath = parent_path + run_name + "_" + "colordensity.txt";
	int fillcoff = std::log10(siz);

	//Fill Buffers
	std::ostringstream buffer;
	for(int i = 0; i<siz; i++)
	{
		buffer << std::setw(fillcoff) << std::setfill('0') << std::setprecision(__Out_Prec__)
			   << xdat[i] << __DSep__ << ydat[i] << __DSep__
			   << occupancy[i] << "\n";	   
	}

	//Write to file
	bool file = SetFile(datapath, buffer.str());


	//Gnuplot Script -> Arguements
	//ARG1 - ParentPath+RunName --> generate Output Filename
	//ARG2 - Data File
	//ARG3 - Range 0_x
	//ARG4 - Range 1_x
	//ARG5 - Range 0_y
	//ARG6 - Range 1_y
	//ARG7 - Tics x & y

	//Generate Plot - System Call to gnuplot
	if(file)
	{
		//Plot Command 1(Variance Plots, Fractional Variance Plots, Histogram)
		std::ostringstream gnuplot;
		gnuplot << "./denscolor.gnu " //ARG0
		  	    << parent_path << run_name //ARG1
		        << " " << datapath << " "      //ARG2
		        << struct_x_0-cut_x*2 << " " << struct_x_1+cut_x*2 << " " //ARG3,4
		        << struct_y_0-cut_y*2 << " " << struct_y_1+cut_y*2 << " " //ARG5,6
		        << Bin; //ARG7
		std::string out = MakeSysCall_S(gnuplot.str(), "gnuplot - Density Color Plot");
		cout << out;
	}
	else
	{
		std::cout << "File creation & plotting failed! — Density Color Plot."
				  <<std::endl;
	}

} //End of DensityColorPlot()




void DensityColorPlot_Mean(const double xdat[], const double ydat[],
					  int siz, int Bin, double Delta, const std::string &parent_path,
					  const std::string &run_name)
{

	double struct_x_0 = 0;
	double struct_x_1 = 0;
	double struct_y_0 = 0;
	double struct_y_1 = 0;


	size_t arrsiz = sizeof(double)*siz;

	//Assign Struct -> Replace operations by memcopy
	//memcpy (struct_x, xdat, arrsiz);
	//memcpy (struct_y, ydat, arrsiz);
	
	//Sorting Done
	//std::sort(struct_x, struct_x+siz);
	//std::sort(struct_y, struct_y+siz);

	struct_x_0 = *std::min_element(xdat, xdat+siz);
	struct_x_1 = *std::max_element(xdat, xdat+siz);

	struct_y_0 = *std::min_element(ydat, ydat+siz);
	struct_y_1 = *std::max_element(ydat, ydat+siz);

	//cout << "struct_x_0: " << struct_x_0 << "  struct_x[end]: " << struct_x_1 << endl;
	//cout << "struct_y_0: " << struct_y_0 << "  struct_y[end]: " << struct_y_1 << endl;
	

	//underflow Safety
	if(std::isnan(struct_x_0))
		struct_x_0 = 0;
	if(std::isnan(struct_y_0))
		struct_y_1 = 0;


	double range_x = std::fabs(struct_x_1 - struct_x_0);
	double range_y = std::fabs(struct_y_1 - struct_y_0);


	double bin_size_x = range_x/Bin;
	double bin_size_y = range_y/Bin;


	double cut_x = bin_size_x/Delta;
	double cut_y = bin_size_y/Delta;
	//cout << cut_x << endl << cut_y << endl;


	int occupancy[siz] = {0};

	//Two Loops
	for(int i = 0; i<siz; i++)
	{

		for(int j=0; j<i; j++)
		{
			if(std::fabs(xdat[i]-xdat[j]) <=cut_x 
			 && std::fabs(ydat[i]-ydat[j]) <=cut_y)
					{occupancy[i]++;}
		}

		for(int j=i+1; j<siz; j++)
		{
			if(std::fabs(xdat[i]-xdat[j]) <=cut_x 
			 && std::fabs(ydat[i]-ydat[j]) <=cut_y)
					{occupancy[i]++;}
		}
	} //End of Two Loops


	std::string datapath = parent_path + run_name + "_" + "colordensity.txt";
	int fillcoff = std::log10(siz);

	//Fill Buffers
	std::ostringstream buffer;
	for(int i = 0; i<siz; i++)
	{
		buffer << std::setw(fillcoff) << std::setfill('0') << std::setprecision(__Out_Prec__)
			   << xdat[i] << __DSep__ << ydat[i] << __DSep__
			   << occupancy[i] << "\n";	   
	}

	//Write to file
	bool file = SetFile(datapath, buffer.str());


	//Gnuplot Script -> Arguements
	//ARG1 - ParentPath+RunName --> generate Output Filename
	//ARG2 - Data File
	//ARG3 - Range 0_x
	//ARG4 - Range 1_x
	//ARG5 - Range 0_y
	//ARG6 - Range 1_y
	//ARG7 - Tics x & y

	//Generate Plot - System Call to gnuplot
	if(file)
	{
		//Plot Command 1(Variance Plots, Fractional Variance Plots, Histogram)
		std::ostringstream gnuplot;
		gnuplot << "./denscolor.gnu " //ARG0
		  	    << parent_path << run_name //ARG1
		        << " " << datapath << " "      //ARG2
		        << struct_x_0-cut_x*2 << " " << struct_x_1+cut_x*2 << " " //ARG3,4
		        << struct_y_0-cut_y*2 << " " << struct_y_1+cut_y*2 << " " //ARG5,6
		        << Bin; //ARG7
		std::string out = MakeSysCall_S(gnuplot.str(), "gnuplot - Density Color Plot");
		cout << out;
	}
	else
	{
		std::cout << "File creation & plotting failed! — Density Color Plot."
				  <<std::endl;
	}

} //End of DensityColorPlot()