#include <iostream>
#include <string>
#include <stdlib.h>
#include "ScenarioSurvival.h"
using namespace std;

ScenarioSurvival::ScenarioSurvival() {}


// ------------------------------ Continuing To Next Day ------------------------------
void ScenarioSurvival::continueNextDay () {
  cout << "Continue to day " << day+1 << "?\n\n";
  cout << "0 - Continue\n";
  cout << "1 - Return to Main Menu\n\n";
  
  cin >> continueToNextDay;

  switch (continueToNextDay) {
    case 0: {
      int health = health;
      int stamina = stamina;
      nextDay();
      break;
    }
    case 1: {
      menu();
    }
  }

  while (day < 0 || day > 0) {
    while (continueToNextDay < 0 || continueToNextDay > 1) {
      cout << "\033[2J\033[0;0H";
      cout << "Please type in a number between 0 and 1 to select an option\n\n";
      continueNextDay();
    }
  }
};
// ------------------------------ Game Over ------------------------------
void ScenarioSurvival::gameOver() {
  
}
// ------------------------------ Instructions ------------------------------
void ScenarioSurvival::instructions () {
  cout << "\033[2J\033[0;0H";
  cout << "---------------- Scenario Survival ----------------\n\n";
  cout << "In Scenario Survival, your goal is to survive as long as possible while maintaining your stamina. When you begin the game, you will recieve a random scenario and actions to choose from. These actions will be remembered and will either help or hurt you later on. The game ends when your health reaches 0.\n\n";
  cout << "Health:\n";
  cout << "Your health is an essential part of the game. If your health drops to 0, you die and lose the game. You can lose and regain health in several scenarios.\n\n";
  cout << "Stamina:\n";
  cout << "Your stamina is another important factor to take into consideration while in the game. Certain actions take up stamina or can replenish it. Depending on your stamina levels, some actions may not be available. If your stamina runs out, your character passes out for a day and you miss being able to act on a scenario. Because of this, you have a large chance of losing the game if this happens.\n\n";
  cout << "Scenarios:\n";
  cout << "Scenarios are the most important part of Scenario Survival. Every day, you will recieve a random scenario along with serveral related actions to choose from. Depending on which action you choose, your health and/or stamina may be affected in a good or bad way.\n\n";
  cout << "Type 0 to return to the main menu\n";
  
  int returnToMenu;
  cin >> returnToMenu;
  
  switch (returnToMenu) {
    case 0: {
      menu();
      break;
    }
  }
  while (returnToMenu < 0 || returnToMenu > 0) {
    cout << "Please type in a number between 0 and 1 to select an option\n\n";
    instructions();
  }
}

// ------------------------------ Actions ------------------------------
// Fight Enemies Action
void ScenarioSurvival::action_fightEnemies() {
  cout << "\033[2J\033[0;0H";
  cout << "---------------- Day " << day << " ----------------\n\n";
  cout << "Health - " << health << endl;
  cout << "Stamina - " << stamina << endl << endl;
  
  health = health - 4;
  
  cout << "You fight the enemies...\n\n";
  cout << "...but they fight back!\n\n";
  cout << "You lose 4 health points before defeating the zombies.\n\n";
  cout << "After Scenario:\n\n";
  cout << "Health - " << health << endl;
  cout << "Stamina - " << stamina << endl << endl;
  continueNextDay();
}
// Run Away Action
void ScenarioSurvival::action_runAway() {
  cout << "\033[2J\033[0;0H";
  cout << "---------------- Day " << day << " ----------------\n\n";
  cout << "Health - " << health << endl;
  cout << "Stamina - " << stamina << endl << endl;
  
  stamina = stamina - 4;
  
  cout << "You run away from the zombies as fast as you can!\n\n";
  cout << "You lose 4 stamina points from your sprint.\n\n";
  cout << "After Scenario:\n\n";
  cout << "Health - " << health << endl;
  cout << "Stamina - " << stamina << endl << endl;
  continueNextDay();
}
// Stay Put Action
void ScenarioSurvival::action_stayPut() {
  cout << "\033[2J\033[0;0H";
  cout << "---------------- Day " << day << " ----------------\n\n";
  cout << "Health - " << health << endl;
  cout << "Stamina - " << stamina << endl << endl;
  
  cout << "You stay put and nevoursly watch the zombies wander closer to your location...\n\n";
  cout << "Your health and stamina stay put as well.\n\n";
  cout << "After Scenario:\n\n";
  cout << "Health - " << health << endl;
  cout << "Stamina - " << stamina << endl << endl;
  continueNextDay();
}

