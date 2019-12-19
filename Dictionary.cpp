#include "Include.h" // includes menu.h and dictionary.h
int numLines = 0;   // global variable nuber lines need this, not sure where or when else I use it 
ifstream input;		//global fstream i open and close to often not to 
bool test = false; //bool for testing
Menu menu;			//we might use it more than once

void Dictionary::checkOpenFile(vector<Dictionary>&Vec_Ptr) {


	input.open("Dictionary.txt"); // opens our file for reading

								  //---------------------------------------------------------------------------------
	string line;
	if (input.is_open()) {
		while (!input.eof())
		{
			getline(input, line);          //counter was gonna be in its own function but no need can do here
			numLines++;
			if (test) cout << line << '\n';

		}
		//---------------------------------------------------------------------------------
	}
	input.clear();
	input.seekg(0, ios::beg);
	if (input) {// if true call populate

		populateDictionary(&Vec_Ptr); // here at 11:47PM check 1 pass move to define populate dic

		if (test)cout << "\nOPENED\n"; //for testing 

	}
	else
		cerr << "Error: No such file exists..."; //no file message

	if (test)cout << "\nHERE\n"; //for testing 
	input.close();//close file here

}

void Dictionary::populateDictionary(vector<Dictionary> *Vec_Ptr)
{
	/*****BELOW****
	Are my variables
	*/
	ifstream input;

	bool keepOn = true;

	string language, partOfSpeech, word, english,
		article, index, specialChar, temp;

	input.open("Dictionary.txt");

	for (int i = 0; i < numLines && keepOn; i++)
	{
		getline(input, language, ' ');
		getline(input, partOfSpeech, ' ');
		getline(input, article, ' ');
		getline(input, word, ' ');
		getline(input, specialChar, ' ');
		getline(input, index, ' ');
		getline(input, english, '\n');

		/***BELOW***
		i check the first and second letter to upper
		why make a func just to turn a string to upper though easy
		*/
		if (toupper(partOfSpeech[0]) == 'C' && toupper(partOfSpeech[1]) == 'A')
		{
			partOfSpeech = (partOfSpeech + " " + article);
			article = word;
			word = specialChar;
			specialChar = index;
			index.clear();
			int j = 0;

			for (; english[j] != ' '; j++)
			{
				index.push_back(english[j]);
			}
			english.erase(0, j + 1);

		}

		//switchChar(Vec_Ptr, stoi(index), (char)specialChar, true)
		Vec_Ptr->at(i).language = language;
		Vec_Ptr->at(i).partOfSpeech = partOfSpeech;
		Vec_Ptr->at(i).word = word;
		Vec_Ptr->at(i).english = english;
		Vec_Ptr->at(i).article = article;
		Vec_Ptr->at(i).index = index;
		Vec_Ptr->at(i).specialChar = specialChar;

	}
	input.close();
	Vec_Ptr->begin();

}

void Dictionary::searchWord(vector<Dictionary>*Vec_Ptr)		//search word from the file was originally a test function
{															//checking if words like credit card were in the correct spot
	system("cls");											//clears the screen
	string word{}, again{}; //{} intialize the string ;										//again is a to run again if word used not match, word is the user input
	bool flagIt = false;									//flagit set to true if a match was found 
	cout
		<< "You choose search, input a word and it will return the translations, in other languages."
		<< "\nWhat word would you like to see the translations for? ";
	try
	{
		getline(cin, word);
	}
	catch (const std::exception&)
	{
		cerr << "Invalid Input try again! ";
		_getch();
		searchWord(Vec_Ptr);
	}


	for (int i = 0; i < numLines; i++)
	{
		if (Vec_Ptr->at(i).word == word || Vec_Ptr->at(i).english == word)
		{
			flagIt = true;
			cout << Vec_Ptr->at(i).language << "    " << Vec_Ptr->at(i).partOfSpeech << "    " << Vec_Ptr->at(i).english
				<< "    " << Vec_Ptr->at(i).word << endl;
		}
	}
	if (flagIt != true)
	{
		again = "";
		cout << "\nNo word entered your input " << word << " would you like to try again? ";
		getline(cin, again);
		if (toupper(again.at(0)) == 'Y')
			searchWord(Vec_Ptr);
		else
			menu.endOfProgram(Vec_Ptr);
	}
	else
	{
		again = "";
		cout << "\nThat is all the words. Would you like to search another word? ";
		getline(cin, again);
		if (toupper(again.at(0)) == 'Y')
			searchWord(Vec_Ptr);
		else
			menu.endOfProgram(Vec_Ptr);
	}
}

