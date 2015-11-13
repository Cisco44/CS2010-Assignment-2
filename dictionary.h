#ifndef DICTIONARY_H

#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

extern DICT dictionary;
extern WORD word;
extern int count[MAX];
extern int dictCoun;


int LocateWord(DICT&, WORD, int);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT&, WORD, int [], int);
WORD GetNextWord(void);
void DumpDictionary(DICT&, int[], int);


#endif
