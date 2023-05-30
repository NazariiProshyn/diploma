#include "Form.h"

void Form::setSizeVert(int info)
{
	sizeVert = info;
	std::cout << "Set sizeVert: " << info << " for " << name;
}

int Form::getSizeVert()
{
	return sizeVert;
}

void Form::setSizeGorz(int info)
{
	sizeGorz = info;
	std::cout << "Set sizeVert: " << info << " for " << name; 
}

int Form::getSizeGorz()
{
	return sizeGorz;
}

void Form::createButton()
{
	Button button;
	buttons.push_back(button);
}

void Form::createLabel()
{
	Label label;
	labels.push_back(label);
}
