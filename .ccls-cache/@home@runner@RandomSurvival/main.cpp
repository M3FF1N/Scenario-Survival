#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <vector>
using namespace std;

// Functions
void menu();
void startGame();
void instructions();
void nextDay();
int exit();
int day = 0;
int scenario;

// Main
int main(){
  menu();
  return 0;
}

// Menu
void menu () {
  // Options
  cout << "\033[2J\033[0;0H";
  cout << "---------------- Random Survival ----------------\n\n";
  cout << "0 - Start Game\n";
  cout << "1 - Instructions\n";
  cout << "2 - Exit\n\n";

  // Option Selecting
  int menuSelect;
  cin >> menuSelect;
  
  switch (menuSelect) {
    case 0: {
      startGame();
      break;
    }
    case 1: {
      instructions();
      break;
    }
    case 2: {
      exit();
      break;
    }
  }

  // Typing in invalid options
  while (menuSelect > 2 || menuSelect < 0) {
    cout << "\033[2J\033[0;0H";
    cout << "Nice try ;) Please type in a number between 1 and 3 to pick a game\n\n";
    menu();
  }
}

// Starting the game
void startGame () {
  // Variables
  int health = 16;
  int stamina = 16;
  int day = 0;
  
  // Information + Options
  cout << "\033[2J\033[0;0H";
  cout << "---------------- Day " << day << " ----------------\n\n";
  cout << "Health - " << health << endl;
  cout << "Stamina - " << stamina << endl << endl;
  cout << "Continue to day " << day+1 << "?\n\n";
  cout << "0 - Continue\n";
  cout << "1 - Return to Main Menu\n\n";

  // Continuing to day 1
  int continueToNextDay;
  cin >> continueToNextDay;

  switch (continueToNextDay) {
    case 0: {
      nextDay();
      break;
    }
    case 1: {
      menu();
    }
  }
}

void nextDay () {
  day++;
  cout << "\033[2J\033[0;0H";
  cout << "---------------- Day " << day << " ----------------\n\n";
  cout << "Health - " << health << endl;
  cout << "Stamina - " << stamina << endl << endl;
  
  // Scenarios
  int scenarios[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  srand((unsigned)time(0));
  int scenario = rand()%10;
  
  switch (scenario) {
    case 0: {
      cout << "A group of zombies has appeared nearby!\n\n";
      cout << "What will you do?\n\n";
      cout << "0 - Fight the zombies\n";
      cout << "1 - Run away\n";
      cout << "2 - Stay put\n";
      break;
    }
    case 1: {
      cout << "Scenario = 1";
      break;
    }
    case 2: {
      cout << "Scenario = 2";
      break;
    }
    case 3: {
      cout << "Scenario = 3";
      break;
    }
    case 4: {
      cout << "Scenario = 4";
      break;
    }
    case 5: {
      cout << "Scenario = 5";
      break;
    }
    case 6: {
      cout << "Scenario = 6";
      break;
    }
    case 7: {
      cout << "Scenario = 7";
      break;
    }
    case 8: {
      cout << "Scenario = 8";
      break;
    }
    case 9: {
      cout << "Scenario = 9";
      break;
    }
  }
}

// Instructions
void instructions () {
  cout << "\033[2J\033[0;0H";
  cout << "Haha I haven't made the instructions yet hahahahaha\n\n";
  menu();
}

// Exit
int exit () {
  cout << "\033[2J\033[0;0H";
  return 0;
}