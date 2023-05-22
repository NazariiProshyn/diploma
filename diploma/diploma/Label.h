#pragma once
#include <iostream>
#include "Text.h"
class Label
{
	Label() = default;
	~Label() = default;


	void setPositionVert(int info);
	int  getPositionVert();
	void setPositionGorz(int info);
	int  getPositionGorz();

	std::string getText();
	void setText(std::string info);

private:
	int positionVert = 0;
	int positionGorz = 0;
	Text text;
};

