#ifndef MENU_H
#define MENU_H

#include "Include.h"

class Menu {
public:

	int selection;

	void switchOptions(vector<Dictionary>*, int);
	void charMenu(vector<Dictionary>*);
	void option1(vector<Dictionary>*);
	void option2(vector<Dictionary>&);
	void option3(vector<Dictionary>&);
	void option4(vector<Dictionary>&);
	void option5(vector<Dictionary>&);
	void option6(vector<Dictionary>&);
	void option7(vector<Dictionary>&);
	void option8(vector<Dictionary>&);
	void option9(vector<Dictionary>&);
	void option10(vector<Dictionary>&);
	void option11(vector<Dictionary>&);
	void option12(vector<Dictionary>&);
	void option13(vector<Dictionary>&);
	void option14(vector<Dictionary>&);
	void option15(vector<Dictionary>&);
	void option16(vector<Dictionary>&);
	void option17();

	void endOfProgram(vector<Dictionary>*);
};
#endif 