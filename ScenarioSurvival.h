class ScenarioSurvival {
private:

public:
// ------------------------------ Functions / Variables ------------------------------
void menu();
void startGame();
void instructions();
void continueNextDay();
void nextDay();
void gameOver();
int exit();
int health = 16;
int stamina = 16;
int continueToNextDay;
int day;
int scenario;

void scenario_zombieAttack();
void scenario_findChest();
void action_fightEnemies();
void action_runAway();
void action_stayPut();
};

