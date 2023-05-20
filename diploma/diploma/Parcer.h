#pragma once
#include <fstream>

#include "Error.h"


class Parcer
{
public:
	Parcer();
	~Parcer();
	bool checkFile();

	std::string getError() { return error.getError(); }
private:
	const std::string pathFile{ "CppUi.txt" };
	const std::string notOpenFile = "can not open file: ";

	std::ifstream fin;

	int line{ 0 };


	Error error;


	
};

