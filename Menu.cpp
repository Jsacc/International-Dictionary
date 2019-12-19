#include "Include.h"

Dictionary dictionary;

void Menu::charMenu(vector<Dictionary>*Vec_Ptr) {					//display for char menu

	system("cls");
	cout
		<< "******************************************************************\n"
		<< "******************************************************************\n"
		<< "****************** Programmer: James Sacchetti *******************\n"
		<< "****************** Instructor: Arland Richmond *******************\n"
		<< "****************** Modified  : 3/20/2016       *******************\n"
		<< "******************************************************************\n"
		<< "******************* International Dictionary *********************\n"
		<< "******************************************************************\n"
		<< "******************************************************************\n"
		<< "1.  Create word list \n"
		<< "2.  German(French, Latin, Hebrew) to English nouns \n"
		<< "3.  German(French, Latin, Hebrew) to English verbs \n"
		<< "4.  German(French, Latin, Hebrew) to English prepositions \n"
		<< "5.  German(French, Latin, Hebrew) to English adverbs \n"
		<< "6.  German(French, Latin, Hebrew) to English adjectives \n"
		<< "7.  German(French, Latin, Hebrew) to English cardinal numbers \n"
		<< "8.  German(French, Latin, Hebrew) to English all \n"
		<< "9.  English to (German, French, Latin, Hebrew) nouns \n"
		<< "10. English to (German, French, Latin, Hebrew) verbs \n"
		<< "11. English to (German, French, Latin, Hebrew) perpositions \n"
		<< "12. English to (German, French, Latin, Hebrew) adjectives \n"
		<< "13. English to (German, French, Latin, Hebrew) adverbs \n"
		<< "14. English to (German, French, Latin, Hebrew) cardinal numbers \n"
		<< "15. English to (German, French, Latin, Hebrew) all \n"
		<< "16. Search for a word in one language and return the other languages\n"
		<< "17. Quit\n"
		<< "Enter your selection: ";




	cin >> selection; cin.ignore(80, '\n');

	switchOptions(Vec_Ptr, selection);
}


void Menu::switchOptions(vector<Dictionary>*Vec_Ptr, int select) {
	switch (select) {

	case 1: option1(Vec_Ptr); break;
	case 2: option2(*Vec_Ptr); break;
	case 3: option3(*Vec_Ptr); break;
	case 4: option4(*Vec_Ptr); break;
	case 5: option5(*Vec_Ptr); break;
	case 6: option6(*Vec_Ptr); break;
	case 7: option7(*Vec_Ptr); break;
	case 8: option8(*Vec_Ptr); break;
	case 9: option9(*Vec_Ptr); break;
	case 10: option10(*Vec_Ptr); break;
	case 11: option11(*Vec_Ptr); break;
	case 12: option12(*Vec_Ptr); break;
	case 13: option13(*Vec_Ptr); break;
	case 14: option14(*Vec_Ptr); break;
	case 15: option15(*Vec_Ptr); break;
	case 16: option16(*Vec_Ptr); break;
	case 17: option17(); break;
	default: dictionary.reverseVector(Vec_Ptr);

	}

}

void Menu::endOfProgram(vector<Dictionary>*Vec_ptr)						//nice way to exit
{
	system("cls");
	string keepGoing;

	cout << "Would you like to continue? (Enter: yes or no) ";			//takes yes no or any thing as long as first letter is y or n
	try {

		cin >> keepGoing;
	}
	catch (exception e) {
		cout << "Invalid numeric value\n";
	}

	if (toupper(keepGoing[0]) == 'N')
	{
		system("exit");
	}
	else
	{
		system("cls");			//clears screen
		charMenu(Vec_ptr);		//calls main menu
	}

}

/*I Really hate how below looks*/
void Menu::option1(vector<Dictionary>*Vec_Ptr) { dictionary.addWordList(Vec_Ptr); endOfProgram(Vec_Ptr); }												//create word list
void Menu::option2(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "German", "English", "noun"); endOfProgram(&Vec_Ptr); }			//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option3(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "German", "English", "verb"); endOfProgram(&Vec_Ptr); }			//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option4(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "German", "English", "preposition"); endOfProgram(&Vec_Ptr); }		//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option5(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "German", "English", "adverb"); endOfProgram(&Vec_Ptr); }			//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option6(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "German", "English", "adjectives"); endOfProgram(&Vec_Ptr); }		//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option7(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "German", "English", "cardinal number"); endOfProgram(&Vec_Ptr); }	//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option8(vector<Dictionary>&Vec_Ptr) { dictionary.printAll(&Vec_Ptr, "toEnglish"); endOfProgram(&Vec_Ptr); }
void Menu::option9(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "english", "German", "noun"); endOfProgram(&Vec_Ptr); }			//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option10(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "english", "German", "verb"); endOfProgram(&Vec_Ptr); }			//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option11(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "english", "German", "preposition"); endOfProgram(&Vec_Ptr); }	//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option12(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "english", "German", "adverb"); endOfProgram(&Vec_Ptr); }			//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option13(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "english", "German", "adjectives"); endOfProgram(&Vec_Ptr); }		//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option14(vector<Dictionary>&Vec_Ptr) { dictionary.seperateByType(&Vec_Ptr, "english", "German", "cardinal number"); endOfProgram(&Vec_Ptr); }//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option15(vector<Dictionary>&Vec_Ptr) { dictionary.printAll(&Vec_Ptr, "fromEnglish"); endOfProgram(&Vec_Ptr); }//seperateByType(fromLanguage, toLanguage, partOfSpeech);
void Menu::option16(vector<Dictionary>&Vec_Ptr) { dictionary.searchWord(&Vec_Ptr); }			//search for a word
void Menu::option17() { system("exit"); }