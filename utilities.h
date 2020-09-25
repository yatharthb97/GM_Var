#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>


//Make System Call
/*void MakeSysCall(std::string command, std::string stringkey)
{
	std::cout <<"Executed System Call: " << stringkey 
			  <<". Returned PID:" << system(command.c_str()) <<std::endl;
}//Make System Call*/


//Make System Call
std::string MakeSysCall_S(std::string command, std::string stringkey)
{
	std::ostringstream buffer;
	buffer  <<"Executed System Call: " << stringkey 
			<<". Returned PID:" << system(command.c_str()) <<std::endl;
	return buffer.str();

}//Make System Call


bool SetFile(const std::string &path, const std::string &content)
{
	std::fstream file(path, ios::out);
	if(file.is_open())
	{
		file << content;
		file.close();
		return true;
	}

	else
		return false;
}



void ArrayCopy(int[] to, int[] from, size_t size)
{
	memcopy(to, from, size);
}