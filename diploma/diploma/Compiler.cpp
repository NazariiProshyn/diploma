#include "Compiler.h"

namespace NMCompMsg
{
	const std::string notOpenFile = "Can not open file: ";//
	std::string unkownSymbol{ "Unknown symbol: " };
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