#include "dependencies.h"

int main() {
  int score = 0;
  int roundsPlayed = 0;
  char playOn = ' ';
  bool runGame = true;
  FILE* gameType = NULL;
  char gameName[100] = " ";
  wordList round;
  // Random is used a lot in this program
  srand(time(NULL));

  // Prompts for file name
  printf("Please enter your file name... \n");
  scanf("%s", gameName);
  strcat(gameName, ".txt");

  // Here we assign the FILE pointer to the game file
  gameType = fopen(gameName, "r");

  // If the file is invalid, the program ends
  if (gameType == NULL) {
    printf("Not a valid file\n");
    return -1;
  }
  while(runGame) {
    // Runs the getWords function to set up a round
    round = getWords(gameType);
    // Here we play the round and add any wins to score
    score = score + gameExecute(round);
    printf("\nSCORE: %d\n", score);
    getchar();
    roundsPlayed++;
    // Prints the score
    printScore(score, roundsPlayed);

    // Asks the user if they want to play again
    while(true) {
      printf("Play again? (Y/N)\n");
      scanf("%c", &playOn);
      if (playOn == 'Y' || playOn == 'y') {
        runGame = true;
        break;
      } else if (playOn == 'N' || playOn == 'n') {
        runGame = false;
        break;
      } else {
        printf("Invalid entry, try again...\n");
        continue;
      }
    }
  }

  fclose(gameType);

  return 0;
}
