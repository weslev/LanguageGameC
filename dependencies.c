#include "dependencies.h"

wordList getWords(FILE* userFile) {
  // Variables
  int select = 0;
  int count = 0;
  wordList tempList;
  char tempWord[100] = " ";
  char tempLanguage[100] = " ";

  // This loop sets up the array of structs
  while(count < 4) {
    select = rand() % 100;
    // If we're at the end of file, it'll rewind
    // This loop assigns the random word for the size of the array
    for(int i = 0; i <= select; i++) {
      if (feof(userFile)) {
        rewind(userFile);
      }
      // Here we put the words from the file into the struct
      fscanf(userFile, "%s %s", tempWord, tempLanguage);

      // This loop prevents duplicate languages
      for (int j = 0; j < 4; j++) {
        if(strcmp(tempLanguage, tempList.gameWords[j].languageType) == 0) {
          i--;
          continue;
        }
      }

      // Now we add the words to the struct
      strcpy(tempList.gameWords[count].showWord, tempWord);
      strcpy(tempList.gameWords[count].languageType, tempLanguage);



    }

    count++;
  }

  return tempList;
}

int gameExecute(wordList setup) {
  int questionWord;
  int userChoice = -1;

  // This selects a random word from the list
  questionWord = rand() % 4;

  printf("What langauge is this word from: ");
  printf("%s\n", setup.gameWords[questionWord].showWord);

  printf("| 1. %-5s ", setup.gameWords[0].languageType);
  printf("| 2. %-5s |\n", setup.gameWords[1].languageType);
  printf("| 3. %-5s ", setup.gameWords[2].languageType);
  printf("| 4. %-5s |\n", setup.gameWords[3].languageType);

  // Prompts the user for their choice
  while(true) {
    printf("From what langauge is this word? (Please type the number): ");
    scanf("%d", &userChoice);

    // Prevents user from choosing something outside of the range
    if (userChoice > 0 && userChoice < 5) {
      break;
    } else {
      printf("Invalid number! Try again...\n");
      continue;
    }
  }

  // Checks if the user got the question right and returns the score
  if ((userChoice - 1) == questionWord) {
    printf("Good job! You got it right!\n\n");
    return 1;
  } else {
    printf("Sorry, but the correct answer was: ");
    printf("%s\n\n", setup.gameWords[questionWord].languageType);
    return 0;
  }
}

void printScore(int userScore, int numRounds) {
  int losses = 0;
  double ratio = 0;
  losses = numRounds - userScore;
  printf("Wins: %d Losses: %d W/L ratio: ", userScore, losses);
  if (losses == 0) {
      printf("N/A\n");
  } else {
    ratio = userScore / (double)losses;
    printf("%0.2lf\n", ratio);
  }
}
