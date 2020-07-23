/* mmm  m    m        m    m   mm   mmmmm	|	Developed by: Yatharth Bhasin
 m"   " ##  ##        "m  m"   ##   #   "#  |	Discipline of Physics
 #   mm # ## #         #  #   #  #  #mmmm"  |	IIT Indore
 #    # # "" #         "mm"   #mm#  #   "m  |	(yatharth1997@gmail.com)
  "mmm" #    #__________##   #    # #    "  |	(git: yatharthb97)
  											|	Licence: *******************
//---------------------------------------------------------------------------------

//Gerrymandering Variance Analysis - GM_VAR v1.0
  Header File defining the Constituency Class & Print Distribution function
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
#include <iostream>
#include <iomanip>

/** Class that defines a constituency.
 *  
 */
class Constituency
{

public:

	static int counter; /*!< Static memeber that keeps count of the constituencies. */
	int ID; /*!< ID token for the constitunency. */
	int con_max; /*!< Maximum population size */
	int min_pop; /*!< Minority Population */
	int swaps; /*!< Number of population exchanges successful. */
	bool min_win; /*!< Is the minority winning in this seat */
	//Implicit conversion to int guarenteed

	//1
	//Constructor
	//!Class Constructor.
 	/*
 	\param con_max constituency maximum size
 	\param min_pop minority population assigned
 	*/
	Constituency(int con_max, int min_pop): ID(++counter), con_max(con_max), min_pop(min_pop), swaps(0), min_win(false)
	{} //End of Constructor
//**********************************************************************************

	//2
	//Return the majority population
	//!Function that returns the majority population.
 	/*
 	\return majority population in constituency.
 	*/
	int majority()
	{
		return (con_max - min_pop);
	}

//**********************************************************************************

}; //End of class constituency
//**********************************************************************************


//External Function - Print Distribution
//!Function that returns a string that countans the measured distribution
 /*
 \param Constituency List - std::vector<Constituency>
 \return String that can be written to a file.
 */
std::string PrintDist(std::vector<Constituency> &conlist)
{
	std::ostringstream buffer;
	buffer << "Distribution: " << "\n" << "con_max: ";
	for(unsigned int i = 0; i < conlist.size(); i++)
	{
		buffer << std::setw(3) << std::setfill('0') << std::setprecision(2)
			   << conlist.at(i).con_max << "  ";
	}

	//Minority
	buffer << "\n" << "min_pop: ";

	for(unsigned int i = 0; i < conlist.size(); i++)
	{
		buffer << std::setw(3) << std::setfill('0') << std::setprecision(2)
		       << conlist.at(i).min_pop << "  ";
	}

	//Minority Fraction
	buffer << "\n" << "fra_min: ";
	for(unsigned int i = 0; i < conlist.size(); i++)
	{
		buffer << std::setw(3) << std::setfill('0') << std::setprecision(2)
		       << double(conlist.at(i).min_pop)/double(conlist.at(i).con_max) << "  ";
	}

	//Minority
	buffer << "\n" << "max_pop: ";
	for(unsigned int i = 0; i < conlist.size(); i++)
	{
		buffer << std::setw(3) << std::setfill('0') << std::setprecision(2)
		       << conlist.at(i).majority() << "  ";
	}
	buffer << std::endl;

	return buffer.str();

} // End of PrintDist()
//**********************************************************************************


////////////////////////////////END OF TRANSLATION UNIT/////////////////////////