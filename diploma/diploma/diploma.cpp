
#include "Parcer.h"

int main()
{
	Parcer parcer;

	if (parcer.checkFile())
	{

	}
	else
	{
		std::cout << parcer.getError();
	}

	//std::cout << parcer.getWARN();
}

