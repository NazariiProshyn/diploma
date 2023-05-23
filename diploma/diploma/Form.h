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
	void createLabel();

private:
	int sizeVert = 720;
	int sizeGorz = 1200;
	std::string name = "Form";

	std::vector<Button> buttons;
	std::vector<Label>  labels;

};

