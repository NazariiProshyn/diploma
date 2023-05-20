#pragma once
#include <fstream>

#include "Error.h"


class Parcer
{
public:
	Parcer();
	~Parcer();
	bool checkFile();
	bool parcing();

	std::string getError() { return error.getError(); }
private:
	const std::string pathFile{ "CppUi.txt" };
	

	std::ifstream fin;

	int line{ 0 };


	Error error;


	
};

