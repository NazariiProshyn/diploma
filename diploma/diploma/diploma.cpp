
#include "Parcer.h"

int main()
{
	Parcer parcer;

	if (parcer.checkFile())
	{
		if (parcer.parcing())
		{

		}
		else
		{

		}
	}
	else
	{
		std::cout << parcer.getError();
	}

	//std::cout << parcer.getWARN();
}

