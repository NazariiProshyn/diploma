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

void Text::setHeight(int info)
{
	height = info;
}

int Text::getHeight()
{
	return height;
}

void Text::setItalic()
{
	italic = true;
}

bool Text::getItalic()
{
	return italic;
}

void Text::setUnderline()
{
	underline = true;
}

bool Text::getUnderline()
{
	return underline;
}

void Text::setBold()
{
	bold = true;
}

bool Text::getBold()
{
	return bold;
}

std::string Text::getText()
{
	return text;
}

void Text::setText(std::string info)
{
	text = info;
}
