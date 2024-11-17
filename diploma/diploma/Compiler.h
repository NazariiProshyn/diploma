#pragma once
#include "Error.h"
#include <fstream>
class Compiler
{
public:
	Compiler();
	~Compiler();
	bool checkFile();
	std::string getError() { return error.getError(); }
private:
	const std::string pathFile{ "MarkUp.txt" };
	Error error;
	std::ifstream fin;
	int line{ 0 };
};

