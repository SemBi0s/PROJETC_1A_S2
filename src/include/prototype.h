/*
*
* Main Window Function Prototype
*
*/

void windowMain();
void windowConfig();
void initSDL();
void doInput();
void buttonClick(SCREEN screen, int x, int y);
void caseClick(int x, int y);


/*
*
* Menu Function Prototype
*
*/
void mainMenu();
void mainMenuScene();
void initButton(Button *btn);
Image* mainMenuLoadAssets();
void PlayBtnFunc();
void QuitButtonFunc();
void RuleBtnFunc();

/*
*
* Rule Function prototype
*
*/
void mainRule();
void initRuleButton(Button *btn);
void mainRuleScene();
Image* mainRuleLoadAssets();
void btnCloseFunc();

/*
*
* Level Selection Function Prototype
*
*/
void mainLevelSelector();
void initLevelButton(Button *btn);
void mainLevelScene();
Image* mainLevelLoadAssets();
void btnCloseFunc();
void LevelSelectFunc();
void btnSwitchOneFunc();
void btnSwitchTwoFunc();
void LevelSelectEasyFunc();
void LevelSelectMediumFunc();
void LevelSelectHardFunc();
void LevelSelectExtremeFunc();
/*
*
* Game Function Prototype
*
*/
void Game(DIFFICULTY difficulty);
void initCase(CASE *tab, int size, char *name);
void gameFunction();
void swapCase(int case1, int case2);
void isSuccess();
void displaySuccess();
void gameClick(int i);
bool isSorted();


/*
*
* Game Window Function Prototype
*
*/
void mainGame();
void initGameButton(Button *btn);
void mainGameScene();
Image* mainGameLoadAssets();

/*
*
* Button Rendering Function
*
*/
void prepareBtnRendering(Button *btn);
void renderBtn(Button *btn);
