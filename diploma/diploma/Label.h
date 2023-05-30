#pragma once
#include <iostream>
#include "Text.h"
class Label
{
public:
	Label() = default;
	~Label() = default;


	void setPositionVert(int info);
	int  getPositionVert();
	void setPositionGorz(int info);
	int  getPositionGorz();

	Text text;

private:
	int positionVert = 0;
	int positionGorz = 0;
	
};

