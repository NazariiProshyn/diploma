#include "Text.h"

void Text::setPositionVert(int info)
{
	positionVert = info;
}

int Text::getPositionVert()
{
	return positionVert;
}

void Text::setPositionGorz(int info)
{
	positionGorz = info;
}

int Text::getPositionGorz()
{
	return positionGorz;
}

std::string Text::getText()
{
	return text;
}

void Text::setText(std::string info)
{
	text = info;
}
