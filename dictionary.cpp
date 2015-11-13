#include "dictionary.h"


/* Full Dictionary

FullDictionary is a function that tests to see if the dictionary is full.
It does so by verifying if it's max position is empty. If so then it returns false. 
Otherwise it will return true, indicating that it is full.

If the dictionary's size is modified in the code, then the dict
value must be changed to reflect it.

*/

BOOL FullDictionary(DICT &dict){
	
	if((dict[99]).empty()) return 0;
	return 1;
}

/* InsertWord

InsertWord inserts a read word into the dictionary. When this occurs
it also increments the count array to reflect that the word has been
added.

*/
BOOL InsertWord(DICT &dict, WORD inWord, int coun[], int dictCoun){
	
	if(dictCoun < MAX){
			dict[dictCoun] = inWord;
			++count[dictCoun];
			return 1;
	}

	return 0;
}

/* DumpDictionary

DumpDictionary writes the dictionary's stored words to the terminal,
along with the word's respective count.
It is also responsible for doing a bubble sort of both arrays before
hand. 

*/
void DumpDictionary(DICT &dict, int coun[], int dictCoun){
	
	
	for(int i = 1; i < dictCoun; ++i){
		for(int k = 0; k < dictCoun - i; ++k){
			if(dict[k] > dict[k + 1]){
				swap(dict[k], dict[k+1]);
				swap(coun[k], coun[k+1]);
			}
		}
	}

	cout << "Words			Count" << endl << endl;
	for(int i = 0; i < dictCoun; ++i){
		cout << dict[i];
		for(int j = 0; j < 24 - dict[i].length(); j++)
		cout << ' ';
		cout << coun[i] << endl;
	}
}

/* GetNextWord

GetNextWord read characters from an input stream, and stores them in 
a word. It first tests a read character to verify its validity. If 
it is valid then it proceeds to store it, and sucessive valid 
characters, into a buffer array. When it encounters an invalid character
it terminates the buffer with a null character and returns it stored
into a word.

*/
WORD GetNextWord(void){
	
	WORD tmpWord;
	char buffer[256];
        int curr = 0;
        bool inWord = false;

        while (cin.good()) {
              char ch = cin.get();
              if (isalpha(ch)) {
                  buffer[curr++] = tolower(ch);
                  inWord = true;
              } else {
                   if (inWord) {
                        buffer[curr] = '\0';
		        return tmpWord = buffer;
                   }
              }
        }
        return "";
}

/* LocateWord

LocateWord tests to see if a word already exists in the dictionary.
If so it will return the position of the value within the dictionary.
Otherwise it will return a "-1" indicating that the word doesn't
exist.

*/
int LocateWord(DICT &dict, WORD word, int dictCoun){

	for(int i = 0; i < dictCoun; i++){
		if(dict[i] == word) return i;
	}
	return -1;
}
