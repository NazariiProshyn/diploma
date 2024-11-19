#include "Compiler.h"
#include "Parcer.h"
#include <iostream>

int main()
{
	Parcer parcer;
	Compiler compiler;
	bool parcingStatus = true;

	if (compiler.lexical()) {

		if (parcer.checkFile())
		{
			if (parcer.parcing())
			{

			}
			else
			{
				parcingStatus = false;
			}
		}
		else
		{
			parcingStatus = false;
			std::cout << parcer.getError();
		}
	}
	else
	{
		parcingStatus = false;
		std::cout << parcer.getError();
	}

	//std::cout << parcer.getWARN();
}

