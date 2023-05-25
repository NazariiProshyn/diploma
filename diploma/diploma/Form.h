#pragma once
#include <iostream>
#include <vector>

#include "Button.h"
#include "Label.h"
class Form
{
public:
	Form() = default;
	~Form() = default;


	void setSizeVert(int info);
	int  getSizeVert();
	void setSizeGorz(int info);
	int  getSizeGorz();


	void createButton();
	void setButtonSizeVert(int info);
	void setButtonSizeGorz(int info);
	void setButtonPositionVert(int info);
	void setButtonPositionGorz(int info);
	void setButtonText(std::string info);


	void createLabel();
	void setPositionVert(int info);
	void setPositionGorz(int info);
	void setText(std::string info);

private:
	int sizeVert = 720;
	int sizeGorz = 1200;
	std::string name = "Form";

	std::vector<Button> buttons;
	std::vector<Label>  labels;

};