// ------------------------------ Scenarios ------------------------------
// Zombie Attack Scenario
void ScenarioSurvival::scenario_zombieAttack() {
  // Info / Options
  cout << "A group of zombies have appeared nearby!\n\n";
  cout << "What will you do?\n\n";
  cout << "0 - Fight the zombies\n";
  cout << "1 - Run away\n";
  cout << "2 - Stay put\n\n";
  
  // Selecting an Action
  int actionSelect;
  cin >> actionSelect;
  
  switch (actionSelect) {
    case 0: {
      action_fightEnemies();
      break;
    }
    case 1: {
      action_runAway();
      break;
    }
    case 2: {
      action_stayPut();
      break;
    }
  }
};

// Finding Chest Scenario
void ScenarioSurvival::scenario_findChest() {
  cout << "You explore around the area and find an unlocked chest!\n\n";
  cout << "What will you do?\n\n";
  cout << "0 - Open the chest\n";
  cout << "1 - Flee the area\n";
  cout << "2 - Check for traps\n\n";
};


// ------------------------------ Menu ------------------------------
void ScenarioSurvival::menu () {
  // Options
  cout << "\033[2J\033[0;0H";
  cout << "---------------- Scenario Survival ----------------\n\n";
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
    cout << "Nice try ;) Please type in a number between 0 and 2 to pick an option\n\n";
    menu();
  }
}

// Exit
int ScenarioSurvival::exit () {
  cout << "\033[2J\033[0;0H";
  return 0;
}

// ------------------------------ Starting the game ------------------------------
void ScenarioSurvival::startGame () {
  // Variables
  int health = startingHealth;
  int stamina = startingStamina;
  int day = startingDay;
  
  // Information + Options
  cout << "\033[2J\033[0;0H";
  cout << "---------------- Day " << day << " ----------------\n\n";
  cout << "Health - " << health << endl;
  cout << "Stamina - " << stamina << endl << endl;
  continueNextDay();
  
  while (continueToNextDay < 0 || continueToNextDay > 1) {
    cout << "\033[2J\033[0;0H";
    cout << "Please type in a number between 0 and 1 to select an option\n\n";
    startGame();
  }
}

// ------------------------------ Moving on to the next day ------------------------------
void ScenarioSurvival::nextDay () {
  if (health <= 0) {
    cout << "\033[2J\033[0;0H";
    cout << "---------------- GAME OVER ----------------\n\n";
    cout << "You died! Survived for " << day << " days\n\n";
    cout << "Play again?\n\n";
    cout << "0 - Play Again\n";
    cout << "1 - Return to Main Menu\n\n";
  }
  else {
    day++;
    cout << "\033[2J\033[0;0H";
    cout << "---------------- Day " << day << " ----------------\n\n";
    cout << "Health - " << health << endl;
    cout << "Stamina - " << stamina << endl << endl;
      
    // Scenario Select
    int scenarios[2] = {0, 1};
    
    srand((unsigned)time(0));
    int scenario = rand()%2;
    
    switch (scenario) {
      case 0: {
        scenario_zombieAttack();
        break;
      }
      case 1: {
        scenario_findChest();
        break;
      }
    }
  }
}