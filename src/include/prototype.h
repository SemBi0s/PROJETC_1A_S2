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

/*
*
* Game Window Function Prototype
*
*/
void mainGame();
void initGameButton(Button *btn);
void mainGameScene();
Image* mainGameLoadAssets();
void btnCloseFunc();
void LevelSelectFunc();

/*
*
* Button Rendering Function
*
*/
void prepareBtnRendering(Button *btn);
void renderBtn(Button *btn);