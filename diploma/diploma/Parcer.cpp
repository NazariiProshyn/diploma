#include "Parcer.h"

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
		error.setError(notOpenFile + pathFile, line);
		return false;
	}
	
}
