
  /*$$$$$  /$$      /$$ /$$    /$$                    |Developed by: Yatharth Bhasin
 /$$__  $$| $$$    /$$$| $$   | $$                    |Discipline of Physics
| $$  \__/| $$$$  /$$$$| $$   | $$ /$$$$$$   /$$$$$$  |IIT Indore
| $$ /$$$$| $$ $$/$$ $$|  $$ / $$/|____  $$ /$$__  $$ |(yatharth1997@gmail.com)
| $$|_  $$| $$  $$$| $$ \  $$ $$/  /$$$$$$$| $$  \__/ |(git: yatharthb97)
| $$  \ $$| $$\  $ | $$  \  $$$/  /$$__  $$| $$       |Licence: *******************
|  $$$$$$/| $$ \/  | $$   \  $/  |  $$$$$$$| $$		  |
 \______/ |__/     |__/====\_/    \_______/|_*/  	//|
//---------------------------------------------------------------------------------

//Gerrymandering Variance Analysis - GM_VAR v1.0
//---------------------------------------------------------------------------------

//		+++ Notes - InComplete, +++ Status - Not Tested
//---------------------------------------------------------------------------------

/*Notes

*/

//Preprocessor Commands
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <algorithm>

//Macros included here
#include "macros.h"
//Macros included here

#include "timer.h"
#include "densityplot.h"
#include "var_minmax.h"
#include "constituency.h"
#include "random.h"
#include "main.h"

using namespace std;
using namespace std::chrono;
//#define __DENSITY_PLOT__

//global declarations
int Constituency::counter = 0; //Counter initialization

////////////////////////////////Global Paramaters/////////////////////
string parent_path_gl = "/mnt/m/Gerry_Study/Results/";

int iterations = 1;
int total_measurements = 10000;
float frac_minority = 0.5;
int total_pop = 1000;

int tot_min = total_pop*frac_minority;
int tot_maj = total_pop - tot_min;

bool printinfo = false;

int con_lowest = 23; //Constituency with the lowest strength - ***Automate
int con_matrix_size = 25;

int con_matrix[25] = {0};
ArrayCopy(con_matrix, All_Equal, 25);
bool ShuffleConMatrix = false;

//---> Sampling Mode
bool twice_swap = false;
double swap_parameter = 1.0; //0.0-0.5
//---> Sampling Mode

////////////////////////////////Global Paramaters/////////////////////


