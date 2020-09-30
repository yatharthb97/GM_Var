
  /*$$$$$  /$$      /$$ /$$    /$$                    |Developed by: Yatharth Bhasin
 /$$__  $$| $$$    /$$$| $$   | $$                    |Discipline of Physics
| $$  \__/| $$$$  /$$$$| $$   | $$ /$$$$$$   /$$$$$$  |IIT Indore
| $$ /$$$$| $$ $$/$$ $$|  $$ / $$/|____  $$ /$$__  $$ |(yatharth1997@gmail.com)
| $$|_  $$| $$  $$$| $$ \  $$ $$/  /$$$$$$$| $$  \__/ |(git: yatharthb97)
| $$  \ $$| $$\  $ | $$  \  $$$/  /$$__  $$| $$       |Licence: **************
|  $$$$$$/| $$ \/  | $$   \  $/  |  $$$$$$$| $$		  |
 \______/ |__/     |__/====\_/    \_______/|_*/  	//|
//---------------------------------------------------------------------------------

//Gerrymandering Variance Analysis - GM_VAR v1.0
//Heaser file for random number generation
//-----------------------------------------------------------------------------------
//		+++ Notes - Complete, +++ Status - Tested 
//-----------------------------------------------------------------------------------

/*Notes

*/

//Preprocessor Commands
#pragma once
#include <random>
#include <iostream>

/** Class that defines the random generation module.
 *  
 */
class Rndm
{

public:

	std::ranlux48 engine; /*!< Ranlux48 generator 1 */
	//std::ranlux48 rlx2; /*!< Ranlux48 generator 2 */
	std::uniform_real_distribution<double> getsII; /*!< Uniform distribution - double */
	std::uniform_int_distribution<int> getsI; /*!< Uniform distribution - integer */



	//1
	//Constructor
	//!Class Constructor. Class constructor that seeds the random number generators using system entropy and sets range of distributions.
	Rndm(double swap_param_l, double swap_param_u)
	{
		//Seed generators from system entropy
		std::random_device r1;
		engine.seed(r1());
		//std::cout << "Seed:" << engine.seed() << "\n\n\n";

		getsII.param(std::uniform_real_distribution<double>::param_type(swap_param_l, swap_param_u));
		std::cout << "Real Distribution Set: [" << getsII.a() << ',' << getsII.b() << "]\n";
		
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
			std::cout << "Int Distribution Set: [" << getsI.a() << ',' << getsI.b() << "]\n";
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
			std::cout << "Real Distribution Set: [" << getsII.a() << ',' << getsII.b() << "]\n";
	}//End of get1_set()
//**********************************************************************************

	//4
	//!Generates and returns integer random number
	/*
	\param integer random number
	*/
	int get1()
	{
		return getsI(engine);
	}//End of get1()
//**********************************************************************************

	//5
	//!Generates and returns double random number
	/*
	\param double random number
	*/
	double get2()
	{
		return getsII(engine);
	} //End of get2()

//**********************************************************************************

}; //End of class Rndm


////////////////////////////////END OF TRANSLATION UNIT/////////////////////////