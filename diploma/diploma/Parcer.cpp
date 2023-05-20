#include "Parcer.h"

namespace NMMessages
{
	const std::string notOpenFile = "can not open file: ";
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
	return false;
}
