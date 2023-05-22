#include "Label.h"

void Label::setPositionVert(int info)
{
	positionVert = info;
}

int Label::getPositionVert()
{
	return positionVert;
}

void Label::setPositionGorz(int info)
{
	positionGorz = info;
}

int Label::getPositionGorz()
{
	return positionGorz;
}

std::string Label::getText()
{
	return text.getText();
}

void Label::setText(std::string info)
{
	text.setText(info);
}
