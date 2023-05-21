#pragma once
#include <fstream>
#include <stack>

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
	std::string activeString{""};
	std::string parcingString{""};
	std::stack<std::string> scope;
	


	Error error;

	void createWidget();
	void changeWidget();
	void paramWidget();
};

