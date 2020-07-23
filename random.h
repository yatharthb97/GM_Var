/* mmm  m    m        m    m   mm   mmmmm	|	Developed by: Yatharth Bhasin
 m"   " ##  ##        "m  m"   ##   #   "#  |	Discipline of Physics
 #   mm # ## #         #  #   #  #  #mmmm"  |	IIT Indore
 #    # # "" #         "mm"   #mm#  #   "m  |	(yatharth1997@gmail.com)
  "mmm" #    #__________##   #    # #    "  |	(git: yatharthb97)
  											|	Licence: *******************
//---------------------------------------------------------------------------------

//Gerrymandering Variance Analysis - GM_VAR v1.0
//Heaser file for random number generation
//-----------------------------------------------------------------------------------
//		+++ Notes - Complete, +++ Status - Tested 
//-----------------------------------------------------------------------------------
*/

/*Notes

*/

//Preprocessor Commands
#pragma once
#include <random>

/** Class that defines the random generation module.
 *  
 */
class Rndm
{
	
	std::ranlux48 rlx1; /*!< Ranlux48 generator 1 */
	std::ranlux48 rlx2; /*!< Ranlux48 generator 2 */
	std::uniform_real_distribution<double> getsII; /*!< Uniform distribution - double */
	std::uniform_int_distribution<int> getsI; /*!< Uniform distribution - integer */

public:

	//1
	//Constructor
	//!Class Constructor. Class constructor that seeds the random number generators using system entropy and sets range of distributions.
	Rndm(double swap_parameter)
	{
		//Seed generators from system entropy
		std::random_device r1; 
		std::random_device r2;
		rlx1.seed(r1());
		rlx2.seed(r2());
		getsII.param(std::uniform_real_distribution<double>::param_type(0.5, swap_parameter));
		
	}//End of constructor
//**********************************************************************************
	
	//2
	//!Set range of distribution for double distribution.
	/*
	\param lower lower bound of distribution
	\param higher higher bound of distribution
	*/
	void get1_set(double lower, double upper)
	{
			getsI.param(std::uniform_int_distribution<int>::param_type(lower, upper));
	}//End of get1_set()
//**********************************************************************************


	//3
	//!Set range of distribution for integer distribution.
	/*
	\param lower lower bound of distribution
	\param higher higher bound of distribution
	*/
	void get2_set(int lower, int upper)
	{
			getsII.param(std::uniform_real_distribution<double>::param_type(lower, upper));
	}//End of get1_set()
//**********************************************************************************

	//4
	//!Generates and returns integer random number
	/*
	\param integer random number
	*/
	int get1()
	{
		return getsI(rlx1);
	}//End of get1()
//**********************************************************************************

	//5
	//!Generates and returns double random number
	/*
	\param double random number
	*/
	double get2()
	{
		return getsII(rlx2);
	} //End of get2()

//**********************************************************************************

}; //End of class Rndm


////////////////////////////////END OF TRANSLATION UNIT/////////////////////////