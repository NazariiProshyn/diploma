#include "Text.h"

void Text::setPositionVert(int info)
{
	positionVert = info;
	std::cout << "Set positionVert: " << info << " for " << text << '\n';

}

int Text::getPositionVert()
{
	return positionVert;
}

void Text::setPositionGorz(int info)
{
	positionGorz = info;
	std::cout << "Set positionGorz: " << info << " for " << text << '\n';
}

int Text::getPositionGorz()
{
	return positionGorz;
}

void Text::setHeight(int info)
{
	height = info;
	std::cout << "Set height: " << info << " for " << text << '\n';
}

int Text::getHeight()
{
	return height;
}

void Text::setItalic()
{
	italic = true;
	std::cout << "Set italic " << "for " << text << '\n';
}

bool Text::getItalic()
{
	return italic;
}

void Text::setUnderline()
{
	underline = true;
	std::cout << "Set underline " << "for " << text << '\n';
}

bool Text::getUnderline()
{
	return underline;
}

void Text::setBold()
{
	bold = true;
	std::cout << "Set bold " << "for " << text << '\n';
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
	std::cout << "Set text: " << info << " for " << text << '\n';
}
