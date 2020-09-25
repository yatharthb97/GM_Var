/* mmm  m    m        m    m   mm   mmmmm	|	Developed by: Yatharth Bhasin
 m"   " ##  ##        "m  m"   ##   #   "#  |	Discipline of Physics
 #   mm # ## #         #  #   #  #  #mmmm"  |	IIT Indore
 #    # # "" #         "mm"   #mm#  #   "m  |	(yatharth1997@gmail.com)
  "mmm" #    #__________##   #    # #    "  |	(git: yatharthb97)
  											|	Licence: *******************
//---------------------------------------------------------------------------------

//Gerrymandering Variance Analysis  - GM_VAR v1.0
//Header file for Main -> Contains Utility functions
//-----------------------------------------------------------------------------------
//		+++ Notes - Complete, +++ Status - Tested
//-----------------------------------------------------------------------------------
*/
/*Notes

 1.//Add ARGS - SetParam function utility

*/

//Preprocessor Commands
#pragma once
#include <iostream>
#include <string>
#include <sys/stat.h>


//----------------------------------
#include "constituency_distro.h"


//----------------------------------


//1
//External Function - Make Directory
//!Function that creates directory
 /*
 \param path string of parent path whwere directory needs to be created.
 \return bool ststus of creator - error handled.
 */
bool MakeDir(std::string path)
{
	const int dir_err1 = mkdir(path.c_str(), 0777);
		if (-1 == dir_err1)
		{
	    	std::cerr << "!!! Directory Not Created: " << path << "\t!!!" << std::endl;
	    	return false;
		}

		else return true;
} //End of MakeDir()
//**********************************************************************************

void MakeSysCall(std::string command, std::string stringkey)
{
	std::cout <<"Executed System Call: " << stringkey <<". Returned PID:" << system(command.c_str()) <<std::endl;
}
