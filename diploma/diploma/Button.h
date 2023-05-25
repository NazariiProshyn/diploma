#pragma once
#include <iostream>
#include "Text.h"
class Button
{
public:
	Button() = default;
	~Button() = default;


	void setSizeVert(int info);
	int  getSizeVert();
	void setSizeGorz(int info);
	int  getSizeGorz();
	void setPositionVert(int info);
	int  getPositionVert();
	void setPositionGorz(int info);
	int  getPositionGorz();

	std::string getText();
	void setText(std::string info);

private:

	int sizeVert = 72;
	int sizeGorz = 120;
	int positionVert = 0;
	int positionGorz = 0;
	Text text;
};

