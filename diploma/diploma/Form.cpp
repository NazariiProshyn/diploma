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

void Form::setButtonSizeVert(int info)
{
	buttons[buttons.size() - 1].setSizeVert(info);
}

void Form::setButtonSizeGorz(int info)
{
	buttons[buttons.size() - 1].setSizeGorz(info);
}

void Form::setButtonPositionVert(int info)
{
	buttons[buttons.size() - 1].setPositionVert(info);
}

void Form::setButtonPositionGorz(int info)
{
	buttons[buttons.size() - 1].setPositionGorz(info);
}

void Form::setButtonText(std::string info)
{
	buttons[buttons.size() - 1].setText(info);
}

void Form::createLabel()
{
	Label label;
	labels.push_back(label);
}

void Form::setPositionVert(int info)
{
	labels[labels.size() - 1].setPositionVert(info);
}

void Form::setPositionGorz(int info)
{
	labels[labels.size() - 1].setPositionGorz(info);
}

void Form::setText(std::string info)
{
	labels[labels.size() - 1].setText(info);
}
