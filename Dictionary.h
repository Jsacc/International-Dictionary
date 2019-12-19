#ifndef DICTIONARY_H
#define DICTIONARY_H

using namespace std;

struct Dictionary {
	//below the variables of the struct
	string language;
	string partOfSpeech;
	string word;
	string english;
	string article;
	string index;
	string specialChar;
	string holder;
	int *capacity;														//capcity so we can add to word list
	Dictionary() {};

	Dictionary(string str) { holder = str; };							// constructor for the string to object in the copy constructor
	Dictionary(Dictionary & obj) { holder = obj.holder; };				// copy constructor to intialize the vector
	void checkOpenFile(vector<Dictionary>&);							//checks if file exsists and calls populate dictionary 
	void populateDictionary(vector<Dictionary>*);						//called from checkOpenFile creates the structures 
	void printAll(vector<Dictionary>*, string);									//prints from the structures to the screen used for all option of the international dictionary program 
	void seperateByType(vector<Dictionary>*, string, string, string);	//used for options seaching by parts of speech 
	void reverseVector(vector<Dictionary>*);							//reverses the oreder of the vector if any num other than 1 through 17 is pressed
	void addWordList(vector<Dictionary>*);								//addswords to a new list
	int getSpecialChar();												//getsspecial characters	
	void specialCh();													//shows display
	void writeNewFile(vector<Dictionary>&);								//write to file
	void switchChar(string&, int, char, int);				//special case called from two places bool set true and false to manipulate it
	void searchWord(vector<Dictionary>*);
};
#endif