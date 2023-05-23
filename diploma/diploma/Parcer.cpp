#include "Parcer.h"

#include <iostream>
#include <string>

namespace NMMessages
{
	const std::string notOpenFile = "can not open file: ";
	const std::string unknCommand = "Unknown command";
	const std::string unknWidget = "Unknown widget or not in scope";
	const std::string createWidgetError = "This widget can't creating in this place";
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
	const std::string text   = "Text";
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
				if (getWidget())
				{
					if (!createWidget())
					{
						error.setError(NMMessages::createWidgetError, line);
						return false;
					}
				}
				else
				{
					error.setError(NMMessages::unknWidget, line);
					return false;
				}
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
				return false;
			}
		}
	}
	std::cout << '\n' << "Parcing done!" << '\n';
	return true;
}

bool Parcer::createWidget()
{
	if (scope.top() == NMWidgets::form)
	{
		if(activeString == NMWidgets::text)
		{
			return false;
		}
		if (activeString == NMWidgets::button)
		{
			scope.push(NMWidgets::button);
			form.createButton();
			std::cout << '\n' << "Create button" << '\n';
		}
		if (activeString == NMWidgets::label)
		{
			scope.push(NMWidgets::label);
			form.createLabel();
			std::cout << '\n' << "Create label" << '\n';
		}
	}
	else
	{
		if (activeString != NMWidgets::text)
		{
			return false;
		}
		scope.push(NMWidgets::text);
	}

	return true;
}

bool Parcer::changeWidget()
{
	return true;
}

bool Parcer::paramWidget()
{
	return true;
}

bool Parcer::getWidget()
{
	bool inScope = false;
	for (size_t i = 1; i < parcingString.size(); ++i)
	{
		if (parcingString[i] != '[' && parcingString[i] != ' '
			&& parcingString[i] != '|' && parcingString[i] != '/'
			&& parcingString[i] != '>' && parcingString[i] != '#')
		{
			activeString += parcingString[i];
		}

		if (parcingString[i] == '[')
		{
			inScope = true;
			break;
			std::cout << '\n' << activeString << '\n';
		}
	}
	if (inScope != true || (activeString != NMWidgets::button && 
		activeString != NMWidgets::label && activeString != NMWidgets::text))
	{
		return false;
	}

	return true;
}


