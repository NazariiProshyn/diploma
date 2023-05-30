#include "Form.h"

void Form::setSizeVert(int info)
{
	sizeVert = info;
	std::cout << "Set sizeVert: " << info << " for " << name << '\n';
}

int Form::getSizeVert()
{
	return sizeVert;
}

void Form::setSizeGorz(int info)
{
	sizeGorz = info;
	std::cout << "Set sizeGorz: " << info << " for " << name << '\n';
}

int Form::getSizeGorz()
{
	return sizeGorz;

}

void Form::createButton()
{
	Button button;
	buttons.push_back(button);
	std::cout << "Create button in " << name << '\n';
}

void Form::createLabel()
{
	Label label;
	labels.push_back(label);
	std::cout << "Create label in " << name << '\n';
}
