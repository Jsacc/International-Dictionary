#include "Include.h"

/*reconfigured to work on 12/17/2019 9:38PM
program waws not finding kernal.lib
copy and pasted all headers and source files to new program 
*/
using namespace std;

int main()
{
	vector<Dictionary>*Vec_Ptr = new vector<Dictionary>;
	Vec_Ptr->resize(100);//resize the vector with the number of lines counted from the file 
	Menu menu;
	Dictionary dictionary;
	dictionary.checkOpenFile(*Vec_Ptr);

	menu.charMenu(Vec_Ptr);

	cout << endl;
}