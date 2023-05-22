#include "Parcer.h"

#include <iostream>
#include <string>

namespace NMMessages
{
	const std::string notOpenFile = "can not open file: ";
	const std::string unknCommand = "Unknown command";
}

namespace NMCaommands
{
	const char create  = '|';
	const char param   = '/';
	const char channge = '>';
	const char comment = '#';
}

namespace NMWidgets
{
	const std::string form   = "Form";
	const std::string button = "Button";
	const std::string label  = "Label";
}



Parcer::Parcer()
{
	fin.open(pathFile);
}

Parcer::~Parcer()
{
	fin.close();
}

bool Parcer::checkFile()
{
	if (fin.is_open())
	{
		return true;
	}
	else
	{
		error.setError(NMMessages::notOpenFile + pathFile, line);
		return false;
	}
	
}

bool Parcer::parcing()
{
	scope.push(NMWidgets::form);

	while (!fin.eof())
	{
		++line;
		std::getline(fin, parcingString);

		if (parcingString.size() > 0)
		{
			if (parcingString[0] == NMCaommands::create)
			{
				createWidget();
			}
			else if (parcingString[0] == NMCaommands::param)
			{
				paramWidget();
			}
			else if (parcingString[0] == NMCaommands::channge)
			{
				changeWidget();
			}
			else if (parcingString[0] == NMCaommands::comment)
			{

			}
			else
			{
				error.setError(NMMessages::unknCommand, line);
			}
		}
	}

	
}

void Parcer::createWidget()
{

}

void Parcer::changeWidget()
{
}

void Parcer::paramWidget()
{
}


