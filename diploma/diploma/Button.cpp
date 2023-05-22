#include "Button.h"

void Button::setSizeVert(int info)
{
	sizeVert = info;
}

int Button::getSizeVert()
{
	return sizeVert;
}

void Button::setSizeGorz(int info)
{
	sizeGorz = info;
}

int Button::getSizeGorz()
{
	return sizeGorz;
}

void Button::setPositionVert(int info)
{
	positionVert = info;
}

int Button::getPositionVert()
{
	return positionVert;
}

void Button::setPositionGorz(int info)
{
	positionGorz = info;
}

int Button::getPositionGorz()
{
	return positionGorz;
}

std::string Button::getText()
{
	return text.getText();
}

void Button::setText(std::string info)
{
	text.setText(info);
}
