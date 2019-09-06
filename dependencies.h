#ifndef DEPENDENCIES_H
#define DEPENDENCIES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


typedef struct word_struct {
  char languageType[20];
  char showWord[100];
  bool isFull;
} wordInfo;

typedef struct wordList_struct {
  wordInfo gameWords[4];
} wordList;

wordList getWords(FILE* userFile);
int gameExecute(wordList setup);
void printScore(int userScore, int numRounds);

#endif