int main(int argc, char const *argv[])
{
	std::string run_name_gl;
	if (argc == 0)
	{
		std::cerr << "Error: No output filename given!" << std::endl;
		return 0;
	}

	else
	{
		run_name_gl = argv[1];
	}

//Controls the number of iterative consecutive runs
//*************Scaling Loop*****************************

//Run Scope Bracket
for(int i = 0; i < iterations; i++)
{ 

std::string run_name = run_name_gl;
std::string parent_path = parent_path_gl;
if(iterations > 1)
{
	run_name += "_";
	run_name += std::to_string(i);
	//total_measurements*=10;
}

//Create Filesystem and Change parentpath
string newpath = parent_path + run_name + "/";
if(MakeDir(newpath))
	{parent_path = newpath;}

//*************Scaling Loop*****************************



////////////////////////////////Print Information/////////////////////

	std::cout 
	<< "-------------------------------------------------------" << "\n"
	<< "-------------------------------------------------------" << "\n"
	<< "Gerrymandering Study" << "\n" << "Run Name: " << run_name << "\n"
	<< "-------------------------------------------------------" << "\n"
	<< "Minority Fraction: " << frac_minority << "\n"
	<< "Total Population: " << total_pop << "\n"
	<< "Minority Population: " << tot_min << "\n"
	<< "Majority population: " << tot_maj << "\n"
	<< "Total Measurements: " << total_measurements << "\n"
	<< "Parent Path: " << parent_path << "\n"
	#ifdef __DENSITY_PLOT__
		<< "Density Color Plot is set!" << "\n"
	#endif
	<< "-------------------------------------------------------" << std::endl;

////////////////////////////////Print Information/////////////////////


////////////////////////////////Run Scope Resources/////////////////////

	
	/////////Declaration of Random Generator and Distributions
	Rndm rand(swap_parameter); //Initialize Random number generators
	rand.get1_set(0, con_matrix_size-1); //Set range for get1 - Constituency list
	//rand.get2_set(0.1,swap_parameter); //Set range for get2 - swap_parameter

	/////////Declaration of Random Generator and Distributions

	if(ShuffleConMatrix)
		std::shuffle(con_matrix, con_matrix+25, rand);

	std::cout << PrintMatrix("Constituency Distribution") << std::endl;


	std::ostringstream buffer1;
	std::ostringstream buffer2;
	std::ostringstream buffer3;
	
	//std::vector<pair<int, double>> seat_var_list;
	VarTable var(con_matrix_size+1); //VarTable for minority variance 
	VarTable fracvar(con_matrix_size+1); //VarTable for fraction of minority variance
	long int swap_matrix[con_matrix_size] = {0}; //For Storing Swaps

	int won_matrix[con_matrix_size] = {0};
	int lost_matrix[con_matrix_size] = {0};

	int min_pop_matrix[con_matrix_size] = {0};
	int maj_pop_matrix[con_matrix_size] = {0};

	int zero_min_con = 0; //Number of Constituencies with zero minority pop
	int uniform_minority = tot_min / con_matrix_size;
	int minority_mean = uniform_minority; //Duplicate
	if(con_lowest < uniform_minority)
	{
		cerr << "Error - Uniform Majority is higher than lowest Constituency Size - Constituency Overflow Expected!" << endl;
	}
	#ifdef __DENSITY_PLOT__
		cout << "**********" << endl;
		double* _varince = new double[total_measurements]();
		double* frac_varince = new double[total_measurements]();
	#endif

////////////////////////////////Run Scope Resources/////////////////////


	
	auto start = high_resolution_clock::now(); /////////Clock - Start////////////


//////////////////////////////////Measurement Loop//////////////////////////
	for(unsigned int mm = 0; mm < total_measurements; mm++)
	{


		
//___________________________________________MEASUREMENT_____________
		
//Loop Scope Resources////////////////////////////////////////////////
		Constituency::counter = 0; //Counter initialization
		std::vector<Constituency> con_list;
		con_list.reserve(con_matrix_size);

		int min_win = 0; //Number of seats won by minority
		double mean = 0; //Mean of fraction pop - calculated during election
		double fracvariance = 0; //Fractional Variance
		double variance = 0; //Variance
		int total_swaps = 0; //Number of attempted swaps
//Loop Scope Resources////////////////////////////////////////////////

		
		//std::cout << "1" << std::endl;


//Populating Constituencies - First Settlement/////////////////////////
		for (unsigned int i = 0; i < con_matrix_size - 1; i++)
		{
			//Equal assignment of all minorities
			con_list.emplace_back(con_matrix[i], uniform_minority); 

		}

		//Fill leftover - Prevent error in case tot_minority is not divisible by con_matrix_size
		int leftover = tot_min - ((con_matrix_size-1)*uniform_minority);
		con_list.emplace_back(con_matrix[con_matrix_size -1], leftover);
//Populating Constituencies - First Settlement/////////////////////////

		//std::cout << "2" << std::endl;

		// ??? Check the algoritm once
////////Migration////////////////////////////////////////////////////
		//Swap only possible when a double swap is possible. - Double Swap Method
		
		//Scope - Migration
		int x = 0;
		double y =0, z=0;
		int mix1=0, mix2=0, temp =0;
		//Scope - Migration
		
		for (unsigned int i = 0; i < con_matrix_size; i++)
		{ 
			
			if(twice_swap == true)
			{
				x = rand.get1();

				y = rand.get2();
				z = rand.get2();
	 
				//std::cout <<  setprecision(16) << x << "\t" << y << "\t" << z << std::endl;

				if(i != x)
				{
					
					mix1 = con_list.at(i).min_pop*y;
					mix2 = con_list.at(x).min_pop*z;
					temp = mix2  - mix1;

					if (con_list.at(i).min_pop + temp <= con_list.at(i).con_max && con_list.at(x).min_pop - temp <=con_list.at(x).con_max)
					{
						con_list.at(i).min_pop += temp;
						con_list.at(x).min_pop -= temp;
						con_list.at(i).swaps++;
						con_list.at(x).swaps++;
					}
				}
				
			} //Twice Swap 

			else  //Single Swap
			{
					x = rand.get1();
					y = rand.get2();
 
					//std::cout <<  setprecision(16) << x << "\t" << y << "\t" << z << std::endl;

					if(i != x)
					{
				
						mix1 = con_list.at(i).min_pop*y;

						if (con_list.at(x).min_pop + mix1 <= con_list.at(x).con_max)
						{
							con_list.at(x).min_pop += mix1;
							con_list.at(i).min_pop -= mix1;
							con_list.at(i).swaps++;
							con_list.at(x).swaps++;
						}
					}
				} //Single Swap
			
		} //End of Migration Loop
////////Migration - End////////////////////////////////////////////////////


		//std::cout << "3" << std::endl;


////////Election////////////////////////////////////////////////////
		double stack = 0; //For storing the mean of frac population
		int mpop = 0;
		for (unsigned int i = 0; i < con_matrix_size; i++)
		{
			mpop = con_list.at(i).min_pop;
			
			//std::cout << mpop << "  ";

			if(mpop == 0){zero_min_con++; lost_matrix[i]++;}

			else
			{
				int majo = con_list.at(i).majority();
				min_pop_matrix[i] += mpop;
				maj_pop_matrix[i] += majo;
				if(mpop > majo)
				{

					won_matrix[i]++;
					//con_list.at(i).min_win = true; 
					//Update the Constituency specific flag

					min_win++; //Update the number of seats won by the minority
					//std::cout << mm << "  " << i << " Minority win!" <<std::endl;
				}

				else
					lost_matrix[i]++;
			}
			
			//Test/////////////
			//Check for negative population
			//if(mpop < 0) {std::cerr << "Error state: Negative minority population!" << std::endl;}
			//Test/////////////


			//total_swaps += con_list.at(i).swaps; //***
			stack += (double(mpop)/double(con_matrix[i])); //Add Fraction of min pop per constituency to the stack

		}
		//std::cout << std::endl;

		mean = stack/con_matrix_size; //Normalising the value of mean
////////Election - End////////////////////////////////////////////////////
		 

////////Analysis////////////////////////////////////////////////////
		double term1, term2 = 0; //term1 - fractional variance & term2 - absolute varaiance
		double var_stack=0; //term2 squared
		double fracvar_stack = 0; //term1 squared

		for (unsigned int i = 0; i < con_matrix_size; i++)
		{
			//Generate terms for variance of fraction of minority population
			term1 = (double(con_list.at(i).min_pop)/double(con_matrix[i])) - mean;
			term2 = double(con_list.at(i).min_pop) - double(minority_mean);
			
			fracvar_stack += (term1*term1);
			var_stack += (term2*term2);

			swap_matrix[i] += con_list.at(i).swaps;
		}
		//Calculate Variance
		variance = var_stack / (con_matrix_size-1); //Normalisation of variance
		fracvariance = fracvar_stack / (con_matrix_size-1); //Normalisation of absolute variance
		
		
		var.Push(min_win, variance); //Update Table
		fracvar.Push(min_win, fracvariance); //Update Table

		//Update buffer for variance v fracvariance plot

		#ifdef __VARVFRACVAR__
		buffer2 << setprecision(10) << variance << __DSep__ << fracvariance <<"\n";
		#endif

		#ifdef __DENSITY_PLOT__
			_varince[mm] = variance;
			frac_varince[mm] = fracvariance;
		#endif

		if(printinfo)
		{
			
			std::cout << "Measurement: " << mm +1 << "\n";
			std::cout << "Fractional Mean: " << mean <<"\n";
			std::cout << "Variance:" << variance << "\n";
			std::cout << "Fractional Variance:" << fracvariance << "\n";
			std::cout << PrintDist(con_list) << std::endl;
		}

//__________________End of Measurement__________________________________
		

	} //End of Main Loop//////////////////////////////////////////////////////////////
	

	//Simulation - End Part
	//________________________________________________________________________________
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds> (stop - start);
	std::cout << "Time taken(ms): " << duration.count() << endl;
	double tmsec = duration.count()/1000;
	std::cout << "Time taken(s): " << tmsec << endl;

	std::cout << "Zero Constituency Count(All Measurements): " << zero_min_con << endl;


/////////Generate Files/////////////////////////////////

	//Fractional Variance
	std::string path1 = parent_path + run_name + "_fracvar.txt";
	fracvar.Print(path1);

	//Variance
	std::string path2 = parent_path + run_name + "_var.txt";
	var.Print(path2);

	//Var v FracVar Plot - buffer2
	#ifdef __VARVFRACVAR__
	std::string path3 = parent_path + run_name + "_varvfracvar.txt";
	ofstream file1(path3, ios::out);
	file1 << buffer2.str(); 
	file1.close();
	#endif

	//Swap Matrix & Seat Specific Distributions
	for(unsigned int i=0; i <con_matrix_size; i++)
	{
		buffer1 << std::setw(2) << std::setfill('0')
				<< i << __DSep__ << swap_matrix[i] << __DSep__ << con_matrix[i] << "\n";
		
		double won = double(won_matrix[i])/total_measurements*100;
		double lost = double(lost_matrix[i])/total_measurements*100;
		double min = double(min_pop_matrix[i])/double(con_matrix[i])/total_measurements*100;
		double maj = double(maj_pop_matrix[i])/double(con_matrix[i])/total_measurements*100;

		buffer3 << setprecision(4) << std::setw(2) << std::setfill('0')
		<< i << __DSep__ << con_matrix[i] << __DSep__ << won << __DSep__ << lost << __DSep__ << min << __DSep__ << maj <<"\n";
	}
	
	std::string path4 = parent_path + run_name + "_swaps.txt";
	ofstream file2(path4, ios::out);
	file2 << buffer1.str(); 
	file2.close();

	std::string path5 = parent_path + run_name + "_seatspec.txt";
	ofstream file3(path5, ios::out);
	file3 << buffer3.str(); 
	file3.close();

	#ifdef __DENSITY_PLOT__
		//Color density plot
		int Bins = 10;
		double Delta = 100; //Divide 1 Bin into Delta parts for sorting.
		{
			Timer colordensity("Color Density Plot");
			DensityColorPlot(_varince, frac_varince,
						  total_measurements, Bins, Delta, parent_path, run_name);
		}

		//Freeing Memory
		delete[] _varince;
		delete[] frac_varince;
	#endif
/////////Generate Files/////////////////////////////////




/////////Call gnuplot scripts////////////////////////////////

	//Plot Command 1(Variance Plots, Fractional Variance Plots, Histogram)
	std::ostringstream plot1;
	plot1 << "./varplot.gnu " 
		  << parent_path << run_name
		  << " " << path1<< " " << path2;
	MakeSysCall(plot1.str(), "gnuplot - Var Plots & Histogram");


	//Plot Command 2(Var v FracVar Scatter Plot)
	#ifdef __VARVFRACVAR__
	std::ostringstream plot2;
	plot2 << "./varvfracvar.gnu " 
		  << parent_path << run_name
		  << " " << path3;
	MakeSysCall(plot2.str(), "gnuplot - Var v FracVar Scatter Plot");
	#endif

	//Plot Command 3(Swap Plot)
	std::ostringstream plot3;
	plot3 << "./swap_plot.gnu " 
		  << parent_path << run_name
		  << " " << path4;
	MakeSysCall(plot3.str(), "gnuplot - Swap Plot");

	//Plot Command 4(Per Seat Distributions)
	std::ostringstream plot4;
	plot4 << "./perseat.gnu " 
		  << parent_path << run_name
		  << " " << path5;
	MakeSysCall(plot4.str(), "gnuplot - Per Seat Distributions");

/////////Call gnuplot scripts - End ///////////////////////

	std::cout << "End of Run!" << "\n" << "Output Saved to: " << parent_path << "\n"
	     	  << "-------------------------------------------------------" << "\n" 
			  << "-------------------------------------------------------" << "\n\n"<< std::endl;

} //Run Scope Bracket
	

	return 0;
} //End of main


