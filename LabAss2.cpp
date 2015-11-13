#include "dictionary.h"

/*
	Author: Da Costa, Francisco
	Student ID: 5026516
	Purpose:

		The main function is designed to create a dictionary by reading a file.
		It has a maximum storage capacity of a hundred unique words. 
		It will store read words into the dictionary, as strings, and count the number of appearences of
		stored words. 
		When the program encounters a null string it will assume the file has been terminated,
		and will write the dictionary to the terminal, along with each words respective count.
		
		It also handles the case of the dictionary being full. It writes out to the terminal a 
		message aknowledging that the word cannot be stored, as the dictionary is full, and then
		continues analysing the rest of the document until termination. It doesn't end immediately,
		so that it may still count future occurances of words already stored in the dictionary.

*/

DICT dictionary;
WORD word;
int count[MAX];
int dictCount = 0;

int main(void){

	int pos = 0;
	
	while(1){
		word = GetNextWord();
		if("" == word){
			DumpDictionary(dictionary, count, dictCount);
			break;
		}
		if( (pos = LocateWord(dictionary,word, dictCount) ) >= 0 ){
			count[pos]++;
		}
		else
			if(!InsertWord(dictionary, word, count, dictCount))
				cout << "The dictionary is full the word \"" << word
				<< "\" cannot be added." << endl;
			else dictCount++;
	}
	return 0;

}

