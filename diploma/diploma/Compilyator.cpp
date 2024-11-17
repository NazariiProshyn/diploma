#include "Compilyator.h"

namespace NMCompMsg
{
	const std::string notOpenFile = "Can not open file: ";//
	std::string unkownSymbol{ "Unknown symbol: " };
}

Compilyator::Compilyator()
{
	fin.open(pathFile);
}

Compilyator::~Compilyator()
{
	fin.close();
}

bool Compilyator::checkFile()
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
