#include "Compiler.h"
#include <vector>
#include <iostream>
#include <string>





namespace NMCompMsg
{
	const std::string notOpenFile = "Can not open file : ";//
	std::string unkownSymbol1{ "Unknown symbol number: '" };
	std::string unkownSymbol2{ "'" };
}

namespace NMSymbols {
	std::vector<char> Symbols{
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
		'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
		'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
		'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', ':', '[', ']', ',', '.', '#', ' ', '_', '^', '+', '-', '/', '%',
		'*', '='
	};

};
namespace NMWidgets {
	std::vector<std::string> Widgets{
		"Button", "CheckBox","Label", "NumberBox", "RadioButton", "Text", "EditLine"
	};
}


Compiler::Compiler()
{
	fin.open(pathFile);
}

Compiler::~Compiler()
{
	fin.close();
}

bool Compiler::checkFile()
{
	if (fin.is_open())
	{
		return true;
	}
	else
	{
		error.setError(NMCompMsg::notOpenFile + pathFile, line);
		return false;
	}
}

bool Compiler::lexical()
{
	
	bool check = true;
	std::cout << "Start\n";
	resultString.clear();
	while (!fin.eof() && check)
	{

		std::getline(fin, parcingString);
		remake();
		++line;
		
		for (size_t i = 0; i < parcingString.size(); ++i) {
			check = false;
			for (size_t j = 0; j < NMSymbols::Symbols.size(); ++j) {
				if (parcingString[i] == NMSymbols::Symbols[j])
				{
					check = true;
					break;
				}
			}
			if (!check) {
				error.setError(NMCompMsg::unkownSymbol1 + std::to_string(i + 1) + NMCompMsg::unkownSymbol2, line);
				break;
			}
		}
	}
	if (check) {
		std::ofstream fout;
		fout.open(pathResult);
		fout << resultString;
	}
	return check;
}

void Compiler::remake()
{
	bool firstCycle = true;
	std::string temp{ "" };
	if (parcingString.size() > 0)
	{
		for (size_t i = 0; i < parcingString.size(); ++i) {
			if (parcingString[i] == ' ') {
				if (!firstCycle) {
					break;
				}
			}

			else 
			{
				firstCycle = false;
				temp += parcingString[i];
			}
			
		}
		if (parcingString[0] == '#')
		{
			resultString += parcingString + "\n";
		}
		else {
			std::cout << temp << '\n';
			bool isWidget = false;
			for (size_t i = 0; i < NMWidgets::Widgets.size(); ++i) {
				if (temp == NMWidgets::Widgets[i]) {
					resultString += "|" + parcingString + "\n";
					isWidget = true;
				}
			}
			if (!isWidget) {
				resultString += "/" + parcingString + "\n";
			}
		}

	}
	else
	{
		resultString += "\n";
	}

}