void Dictionary::seperateByType(vector<Dictionary>*Vec_Ptr, string fromlanguage, string toLanguage, string type) // variable name is not named well but the fution will split the set dictionary by the option
{
	system("cls"); //clears trhe screen
	cout << "Translation from " << fromlanguage << " to " << toLanguage << '\n';
	for (int l = 0; l < numLines; l++)
	{

		if (Vec_Ptr->at(l).partOfSpeech == type)
			if (partOfSpeech == "cardinal number")
				cout << Vec_Ptr->at(l).language << "  " << Vec_Ptr->at(l).partOfSpeech << "   " << Vec_Ptr->at(l).word << "   " << Vec_Ptr->at(l).english << endl << endl;
			else
				cout << Vec_Ptr->at(l).language << "  " << Vec_Ptr->at(l).partOfSpeech << "   " << Vec_Ptr->at(l).word << "   " << Vec_Ptr->at(l).english << endl << endl;
	}
	cout << "\nPress any key to continue...";
	cin.get();
	//menu.endOfProgram(Vec_Ptr);		//end of program funtion

}


void Dictionary::printAll(vector<Dictionary>*Vec_Ptr, string fromLanguage) // prints all words
{
	if (fromLanguage != "toEnglish")
		for (int j = 0; j < numLines; j++)
			cout
			<< Vec_Ptr->at(j).language << "  " << Vec_Ptr->at(j).partOfSpeech << "   "
			<< Vec_Ptr->at(j).word << "   " << Vec_Ptr->at(j).specialChar << "   "
			<< Vec_Ptr->at(j).english << endl << endl;
	else
		for (int j = 0; j < numLines; j++)
			cout << "English  " << Vec_Ptr->at(j).partOfSpeech << "   " << Vec_Ptr->at(j).article << "   " << Vec_Ptr->at(j).english
			<< "   " << Vec_Ptr->at(j).word << endl << endl;
	cout << "\nPress any key to continue...";
	cin.get();


}

void Dictionary::reverseVector(vector<Dictionary>*Vec_Ptr)   //reverses the vector of struct definitions
{
	vector<Dictionary>*temp = new vector<Dictionary>();		//temp vector deleted after use
	temp->resize(100);


	for (int i = 0; i < Vec_Ptr->capacity(); i++)
		temp->at(i) = Vec_Ptr->at(Vec_Ptr->capacity() - (i + 1));


	printAll(temp, "fromEnglish");
	Vec_Ptr->empty();
	Vec_Ptr->swap(*temp);     //swap the temp vector back to the one used throughtout the program
	delete temp;			//delete temp vec

	cout << "The word list is now in reverse order. To undo this enter any number other than 1 - 17...\n\n";

	//menu.endOfProgram(Vec_Ptr);   //cleanly exits if you want


}

