#pragma once
#include <iostream>
class Text
{
public:
	Text() = default;
	~Text() = default;


	void setPositionVert(int info);
	int  getPositionVert();
	void setPositionGorz(int info);
	int  getPositionGorz();

	std::string getText();
	void setText(std::string info);

private:
	int positionVert = 0;
	int positionGorz = 0;
	std::string text = "Text";


};

