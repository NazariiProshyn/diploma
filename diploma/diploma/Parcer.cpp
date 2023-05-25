#include "Parcer.h"

#include <iostream>
#include <string>

namespace NMMessages
{
	const std::string notOpenFile = "can not open file: ";
	const std::string unknCommand = "Unknown command";
	const std::string unknWidget = "Unknown widget or not in scope";
	const std::string createWidgetError = "This widget can't creating in this scope";
	const std::string outOfScope = "Out of any scopes";
	const std::string noParam = "Must be ':' in this line";
	const std::string noValue = "Must be value in this line";
	const std::string badParam = "This widget havent this param";
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
		if (scope.size() == 0)
		{
			error.setError(NMMessages::outOfScope, line);
			return false;
		}
		++line;
		std::getline(fin, parcingString);

		if (parcingString.size() > 0)
		{//////////////////////////////////////////////
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
			}//////////////////////////////////////////////
			else if (parcingString[0] == NMCaommands::param)
			{
				if (getParam())
				{
					if (getValue())
					{
						if (checkParam())
						{
							if (!paramWidget())
							{
								error.setError(NMMessages::createWidgetError, line);
								return false;
							}
						}
						else
						{
							error.setError(NMMessages::badParam, line);
							return false;
						}
					}
					else
					{
						error.setError(NMMessages::noValue, line);
						return false;
					}
				}
				else
				{
					error.setError(NMMessages::noParam, line);
					return false;
				}
			}/////////////////////////////////////////////////
			else if (parcingString[0] == NMCaommands::channge)
			{
				changeWidget();
			}////////////////////////////////////////////////
			else if (parcingString[0] == NMCaommands::comment)
			{

			}
			else
			{////////////////////////////////////////////////
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
		std::cout << '\n' << "Create Text" << '\n';
	}

	return true;
}

bool Parcer::changeWidget()
{
	return true;
}

bool Parcer::paramWidget()
{
	//valueString
	//parcingString
	//activeString
	return true;
}

bool Parcer::getWidget()
{
	activeString.clear();
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

bool Parcer::getParam()
{
	activeString.clear();
	bool value = false;
	for (size_t i = 1; i < parcingString.size(); ++i)
	{
		if (parcingString[i] != '[' && parcingString[i] != ' '
			&& parcingString[i] != '|' && parcingString[i] != '/'
			&& parcingString[i] != '>' && parcingString[i] != '#')
		{
			activeString += parcingString[i];
		}

		if (parcingString[i] == ':')
		{
			value = true;
			break;
			std::cout << '\n' << activeString << '\n';
		}
	}
	if (value != true)
	{
		return false;
	}

	return true;
}

bool Parcer::getValue()
{
	valueString.clear();
	bool value = false;
	bool firstspace = false;
	for (size_t i = 1; i < parcingString.size(); ++i)
	{
		if (parcingString[i] == ':')
		{
			value = true;
		}
		if (value)
		{
			if (parcingString[i] == ' ' && firstspace)
			{
				valueString += parcingString[i];
			}
			if (parcingString[i] != ' ')
			{
				firstspace = true;
				valueString += parcingString[i];
			}
			
		}
	}
	if (valueString.size() == 0)
	{
		return false;
	}

	return true;
}

bool Parcer::checkParam()
{
	if (scope.top() == NMWidgets::text)
	{
		if (scope.top() != "text"
			&& scope.top() != "positionVert" && scope.top() != "positionGorz")
		{
			return false;
		}
	}
	else if(scope.top() == NMWidgets::button)
	{
		if (scope.top() != "sizeVert" && scope.top() != "sizeGorz"
			&& scope.top() != "positionVert" && scope.top() != "positionGorz")
		{
			return false;
		}
	}
	else if(scope.top() == NMWidgets::label)
	{
		if (scope.top() != "positionVert" && scope.top() != "positionGorz")
		{
			return false;
		}
	}
	else if(scope.top() == NMWidgets::form)
	{
		if (scope.top() != "sizeVert" && scope.top() != "sizeGorz")
		{
			return false;
		}
	}
	return true;
}