void Dictionary::addWordList(vector<Dictionary>*Vec_Ptr)
{
	Dictionary dict;
	dict.capacity = new int;
	delete Vec_Ptr;							//delete the original vec
	Vec_Ptr = new vector<Dictionary>;		//create a new one
	char languageSpecial = ' ';
	string keepOn, languageTo, languageFrom, languageIndex, isLanguageSpecial = "-1", languagePart, languageWord, languageArticle;				//point to a string array and keepon which is yeas or no to continue
																																				//new array list 7 for the input

																																				/*
																																				Not impressed by this for loop, if i change it i do but for now
																																				it is calling getline 7 times for a string array where it reads into
																																				the construnter for the struct, it works its just not pretty
																																				*/

	for (int i = 0; toupper(keepOn[0]) != 'N'; i++)
	{
		Vec_Ptr->resize(i + 1); // expands out vector to add more to it 
		system("cls");

		cout << "\nEnter the language the word is being translated from: ";
		getline(cin, languageFrom);

		cout << "\nEnter the part of speech for the word: ";
		getline(cin, languagePart);

		cout << "\nEnter the word to be translated: ";
		getline(cin, languageTo);

		cout << "\nEnter the translated word: ";
		getline(cin, languageWord);


		if (toupper(languageFrom[0]) == 'F' && toupper(languageFrom[2]) == 'E' || toupper(languageFrom[0]) == 'H' && toupper(languageFrom[2]) == 'B'
			|| toupper(languageFrom[0]) == 'G' && toupper(languageFrom[2]) == 'R')
		{
			cout << "\nEnter the article: ";
			getline(cin, languageArticle);
		}
		else
			languageArticle = "No Ariticle! ";

		cout << "\nIf there is a special character enter its postion in the word, else enter \"No\": ";
		getline(cin, isLanguageSpecial);


		if (toupper(isLanguageSpecial[0]) == 'N')
		{
			isLanguageSpecial[0] = -1;		//if not set to a crazy value

		}
		else {


			specialCh();
			languageSpecial = getSpecialChar();
			switchChar(languageWord, stoi(isLanguageSpecial), i, languageSpecial);
		}
		//tempLocatVal = stoi(languageSpecial);
		//cout << "\n\n" << languageSpecial<< "\n\n";




		//the next few lines set the struct 
		Vec_Ptr->at(i).language = languageFrom;
		Vec_Ptr->at(i).partOfSpeech = languagePart;
		Vec_Ptr->at(i).word = languageTo;
		Vec_Ptr->at(i).english = languageWord;
		Vec_Ptr->at(i).article = languageArticle;
		Vec_Ptr->at(i).index = isLanguageSpecial;
		Vec_Ptr->at(i).specialChar = languageSpecial;




		cout << "\n\nWould you like to add another definition? ";
		getline(cin, keepOn);

		capacity = (int*)Vec_Ptr->capacity(); //sets capcity for next use of add words

	}

	cout
		<< "..................................User created dictionary...................................\n"
		<< " From language	    Part of Speech	    	Word    	To language	    	Translated word\n";

	string fromLanguage = "English ", toLanguage{};

	for (int i = 0; i < Vec_Ptr->capacity(); i++)
	{
		if (toupper(Vec_Ptr->at(i).language[0] != 'E') && toupper(Vec_Ptr->at(i).language[2] != 'G'))
		{
			fromLanguage = Vec_Ptr->at(i).language;
			toLanguage = "English ";
		}
		else
			toLanguage = Vec_Ptr->at(i).language;

		cout
			<< fromLanguage << "    " << Vec_Ptr->at(i).partOfSpeech << "    " << Vec_Ptr->at(i).word << "    "
			<< toLanguage << "    " << Vec_Ptr->at(i).english << endl;

	}
	Vec_Ptr->begin();						//points back to 0 on the vector

	writeNewFile(*Vec_Ptr);
	cout << "\nPress any key to continue...\n";
	_getch();
	//menu.endOfProgram(Vec_Ptr);				//cleanly exits if you want
}

int Dictionary::getSpecialChar()  //returns special character 
{
	unsigned char key, key2;
	while ((key = _getch()) != '/r') {
		if (key == 0) {
			key2 = _getch();
			switch (key2) {
			case 59:cout << (char)153;
				return 153;
				break;
			case 60:cout << (char)132;
				return 132;
				break;
			case 61:cout << (char)129;
				return 129;
				break;
			case 62:cout << (char)148;
				return 148;
				break;
			case 63:cout << (char)135;
				return 135;
				break;
			case 64:cout << (char)130;
				return 130;
				break;
			case 65:cout << (char)136;
				return 136;
				break;
			case 66:cout << (char)138;
				return 138;
				break;
			default: return -1;

			}
		}

	}
	return 0;
}


void Dictionary::switchChar(string& word, int index, char special, int i) // bool so we can use two places maybe more later
{


	word.at(index - 1) = (char)i;
	//Vec_Ptr->at(i).word.at(index-1) = special ;

}

void Dictionary::writeNewFile(vector<Dictionary> &Vec_Ptr)
{
	ofstream outFile;

	string fromLanguage = "English ", toLanguage{};

	outFile.open("userCreatedDictionary.txt");                             //creates new dictionary 
	outFile
		<< "..................................User created dictionary..................................\n"
		<< " From language	Part of Speech		Word	To language		Translated word\n";

	for (int i = 0; i < Vec_Ptr.capacity(); i++)
	{
		if (toupper(Vec_Ptr[i].language[0] != 'E') && toupper(Vec_Ptr[i].language[2] != 'G'))
		{
			fromLanguage = Vec_Ptr[i].language;
			toLanguage = "English ";
		}
		else
			toLanguage = Vec_Ptr[i].language;

		{
			outFile << fromLanguage << "    " << Vec_Ptr[i].partOfSpeech << "    " << Vec_Ptr[i].word << "    "
				<< toLanguage << "    " << Vec_Ptr[i].english << endl;
		}
	}
	outFile.close();


}

void Dictionary::specialCh()  //display for chars
{
	cout << "\n\nType F1 for " << (char)153 << endl;
	cout << "Type F2 for " << (char)132 << endl;
	cout << "Type F3 for " << (char)129 << endl;
	cout << "Type F4 for " << (char)148 << endl;
	cout << "Type F5 for " << (char)135 << endl;
	cout << "Type F6 for " << (char)130 << endl;
	cout << "Type F7 for " << (char)136 << endl;
	cout << "Type F8 for " << (char)138 << endl;
	cout << "Enter any special characters: ";

}

